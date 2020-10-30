// Day 3: Try, Catch, and Finally
// https://www.hackerrank.com/challenges/js10-try-catch-and-finally/problem

function reverseString(s) {
    try{
        s = s.split("").reverse().join("")
    }
    catch(e){
        console.log(e.message);
    }
    finally{
        console.log(s);
    }
}

// Javascript의 오류 처리 방식도 다른 언어와 같음
// 오류 e를 catch에서 받고 e.name으로 이름, e.message로 메시지 받기
// s.split("").reverse().join("")의 뜻 - s의 모든 문자를 한 칸씩 쪼개서 배열로 만든 다음 순서를 뒤집고 사이에 ""를 넣어 하나의 문자열로 만들라는 것
