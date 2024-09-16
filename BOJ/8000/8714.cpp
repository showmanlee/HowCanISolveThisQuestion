// Monety
// https://www.acmicpc.net/problem/8714

#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int zero = 0, one = 0;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        if (p == 0) {
            zero++;
        } else {
            one++;
        }
    }
    cout << (zero > one ? one : zero) << '\n';
}

// 동전 n개의 앞뒷면 상황이 나왔을 때 모두 같은 면으로 만들기 위한 최소 뒤집기 횟수 구하기