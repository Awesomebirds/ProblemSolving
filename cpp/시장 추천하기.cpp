#include <iostream>
#include <map>

using namespace std;

int main () {
  int n; //투표용지의 수
  cin >> n; //입력받음

  //key: 후보자 이름, value: 득표 수
  map<string, int> election; 

  int maximum = 0; //최대 득표 수

  for(int i = 0; i < n; i++){
    string input;
    cin >> input; //후보자 이름 입력받음
    
    if(election.count(input) == 0){
      //후보자가 지명된 적 없음
      election[input] = 1;
    } else {
      //후보자가 지명된 적 없음
      election[input]++; //득표 수를 올려줌

      //현재 득표 수가 최다 득표수보다 크면 최다 득표수를 갱신함
      if (election[input] > maximum) maximum = election[input]; 
    }
  }

  cout << maximum << endl; //최다 득표수 출력
  
  map<string, int>:: iterator it;
  for (it = election.begin(); it != election.end(); it++){
    //map 전체 순회
    if (it->second == maximum){
      //최다 득표수를 가진 후보일 때
      cout << it->first << " "; //후보자 이름 출력
    }
  }
}