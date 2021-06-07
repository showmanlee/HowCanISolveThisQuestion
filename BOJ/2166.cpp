// 다각형의 면적
// https://www.acmicpc.net/problem/2166

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<long long, long long> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<pr> pts(n);
	for (int i = 0; i < n; i++)
		cin >> pts[i].first >> pts[i].second;
	long long res = 0;
	for (int i = 1; i < n - 1; i++) {
		pr a = { pts[i].first - pts[0].first, pts[i].second - pts[0].second };
		pr b = { pts[i + 1].first - pts[0].first, pts[i + 1].second - pts[0].second };
		res += (a.first * b.second - a.second * b.first);
	}
	if (res < 0)
		res *= -1;

	cout << (res / 2) << '.' << (res % 2 == 0 ? 0 : 5) << '\n';
}

// n개의 점으로 이루어진 다각형의 넓이 구하기

// 점들은 이어지는 순서대로 주어짐 - 따라서 점 하나를 원점으로 잡고, 붙어있는 점 2개와 원점을 꼭짓점 삼은 삼각형들의 넓이를 모두 구하면 됨
// 문제는 그걸 어떻게 계산하느냐 - 벡터의 외적을 활용하면 됨
// 원점에서 출발한 두 벡터의 외적의 크기는 두 벡터의 합을 네 번째 점으로 삼은 평행사변형의 넓이와 같음 - 그리고 여기서 /2를 하면 삼각형의 넓이가 됨
// 가장 중요한 2차원 공간에서의 벡터의 외적은 (px * qy - py * qx) - 외적 특성상 하나의 축에서만 값이 나오고, 따라서 크기 값(스칼라)를 바로 알 수 있음
// 원래는 (aybz - azby, azbx - axbz, axby - aybx)지만, 2차원 공간의 점은 (i, j, 0)으로 볼 수 있기에 z항이 포함된 외적의 x, y는 모두 0이 되어버리는 것
// 또한 평행사변형(:= 삼각형)의 넓이를 구하기 위해 외적의 크기만 알면 되기에 별도의 변환 없이 바로 값을 가져올 수 있음

// 점의 절댓값은 최대 100000 - 이들의 곱의 합이 int를 넘을 수 있기에 long long으로 계산하기
// 점들을 모두 받은 뒤, 0번 점을 원점으로 삼고, 1번 점부터 n - 2번 점까지 순회하면 i, i + 1번 점에 대해 벡터를 만들고, 외적을 구해 결과값에 누적한다
// 외적값이 음수가 나와도 그대로 모두 더하기 - 결과값이 음수가 나오면 양수로 바꿔 크기로 변환
// 이후 나온 값들을 /2한 값이 우리가 원하는 답
// 정수의 차의 곱의 합이기 때문에 결과값은 정수임이 보장됨 - 따라서 실수형으로 변환할 필요 없이, (정수형 / 2).(정수형 % 2 ? 0 : 5)로 출력하면 원하는 답이 됨