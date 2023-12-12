def fun1():
    str = input("请输入字符串:")
    str1 = 0 # 字母数量
    str2 = 0 # 数字数量
    for i in str:
        if i > 'a' and i< 'z':
            str1= str1+1
        elif i > '0' and i < '9':
            str2  = str2 + 1
    print(str1, "个字母，", str2, "个数字")


if __name__ == '__main__':
    fun1()