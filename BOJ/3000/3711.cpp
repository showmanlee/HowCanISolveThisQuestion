// 학번
// https://www.acmicpc.net/problem/3711

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        for (int i = 1; i <= 999999; i++) {
            bool res = true;
            vector<int> check;
            for (int j = 0; j < n; j++) {
                if (find(check.begin(), check.end(), v[j] % i) != check.end()) {
                    res = false;
                    break;
                }
                check.push_back(v[j] % i);
            }
            if (res) {
                cout << i << '\n';
                break;
            }
        }
    }
}

// 주어진 정수들을 나눴을 때 나머지가 모두 다르게 나오는 가장 작은 정수 구하기

// 범위가 작아서 브루트포스로 돌려도 됨 - 나머지 카운트 보고 중복 나오면 넘기기