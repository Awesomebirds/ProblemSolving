#include <iostream>
#include <stdio.h>

using namespace std;

void printIndexes(string school[], int n){
  int first = -1; //존재하지 않으면 -1
  int last = -1; //존재하지 않으면 -1
  for(int i = 0; i < n; i++){
    if(school[i] == "AJOU"){
      if(first == -1){
        //first가 -1(초기값)일 때만
        first = i + 1; //first에 i + 1을 넣음
      }
      last = i + 1; //last값은 마지막까지 변화함
    }
  }

  printf("%d %d\n", first, last);
}

int main(){
  int n;
  char buff[11];
  string* school;

  scanf("%d", &n);
  school = new string[n];

  for(int i = 0; i < n; i++){
    scanf("%s", buff);
    school[i] = buff;
  }

  printIndexes(school, n);

  delete[] school;
  return 0;
}