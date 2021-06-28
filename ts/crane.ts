{
  class Crane {
    private board: Array<Array<number>>;

    constructor(board: Array<Array<number>>) {
      this.board = board;
    }

    play = (moves: Array<number>): number => {
      const stack: Array<number> = [];
      let count = 0;

      moves.forEach((move) => {
        move--;
        let isBreak = false;

        this.board.forEach((line) => {
          if (line[move] == 0 || isBreak) return; //비어있는지 검사

          if (stack && stack[stack.length - 1] == line[move]) {
            //스택의 맨 위 요소가 꺼낸 인형과 같을 경우
            stack.pop(); //맨 위 요소를 제거함
            count++; //카운트 증가
          } else {
            stack.push(line[move]); //스택에 꺼낸 인형을 넣어줌
          }

          line[move] = 0; //인형을 꺼낸 공간은 비어있는 것으로 바꿈
          console.log(this.board);
          console.log(stack);
          isBreak = true;
        });
      });

      return count * 2;
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
}
