// 재귀의 귀재
// https://www.acmicpc.net/problem/25501

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		string s;
		cin >> s;
		int cnt = 0;
		bool isPalindrome = true;
		for (int i = 0; i < s.length() / 2 + 1; i++) {
			cnt++;
			if (s[i] != s[s.length() - 1 - i]) {
				isPalindrome = false;
				break;
			}
		}
		cout << isPalindrome << ' ' << cnt << '\n';
	}
}

// 팰린드롬을 재귀함수로 판정할 때, 재귀함수 호출 횟수와 팰린드롬 여부 확인하기

// int recursion(const char *s, int l, int r){
//     if(l >= r) return 1;
//     else if(s[l] != s[r]) return 0;
//     else return recursion(s, l+1, r-1);
// }

// int isPalindrome(const char *s){
//     return recursion(s, 0, strlen(s)-1);
// }

// 맨 끝에서부터 차례로 좁혀오면서 팰린드롬을 판정한다
// 이는 굳이 재귀로 풀 필요가 없음 - 반복문으로도 할 수 있으니까
// 실제로 이 재귀 코드를 그대로 갖다가 풀면 시간 초과
// 따라서 반복문으로 바꿔서 푼다 - cnt는 팰린드롬 최종 판정 전 반복 횟수
