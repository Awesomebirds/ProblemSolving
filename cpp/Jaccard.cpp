#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

int Jaccard(vector<string> firstMultiSet, vector<string> secondMultiSet){
  int firstLength = firstMultiSet.size();
  int secondLength = secondMultiSet.size();

  vector<string> myIntersection;
  for (int i = 0; i < firstMultiSet.size(); i++){
    for(int j = 0; j < secondMultiSet.size(); j++){
      if(firstMultiSet[i] == secondMultiSet[j]){
        myIntersection.push_back(firstMultiSet[i]);
        secondMultiSet.erase(secondMultiSet.begin() + j);
        break;
      }
    }
  }
  
  for(int i = 0; i < myIntersection.size(); i++){
    cout << myIntersection[i] << endl;
  }
  double temp = (double) myIntersection.size() / (double) (firstLength + secondLength - myIntersection.size());
  int jaccard = temp * 65536;
  return jaccard;
}

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
  getline(cin, first);
  getline(cin, second);

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

  clock_t start = clock(); //시간 측정 시작

  int answer = Jaccard(firstMultiSet, secondMultilSet);

  clock_t end = clock(); //  시간 측정 종료
  cout << answer << endl; //정답 출력
  cout << "실행시간: "<<(double)(end-start)/CLOCKS_PER_SEC  << "초" << "\n"; //시간 출력

  return 0;
}