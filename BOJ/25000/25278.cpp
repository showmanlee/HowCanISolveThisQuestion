// Terraforming
// https://www.acmicpc.net/problem/25278

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int oxygen = 0;
    int ocean = 0;
    int temp = -30;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        int p = b[1] - '0';
        if (a == "oxygen") {
            oxygen += p;
        } else if (a == "ocean") {
            ocean += p;
        } else {
            temp += p;
        }
    }
    if (ocean >= 9 && oxygen >= 14 && temp >= 8) {
        cout << "liveable\n";
    } else {
        cout << "not liveable\n";
    }
}

// 주어진 행성의 초기 상태가 산소 0%, 해수면 0%, 온도 -30도이고, 이게 각각 14%, 9%, 8도 이상이 되어야 생물체가 살 수 있을 떄, 환경 변화 로그를 보고 생물체가 살 수 있게 됐는지 표시하기

// 로그 따라가면서 누적해주기 - 무조건 + 한자릿수만 나오므로...