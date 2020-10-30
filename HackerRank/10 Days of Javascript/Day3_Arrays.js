// Day 3: Arrays
// https://www.hackerrank.com/challenges/js10-arrays/problem

function getSecondLargest(nums) {
    let first = -1, second = -1;
    for (let i = 0; i < nums.length; i++){
        if (nums[i] > first)
            first = nums[i];
    }
    for (let i = 0; i < nums.length; i++){
        if (nums[i] != first && nums[i] > second)
            second = nums[i];
    }
    return second;
}

// 배열에서 두 번째로 큰 원소 뽑아내기
// 배열 내 원소가 중복될 수도 있고, nums.sort()가 있긴 하나 돌리면 문자열 기준으로 정렬되더라
// 배열 선언 -> let a = [1, 2, 3, 4]; or new Array(1, 2, 3, 4); or new Array();