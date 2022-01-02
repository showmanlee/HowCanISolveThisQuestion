// 효정과 새 모니터
// https://www.acmicpc.net/problem/20949

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<pr> list(n);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		list[i] = { -(a * a + b * b), i + 1 };
	}
	sort(list.begin(), list.end());
	for (int i = 0; i < n; i++)
		cout << list[i].second << '\n';
}

// 같은 크기의 해상도가 다른 모니터들이 주어졌을 때, ppi가 높은 순서대로(같다면 번호가 작은 순서대로) 모니터 정렬하기
// 원래 ppi 공식은 sqrt(w^2 + h^2) / d
// 하지만 모니터의 크기는 모두 같기 때문에 ppi 비교를 위해 굳이 77로 나눌 필요가 없음 + 루트 씌우든 안 씌우든 대소관계는 같으니 굳이 sqrt를 할 필요도 없음
// 즉, 최대한 단순하게 w^2 + h^2로만 비교해도 된다는 것
// 모니터의 ppi와 원래 번호를 기억하는 pair 배열을 정렬하여 결과를 얻는다
// ppi는 내림차순, 번호는 오름차순으로 정렬해야 하므로 ppi는 음수로 저장