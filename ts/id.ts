{
  const toLower = (id: string): string => id.toLowerCase();

  const eraseSpecialCharacters = (id: string): string => {
    const re = /[^\w|-|_|.]/g;
    const newText = id.replace(re, "");
    return newText;
  };

  const replaceDotsToDot = (id: string): string => {
    const re = /\.{2,}/g;
    const newText = id.replace(re, ".");
    return newText;
  };

  const eraseHeadOrTailDot = (id: string): string => {
    const re = /^\.|$\./g;
    const newText = id.replace(re, "");
    return newText;
  };

  const convertToA = (id: string): string => {
    if (id.length == 0) return "a";
    return id;
  };

  const cutTail = (id: string): string => {
    return eraseHeadOrTailDot(id.slice(0, 15));
  };

  const makeSnake = (id: string): string => {
    while (id.length < 3) {
      id = id + id.charAt(id.length - 1);
    }

    return id;
  };

  const solution = (new_id: string): string => {
    let answer = new_id;

    answer = toLower(answer);
    answer = eraseSpecialCharacters(answer);
    answer = replaceDotsToDot(answer);
    answer = eraseHeadOrTailDot(answer);
    answer = convertToA(answer);
    answer = cutTail(answer);
    answer = makeSnake(answer);

    return answer;
  };

  const new_id = "z-+.^.";
  const answer = solution(new_id);
  console.log(answer);
}
