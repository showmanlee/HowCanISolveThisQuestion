// 장보기
// https://www.acmicpc.net/problem/18310

#include <iostream>
#include <vector>
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
    cout << v[(n - 1) / 2] << '\n';
}

// 1차원 공간에 집들이 있는 위치가 주어지고, 집이 있는 곳 중 하나에 안테나를 놓아야 할 떄, 모든 집과의 거리의 합이 가장 작은 위치 구하기

// 모든 좌표값을 정렬한 뒤 가운데에 있는 값이 가장 가까움