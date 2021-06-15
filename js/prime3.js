const isPrime = (num) => {
  for (let i = 2; i < num; i++) {
    if (num % i === 0) {
      //약수가 존재함
      return false;
    }
  }
  return true;
};

function solution(nums) {
  var answer = 0;
  const set = [];

  const n = nums.length;
  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      for (let k = j + 1; k < n; k++) {
        set.push([nums[i], nums[j], nums[k]]);
      }
    }
  }

  set.forEach((array) => {
    const sum = array[0] + array[1] + array[2];
    if (isPrime(sum)) answer++;
  });

  return answer;
}
