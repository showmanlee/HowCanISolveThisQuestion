// K번째 수
// https://www.acmicpc.net/problem/1300

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	int left = 1, right = k;
	int res = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			cnt += min(n, mid / i);
		if (cnt >= k) {
			res = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	cout << res << '\n';
}

// n*n 크기의 2차원 배열 A가 A[i][j] = i * j를 만족하고, 배열 A를 1차원 배열화하여 정렬한 배열을 B라고 할 때, B[k] 구하기

// 일단 이분 탐색 문제라는 것은 명백함
// n이 10만 - 시간적으로나 공간적으로나 진짜 1차원 배열을 만들어서 탐색하는 것은 불가능
// 그렇다면 이분탐색을 어떻게 돌려야 할까 - 약간의 아이디어가 필요함
// 우선 이분탐색에서 left는 1, right는 k로 두고 탐색 시작 - A[1][j] = j, A[n][n] = b[n * n]이기에 B[k]의 수는 k 이하임이 보장됨
// 탐색 과정에서 얻은 mid 값을 이용해, mid 값을 i로 나누는 방식으로 A의 각 열에 mid보다 작은 수의 개수 구하기 - 위의 보장을 활용해, 각 열에서 mid보다 작은 수의 개수는 min(n, mid / i)
// 여기서 mid값은 B[k]가 될 수 있는 어떤 수를 지정한 것 - 그리고 위의 방식으로 구한 개수가 곧 어떤 수의 B에서의 인덱스가 됨
// 따라서 개수값이 k 이상인 경우 문제의 답이 될 수 있음 - 이 경우 right를 당기고, 결과값에 갱신 - 그렇지 않은 경우 left만 당기기
// 이렇게 범위를 좁혀가면 정확히 k번째 수를 찾을 수 있음