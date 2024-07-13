// Cakes
// https://www.acmicpc.net/problem/21212

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int res = 987654321;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        res = min(res, b / a);
    }
    cout << res << '\n';
}

// 케이크를 만드는데 필요한 각 재료의 필요량과 소지량이 주어질 때, 온전한 케이크를 몇 개 만들 수 있는지 판정하기

// 가장 적은 재료 체크