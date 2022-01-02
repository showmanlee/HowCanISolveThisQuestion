// 우리집엔 도서관이 있어
// https://www.acmicpc.net/problem/2872

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> books(n);
	for (int i = 0; i < n; i++) 
		cin >> books[i];
	int res = n;
	for (int i = n - 1; i >= 0; i--)
		if (books[i] == res)
			res--;
	cout << res << '\n';
}

// 책 더미를 알파벳 순으로 정렬하기 위해 책 하나를 선택해 맨 위로 올려놓을 수 있을 때, 정렬에 필요한 이동 횟수는?

// 책이 뽑혀서 맨 위로 이동하면 그 아래에 있는 책들은 점점 아래로 내려감
// 따라서 맨 아래에 있어야 하는 책은 뽑을 필요가 없음 - 어차피 다른 책들을 뽑다보면 맨 아래로 가기 때문
// 그리고 바로 한 칸 위에 있어야 하는 책이 맨 아래에 있어야 하는 책 바로 위에 있다면 그것도 뽑을 필요가 없음 - 이미 제자리에 있음
// 이 원리를 반복적으로 적용하면, 맨 아래에 있어야 하는 책과 차례대로 붙어있는 책들은 뽑을 필요가 없어짐
// 이 원리를 더 확장하면, 서로 붙어있지 않아도 맨 아래에 있어야 하는 책 위로 책들이 차례대로 있다면 뽑을 필요가 없음
// 그렇지 않은 책들을 뽑으면서 서로 떨어진 정렬된 덩어리들이 하나로 만나기 때문
// 따라서 맨 아래에 있는 책을 찾은 뒤, 위로 올라가면서 그 다음으로 놓여야 하는 책을 찾으면 책 옮기기 카운트를 줄이는 방식으로 문제를 해결할 수 있음