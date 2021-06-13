function solution(n) {
  var answer = [];

  const stringN = n.toString();
  const array = stringN.split("");
  const reversedArray = array.reverse();
  reversedArray.forEach((el) => {
    answer.push(Number(el));
  });

  return answer;
}

const answer = solution(12345);
console.log(answer);
