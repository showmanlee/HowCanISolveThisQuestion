// 줄 세우기
// https://www.acmicpc.net/problem/11536

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
    vector<string> v(n), vi(n), vd(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        vi[i] = vd[i] = v[i];
    }
    sort(vi.begin(), vi.end());
    sort(vd.begin(), vd.end(), greater<string>());
    bool isInc = true, isDec = true;
    for (int i = 0; i < n; i++) {
        if (vi[i] != v[i]) {
            isInc = false;
        }
        if (vd[i] != v[i]) {
            isDec = false;
        }
    }
    if (isInc) {
        cout << "INCREASING\n";
    } else if (isDec) {
        cout << "DECREASING\n";
    } else {
        cout << "NEITHER\n";
    }
}

// 문자열 순서가 주어졌을 때, 오름차순인지 내림차순인지 둘 다 아닌지 판정하기

// 문자열 개수가 최대 20개까지이므로 미리 오름차순과 내림차순으로 정렬한 배열을 만들어둘 수 있음
// 이를 이용해 원본 배열이 오름차순/내림차순과 맞는지 확인해본다