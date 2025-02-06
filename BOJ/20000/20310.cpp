// 타노스
// https://www.acmicpc.net/problem/20310

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    int zero = 0, one = 1;
    for (char c : s) {
        if (c == '0') {
            zero++;
        } else {
            one++;
        }
    }
    string res, ress;
    int cnt = 0;
    for (char c : s) {
        if (c == '1' && cnt < one / 2) {
            cnt++;
            continue;
        }
        res += c;
    }
    cnt = 0;
    for (char c : res) {
        if (c == '0') {
            cnt++;
            if (cnt > zero / 2) {
                continue;
            }
        }
        ress += c;
    }
    cout << ress << '\n';
}

// 0과 1로 구성된 문자열에서 0과 1을 절반씩 제거하여 만들 수 있는 사전상 가장 앞선 문자열 출력하기