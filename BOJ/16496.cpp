// 큰 수 만들기
// https://www.acmicpc.net/problem/16496

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool sorter(string a, string b) {
	return a + b > b + a;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<string> nums(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	sort(nums.begin(), nums.end(), sorter);
	string res;
	for (string s : nums)
		res += s;
	while (res[0] == '0' && res.length() > 1)
		res = res.substr(1);
	cout << res << '\n';
}

// n개의 음이 아닌 정수를 이어붙여 만들 수 있는 가장 큰 수는?

// 그리디 원리를 적용해볼 수 있음 - 길이와 절댓값으로 정렬해서 붙여넣을 수도 있음
// 하지만 더 간단하게 두 수를 이어붙였을 때 크게 나오는 쪽으로 수를 정렬해나갈 수도 있음 - sorter + sort
// 이렇게 정렬한 결과를 결과 문자열에 그대로 붙여넣어 출력하기
// 0이 등장할 수도 있고, 여러 개 등장할 수도 있기에 문자열 출력 전에 앞쪽의 0 지우기 