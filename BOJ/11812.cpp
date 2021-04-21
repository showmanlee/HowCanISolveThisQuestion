// K진 트리
// https://www.acmicpc.net/problem/11812

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long n, k, q;
	cin >> n >> k >> q;
	for (long long t = 0; t < q; t++) {
		long long a, b;
		cin >> a >> b;
		if (k == 1) {
			cout << abs(a - b) << '\n';
			continue;
		}
		long long res = 0;
		while (a != b) {
			long long m = max(a, b);
			a = min(a, b);
			b = (m - 2) / k + 1;
			res++;
		}
		cout << res << '\n';
	}
}

// 완전 K진 트리에서 두 노드 사이의 거리 구하기
// 완전 K진 트리에서 두 노드 사이의 거리는 두 노드 사이의 최소 공통 조상 노드를 찍고 돌아오는 거리와 같음
// 따라서 이 문제는 완전 K진 트리에서 최소 공통 조상 노드 찾기 문제와 사실상 같음 - 올라가는 중에 거리를 재야 하지만

// 완전 이진 트리에서 노드의 깊이는 int(sqrt(n))으로 정의할 수 있었음 - 완전 K진 트리에서는 그것이 불가
// 최대 노드 개수가 10^15이기 때문에 고전적인 LCA(parent 마킹)로는 접근 불가 + 인덱스명도 long long으로 처리해야 함
// 완전 K진 트리에서 다음 깊이가 시작되는 노드는 다음과 같다
// 2: 1 2 4 8 16
// 3: 1 2 5 14 41
// 4: 1 2 6 22 86
// 5: 1 2 7 32 158
// ...
// 여기서 점화식을 뽑아내면 됨 - 1 k k^2 k^3...
// 하지만 깊이 정보를 저장한 인덱스 배열을 활용하기는 어려울 것 같음(sqrt(10^15) > 3천만)
// 그런데 사실 공식이 있음 - 부모노드 = int((자식노드 - 2) / k + 1)

// 이 공식을 이용해 노드를 타고 올라가면서 올라간 횟수(= 거리)를 누적해주면 됨 - a == b가 될 때까지
// 매 시도마다 작은 수는 두고, 큰 수를 올려준다
// 여기서 주의할 점: k가 1이 될 수도 있다
// 이 경우 트리가 일렬이 되는데, 이 상황에서 저 알고리즘을 돌리면 10^15를 O(n)으로 돌리는 꼴이 됨 - 시간초과
// 따라서 k == 1일 경우에는 저 알고리즘을 돌리는 대신 b - a를 대신 출력하게 하여 시간을 절약한다