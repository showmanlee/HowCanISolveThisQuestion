// 정육면체의 네 꼭짓점
// https://www.acmicpc.net/problem/31945

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<int> v(3);
        for (int i = 0; i < 4; i++) {
            int p;
            cin >> p;
            for (int j = 0; j < 3; j++) {
                v[j] += p % 2;
                p /= 2;
            }
        }
        int res = false;
        for (int j = 0; j < 3; j++) {
            if (v[j] == 0 || v[j] == 4) {
                res = true;
                break;
            }
        }
        cout << (res ? "YES" : "NO") << '\n';
    }
}

// 각 좌표의 점 4개가 모두 정육면체 한 면 위에 있는지 확인하기

// 좌표를 이진수처럼 생각하면, 각 자릿수의 합이 0이나 4명면 된다