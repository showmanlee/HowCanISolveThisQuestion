// 회사에 있는 사람
// https://www.acmicpc.net/problem/7785

#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	set<string, greater<string>> list;
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		if (b == "enter")
			list.insert(a);
		else
			list.erase(a);
	}
	for (string s : list)
		cout << s << '\n';
}

// 회사 출입 로그가 주어질 때, 로그가 끝나는 시점에서 회사에 있는 사람 목록을 역순으로 출력하기
// map으로 출입 여부를, vector로 등장 여부를 체크할 수도 있으나, set을 사용하면 이를 한 번에 할 수 있다

// set은 균형 이진 트리 기반의 자료구조로, insert로 들어온 모든 데이터를 *중복 없이 정렬해서* 보관한다
// 따라서 iterator로 순회가 가능하지만, 인덱스로는 탐색할 수 없다
// 정렬 기준은 기본적으로 오름차순, 내림차순이라면 선언 과정에서 바꿔줘야 함 - 여기서는 내림차순 정렬이 필요하니 저렇게 설정
// insert로 삽입, erase로 삭제 