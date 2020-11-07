// 1926. 간단한 369게임
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PTeo6AHUDFAUq

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        string s = to_string(i), clap = "";
        for (char c : s)
            if (c == '3' || c == '6' || c == '9')
                clap += "-";
        if (clap == "")
            cout << i << ' ';
        else
            cout << clap << ' ';
    }
    cout << '\n';
	return 0;
}

// 369 게임 돌리면서 박수 치는 부분을 -으로 처리하기