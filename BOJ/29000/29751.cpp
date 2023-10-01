// 삼각형
// https://www.acmicpc.net/problem/29751

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;
	int res = a * b * 5;
	cout << (res / 10) << '.' << (res % 10) << '\n';
}

// 삼각형의 밑변과 높이가 주어질 때, 넓이 구하기

// 구해줍시다 - 밑변과 높이가 정수이므로 언제나 .0, .5 형태로 출력됨에 유의
// 출력 형식을 지키기 위해 결과에 10을 곱하고, 소수점 앞에는 10의 몫, 뒤에는 나머지를 출력해준다