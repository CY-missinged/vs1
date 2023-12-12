'''
Date: 2023-09-16 17:41:48
LastEditTime: 2023-10-24 18:56:17
'''
"""
Date: 2023-09-16 17:41:48
LastEditTime: 2023-10-22 11:06:19
"""
"""
Date: 2023-09-16 17:41:48
LastEditTime: 2023-10-06 01:18:25
"""
"""
Date: 2023-09-16 17:41:48
LastEditTime: 2023-10-05 01:07:29
"""


def fun(fun_out):
    def out_fun():
        print("start")
        fun_out()
        print("end")

    return out_fun


def p():
    print("test")


#  wraps(p)

print("old:")
p()
print("\nnew:")
p = fun(p)
p()


@fun  # 等于 p1 = fun(p1)
def p1():
    print("hhh")


print()
p1()
