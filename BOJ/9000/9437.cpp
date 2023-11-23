// 사라진 페이지 찾기
// https://www.acmicpc.net/problem/9437

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    while (true) {
        int n, p;
        cin >> n;
        if (n == 0) {
            break;
        }
        cin >> p;
        vector<int> v = {
            p % 2 ? p + 1 : p - 1,     
            p % 2 ? n - p : n - p + 1,
            p % 2 ? n - p + 1 : n - p + 2
        };
        sort(v.begin(), v.end());
        cout << v[0] << ' ' << v[1] << ' ' << v[2] << '\n';
    }
}

// 종이를 쌓은 후 그대로 접은 형태로 책자를 만들 때, 해당 페이지 번호가 있는 종이의 나머지 페이지 3개 출력하기

// 단순 계산 문제 - 거기에 정렬을 곁들이면 더 쉬워지지