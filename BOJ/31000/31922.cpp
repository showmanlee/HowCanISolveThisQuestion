// 이 대회는 이제 제 겁니다
// https://www.acmicpc.net/problem/31922

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int a, p, c;
    cin >> a >> p >> c;
    cout << max(a + c, p) << '\n';
}

// a, p, c가 주어질 때, a+c와 p 중 더 높은 수 출력하기