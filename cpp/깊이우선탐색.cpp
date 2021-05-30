#include <iostream>

using namespace std;

int maps[10][10]; //인접행렬
int visited[10] = {0}; //방문한 노드: 0, 방문하지 않은 노드: 1
int num; //간선 개수
void init() {
  //초기화 함수
  for (int i = 0; i < 10; i++){
    //10번 반복
    for (int j = 0; j < 10; j++){
      //10번 반복
      maps[i][j] = 0; //0으로 초기화
    }
  }
}

void dfs(int v){  
  //깊이우선탐색
  cout << v << endl; //현재 노드 출력
  visited[v] = 0; //반복을 피하기 위해 방문한 노드로 바꿔줌
  for (int i = 0; i <= num; i++){
    //간선의 수만큼 반복
    if(maps[v][i] && visited[i])
      //노드를 잇는 간선이 존재하고, 방문하지 않은 노드일 때
      dfs(i); //재귀적으로 깊이우선 탐색 실행
  }
}

int main(){
  int v1, v2; //간선
  init(); //행렬 초기화
  cin >> num; //간선 개수 입력받음

  for (int i = 0; i < num; i++){
    //간선 개수만큼 반복
    cin >> v1 >> v2; //간선 정보 입력받음
    maps[v1][v2] = maps[v2][v1] = 1; //방향이 없는 그래프이므로 두개를 한번에 바꿈
    visited[v1] = visited[v2] = 1; //방문하지 않은 노드로 설정
  }
  dfs(1); //1 부터 깊이우선탐색 실행

  return 0;
}