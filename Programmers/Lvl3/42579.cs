// 베스트앨범
// https://programmers.co.kr/learn/courses/30/lessons/42579

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int[] solution(string[] genres, int[] plays) {
        List<int> answer = new List<int>();
        Dictionary<string, List<int>> songs = new Dictionary<string, List<int>>();
        for (int i = 0; i < genres.Length; i++){
            if (!songs.ContainsKey(genres[i]))
                songs.Add(genres[i], new List<int>());
            songs[genres[i]].Add(i);
        }
        foreach(string p in songs.Keys){
            songs[p].Sort(delegate(int a, int b){
                if (plays[a] > plays[b]) return -1;
                else if (plays[a] < plays[b]) return 1;
                else {
                    if (a > b) return 1;
                    else return -1;
                }
            });
        }
        List<string> finale = new List<string>(songs.Keys);
        finale.Sort(delegate(string a, string b){
            int p = 0, q = 0;
            foreach(int i in songs[a])
                p += plays[i];
            foreach(int i in songs[b])
                q += plays[i];
            if (p > q) return -1;
            else return 1;
        });
        foreach(string p in finale){
            answer.Add(songs[p][0]);
            if (songs[p].Count != 1)
                answer.Add(songs[p][1]);
        }
        
        return answer.ToArray();
    }
}

// 장르, 노래, 번호 순으로 정렬
// 장르별 Top 2만 수록