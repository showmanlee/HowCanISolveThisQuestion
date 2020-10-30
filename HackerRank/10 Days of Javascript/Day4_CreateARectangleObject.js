// Day 4: Create a Rectangle Object
// https://www.hackerrank.com/challenges/js10-objects/problem

function Rectangle(a, b) {
    this.length = a;
    this.width = b;
    this.perimeter = 2 * (a + b);
    this.area = a * b;
}

// 아니, 클래스를 안 만들고 이런 식으로 된다고? - Javascript는 함수도 객체다!
// 정확히는 함수 자체를 new Rectangle(a, b) 같은 식으로 객체로 만들어서 값으로 사용할 수 있다는 것
// 애초에 Javascript의 함수 선언 방식 중에는 var p = function(a, b) { return a + b; } 같은 방식도 있음 -> 함수 자체를 변수의 값으로 사용
// 저 Rectangle은 '생성자 함수'라고 부름 - 말 그대로 생성자 역할을 하는 함수