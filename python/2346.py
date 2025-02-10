import sys

n = int(sys.stdin.readline())
data = list(enumerate((map(int, sys.stdin.readline().split())), start = 1))
idx = 0

while data:
	ret = data.pop(idx)
	print(ret[0], end=' ')
	if ret[1] < 0 and data:
		idx = (idx + ret[1]) % len(data)
	elif ret[1] > 0 and data:
		idx = (idx + (ret[1] - 1)) % len(data)