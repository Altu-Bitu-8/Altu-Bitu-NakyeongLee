#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true) {
		string str;
		getline(cin, str);

		if (str == ".") {
			break;
		}

		bool is_balanced = true;
		stack<char> s;
		for (int i = 0; i < str.length(); i++) {
			char c = str[i];
			if (c == '(' || c == '[') {
				s.push(c);
			}
			else if (c == ')') {
				if (!s.empty() && s.top() == '(') {
					s.pop();
				}
				else {
					is_balanced = false;
					break;
				}
			}
			else if (c == ']') {
				if (!s.empty() && s.top() == '[') {
					s.pop();
				}
				else {
					is_balanced = false;
					break;
				}
			}
		}
		if (is_balanced && s.empty()) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}
}
