class people:
    """示例"""
    my_name=[1,2,3]
    def __init__(self, name):
        self.name = name

    def speak(self,word):
        print(self.name,": {}".format(word))


class runner:
    def run(num):
        print("run {}".format(num))


class student (people, runner):
    def __init__(self, grade, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.grade = grade

    def eat(self, food):
        print(self.name, "like eat {}".format(food))

    def speak(self, word):
        print('this is student. ',end=" ")
        return super().speak(word)


p1 = people('Jack')
p2 = people("Mack")
s1 = student(100, 'red')
s2 = student(90, 'blue')
s1.eat("rou")
# print(dir(s1))
print(dir(s1))
s1.speak("hello")
print(s1.__dict__)

# isinstance 多态