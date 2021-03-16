// 암호 만들기
// https://www.acmicpc.net/problem/1759

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
char cons[5] = { 'a', 'e', 'i', 'o', 'u' };
char vowel[21] = { 'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z' };

int l, c;
int visit[26];
char arr[15];

void dfs(int count, char last) {
	if (count == l) {
		int o = 0, v = 0;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < l; j++)
				if (cons[i] == arr[j])
					o++;
		}
		for (int i = 0; i < 21; i++) {
			for (int j = 0; j < l; j++)
				if (vowel[i] == arr[j])
					v++;
		}
		if (o < 1 || v < 2)
			return;
		for (int i = 0; i < l; i++)
			cout << arr[i];
		cout << '\n';
		return;
	}
	for (char h = last; h <= 'z'; h++) {
		if (visit[h - 'a'] == 0) {
			visit[h - 'a'] = 1;
			arr[count] = h;
			dfs(count + 1, h + 1);
			visit[h - 'a'] = 0;
		}
	}
}

int main(void) {
	cin >> l >> c;
	for (int i = 0; i < 26; i++)
		visit[i] = -1;
	for (int i = 0; i < c; i++) {
		char h;
		cin >> h;
		visit[h - 'a'] = 0;
	}
	dfs(0, 'a');
}

// 주어진 알파벳 c개 중 l개를 선택하되, 모음은 최소 하나, 자음은 최소 둘 이상 포함되도록 하는 모든 암호 출력하기
// 일단 자음/모음 수 구분하지 않고 dfs를 돌린 뒤, l까지 채워지면 자음/모음 수 판정, 미달이면 출력하지 않고, 충족하면 출력하기
// 문자는 반드시 알파벳 순서대로 나열되어야 함에 주의