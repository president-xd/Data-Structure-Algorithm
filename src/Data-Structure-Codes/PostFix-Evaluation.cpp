#include <iostream>
#include <stack>

using namespace std;

class PostfixEvaluator {
public:
    int evaluate(string expression) {
        stack<int> s;
        for (char ch : expression) {
            if (isdigit(ch)) {
                s.push(ch - '0');
            } else {
                int val2 = s.top(); s.pop();
                int val1 = s.top(); s.pop();
                switch (ch) {
                    case '+': s.push(val1 + val2); break;
                    case '-': s.push(val1 - val2); break;
                    case '*': s.push(val1 * val2); break;
                    case '/': s.push(val1 / val2); break;
                }
            }
        }
        return s.top();
    }
};

int main() {
    PostfixEvaluator evaluator;
    string expression = "23*54*+9-"; // (2 * 3) + (5 * 4) - 9
    cout << "Result of postfix expression: " << evaluator.evaluate(expression) << endl;
    return 0;
}
