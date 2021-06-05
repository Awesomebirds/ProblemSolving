#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
  for(int i = 0; i < first.length() - 1; i++){
    string el = first.substr(i, 2);
    cout << el <<endl;
  }

  return 0;
}