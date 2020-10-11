// Minimum Absolute Difference in an Array
// https://www.hackerrank.com/challenges/minimum-absolute-difference-in-an-array/

int minimumAbsoluteDifference(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int min = 2100000000;
    for (int i = 0; i < arr.size() - 1; i++){
        int g = abs(arr[i] - arr[i+1]);
        if (g < min)
            min = g;
    }
    return min;
}
// arr 길이가 10만이라서 n^2로 풀면 타임아웃 발생
// sort(퀵 정렬 기반, nlogn)으로 소팅하고 배열 순회 한 번만 하면 해결 가능
// 참고로 이거 그리디 문제