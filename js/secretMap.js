const makeBinaryMap = (number, size) => {
  const mapArray = [];
  for (let i = 0; i < size; i++) {
    if (number % 2 === 1) {
      mapArray.push(1);
      number = (number - 1) / 2;
    } else {
      mapArray.push(0);
      number /= 2;
    }
  }
  mapArray.reverse();
  return mapArray;
};

function solution(n, arr1, arr2) {
  var answer = [];
  const maps = [[], []];
  arr1.forEach((el) => maps[0].push(makeBinaryMap(el, n)));
  arr2.forEach((el) => maps[1].push(makeBinaryMap(el, n)));
  for (let i = 0; i < n; i++) {
    let temp = "";
    for (let j = 0; j < n; j++) {
      if (maps[0][i][j] === 1 || maps[1][i][j] === 1) {
        temp = temp + "#";
      } else {
        temp = temp + " ";
      }
    }
    answer.push(temp);
  }
  return answer;
}
