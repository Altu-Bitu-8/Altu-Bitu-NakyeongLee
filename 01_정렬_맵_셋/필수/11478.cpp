#include <iostream>
#include <set>

using namespace std;

int main() {
	string s;
	cin >> s;
	int n = s.size();
	set<string> part;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			part.insert(s.substr(j, 1+i));
		}
	}
	cout << part.size();
}
