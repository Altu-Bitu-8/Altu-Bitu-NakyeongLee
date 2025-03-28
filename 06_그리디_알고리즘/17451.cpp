#include <iostream>
#include <vector>

using namespace std;

long findMinSpeed(int n, vector<long> &v) {
  long min_speed = 0, operand;
  for (int i = n - 1; i >= 0; i--) {
    if (v[i] < min_speed) {
      operand = min_speed / v[i];
      if (min_speed % v[i] != 0)
        operand++;
      min_speed = operand * v[i];
    } else {
      min_speed = v[i];
    }
  }
  return min_speed;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  vector<long> v(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  cout << findMinSpeed(n, v);
}
