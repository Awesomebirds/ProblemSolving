#include <iostream>
#include <vector>

using namespace std;

class TicketTable {
  public:
    vector<bool> used;
    int length;

    //생성자
    TicketTable(int length) {
      this->length = length; //
      this->used.assign(length, false);
    }

    /**
    * 사용자의 회원 번호로 지급받게 될 행운권 번호를 계산하는 메소드
    */
    int findEmptyIndexByUserId(int userId) {
      int index = userId % length; //가장 초기에 시도 할 티켓 번호
      while (this->isEmpty(index) == true) { // 사용된 티켓 번호라면 건너 뛴다.
        index = (index + 1) % length; //다음 번호를 조사해나간다.
      }
      return index; // 사용되지 않은 인덱스를 찾아서 반환한다.
    }

    /**
    * 해당 행운권 번호가 이미 사용중인지 여부를 반환하는 메소드
    */
    bool isEmpty(int ticketIndex){
      return this->used[ticketIndex]; // 사용 여부 <==> used[ticketIndex]
    }

    /**
    * 티켓 사용 여부를 갱신하기 위한 메소드
    */
    void setUsed(int index, bool status){
      used[index] = status;
    }
};

//최종적으로 티켓 번호를 구하는 함수
vector<int> getTicketNumbers(int n, int m, const vector<int>& ids){
  vector<int> tickets;
  TicketTable table = TicketTable(n); //티켓 수만큼의 공간을 가짐

  for(int i = 0; i < m; i++){
    int userId = ids[i];
    int ticketIndex = table.findEmptyIndexByUserId(userId); //티켓 번호 찾아냄
    tickets.push_back(ticketIndex); //찾은 번호를 배열의 맨 끝에 추가함
    table.setUsed(ticketIndex, true); //사용한 티켓번호를 사용한 상태로 바꿔줌
  }

  return tickets;
}

int main() {
  //n: 전체 티켓의 수
  //m: 요청 고객의 수
  int n, m;
  cin >> n >> m;

  vector<int> ids(m);
  for (int i = 0; i < m; i++){
    cin >> ids[i]; //고객 번호 입력받음
  }

  vector<int> tickets = getTicketNumbers(n, m, ids);
  for (int i = 0; i < tickets.size(); i++){
    cout << tickets[i]; //티켓 번호 출력
  }
}