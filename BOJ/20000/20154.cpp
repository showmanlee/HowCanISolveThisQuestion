// 이 구역의 승자는 누구야?!
// https://www.acmicpc.net/problem/20154

#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	string scores = "32123333113133122212112221";
	vector<int> league(s.length());
	for (int i = 0; i < s.length(); i++)
		league[i] = scores[s[i] - 'A'] - '0';
	int space = 1;
	while (true) {
		if (space >= s.length())
			break;
		for (int i = 0; i < s.length(); i += space * 2) {
			if (i + space >= s.length())
				break;
			league[i] = (league[i] + league[i + space]) % 10;
		}
		space *= 2;
	}
	cout << (league[0] % 2 == 1 ? "I'm a winner!" : "You're the winner?") << '\n';
}

// 대문자로 구성된 알파벳이 있고, 각 알파벳의 획순의 합 % 10을 토너먼트 형식으로 더해 올라간다고 할 때, 최종 결과가 홀수인가 짝수인가
// 각 알파벳에 초기 점수를 매긴 후, 매 반복마다 간격을 늘려가며 더해간다 - while 안에서 for를 돌릴 때 나에게 내 옆 수를 더하고, 간격 * 2만큼 이동한다
// 이후 간격이 범위를 벗어났을 때 반복을 끝내고, 첫 번째 칸의 점수를 보고 결과를 판정한다