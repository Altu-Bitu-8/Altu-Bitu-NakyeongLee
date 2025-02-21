#include <iostream>
#include <cmath>

using namespace std;

void getSimpleResult(int w, int i,int i0, int d, int a) {
	int diff = i - a - i0;
	int result_w = w + (d * diff);

	if (result_w <= 0) {
		cout << "Danger Diet\n";
	}
	else {
		cout << result_w << " " << i0 << "\n";
	}
}

void getComplexResult(int w, int i0, int i, int t, int d, int a) {
	int diff;
	int i1 = i0;
	string result;
	for (int j = 0; j < d; j++) {
		diff = i - a - i1;
		w += diff;
		if (w <= 0) {
			cout << "Danger Diet";
			return;
		}
		if (abs(diff) > t) {
			i1 += floor(diff / 2.0);
		}
		if (i1 <= 0) {
			cout << "Danger Diet";
			return;
		}
	}
	result = "NO";
	if (i0 - i1 > 0) {
		result = "YOYO";
	}
	cout << w << " " <<  i1 << " " << result;
}

int main() {
	int w;
	int i0, i;
	int t, d, a;

	cin >> w >> i0 >> t >> d >> i >> a;

	getSimpleResult(w, i, i0, d, a);
	getComplexResult(w, i0, i, t, d, a);

	return 0;
}
