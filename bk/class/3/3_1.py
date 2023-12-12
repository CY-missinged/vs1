class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    
    def move_to(self, x, y):
        self.x = x
        self.y = y

    def dis_to(self, x, y):
        print(((self.x-x)**2+(self.y-y)**2)**0.5)

    def repr(self):
        print("postion:", self.x, self.y)


p = Point(1,1)
p.repr()
p.dis_to(0, 0)
p.move_to(3,3)
p.repr()