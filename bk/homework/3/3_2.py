"""
Date: 2023-10-01 15:10:56
LastEditTime: 2023-10-06 01:46:31
"""
"""
@File    		:   3_2.py
@Author   		:   bdd 
@Description	:   作业二：定义一个授权装饰器函数并测试其功能       
                        1. 编写一个AuthClass类封装name和pwd属性，对应用户名和密码
                            类中拥有授权方法auth()，判断当前对象的name值是否为python, pwd值是否为123，
                            如果是返回True，否则返回False。
                        2. 基于AuthClass创建一个用户对象user，创建时填入用户名和密码
                        3. 编写装饰器函数，首先让user对象来验证身份，如果验证通过，运行被装饰的函数，
                            否则打印认证失败，返回False

"""

from functools import wraps


class AuthClass:
    def __init__(self, name="", pwd=""):
        self.name = name
        self.pwd = pwd

    def auth(self):
        if self.name == "python" and self.pwd == "123":
            return True
        else:
            return False


def fun(need_fun):
    @wraps(need_fun)
    def out_fun(*args, **kwargs):
        if user.auth():
            return need_fun(*args, **kwargs)
        else:
            print("用户名或密码错误。")
            return False

    return out_fun


@fun
def test():
    return "登陆成功"


if __name__ == "__main__":
    user = AuthClass("python", "123")
    print(test())
