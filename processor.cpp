#include <iostream>
#include <string>
#include <vector>

class HardDrive {
public:
    std::string readData() {
        return "Data read from hard drive";
    }
    void writeData(const std::string& data) {
        std::cout << "Data written to hard drive: " << data << std::endl;
    }
};

class RAM {
public:
    std::string readData() {
        return "Data read from RAM";
    }
    void writeData(const std::string& data) {
        std::cout << "Data written to RAM: " << data << std::endl;
    }
};

class GPU {
public:
    void render(const std::string& data) {
        std::cout << "Rendering data using GPU: " << data << std::endl;
    }
};

class Processor {
private:
    HardDrive hardDrive;
    RAM ram;
    GPU gpu;

    std::vector<std::string> storage;

public:
    void fetchDataFromHardDrive() {
        std::string data = hardDrive.readData();
        storage.push_back(data);
    }

    void sendDataToRAM() {
        if (!storage.empty()) {
            std::string data = storage.back();
            storage.pop_back();
            ram.writeData(data);
        } else {
            std::cout << "No data available to send to RAM." << std::endl;
        }
    }

    void processAndRenderData() {
        if (!storage.empty()) {
            std::string data = storage.back();
            storage.pop_back();
            gpu.render(data);
        } else {
            std::cout << "No data available to process and render." << std::endl;
        }
    }
};

int main() {
    Processor processor;

    processor.fetchDataFromHardDrive();
    processor.fetchDataFromHardDrive();
    processor.fetchDataFromHardDrive();

    processor.sendDataToRAM();
    processor.sendDataToRAM();
    processor.processAndRenderData();

    return 0;
}
