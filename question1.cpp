#include <iostream>
#include <stack>

using namespace std;

bool areBracesBalanced(const string& code) {
    stack<char> s;

    for (char ch : code) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) {
                return false;
            }
            char top = s.top();
            if ((ch == ')' && top != '(') || (ch == '}' && top != '{') || (ch == ']' && top != '[')) {
                return false;
            }
            s.pop();
        }
    }

    return s.empty();
}

int main() {
    string code;
    cout << "Enter the code string: ";
    cin >> code;

    if (areBracesBalanced(code)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
