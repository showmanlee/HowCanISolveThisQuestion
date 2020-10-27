// Day 0: Hello, World!
// https://www.hackerrank.com/challenges/js10-hello-world/problem

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });
    
    main();    
});

function readLine() {
    return inputString[currentLine++];
}

function greeting(parameterVariable) {
    console.log('Hello, World!');
    console.log(parameterVariable);
}


function main() {
    const parameterVariable = readLine();
    
    greeting(parameterVariable);
}

// 10 Days of Javascript - 10일 만에 끝내는 속성 Javascript
// 지금은 함수에서 입력한 문자열을 출력하는 방법을 설명
// 물론 이것 만으로는 부족할 테니 책이나 인터넷을 통해 더 세부적인 정보를 알아야겠지만, 어쨌든 새로운 언어를 알아보고자 한다
// 그래서 일단은 코드 전체를 가져와봤음
// console.log() = 표준 출력
// 그런데 그를 위해서 위에서 뭘 해줘야 하는 거 같음
// 다른 언어와 비슷하게 끝에 ; 붙이고, //로 각주 처리
// function으로 함수 선언하는 것 같고...