// Day 0: Data Types
// https://www.hackerrank.com/challenges/js10-data-types/problem

function performOperation(secondInteger, secondDecimal, secondString) {
    const firstInteger = 4;
    const firstDecimal = 4.0;
    const firstString = 'HackerRank ';

    var integer = firstInteger + Number(secondInteger);
    var decimal = firstDecimal + Number(secondDecimal);
    var string = firstString + secondString;

    console.log(integer);
    console.log(decimal);
    console.log(string);
}

// Javascript는 기본적으로 자료형을 선언하지 않아도 된다(동적 형지정) -> 지역/전역 변수는 var, 블록 상수는 const, 블록 범위 변수는 let을 붙여 선언
// 다만 내부적으로는 7개의 자료형으로 나누어짐
// 	Boolean - true, false
// 	null - 흔히 보는 null
// 	undefined - 선언한 변수에 값이 지정되지 않은 경우(== 으로 판독 가능)
//	Number - 정수형 또는 실수형
//	String - 문자열(''이나 ""로 지정)
//	Symbol - 인스턴스가 고유하고 불변인 자료형(??)
// 	Object - 참조형 변수(클래스 객체, 배열, 함수 등등)
// 변수 이름은 문자, _, $, 숫자로 구성(숫자는 첫 글자가 될 수 없음)
// 문자열 형으로 초기화한 변수에 정수형을 넣어도 문제없음 - Javascript의 특성
// 다만 문자열에서 숫자로 명시적 변환하고 싶다면 Number(), parseInt(), parseFloat() 등으로 적용
// 위 문제에서는 second 친구들을 문자열로 받고 있는데, 만약 +를 명시적 형변환 없이 넣었다면 Number들을 문자열로 처리해 계산했을 것
// 그런데 - 등의 연산자에는 오히려 문자열이 숫자로 바뀐다(!) - Javascript의 특성이기 기억해두도록