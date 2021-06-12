// 세로읽기
// https://www.acmicpc.net/problem/10798

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<string> v(5);
	for (int i = 0; i < 5; i++)
		cin >> v[i];
	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 5; j++)
			if (i < v[j].length())
				cout << v[j][i];
	cout << '\n';
}

// 길이가 다른 5개의 문자열을 한 줄씩 놓고 붙은 문자들만 보고 세로로 읽을 때 나오는 결과 출력하기

// 문자열의 길이는 최대 15개
// 따라서 15*5 크기의 배열이라고 생각하며 배열에 문자열을 넣은 뒤, 현재 인덱스가 현재 문자열의 길이보다 작을 경우 해당 인덱스의 문자 출력하기