// Day 3: Throw
// https://www.hackerrank.com/challenges/js10-throw/problem

function isPositive(a) {
    if (a == 0)
        throw new Error("Zero Error");
    if (a < 0)
        throw new Error("Negative Error");
    return "YES";
}

// 오류 던지는 건 이렇게