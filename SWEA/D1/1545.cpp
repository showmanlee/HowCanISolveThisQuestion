// 1545. 거꾸로 출력해 보아요
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV2gbY0qAAQBBAS0

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int n;
    cin >> n;
    for (int i = n; i >= 0; i--)
        cout << i << ' ';
    cout << '\n';
	return 0;
}

// n부터 0까지 출력하기