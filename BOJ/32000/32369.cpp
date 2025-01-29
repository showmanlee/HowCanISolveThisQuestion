// 양파 실험
// https://www.acmicpc.net/problem/32369

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, a, b;
    cin >> n >> a >> b;
    int x = 1, y = 1;
    for (int i = 0; i < n; i++) {
        x += a;
        y += b;
        if (x < y) {
            swap(x, y);
        } else if (x == y) {
            y--;
        }
    }
    cout << x << ' ' << y << '\n';
}

// 두 양파가 늘어나는 길이가 주어지고 x보다 y가 더 길어질 때 서로 위치를 바꾸고, x와 y의 길이가 같으면 y의 길이를 하나 자를 때, n일 동안 돌린 결과 구하기 