#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000001;

void getPrimes(vector<bool>& primes) {
	for (int i = 2; i * i < MAX; i++) {
		if (!primes[i]) {
			continue;
		}
		for (int j = i; j * i < MAX; j++) {
			primes[j * i] = false;
		}
	}
}

void findAnswer(int& a, int& b, int n, vector<bool>& primes) {
	for (int i = 3; i <= n / 2; i++) {
		if (primes[i] && primes[n - i]) {
			a = i;
			b = n - i;
			return;
		}
	}
}

void printResult(int a, int b, int n) {
	if (a == 1 || b == 1) {
		cout << "Goldbach's conjecture is wrong.\n";
		return;
	}

	cout << n << " = " << a << " + " << b << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<bool> primes(MAX, true);
	int n, a, b;

	getPrimes(primes);
	
	while (true) {
		cin >> n;
		if (n == 0) {
			break;
		}
		a = 1;
		b = 1;

		findAnswer(a, b, n, primes);
		printResult(a, b, n);
	}
}
