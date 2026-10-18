#include <iostream>

using namespace std;

class CPU
{
public:
    void process() {
        cout << "CPU is processing data." << endl;
    }
};

class Memory
{
public:
    void load() {
        cout << "Memory is loading data." << endl;
    }
};

class HardDrive
{
public:
    void read() {
        cout << "Hard Drive is reading data." << endl;
    }
};

class NetworkCard
{
public:
    void connect() {
        cout << "Network Card is connecting to the network." << endl;
    }
};

class GPU
{
public:
    void render() {
        cout << "GPU is rendering graphics." << endl;
    }
};

class ComputerFacade
{
    CPU cpu;
    Memory memory;
    HardDrive hardDrive;
    NetworkCard networkCard;
    GPU gpu;

public:
    void startComputer() {
        cout << "Starting the computer..." << endl;
        cpu.process();
        memory.load();
        hardDrive.read();
        networkCard.connect();
        gpu.render();
        cout << "Computer started successfully!" << endl;
    }
};

int main() {
    ComputerFacade computer;
    computer.startComputer();

    return 0;

}