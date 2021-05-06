#include <iostream>
#include <cstdio>

using namespace std;

int getMinIndexInRange(int data[], int n, int begin, int end){
  int index = begin; //인덱스에 시작값을 넣음

  for (int i = begin; i <= end; i++){
    //인덱스가 end값에 도달할 때까지 반복
    if(data[index] > data[i]){
      //data[i]가 기존의 최소값 data[index]보다 작을 때
      index = i;  //인덱스를 업데이트함
    }
  }
  return index;
}

void selectionSort(int data[], int n){
  for (int i = 0; i < n; i++){
    //주어진 범위에서 가장 작은 원소의 위치를 찾는다.
    int minIndex =  getMinIndexInRange(data, n, i, n - 1);

    //2개 위치를 바꿔주는 로직
    int temp = data[minIndex];
    data[minIndex] = data[i];
    data[i] = temp;
  }
}

int main(){
  int n;
  int *data;

  scanf("%d", &n);
  data = new int[n];

  for(int i = 0; i < n; i++){
    scanf("%d", &data[i]);
  }

  selectionSort(data, n);

  for(int i = 0; i < n; i++){
    if (i > 0){
      printf(" ");
    }
    printf("%d", data[i]);
  }

  delete[] data;
  return 0;
} 