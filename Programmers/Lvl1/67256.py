# 키패드 누르기(2020 카카오 인턴십)
# https://programmers.co.kr/learn/courses/30/lessons/67256?language=python3

def solution(numbers, hand):
    lx = 0
    ly = 3
    rx = 2
    ry = 3
    answer = ''
    for i in range(len(numbers)):
        if numbers[i] == 1:
            lx = 0
            ly = 0
            answer += 'L'
        elif numbers[i] == 4:
            lx = 0
            ly = 1
            answer += 'L'
        elif numbers[i] == 7:
            lx = 0
            ly = 2
            answer += 'L'
        elif numbers[i] == 3:
            rx = 2
            ry = 0
            answer += 'R'
        elif numbers[i] == 6:
            rx = 2
            ry = 1
            answer += 'R'
        elif numbers[i] == 9:
            rx = 2
            ry = 2
            answer += 'R'
        elif numbers[i] == 2:
            ldist = abs(lx - 1) + abs(ly - 0)
            rdist = abs(rx - 1) + abs(ry - 0)
            if ldist < rdist:
                lx = 1
                ly = 0
                answer += 'L'
            elif rdist < ldist:
                rx = 1
                ry = 0
                answer += 'R'
            else:
                if hand == 'left':
                    lx = 1
                    ly = 0
                    answer += 'L'  
                else:
                    rx = 1
                    ry = 0
                    answer += 'R'    
        elif numbers[i] == 5:
            ldist = abs(lx - 1) + abs(ly - 1)
            rdist = abs(rx - 1) + abs(ry - 1)
            if ldist < rdist:
                lx = 1
                ly = 1
                answer += 'L'
            elif rdist < ldist:
                rx = 1
                ry = 1
                answer += 'R'
            else:
                if hand == 'left':
                    lx = 1
                    ly = 1
                    answer += 'L'  
                else:
                    rx = 1
                    ry = 1
                    answer += 'R' 
        elif numbers[i] == 8:
            ldist = abs(lx - 1) + abs(ly - 2)
            rdist = abs(rx - 1) + abs(ry - 2)
            if ldist < rdist:
                lx = 1
                ly = 2
                answer += 'L'
            elif rdist < ldist:
                rx = 1
                ry = 2
                answer += 'R'
            else:
                if hand == 'left':
                    lx = 1
                    ly = 2
                    answer += 'L'  
                else:
                    rx = 1
                    ry = 2
                    answer += 'R' 
        elif numbers[i] == 0:
            ldist = abs(lx - 1) + abs(ly - 3)
            rdist = abs(rx - 1) + abs(ry - 3)
            if ldist < rdist:
                lx = 1
                ly = 3
                answer += 'L'
            elif rdist < ldist:
                rx = 1
                ry = 3
                answer += 'R'
            else:
                if hand == 'left':
                    lx = 1
                    ly = 3
                    answer += 'L'  
                else:
                    rx = 1
                    ry = 3
                    answer += 'R' 
    return answer

# 스타트 위치는 (0, 3), (2, 3) (각각 왼손/오른손 좌표)
# 손가락이 움직이면 다음 움직이기 전까지는 그 자리 그대로 유지
# 이동 거리는 상하좌우 기준 한칸(대각선 처리 X)
# 1, 4, 7은 왼손, 3, 6, 9는 오른손만(거리 관계없이 무조건)
# 2, 5, 8, 0의 경우 손가락 거리로 결정, 같은 경우 hand에 따라 결정