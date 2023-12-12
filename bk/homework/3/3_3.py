"""
Date: 2023-10-06 01:57:08
LastEditTime: 2023-10-06 01:59:11
"""
"""
@File    		:   3_3.py
@Author   		:   bdd 
@Description	:   作业三：定义一个带文件名参数的记录日志装饰器函数，并测试其功能
    程序分析：在课堂练习基础上，给装饰器函数增加输入日志文件名参数，在日志记录时将日志信息写入到对应的日志文件。
"""


from functools import wraps
import time


def logit(logfile="out.log"):
    def logging_decorator(func):
        @wraps(func)
        def wrapped_function(*args, **kwargs):
            log_string = func.__name__ + " was called"
            print(log_string)
            # 打开logfile，并写入内容
            with open(logfile, "a") as opened_file:
                # 现在将日志打到指定的logfile
                opened_file.write(
                    log_string
                    + time.strftime(" %Y-%m-%d %H:%M:%S", time.localtime())
                    + "\n"
                )
            return func(*args, **kwargs)

        return wrapped_function

    return logging_decorator


@logit(logfile="func1.log")
def myfunc1():
    pass


@logit(logfile="func2.log")
def myfunc2():
    pass


if __name__ == "__main__":
    myfunc1()
    myfunc2()
