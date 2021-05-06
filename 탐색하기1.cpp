#include <iostream>
#include <stdio.h>

using namespace std;

//인덱스를 찾아주는 함수
int findIndex(int data[], int n, int m){
  int index = -1;  //인덱스 초기화

  for(int i = 0; i < n; i++){
    //data 배열의 길이만큼 반복
    if(data[i] == m){
      //data[i]가 찾는 값 m과 같으면
      index = i;  //인덱스에 i를 넣어줌
    }
  }
  return index;
}

int main(){
  int n, m;
  int *data;

  scanf("%d %d", &n, &m);
  data = new int[n];
  for (int i = 0; i < n; i++){
    scanf("%d", &data[i]);
  }

  int answer = findIndex(data, n, m);

  printf("%d\n", answer);

  delete[] data;
  return 0;
}