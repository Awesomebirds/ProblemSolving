function solution(s) {
  var answer = "";
  let num;
  if (s.length % 2 === 1) {
    //s가 홀수일 때
    num = Math.floor(s.length / 2);
    answer = s.charAt(num);
  } else {
    num = s.length / 2;
    answer = s.charAt(num - 1) + s.charAt(num);
  }
  return answer;
}
