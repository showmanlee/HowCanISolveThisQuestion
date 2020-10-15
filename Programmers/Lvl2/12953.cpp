// N개의 최소공배수
// https://programmers.co.kr/learn/courses/30/lessons/12953

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
    if (a < b)
        swap(a, b);
    while(b != 0){
        int n = a % b;
        if (n == 0)
            return b;
        else{
            a = b;
            b = n;
        }
    }
    return 1;
}

int solution(vector<int> arr) {
    int answer = arr[0];
    for (int i = 1; i < arr.size(); i++){
        answer = answer * arr[i] / gcd(answer, arr[i]);
    }
    return answer;
}

// 잊지 말 것 - 최소공배수는 최대공약수로 풀 수 있다