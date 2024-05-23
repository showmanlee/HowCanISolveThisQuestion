// 모르고리즘 회장 정하기
// https://www.acmicpc.net/problem/30684

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> v;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s.length() == 3) {
            v.push_back(s);
        }
    }
    sort(v.begin(), v.end());
    cout << v[0] << '\n';
}

// 대문자 문자열들 중 3글자에서 가장 사전 순으로 먼저 나오는 문자열 출력하기