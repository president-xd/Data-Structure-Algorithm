#include <iostream>
#include <stack>

using namespace std;

class PrefixEvaluator {
public:
    int evaluate(string expression) {
        stack<int> s;
        for (int i = expression.length() - 1; i >= 0; i--) {
            char ch = expression[i];
            if (isdigit(ch)) {
                s.push(ch - '0');
            } else {
                int val1 = s.top(); s.pop();
                int val2 = s.top(); s.pop();
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
    PrefixEvaluator evaluator;
    string expression = "-+*23*549"; // (2 * 3) + (5 * 4) - 9
    cout << "Result of prefix expression: " << evaluator.evaluate(expression) << endl;
    return 0;
}
