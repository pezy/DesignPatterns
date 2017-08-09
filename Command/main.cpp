#include <iostream>

class Bulb {
  public:
    void TurnOn() { std::cout << "Bulb has been lit" << std::endl; }
    void TurnOff() { std::cout << "Darkness!" << std::endl; }
};

class ICommand {
  public:
    virtual void Execute() = 0;
    virtual void Undo() = 0;
    virtual void Redo() = 0;
};

class TurnOn : public ICommand {
  public:
    TurnOn(Bulb& bulb): bulb_(bulb) {}
    void Execute() override { bulb_.TurnOn(); }
    void Undo() override { bulb_.TurnOff(); }
    void Redo() override { Execute(); }
  private:
    Bulb& bulb_;
};

class TurnOff : public ICommand {
  public:
    TurnOff(Bulb& bulb): bulb_(bulb) {}
    void Execute() override { bulb_.TurnOff(); }
    void Undo() override { bulb_.TurnOn(); }
    void Redo() override { Execute(); }
  private:
    Bulb& bulb_;
};

class RemoteControl {
  public:
    void Submit(ICommand& command) { command.Execute(); }
};

int main()
{
  Bulb bulb;
  TurnOn turnOn(bulb);
  TurnOff turnOff(bulb);

  RemoteControl remote;
  remote.Submit(turnOn);
  remote.Submit(turnOff);
}
