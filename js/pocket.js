let answer;

const nums = [3, 1, 2, 3];
const n = nums.length / 2;

const mySet = new Set();
nums.forEach((el) => mySet.add(el));

if (mySet.size < n) {
  answer = mySet.size;
} else {
  answer = n;
}
