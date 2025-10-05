#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int findPrecedence(char op) {
	if (op == '^') return 3;
	if (op == '*' || op == '/') return 2;
	if (op == '+' || op == '-') return 1;
	return 0;
}

string infixToPrefix(string s) {
	reverse(s.begin(), s.end());
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') s[i] = ')';
		else if (s[i] == ')') s[i] = '(';
	}

	stack<char> st;
	string prefix;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') continue;
		if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
			prefix += s[i];
		}
		else if (s[i] == '(') {
			st.push(s[i]);
		}
		else if (s[i] == ')') {
			while (!st.empty() && st.top() != '(') {
				prefix += st.top();
				st.pop();
			}
			if (!st.empty()) st.pop();
		}
		else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^') {
			while (!st.empty() && findPrecedence(st.top()) > findPrecedence(s[i])) {
				if (st.top() == '(') break;
				prefix += st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}

	while (!st.empty()) {
		prefix += st.top();
		st.pop();
	}

	reverse(prefix.begin(), prefix.end());
	return prefix;
}

int main() {
	string s;
	cout << "Enter a string to convert to prefix : ";
	getline(cin, s);

	cout << "Infix to Prefix : " << infixToPrefix(s);
	return 0;
}
