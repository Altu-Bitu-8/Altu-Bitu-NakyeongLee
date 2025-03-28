#include <iostream>

using namespace std;

bool checkForward(int k, int i, string &arr) {
  int index;
  for (int j = k; j > 0; j--) {
    index = i - j;
    if (index < 0)
      continue;
    if (arr[index] == 'H') {
      arr[index] = '0';
      return true;
    }
  }
  return false;
}

bool checkBackward(int k, int i, string &arr, int n) {
  int index;
  for (int j = 0; j < k; j++) {
    index = i + j + 1;
    if (index >= n)
      continue;
    if (arr[index] == 'H') {
      arr[index] = '0';
      return true;
    }
  }
  return false;
}

int countFullPeople(int n, int k, string &arr) {
  int cnt = 0;

  for (int i = 0; i < n; i++) {
    if (arr[i] != 'P') {
      continue;
    }
    if (checkForward(k, i, arr)) {
      cnt++;
      continue;
    }
    if (checkBackward(k, i, arr, n)) {
      cnt++;
    }
  }
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, k;
  cin >> n >> k;

  string arr;
  cin >> arr;

  cout << countFullPeople(n, k, arr);
}
