// 배수 스위치
// https://www.acmicpc.net/problem/12927

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.length();
    s = ' ' + s;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'Y') {
            for (int j = i; j <= n; j += i) {
                s[j] = (s[j] == 'Y' ? 'N' : 'Y');
            }
            res++;
        }
    }
    cout << res << '\n';
}

// 일렬로 나열된 n개의 스위치 중 i번 스위치가 i의 배수 번째 스위치를 모두 조작할 때, 모든 스위치를 끄는데 필요한 조작 수 구하기

// i번 스위치는 i번 미만의 스위치를 건드리지 않음이 보장됨 - 따라서 1번부터 차례대로 조작하면 된다
// 여기서 뒷 스위치가 움직였다면 자기 차례에 꺼주면 되고, 아니면 그냥 두면 됨