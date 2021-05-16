#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int getRangeSumFromOne(int i){
  int sum = 0;

  for(int j = 0; j < i; j++){
    //0부터 i까지의 합
    sum += j;
  }

  return sum;
}

long long getAnswer(int n){
  long long answer = 0;

  for(int i = 0; i < n; i++){
    //0부터 i까지의 합의 합
    answer += getRangeSumFromOne(i);
  }
  return answer;
}

int main(){
  int n;

  scanf("%d", &n);
  
  long long answer = getAnswer(n);
  printf("%lld", answer);

  return 0;
} 