#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	queue<int> card;

	for (int i = 1; i <= n; i++) {
		card.push(i);
	}

	int top;
	while (card.size() > 1) {
		card.pop();
		top = card.front();
		card.pop();
		card.push(top);
	}

	cout << card.front();
}
