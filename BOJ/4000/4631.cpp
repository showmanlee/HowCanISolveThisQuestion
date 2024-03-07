// Symmetric Order
// https://www.acmicpc.net/problem/4631

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int cnt = 0;
    int n;
    while (true) {
        cnt++;
        cin >> n;
        if (n == 0) {
            break;
        }
        vector<string> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector<string> res(n);
        int idx = 0, ridx = n - 1;
        bool side = true;
        for (int j = 0; j < n; j++) {
            if (side) {
                res[idx] = v[j];
                idx++;
            } else {
                res[ridx] = v[j];
                ridx--;
            }
            side = !side;
        }
        cout << "SET " << cnt << '\n';
        for (int i = 0; i < n; i++) {
            cout << res[i] << '\n';
        }
    }
}

// 주어진 문자열 배열을 양 끝부터 교대로 채우기

// 약간(??) 멍청하게 처리해봅시다 - 길이에 따라 나오는 순서대로 갖다 넣기