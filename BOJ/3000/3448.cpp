// 문자 인식
// https://www.acmicpc.net/problem/3448

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    cout << fixed;
    cout.precision(1);

    int n;
    cin >> n;
    cin.ignore();
    string s;
    int p = 0, q = 0;
    while (getline(cin, s)) {
        if (s == "") {
            q *= 1000;
            int res = 1000 - (q / p);
            if (res % 10 == 0) {
                cout << "Efficiency ratio is " << (res / 10) << "%.\n";
            } else {
                cout << "Efficiency ratio is " << (res / 10) << "." << (res % 10) << "%.\n";
            }           
            p = 0;
            q = 0;
        } else {
            for (char c : s) {
                p++;
                if (c == '#') {
                    q++;
                }
            }
        }
    }
}

// 주어진 문자열들에서 '#' / 전체 문자 개수 비율 구하기

// 세서 구해주면 되는데, 출력 방식에 주의 - 여기서는 int로 1000 곱해서 처리