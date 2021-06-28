function solution(arr: number[]): number[] {
  if (arr.length === 1) return [-1];

  const min = {
    value: Number.MAX_SAFE_INTEGER,
    index: 0,
  };

  for (let i = 0; i < arr.length; i++) {
    if (arr[i] < min.value) {
      min.value = arr[i];
      min.index = i;
    }
  }
  arr.splice(min.index, 1);
  return arr;
}
