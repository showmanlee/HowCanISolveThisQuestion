// 창문 닫기
// https://www.acmicpc.net/problem/13909

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int res = 0;
    for (int i = 1; i * i <= n; i++) {
        res++;
    }
    cout << res << '\n';
}

// n개의 닫힌 창문에서 1~n의 배수의 창문을 열고 닫기를 반복할 때, 최종적으로 열려있는 창문의 개수 구하기

// 모든 창문은 약수의 개수만큼 열리고 닫힌다 - 그렇다면 약수의 개수가 홀수일 때 창문이 열려있는 상태가 되는데
// 여기서 약수가 홀수가 되려면 제곱수가 되어야 함 - a*b로 수가 만들어지는데 a*a인 케이스가 있는 거니까
// 따라서 제곱수의 수를 모두 세주면 됩니다