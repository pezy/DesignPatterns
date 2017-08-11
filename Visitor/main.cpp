#include <iostream>

class AnimalOperation;

// visitee
class Animal {
public:
    virtual void Accept(AnimalOperation& operation) = 0;
};

class Monkey;
class Lion;
class Dolphin;

// visitor
class AnimalOperation {
public:
    virtual void visitMonkey(Monkey& monkey) = 0;
    virtual void visitLion(Lion& lion) = 0;
    virtual void visitDolphin(Dolphin& dolphin) = 0;
};

class Monkey : public Animal {
public:
    void Shout() { std::cout << "Ooh oo aa aa!" << std::endl; }
    void Accept(AnimalOperation& operation) override { operation.visitMonkey(*this); }
};

class Lion : public Animal {
public:
    void Roar() { std::cout << "Roaaar!" << std::endl; }
    void Accept(AnimalOperation& operation) override { operation.visitLion(*this); }
};

class Dolphin : public Animal {
public:
    void Speak() { std::cout << "Tuut tuttu tuutt!" << std::endl; }
    void Accept(AnimalOperation& operation) override { operation.visitDolphin(*this); }
};

class Speak : public AnimalOperation {
public:
    void visitMonkey(Monkey& monkey) override { monkey.Shout(); }
    void visitLion(Lion& lion) override { lion.Roar(); }
    void visitDolphin(Dolphin& dolphin) override { dolphin.Speak(); }
};

int main()
{
    Monkey monkey;
    Lion lion;
    Dolphin dolphin;

    Speak speak;
    monkey.Accept(speak);
    lion.Accept(speak);
    dolphin.Accept(speak);
}
