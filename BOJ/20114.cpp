// 미아 노트
// https://www.acmicpc.net/problem/20114

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, h, w;
	cin >> n >> h >> w;
	vector<string> arr(h);
	for (int i = 0; i < h; i++)
		cin >> arr[i];
	string res;
	for (int t = 0; t < n * w; t += w) {
		char c = '?';
		for (int i = 0; i < h; i++)
			for (int j = t; j < t + w; j++)
				if (arr[i][j] != '?')
					c = arr[i][j];
		res += c;
	}
	cout << res << '\n';
}

// 길이가 n인 문자열이 가로로 w, 세로로 h만큼 번지고 일부가 지워졌을 때, 원래 문자열에서 확인할 수 있는 글자만 복원하기

// 일단 규칙대로 번졌다는 것은 보장됨 - 번진 문자열에서 한 글자당 차지하는 범위는 w * h
// 따라서 글자 범위들을 순회하며 ?가 아닌 문자가 발견된 경우 해당 글자를 출력하고, 그렇지 않다면 ? 출력하기