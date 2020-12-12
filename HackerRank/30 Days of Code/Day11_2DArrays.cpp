// Day 11: 2D Arrays
// https://www.hackerrank.com/challenges/30-2d-arrays/problem

#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    int max = -80;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            int sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1] + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            if (max < sum)
                max = sum;
        }
    }
    cout << max << '\n';
    return 0;
}

// 6x6 배열에서 나오는 3x3 모래시계 모양의 합 중 최댓값 구하기
// 음수가 나올 수 있음에 주의