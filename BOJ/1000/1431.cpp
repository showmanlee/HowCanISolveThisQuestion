// 시리얼 번호
// https://www.acmicpc.net/problem/1431

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

bool sorter(string a, string b) {
	if (a.length() != b.length())
		return a.length() < b.length();
	else {
		int ta = 0, tb = 0;
		for (char c : a)
			if (isdigit(c))
				ta += c - '0';
		for (char c : b)
			if (isdigit(c))
				tb += c - '0';
		if (ta != tb)
			return ta < tb;
		else
			return a < b;
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<string> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end(), sorter);
	for (int i = 0; i < n; i++)
		cout << arr[i] << '\n';
}

// 문자열의 길이 오름차순 -> 문자열에 속한 숫자들의 합 오름차순 -> 사전순으로 주어진 문자열 정렬하기

// 커스텀 sort 함수를 이용해 주어진 문자열 정렬하기
// 문자열 길이 먼저 보고, 같다면 문자열에 속한 숫자들의 합을 구해서 본 후, 그렇지 않다면 사전순(문자열 비교 연산)으로 결과 리턴