#include <time.h>
#include <stdio.h>
#include <langinfo.h>

const char *__langinfo(nl_item);

char *__asctime(const struct tm *tm, char *buf)
{
	/* FIXME: change __langinfo to __C_langinfo once we have locales */
	if (snprintf(buf, 26, "%.3s %.3s%3d %.2d:%.2d:%.2d %d\n",
		__langinfo(ABDAY_1+tm->tm_wday),
		__langinfo(ABMON_1+tm->tm_mon),
		tm->tm_mday, tm->tm_hour,
		tm->tm_min, tm->tm_sec,
		1900 + tm->tm_year) >= 26)
	{
		/* ISO C requires us to use the above format string,
		 * even if it will not fit in the buffer. Thus asctime_r
		 * is _supposed_ to crash if the fields in tm are too large.
		 * We follow this behavior and crash "gracefully" to warn
		 * application developers that they may not be so lucky
		 * on other implementations (e.g. stack smashing..).
		 */
		*(int*)0 = 0;
	}
	return buf;
}
