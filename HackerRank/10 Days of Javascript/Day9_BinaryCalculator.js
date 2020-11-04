// Day 9: Binary Calculator
// https://www.hackerrank.com/challenges/js10-binary-calculator

let res = document.getElementById("res");
function inputChar() {
    res.insertAdjacentHTML('beforeend',this.innerHTML);
}
document.getElementById("btn0").onclick = inputChar;
document.getElementById("btn1").onclick = inputChar;
document.getElementById("btnSum").onclick = inputChar;
document.getElementById("btnSub").onclick = inputChar;
document.getElementById("btnMul").onclick = inputChar;
document.getElementById("btnDiv").onclick = inputChar;
document.getElementById("btnClr").onclick = function() {
    res.innerHTML = "";
};
document.getElementById("btnEql").onclick = function() {
    let matched = res.innerHTML.match(/(\d+)([+\-\*\/])(\d+)/);
    let operand1 = parseInt(matched[1],2);
    let operator = matched[2];
    let operand2 = parseInt(matched[3],2);
    let result;
    switch( operator ) {
        case '+': result = operand1 + operand2; break;
        case '-': result = operand1 - operand2; break;
        case '*': result = operand1 * operand2; break;
        case '/': result = operand1 / operand2; break;
    }
    res.innerHTML = result.toString(2);
};

// 이진법 계산기 만들기
// HTML 문서에 적힌 버튼들에 onclick 리스너를 만든 함수(버튼 안에 있는 글자를 res라는 텍스트박스 뒤에 붙인다?)로 지정
// Clr 버튼을 누르면 보드 클리어
// Eql 버튼을 누르면 정규식으로 연산자와 피연산자 찾고 연산 후 결과 이진수로 반환
// 더 자세히 알고 싶으면 웹 관련 책 하나 사서 차근차근 공부하는 게 맞을 듯