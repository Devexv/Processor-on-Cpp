#include <iostream>
#include <vector>
#include <cstdint>
#include <iomanip>

class CPU {
private:
    std::vector<uint8_t> memory;
    uint64_t ip;
    uint64_t regs[16];

public:
    CPU() : memory(4096), ip(0) {
        for (int i = 0; i < 16; ++i) {
            regs[i] = 0;
        }
    }

    void loadProgram(const std::vector<uint8_t>& program) {
        if (program.size() > memory.size()) {
            std::cerr << "Program is too large for memory." << std::endl;
            return;
        }
        std::copy(program.begin(), program.end(), memory.begin());
    }

    void run() {
        while (ip < memory.size()) {
            uint8_t opcode = memory[ip];
            switch (opcode) {
                case 0x01:
                    {
                        uint8_t reg = memory[ip + 1];
                        uint64_t value = *(uint64_t*)&memory[ip + 2];
                        regs[reg] = value;
                        ip += 10;
                    }
                    break;
                case 0x02:
                    {
                        uint8_t reg = memory[ip + 1];
                        uint64_t value = *(uint64_t*)&memory[ip + 2];
                        regs[reg] += value;
                        ip += 10;
                    }
                    break;
                case 0x03:
                    {
                        uint8_t reg = memory[ip + 1];
                        uint64_t value = *(uint64_t*)&memory[ip + 2];
                        regs[reg] -= value;
                        ip += 10;
                    }
                    break;
                case 0x04:
                    {
                        uint64_t value = *(uint64_t*)&memory[ip + 1];
                        ip = value;
                    }
                    break;
                case 0xFF:
                    return;
                default:
                    std::cerr << "Unknown opcode: 0x" << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(opcode) << std::endl;
                    return;
            }
        }
    }

    void printRegisters() {
        std::cout << "Registers:" << std::endl;
        for (int i = 0; i < 16; ++i) {
            std::cout << "R" << std::dec << i << ": " << std::hex << std::setw(16) << std::setfill('0') << regs[i] << std::endl;
        }
    }
};

int main() {
    std::vector<uint8_t> program = {0x01, 0x00, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49,
                                     0x02, 0x01, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39,
                                     0x03, 0x01, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39,
                                     0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                     0xFF};
    CPU cpu;
    cpu.loadProgram(program);
    cpu.run();
    cpu.printRegisters();
    return 0;
}
