// Chili Peppers
// https://www.acmicpc.net/problem/28249

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "Poblano") {
            res += 1500;
        } else if (s == "Mirasol") {
            res += 6000;
        } else if (s == "Serrano") {
            res += 15500;
        } else if (s == "Cayenne") {
            res += 40000;
        } else if (s == "Thai") {
            res += 75000;
        } else if (s == "Habanero") {
            res += 125000;
        }
    }
    cout << res << '\n';
}

// 산 고추의 목록이 주어질 때 가격 총합 구하기

// 문제에 주어진 대로 더해줍니다