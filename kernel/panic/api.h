#ifndef PANIC_API_H
#define PANIC_API_H

#include "arch/api.h"
#include "log/log.h"

inline void panic(void)
{
	log_puts("A kernel panic has occurred!!!");
	isa_hcf();
}

inline void assert([[maybe_unused]] const bool expr)
{
#ifdef ASSERT
	if (expr == false)
		panic();
#endif
}

inline void assert_not_null([[maybe_unused]] const void *const ptr)
{
#ifdef ASSERT
	if (ptr == nullptr)
		panic();
#endif
}

#endif
