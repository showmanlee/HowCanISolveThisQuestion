// 배고픈 아리의 샌드위치 구매하기
// https://www.acmicpc.net/problem/25166

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int s, m;
    cin >> s >> m;
    if (s <= 1023) {
        cout << "No thanks\n";
    } else {
        s -= 1023;
        bool res = true;
        for (int i = 0; i <= 10; i++) {
            bool f1 = s & (1 << i);
			bool f2 = m & (1 << i);
			if (f1 && !f2) {
				res = false;
			}
        }
        cout << (res ? "Thanks" : "Impossible") << '\n';
    }
}

// 1, 2, 4... 256, 512원 동전으로 s원을 정확히 지불해야 하는데, 1, 2, 4... 256, 512원으로 m원을 추가로 받을 수 있을 때 지불할 수 있는지 확인하기

// 1023원 이하라면 빌리지 않고도 그냥 낼 수 있음
// 1024원 이상일 경우 빌려야 하는데, 이때 부족한 돈만큼 빌릴 수 있으면 빌려야 한다
// 1024~2048 자리까지 체크해줘야 함에 주의