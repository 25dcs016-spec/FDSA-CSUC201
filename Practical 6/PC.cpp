#include <iostream>
#include <stack>
#include <string>
#include <cctype>

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

std::string infixToPostfix(std::string s) {
    std::stack<char> st;
    std::string result;
    for (char c : s) {
        if (std::isalnum(c)) {
            result += c;
        } else if (c == '(') {
            st.push('(');
        } else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        } else {
            while (!st.empty() && prec(c) <= prec(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    return result;
}

int main() {
    std::string exp = "(a+b)*c-(d-e)*(f+g)";
    std::cout << infixToPostfix(exp) << std::endl;
    return 0;
}
