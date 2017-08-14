#include <iostream>
#include <string>
#include <algorithm>
#include <memory>

class IWritingState {
public:
    virtual void Write(std::string words) = 0;
};

class UpperCase : public IWritingState {
    void Write(std::string words) override {
        std::transform(words.begin(), words.end(), words.begin(), ::toupper);
        std::cout << words << std::endl;
    }
};

class LowerCase : public IWritingState {
    void Write(std::string words) override {
        std::transform(words.begin(), words.end(), words.begin(), ::tolower);
        std::cout << words << std::endl;
    }
};

class Default : public IWritingState {
    void Write(std::string words) override { std::cout << words << std::endl; }
};

class TextEditor {
public:
    TextEditor(const std::shared_ptr<IWritingState>& state): state_(state) {}
    void SetState(const std::shared_ptr<IWritingState>& state) { state_ = state; }
    void Type(std::string words) { state_->Write(words); }
private:
    std::shared_ptr<IWritingState> state_;
};

int main()
{
  TextEditor editor(std::make_shared<Default>());
  editor.Type("First line");

  editor.SetState(std::make_shared<UpperCase>());
  editor.Type("Second line");
  editor.Type("Third line");

  editor.SetState(std::make_shared<LowerCase>());
  editor.Type("Fourth line");
  editor.Type("Fifth line");
}
