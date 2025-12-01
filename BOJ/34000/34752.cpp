// ZOAC 8
// https://www.acmicpc.net/problem/34752

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef pair<string, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<bool> isprime(100001, true);
	vector<int> cnt(100001);
	isprime[0] = isprime[1] = false;
	for (int i = 2; i <= sqrt(100001); i++) {
		if (isprime[i]) {
			for (int j = i * 2; j <= 100000; j += i) {
				isprime[j] = false;
			}
		}
	}
	for (int i = 2; i <= 100000; i++) {
		cnt[i] = cnt[i - 1];
		if (isprime[i]) {
			cnt[i]++;
		}
	}

	int n;
	cin >> n;
	vector<pr> v;
	for (int i = 0; i < n; i++) {
		string s;
		long long p;
		cin >> s >> p;
		long long a = p / 100000;
		long long b = p % 100000;
		if (a > b) {
			swap(a, b);
		}
		int t = cnt[b] - cnt[a];
		if (isprime[a]) {
			t++;
		}
		v.push_back({s, t});
	}
	sort(v.begin(), v.end(), [](pr& a, pr& b) {
		if (a.second == b.second) {
			return a.first < b.first;
		}
		return a.second > b.second;
	});
	int last = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (v[n - 1].second != v[i].second) {
			last = i + 1;
			break;
		}
	}
	cout << v[0].first << '\n' << v[last].first << '\n';
}

// 사람 이름과 앞뒤 5자리로 나눌 수 있는 코드가 주어질 때, 앞뒷자리 사이에 있는 소수의 개수로 정렬해서 가장 앞과 뒷사람 구하기