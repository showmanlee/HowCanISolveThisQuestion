// LOL Lovers
// https://www.acmicpc.net/problem/33026

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;
    int al = 0, ao = 0, bl = 0, bo = 0;
    for (char c : s) {
        if (c == 'L') {
            bl++;
        } else {
            bo++;
        }
    }
    bool pass = false;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'L') {
            al++;
            bl--;
        } else {
            ao++;
            bo--;
        }
        if (al != bl && ao != bo) {
            pass = true;
            cout << (al + ao) << '\n';
            break;
        }
    }
    if (!pass) {
        cout << -1 << '\n';
    }
}

// L과 O로 구성된 문자열을 둘로 나눠서 양쪽의 L과 O 갯수를 서로 다르게 할 때 나올 수 있는 왼쪽 문자열 길이 출력하기