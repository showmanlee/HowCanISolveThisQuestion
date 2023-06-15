// 0123456789
// https://www.acmicpc.net/problem/6916

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string digits[10] = {
    " * * *\n*     *\n*     *\n*     *\n\n*     *\n*     *\n*     *\n * * *\n",
    "\n      *\n      *\n      *\n\n      *\n      *\n      *\n",
    " * * *\n      *\n      *\n      *\n * * *\n*\n*\n*\n * * *\n",
    " * * *\n      *\n      *\n      *\n * * *\n      *\n      *\n      *\n * * *\n",
    "\n*     *\n*     *\n*     *\n * * *\n      *\n      *\n      *\n",
    " * * *\n*\n*\n*\n * * *\n      *\n      *\n      *\n * * *\n",
    " * * *\n*\n*\n*\n * * *\n*     *\n*     *\n*     *\n * * *\n",
    " * * *\n      *\n      *\n      *\n\n      *\n      *\n      *\n",
    " * * *\n*     *\n*     *\n*     *\n * * *\n*     *\n*     *\n*     *\n * * *\n",
    " * * *\n*     *\n*     *\n*     *\n * * *\n      *\n      *\n      *\n * * *\n"
};

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	cout << digits[n];
}

// 7-segment 숫자 세그먼트 출력하기

// 별 찍기처럼 조건문 기반으로 찍어도 되지만, 그냥 저렇게 문자열 하드코딩으로 써도 됨
// 저거 질문 게시판에 대놓고 있더라 - 단순 출력 문제인데 안 쓸 이유가 없지