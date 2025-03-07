#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

void fillWheel(int n, int k,int& curr, bool& normal, vector<char>& wheel) {
	int s;
	char a;

	for (int i = 0; i < k; i++) {
		cin >> s >> a;
		curr += s;
		curr %= n;
		if (wheel[curr] != '?' && wheel[curr] != a) {
			normal = false;
		}
		wheel[curr] = a;
		if (count(wheel.begin(), wheel.end(), a) > 1) {
			normal = false;
		}
	}
}

void printWheel(int n, bool& normal, int& curr, vector<char>& wheel) {

	if (!normal) {
		cout << '!';
		return;
	}

	int end = curr;
	while (true) {
		cout << wheel[curr];
		curr = (curr - 1 + n) % n;
		if (curr == end) {
			break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k, curr;
	bool normal = true;
	cin >> n >> k;
	curr = 0;

	vector<char> wheel(n, '?');

	fillWheel(n, k, curr, normal, wheel);
	printWheel(n, normal, curr, wheel);
}
