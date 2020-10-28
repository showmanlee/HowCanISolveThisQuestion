// Day 2: Conditional Statements: If-Else
// https://www.hackerrank.com/challenges/js10-if-else/problem

function getGrade(score) {
    let grade;
    if (score > 25 && score <= 30)
        grade = 'A';
    else if (score > 20)
        grade = 'B';
    else if (score > 15)
        grade = 'C';
    else if (score > 10)
        grade = 'D';
    else if (score > 5)
        grade = 'E';
    else
        grade = 'F';
    return grade;
}

// Javascript도 if-else문 사용법은 같음
// 비교 연산자도 같음