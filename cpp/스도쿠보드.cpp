#include <iostream>
#include <cstdio>

using namespace std;

const int MAX_ROW = 9;
const int MAX_COL = 9;

class SudokuBoard {
  public:
    //칸의 번호로 행의 번호를 계산하는 메소드
    int getRowByIndex(int index) {
      // 칸의 번호에 대해 마디를 가지고 증가하므로 몫으로 계산할 수 있다.
      return (index - 1) / 9 + 1;
    }

    //칸의 번호로 열의 번호를 계산하는 메소드
    int getColByIndex(int index) {
      //칸의 번호에 대해 규칙적으로 순환하므로 나머지로 계산할 수 있다.
      return (index - 1) % 9 + 1;
    }

    //칸의 번호로 그룹 번호를 계산하는 메소드
    int getGroupByIndex(int index) {
      int r = getRowByIndex(index);
      int c = getColByIndex(index);
      return getGroupByPosition(r, c);
    }

    //칸의 위치 (행, 열)로 그룹 번호를 계산하는 메소드
    int getGroupByPosition(int row, int column){
      int groupRow = ((row - 1) / 3) * 3 + 1; //몫을 구해서 3을 곱한 값에 1을 더해줌(1, 4, 7)
      int groupColumn = (column - 1) / 3; //3으로 나눈 나머지를 구함(0, 1, 2);
      return groupRow + groupColumn;
    }

    //칸의 위치 (행, 열)로 칸의 번호를 계산하는 메소드
    int getIndexByPosition(int row, int column){
      //행과 열의 번호를 구하는 방법을 거꾸로 적용하면 구할 수 있음
      return (row - 1) * 9 + (column - 1) % 9 + 1;
    }
};

void process(int caseIndex){
  int index;
  cin >> index;

  SudokuBoard board = SudokuBoard();

  //칸의 번호로 행, 열, 그룹 번호를 계산한다
  int row = board.getRowByIndex(index);
  int col = board.getColByIndex(index);
  int group = board.getGroupByIndex(index);

  cout << "Case #" << caseIndex << ":" << endl;
  cout << row << col << group << endl;
}

int main() {
  int caseSize;
  cin >> caseSize; //개수 입력받음

  for (int caseIndex = 1; caseIndex <= caseSize; caseIndex++) {
    //개수만큼 반복
    process(caseIndex);
  }
}
  