// 캐시(2018 카카오)
// https://programmers.co.kr/learn/courses/30/lessons/17680

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cacheMem;
    vector<int> cacheTime;
    int memSize;
    
    if (cacheSize == 0)
        return 5 * cities.size();
    
    for (int i = 0; i < cities.size(); i++){
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        bool found = false;
        for(int j = 0; j < cacheMem.size(); j++)
            if (cities[i] == cacheMem[j]){
                found = true;
                cacheTime[j] = 0;
                answer += 1;
                break;
            }   
        
        if (!found){
            if(memSize < cacheSize){
                cacheMem.push_back(cities[i]);
                cacheTime.push_back(0);
                memSize++;
            }
            else{
                int max = 0;
                for(int j = 0; j < cacheTime.size(); j++)
                    if (cacheTime[max] < cacheTime[j])
                        max = j;
                cacheMem[max] = cities[i];
                cacheTime[max] = 0;
            }
            answer += 5;
        }
        
        for(int j = 0; j < cacheTime.size(); j++)
            cacheTime[j]++;
    }
    return answer;
}

// 0~30까지의 캐시사이즈, 10만개까지 있는 도시들(대소문자 구분 X).
// LRU를 이용한 캐시 메모리 교체 과정을 수행했을 때, 소요 시간을 표시
// 캐시가 있을 경우 1, 없을 경우 5.