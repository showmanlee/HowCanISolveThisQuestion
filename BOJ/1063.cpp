// 킹
// https://www.acmicpc.net/problem/1063

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

pr move(string s, pr pos) {
	pr ret = pos;
	for (char c : s) {
		if (c == 'R')
			ret.first++;
		if (c == 'L')
			ret.first--;
		if (c == 'B')
			ret.second--;
		if (c == 'T')
			ret.second++;
	}
	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string a, b;
	int n;
	cin >> a >> b >> n;
	pr king = { a[0] - 'A', a[1] - '1' };
	pr rock = { b[0] - 'A', b[1] - '1' };
	for (int i = 0; i < n; i++) {
		string dir;
		cin >> dir;
		pr nking = move(dir, king);
		if (nking.first < 0 || nking.second < 0 || nking.first >= 8 || nking.second >= 8)
			continue;
		pr nrock = rock;
		if (nking == rock) {
			nrock = move(dir, rock);
			if (nrock.first < 0 || nrock.second < 0 || nrock.first >= 8 || nrock.second >= 8)
				continue;
		}
		king = nking;
		rock = nrock;
	}
	cout << char(king.first + 'A') << char(king.second + '1') << '\n';
	cout << char(rock.first + 'A') << char(rock.second + '1') << '\n';
}

// 8*8 체스판에 킹과 돌이 있고 이 둘을 주어진 명렁에 맞게 움직일 때, 킹과 돌의 최종 위치는?

// 만약 움직인 결과가 보드를 벗어나게 되는 경우 해당 명령은 수행하지 않음
// 돌은 항상 킹과 함께 움직이지 않음에 주의 - 킹이 움직였을 때 돌과 겹치는 경우만 움직임

// 우선 킹과 돌의 위치를 잡는다 - 문자열 형태로 받고, 이를 int pair화한다
// 이후 주어진 명령과 조건에 맞춰 말들을 움직인다 - 이동은 함수 기반으로 하고, 리턴값은 새로운 변수에 저장
// 그 결과 새로운 위치가 보드 밖일 경우 패스하고, 그렇지 않다면 새로운 위치를 현재 위치로 갱신한다
// 그러다가 결과 출력하기