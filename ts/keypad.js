{
    var KeyPad_1 = /** @class */ (function () {
        function KeyPad(handType) {
            var _this = this;
            this.pad = [
                [1, 2, 3],
                [4, 5, 6],
                [7, 8, 9],
                [10, 0, 11],
            ];
            this.state = {
                left: [3, 0],
                right: [3, 2]
            };
            this.press = function (hand, index) {
                if (hand === "L") {
                    _this.state.left = index;
                    return "L";
                }
                else {
                    _this.state.right = index;
                    return "R";
                }
            };
            this.pressNumber = function (number) {
                var result;
                var index;
                for (var i = 0; i < _this.pad.length; i++) {
                    for (var j = 0; j < _this.pad[i].length; j++) {
                        if (_this.pad[i][j] === number)
                            index = [i, j];
                    }
                }
                if (index[1] === 0) {
                    //왼쪽 줄
                    result = _this.press("L", index);
                }
                else if (index[1] === 2) {
                    //오른쪽 줄
                    result = _this.press("R", index);
                }
                else {
                    //가운데 줄
                    var leftDifference = _this.difference(_this.state.left, index);
                    var rightDifference = _this.difference(_this.state.right, index);
                    if (leftDifference < rightDifference) {
                        //왼쪽이 더 가까울 때
                        result = _this.press("L", index);
                    }
                    else if (leftDifference > rightDifference) {
                        //오른쪽이 더 가까울 때
                        result = _this.press("R", index);
                    }
                    else {
                        //같을 때
                        if (_this.handType === "left") {
                            result = _this.press("L", index);
                        }
                        else {
                            result = _this.press("R", index);
                        }
                    }
                }
                return result;
            };
            this.pressNumbers = function (numbers) {
                var answer = "";
                numbers.forEach(function (num) {
                    answer += _this.pressNumber(num);
                });
                return answer;
            };
            this.handType = handType;
        }
        KeyPad.prototype.difference = function (a, b) {
            if (a.length < 2 || b.length < 2) {
                throw new Error("인덱스가 잘못되었습니다.");
            }
            var result;
            result = Math.abs(a[0] - b[0]) + Math.abs(a[1] - b[1]);
            return result;
        };
        return KeyPad;
    }());
    function solution(numbers, hand) {
        var myKeyPad = new KeyPad_1(hand);
        var answer = myKeyPad.pressNumbers(numbers);
        return answer;
    }
}
