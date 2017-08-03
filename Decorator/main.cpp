#include <iostream>
#include <string>

class ICoffee {
public:
    virtual float GetCost() = 0;
    virtual std::string GetDescription() = 0;
};

class SimpleCoffee : public ICoffee {
public:
    float GetCost() override { return 10; }
    std::string GetDescription() override { return "Simple coffee"; }
};

class CoffeePlus : public ICoffee {
public:
    CoffeePlus(ICoffee& coffee): coffee_(coffee) {}
    virtual float GetCost() = 0;
    virtual std::string GetDescription() = 0;
protected:
    ICoffee& coffee_;
};

class MilkCoffee : public CoffeePlus {
public:
    MilkCoffee(ICoffee& coffee): CoffeePlus(coffee) {}
    float GetCost() override { return coffee_.GetCost() + 2; }
    std::string GetDescription() override { return coffee_.GetDescription() + ", milk"; }
};

class WhipCoffee : public CoffeePlus {
public:
    WhipCoffee(ICoffee& coffee): CoffeePlus(coffee) {}
    float GetCost() override { return coffee_.GetCost() + 5; }
    std::string GetDescription() override { return coffee_.GetDescription() + ", whip"; }
};

class VanillaCoffee : public CoffeePlus {
public:
    VanillaCoffee(ICoffee& coffee): CoffeePlus(coffee) {}
    float GetCost() override { return coffee_.GetCost() + 3; }
    std::string GetDescription() override { return coffee_.GetDescription() + ", vanilla"; }
};

int main()
{
    ICoffee* someCoffee = new SimpleCoffee();
    std::cout << someCoffee->GetCost() << std::endl;
    std::cout << someCoffee->GetDescription() << std::endl;

    someCoffee = new MilkCoffee(*someCoffee);
    std::cout << someCoffee->GetCost() << std::endl;
    std::cout << someCoffee->GetDescription() << std::endl;

    someCoffee = new WhipCoffee(*someCoffee);
    std::cout << someCoffee->GetCost() << std::endl;
    std::cout << someCoffee->GetDescription() << std::endl;

    someCoffee = new VanillaCoffee(*someCoffee);
    std::cout << someCoffee->GetCost() << std::endl;
    std::cout << someCoffee->GetDescription() << std::endl;
}
