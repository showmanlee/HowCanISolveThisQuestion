// 수들의 합 5
// https://www.acmicpc.net/problem/2018

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int res = 0;
    int l = 1, r = 1;
    int sum = 1;
    while (l <= n) {
        if (sum == n) {
            res++;
        }
        if (sum >= n) {
            sum -= l;
            l++;
        } else {
            r++;
            sum += r;
        }
    }
    cout << res << '\n';
}

// 주어진 자연수를 연속된 자연수의 합으로 나타낼 수 있는 경우의 수 구하기

// 투 포인터를 이용해 구해냅니다 - 최솟값과 최댓값을 이용해 슬라이딩