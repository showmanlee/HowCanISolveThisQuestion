// 모험의 시작
// https://www.acmicpc.net/problem/31789

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, x, s;
    cin >> n >> x >> s;
    bool res = false;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a <= x && b > s) {
            res = true;
        }
    }
    cout << (res ? "YES" : "NO") << '\n';
}

// n개의 무기 중 가격이 x 이하면서 공격력이 s를 넘는 무기가 있는지 확인하기