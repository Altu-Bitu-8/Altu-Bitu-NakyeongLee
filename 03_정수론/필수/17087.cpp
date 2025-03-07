#include <iostream>
#include <set>

using namespace std;

void getDifferences(set<int>& location, set<int>& diff) {
	auto next = location.begin();
	auto prev = next++;
	while (next != location.end()) {
		diff.insert(*next - *prev);
		prev = next++;
	}
}

int getGcdBetweenTwo(int a, int b) {
	if (b == 0) {
		return a;
	}
	return getGcdBetweenTwo(b, a%b);
}

void getAndPrintGcd(set<int>& diff) {
	if (diff.size() == 1) {
		cout << *diff.begin();
		return;
	}
	auto next = diff.begin();
	auto prev = next++;
	int n = getGcdBetweenTwo(*next, *prev);
	diff.erase(prev);
	diff.erase(next);
	diff.insert(n);
	getAndPrintGcd(diff);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, s, a;
	cin >> n >> s;

	set<int> location, diff;

	location.insert(s);
	for (int i = 0; i < n; i++) {
		cin >> a;
		location.insert(a);
	}

	getDifferences(location, diff);
	getAndPrintGcd(diff);
}
