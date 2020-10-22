// Mini-Max Sum
// https://www.hackerrank.com/challenges/mini-max-sum/problem

void miniMaxSum(vector<int> arr) {
    long long min = 0, max = 0;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < 5; i++){
        if (i != 0)
            max += arr[i];
        if (i != 4)
            min += arr[i];
    }
    cout << min << ' ' << max << '\n';
}

// 5개의 원소가 있는 배열에서 4개를 뽑은 합이 최소인 경우와 최대인 경우 출력