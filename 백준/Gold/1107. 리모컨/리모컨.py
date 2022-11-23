import sys; input = sys.stdin.readline

target = int(input())
n = int(input())
broken = list(map(int, input().split()))

min_count = abs(100 - target)
for num in range(1000001):
    num = str(num)
    for j in range(len(num)):
        if int(num[j]) in broken:
            break
        elif j == len(num) - 1:
            min_count = min(min_count, abs(int(num) - target) + len(num))

print(min_count)