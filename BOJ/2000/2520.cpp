// 팬케이크 사랑
// https://www.acmicpc.net/problem/2520

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
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        int x = min(987654321.0, min(a * 2.0, min(b * 2.0, min(c * 4.0, min(d * 16.0, e / 9.0 * 16.0)))));
        int f, g, h, i;
        cin >> f >> g >> h >> i;
        int y = f + (g / 30) + (h / 25) + (i / 10);
        cout << min(x, y) << '\n';
    }
}

// 팬케이크를 하나 만드는데 문제에서 주어진 분량이 필요할 때, 현재 재료로 팬케이크를 몇 개나 만들 수 있는지 확인하기

// 반죽은 소수 단위지만 토핑은 정수 단위 - 이를 감안하여 반죽과 토핑 개수를 구한 뒤, 동시에 올릴 수 있는 개수를 출력한다