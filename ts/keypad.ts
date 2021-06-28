{
  type HandType = "left" | "right";

  class KeyPad {
    private pad = [
      [1, 2, 3],
      [4, 5, 6],
      [7, 8, 9],
      [10, 0, 11],
    ];
    private state = {
      left: [3, 0],
      right: [3, 2],
    };
    private handType: HandType;

    constructor(handType: HandType) {
      this.handType = handType;
    }

    private difference(a: number[], b: number[]) {
      if (a.length < 2 || b.length < 2) {
        throw new Error("인덱스가 잘못되었습니다.");
      }
      let result: number;
      result = Math.abs(a[0] - b[0]) + Math.abs(a[1] - b[1]);
      return result;
    }

    private press = (hand: "L" | "R", index: number[]) => {
      if (hand === "L") {
        this.state.left = index;
        return "L";
      } else {
        this.state.right = index;
        return "R";
      }
    };

    private pressNumber = (number: number): "L" | "R" => {
      let result: "L" | "R";
      let index: number[];

      for (let i = 0; i < this.pad.length; i++) {
        for (let j = 0; j < this.pad[i].length; j++) {
          if (this.pad[i][j] === number) index = [i, j];
        }
      }

      if (index[1] === 0) {
        //왼쪽 줄
        result = this.press("L", index);
      } else if (index[1] === 2) {
        //오른쪽 줄
        result = this.press("R", index);
      } else {
        //가운데 줄
        const leftDifference = this.difference(this.state.left, index);
        const rightDifference = this.difference(this.state.right, index);
        if (leftDifference < rightDifference) {
          //왼쪽이 더 가까울 때
          result = this.press("L", index);
        } else if (leftDifference > rightDifference) {
          //오른쪽이 더 가까울 때
          result = this.press("R", index);
        } else {
          //같을 때
          if (this.handType === "left") {
            result = this.press("L", index);
          } else {
            result = this.press("R", index);
          }
        }
      }

      return result;
    };

    public pressNumbers = (numbers: Array<number>): string => {
      let answer = "";
      numbers.forEach((num) => {
        answer += this.pressNumber(num);
      });
      return answer;
    };
  }

  function solution(numbers, hand) {
    const myKeyPad = new KeyPad(hand);
    const answer = myKeyPad.pressNumbers(numbers);
    return answer;
  }
}
