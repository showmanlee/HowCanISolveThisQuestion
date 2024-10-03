// 선택 가능성이 가장 높은 자료형
// https://www.acmicpc.net/problem/32278

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    long long n;
    cin >> n;
    if (SHRT_MIN <= n && n <= SHRT_MAX) {
        cout << "short\n";
    } else if (INT32_MIN <= n && n <= INT32_MAX) {
        cout << "int\n";
    } else {
        cout << "long long\n";
    }
}

// 주어진 정수가 어떤 자료형 범위에 들어가는지 출력하기