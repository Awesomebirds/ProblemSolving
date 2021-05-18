#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Player {
  public:
    int index;

    Player(int index) {
      this->index = index;
    }
};

vector<Player> getDeadPlayersList(int n, int m, const vector<Player>& players){
  //현재 게임에서 제외된 플레이어들의 리스트
  vector<Player> deadPlayers;

  //아직 게임에서 제외되지 않은 플레이어들의 리스트
  queue<Player> playerQueue;

  for(int i = 0; i < n; i++){
    playerQueue.push(players[i]); // 1 2 3 4 5 6 7
  }

  for(int i = 0; i < n; i++){
    //(m-1)명의 사람을 건너뛴다.
    int jump = 1 + (m - 1) % playerQueue.size();
    for (int j = 0; j < jump - 1; j++){
      Player p = playerQueue.front();
      playerQueue.pop();
      playerQueue.push(p); //맨 앞의 원소를 뒤로 보냄
    }

    //m번째 사람은 게임에서 제외한다.
    Player dead = playerQueue.front();
    playerQueue.pop();

    //제외 리스트에 추가한다.
    deadPlayers.push_back(dead);
  }

  return deadPlayers;
}

void process(int caseIndex) {
  int n, m;
  cin >> n >> m; //사람의 수, M입력받음

  vector<Player> players; //인덱스를 가지고 있는 사람들의 벡터 생성
  for(int i = 0; i < n; i++){
    players.push_back(Player(i + 1)); //사람 수만큼 1~n까지 벡터 생성함
  }

  vector<Player> deadPlayers = getDeadPlayersList(n, m, players);

  for(int i = 0; i < n; i++){
    if(i > 0) {
      cout << " "; //공백출력
    }

    Player p = deadPlayers[i];
    cout << p.index; //인덱스 출력
  }

  cout << endl; //줄바꿈
}

int main() {
  int caseSize; //테스트케이스의 횟수
  cin >> caseSize; //사이즈 입력받음

  for(int caseIndex = 1; caseIndex <= caseSize; caseIndex++){
    //테스트사이즈만큼 반복
    process(caseIndex);
  }

  return 0;
}