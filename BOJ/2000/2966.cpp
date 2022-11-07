// 찍기
// https://www.acmicpc.net/problem/2966

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	string s;
	cin >> n >> s;
	string adrian = "ABC";
	string bruno = "BABC";
	string goran = "CCAABB";
	int a = 0, b = 0, g = 0, maxx = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == adrian[i % 3]) {
			a++;
		}
		if (s[i] == bruno[i % 4]) {
			b++;
		}
		if (s[i] == goran[i % 6]) {
			g++;
		}
		maxx = max(a, max(b, g));
	}
	cout << maxx << '\n';
	if (a == maxx) {
		cout << "Adrian\n";
	}
	if (b == maxx) {
		cout << "Bruno\n";
	}
	if (g == maxx) {
		cout << "Goran\n";	
	}
}

// 세 사람이 정해진 패턴으로 찍을 때, 주어진 답안에서 가장 많이 맞추는 사람은?

// 해당 패턴을 넣으며 점수를 계산해본다 - 순환은 나머지로
// 동점인 사람을 모두 표시해줘야 하므로 개인 점수와 함께 최대 점수를 구한 뒤 최대 점수인 사람 이름 출력하기