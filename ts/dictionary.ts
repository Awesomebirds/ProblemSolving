{
  function solve(word: string): number {
    let answer = 0;
    const words = ["A", "E", "I", "O", "U"];
    const init = 1 + Math.pow(words.length, word.length);
    console.log(init);
    return answer;
  }

  solve("AAAAA");
}
