// Day 1: Functions
// https://www.hackerrank.com/challenges/js10-function/problem

function factorial(n){
    let ret = 1;
    for (let i = 1; i <= n; i++){
        ret *= i;
    }
    return ret;
}

// 함수는 이런 형식으로 만들면 됨
// 조건문, 반복문은 다른 언어와 비슷 - if-else, switch, while, do while, for 등을 동일하게 사용 가능