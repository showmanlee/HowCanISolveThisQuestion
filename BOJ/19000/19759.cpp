// <<Кто хочет стать миллионером?>>
// https://www.acmicpc.net/problem/19759

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int v[25] = { 
		100,
		200,
		400,
		800,
		1600,
		3200,
		6400,
		13000,
		26000,
		52000,
		104000,
		208000,
		416000,
		832000,
		1670000,
		3340000,
		6680000,
		13360000,
		26720000,
		53440000,
		106900000,
		213800000,
		427600000,
		855200000,
		1710400000
	};
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << v[i] << '\n';
	}
}

// 100부터 시작해서 2배로 늘어나되, 뒷자리 0의 개수가 절반 이상이 되도록 반올림한 결과 출력하기