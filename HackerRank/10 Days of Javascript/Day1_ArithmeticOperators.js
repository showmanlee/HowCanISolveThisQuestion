// Day 1: Arithmetic Operators
// hackerrank.com/challenges/js10-arithmetic-operators/problem

function getArea(length, width) {
    let area;
    area = length * width;
    return area;
}

function getPerimeter(length, width) {
    let perimeter;
    perimeter = 2 * (length + width);  
    return perimeter;
}

// 연산자 체계는 다른 언어와 큰 차이가 없음 
// function의 반환값은 return으로, 그러나 반환하는 자료형(?)을 function 제목부에 달 필요는 없음
// 원리가 Python과 비슷한 듯