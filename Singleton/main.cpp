#include <iostream>
#include <string>
#include <cassert>

class President {
public:
    static President& GetInstance() {
        static President instance;
        return instance;
    }

    President(const President&) = delete;
    President& operator=(const President&) = delete;

private:
    President() {}
};

int main()
{
    const President& president1 = President::GetInstance();
    const President& president2 = President::GetInstance();

    assert(&president1 == &president2); // same address, point to same object.
}
