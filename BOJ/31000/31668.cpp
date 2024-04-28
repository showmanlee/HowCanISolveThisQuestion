// 특별한 가지
// https://www.acmicpc.net/problem/31668

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    cout << (m / n * k) << '\n';
}

// m / n * k 출력하기