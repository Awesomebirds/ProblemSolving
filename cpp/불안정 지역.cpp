#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class City {
  public:
    int index; //도시 인덱스
    int income; //소득

    City(int index, int income){
      //생성자
      this->index = index;
      this->income = income;
    }

    bool operator < (const City& o) const {
      return this->income < o.income; //소득을 비교하는 연산자
    }

    bool operator > (const City& o) const {
      return this->income > o.income; //소득을 비교하는 연산자
    }
};

int getMaximumDifference(int n, int k, const vector<City>& cities){
  int answer = 0;
  
  //소득이 가장 작은 도시부터 pop되는 우선순위 큐
  priority_queue<City, vector<City>, greater<City> > rangeMinimum;

  //소득이 가장 높은 도시부터 pop되는 우선순위 큐
  priority_queue<City> rangeMaximum;

  for (int i = 0; i < k - 1; i++){
    rangeMaximum.push(cities[i]); //소득이 높은 순서대로 k - 1 개만큼 채움
    rangeMinimum.push(cities[i]); //소득이 낮은 순서대로 k - 1 개만큼 채움
  }
  for (int i = k - 1; i < n; i++){
    rangeMaximum.push(cities[i]); //하나를 넣어줌 (내림차순 자동정렬)
    rangeMinimum.push(cities[i]); //하나를 넣어줌 (오름차순 자동정렬)
    while (rangeMaximum.top().index < i - k + 1) rangeMaximum.pop(); //구역을 벗어난 왼쪽 요소를 빼줌
    while (rangeMinimum.top().index < i - k + 1) rangeMinimum.pop(); //구역을 벗어난 왼쪽 요소를 빼줌
    answer = max(answer, rangeMaximum.top().income - rangeMinimum.top().income); //answer의 최대값을 갱신함
  }

  return answer;
}

void process(){
  int n, k; //n: 도시의 수, k:영역; 연속된 도시의 수
  cin >> n >> k; //입력받음
  vector<City> cities; //City객체를 담은 벡터

  for(int i = 0; i < n; i++){
    //도시의 수만큼 반복
    int income; 
    cin >> income; //각 도시의 소득을 입력받음
    cities.push_back(City(i, income)); //객체를 만들어 넣어줌
  }

  int answer = getMaximumDifference(n, k, cities); //정답도출

  cout << answer << endl; //정답출력
}

int main() {
  int caseSize; //케이스 사이즈
  cin >> caseSize; //입력받음

  for (int caseIndex = 1; caseIndex <= caseSize; caseIndex++){
    //케이스사이즈 만큼 반복
    process();
  }
}