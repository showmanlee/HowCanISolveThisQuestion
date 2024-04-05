// 준살 프로그래밍 대회
// https://www.acmicpc.net/problem/7513

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
    int cnt = 0;
    for (int t = 0; t < tt; t++) {
        cnt++;
        int m;
        cin >> m;
        vector<string> v(m);
        for (int i = 0; i < m; i++) {
            cin >> v[i];
        }
        int n;
        cin >> n;
        cout << "Scenario #" << cnt << ":\n";
        for (int i = 0; i < n; i++) {
            string s;
            int p;
            cin >> p;
            for (int j = 0; j < p; j++) {
                int pp;
                cin >> pp;
                s += v[pp];
            }
            cout << s << '\n';
        }
        cout << '\n';
    }
}

// 문자열 배열이 주어질 때, 주어진 인덱스 순서대로 배열 원소를 뽑아 이어붙인 결과 출력하기

// 배열로 받아서 출력해주기