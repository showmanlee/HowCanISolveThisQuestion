// 야바위 대장
// https://www.acmicpc.net/problem/15814

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        swap(s[a], s[b]);
    }
    cout << s << '\n';
}

// 주어진 문자열에서 주어진 인덱스 쌍끼리 위치를 바꾼 결과 출력하기