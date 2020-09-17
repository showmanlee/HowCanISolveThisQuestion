// 수 정렬하기
// https://www.acmicpc.net/problem/2750

#include <iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	int a[1000];
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		int min = i;
		for (int j = i; j < n; j++)
			if (a[min] > a[j])
				min = j;
		int tmp = a[i];
		a[i] = a[min];
		a[min] = tmp;
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << endl;
}

// c++은 알았지만 STL은 몰랐을 시절 - sort 함수 및 vector 미사용 예