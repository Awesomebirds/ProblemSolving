const makeRank = (number) => {
  switch (number) {
    case 6:
      return 1;
    case 5:
      return 2;
    case 4:
      return 3;
    case 3:
      return 4;
    case 2:
      return 5;
    default:
      return 6;
  }
};

function solution(lottos, win_nums) {
  var answer = [];
  let count = 0;
  let zero = 0;
  lottos.forEach((lotto) => {
    if (lotto === 0) zero++;

    win_nums.forEach((num) => {
      if (lotto === num) count++;
    });
  });
  answer.push(makeRank(count), makeRank(count + zero));
  return answer;
}
