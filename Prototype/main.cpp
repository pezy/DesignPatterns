#include <iostream>
#include <string>

class Sheep {
public:
    Sheep(const std::string& name, const std::string& category = "Mountain Sheep") : name_(name), category_(category) {}
    void SetName(const std::string& name) { name_ = name; }
    void ShowInfo() { std::cout << name_ << " : " << category_ << std::endl; }
private:
    std::string name_;
    std::string category_;
};

int main()
{
    Sheep jolly("Jolly");
    jolly.ShowInfo();

    Sheep dolly(jolly); // copy constructor
    dolly.SetName("Dolly");
    dolly.ShowInfo();

    Sheep doolly = jolly; // copy assignment
    doolly.SetName("Doolly");
    doolly.ShowInfo();
}
