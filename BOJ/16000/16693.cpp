// Pizza Deal
// https://www.acmicpc.net/problem/16693

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	double a, p1, r, p2;
	cin >> a >> p1 >> r >> p2;
	double aa = a / p1;
	double rr = r * r * M_PI / p2;
	if (aa > rr) {
		cout << "Slice of pizza\n";
	} else {
		cout << "Whole pizza\n";
	}
}

// 주어진 소떡소떡을 왼쪽부터 하나씩 빼 소시지와 떡의 개수를 맞추려고 할 때, 얻을 수 있는 가장 긴 경우는?

// 문자열을 받고, 문자열 안의 소시지와 떡 개수를 센 뒤, 두 개수가 같을 때 남은 소떡소떡을 출력하고, 아니면 앞에서부터 하나씩 뺀다
// 반드시 경우의 수가 나오기 때문에 비었을 때는 생각하지 않아도 됨