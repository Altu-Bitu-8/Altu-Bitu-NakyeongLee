#include <iostream>
#include <queue>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int n, m;
  cin >> n;

  priority_queue<int, vector<int>, greater<int>> pq;

  for(int i=0; i<n*n; i++){
    cin >> m;
    pq.push(m);
    while(pq.size() > n){
      pq.pop();
    }
  }
  cout << pq.top();
}
