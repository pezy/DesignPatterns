#include <iostream>

class Builder {
public:
    void Build() {
        Test();
        Lint();
        Assemble();
        Deploy();
    }
protected:
    virtual void Test() = 0;
    virtual void Lint() = 0;
    virtual void Assemble() = 0;
    virtual void Deploy() = 0;
};

class AndroidBuilder : public Builder {
    void Test() override { std::cout << "Running android tests" << std::endl; }
    void Lint() override { std::cout << "Linting the android code" << std::endl; }
    void Assemble() override { std::cout << "Assembling the android build" << std::endl; }
    void Deploy() override { std::cout << "Deploying android build to server" << std::endl; }
};

class IosBuilder : public Builder {
    void Test() override { std::cout << "Running ios tests" << std::endl; }
    void Lint() override { std::cout << "Linting the ios code" << std::endl; }
    void Assemble() override { std::cout << "Assembling the ios build" << std::endl; }
    void Deploy() override { std::cout << "Deploying ios build to server" << std::endl; }
};

int main()
{
    AndroidBuilder androidBuilder;
    androidBuilder.Build();

    IosBuilder iosBuilder;
    iosBuilder.Build();
}
