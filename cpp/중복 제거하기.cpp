#include <iostream>
#include <set>

using namespace std;

int main() {
  int n;  //정수의 개수
  cin >> n; //개수 입력받음

  set<int> s; //이전까지 등장한 모든 정수를 저장한 집합
  for(int i = 0; i < n; i++){
    int input; //사용자 입력
    cin >> input; //입력받음

    if (s.find(input) != s.end()){
      //존재함
      cout << "DUPLICATED" << endl;
    } else {
      //존재하지 않음
      cout << "OK" << endl;
    }
    s.insert(input); //세트에 사용자 입력을 추가함
  }

  return 0;
}