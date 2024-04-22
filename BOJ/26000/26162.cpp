// 인공 원소
// https://www.acmicpc.net/problem/26162

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    vector<bool> isprime(121, true);
	vector<int> prime;
	isprime[0] = isprime[1] = false;
	for (int i = 2; i <= sqrt(120); i++) {
		if (isprime[i]) {
			for (int j = i * 2; j <= 120; j += i) {
				isprime[j] = false;
			}
		}
	}
    vector<bool> isvalid(242, false);
    for (int i = 2; i <= 120; i++) {
        for (int j = 2; j <= 120; j++) {
            if (isprime[i] && isprime[j]) {
                isvalid[i + j] = true;
            }
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        cout << (isvalid[p] ? "Yes" : "No") << '\n'; 
    }
}

// 주어진 정수를 소수 2개의 합을 나타낼 수 있는지 확인하기

// 범위가 좁음 - 브루트포스