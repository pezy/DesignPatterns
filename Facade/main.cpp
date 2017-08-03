#include <iostream>

class Computer {
public:
    void GetElectricShock() { std::cout << "Ouch!" << std::endl; }
    void MakeSound() { std::cout << "Beep beep!" << std::endl; }
    void ShowLoadingScreen() { std::cout << "Loading..." << std::endl; }
    void Bam() { std::cout << "Ready to be used!" << std::endl; }
    void CloseEverything() { std::cout << "Bup bup bup buzzzz!" << std::endl; }
    void Sooth() { std::cout << "Zzzzz" << std::endl; }
    void PullCurrent() { std::cout << "Haaah!" << std::endl; }
};

class ComputerFacade {
public:
    ComputerFacade(Computer& computer): computer_(computer) {}
    void TurnOn() {
        computer_.GetElectricShock();
        computer_.MakeSound();
        computer_.ShowLoadingScreen();
        computer_.Bam();
    }
    void TurnOff() {
        computer_.CloseEverything();
        computer_.PullCurrent();
        computer_.Sooth();
    }

private:
    Computer& computer_;
};

int main()
{
    Computer real_computer;
    ComputerFacade computer(real_computer);
    computer.TurnOn();
    computer.TurnOff();
}
