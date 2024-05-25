// 알록달록 앵무새
// https://www.acmicpc.net/problem/28445

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    vector<string> v;
    for (int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        if (find(v.begin(), v.end(), s) == v.end()) {
			v.push_back(s);
        }
    }
    sort(v.begin(), v.end());
    for (string s : v) {
        for (string t : v) {
            cout << s << ' ' << t << '\n';
        }
    }
}

// 4가지 색상이 문자열로 주어질 때, 중복 포함해서 뽑을 수 있는 색상 쌍 출력하기

// 색상 문자열을 받아 중복을 없애고, 쌍을 구한다