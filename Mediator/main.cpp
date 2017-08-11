#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

class User;

class IChatRoomMediator {
public:
    virtual void ShowMessage(const User& user, const std::string& message) = 0;
};

class ChatRoom : public IChatRoomMediator {
public:
    void ShowMessage(const User& user, const std::string& message) override;
};

class User {
public:
    User(const std::string& name, IChatRoomMediator& chatMediator): name_(name), chatMediator_(chatMediator) {}
    const std::string& GetName() const { return name_; }
    void Send(const std::string& message) { chatMediator_.ShowMessage(*this, message); }
private:
    std::string name_;
    IChatRoomMediator& chatMediator_;
};

void ChatRoom::ShowMessage(const User &user, const std::string &message) {
    std::time_t now = std::time(nullptr);
    std::cout << std::put_time(std::localtime(&now), "%Y-%m-%d %H:%M:%S") << "[" << user.GetName() << "]: " << message << std::endl;
}

int main()
{
    ChatRoom mediator;
    User john("John Doe", mediator);
    User jane("Jane Doe", mediator);
    john.Send("Hi, there!");
    jane.Send("Hey!");
}
