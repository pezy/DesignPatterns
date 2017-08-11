#include <iostream>
#include <string>
#include <memory>

class EditorMemento {
public:
    EditorMemento(const std::string& content): content_(content) {}
    const std::string& GetContent() const { return content_; }
private:
    std::string content_;
};

class Editor {
    using MementoType = std::shared_ptr<EditorMemento>;
public:
    void Type(const std::string& words) { content_ += " " + words; }
    const std::string& GetContent() const { return content_; }
    MementoType Save() { return std::make_shared<EditorMemento>(content_); }
    void Restore(MementoType memento) { content_ = memento->GetContent(); }
private:
    std::string content_;
};

int main()
{
    Editor editor;
    //! Type some stuff
    editor.Type("This is the first sentence.");
    editor.Type("This is second.");
    //! Save the state to restore to : This is the first sentence. This is second.
    auto saved = editor.Save();
    //! Type some more
    editor.Type("And this is third.");
    std::cout << editor.GetContent() << std::endl;
    editor.Restore(saved);
    std::cout << editor.GetContent() << std::endl;
}
