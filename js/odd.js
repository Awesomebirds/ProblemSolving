function solution(s) {
  var answer = "";

  const words = s.split(" ");
  const parsedWords = words.map((word) => {
    let temp = "";
    for (let i = 0; i < word.length; i++) {
      if (i % 2 === 0) {
        temp += word.charAt(i).toUpperCase();
      } else {
        temp += word.charAt(i);
      }
    }
    return temp;
  });
  answer = parsedWords.join(" ");

  return answer;
}

console.log(solution("hi my name is haseong"));
