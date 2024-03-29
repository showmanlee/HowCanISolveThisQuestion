// Some Sum
// https://www.acmicpc.net/problem/21185

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    if (n % 2 == 1) {
        cout << "Either" << '\n';
    } else if (n / 2 % 2 == 1) {
        cout << "Odd" << '\n';
    } else {
        cout << "Even" << '\n';
    }
}

// 1부터 100까지의 자연수 중 연속되는 n개의 합을 구할 때, 결과가 홀인지 짝인지 둘 다 나올 수 있는지 확인하기

// 홀수가 홀수 개 있어야 홀수가 가능함 - 수가 홀수 개 있을 때는 홀수 개수가 계속 바뀌므로 Either
// 짝수 개 있을 때는 n의 절반 - 즉 홀수의 개수에 따라 판정