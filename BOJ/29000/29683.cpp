// Рождественская лотерея
// https://www.acmicpc.net/problem/29683

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, a;
    cin >> n >> a;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        res += p / a;
    }
    cout << res << '\n';
}

// n장의 영수증에서 a원마다 복권 1장을 얻을 때, 얻을 수 있는 복권의 총 개수 구하기