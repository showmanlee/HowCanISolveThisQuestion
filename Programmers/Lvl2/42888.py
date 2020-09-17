// 오픈채팅방(2019 카카오)
// https://programmers.co.kr/learn/courses/30/lessons/42888

def solution(record):
    answer = []
    user = {}
    for s in record:
        if s.split()[0] == "Enter":
            user[s.split()[1]] = s.split()[2]
            answer.append(s.split()[1] + " IN")
        elif s.split()[0] == "Leave":
            answer.append(s.split()[1] + " OUT")
        elif s.split()[0] == "Change":
            user[s.split()[1]] = s.split()[2]
    for i in range(0, len(answer)):
        answer[i] = user[answer[i].split()[0]] + "님이 " + ("들어왔습니다." if answer[i].split()[1] == "IN" else "나갔습니다.")
    return answer