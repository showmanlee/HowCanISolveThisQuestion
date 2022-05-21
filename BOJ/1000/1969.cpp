// DNA
// https://www.acmicpc.net/problem/1969

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<string> dna(n);
	for (int i = 0; i < n; i++) {
		cin >> dna[i];
	}
	int res = 0;
	string ress;
	for (int i = 0; i < m; i++) {
		int a = 0, c = 0, g = 0, t = 0;
		int maxx = 0;
		for (int j = 0; j < n; j++) {
			if (dna[j][i] == 'A') {
				a++;
				maxx = max(maxx, a);
			}
			if (dna[j][i] == 'C') {
				c++;
				maxx = max(maxx, c);
			}
			if (dna[j][i] == 'G') {
				g++;
				maxx = max(maxx, g);
			}
			if (dna[j][i] == 'T') {
				t++;
				maxx = max(maxx, t);
			}
		}
		if (maxx == a) {
			ress += 'A';
			res += n - a;
		} else if (maxx == c) {
			ress += 'C';
			res += n - c;
		} else if (maxx == g) {
			ress += 'G';
			res += n - g;
		} else if (maxx == t) {
			ress += 'T';
			res += n - t;
		}
	}
	cout << ress << '\n' << res << '\n';
}

// 길이가 같은 DNA 염기 배열들과 같은 위치의 글자가 다른 경우(Hamming Distance)가 가장 작은 DNA 배열은?

// 주어진 배열들에서 찾는 게 아닌 주어진 배열들과 비교해서 얻을 수 있는 배열을 새로 만들어야 함에 주의 - 사전 순으로
// 각 자리별로 나온 글자 수를 세고, 가장 많이 나온 글자(중복일 경우 사전순)을 골라 새로 만든 배열에 넣는다
// distance는 전체 배열 수 중 해당 글자가 나오지 않은 수 - 이를 누적시켜 답 구하기
// 그니까 문제 잘 읽어야지요