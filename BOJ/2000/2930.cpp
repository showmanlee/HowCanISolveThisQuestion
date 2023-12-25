// 가위 바위 보
// https://www.acmicpc.net/problem/2930

#include <iostream>
#include <vector>
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
    int m;
    cin >> m;
    vector<string> v(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i];
    }
    int resa = 0, resb = 0;
    for (int i = 0; i < n; i++) {
        int rr = 0, ss = 0, pp = 0;
        for (int j = 0; j < m; j++) {
            if (v[j][i] == 'S') {
                ss++;
            } else if (v[j][i] == 'R') {
                rr++;
            } else if (v[j][i] == 'P') {
                pp++;
            }
        }
        int rrc = ss * 2 + rr;
        int ssc = pp * 2 + ss;
        int ppc = rr * 2 + pp;
        resb += max(rrc, max(ssc, ppc));
        resa += (s[i] == 'S' ? ssc : (s[i] == 'R' ? rrc : ppc));
    }
    cout << resa << '\n' << resb << '\n';
}

// 가위바위보에서 내가 낸 수와 상대 m명이 낸 수가 주어질 때, 현 상황에서 얻을 수 있는 점수와 최고로 얻을 수 있는 점수 구하기

// 승리하면 2점, 비기면 1점
// 전자는 구해보면 되고, 후자의 경우에도 세 경우 모두 보고 최대를 더해준다