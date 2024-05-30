// 줄세우기
// https://www.acmicpc.net/problem/10431

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
        int tm;
        cin >> tm;
        vector<int> v;
        int res = 0;
        for (int i = 0; i < 20; i++) {
            int p;
            cin >> p;
            v.push_back(p);
            for (int j = i; j > 0; j--) {
                if (v[j] < v[j - 1]) {
                    swap(v[j], v[j - 1]);
                    res++;
                } else {
                    break;
                }
            }
        }
        cout << tm << ' ' << res << '\n';
    }
}

// 주어진 20개의 수를 앞에서부터 순서대로 채우되, 채운 순간 앞에 더 큰 수가 있을 경우 자리 교체를 할 때, 모든 자리 교체 횟수 구하기

// 이게 그 버블 소팅인가 그런 거예요 - 시키는 대로 처리해줍시다