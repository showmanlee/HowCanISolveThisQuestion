// 핑크빈 레이드
// https://www.acmicpc.net/problem/31712

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int ac, ad, bc, bd, cc, cd, x;
    cin >> ac >> ad >> bc >> bd >> cc >> cd >> x;
    int cnt = -1;
    while (true) {
        cnt++;
        if (cnt % ac == 0) {
            x -= ad;
        }
        if (cnt % bc == 0) {
            x -= bd;
        }
        if (cnt % cc == 0) {
            x -= cd;
        }
        if (x <= 0) {
            cout << cnt << '\n';
            break;
        }
    }
}

// 세 가지 스킬의 쿨타임과 대미지가 주어질 때, 0초부터 쿨타임 돌 때마다 스킬을 쓸 때 체력 x의 적이 죽는 시간 구하기

// 그대로 계속 돌려본다