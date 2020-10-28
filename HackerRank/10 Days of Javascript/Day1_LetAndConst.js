// Day 1: Let and Const
// https://www.hackerrank.com/challenges/js10-let-and-const/problem

function main() {
    const PI = Math.PI;
    let r = readLine();
    
    console.log(PI * r * r);
    console.log(PI * r * 2);
}

// let = 지역변수, const = 상수, var = 전역변수
// 참고로 PI 상수는 Math.PI에 저장되어 있음