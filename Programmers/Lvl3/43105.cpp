// 정수 삼각형
// https://programmers.co.kr/learn/courses/30/lessons/43105?language=cpp

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    vector<vector<int>> dp_sum(triangle.size(), vector<int>(triangle.size()));
    for (int i = triangle.size() - 1; i >= 0; i--){
        for (int j = 0; j <= i; j++){
            if (i == triangle.size() - 1)
                dp_sum[i][j] = triangle[i][j];
            else
                dp_sum[i][j] = triangle[i][j] + max(dp_sum[i+1][j], dp_sum[i+1][j+1]);
        }
    }
    int answer = dp_sum[0][0];
    return answer;
}

// 트리 순회가 아닌 dp 문제.