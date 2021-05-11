// 가장 가까운 세 사람의 심리적 거리
// https://www.acmicpc.net/problem/20529

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

string mbtis[16] = {
	"ISTJ", "ISFJ", "INFJ", "INTJ", "ISTP", "ISFP", "INFP", "INTP", "ESTP", "ESFP", "ENFP", "ENTP", "ESTJ", "ESFJ", "ENFJ", "ENTJ"
};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		vector<string> v(n);
		map<string, int> count;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			count[v[i]]++;
		}
		int res = 0;
		for (int i = 0; i < 16; i++) {
			res = max(count[mbtis[i]], res);
		}
		if (res >= 3) {
			cout << 0 << '\n';
			continue;
		}
		res = 987654321;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = j + 1; k < n; k++) {
					int d1 = 0, d2 = 0, d3 = 0;
					for (int p = 0; p < 4; p++) {
						if (v[i][p] != v[j][p])
							d1++;
						if (v[i][p] != v[k][p])
							d2++;
						if (v[j][p] != v[k][p])
							d3++;
					}
					res = min(res, d1 + d2 + d3);
				}
			}
		}
		cout << res << '\n';
	}
}

// n명 중 3명을 골랐을 때, 3명 간의 mbti의 다른 문자 수가 최소인 경우의 차는?
// n명 중 3명으로 골라서 비교해보면 되겠지만, 문제는 n이 최대 10만이라 일반적인 브포로는 풀 수 없음
// mbti의 경우의 수는 16가지기에, n이 높아지면 필연적으로 한 mbti에 3명 이상이 나올 수 있음
// 만약 한 mbti에 3명 이상이 등장하면 결과값은 무조건 0이 됨 - 같은 mbti 3명을 고르는 경우
// 따라서 map을 이용해 mbti 인원 수를 구한 후, 한 mbti에 3명 이상이 있음이 확인되면 탐색 과정 없이 0 출력
// 그렇지 않다면 3중 for를 통한 브포로 최솟값 구하기