# Catalyst
Catalyst was going to be the kernel of CharlotteOS. It is written in portable C23 and assembly language.

## Status

Catalyst has been fully superceded as the kernel of CharlotteOS by Charlotte Core which has been written from the ground up in Rust and Assembly language. 

This repository exists solely for record keeping purposes at this point.

## Design

- **Hybrid Kernel**:
  - A relatively stable kernel that is extensible via userspace kernel servers
  - Performance-critical driver components can be integrated directly into kernelspace as required

- **Security & System Calls**:
  - Capability based security
  - System call interface that offers close control over system primitives

- **Bootloader**:
  - Uses the [Limine Boot Protocol](https://github.com/limine-bootloader/limine)

## Hardware Support

- x86-64 implementation in progress
- Aarch64 support planned
- UEFI and ACPI are required

## Building

Building is as simple as running `make`.

## Contributing

If you're interested in contributing to the Catalyst Kernel, please reach out to [mdpatel.econ@gmail.com](mailto:mdpatel.econ@gmail.com).

## License

Catalyst is licensed under the [GNU General Public License Version 3.0](https://www.gnu.org/licenses/gpl-3.0.en.html) as published by the Free Software Foundation.
