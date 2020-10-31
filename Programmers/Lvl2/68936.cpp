// 쿼드 압축 후 개수 세기
// https://programmers.co.kr/learn/courses/30/lessons/68936

#include <string>
#include <vector>

using namespace std;
int zero = 0;
int one = 0;

void dq(vector<vector<int>>& arr, int x, int y, int size){
    if (size == 1){
        if (arr[x][y] == 0)
            zero++;
        else
            one++;
        return;
    }
    bool divide = false;
    for (int i = x; i < x + size; i++){
        for (int j = y; j < y + size; j++){
            if (arr[i][j] != arr[x][y]){
                divide = true;
                break;
            }
        }
        if (divide)
            break;
    }
    if (divide){
        int p = size / 2;
        dq(arr, x, y, p);
        dq(arr, x + p, y, p);
        dq(arr, x, y + p, p);
        dq(arr, x + p, y + p, p);
    }
    else{
        if (arr[x][y] == 0)
            zero++;
        else
            one++;
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    dq(arr, 0, 0, arr.size());
    answer.push_back(zero);
    answer.push_back(one);
    return answer;
}

// 분할 정복으로 풀기