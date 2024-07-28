// 예비 소집 결과 보고서
// https://www.acmicpc.net/problem/31776

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
    for (int t = 0; t < n; t++) {
        vector<int> v(3);
        for (int i = 0; i < 3; i++) {
            cin >> v[i];
            if (v[i] == -1) {
                v[i] = 987654321;
            }
        }
        bool pass = true;
        if (v[0] <= v[1] && v[1] <= v[2]) {
            if (v[0] == v[1] && v[1] == v[2] && v[2] == 987654321) {
                pass = false;
            }
        } else {
            pass = false;
        }
        if (pass) {
            res++;
        }
    }
    cout << res << '\n';
}

// 세 결과값이 모두 -1이 아니면서 차례대로 비내림차순으로 정렬되거나 끝에 -1만 남는 경우의 수 출력하기
