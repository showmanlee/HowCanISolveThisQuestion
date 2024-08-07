// 체육은 수학과목 입니다
// https://www.acmicpc.net/problem/32025

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    a *= 100;
    b *= 100;
    int res = min(a, b) / 2;
    cout << res << '\n';
}

// 직사각형의 가로 세로 길이가 미터 단위로 주어졌을 때, 그 안에 그릴 수 있는 가장 큰 원의 반지름을 센티미터로 출력하기

// 가장 짧은 변 / 2 * 100