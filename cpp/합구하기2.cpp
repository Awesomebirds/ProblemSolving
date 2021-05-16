#include <iostream>
#include <stdio.h>

using namespace std;

void solve(int data[], int n, int p, int q){
  int count = 0, sum = 0;  //초기화

  for(int i = 0; i < n; i++){
    //data 배열의 길이만큼 반복
    if(data[i] <= p){
      //data[i]가 p보다 작거나 같을 때:
      count++; //count 증가
      sum += data[i]; //sum에 data[i]를 더해줌
    }
  }

  printf("%d %d\n", count, sum);  //count와 sum 출력
  if(sum < q){
    //합계 sum이 총 무게 제한 q보다 작으면
    printf("YES");
  } else {
    //합계 sum이 총 무게 제한 q보다 크면
    printf("NO");
  }
}

int main(){
  int n, p, q;
  int *data;

  scanf("%d %d %d", &n, &p, &q);
  data = new int[n];
  for (int i = 0; i < n; i++){
    scanf("%d", &data[i]);
  }

  solve(data, n, p ,q);

  delete[] data;
  return 0;
}