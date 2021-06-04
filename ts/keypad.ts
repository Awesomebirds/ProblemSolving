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
        this.state.left = index;
        result = "L";
      } else if (index[1] === 2) {
        //오른쪽 줄
        this.state.right = index;
        result = "R";
      } else {
        //가운데 줄
        const leftDifference = this.difference(this.state.left, index);
        const rightDifference = this.difference(this.state.right, index);
        if (leftDifference > rightDifference) {
          //오른쪽이 더 가까울 때
        } else if (leftDifference < rightDifference) {
          //왼쪽이 더 가까울 때
        } else {
          //같을 때
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
}
