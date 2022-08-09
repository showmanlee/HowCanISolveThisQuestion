// Serious Problem
// https://www.acmicpc.net/problem/17094

#include <iostream>
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
    int t = 0, e = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '2') {
            t++;
        } else {
            e++;
        }
    }
    if (t > e) {
        cout << "2\n";
    } else if (t < e) {
        cout << "e\n";
    } else {
        cout << "yee\n";
    }
}

// 2와 e로만 구성된 문자열이 주어질 때, 2와 e의 개수 관계 출력하기

// 문자열 받고, 문자 돌면서 세고, 결과 출력하기