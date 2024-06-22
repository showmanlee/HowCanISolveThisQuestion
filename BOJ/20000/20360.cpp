// Binary numbers
// https://www.acmicpc.net/problem/20360

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int cnt = 0;
    while (n > 0) {
        if (n % 2 == 1) {
            cout << cnt << ' ';
        }
        n /= 2;
        cnt++;
    }
    cout << '\n';
}

// 주어진 정수를 2진수로 바꿨을 때 1이 들어가는 자리 위치들 출력하기