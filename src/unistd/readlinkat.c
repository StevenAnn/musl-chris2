#include <unistd.h>
#include "syscall.h"

int readlinkat(int fd, const char *path, char *buf, size_t bufsize)
{
	return syscall(SYS_readlinkat, fd, path, buf, bufsize);
}
