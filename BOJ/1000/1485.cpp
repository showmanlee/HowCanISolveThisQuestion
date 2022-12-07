// 정사각형
// https://www.acmicpc.net/problem/1485

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<long long, long long> pr;

long long dist(pr a, pr b) {
	return ((a.first - b.first) * (a.first - b.first)) + ((a.second - b.second) * (a.second - b.second));
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		vector<pr> p(4);
		for (int i = 0; i < 4; i++) {
			cin >> p[i].first >> p[i].second;
		}
		sort(p.begin(), p.end());
		long long d01 = dist(p[0], p[1]);
        long long d02 = dist(p[0], p[2]);
        long long d13 = dist(p[1], p[3]);
        long long d23 = dist(p[2], p[3]);
        long long d03 = dist(p[0], p[3]);
        long long d12 = dist(p[1], p[2]); 
		cout << (d01 == d13 && d13 == d23 && d23 == d02 && d03 == d12) << '\n';
	}
}

// 사각형의 네 점이 주어졌을 때, 네 점을 이어 정사각형을 만들 수 있는지 판정하기

// 정사각형의 조건 - 네 변의 길이가 모두 같고 대각선끼리의 길이도 같다
// 주어진 점의 좌표를 오름차순으로 정렬하면 Z형으로 점이 정렬되고, 이를 이용해 각 변의 길이와 대각선의 길이를 구한다 - 실수로 하면 정확도 때문에 틀릴 수 있으므로 제곱을 이용한 long long 정수로 표현
// 이후 네 변의 길이가 서로 같고 대각선의 길이가 서로 같은지 확인해봅니다