// 병약한 영정
// https://www.acmicpc.net/problem/14670

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> med(101, -1);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		med[a] = b;
	}
	int r;
	cin >> r;
	for (int i = 0; i < r; i++) {
		int l;
		cin >> l;
		vector<int> res(l);
		int fail = false;
		for (int j = 0; j < l; j++) {
			int s;
			cin >> s;
			if (med[s] == -1)
				fail = true;
			else
				res[j] = med[s];
		}
		if (fail)
			cout << "YOU DIED";
		else
			for (int j = 0; j < l; j++)
				cout << res[j] << ' ';
		cout << '\n';
	}
}

// 어떤 증상을 치료하는 약들이 있을 때, 현재 앓고 있는 증상(들)을 해결할 수 있는가? 있다면 어떤 약(들)을 써야 하는가?
// 증상 - 이름 순으로 약이 주어지는데, 우리는 증상을 보고 약을 골라야 하기에 배열에 증상을 인덱스로 하여 이름을 저장
// 이후 증상들을 받으며 써야 하는 약을 결과 배열에 넣는데, 만약 해당되는 약이 없는 경우(-1) 실패 판정
// 실패 판정이 나면 YOU DIED를, 그렇지 않으면 결과 배열 출력