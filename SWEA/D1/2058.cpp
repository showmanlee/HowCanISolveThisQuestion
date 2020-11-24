// 2058. 자릿수 더하기
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QPRjqA10DFAUq

#include<iostream>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
    int n, res = 0;
    cin >> n;
    string s = to_string(n);
    for (char c : s)
        res += c - '0';
    cout << res << '\n';
	return 0;
}

// 어차피 4자릿수 - 문자열로 바꿔버리자