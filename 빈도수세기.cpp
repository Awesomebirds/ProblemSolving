#include <iostream>
#include <map>

using namespace std;

int main () {
  map<int, int> numbers; //key: 입력받은 숫자, value: 빈도수
  int n; //숫자의 개수
  cin >> n; //입력받음

  for (int i = 0; i < n; i++){
    int input; //사용자 입력
    cin >> input; //입력받음

    if(numbers.count(input) == 0){
      //존재하지 않을 때
      numbers[input] = 1;
    } else {
      //존재할 때
      numbers[input]++;
    }

    //C: 현재까지 입력된 숫자의 종류의 수, F: 이 번에 입력된 숫자가 등장한 횟수
    int C, F; 
    C = numbers.size();
    F = numbers[input];

    cout << C << " " << F << endl; //C, F 출력
  }
}