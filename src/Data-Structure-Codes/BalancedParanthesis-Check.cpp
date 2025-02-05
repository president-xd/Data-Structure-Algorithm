#include <iostream>
#include <stack>

using namespace std;

class ParenthesesChecker {
public:
    bool isBalanced(string expr) {
        stack<char> s;
        for (char ch : expr) {
            if (ch == '(' || ch == '{' || ch == '[') {
                s.push(ch);
            } else {
                if (s.empty()) return false;
                char top = s.top();
                s.pop();
                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '[')) {
                    return false;
                }
            }
        }
        return s.empty();
    }
};

int main() {
    ParenthesesChecker checker;
    string expr = "{[()]}";
    if (checker.isBalanced(expr)) {
        cout << "The expression is balanced." << endl;
    } else {
        cout << "The expression is not balanced." << endl;
    }
    return 0;
}
