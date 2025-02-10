class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.parent = None
        self.color = 'RED'  # RED or BLACK


class RedBlackTree:
    def __init__(self):
        self.TNULL = Node(0)  # Sentinel node
        self.TNULL.color = 'BLACK'
        self.root = self.TNULL
        self.counter = 0  # C 값 저장

    def insert(self, key):
        # 새 노드 생성
        new_node = Node(key)
        new_node.parent = None
        new_node.left = self.TNULL
        new_node.right = self.TNULL

        # 트리에 삽입하며 카운터 계산
        current = self.root
        parent = None
        local_counter = 0

        while current != self.TNULL:
            parent = current
            local_counter += 1  # 노드 탐색 시 카운터 증가
            if key < current.key:
                current = current.left
            else:
                current = current.right

        new_node.parent = parent
        if parent is None:  # 트리가 비어 있는 경우
            self.root = new_node
        elif key < parent.key:
            parent.left = new_node
        else:
            parent.right = new_node

        self.counter += local_counter  # C 값 누적
        self.fix_insert(new_node)  # 레드-블랙 트리 규칙 복원
        return self.counter

    def fix_insert(self, k):
        # 레드-블랙 트리 규칙 복원
        while k.parent and k.parent.color == 'RED':
            if k.parent == k.parent.parent.left:
                uncle = k.parent.parent.right
                if uncle.color == 'RED':  # Case 1: 삼촌이 RED
                    uncle.color = 'BLACK'
                    k.parent.color = 'BLACK'
                    k.parent.parent.color = 'RED'
                    k = k.parent.parent
                else:
                    if k == k.parent.right:  # Case 2: 삼촌이 BLACK, z는 오른쪽 자식
                        k = k.parent
                        self.left_rotate(k)
                    k.parent.color = 'BLACK'  # Case 3: 삼촌이 BLACK, z는 왼쪽 자식
                    k.parent.parent.color = 'RED'
                    self.right_rotate(k.parent.parent)
            else:
                uncle = k.parent.parent.left
                if uncle.color == 'RED':  # Case 1: 삼촌이 RED
                    uncle.color = 'BLACK'
                    k.parent.color = 'BLACK'
                    k.parent.parent.color = 'RED'
                    k = k.parent.parent
                else:
                    if k == k.parent.left:  # Case 2: 삼촌이 BLACK, z는 왼쪽 자식
                        k = k.parent
                        self.right_rotate(k)
                    k.parent.color = 'BLACK'  # Case 3: 삼촌이 BLACK, z는 오른쪽 자식
                    k.parent.parent.color = 'RED'
                    self.left_rotate(k.parent.parent)
        self.root.color = 'BLACK'

    def left_rotate(self, x):
        y = x.right
        x.right = y.left
        if y.left != self.TNULL:
            y.left.parent = x
        y.parent = x.parent
        if x.parent is None:
            self.root = y
        elif x == x.parent.left:
            x.parent.left = y
        else:
            x.parent.right = y
        y.left = x
        x.parent = y

    def right_rotate(self, x):
        y = x.left
        x.left = y.right
        if y.right != self.TNULL:
            y.right.parent = x
        y.parent = x.parent
        if x.parent is None:
            self.root = y
        elif x == x.parent.right:
            x.parent.right = y
        else:
            x.parent.left = y
        y.right = x
        x.parent = y


# 입력 처리 및 실행
import sys

input = sys.stdin.read
data = input().split()
N = int(data[0])
sequence = list(map(int, data[1:]))

rbt = RedBlackTree()
for num in sequence:
    print(rbt.insert(num))
