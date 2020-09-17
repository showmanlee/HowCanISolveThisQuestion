// 위장
// https://programmers.co.kr/learn/courses/30/lessons/42578

using System;
using System.Collections.Generic;

public class Solution {
    public int solution(string[,] clothes) {
        int answer = 1;
        Dictionary<string, List<string>> matchs = new Dictionary<string, List<string>>();
        bool tick = false;
        string prev = "";
        foreach(var s in clothes){
            if (!tick){
                prev = s;
            }
            else{
                if (!matchs.ContainsKey(s))
                    matchs.Add(s, new List<string>());
                matchs[s].Add(prev);
            }
            tick = !tick;
        }
        foreach(var b in matchs.Values){
            answer *= b.Count + 1;
        }
        return answer - 1;
    }
}