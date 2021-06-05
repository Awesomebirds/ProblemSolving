#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> makeMultiSet(string word) {
  vector<string> multiSet;
  for(int i = 0; i < word.length() - 1; i++){
    string el = word.substr(i, 2);
    int isContinue = 0;
    for (int j = 0; j < el.length(); j++){
      if(el[j] < 97 || el[j] > 122) isContinue = 1; //[a-z]검사
    }
    if(isContinue == 1) continue;
    multiSet.push_back(el);
  }
  return multiSet;
}

int main() {
  string first, second; //첫번째 문자열, 두번째 문자열 정의
  cin >> first >> second; //문자열 입력받음

  //소문자 변환
  for(int i = 0; i < first.length(); i++){
    first[i] = tolower(first[i]);
  }
  for(int i = 0; i < second.length(); i++){
    second[i] = tolower(second[i]);
  }

  vector<string>  firstMultiSet, secondMultilSet;
  firstMultiSet = makeMultiSet(first);
  secondMultilSet = makeMultiSet(second);
  
  //멀티셋 출력 (확인용)
  for(int i = 0; i < firstMultiSet.size(); i++){
    cout << firstMultiSet[i] << endl;
  }

  for(int i = 0; i < secondMultilSet.size(); i++){
    cout << secondMultilSet[i] << endl;
  }

  return 0;
}