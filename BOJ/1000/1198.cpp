// 삼각형으로 자르기
// https://www.acmicpc.net/problem/1198

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<double, double> pr;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<pr> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	int res = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				int p = abs((v[i].first * v[j].second + v[j].first * v[k].second + v[k].first * v[i].second) - (v[j].first * v[i].second + v[k].first * v[j].second + v[i].first * v[k].second));
				res = max(res, p);
			}
		}
	}
	cout << res / 2 << (res % 2 ? ".5" : "") << '\n';
}

// 주어진 다각형에서 세 점만 빼고 모두 지워 나오는 삼각형의 최대 넓이 구하기

// 삼각형의 세 점이 주어질 때 넓이는 |(x1y2 + x2y3 + x3y1) - (x2y1 + x3y2 + x1y3)| / 2
// double로 계산하면 정밀도 때문에 틀릴 수 있으니 정수로 계산 후 2로 나눈다 - 어차피 정수끼리 계산하므로 결과도 정수임
