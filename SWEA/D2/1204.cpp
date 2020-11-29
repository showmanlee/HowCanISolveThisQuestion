// 1204. [S/W 문제해결 기본] 1일차 - 최빈수 구하기
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV13zo1KAAACFAYh

#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int count[101] = {0, };
        int max = 0, maxc = 0;
        int tt;
        cin >> tt;
        for (int i = 0; i < 1000; i++){
            int n;
            cin >> n;
            count[n]++;
        }
        for (int i = 0; i < 100; i++){
            if (count[i] >= maxc){
                max = i;
                maxc = count[i];
            }
        }
         cout << '#' << tt << ' ' << max << '\n';
	}
	return 0;
}

// 1000명의 점수 중에서 가장 많이 나온 점수(의 최댓값)을 구하라
// 0~100 안이니 충분히 카운트 배열 생성 가능