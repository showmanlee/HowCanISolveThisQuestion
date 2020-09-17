// 알파벳 찾기
// https://www.acmicpc.net/problem/10809

#include <stdio.h>
#include <string.h>

int main(void) {
	int list[26];
	for (int i = 0; i < 26; i++)
		list[i] = -1;
	char word[101];
	scanf("%s", word);
	for (int i = 0; i < 101; i++)
		if (word[i] == '\0')
			break;
		else if (list[word[i] - 'a'] == -1)
			list[word[i] - 'a'] = i;
	for (int i = 0; i < 26; i++)
		printf("%d ", list[i]);
}