// 숫자놀이
// https://www.acmicpc.net/problem/1755

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<string, int> pr;
string nums[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
 
int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int m, n;
	cin >> m >> n;
	vector<pr> v;
	for (int i = m; i <= n; i++) {
		if (i >= 10) {
			string s = nums[i / 10] + ' ' + nums[i % 10];
			v.push_back({ s, i });
		}
		else {
			v.push_back({ nums[i], i });
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].second << ' ';
		if (i % 10 == 9) {
			cout << '\n';
		}
	}
}

// 최대 두 자리 자연수를 영어로 하나씩 끊어 읽을 때, m~n까지의 자연수를 읽는 사전 순으로 배치한 결과를 10개씩 끊어서 출력하기

// 순서를 보고 직접 우선순위를 짜줄 수도 있겠으나, 가장 좋은 방법은 역시 문자열로 변환해서 정렬하는 것
// 두 자리수인 경우 두 문자열 사이에 공백을 두어야 제대로 정렬된다
// twenty-four가 아닌 two four로 쓰기에 이 방법으로 정렬 가능