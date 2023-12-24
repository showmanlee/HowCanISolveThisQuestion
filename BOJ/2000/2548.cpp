// 대표 자연수
// https://www.acmicpc.net/problem/2548

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
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    cout << (n % 2 == 1 ? v[n / 2] : v[n / 2 - 1]) << '\n';
}

// 주어진 자연수들의 차의 합이 최소가 되는 '대표 자연수' 찾기

// 모두 구해볼 수도 있지만, 사실 이건 '중앙값'을 찾는 문제
// 모두 정렬한 뒤 가준데에 오는 수(들 중 왼쪽 값) 찾기