#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

vector< vector <int> > pulling(vector< vector <int> > matrix){
  int n = matrix.size(); //원래 행렬의 길이
  int pn = n / 2; //우리가 만들 행렬의 길이
  
  vector< vector<int> > pulledMatrix(pn, vector<int>(pn, 0)); //행렬을 0으로 초기화

  for (int i = 0; i < pn * pn; i++){ //행렬의 총 개수만큼 반복
    vector<int> temp; //비교를 위한 임시 배열

    //행렬을 2 * 2로 쪼갰을 때, 작은 행렬의 왼쪽 위의 인덱스
    int indexX = int(i / pn) * 2;
    int indexY = int(i % pn) * 2;

    //구한 인덱스를 기준으로 2 * 2 행렬 값을 가져옴
    temp.push_back(matrix[indexX][indexY]);
    temp.push_back(matrix[indexX+1][indexY]);
    temp.push_back(matrix[indexX][indexY+1]);
    temp.push_back(matrix[indexX+1][indexY+1]);
    sort(temp.begin(), temp.end()); //temp 행렬을 정렬함

    int result = temp[2]; //두 번째로 큰 값
    pulledMatrix[int(i / pn)][int(i % pn)] = result; //우리가 만든 행렬에 그 값을 넣어 줌.
  }

  return pulledMatrix;
}

int main() {
  vector< vector<int> > matrix;
  int n; //정사각형 변의 길이
  cin >> n;

  //행렬 입력받기
  for (int i = 0; i < n; i++){
    vector<int> temp;
    for (int j = 0; j < n; j++){
      int input;
      cin >> input;
      temp.push_back(input);
    };
    matrix.push_back(temp);
  }

  clock_t start = clock(); //시간 측정 시작

  //행렬의 크기가 1이 될때까지 반복함
  for (int i = n; i > 1; i = i / 2){
    matrix = pulling(matrix);
  }

  clock_t end = clock(); //  시간 측정 종료

  int answer = matrix[0][0]; //하나 남은 값
  
  cout << answer << endl; //정답 출력
  cout << "실행시간: "<<(double)(end-start)/CLOCKS_PER_SEC  << "초" << "\n"; //시간 출력

 return 0; 
}