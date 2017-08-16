#include <iostream>
#include <string>
#include <unordered_map>

// Anything that will be cached is flyweight.
// Types of tea here will be flyweights.
class KarakTea {};

class TeaMaker {
public:
    KarakTea* Make(const std::string& preference) {
        if (availableTea_.find(preference) == availableTea_.end())
            availableTea_.insert({preference, new KarakTea()});

        return availableTea_.at(preference);
    }

private:
    std::unordered_map<std::string, KarakTea*> availableTea_;
};

class TeaShop {
public:
    TeaShop(TeaMaker& teaMaker): teaMaker_(teaMaker) {}
    void TakeOrder(const std::string& teaType, int table) {
        orders_[table] = teaMaker_.Make(teaType);
    }
    void Serve() {
        for(auto order : orders_)
            std::cout << "Serving tea to table# " << order.first << std::endl;
    }

private:
    std::unordered_map<int, KarakTea*> orders_;
    TeaMaker& teaMaker_;
};

int main()
{
    TeaMaker teaMaker;
    TeaShop shop(teaMaker);

    shop.TakeOrder("less sugar", 1);
    shop.TakeOrder("more milk", 2);
    shop.TakeOrder("without sugar", 5);

    shop.Serve();
}
