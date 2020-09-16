# 추석 트래픽(2018 카카오)
# https://programmers.co.kr/learn/courses/30/lessons/17676

def solution(lines):
    answer = 0
    windows = []
    for s in lines:
        t = s[11:24]
        d = float(s[24:-1])
        h = int(t.split(':')[0])
        m = int(t.split(':')[1])
        c = float(t.split(':')[2])
        end = h * 10000 + m * 100 + c
        c -= d - 0.001
        if (c < 0):
            c += 60
            m -= 1
            if (m < 0):
                m += 60
                h -= 1
        start =  h * 10000 + m * 100 + c
        windows += [[start, end]]
    
    for i in range(0, len(windows)):
        for h in range(0, 2):
            temp = 0
            for j in range(0, len(windows)):
                if windows[j][0] <= windows[i][h] and windows[j][1] >= windows[i][h] - 0.999:
                    temp += 1
            if temp > answer:
                answer = temp
    return answer

# lines의 형태는 '2016-09-15 hh:mm:ss.sss x.yyys'의 형태로 구성, 해당 시간 - x.yyy + 0.001초 전부터 해당 시간까지 작업이 처리되었음을 의미
# x.yyy초는 3초를 넘지 않음
# lines는 완료 시간 순서대로 정렬되어 있다.
# 모든 타이밍을 굳이 체크할 필요가 없음 - 로그 시작과 끝만 검색하면 됨