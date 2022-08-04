// 카드 뽑기
// https://www.acmicpc.net/problem/16204

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    int res = min(m, k) + min(n - m, n - k);
    cout << res << '\n';
}

// n장의 카드 중 앞면에는 m장의 O와 n-m장의 X가 있고, 카드 뒷면에 k개의 O와 n-k개의 X를 그리려 할 때 양면의 무늬가 같게 되는 카드의 수는?

// O나 X가 그려지는 면의 수 중 작은 수를 서로 더해준다 - 결국 앞면과 뒷면에 같은 무늬가 그려지는 카드의 수는 각 면에 그려지는 무늬의 수 중 작은 쪽일 테니까