// 평행사변형
// https://www.acmicpc.net/problem/1064

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cout << fixed;
    cout.precision(16);

	double xa, ya, xb, yb, xc, yc;
	cin >> xa >> ya >> xb >> yb >> xc >> yc;

	double pa = (ya - yb == 0 ? 98765432198765 : abs(xa - xb) / abs(ya - yb));
	double pb = (yb - yc == 0 ? 98765432198765 : abs(xb - xc) / abs(yb - yc));
	if (pa == pb) {
		cout << -1 << '\n';
		return 0;
	}

	double aa = sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
	double bb = sqrt((xa - xc) * (xa - xc) + (ya - yc) * (ya - yc));
	double cc = sqrt((xb - xc) * (xb - xc) + (yb - yc) * (yb - yc));
	double ra = 2 * (aa + bb);
	double rb = 2 * (aa + cc);
	double rc = 2 * (bb + cc);
	double rmax = max(ra, max(rb, rc));
	double rmin = min(ra, min(rb, rc));
	double res = rmax - rmin;
	cout << res << '\n';
}

// 세 점이 주어졌을 때, 점 하나를 더 찍어서 만들 수 있는 평행사변형 둘레의 최대/최소 구하기

// 세 점을 이어 만들 수 있는 선분 중 2개를 골라, 해당 선분에 평행하는 선분을 그어주면 평행사변형이 됩니다
// 다만 '불가능한 경우'도 있다고 했는데, 그건 세 점이 한 직선 위에 있는 경우 - 두 선분의 기울기를 구해 같으면 -1 출력
// 평행사변형 둘레의 길이는 선택한 두 선분의 길이의 합 * 2
// 이렇게 구할 수 있는 3개의 값 중 최대와 최소의 차를 출력한다