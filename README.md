# Processor on C++

x86/64 CPU Emulator in C++

This project is a simple emulator for a fictional 64-bit CPU architecture written in C++. It simulates the execution of binary code represented as machine instructions.

# Features

- Emulation of a 64-bit CPU architecture.
- Support for basic instructions:
  - MOV (Move immediate value to register)
  - ADD (Add immediate value to register)
  - SUB (Subtract immediate value from register)
  - JMP (Unconditional jump)
  - HLT (Halt)
- Ability to load binary programs into memory.
- Execution of loaded programs.
- Print register values after execution.

# Usage

1. Clone the repository or download the cpu_emulator.cpp file.
2. Compile the code using a C++ compiler:

```g++ -o cpu_emulator cpu_emulator.cpp```

3. Run the compiled executable:

```./cpu_emulator```

4. Modify the main() function in cpu_emulator.cpp to load and execute different programs.

# Example

A simple program that moves immediate values into registers, performs addition and subtraction, and halts:

std::vector<uint8_t> program = {0x01, 0x00, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, // MOV R0, 0x4948474645444342
                                 0x02, 0x01, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, // ADD R1, 0x3938373635343332
                                 0x03, 0x01, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, // SUB R1, 0x3938373635343332
                                 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // JMP to start of program
                                 0xFF}; // HLT

# Notes

- This emulator is a simplified representation and does not cover all aspects of a real x86/64 CPU architecture.
- It is intended for educational purposes and as a starting point for further exploration of CPU emulation concepts.

# License

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
