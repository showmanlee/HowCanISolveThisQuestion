// Day 6: Bitwise Operators
// https://www.hackerrank.com/challenges/js10-bitwise/problem

function getMaxLessThanK(n, k){
    let max = 0;
    for (let i = 1; i < n; i++){
        for (let j = i + 1; j <= n; j++){
            let p = i & j;
            if (p < k && p > max)
                max = p;
        }
    }
    return max;
}

// Javascript에서 비트 연산자 쓰기 - 다른 언어와 비슷함(&|^~)