// 자바의 형변환
// https://www.acmicpc.net/problem/25601

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	map<string, string> tree;
	for (int i = 1; i < n; i++) {
		string a, b;
		cin >> a >> b;
		tree[a] = b;
	}
	string x, y;
	cin >> x >> y;
	bool res = false;
	string xx = x;
	string yy = y;
	while (xx != "") {
		xx = tree[xx];
		if (xx == y) {
			res = true;
			break;
		}
	}
	if (!res) {
		while (yy != "") {
			yy = tree[yy];
			if (yy == x) {
				res = true;
				break;
			}
		}
	}
	cout << res << '\n';
}

// 클래스 상속 관계가 주어질 때, 주어진 두 클래스의 형변환이 가능한지 판정하기

// 클래스 상속 관계는 트리 형태로 주어지는데, 해당 트리가 부모자식 관계인지 확인하자는 말
// 자식에서 부모로 올라가면서 주어진 클래스를 만나게 되는지 판정하기 - 이를 위해 map을 이용, 클래스 트리를 만들어둔다
// 주어지는 관계에서는 누가 자식이고 부모인지 주어지기 때문에, 이를 이용해 자식 선택 시 부모를 확인할 수 있도록 map을 만든다
// 하지만 결과 판정 시 주어진 두 클래스 중 누가 자식인지는 모르기 때문에, 양쪽에서 모두 거슬러 올라가본다