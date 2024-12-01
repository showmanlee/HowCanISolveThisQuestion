// 호텔 방 번호
// https://www.acmicpc.net/problem/5671

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m;
    while (cin >> n >> m) {
        int res = 0;
        for (int i = n; i <= m; i++) {
            vector<bool> v(10);
            bool check = true;
            int ii = i;
            while (ii > 0) {
                if (v[ii % 10]) {
                    check = false;
                    break;
                }
                v[ii % 10] = true;
                ii /= 10;
            }
            if (check) {
                res++;
            }
        }
        cout << res << '\n';
    }
}

// n부터 m까지의 자연수 중 같은 숫자가 2개 이상 들어가지 않는 수의 개수 찾기