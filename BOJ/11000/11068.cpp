// 회문인 수
// https://www.acmicpc.net/problem/11068

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
        int res = 0;
        for (int i = 2; i <= 64; i++) {
            vector<int> v;
            int nn = n;
            while (nn > 0) {
                v.push_back(nn % i);
                nn /= i;
            }
            bool ress = true;
            for (int j = 0; j < v.size() / 2; j++) {
                if (v[j] != v[v.size() - j - 1]) {
                    ress = false;
                    break;
                }
            }
            if (ress) {
                res = 1;
                break;
            }
        }
        cout << res << '\n';
    }
}

// 주어진 정수를 2~64진법으로 표시했을 때 표기되는 수가 회문이 되는 경우가 있는지 확인하기

// 2~64진수로 만들고, 거기서 회문에 대응하는 위치의 숫자가 모두 동일한지 확인하기
// 만드는 건 배열로다가