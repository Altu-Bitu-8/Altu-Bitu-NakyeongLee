#include <deque>
#include <iostream>
#include <vector>

using namespace std;

vector<int> findDirections(vector<deque<int>> &wheel, int id,
                           int first_direction) {
  vector<int> directions(wheel.size(), 0);
  directions[id - 1] = first_direction;

  for (int i = id - 1; i > 0; i--) {
    if (wheel[i][6] == wheel[i - 1][2])
      break;
    directions[i - 1] = -1 * directions[i];
  }

  for (int i = id - 1; i < wheel.size() - 1; i++) {
    if (wheel[i][2] == wheel[i + 1][6])
      break;
    directions[i + 1] = -1 * directions[i];
  }
  return directions;
}

void spinEach(deque<int> &wheel, int direction) {
  if (direction == 1) {
    wheel.push_front(wheel.back());
    wheel.pop_back();
  } else if (direction == -1) {
    wheel.push_back(wheel.front());
    wheel.pop_front();
  }
}

void spinWheels(vector<deque<int>> &wheel, int id, int first_direction) {
  vector<int> direction = findDirections(wheel, id, first_direction);
  for (int i = 0; i < wheel.size(); i++) {
    if (!direction[i])
      continue;
    spinEach(wheel[i], direction[i]);
  }
}

int getSPoleWheelCount(vector<deque<int>> &wheel) {
  int cnt = 0;
  for (int i = 0; i < wheel.size(); i++) {
    if (wheel[i].front())
      cnt++;
  }
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, k;
  cin >> t;

  vector<deque<int>> wheel(t);

  string pole;
  for (int i = 0; i < t; i++) {
    cin >> pole;
    for (int j = 0; j < pole.size(); j++) {
      wheel[i].push_back(pole[j] - '0');
    }
  }

  cin >> k;
  int id, first_direction;
  for (int i = 0; i < k; i++) {
    cin >> id >> first_direction;
    spinWheels(wheel, id, first_direction);
  }

  cout << getSPoleWheelCount(wheel);
}
