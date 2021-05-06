#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int findIndex(int data[], int n){
  int sum = 0, x = 0;
  
  for(int i = 0; i < n; i++){
    sum += data[i];  //데이터 값을 전부 더함
  }

  for(int i = 0; i < n; i++){
    int dx = abs(n*data[x] - sum); //평균: (값 - 합/n)를 n으로 스케일링함. x는 평균과 가장 가까운 수
    int di = abs(n*data[i] - sum); //데이터의 i번째  수
    if(dx > di){
      //저장된 평균과 가장 가까운 수 dx보다 인덱스번째의 수 di가 평균과 더 가깝다면
      x = i;  //x를 i로 업데이트함
    }
  }
  return x + 1; // 실제 번호는 1부터 시작하기 때문
}

int main(){
  int n;
  int *data;

  scanf("%d", &n);
  data = new int[n];

  for(int i = 0; i < n; i++){
    scanf("%d", &data[i]);
  }

  int answer = findIndex(data, n);
  printf("%d  %d\n", answer, data[answer - 1]);

  delete[] data;
  return 0;
} 