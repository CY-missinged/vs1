import math
from sympy import*
hl=1852 # 1海里=1852m
a=[0.3131,0.5828,1.6004,0.3811] # 平分之后每一个子海域的坡度
po_chang = [2,2.5,2,2] # 坡的水平长度
po_kuan = [2.5,2,2.5,2.5]
my_h0=[26.02,36.25,46.27,85.60]
total_x = 0
total_i = 0
for my_i in range(4):
    number=po_chang[my_i]*hl # 海里变成米
    A=math.radians(a[my_i]) # 化为弧度
    h0=my_h0[my_i] # 东边界海水深度
    # 此处计算β=90°时的情况,90°时沿着测线方向高度不变
    k90=math.tan(math.pi/2)
    # 设将第一条测线向下挪动x米
    x = Symbol('x')
    x= solve((2*math.sqrt(3)*(k90*k90+1)*(h0+x*math.tan(A))/(k90*k90+1-3*k90*k90*math.tan(A)*math.tan(A)))-2*x,x)[0]
    #print(x)
    # 至此得到第一条测线的位置
    w1=2*x 
    num=w1
    i=1
    ww=2*x
    AH=h0+x*math.tan(A)
    while num<number:
        y=Symbol('y')
        a_h=(AH+y*math.tan(A)) # 定义一个带y的高度，y此时为变量
        y=solve((2*math.sqrt(3)*(k90*k90+1)*a_h/(k90*k90+1-3*k90*k90*math.tan(A)*math.tan(A)))/2+ww/2-y,y)[0] # 求解出y的值
        AH=AH+y*math.tan(A) # 这时候y有值
        w=(2*math.sqrt(3)*(k90*k90+1)*AH/(k90*k90+1-3*k90*k90*math.tan(A)*math.tan(A)))
        ww=w
        num=num+w
        i=i+1
    print('w=',w) # 最低处的侧线的覆盖宽度
    print('num-number=',num-number) # 可能覆盖的宽度 
    print('num=',num) # 所有侧线的宽度
    print('i=',i) # 
    total_i = total_i+i
    total_x=total_x+i*po_kuan[my_i]*hl
print("total=",total_x,total_i)
