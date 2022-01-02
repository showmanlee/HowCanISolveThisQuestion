// 유니대전 퀴즈쇼
// https://www.acmicpc.net/problem/20362

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	string s;
	cin >> n >> s;
	vector<string> answers(n);
	int res = 0;
	for (int i = 0; i < n; i++) {
		string name, chat;
		cin >> name >> chat;
		answers[i] = chat;
		if (name == s) {
			for (int j = 0; j < i; j++)
				if (answers[j] == chat)
					res++;
		}
	}
	cout << res << '\n';
}

// 정답자의 닉네임과 닉네임과 답들이 있는 로그가 주어질 때, 정답자보다 정답을 빨리 말한 사람의 수는?
// 닉네임은 로그에서 한 번만 나옴이 보장됨
// 지금까지 나왔던 답안을 배열에 저장했다가, 정답자 닉네임이 나오면 지금까지 나온 답들 중 정답자의 정답이 나온 수 세기