// Every Second Counts
// https://www.acmicpc.net/problem/15080

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int ah, am, as, bh, bm, bs;
    char _;
    cin >> ah >> _ >> am >> _ >> as >> bh >> _ >> bm >> _ >> bs;
    int res = 0;
    while (ah != bh || am != bm || as != bs) {
        as++;
        if (as == 60) {
            am++;
            as = 0;
            if (am == 60) {
                ah++;
                am = 0;
                if (ah == 24) {
                    ah = 0;
                }
            }
        }
        res++;
    }
    cout << res << '\n';
}

// a 시각에서 b 시각으로 가는데 걸리는 초 구하기

// 멍청하게 구해보자