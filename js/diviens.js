const isPrimeOdd = (num) => {
  let count = 2;
  for (let i = 2; i < Math.sqrt(num); i++) {
    if (num % i === 0) {
      count += 2;
    }
  }
  if (num % Math.sqrt(num) === 0) count++;
  if (count % 2 === 1) {
    return true;
  } else {
    return false;
  }
};

function solution(left, right) {
  var answer = 0;
  for (let i = left; i <= right; i++) {
    if (isPrimeOdd(i)) {
      answer -= i;
    } else {
      answer += i;
    }
  }
  return answer;
}
