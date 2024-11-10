// 전구와 스위치
// https://www.acmicpc.net/problem/2138

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string a, b;

void click(char& c) {
    c = (c == '0' ? '1' : '0');
}

int f(int d) {
    string s = a;
    int ret = 0;
    if (d == 0) {
        click(s[0]);
        click(s[1]);
        ret++;
    }
    for (int i = 1; i < b.length(); i++) {
        if (b[i - 1] != s[i - 1]) {
            click(s[i - 1]);
            click(s[i]);
            if (i < b.length() - 1) {
                click(s[i + 1]);
            }
            ret++;
        }
    }
    if (s != b) {
        ret = 987654321;
    }
    return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    cin >> a >> b;
    int res = 987654321;
    res = min(res, min(f(0), f(1)));
    if (res == 987654321) {
        res = -1;
    }
    cout << res << '\n';
}

// 스위치를 누르면 자신과 인접한 두 전구의 상태가 바뀌는 전구 배열에서 특정 상태에서 새로운 상태로 바꾸는 게 가능한지, 가능하다면 최소 횟수 구하기

// 앞에서부터 조작하면서 자신 앞쪽의 전구가 바뀌어야 될 경우 눌러준다
// 다만 이 경우 양 끝쪽 스위치는 컨트롤이 불가능한데, 이를 대비해 첫 스위치를 무조건 누를지와 안 누를지에 따라 플로우를 나누어 확인