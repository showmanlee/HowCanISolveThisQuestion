// DNA 비밀번호
// https://www.acmicpc.net/problem/12891

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int aa, cc, gg, tt;
    cin >> aa >> cc >> gg >> tt;

    int res = 0;
    int a = 0, c = 0, g = 0, t = 0;
    for (int i = 0; i < m; i++) {
        if (s[i] == 'A') {
            a++;
        } else if (s[i] == 'C') {
            c++;
        } else if (s[i] == 'G') {
            g++;
        } else if (s[i] == 'T') {
            t++;
        }
    }
    if (a >= aa && c >= cc && g >= gg && t >= tt) {
        res++;
    }
    for (int i = 0; i < n - m; i++) {
        if (s[i] == 'A') {
            a--;
        } else if (s[i] == 'C') {
            c--;
        } else if (s[i] == 'G') {
            g--;
        } else if (s[i] == 'T') {
            t--;
        }  
        if (s[i + m] == 'A') {
            a++;
        } else if (s[i + m] == 'C') {
            c++;
        } else if (s[i + m] == 'G') {
            g++;
        } else if (s[i + m] == 'T') {
            t++;
        } 
        if (a >= aa && c >= cc && g >= gg && t >= tt) {
            res++;
        }
    }
    cout << res << '\n';
}

// ACGT로 구성된 길이 n의 문자열에서 각 문자의 최소 개수를 만족하는 길이 m의 부분 문자열의 개수 구하기

// n^2 말고 슬라이드