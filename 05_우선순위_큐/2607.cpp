#include <iostream>
#include <vector>

using namespace std;

void fillAlph(vector<int>& alph, string word){
  for(int i = 0; i < word.length(); i++){
    alph[word[i] - 'A']++;
  }
}

bool isSimilarWord(string word, string cmp, vector<int> word_alph, vector<int> cmp_alph){
  int diff = 0;
  for(int i = 0; i < 26; i++){
    diff += abs(word_alph[i] - cmp_alph[i]);
  }
  return diff < 2 || (diff == 2 && word.length() == cmp.length());
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int n;
  cin >> n;

  string word, cmp_word;
  cin >> word;

  vector<int> word_alph, cmp_alph;
  word_alph.assign(26, 0);
  fillAlph(word_alph, word);

  int similar_cnt = 0;

  for(int i=0; i<n-1; i++){
    cin >> cmp_word;
    cmp_alph.assign(26, 0);
    fillAlph(cmp_alph, cmp_word);
    
    if(isSimilarWord(word, cmp_word, word_alph, cmp_alph)){
      similar_cnt++;
    }
  }

  cout << similar_cnt;
}
