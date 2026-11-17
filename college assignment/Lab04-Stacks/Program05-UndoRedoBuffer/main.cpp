/**
 * @file main.cpp
 * @brief Text Editor Undo/Redo Engine using Command Pattern & Dual Stacks
 * @course IC-307D: Data Structures & Algorithms LAB
 * @author Samarth Dubey (Roll No: IC-2K25-75)
 * @institution IIPS, Devi Ahilya Vishwavidyalaya (DAVV), Indore
 */

#include <iostream>
#include <stack>
#include <string>
#include <memory>
#include <vector>

// Command Pattern Interface
class Command {
public:
    virtual ~Command() = default;
    virtual void execute(std::string& doc) = 0;
    virtual void undo(std::string& doc) = 0;
    virtual std::string getDescription() const = 0;
};

// Concrete Command: Append/Type Text
class TypeCommand : public Command {
private:
    std::string addedText;

public:
    explicit TypeCommand(std::string text) : addedText(std::move(text)) {}

    void execute(std::string& doc) override {
        doc += addedText;
    }

    void undo(std::string& doc) override {
        if (doc.length() >= addedText.length()) {
            doc.erase(doc.length() - addedText.length());
        }
    }

    std::string getDescription() const override {
        return "Type \"" + addedText + "\"";
    }
};

// Concrete Command: Clear Document
class ClearCommand : public Command {
private:
    std::string previousContent;

public:
    void execute(std::string& doc) override {
        previousContent = doc;
        doc.clear();
    }

    void undo(std::string& doc) override {
        doc = previousContent;
    }

    std::string getDescription() const override {
        return "Clear Document";
    }
};

// Text Editor Buffer with Dual Stacks
class TextEditor {
private:
    std::string document;
    std::stack<std::shared_ptr<Command>> undoStack;
    std::stack<std::shared_ptr<Command>> redoStack;

public:
    void executeCommand(const std::shared_ptr<Command>& cmd) {
        cmd->execute(document);
        undoStack.push(cmd);
        // Performing a new command invalidates redo history
        while (!redoStack.empty()) {
            redoStack.pop();
        }
        std::cout << "[Action] Executed: " << cmd->getDescription() << "\n";
        printDocument();
    }

    void undo() {
        if (undoStack.empty()) {
            std::cout << "[Undo] Warning: Nothing to undo.\n";
            return;
        }
        auto cmd = undoStack.top();
        undoStack.pop();
        cmd->undo(document);
        redoStack.push(cmd);
        std::cout << "[Action] Reverted (Undo): " << cmd->getDescription() << "\n";
        printDocument();
    }

    void redo() {
        if (redoStack.empty()) {
            std::cout << "[Redo] Warning: Nothing to redo.\n";
            return;
        }
        auto cmd = redoStack.top();
        redoStack.pop();
        cmd->execute(document);
        undoStack.push(cmd);
        std::cout << "[Action] Re-applied (Redo): " << cmd->getDescription() << "\n";
        printDocument();
    }

    void printDocument() const {
        std::cout << "  Document State: \"" << document << "\"\n";
        std::cout << "  (Undo Stack Size: " << undoStack.size() 
                  << " | Redo Stack Size: " << redoStack.size() << ")\n\n";
    }
};

int main() {
    std::cout << "========================================================\n";
    std::cout << " IC-307D Data Structures LAB - Text Editor Undo/Redo\n";
    std::cout << " Student: Samarth Dubey | Roll No: IC-2K25-75\n";
    std::cout << "========================================================\n\n";

    TextEditor editor;

    // Perform typing actions
    editor.executeCommand(std::make_shared<TypeCommand>("Data Structures "));
    editor.executeCommand(std::make_shared<TypeCommand>("& Algorithms "));
    editor.executeCommand(std::make_shared<TypeCommand>("Assignment"));

    // Demonstrate Undo operations
    std::cout << "--- Executing Undo Operations ---\n";
    editor.undo(); // Undoes "Assignment"
    editor.undo(); // Undoes "& Algorithms "

    // Demonstrate Redo operations
    std::cout << "--- Executing Redo Operations ---\n";
    editor.redo(); // Redoes "& Algorithms "

    // Clear and restore
    std::cout << "--- Testing Document Clear & Restoration ---\n";
    editor.executeCommand(std::make_shared<ClearCommand>());
    editor.undo(); // Document fully restored!

    return 0;
}
