// Ragged Right
// https://www.acmicpc.net/problem/10501

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    vector<string> v;
    string s;
    int maxx = 0;
    while (getline(cin, s)) {
        v.push_back(s);
        maxx = max(maxx, (int)s.length());
    }
    int res = 0;
    for (int i = 0; i < v.size()- 1; i++) {
        res += (maxx - v[i].length()) * (maxx - v[i].length());   
    }
    cout << res << '\n';
}

// 여러 줄의 문자열이 주어질 때, (가장 긴 문자열의 길이 - 문자열 길이)^2의 합 구하기

// 구해주면 됩니다... - 마지막줄은 제외함에 주의