// 팰린드롬
// https://www.acmicpc.net/problem/8892

#include <iostream>
#include <vector>
#include <string>
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
        vector<string> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        bool done = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                string s = v[i] + v[j];
                int len = s.length();
                bool fail = false;
                for (int k = 0; k < len / 2; k++) {
                    if (s[k] != s[len - 1 - k]) {
                        fail = true;
                        break;
                    }
                }
                if (fail) {
                    continue;
                }
                done = true;
                cout << s << '\n';
                break;
            }
            if (done) {
                break;
            }
        }
        if (!done) {
            cout << "0\n";
        }
    }
}

// 주어진 문자열 중 2개를 서로 붙여 팰린드롬이 만들어지는지 확인하기

// 문자열 풀 길이가 작기 때문에 브루트포스로 일일이 붙여서 확인할 수 있음 - 그리고 팰린드롬 발견되면 아무거나 하나만 출력해야 함
// 문자열 풀 브포 + 팰린드롬 판정 시간에 충분히 맞출 수 있으므로 브포로 확인합니다 - 탐색 중 팰린드롬이 발견되지 않은 여부만 확인하면 됨
// 만약 발견되지 않았다면 끝에 가서 0 출력하고, 발견했다면 그 팰린드롬 출력하고 탐색 중단