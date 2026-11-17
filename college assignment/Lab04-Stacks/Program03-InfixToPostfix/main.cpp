/**
 * @file main.cpp
 * @brief Infix to Postfix Expression Conversion using Stack in C++
 * @course IC-307D: Data Structures & Algorithms LAB
 * @author Samarth Dubey (Roll No: IC-2K25-75)
 * @institution IIPS, Devi Ahilya Vishwavidyalaya (DAVV), Indore
 */

#include <iostream>
#include <stack>
#include <string>
#include <cctype>

class ExpressionConverter {
private:
    static int precedence(char op) {
        if (op == '^') return 3;
        if (op == '*' || op == '/' || op == '%') return 2;
        if (op == '+' || op == '-') return 1;
        return 0;
    }

    static bool isRightAssociative(char op) {
        return op == '^';
    }

public:
    static std::string infixToPostfix(const std::string& infix) {
        std::stack<char> st;
        std::string postfix = "";

        std::cout << "\n--- Conversion Trace for: \"" << infix << "\" ---\n";
        std::cout << "| Token | Stack Content | Current Postfix |\n";
        std::cout << "|-------|---------------|-----------------|\n";

        for (char ch : infix) {
            if (isspace(ch)) continue;

            // Operands go directly to output
            if (isalnum(ch)) {
                postfix += ch;
            } else if (ch == '(') {
                st.push(ch);
            } else if (ch == ')') {
                while (!st.empty() && st.top() != '(') {
                    postfix += st.top();
                    st.pop();
                }
                if (!st.empty() && st.top() == '(') {
                    st.pop(); // Discard '('
                }
            } else { // Operator
                while (!st.empty() && st.top() != '(' &&
                       (precedence(st.top()) > precedence(ch) ||
                       (precedence(st.top()) == precedence(ch) && !isRightAssociative(ch)))) {
                    postfix += st.top();
                    st.pop();
                }
                st.push(ch);
            }

            // Print step trace
            std::stack<char> temp = st;
            std::string stStr = "";
            while (!temp.empty()) {
                stStr = temp.top() + stStr;
                temp.pop();
            }
            std::cout << "|   " << ch << "   | " << stStr 
                      << std::string(14 > stStr.length() ? 14 - stStr.length() : 1, ' ') 
                      << "| " << postfix << "\n";
        }

        // Pop remaining operators
        while (!st.empty()) {
            postfix += st.top();
            st.pop();
        }

        return postfix;
    }
};

int main() {
    std::cout << "========================================================\n";
    std::cout << " IC-307D Data Structures LAB - Infix to Postfix\n";
    std::cout << " Student: Samarth Dubey | Roll No: IC-2K25-75\n";
    std::cout << "========================================================\n";

    std::string infix1 = "A + B * C - D / E";
    std::string post1 = ExpressionConverter::infixToPostfix(infix1);
    std::cout << "\n[Result 1] Infix: " << infix1 << "  ==>  Postfix: " << post1 << "\n";

    std::string infix2 = "(A + B) * (C - D)";
    std::string post2 = ExpressionConverter::infixToPostfix(infix2);
    std::cout << "\n[Result 2] Infix: " << infix2 << "  ==>  Postfix: " << post2 << "\n";

    return 0;
}
