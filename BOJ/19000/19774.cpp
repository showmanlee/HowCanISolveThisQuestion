// ABCD-код
// https://www.acmicpc.net/problem/19774

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        int n;
        cin >> n;
        int a = n / 100, b = n % 100;
        bool res = (a * a + b * b) % 7 == 1;
        cout << (res ? "YES" : "NO") << '\n';
    }
}

// 4자리 수가 주어질 때, 앞 두자리와 뒤 두자리의 제곱의 합을 7로 나눌 때 나머지가 1이 나오는지 판정하기 