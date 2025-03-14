#include <iostream>

using namespace std;

typedef long long ll;

void calculate(ll& s) {
	string oper;
	int x;
	bool b;

	cin >> oper;

	if (oper == "add") {
		cin >> x;
		s |= ((ll)1 << x);
	}
	else if (oper == "remove") {
		cin >> x;
		s &= ~((ll)1 << x);
	}
	else if (oper == "check") {
		cin >> x;
		b = s & ((ll)1 << x);
		cout << (int)b << "\n";
	}
	else if (oper == "toggle") {
		cin >> x;
		if (s & ((ll)1 << x)) {
			s &= ~((ll)1 << x);
		}
		else {
			s |= (ll)1 << x;
		}
	}
	else if (oper == "all") {
		s |= ((ll)1 << 21) - 1;
	}
	else if (oper == "empty") {
		s = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int m;
	cin >> m;

	ll s = 0;

	for (int i = 0; i < m; i++) {
		calculate(s);
	}
}
