// Day 7: Regular Expressions II
// https://www.hackerrank.com/challenges/js10-regexp-2/problem

function regexVar() {
    const str = /^(Mr\.|Dr\.|Er\.|Ms\.|Mrs\.)\s?[a-z|A-Z]+$/
    const re = new RegExp(str);
    return re;
}


function main() {
    const re = regexVar();
    const s = readLine();
    
    console.log(!!s.match(re));
}

// 뜻: 시작 부분에 Mr., Dr., Er., Ms., Mrs.가 붙고 그 뒤에 공백(\s)이 0~1회 있고(?) 끝부분에 a~z나 A~Z가 1개 이상(+) 있는 경우