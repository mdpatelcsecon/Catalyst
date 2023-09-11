/* 
Catalyst: A Standalone General Purpose OS Kernel
Copyright (C) 2023  Mohit D. Patel (mdpatelcsecon)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see https://www.gnu.org/licenses/
*/

#ifdef __x86_64__

#include "llk/isa/include/api.h"

#include "include/cpu.h"
#include "include/gdt.h"
#include "include/isa.h"
#include "include/serial.h"
#include "include/tss.h"

#include "hlk/log/include/log.h"
#include "hlk/log/include/string.h"
#include "hlk/log/include/type_conv.h"

static gdt_t gdt;
static tss_t tss;
static uint8_t bsp_stack[4096];

/*CPU*/
void inline llk_disable_interrupts(void)
{
        disable_interrupts();
}
void inline llk_enable_interrupts(void)
{
        enable_interrupts();
}
[[noreturn]]
void llk_hcf(void)
{
        hcf();
}
void llk_init_lp(void)
{
        setup_gdt(gdt, tss, &bsp_stack[1024]);
        log_puts("Global Descriptor Table:\r\n");
        for (size_t i = 0; i < 7; ++i) {
                memset(temp_str, '\0', 1024);
                u64_to_hex_str(gdt[i], temp_str);
                log_puts(temp_str);
                log_puts("\r\n");
        }
        load_gdt(gdt);
}

/*Serial Port*/
int32_t llk_init_serial(void)
{
        init_serial();
        return 0;
}
void llk_serial_putc(const char c)
{
        serial_putc(c);
}

/*Memory*/
void llk_init_memory(void)
{
}

#endif
