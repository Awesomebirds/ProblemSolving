function solution(n: number) {
  const parsedN = n.toString();
  const nArray = parsedN.split("");
  nArray.sort();
  nArray.reverse();
  const answer = nArray.join("");
  return parseInt(answer);
}

solution(12345320);
