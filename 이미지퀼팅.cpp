#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <cmath>

using namespace std;

int solve (vector<vector<int> > B1, vector<vector<int> > B2, int H, int W) {
  int point = W - 2; //시작점
  vector<int> SSDVector; //각각의 경계선의 SSD를 담을 벡터
  
  for (int i = point; i > 0; i--){ //오른쪽 두번째부터 왼쪽으로 한칸씩 이동함
    point = i; //경계선 포인트를 i로 초기화함 *경계선 포인트는 바로 위의 경계선의 x좌표임
    int SSD = pow(B1[0][point] - B2[0][point], 2); //SSD초기화 (가장 윗 줄 시작점)

    for (int j = 1; j < H; j++){ //j = 높이; 1부터 시작해서 마지막 인덱스인 H - 1까지 쭉 내려감.
      vector<int> temp; //왼쪽, 오른쪽, 아래를 담을 벡터
      temp.assign(3, INT_MAX); //우선 가장 큰 값으로 저장함. 최소값을 찾아야 하기 때문

      if (point == W - 1){ //현재 위치가 오른쪽 끝일 경우
        temp[0] = pow(B1[j][point - 1] - B2[j][point - 1], 2); //왼쪽의 차이의 제곱
      } if (point == 0){ //현재 위치가 왼쪽 끝일 경우
        temp[2] = pow(B1[j][point + 1] - B2[j][point + 1], 2); //오른쪽의 차이의 제곱
      } else {
        temp[0] = pow(B1[j][point - 1] - B2[j][point - 1], 2); //왼쪽의 차이의 제곱
        temp[2] = pow(B1[j][point + 1] - B2[j][point + 1], 2); //오른쪽의 차이의 제곱
      }
      temp[1] = pow(B1[j][point] - B2[j][point], 2); //중앙 차이의 제곱

      int minValue = *min_element(temp.begin(), temp.end()); //왼쪽, 중앙, 오른쪽 차이의 제곱 중 가장 작은 값
      if (minValue == temp[0]){ //왼쪽 값이 자연스러운 경우
        point--; //경계선을 왼쪽으로 옮김
      } else if (minValue == temp[2]){ //오른쪽 값이 자연스러운 경우
        point++; //경계선을 오른쪽으로 옮김
      }
      SSD += minValue; //SSD에 이번 값을 추가함
    }
    SSDVector.push_back(SSD); //SSD들의 벡터에 값을 추가함.
  }

  int minSSD = *min_element(SSDVector.begin(), SSDVector.end()); //SSD 벡터의 최소값을 구함
  return minSSD;
}

int main () {
  int H, W;
  cin >> H >> W; //높이 및 너비 입력받음
  vector<vector<int> > B1;
  vector<vector<int> > B2;

  // B1 입력받음
  for (int i = 0; i < H; i++){
    vector<int> temp;
    for (int j = 0; j < W; j++){
      int input;
      cin >> input;
      temp.push_back(input);
    };
    B1.push_back(temp);
  }

  // B2 입력받음
  for (int i = 0; i < H; i++){
    vector<int> temp;
    for (int j = 0; j < W; j++){
      int input;
      cin >> input;
      temp.push_back(input);
    };
    B2.push_back(temp);
  }

  clock_t start = clock(); //시간 측정 시작

  int answer = solve(B1, B2, H, W);

  clock_t end = clock(); //  시간 측정 종료
  cout << answer << endl; //정답 출력
  cout << "실행시간: "<<(double)(end-start)/CLOCKS_PER_SEC  << "초" << "\n"; //시간 출력

  return 0;
}
