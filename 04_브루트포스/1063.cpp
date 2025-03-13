#include <iostream>
#include <string>

using namespace std;

void R(pair<int, int>& obj){
  obj.first = obj.first + 1;
}

void L(pair<int, int>& obj){
  obj.first = obj.first - 1;
}

void B(pair<int, int>& obj){
  obj.second = obj.second - 1;
}

void T(pair<int, int>& obj){
  obj.second = obj.second + 1;
}

void RT(pair<int, int>& obj){
  R(obj); T(obj);
}

void LT(pair<int, int>& obj){
  L(obj); T(obj);
}

void RB(pair<int, int>& obj){
  R(obj); B(obj);
}

void LB(pair<int, int>& obj){
  L(obj); B(obj);
}

void moveChess(string how, pair<int, int>& obj){
  if(how == "R") R(obj);
  else if(how == "L") L(obj);
  else if(how == "B") B(obj);
  else if(how == "T") T(obj);
  else if(how == "RT") RT(obj);
  else if(how == "LT") LT(obj);
  else if(how == "RB") RB(obj);
  else if(how == "LB") LB(obj);
}

void moveChessReverse(string how, pair<int, int>& obj){
  if(how == "R") L(obj);
  else if(how == "L") R(obj);
  else if(how == "B") T(obj);
  else if(how == "T") B(obj);
  else if(how == "RT") LB(obj);
  else if(how == "LT") RB(obj);
  else if(how == "RB") LT(obj);
  else if(how == "LB") RT(obj);
}

void moveUntilEnds(int n, pair<int, int>& king, pair<int, int>& rock){
  string how;

  for(int i = 0; i < n; i++){
    cin >> how;

    moveChess(how, king);
    if(king == rock){
      moveChess(how, rock);
      if(king.first < 1 || king.first > 8 || king.second < 1 || king.second > 8 || rock.first < 1 || rock.first > 8 || rock.second < 1 || rock.second > 8){
        moveChessReverse(how, king);
        moveChessReverse(how, rock);
      }
    }
    if(king.first < 1 || king.first > 8 || king.second < 1 || king.second > 8){
      moveChessReverse(how, king);
    }
  }
}

int main(){
  string k, r;
  int n;

  cin >> k >> r >> n;

  pair<int, int> king, rock;
  king.first = k[0] - 'A' + 1;
  king.second = k[1] - '0';
  rock.first = r[0] - 'A' + 1;
  rock.second = r[1] - '0';

  moveUntilEnds(n, king, rock);
  char king_x = king.first + 'A' - 1;
  char rock_x = rock.first + 'A' - 1;
  cout << king_x << king.second << "\n" << rock_x << rock.second;
}
