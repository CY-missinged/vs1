# c2_12.py
# import time

# """
# UNIXʱ��ת����ʱ��
# """

# Time_19700101 = time.time()

# total_s = int(Time_19700101)
# time_s = total_s % 60

# total_min = int(total_s / 60)
# time_min = total_min % 60

# total_h = int(total_min / 60)
# time_h = total_h % 24

# print(time_h + 8, time_min, time_s)

# time_time = time.localtime(Time_19700101)
# print(time.strftime("%H:%M:%S", time_time))

# p23.py
# # ��ʽ������PIֵ

# def pipi(x):
#     c = 1
#     total = 1
#     print("4 * (1", end="")
#     for i in range(3, 2 * x, 2):
#         print(format(-1 * c, "+d"), end="")
#         print(f"/{i}", end="")
#         c = -1 * c
#         total = total + (c * 1 / i)
#     print(f")={format(4 * total, '.4f')}")


# pipi(6)
# pipi(8)


# p24.py
# import turtle

# """
# ��������
# """

# turtle.hideturtle()
# turtle.goto(100, 0)
# turtle.goto(100, 35)
# turtle.goto(0, 35)
# turtle.goto(0, 0)
# turtle.goto(-25, -25)
# turtle.goto(75, -25)
# turtle.goto(75, 10)
# turtle.goto(-25, 10)
# turtle.goto(-25, -25)
# turtle.goto(-25, 10)
# turtle.goto(0, 35)
# turtle.goto(0, 0)
# turtle.goto(100, 0)
# turtle.goto(75, -25)
# turtle.goto(75, 10)
# turtle.goto(100, 35)
# turtle.done()


# point_point_juli.py
# import turtle

# """
# ��������
# """

# turtle.hideturtle()
# turtle.goto(100, 0)
# turtle.goto(100, 35)
# turtle.goto(0, 35)
# turtle.goto(0, 0)
# turtle.goto(-25, -25)
# turtle.goto(75, -25)
# turtle.goto(75, 10)
# turtle.goto(-25, 10)
# turtle.goto(-25, -25)
# turtle.goto(-25, 10)
# turtle.goto(0, 35)
# turtle.goto(0, 0)
# turtle.goto(100, 0)
# turtle.goto(75, -25)
# turtle.goto(75, 10)
# turtle.goto(100, 35)
# turtle.done()


# p22.py
# # ������

# print("a\ta^2\ta^3")
# for x in range(4):
#     i = x + 1
#     print(f"{i}\t{i ** 2}\t{i ** 3}")


# test.py
# # a = 3
# # b = 2
# # print(a, b)
# # a, b = b, a
# # print(a, b)
# # a, b = eval(input("a,b:"))
# # print(a, b)


# # i = 1
# # print(i)
# # i += 1
# # #  +=֮�䲻�ܼӿո�
# # print(i)


# # # ��λround���Ͻ�λ,�ڶ���������С��λ�����������Ϊ�㣬����һλС����˵��Ϊfloat����
# # i = 5.6000
# # print(i)
# # print("����ȡ��", int(i))
# # print("����ȡ��", round(i))
# # print(round(i, 3))
# #
# # i = 5.63123123
# # print(i)
# # print("����ȡ��", int(i))
# # print("����ȡ��", round(i))
# # print(round(i, 3))


# i = 1.2356
# i = int(i * 100)
# i = i / 100
# print(i)
