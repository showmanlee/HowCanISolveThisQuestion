// 막대과자 포장
// https://www.acmicpc.net/problem/14219

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	cout << (n * m % 3 == 0 ? "YES" : "NO") << '\n'; 
}

// 1*3 일자, 2*2 ㄱ자 상자가 있을 때, 상자를 넣어야 하는 공간 크기가 주어지면 그 공간 안에 상잘르 채울 수 있는지 판정하기

// 사실 상자 모양에 상관없이 공간의 칸 수가 3으로 나누어떨어지면 넣을 수 있음 - 1*3, 2*3, 3*3, 2*6...
// 따라서 칸 수가 3으로 나누어떨어지는지 보고 정답 출력하기