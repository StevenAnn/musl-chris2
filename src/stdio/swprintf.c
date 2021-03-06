#include <stdio.h>
#include <stdarg.h>
#include <wchar.h>

int swprintf(wchar_t *s, size_t n, const wchar_t *fmt, ...)
{
	int ret;
	va_list ap;
	va_start(ap, fmt);
	ret = vswprintf(s, n, fmt, ap);
	va_end(ap);
	return ret;
}

