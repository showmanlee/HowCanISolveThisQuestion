// 7 더하기
// https://www.acmicpc.net/problem/4900

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    map<string, int> cvt;
    cvt["063"] = 0;
    cvt["010"] = 1;
    cvt["093"] = 2;
    cvt["079"] = 3;
    cvt["106"] = 4;
    cvt["103"] = 5;
    cvt["119"] = 6;
    cvt["011"] = 7;
    cvt["127"] = 8;
    cvt["107"] = 9;
    vector<string> tvc = { "063", "010", "093", "079", "106", "103", "119" , "011", "127", "107" };

    string s;
    while (cin >> s) {
        if (s == "BYE") {
            break;
        }
        int idx = 0;
        int a = 0, b = 0;
        int* cur = &a;
        while (idx < s.length()) {
            if (s[idx] == '+') {
                cur = &b;
                idx++;
            } else if (s[idx] == '=') {
                break;
            } else {
                string ss;
                ss += s[idx];
                ss += s[idx + 1];
                ss += s[idx + 2];
                *cur *= 10;
                *cur += cvt[ss];
                idx += 3;
            }
        }
        int res = a + b;
        string ress = to_string(res);
        cout << s;
        for (char c : ress) {
            cout << tvc[c - '0'];
        }
        cout << '\n';
    }
}

// 7 세그먼트 디스플레이 비트값을 10진수로 변환한 값으로 구성된 덧셈 수식이 주어질 때, 결과를 같은 포맷으로 출력하기

// 변환해서 출력하기만 하면 되는데, 문제는 변환하는 게 귀찮지요 - 다시 돌려놔야 하기도 하고