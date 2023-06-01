// Absolutely Flat
// https://www.acmicpc.net/problem/26863

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int> v(4);
    for (int i = 0; i < 4; i++) {
		cin >> v[i];
    }
    int p;
    cin >> p;
    int res = 1;
    sort(v.begin(), v.end());
    for (int i = 0; i < 3; i++) {
 		if (v[i] != v[i + 1]) { 
			res = 0;
		}
    }
    if (res == 0) {
		v[0] += p;
		res = 1;
		for (int i = 0; i < 3; i++) {
			if (v[i] != v[i + 1]) { 
				res = 0;
			}
		}
    }
    cout << res << '\n';
}

// 책상 네 다리의 길이와 다리 하나에 걸칠 수 있는 받침대의 크기가 주어질 때, 평평하게 만들 수 있는지 구하기

// 네 다리의 길이가 모두 일정하거나, 세 다리의 길이가 일정하고 남은 다리 하나도 받침대를 받치면 세 다리의 길이와 같아지는지 확인