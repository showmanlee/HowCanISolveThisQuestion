// 인간은 무엇인가
// https://www.acmicpc.net/problem/32651

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    bool res = (n <= 100000 && n % 2024 == 0);
    cout << (res ? "Yes" : "No") << '\n';
}

// 주어진 수가 100000 이하의 2024의 배수인지 구하기