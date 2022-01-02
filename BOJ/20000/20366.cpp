// 같이 눈사람 만들래?
// https://www.acmicpc.net/problem/20366

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<long long> snows(n);
	for (int i = 0; i < n; i++)
		cin >> snows[i];
	sort(snows.begin(), snows.end());
	long long res = 98765432198765;
	for (int i = 0; i < n - 3; i++) {
		for (int j = i + 3; j < n; j++) {
			int left = i + 1, right = j - 1;
			while (left < right) {
				long long p = snows[left] + snows[right] - snows[i] - snows[j];
				res = min(res, abs(p));
				if (p > 0)
					right--;
				else
					left++;
			}
		}
	}
	cout << res << '\n';
}

// 크기가 다른 눈덩이 중 4개를 선택해 두 개씩 쌓은 눈사람의 키 크기를 최소로 할 때, 최솟값은?\

// n이 최대 600까지 - n^4로 푸는 것은 미친짓, n^2^2도 마찬가지
// 하지만 이분탐색이 나온다면 어떨까 - 눈덩이 2개를 골라놓고, 나머지 두 개를 선택하는 이분탐색

// 이분탐색을 위해 주어진 눈덩이들을 먼저 정렬하기
// 이후 초기값 2개를 선택 - 둘 사이에 최소 2개의 눈덩이가 있을 수 있도록 초기 인덱스 설정하기
// 그리고 그 사이 양옆을 left, right 삼아 이분탐색 시작
// 선택한 눈덩이의 대소관계는 i -> left -> right -> j 순임이 보장됨 - 그리고 left-right, i-j로 눈사람을 묶어 만드는 것이 언제나 더 유리함
// 따라서 4개를 구해서 조합관계를 모두 구할 필요 없이 (left + right) - (i + j) = left + right - i - j으로 현재 선택한 눈사람의 차의 최솟값을 구할 수 있음
// 이렇게 얻은 값을 절댓값화하여 결과값을 갱신하는데 활용 후, 포인터 이동하기
// 결과가 0 이상이면 lr 눈사람이 더 크고, 그렇지 않으면 더 작으니, 두 눈사람의 차(:= lr 눈사람의 키)를 최소화할 수 있는 방향으로 움직이기
// 이 방식으로 n^2*logn의 시간복잡도로 결과를 얻을 수 있음