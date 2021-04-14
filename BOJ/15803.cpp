// PLAYERJINAH’S BOTTLEGROUNDS
// https://www.acmicpc.net/problem/15803

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<pr> v(3);
	for (int i = 0; i < 3; i++)
		cin >> v[i].first >> v[i].second;
	pr va = { v[1].first - v[0].first, v[1].second - v[0].second};
	pr vb = { v[2].first - v[1].first, v[2].second - v[1].second};
	pr vc = { v[0].first - v[2].first, v[0].second - v[2].second};
	double a = sqrt(va.first * va.first + va.second * va.second);
	double b = sqrt(vb.first * vb.first + vb.second * vb.second);
	double c = sqrt(vc.first * vc.first + vc.second * vc.second);
	double s = (a + b + c) / 2;
	if (s * (s - a) * (s - b) * (s - c) == 0)
		cout << "WHERE IS MY CHICKEN?\n";
	else
		cout << "WINNER WINNER CHICKEN DINNER!";
}

// 서로 다른 위치에 있는 세 사람의 위치가 일직선 상에 있는가?
// 일단 세 사람의 위치가 정렬된 상황일 때, 한 축의 좌표가 모두 동일한 경우, 그리고 서로 붙어있는 좌표간의 거리가 동일한 경우 그렇다고 볼 수 있음
// 하지만 한 축의 좌표가 모두 다름에도 좌표간 거리가 동일한 경우에는 어떻게 할까? - 이게 답이 안 나옴

// 사실 세 변의 길이만으로 삼각형의 넓이를 구할 수 있는 공식이 있음 - 헤론의 공식
// s = (a + b + c) / 2일 경우, sqrt(s * (s - a) * (s - b) * (s - c))
// 만약 삼각형의 넓이가 0이면 해당 점들은 일직선 상에 있는 것이라고 볼 수 있음
// 우리는 결과가 0인 것을 보고 싶기 때문에 sqrt를 넣어줄 필요는 없음
// 아무튼 세 변의 길이를 구해주고 헤론의 공식을 대입하면 결과를 알 수 있음