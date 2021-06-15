// 숫자의 신
// https://www.acmicpc.net/problem/1422

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool sorterk(string a, string b) {
	if (a.length() == b.length())
		return a < b;
	else
		return a.length() < b.length();
}

bool sortern(string a, string b) {
	return a + b > b + a;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int k, n;
	cin >> k >> n;
	vector<string> nums(k), res(n);
	for (int i = 0; i < k; i++)
		cin >> nums[i];
	sort(nums.begin(), nums.end(), sorterk);
	for (int i = 0; i < n; i++) {
		if (i >= k)
			res[i] = nums[k - 1];
		else
			res[i] = nums[i];
	}
	sort(res.begin(), res.end(), sortern);
	for (string s : res)
		cout << s;
	cout << '\n';
}

// 중복이 포함된 k개의 자연수 중 모든 수를 적어도 한 번 이상 사용하여 n개의 수를 붙여 만들 수 있는 자연수의 최댓값은?

// 자연수 붙여서 큰 수 만들기 - 그리디
// 당연히 큰 수를 앞에 붙이는 것이 유리 - 그리고 수의 길이가 길수록 큰 수를 더 확실히 만들 수 있음(앞에 9를 붙일까 99를 붙일까)
// 따라서 주어진 수 로스터는 길이 -> 절댓값의 우선순위로 정렬
// 이후 수들의 위치를 나타내는 배열에서 처음 k개는 정렬된 대로 채워주고, 이후에는 로스터에서 가장 마지막 = 가장 '큰' 수만 삽입
// 그리고 해당 배열을 정렬하는데, 정렬 기준은 두 문자열을 더했을 때 큰 값이 나오는 쪽으로
// 마지막으로 정렬한 배열의 내용을 차례로 출력하기