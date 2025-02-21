#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sumOfDigits(string g) {
	int sum = 0;
	for (char c : g) {
		if (isdigit(c)) {
			sum += c - '0';
		}
	}
	return sum;
}

bool cmpSerial(string g1, string g2) {
	if (g1.size() != g2.size()) {
		return g1.size() < g2.size();
	}
	int sum1 = sumOfDigits(g1);
	int sum2 = sumOfDigits(g2);
	if (sum1 != sum2) {
		return sum1 < sum2;
	}
	return g1 < g2;
}

int main(){
	int n;
	vector<string> guitars;

	cin >> n;
	guitars.assign(n, "");
	for (int i = 0; i < n; i++) {
		cin >> guitars[i];
	}

	sort(guitars.begin(), guitars.end(), cmpSerial);

	for (int i = 0; i < guitars.size(); i++) {
		cout << guitars[i] << '\n';
	}

	return 0;
}
