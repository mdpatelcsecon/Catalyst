#ifndef GDT_H
#define GDT_H

#include <stdint.h>
#include <stddef.h>

void setup_gdt(uint64_t gdt[7]);

#endif
