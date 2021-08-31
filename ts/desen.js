function solution(n) {
    var parsedN = n.toString();
    var nArray = parsedN.split("");
    nArray.sort();
    nArray.reverse();
    var answer = nArray.join("");
    return parseInt(answer);
}
solution(12345320);
