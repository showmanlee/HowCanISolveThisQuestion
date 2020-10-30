// Day 4: Count Objects
// https://www.hackerrank.com/challenges/js10-count-objects/problem

function getCount(objects) {
    let count = 0;
    for (let i = 0; i < objects.length; i++){
        if (objects[i].x == objects[i].y)
            count++;
    }
    return count;
}

// 객체 순회하기
// 검색해보니까 reduce 함수를 써도 된다고 하는데, 이거 끝나고 나서 따로 책을 사서 한번 싹 훑어야 될듯