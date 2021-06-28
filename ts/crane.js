{
    var Crane_1 = /** @class */ (function () {
        function Crane(board) {
            var _this = this;
            this.play = function (moves) {
                var stack = [];
                var count = 0;
                moves.forEach(function (move) {
                    move--;
                    var isBreak = false;
                    _this.board.forEach(function (line) {
                        if (line[move] == 0 || isBreak)
                            return; //비어있는지 검사
                        if (stack && stack[stack.length - 1] == line[move]) {
                            //스택의 맨 위 요소가 꺼낸 인형과 같을 경우
                            stack.pop(); //맨 위 요소를 제거함
                            count++; //카운트 증가
                        }
                        else {
                            stack.push(line[move]); //스택에 꺼낸 인형을 넣어줌
                        }
                        line[move] = 0; //인형을 꺼낸 공간은 비어있는 것으로 바꿈
                        console.log(_this.board);
                        console.log(stack);
                        isBreak = true;
                    });
                });
                return count * 2;
            };
            this.board = board;
        }
        return Crane;
    }());
    var solution = function (board, moves) {
        var myCrane = new Crane_1(board);
        var answer = myCrane.play(moves);
        console.log(answer);
        return answer;
    };
}
