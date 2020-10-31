// Day 5: Inheritance
// https://www.hackerrank.com/challenges/js10-inheritance/problem

class Rectangle {
    constructor(w, h) {
        this.w = w;
        this.h = h;
    }
}

Rectangle.prototype.area = function(){
    return this.w * this.h;
}

class Square extends Rectangle{
    constructor(s){
        super(s, s);
    }
}

// 사실 Javascript에는 클래스란 개념이 없다 - 프로토타입이 있을 뿐
// 지금 쓰고 있는 class, extends는 사용자 편의를 위해 나중에 생긴 문법
// prototype은 초기값(그리고 함수)를 저장하는 어떤 오브젝트 - 여기에 있는 오브젝트는 해당 '클래스'(정확히는 함수) 기반의 모든 '객체'가 사용할 수 있다
// 함수가 생성되면 어딘가에 프로토타입 객체도 생성된다 - 이름.prototype으로 접근 가능
// 오브젝트는 함수를 constructor로 가지고, __proto__로 그 함수의 prototype 객체를 가리킨다(?)