function solution(numbers) {
  var answer = [];
  const mySet = new Set();
  for (let i = 0; i < numbers.length; i++) {
    for (let j = i + 1; j < numbers.length; j++) {
      mySet.add(numbers[i] + numbers[j]);
    }
  }
  mySet.forEach((el) => answer.push(el));
  answer.sort((a, b) => a - b);
  return answer;
}
