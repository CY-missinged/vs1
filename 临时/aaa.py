import os
import pyautogui
import time
from pymysql import *

#qq启动文件地址
Path = r"C:\\Program Files (x86)\\Tencent\\QQ\\Bin\\QQScLauncher.exe"
os.startfile(Path)
time.sleep(6)
#移动鼠标点击登录按钮
pyautogui.moveTo(960, 700)
pyautogui.click()
time.sleep(4)
#登录完成点击加好友
pyautogui.moveTo(1482, 692)
pyautogui.click()
time.sleep(4)
# qq = 1809214019
#清除输入框内
pyautogui.press("backspace")
# pyautogui.typewrite(message=qq, interval=0.2)
pyautogui.typewrite("1648472616", interval=0.25)
#点击搜索
pyautogui.moveTo(1206, 277)
pyautogui.click()
time.sleep(1)
#点击加好友按钮
pyautogui.moveTo(559, 475)
pyautogui.click()
time.sleep(1)
print("ok")
#清除输入框内
# for i in range(15):
#     pyautogui.press("backspace")
#     #填写QQ号码
#     pyautogui.typewrite(message=qq, interval=1)
#     #点击搜索
#     pyautogui.moveTo(1145, 328)
#     pyautogui.click()
#     time.sleep(1)
#     #点击加好友按钮
#     pyautogui.moveTo(634, 496)
#     pyautogui.click()
#     time.sleep(1)
#     #点击下一步
#     pyautogui.moveTo(1070, 680)
#     pyautogui.click()
#     time.sleep(0.5)
#     pyautogui.click()
#     pyautogui.moveTo(1150, 680)
#     pyautogui.click()
#     #鼠标重新定位到输入框
#     pyautogui.moveTo(710, 320)
#     pyautogui.click()
#     print("添加QQ:" + str(qq) + "成功")
#     time.sleep(3)
