function solution(absolutes, signs) {
  let answer = 0;
  for (let i = 0; i < absolutes.length; i++) {
    if (signs[i]) {
      //양수인 경우
      answer += absolutes[i];
    } else {
      //음수인 경우
      answer -= absolutes[i];
    }
  }
  return answer;
}
