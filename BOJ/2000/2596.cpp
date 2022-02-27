// 비밀편지
// https://www.acmicpc.net/problem/2596

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string p[8] = {"000000", "001111", "010011", "011100", "100110", "101001", "110101", "111010"};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string s;
	cin >> s;
	int resn = 0;
	string ress;
	for (int i = 0; i < n; i++) {
		bool pass = false;
		for (int t = 0; t < 8; t++) {
			int u = 0;
			for (int j = 0; j < 6; j++) {
				if (s[6 * i + j] == p[t][j]) {
					u++;
				}
			}
			if (u >= 5) {
				ress += 'A' + t;
				pass = true;
				break;
			}
		}
		if (!pass) {
			resn = i + 1;
		}
		if (resn != 0) {
			break;
		}
	}
	if (resn != 0) {
		cout << resn << '\n';
	}
	else {
		cout << ress << '\n';
	}
}

// 각 글자당 6비트로 구성된 비밀편지에서 각 글자당 1비트까지 이상해도 읽을 수 있다고 할 때, 전체 해독 가능한 경우 해독 결과, 불가능한 경우 불가능한 첫 글자 출력하기

// 받은 암호문을 6비트 단위로 나누어 주어진 문자와 동일한지 비트 단위로 확인 - 맞는 개수를 세면서
// 맞는 개수가 5 이상이면 결과 문자열에 문자를 추가하고, 그러한 문자가 없으면 결과 정수에 현재 문자 인덱스를 적는다
// 따라서 결과 정수가 0이 아니면 정수를, 아니면 문자열을 출력하는 방식으로