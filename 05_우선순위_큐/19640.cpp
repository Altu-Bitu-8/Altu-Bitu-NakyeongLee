#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Staff {
  int id;
  int l;
  int d;
  int h;
};

struct cmp {
  bool operator()(Staff a, Staff b) {
    if (a.d != b.d)
      return a.d < b.d;
    if (a.h != b.h)
      return a.h < b.h;
    return a.l > b.l;
  }
};

void standInLine(vector<vector<Staff>>& line, int n, int m){
  for (int i = 0; i < n; i++) {
    Staff s;
    s.id = i;
    s.l = i % m;
    cin >> s.d >> s.h;
    line[s.l].push_back(s);
  }
}

void printSequence(vector<vector<Staff>>& line, priority_queue<Staff, vector<Staff>, cmp>& pq, int k){
  int seq = 0;
  int out, l;
  for (int i = 0; i < line.size(); i++) {
    if (line[i].size() > 0) {
      pq.push(line[i][0]);
      line[i].erase(line[i].begin());
    }
  }
  while (!line.empty()) {
    out = pq.top().id;
    l = pq.top().l;
    pq.pop();
    if (out == k)
      break;
    if (line[l].size() > 0) {
      pq.push(line[l][0]);
      line[l].erase(line[l].begin());
    }
    seq++;
  }
  cout << seq;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<Staff>> line(m);
  priority_queue<Staff, vector<Staff>, cmp> pq;

  standInLine(line, n, m);
  printSequence(line, pq, k);
}
