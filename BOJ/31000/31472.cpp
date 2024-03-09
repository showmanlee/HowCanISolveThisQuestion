// 갈래의 색종이 자르기
// https://www.acmicpc.net/problem/31472

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    n = sqrt(n / 2);
    cout << (n * 8) << '\n';
}

// 길이가 짝수인 정사각형을 정확히 절반으로 나눈 넓이가 주어질 떄, 원래 정사각형의 둘레 구하기

// 한 변의 절반을 x라고 할 때, 2x^2에서 8x을 구하라는 뜻