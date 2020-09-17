// 스킬트리
// https://programmers.co.kr/learn/courses/30/lessons/49993

class Solution {
    public int solution(String skill, String[] skill_trees) {
        int answer = 0;
        for (int i = 0; i < skill_trees.length; i++){
            int index = 0;
            Boolean error = false;
            for (int j = 0; j < skill_trees[i].length(); j++){                                
                if (index >= skill.length())
                    break;
                
                if (skill_trees[i].charAt(j) == skill.charAt(index))
                    index++;
                else if (skill.substring(index).indexOf(skill_trees[i].charAt(j)) != -1){
                    error = true;
                    break;
                }
            }
            
            if (!error)
                answer++;
        }
        return answer;
    }
}

// 스킬 순서와 스킬트리 하나를 가지고 본다.
// 해당 커서의 문자가 현재 내 문자와 같다면, index++, cursor++
// 해당 커서의 문자가 내 다음 문자와 같다면, error
// 해당 커서의 문자가 내 문자와 내 다음 문자들과 같지 않다면, cursor++