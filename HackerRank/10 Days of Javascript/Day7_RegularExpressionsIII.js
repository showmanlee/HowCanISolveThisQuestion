// Day 7: Regular Expressions III
// https://www.hackerrank.com/challenges/js10-regexp-3/problem

function regexVar() {
    const str = /\d+/g;
    const re = new RegExp(str);
    return re;
}


function main() {
    const re = regexVar();
    const s = readLine();
    
    const r = s.match(re);
    
    for (const e of r) {
        console.log(e);
    }
}

// 문자열.match(정규식) = 일치하는 문자열의 배열 반환(문자열에 .붙이기)
// .search(정규식) = 일치하는 문자열의 인덱스 반환 
// 뜻: 숫자(\d)가 1개 이상 반복되는(+) 문자열 여러 개(g) 찾기