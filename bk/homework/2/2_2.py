def fun2():
    str1, str2 = input("请输入两个字符串（用,隔开）:").split(',')
    str1 = str1.strip()
    str2 = str2.strip()
    if len(str1) != len(str2):
        return False
    x1 = list(str1)
    x1.sort()
    x2 = list(str2)
    x2.sort()
    for i in x1:
        if i not in x2:
            return False
        else:
            x2.remove(i)
    return True


if __name__ == '__main__':
    print(fun2())
