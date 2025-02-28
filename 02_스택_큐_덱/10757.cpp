#include <iostream>
#include <stack>

using namespace std;

void fillStack(stack<int>& a_stack, stack<int>& b_stack, string a, string b) {
	int diff;
	if (a.size() > b.size()) {
		diff = a.size() - b.size();
		for (int i = 0; i < diff; i++) {
			b_stack.push(0);
		}
	}
	else if (a.size() < b.size()) {
		diff = b.size() - a.size();
		for (int i = 0; i < diff; i++) {
			a_stack.push(0);
		}
	}

	for (int i = 0; i < a.size(); i++) {
		a_stack.push(a[i] - '0');
	}
	for (int i = 0; i < b.size(); i++) {
		b_stack.push(b[i] - '0');
	}
}

int add(stack<int>& a_stack, stack<int>& b_stack, stack<int>& sum_stack) {
	int up = 0;
	int sum;
	while (!a_stack.empty()) {
		sum = a_stack.top() + b_stack.top();
		a_stack.pop();
		b_stack.pop();
		if (up == 1) {
			sum += 1;
		}
		if (sum >= 10) {
			up = 1;
			sum -= 10;
		}
		else
		{
			up = 0;
		}
		sum_stack.push(sum);
	}
	return up;
}

void printStack(int up, stack<int>& s) {
	if (up == 1) {
		cout << 1;
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a, b;
	cin >> a >> b;

	stack<int> a_stack, b_stack, sum_stack;

	fillStack(a_stack, b_stack, a, b);
	int up = add(a_stack, b_stack, sum_stack);
	printStack(up, sum_stack);
}
