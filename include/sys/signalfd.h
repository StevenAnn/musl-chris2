#ifndef _SYS_SIGNALFD_H
#define _SYS_SIGNALFD_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define __NEED_sigset_t

#include <bits/alltypes.h>

int signalfd(int, const sigset_t *, int);

struct signalfd_siginfo {
	uint32_t  ssi_signo;
	int32_t   ssi_errno;
	int32_t   ssi_code;
	uint32_t  ssi_pid;
	uint32_t  ssi_uid;
	int32_t   ssi_fd;
	uint32_t  ssi_tid;
	uint32_t  ssi_band;
	uint32_t  ssi_overrun;
	uint32_t  ssi_trapno;
	int32_t   ssi_status;
	int32_t   ssi_int;
	uintptr_t ssi_ptr;
	uint64_t  ssi_utime;
	uint64_t  ssi_stime;
	uint64_t  ssi_addr;
	uint8_t   pad[128-12*4-sizeof(void *)-3*8];
};

#ifdef __cplusplus
}
#endif

#endif
