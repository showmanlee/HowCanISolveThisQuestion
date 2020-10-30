// Day 4: Classes
// https://www.hackerrank.com/challenges/js10-class/problem

class Polygon{
    constructor(arr){
        this.arr = arr;
    }
    perimeter(){
        let count = 0;
        for (let i = 0; i < this.arr.length; i++)
            count += this.arr[i];
        return count;
    }
}

// 객체를 생성자 함수로 만들 수도 있지만 class를 통해서 만들 수도 있어요
// constructor()는 생성자 -> this.뭐시기로 멤버 변수들을 초기화
// 그 아래 메서드들을 넣을 수 있음 -> constructor로 선언한 멤버 변수는 this.뭐시기로 불러오기
// class가 Javascript에서 근본이 아니라는 얘기도 있던데?