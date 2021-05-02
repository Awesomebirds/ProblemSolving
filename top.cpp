#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Tower {
  public:
    int index; //인덱스
    int height; //높이
    int targetTowerIndex; // 이 타워의 레이저를 수신하는 타워의 인덱스

    Tower(int index, int height){
      //constructor
      this->index = index;
      this->height = height;
      this->targetTowerIndex = 0;
    }

    //Setter
    void setTargetTowerIndex(int targetTowerIndex) {
      this->targetTowerIndex = targetTowerIndex;
    }

    //Getter
    int getTargetTowerIndex() {
      return this->targetTowerIndex; //타겟 인덱스 게터
    }
};

void findTargetTowers(vector<Tower>& tower) {
  // 현재 다른 타워의 신호를 수신할 가능성이 있는 타워 스택
  stack<Tower> stk; 

  for (int i = 0; i < tower.size(); i++){
    //벡터 크기만큼 반복
    Tower& t = tower[i]; //벡터에 담긴 엘리먼트를 하나씩 담음
    int targetTowerIndex = 0; //타겟 인덱스는 기본적으로 0

    while(stk.empty() == false && stk.top().height < t.height){
      //스택이 비어있지 않고 레이저를 수신하지 못할 때 (작을 때)
      stk.pop();
    }

    if(stk.size() > 0) {
      //스택에 데이터가 있으면 그 인덱스를 가저옴
      targetTowerIndex = stk.top().index;
    }

    t.setTargetTowerIndex(targetTowerIndex); //가져온 인덱스로 타겟을 바꿈

    stk.push(t); //사용한 타워를 스택에 추가함
  }

}

int main() {
  int n;
  cin >> n; //타워 개수 입력받음

  vector<Tower> towers; //타워 클래스를 엘리먼트로 받는 벡터 생성

  for (int i = 0; i < n; i++){
    int height;
    cin >> height; //높이 입력받기
    towers.push_back(Tower(i + 1, height)); //클래스 벡터에 넣음
  }

  findTargetTowers(towers);

  for(int i = 0; i < n; i++){
    if(i > 0) {
      cout << " "; //첫번째를 제외하고 공백 출력
    }

    Tower t = towers[i]; //현재 타워
    int targetIndex = t.getTargetTowerIndex();
    cout << targetIndex; //인덱스 출력
  }
  return 0;
}