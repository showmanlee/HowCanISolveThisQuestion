// ЛОВНО КУЧЕ
// https://www.acmicpc.net/problem/31282

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    int p = 0;
    int res = 0;
    while (n > p) {
        n += m;
        p += k;
        res++;
    }
    cout << res << '\n';
}

// 토끼가 사냥개보다 n칸 앞에 있고, 매 초 토끼는 m칸, 사냥개는 k칸 이동할 때, 따라잡히는 시간 구하기

// 더해주며 계산해준다