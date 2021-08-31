#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

/**
* 자연수 N을 구성하는 모든 소인수를 반환하는 함수
*/
vector<int> factorize(int n) {
  vector<int> factors;

  for (int div = 2; div * div <= n; div++){
    while (n % div == 0){
      //div가 N의 약수라면
      // 이 때, div보다 작은 약수는 모두 처리되었으므로 div는 소인수임이 보장된다.

      //소인수 목록에 div를 추가한다.
      factors.push_back(div);

      //N에서 div를 소거해준다.
      // 그러므로 이후에는 div를 제외한 소인수를 찾게 된다.

      n /= div;
    }
  }
  if (n > 1) {
    // 소인수를 찾지 못하고 남아있는 N이 존재한다면, 소수일 수 밖에 없다.
    //이를 소인수에 추가한다.
    factors.push_back(n);
  }

  return factors;
}


void process(int caseIndex) {
  int n;
  cin >> n; //소인수 분해할 수 입력받음

  vector<int> factors = factorize(n); //소인수들의 배열

  cout << "#" << caseIndex << ":" << endl;

  for(int i = 0; i < factors.size(); i++){
    //소인수의 수만큼 반복해서 원소를 출력
    if (i > 0) {
      cout << " ";
    }
    cout << factors[i];
  }
  cout << endl;
}


int main() {
  int caseSize; //사이즈 입력받음 
  cin >> caseSize;

  for (int caseIndex = 1; caseIndex <= caseSize; caseIndex++){
    //사이즈만큼 반복
    process(caseIndex);
  }
}