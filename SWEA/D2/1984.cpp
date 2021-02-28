// 1984. 중간 평균값 구하기
// https://swexpertacademy.com/main/code/problem/problemSubmitHistory.do?contestProbId=AV5Pw_-KAdcDFAUq

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        vector<int> v(10);
        for (int i = 0; i < 10; i++)
            cin >> v[i];
        sort(v.begin(), v.end());
        double sum = 0;
        for (int i = 1; i < 9; i++)
            sum += v[i];
        sum /= 8;
        int res = (int)(sum + 0.5);
		cout << '#' << test_case << ' ' << res << '\n';
	}
	return 0;
}

// 10개의 수 중 최솟값과 최댓값을 뺀 수의 평균값 구하기
// 정렬하고, 합하고, 나누고, 반올림((int)(f + 0.5))