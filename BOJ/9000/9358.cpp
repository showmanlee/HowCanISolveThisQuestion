// 순열 접기 게임
// https://www.acmicpc.net/problem/9358

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int len = n;
        while (len > 2) {
            int half = ceil(len / 2.0);
            for (int i = 0; i < half; i++) {
                v[i] += v[len - i - 1];
            }
            len = half;
        }
        cout << "Case #" << t << ": " << (v[0] > v[1] ? "Alice" : "Bob") << '\n';
    }
}

// 주어진 정수 배열을 반으로 접었을 때 만나는 원소끼리 더하는 과정을 반복하여 두개만 남았을 때 어느쪽 수가 더 큰지 판정하기

// 실제로 주어진 대로 접어가며 확인해보기