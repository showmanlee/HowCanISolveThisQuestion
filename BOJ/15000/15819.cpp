// 너의 핸들은
// https://www.acmicpc.net/problem/15819

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, p;
    cin >> n >> p;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    cout << v[p - 1] << '\n';
}

// 주어진 n개의 문자열을 사전순으로 정렬했을 때 p번째로 오는 문자열 출력하기

// c++ sort 기본값이 사전순 정렬임