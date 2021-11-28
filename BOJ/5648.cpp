// 역원소 정렬
// https://www.acmicpc.net/problem/5648

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<long long> v;
	string s;
	cin >> s;
	while (cin >> s) {
		reverse(s.begin(), s.end());
		v.push_back(stoll(s));
	}
	sort(v.begin(), v.end());
	for (long long i : v) {
		cout << i << '\n';
	}
}

// 주어진 수들을 거꾸로 뒤집고 오름차순으로 정렬한 결과 출력하기

// 주어진 수들이 한 줄에 나올 수도 있고, 여러 줄에 나올 수도 있음 - 확실한 건 첫 번째로 나오는 수는 원소 수
// while cin이라면 어떻게 주어지든 모두 받을 수 있음
// 여기서 string 형태로 수를 받은 뒤 reverse로 뒤집어서 배열에 넣고 정렬해서 출력하기