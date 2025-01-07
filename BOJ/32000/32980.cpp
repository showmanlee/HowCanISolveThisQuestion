// 분리배출
// https://www.acmicpc.net/problem/32980

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> v(n);
    vector<char> t(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        char prev = ' ';
        bool trash = false;
        for (char c : v[i]) {
            if (prev != ' ' && prev != c) {
                trash = true;
                break;
            } 
            prev = c;
        }
        t[i] = trash ? 'O' : v[i][0];
    }
    map<char, long long> p;
    cin >> p['P'] >> p['C'] >> p['V'] >> p['S'] >> p['G'] >> p['F'] >> p['O'];
    long long res = 0;
    for (int i = 0; i < n; i++) {
        res += v[i].length() * min(p['O'], p[t[i]]);
    }
    cout << res << '\n';
}

// 쓰레기의 구성 성분, 분리수거시 성분별 처리비용, 일반쓰레기 처리비용이 주어질 때 최소 처리비용 구하기