// 오리
// https://www.acmicpc.net/problem/12933

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	if (s.length() % 5 != 0) {
		cout << -1 << '\n';
		return 0;
	}
	vector<int> check(s.length(), -1);
	string quack = "quack";
	int res = 0;
	while (true) {
		vector<int> pos;
		int t = 0;
		for (int i = 0; i < s.length(); i++) {
			if (check[i] == -1 && s[i] == quack[t]) {
				pos.push_back(i);
				t = (t + 1) % 5;
			}
		}
		if (pos.size() < 5)
			break;
		for (int i : pos)
			check[i] = res;
		res++;
	}
	if (res == 0)
		res = -1;
	for (int i = 0; i < s.length(); i++) {
		if (check[i] == -1) {
			res = -1;
			break;
		}
	}
	cout << res << '\n';
	return 0;
}

// quack하는 오리 소리가 한데 섞여 문자열을 이룰 때, 오리의 최소 개수는?
// 오리의 울음소리 quack의 글자들은 순서대로 등장해야 하나, 연속해서 등장할 필요는 없다
// 하나의 오리는 quack이 끝나면 다음 quack을 할 수 있다 - 그러니까 quack 중간에 quack이 등장한다면(qquuaacckk) 오리가 두 마리 이상 있다는 것
// 하지만 quack이 완전히 등장해야 한다 - quack 중 일부만 등장한다면 불가능한 상황이니 -1을 출력해야 함
// 즉, 주어지는 문자열의 길이가 5의 배수가 아니라면 무조건 에러 - 5의 배수라도 quack이 중간에 끊기면 에러

// 주어진 문자열과 같은 길이의 체크용 배열(check)을 생성 - 처음에는 -1로, 누구의 quack에 해당되는 문자인지 0번부터 기록됨
// 매 오리마다 문자열을 순회하며 quack이 나오는 대로 별도의 체커(pos)에 기록해준다
// 만약 pos의 크기가 5 미만이라면(quack이 제대로 나오지 않았다면) 더 이상의 quack이 없다는 의미이니 탈출하고, 그렇지 않다면 quack이 나왔다는 의미이니 pos에 누적된 위치를 check에 기록하고 오리 수를 늘려준다
// 오리 개수 탐색을 마친 후 오리가 없다면 에러
// check를 돌면서 빈칸(-1)이 있어도 에러 - quack이 이상하게 기록되었어도 다음 오리 탐색하면서 빈칸으로 남으니 같이 에러
// 에러가 안 나면 원래 오리 개수를 출력, 그렇지 않으면 -1