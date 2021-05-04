#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Parenthesis {
  public:
    bool type; //열린 괄호면 true. 닫힌 괄호면 false
    int index; //괄호의 인덱스

    Parenthesis(int index, char c){
      //constructor
      this->index = index;
      if (c == '(') { //열린 괄호인 경우
        this->type = true;
      } else { //닫힌 괄호인 경우
        this->type = false;
      }
    }
};

bool isValidParenthese(vector<Parenthesis> parentheses){
  stack<Parenthesis> myStack; //스택 선언

  for (int i = 0; i < parentheses.size(); i++){ //parentheses 사이즈만큼 반복
    if (parentheses[i].type){ //현재 인덱스의 type이 true일 때(열린 괄호일 때)
      myStack.push(parentheses[i]); //스택에 자료를 추가함
    } else { //닫힌 괄호일 때
      if(myStack.empty()){ //스택이 비어있다면 false 리턴
        return false;
      } else { //스택에 있는 자료를 하나 없앰
        myStack.pop();
      }
    }
  }

  if (myStack.size() != 0) { //스택에 자료가 남아있으면
    return false;
  }

  return true;
}

void process(int caseIndex){
  string str;
  cin >> str; //문자열 입력받음

  vector<Parenthesis> parentheses; //class를 원소로 받는 벡터
  for (int i = 0; i < str.length(); i++){
    parentheses.push_back(Parenthesis(i, str[i])); //받은 문자열을 파싱해서 벡터로 만듬
  }

  bool isValid = isValidParenthese(parentheses); //온전한 괄호인지 검사

  if(isValid) {
    cout << "YES" << endl; //온전하면 YES
  } else {
    cout << "NO" << endl; //온전하지 않으면 NO 출력
  }
}

int main() {
  int caseSize;
  cin >> caseSize; //시행횟수 입력

  for(int caseIndex = 1; caseIndex <= caseSize; caseIndex++){
    process(caseIndex); //시행횟수만큼 반복
  }

  return 0;
}