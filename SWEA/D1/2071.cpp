// 2071. 평균값 구하기
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QRnJqA5cDFAUq

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        double sum = 0;
        for (int i = 0; i < 10; i++){
            double a;
            cin >> a;
            sum += a;
        }
        cout << '#' << test_case << ' ' << floor(sum / 10 + 0.5) << '\n';
	}
	return 0;
}

// 반올림을 하려면 floor(n + 0.5)