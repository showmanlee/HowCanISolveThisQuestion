// 왕복
// https://www.acmicpc.net/problem/18311

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    bool pass = false;
    for (int i = 0; i < n; i++) {
        k -= v[i];
        if (k < 0) {
            cout << (i + 1) << '\n';
            pass = true;
            break;
        }
    }
    if (!pass) {
        for (int i = n - 1; i >= 0; i--) {
            k -= v[i];
            if (k < 0) {
                cout << (i + 1) << '\n';
                pass = true;
                break;
            }
        }
    }
}

// n개의 구간 포인트가 있는 1차원 공간의 끝에서 끝을 왕복할 때, 이동 거리에 따른 현재 구간 번호 구하기