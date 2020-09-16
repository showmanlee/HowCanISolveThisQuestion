#include <string>
#include <vector>

// K번째수
// https://programmers.co.kr/learn/courses/30/lessons/42748

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int i = 0; i < commands.size(); i++){
        vector<int> part;
        for (int j = commands[i][0] - 1; j <= commands[i][1] - 1; j++)
            part.push_back(array[j]);
        
        for (int j = 0; j < part.size(); j++){
            int min = j;
            for (int k = j; k < part.size(); k++)
                if (part[min] > part[k])
                    min = k;
            swap(part[min], part[j]);
        }
        
        answer.push_back(part[commands[i][2] - 1]);
    }
    return answer;
}

// 정렬 문제