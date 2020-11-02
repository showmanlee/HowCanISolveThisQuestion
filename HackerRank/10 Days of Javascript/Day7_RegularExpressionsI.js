// Day 7: Regular Expressions I
// https://www.hackerrank.com/challenges/js10-regexp-1/problem

function regexVar() {
    let str = /^([aeiou]).*\1$/;
    let re = new RegExp(str);
    return re;
}

function main() {
    const re = regexVar();
    const s = readLine();
    
    console.log(re.test(s));
}

// Javascript의 정규 표현식(RegExp)
// RegExp에 / /로 둘러싸인 특정 문자열을 넣어서 변수를 만들고 거기에 test(문자열)을 돌려 참인지 거짓인지 알아내자
// [aeiou] - 저 다섯 글자 중 하나
// [a-e] - a~e 중 하나
// a|b - a or b
// 대괄호 벗기면 그 글자 그대로 맞는가?
// ^ - ~로 시작하는가?
// $ - ~로 끝나는가?
// . - 임의의 1문자
// * - 0회 이상 반복되는 문자와 가능한 많이 일치(? 붙으면 적게 일치)
// + - 1회 이상 반복되는 문자와 가능한 많이 일치(? 붙으면 적게 일치)
// ? - 없거나 1회 일치(? 붙으면 적게 일치)
// (가능한 많이는 ~이상 붙는 걸 찾으려고 하지만, 적게는 최대한 찾지 않으려고 함)
// {2,5} - 2회 이상 5회 이하 연속 일치
// \1~9 - 캡처(소괄호로 묶인 표현식)한 표현식을 사용
// /abcde/? - 뒤에 flag 문자로...
// g - 문자열 전체 확인
// i - 대소문자 무시
// m - ^, $에서 개행 허용
// s - .에서 개행 허용
// y - 특정 인덱스만 확인
// u - 유니코드로 처리

// 정규 표현식 관련 좋게 정리한 사이트
// https://heropy.blog/2018/10/28/regexp/
