; Catalyst: A Standalone General Purpose OS Kernel
; Copyright (C) 2023  Mohit D. Patel (mdpatelcsecon)

; This program is free software: you can redistribute it and/or modify
; it under the terms of the GNU General Public License as published by
; the Free Software Foundation, either version 3 of the License, or
; (at your option) any later version.

; This program is distributed in the hope that it will be useful,
; but WITHOUT ANY WARRANTY; without even the implied warranty of
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
; GNU General Public License for more details.

; You should have received a copy of the GNU General Public License
; along with this program.  If not, see https://www.gnu.org/licenses/

bits 64

section .text
global inb
inb:
	mov dx, di
	in al, dx
	ret

global outb
outb:
	mov dx, di
	mov al, sil
	out dx, al
	ret
global reg_test
reg_test:
	mov rax, 1
	mov rbx, 2
	mov rcx, 4
	mov rdx, 8
	ret