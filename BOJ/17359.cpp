// 전구 길만 걷자
// https://www.acmicpc.net/problem/17359 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<string> str(n);
	vector<int> perm(n);
	int sum = 0;
	for (string& s : str)
		cin >> s;
	for (int i = 0; i < n; i++) {
		perm[i] = i;
		for (int j = 1; j < str[i].length(); j++) {
			if (str[i][j] != str[i][j - 1]) 
				sum++;
		}
	}
	int res = 9876543210;
	do {
		int p = sum;
		for (int i = 0; i < n - 1; i++)
			if (str[perm[i]][str[perm[i]].length() - 1] != str[perm[i + 1]][0])
				p++;
		res = min(p, res);
		if (res == sum)
			break;
	} while (next_permutation(perm.begin(), perm.end()));
	cout << res << '\n';
}

// 0과 1로 구성된 문자열들을 서로 붙일 때, 숫자가 바뀌는 순간을 최소화한 경우의 숫자가 바뀌는 순간의 횟수는?
// 주어진 문자열을 재배열한다 - 순열이 필요함 - 재귀함수를 써야 할까?
// 하지만 STL에는 next_permutation이란 게 있음 - 함수가 실행될 때마다 주어진 배열의 순서를 계속 바꿔 마지막 수열에 도달하면 false 출력
// 합친 문자열 길이가 최대 1000(100*10)이고 재조합 과정을 10!번 해야 하기에 일일히 합쳐서 계산하면 시간 초과
// 각 문자열에서 숫자가 바뀌는 횟수의 합을 따로 저장하고, 순열 재조합 과정에서 붙은 두 문자열의 끝부분이 다른 경우에 횟수 더하기
// 어쨌든 모든 문자열을 써야 하기에 최소 횟수는 보장되어 있음 - res == sum이 되면 순열 탐색을 종료하게 하면 시간을 아낄 수 있음