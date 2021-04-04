// 좌표 압축
// https://www.acmicpc.net/problem/18870

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> input(n);
	vector<int> coord(n);
	for (int i = 0; i < n; i++) {
		cin >> input[i];
		coord[i] = input[i];
	}
	sort(coord.begin(), coord.end());
	coord.resize(unique(coord.begin(), coord.end()) - coord.begin());
	for (int i : input)
		cout << lower_bound(coord.begin(), coord.end(), i) - coord.begin() << ' ';
	cout << '\n';
}

// 이러한 좌표 압축 알고리즘은 나중에도 많이 쓰게 될 예정
// 그러려고 굳이 find를 n^2로 돌릴 필요도 없고(어차피 백만개라 시간초과) map을 쓸 필요도 없다
// unique = 연속된 중복값을 뒷쪽으로 보내버림 - 정렬된 배열에서 하면 중복되지 않은 모든 값이 앞에 남고 나머지는 모두 뒤로 보낸다
// 뒤로 가버린 쓰레기값들을 resize(unique() - begin() = 중복값을 제거한 크기) 등으로 처리하면 lower_bound를 사용할 수 있음
// lower_bound = 정렬된 배열에서 이진탐색으로 값(없으면 그거보다 바로 더 큰 값)의 위치를 구함 -  다른 언어의 indexof와 비슷하다고 보면 될듯
// 값을 넘는 최초의 값을 찾으려면 upper_bound를 쓰면 됨
// lower_bound의 반환값이 iterator라서 int로 표현하려면 - v.begin()을 붙여야 함에 유의