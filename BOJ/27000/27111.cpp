// 출입 기록
// https://www.acmicpc.net/problem/27111

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<bool> checker(200001);
    int res = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (b == 1) {
            if (checker[a]) {
                res++;
            } else {
                checker[a] = true;
            }
        } else {
            if (!checker[a]) {
                res++;
            } else {
                checker[a] = false;
            }
        }
    }
    for (int i = 0; i < 200001; i++) {
        if (checker[i]) {
            res++;
        }
    }
    cout << res << '\n';
}

// 일부 기록이 누락된 출입 기록이 주어진 상황에서 처음과 끝에는 사람이 없어야 할 때, 누락된 기록 갯수 구하기

// 출입 여부를 bool로 기억하고, 현재 상태에서 대응되는 기록이 들어오지 않은 경우 에러 누적