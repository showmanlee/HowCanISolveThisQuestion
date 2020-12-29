// 10726. 이진수 표현
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXRSXf_a9qsDFAXS

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n, m;
        cin >> n >> m;
        bool res = true;
        while (n > 0){
            if (m % 2 == 0)
                res = false;
            m /= 2;
            n--;
        }
        cout << '#' << test_case << ' ' << (res ? "ON" : "OFF") << '\n';
	}
	return 0;
}

// M을 이진수로 표현했을 때 뒤 N자릿수가 모두 1인가?
// while로 이진수를 만들 때는 뒤부터 채워진다는 것을 이용하자