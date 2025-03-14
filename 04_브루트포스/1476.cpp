#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int e, s, m;
  cin >> e >> s >> m;

  int year = s;

  while(true) {
    if((year % 15 == e % 15) && (year % 19 == m % 19)) {
      break;
    }
    year += 28;
  }

  cout << year;
}
