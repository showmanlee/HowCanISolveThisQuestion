// Фигурки
// https://www.acmicpc.net/problem/29029

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(26);
    int maxx = 0;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        v[c - 'A']++;
        maxx = max(maxx, v[c - 'A']);
    }
    cout << (n - maxx) << '\n';
}

// NSWE로 구성된 문자열에서 같은 문자로 통일시키기 위해 필요한 최소 문자 변경 횟수 구하기

// 가장 많은 글자를 빼고 나머지는 다 바꾼다