// Missing Numbers
// https://www.acmicpc.net/problem/14627

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    long long s, c;
    cin >> s >> c;
    vector<long long> v(s);
    long long total = 0;
    for (long long i = 0; i < s; i++) {
        cin >> v[i];
        total += v[i];
    }
    
    long long left = 1, right = 1000000000;
    long long midd = 0;
    
    while (left <= right){
        long long mid = (left + right) / 2;
        long long sum = 0;
        for(long long i = 0; i < s; i++) {
            if (v[i] >= mid) {
                sum += v[i] / mid;
            }
        }
        if (sum >= c){
            midd = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    long long res = total - (midd * c);
    cout << res << '\n';
}

// 서로 길이가 다른 s개의 파를 c개의 파닭에 개당 하나의 파를 이용하여 같은 양으로 넣었을 때 최소로 남는 경우 출력하기

// 이분 탐색으로 구하기 - 길이를 정한 후 파들을 체크, 나온 조각 수를 c와 비교해 탐색