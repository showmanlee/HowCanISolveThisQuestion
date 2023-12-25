// 시파르
// https://www.acmicpc.net/problem/9693

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int cnt = 0;
    while (true) {
        cnt++;
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        int res = 0;
        for (int i = 1; i <= 8; i++) {
            res += n / pow(5, i);
        }
        cout << "Case #" << cnt << ": " << res << '\n';
    }
}

// n!/10^m이 정수가 되는 m의 최댓값 구하기

// 10의 배수, 그러니까 뒤에 0이 m개 붙으면 10^m으로 나누어떨어진다
// 10은 2와 5의 곱으로 나오는데, 2의 배수보다 5(의 거듭제곱)의 배수가 더 적게 나오므로 그걸 세준다
// 세는 방법은 n을 5로 나눈 몫, 25로 나눈 몫... 을 계속 취해주는 것 