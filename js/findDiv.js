const isDiv = (n) => {
  for (let i = 2; i * i <= n; i++) {
    if (n % i === 0) return false;
  }
  return true;
};

function solution(n) {
  let count = 0;
  for (let i = 2; i <= n; i++) {
    if (isDiv(i)) count++;
  }
  return count;
}
