class Crane {
  private board: Array<Array<number>>;
  private stack: Array<number> = [];

  constructor(board: Array<Array<number>>) {
    this.board = board;
  }

  play = (moves: Array<number>): number => {
    let count = 0;

    moves.forEach((move) => {
      move--;
      this.board.forEach((line) => {
        if (line[move] == 0) return; //비어있는지 검사

        if (this.stack && this.stack[this.stack.length - 1]) {
          //스택의 맨 위 요소가 꺼낸 인형과 같을 경우
          this.stack.pop(); //맨 위 요소를 제거함
          count++; //카운트 증가
          console.log(this.board);
        } else {
          this.stack.push(line[move]); //스택에 꺼낸 인형을 넣어줌
        }

        line[move] = 0; //인형을 꺼낸 공간은 비어있는 것으로 바꿈
      });
    });

    return count;
  };
}

const solution = (
  board: Array<Array<number>>,
  moves: Array<number>
): number => {
  const myCrane = new Crane(board);
  var answer = myCrane.play(moves);
  console.log(answer);

  return answer;
};

solution(
  [
    [0, 0, 0, 0, 0],
    [0, 0, 1, 0, 3],
    [0, 2, 5, 0, 1],
    [4, 2, 4, 4, 2],
    [3, 5, 1, 3, 1],
  ],
  [1, 5, 3, 5, 1, 2, 1, 4]
);
