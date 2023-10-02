import os
import pyautogui
import time
from pymysql import *

# pyautogui.moveTo(1766,328)
# pyautogui.click()
# for i in range(10):
#     k = str(i)
#     kl= k.zfill(4)
#     pyautogui.press("backspace")
#     pyautogui.press("backspace")
#     pyautogui.press("backspace")
#     pyautogui.press("backspace")
#     pyautogui.typewrite(kl, interval=0.15)
#     print(kl)
#     pyautogui.moveTo(1766,428)
#     pyautogui.click()

for i in range(1000):
    k = str(i)
    kl= k.zfill(3)
    pyautogui.moveTo(1700,121)
    pyautogui.click()
    pyautogui.keyDown("backspace")
    pyautogui.keyUp("backspace")
    pyautogui.keyDown("backspace")
    pyautogui.keyUp("backspace")
    pyautogui.keyDown("backspace")
    pyautogui.keyUp("backspace")
    pyautogui.keyDown("backspace")
    pyautogui.keyUp("backspace")
    pyautogui.typewrite(kl, interval=0.0001)
    flag=1
    for k11 in range(10):
        if flag==0:
            pyautogui.moveTo(1700,121)
            pyautogui.click()
            pyautogui.keyDown("backspace")
            pyautogui.keyUp("backspace")
        else:
            flag=0
        k2=str(k11)
        pyautogui.moveTo(1700,121)
        pyautogui.click()
        pyautogui.typewrite(k2, interval=0.0)
        print(kl+k2)
        pyautogui.moveTo(1766,428)
        pyautogui.click()
        # time.sleep(1)

# pyautogui.moveTo(1700,121)
# pyautogui.click()
#  //////////////////////////654
