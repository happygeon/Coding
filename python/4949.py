string = input()
while string != '.':
    stack = []
    flag = True
    for i in string:
        if(i == '(' or i == '['):
            stack.append(i)
        elif(i == ')'):
            if stack and stack[-1] == '(':
                stack.pop()
            else:
                flag = False
                break
        elif(i == ']'):
            if stack and stack[-1] == '[':
                stack.pop()
            else:
                flag = False
                break
    if(stack or not flag):
        print('no')
    else:
        print('yes')
    string = input()