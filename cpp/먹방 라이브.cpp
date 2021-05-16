#include <iostream>
#include <time.h>
#include <queue>
#include <vector>

using namespace std;

class Dish {
  public:
  int index; //인덱스
  int time; //남은 시간

  Dish(int index, int time){
    //constructor
    this->index = index;
    this->time = time;
  }
};

int solve(queue<Dish> dishes, long long k) {
  for (int i = 0; i < k; i++){
    //중단되기 전까지 반복
    dishes.front().time--; //남은 시간의 1초를 뺌

    if(dishes.front().time == 0){
      //맨 앞에 있는 음식의 남은 시간이 0이라면 없애버림
      dishes.pop();

      if (dishes.size() == 0) return -1; //모든 음식을 먹었다면 반복을 멈추고 -1 리턴
    } else {
      //더 먹어야 한다면
      dishes.push(dishes.front()); //현재 음식을 맨 뒤로 넣어줌
      dishes.pop(); //맨 뒤로 넣은 음식은 없애버림
    }
  }

  return dishes.front().index;
}

int main() {
  int n; //음식의 개수
  cin >> n; //개수입력받음
  queue<Dish> dishes; //음식 클래스 큐

  for (int i = 0; i < n; i++){
    //음식 개수만큼 반복

    int time; //음식을 먹는데 소요되는 시간
    cin >> time; //시간 입력받음

    dishes.push(Dish(i + 1, time)); //인덱스와 시간을 가진 클래스를 큐에 넣음
  }

  long long k; //방송이 중단되는 시간(초)
  cin >> k; //시간 입력받음

  clock_t start = clock();

  int answer = solve(dishes, k);

  clock_t end = clock(); //  시간 측정 종료
  cout << answer << endl; //정답 출력
  cout << "실행시간: "<<(double)(end-start)/CLOCKS_PER_SEC  << "초" << "\n"; //시간 출력

}