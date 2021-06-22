function solution(n) {
  let answer = 0;
  for (let i = 1; i * i <= n; i++) {
    if (n % i === 0) {
      //i가 n의 약수
      answer += i; //나누는 수
      answer += n / i; //몫
    }
  }
  return answer;
}

console.log(solution(12));
