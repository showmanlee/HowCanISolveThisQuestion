// 행운의 수
// https://www.acmicpc.net/problem/9575

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        vector<bool> v(90001);
        int res = 0;
        vector<int> a, b, c;
        int aa, bb, cc;
        cin >> aa;
        for (int i = 0; i < aa; i++) {
            int p;
            cin >> p;
            a.push_back(p);
        }
        cin >> bb;
        for (int i = 0; i < bb; i++) {
            int p;
            cin >> p;
            b.push_back(p);
        }
        cin >> cc;
        for (int i = 0; i < cc; i++) {
            int p;
            cin >> p;
            c.push_back(p);
        }
        for (int i = 0; i < aa; i++) {
            for (int j = 0; j < bb; j++) {
                for (int k = 0; k < cc; k++) {
                    int p = a[i] + b[j] + c[k];
                    if (v[p]) {
                        continue;
                    }
                    int pp = p;
                    bool go = true;
                    while (pp > 0) {
                        if (pp % 10 == 5 || pp % 10 == 8) {
                            pp /= 10;
                        } else {
                            go = false;
                            break;
                        }
                    }
                    if (go) {
                        res++;
                    }
                    v[p] = true;
                }
            }
        }
        cout << res << '\n';
    }
}

// 세 정수 배열에서 원소 하나씩을 고른 합이 5 또는 8로만 구성되는 경우의 수 출력하기

// 직접 모두 돌려볼 수 있음 - 중복 제거하면서 체크해봅시다