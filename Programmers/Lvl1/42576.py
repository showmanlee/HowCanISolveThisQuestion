# 완주하지 못한 선수
# https://programmers.co.kr/learn/courses/30/lessons/42576

def solution(participant, completion):
    participant.sort()
    completion.sort()
    answer = ''
    for i, p in enumerate(completion):
        if p != participant[i]:
            answer = participant[i]
            break
    if answer == '':
        answer = participant[-1]
    return answer