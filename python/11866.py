import sys
sys.setrecursionlimit(10**6)
a, b = map(int, input().split())

ans = []
class linked_list():
    def __init__(self, n):
        self.head = None
        self.tail = None
        self.num = n

    def delete(self):
        self.tail.head = self.head
        self.head.tail = self.tail
        ans.append(self.num)
        
        self.head.cnt(b)
        
    def cnt(self, idx):
        if self.head == self:
            ans.append(self.num)
            return
        if idx == 1:
            self.delete()
            return
        self.head.cnt(idx-1)
start = linked_list(1)
idx = start
for i in range(2, a+1):
    start.head = linked_list(i)
    start.head.tail = start
    start = start.head
start.head = idx
idx.tail = start

idx.cnt(b)
print('<', end='')
for i in range(len(ans)-1):
    print(ans[i], end=', ')
print(ans[-1], end='>')



