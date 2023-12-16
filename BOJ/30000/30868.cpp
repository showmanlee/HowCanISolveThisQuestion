// 개표
// https://www.acmicpc.net/problem/30868

#include <iostream>
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
        while (n >= 5) {
            cout << "++++ ";
            n -= 5;
        }
        for (int i = 0; i < n; i++) {
            cout << "|";
        }
        cout << '\n';
    }
}

// 주어진 수를 5개씩 문자로 출력하기

// 출력해줍시다... - 5 나올 때마다 ++++, 이후 남은 수만큼 | 출력