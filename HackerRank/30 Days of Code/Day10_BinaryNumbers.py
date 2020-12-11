# Day 10: Binary Numbers
# https://www.hackerrank.com/challenges/30-binary-numbers/problem

if __name__ == '__main__':
    n = int(input())
    
    count = 0
    maxi = 0
    while n > 0:
        if n % 2 == 1:
            count += 1
            if maxi < count:
                maxi = count
        else:
            count = 0
        n //= 2
    print(maxi)  

# 10진수를 2진수로 변환하고, 연속해서 나오는 1의 최대 개수 구하기