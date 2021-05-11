// 디지털 친구
// https://www.acmicpc.net/problem/1985

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int t = 0; t < 3; t++) {
		string s1, s2;
		cin >> s1 >> s2;
		vector<int> c1(10), c2(10);
		for (char c : s1)
			c1[c - '0']++;
		for (char c : s2)
			c2[c - '0']++;
		bool fr = true;
		for (int i = 0; i < 10; i++) {
			if ((c1[i] == 0) != (c2[i] == 0))
				fr = false;
		}
		if (fr) {
			cout << "friends\n";
			continue;
		}
		fr = false;
		for (int i = 0; i < s1.length() - 1; i++) {
			if (s1[i] < '9' && s1[i + 1] > '0') {
				c1[s1[i] - '0']--;
				c1[s1[i + 1] - '0']--;
				c1[s1[i] - '0' + 1]++;
				c1[s1[i + 1] - '0' - 1]++;
				fr = true;
				for (int i = 0; i < 10; i++) {
					if ((c1[i] == 0) != (c2[i] == 0))
						fr = false;
				}
				if (fr)
					break;
				c1[s1[i] - '0']++;
				c1[s1[i + 1] - '0']++;
				c1[s1[i] - '0' + 1]--;
				c1[s1[i + 1] - '0' - 1]--;
			}
			if (s1[i] > '0' && s1[i + 1] < '9') {
				if (i == 0 && s1[0] == '1')
					continue;
				c1[s1[i] - '0']--;
				c1[s1[i + 1] - '0']--;
				c1[s1[i] - '0' - 1]++;
				c1[s1[i + 1] - '0' + 1]++;
				fr = true;
				for (int i = 0; i < 10; i++) {
					if ((c1[i] == 0) != (c2[i] == 0))
						fr = false;
				}
				if (fr)
					break;
				c1[s1[i] - '0']++;
				c1[s1[i + 1] - '0']++;
				c1[s1[i] - '0' - 1]--;
				c1[s1[i + 1] - '0' + 1]--;
			}
		}
		if (fr) {
			cout << "almost friends\n";
			continue;
		}
		for (int i = 0; i < s2.length() - 1; i++) {
			if (s2[i] < '9' && s2[i + 1] > '0') {
				c2[s2[i] - '0']--;
				c2[s2[i + 1] - '0']--;
				c2[s2[i] - '0' + 1]++;
				c2[s2[i + 1] - '0' - 1]++;
				fr = true;
				for (int i = 0; i < 10; i++) {
					if ((c1[i] == 0) != (c2[i] == 0))
						fr = false;
				}
				if (fr)
					break;
				c2[s2[i] - '0']++;
				c2[s2[i + 1] - '0']++;
				c2[s2[i] - '0' + 1]--;
				c2[s2[i + 1] - '0' - 1]--;
			}
			if (s2[i] > '0' && s2[i + 1] < '9') {
				if (i == 0 && s2[0] == '1')
					continue;
				c2[s2[i] - '0']--;
				c2[s2[i + 1] - '0']--;
				c2[s2[i] - '0' - 1]++;
				c2[s2[i + 1] - '0' + 1]++;
				fr = true;
				for (int i = 0; i < 10; i++) {
					if ((c1[i] == 0) != (c2[i] == 0))
						fr = false;
				}
				if (fr)
					break;
				c2[s2[i] - '0']++;
				c2[s2[i + 1] - '0']++;
				c2[s2[i] - '0' - 1]--;
				c2[s2[i + 1] - '0' + 1]--;
			}
		}
		if (fr) {
			cout << "almost friends\n";
			continue;
		}
		cout << "nothing\n";
	}
}

// 두 정수가 같은 숫자들로만 구성되어 있다면 'friends', 그렇지 않다면 'nothing',
// 두 정수 중 하나의 맞붙은 수 한 쌍의 값을 올리고 내리거나 내리고 올려서 (정수 첫 자리를 0으로 만들지 않고) friends로 만들 수 있는 경우 'almost friends'라고 부를 때, 두 정수의 친구관계 판정하기
// 정수가 최대 100자리까지 들어올 수 있으므로 문자열로 받고, 주어진 정수에 등장하는 숫자의 개수 세기
// 이후 두 정수의 숫자 존재 여부가 같다면 friends 판정
// 그렇지 않다면 'almost friends' 판정을 위해 각 문자열에 맞붙은 숫자에 대해 개수 조절해서 다시 friends 판정
// 만약 판정이 난다면 almost friends, 그렇지 않았다면 nothing