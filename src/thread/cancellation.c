#include "pthread_impl.h"

#ifdef __pthread_register_cancel
#undef __pthread_register_cancel
#undef __pthread_unregister_cancel
#define __pthread_register_cancel __pthread_register_cancel_3
#define __pthread_unregister_cancel __pthread_unregister_cancel_3
#endif

void __pthread_register_cancel(struct __ptcb *cb)
{
	struct pthread *self = pthread_self();
	cb->__next = self->cancelbuf;
	self->cancelbuf = cb;
}

void __pthread_unregister_cancel(struct __ptcb *cb)
{
	struct pthread *self = __pthread_self();
	self->cancelbuf = self->cancelbuf->__next;
}
