function solution(arr) {
    if (arr.length === 1)
        return [-1];
    var min = {
        value: Number.MAX_SAFE_INTEGER,
        index: 0
    };
    for (var i = 0; i < arr.length; i++) {
        if (arr[i] < min.value) {
            min.value = arr[i];
            min.index = i;
        }
    }
    arr.splice(min.index, 1);
    return arr;
}
