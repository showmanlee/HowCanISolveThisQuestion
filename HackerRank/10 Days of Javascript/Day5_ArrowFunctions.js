// Day 5: Arrow Functions
// https://www.hackerrank.com/challenges/js10-arrows/problem

function modifyArray(nums) {
    let ret = nums.map(a => (a % 2 == 0 ? a * 2 : a * 3));
    return ret;
}


function main() {
    const n = +(readLine());
    const a = readLine().split(' ').map(Number);
    
    console.log(modifyArray(a).toString().split(',').join(' '));
}

// Javascript판 람다식
// map()은 배열의 각 원소에 괄호 안의 함수를 적용한다는 말