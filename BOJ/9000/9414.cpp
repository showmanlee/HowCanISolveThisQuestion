// 프로그래밍 대회 전용 부지
// https://www.acmicpc.net/problem/9414

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
    for (int t = 0; t < tt; t++) {
        vector<long long> v;
        while (true) {
            long long p;
            cin >> p;
            if (p == 0) {
                break;
            }
            v.push_back(p);
        }
        sort(v.begin(), v.end(), greater<int>());
        long long res = 0;
        for (long long i = 0; i < v.size(); i++) {
            res += 2 * pow(v[i], i + 1);
            if (res > 5000000) {
                res = -1;
                break;
            }
        }
        if (res == -1) {
            cout << "Too expensive\n";
        } else {
            cout << res << '\n';
        }
    }
}

// 가격이 서로 다른 n개의 부지 중 1년에 땅 하나만 살 수 있고, 매년 땅 가격이 기하급수로 늘어날 때 최소로 모두 사는 가격 구하기

// 내림차순으로 정렬해서 그 순서로 사는 게 이득
// 합이 500만 이상이면 too expensive 출력