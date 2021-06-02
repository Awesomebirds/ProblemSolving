{
  function solution(array: Array<number>, commands: Array<Array<number>>) {
    var answer = [];
    commands.forEach((command) => {
      const begin = command[0] - 1;
      const end = command[1];
      const num = command[2] - 1;

      const slicedArray = array.slice(begin, end);
      console.log(slicedArray);
      const sortedArray = slicedArray.sort((a, b) => a - b);
      answer.push(sortedArray[num]);
    });
    return answer;
  }

  console.log(
    solution(
      [1, 5, 2, 6, 3, 7, 4],
      [
        [2, 5, 3],
        [4, 4, 1],
        [1, 7, 3],
      ]
    )
  );
}
