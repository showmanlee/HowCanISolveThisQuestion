// Farm
// https://www.acmicpc.net/problem/16283

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int a, b, n, w;
    cin >> a >> b >> n >> w;
    int ra = -1, rb = -1;
    for (int i = 1; i < n; i++) {
        int p = a * i + b * (n - i);
        if (p == w) {
            if (ra != -1) {
                ra = rb = -1;
                break;
            }
            ra = i;
            rb = n - i;
        }
    }
    if (ra == -1) {
        cout << -1;
    } else {
        cout << ra << ' ' << rb;
    }
    cout << '\n';
}

// 양과 염소가 먹는 사료의 양, 양과 염소의 총 마릿수, 먹은 사료의 총 양이 주어질 때, 양과 염소의 유일한 마릿수 출력하기

// 즉, 중복될 수 있는 경우 -1을 출력해야 한다는 것 - 예를 들어 a == b라거나
// 브루트포스로 하나씩 빼보면서 출력하면 됨