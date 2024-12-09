// 벼락치기
// https://www.acmicpc.net/problem/23739

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int d = 30;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        if (d > p) {
            d -= p;
            res++;
        } else {
            if (d >= p / 2.0) {
                res++;
            }
            d = 30;
        }
    }
    cout << res << '\n';
}

// 30분 동안 공부하고 30분 동안 쉬는 과정을 반복하면서 완독 소요시간이 다른 과목들을 공부할 때, 절반 이상 공부할 수 있는 과목 개수 구하기