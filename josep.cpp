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

  return deadPlayers;
}

void process(int caseIndex) {
  int n, m;
  cin >> n >> m;

  vector<Player> players;
  for(int i = 0; i < n; i++){
    players.push_back(Player(i + 1));
  }

  vector<Player> deadPlayers = getDeadPlayersList(n, m, players);

  for(int i = 0; i < n; i++){
    if(i > 0) {
      cout << " ";
    }

    Player p = deadPlayers[i];
    cout << p.index;
  }

  cout << endl;
}

int main() {
  int caseSize;
  cin >> caseSize;

  for(int caseIndex = 1; caseIndex <= caseSize; caseIndex++){
    process(caseIndex);
  }

  return 0;
}