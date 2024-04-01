// Disposable Cup
// https://www.acmicpc.net/problem/13129

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int a, b, n;
    cin >> a >> b >> n;
    for (int i = 1; i <= n; i++) {
        cout << (a * n + b * i) << ' ';
    }
    cout << '\n';
}

// 컵이 겹쳐질 때 버려지는 부분과 남는 부분의 길이가 주어질 때, n개의 컵을 겹치거나 반대 방향으로 세워서 얻을 수 있는 놉이의 총 개수 구하기

// 모든 컵을 겹치지 않거나, 모든 컵을 겹치거나, 아니면 그 사이 컵을 몇 개만 겹치거나
// 이렇게 처리하면 될 듯합니다