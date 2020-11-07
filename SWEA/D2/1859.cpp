// 1859. 백만 장자 프로젝트
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5LrsUaDxcDFAXc

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n;
        cin >> n;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        long long res = 0;
        long long max = arr[n - 1], c = 0;
        for (int i = n - 2; i >= 0; i--){
            if (max < arr[i]){
                res += c * max;
                max = arr[i];
                c = 0;
            }
            else{
                res -= arr[i];
                c++;
            }
        }
        res += c * max;
        cout << '#' << test_case << ' ' << res << '\n';
	}
	return 0;
}

// 하루에 하나만 살 수 있는 상황에서 되팔렘으로 얻을 수 있는 최대의 이득 구하기
// 가격 리스트를 역순으로 돌면 O(n)으로 가능
// 삼성 문제가 전체적으로 어렵다 - 그만큼 자기계발에 좋다는 것