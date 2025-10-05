#include <iostream>
#include <stack>
using namespace std;

int findPrecedence(char op) {
	if (op == '^') return 3;
	if (op == '*' || op == '/') return 2;
	if (op == '+' || op == '-') return 1;
	return 0;
}

string infixToPostfix(string s){
	string postfix;
	stack<char> st;

	for(int i = 0 ; i < s.size(); i++){
		if(s[i] == ' ') continue;

		if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
			postfix += s[i];
		}

		else if(s[i] == '(') st.push(s[i]);
		else if(s[i] == ')'){
			while(!st.empty() && st.top() != '('){
				postfix += st.top();
				st.pop();
			}
			if(!st.empty()) st.pop();
		}

		else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^'){
			while(!st.empty() && findPrecedence(st.top()) >= findPrecedence(s[i])){
				if(st.top() == '(') break;
				postfix += st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}

	while(!st.empty()){
		postfix += st.top();
		st.pop();
	}

	return postfix;
}

int main(){
	string s;
	cout << "Enter a string to convert to postfix : ";
	getline(cin, s);

	cout << "Infix to Postfix : " << infixToPostfix(s);
	return 0;
}