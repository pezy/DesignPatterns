#include <iostream>

class ILion {
public:
    virtual void Roar() {
        std::cout << "I am a Lion" << std::endl;
    }
};

class Hunter {
public:
    void Hunt(ILion& lion) {
        lion.Roar();
    }
};

class WildDog
{
public:
    void Bark() {
        std::cout << "I am a wild dog." << std::endl;
    }
};

//! now we added a new class `WildDog`, the hunter can hunt it also.
//! But we cannot do that directly because dog has a different interface.
//! To make it compatible for our hunter, we will have to create an adapter.

class WildDogAdapter : public ILion {
public:
    WildDogAdapter(WildDog& dog): dog_(dog) {}
    void Roar() override {
        dog_.Bark();
    }
private:
    WildDog& dog_;
};

int main()
{
    WildDog dog;
    WildDogAdapter dogAdapter(dog);

    Hunter hunter;
    hunter.Hunt(dogAdapter);
}
