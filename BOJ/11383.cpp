// 똚
// https://www.acmicpc.net/problem/11383

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<string> v(n), p(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
        cin >> p[i];
    bool res = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] != p[i][j * 2] || v[i][j] != p[i][j * 2 + 1])
                res = false;
        }
    }
    cout << (res ? "Eyfa" : "Not Eyfa") << '\n';
}

// 주어진 문자열들과 그 문자열들을 가로로 두 배 늘인 결과가 주어질 때, 정말 그런 결과인지 판정하기
// 원래 문자열의 글자가 늘인 문자열의 두 글자와 모두 같으면 된 거고, 아니면 탈락