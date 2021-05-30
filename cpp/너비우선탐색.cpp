#include <iostream>
#include <queue>

using namespace std;

int map[10][10] = {0}; //인접행렬
int visited[10] = {0}; //방문한 노드: 1, 방문하지 않은 노드: 0
queue<int> q; //큐 생성
int num, edge_num; //노드와 간선 개수

void bfs(int v){  
  //너비우선탐색
  cout << v << endl; //현재 노드 출력
  q.push(v); //큐에 노드를 넣음

  while (!q.empty()) { //큐가 비어있을 때까지 반복
    int node = q.front(); //큐에 있는 노드를 꺼냄
    q.pop(); //큐의 맨 앞 노드 삭제
    for(int i = 0; i < num; i++){
      if(map[node][i] == 1 && visited[i] == 0){
        //간선이 존재하고 방문하지 않은 노드일 때
        visited[node] = 1; //방문한 노드로 바꿔줌
        cout << i << endl; //노드정보 출력
        q.push(i); //노드를 큐에 넣음
      }
    }
  }
}

int main(){
  cin >> num >> edge_num; //노드와 간선 개수 입력받음

  for (int i = 0; i < edge_num; i++){
    //간선 개수만큼 반복
    int v1, v2; //간선 정보
    cin >> v1 >> v2; //간선 정보 입력받음
    map[v1][v2] = map[v2][v1] = 1; //방향이 없는 그래프이므로 두개를 한번에 바꿈
  }
  bfs(1); //1부터 너비우선탐색 실행

  return 0;
}