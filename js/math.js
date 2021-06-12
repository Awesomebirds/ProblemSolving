function solution(answers) {
  var answer = [];
  const n = answers.length;
  let counts = [0, 0, 0];

  const makePerson1 = (i) => {
    i++;
    if (i % 5 === 0) {
      return 5;
    }
    return i % 5;
  };

  const makePerson2 = (i) => {
    i++;
    if (i % 2 === 1) {
      return 2;
    }
    i = (i / 2) % 4;
    switch (i) {
      case 1:
        return 1;
      case 2:
        return 3;
      case 3:
        return 4;
      case 0:
        return 5;
    }
  };

  const makePerson3 = (i) => {
    const n = Math.floor(i / 2);
    switch (n % 5) {
      case 0:
        return 3;
      case 1:
        return 1;
      case 2:
        return 2;
      case 3:
        return 4;
      case 4:
        return 5;
    }
  };

  for (let i = 0; i < n; i++) {
    if (answers[i] === makePerson1(i)) {
      //1번 수포자
      counts[0]++;
    }
    if (answers[i] === makePerson2(i)) {
      //2번 수포자
      counts[1]++;
    }
    if (answers[i] === makePerson3(i)) {
      //3번 수포자
      counts[2]++;
    }
  }

  const max = Math.max(counts[0], counts[1], counts[2]);
  for (let i = 0; i < 3; i++) {
    if (counts[i] === max) {
      answer.push(i + 1);
    }
  }

  return answer;
}

const answer = [1, 3, 2, 4, 2];
console.log(solution(answer));
