# 소수 만들기
# https://programmers.co.kr/learn/courses/30/lessons/12977

def isPrime(n):
    for i in range(2, int(n / 2)):
        if n % i == 0:
            return False
    return True

def solution(nums):
    answer = 0
    for i in range(0, len(nums)):
        for j in range(i + 1, len(nums)):
            for k in range(j + 1, len(nums)):
                if isPrime(nums[i] + nums[j] + nums[k]):
                    answer += 1
    
    return answer

# 주어진 숫자(3~50개) 중 3개의 숫자를 더했을 때 소수가 되는 경우의 수는?