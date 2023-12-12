def fun3():
    x, y=0, 0
    while True:
        s = input()
        if s != "STOP":
            p = s.split(" ")
            if p[0] == "UP":
                y += int(p[1])
            if p[0] == "DOWN":
                y -= int(p[1])
            if p[0] == "LEFT":
                x -= int(p[1])
            if p[0] == "RIGHT":
                x += int(p[1])
        else:
            print(round((x**2+y**2)**0.5))
            break
    

if __name__ == "__main__":
    fun3()