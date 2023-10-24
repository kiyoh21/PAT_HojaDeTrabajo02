#include "Ejercicio03.h"
#include <stack>
#include <cctype>

int Ejercicio03::calculate(std::string s) {
    std::stack<int> values;
    std::stack<char> ops;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') continue;

        if (isdigit(s[i])) {
            int val = 0;
            while (i < s.size() && isdigit(s[i])) {
                val = val * 10 + (s[i] - '0');
                i++;
            }
            i--;
            values.push(val);
        }
        else if (s[i] == '+' || s[i] == '-') {
            while (!ops.empty()) {
                int b = values.top(); values.pop();
                int a = values.top(); values.pop();
                if (ops.top() == '+') values.push(a + b);
                else if (ops.top() == '-') values.push(a - b);
                else if (ops.top() == '*') values.push(a * b);
                else values.push(a / b);
                ops.pop();
            }
            ops.push(s[i]);
        }
        else if (s[i] == '*' || s[i] == '/') {
            while (!ops.empty() && (ops.top() == '*' || ops.top() == '/')) {
                int b = values.top(); values.pop();
                int a = values.top(); values.pop();
                if (ops.top() == '*') values.push(a * b);
                else values.push(a / b);
                ops.pop();
            }
            ops.push(s[i]);
        }
    }

    while (!ops.empty()) {
        int b = values.top(); values.pop();
        int a = values.top(); values.pop();
        if (ops.top() == '+') values.push(a + b);
        else if (ops.top() == '-') values.push(a - b);
        else if (ops.top() == '*') values.push(a * b);
        else values.push(a / b);
        ops.pop();
    }

    return values.top();
}
