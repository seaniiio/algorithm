#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<char> s;
	string output = "";
	string str; cin >> str;
	bool b = false;
	int count = 0;
	for (int i{ 0 }; i < str.length(); i++) {
		if (str[i] == '*' && !b) {
			while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
				output += s.top();
				s.pop();
			}
			s.push('*');
		}
		else if (str[i] == '/' && !b) {
			while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
				output += s.top();
				s.pop();
			}
			s.push('/');
		}
		else if (str[i] == '+' && !b) {
			while (!s.empty() && (s.top() == '+' || s.top() == '-' || s.top() == '*' || s.top() == '/'))  {
				output += s.top();
				s.pop();
			}
			s.push('+');
		}
		else if (str[i] == '-' && !b) {
			while (!s.empty() && (s.top() == '+' || s.top() == '-' || s.top() == '*' || s.top() == '/')) {
				output += s.top();
				s.pop();
			}
			s.push('-');
		}

		else if (str[i] == '(') {
			b = true;
			continue;
		}
		else if (str[i] == ')') {
			b = false;
			while (count--) {
				output += s.top();
				s.pop();
			}
			continue;
		}
		else if (b && (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')) {
			count++;
			s.push(str[i]);
		}
		else {
			output += str[i];
		}
	}

	while (!s.empty()) {
		output += s.top();
		s.pop();
	}
	cout << output << '\n';
}