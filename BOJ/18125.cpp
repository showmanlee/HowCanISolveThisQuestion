// 고양이 사료
// https://www.acmicpc.net/problem/18125

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string no[5]{
	"|>___/|     /}",
	"| O O |    / }",
	"( =0= )\"\"\"\"  \\",
	"| ^  ____    |",
	"|_|_/    ||__|"
};

string yes[5]{
	"|>___/|        /}",
	"| O < |       / }",
	"(==0==)------/ }",
	"| ^  _____    |",
	"|_|_/     ||__|",
};

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v1(m, vector<int>(n)), v2(n, vector<int>(m));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> v1[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> v2[i][j];
	bool res = true;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (v1[i][j] != v2[j][m - i - 1])
				res = false;
	if (res) {
		for (int i = 0; i < 5; i++)
			cout << yes[i] << '\n';
	}
	else {
		for (int i = 0; i < 5; i++)
			cout << no[i] << '\n';
	}
}

// 고양이 사료판을 반시계 방향으로 90도 방향으로 돌린 상황과 원래 상황이 주어질 때, 두 상황이 같은 상황인가?

// 각 칸에 대응되는 인덱스가 무엇인지 확인하기 
// 고양이 출력에 주의할 것 - 문자열 속에 들어갈 수 없는 "과 \이 섞여있음