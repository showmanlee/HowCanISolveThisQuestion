# 야근 지수
# https://programmers.co.kr/learn/courses/30/lessons/12927

import heapq

def solution(n, works):
    answer = 0
    heap = []
    for w in works:
        heapq.heappush(heap, -w)
    for i in range(0, n):
        h = heapq.heappop(heap)
        heapq.heappush(heap, h + 1)
    for p in heap:
        if p > 0:
            return 0
        answer += p * p
    return answer

# 계속 정렬을 해줘야 할 때는 힙을 사용하자
# 단순 리스트를 사용해버리면 nlogn으로 풀릴 게 n^2의 수렁으로 빠져버린