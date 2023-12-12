"""
Date: 2023-10-01 14:15:28
LastEditTime: 2023-10-03 02:26:37
"""
"""
@File    		:   3_1.py
@Author   		:   bdd 
@Description	:   作业一：Python类的编写与继承
    程序分析：要求编写以下类，并创建student和CollegeStudent对象进行测试，让子类调用自身和父类的方法。
"""
import time


class Person:
    """
    编写 Person 类，具有以下属性和方法：
        1. 属性：姓名name, 年龄age 。
        2. 方法：speak（），打印出当前Person对象的姓名和年龄。
    """

    def __init__(self, name="", age=0):
        self.name = name
        self.age = age

    def speak(self):
        print("name: ", self.name)
        print("age: ", self.age)


class Student(Person):
    """
    编写 Student 类继承 Person类，具有以下属性和方法：
        1. 属性：姓名name, 年龄age, 学校school 和 学号my_id。
        2. 方法：speak（），打印出当前Student对象的所有属性信息。
        3. 方法：run (v, times)，设置学生速度和时间，输出学生跑步距离。
    """

    def __init__(self, name="", age=0, school="", my_id=""):
        super().__init__(name, age)
        self.school = school
        self.my_id = my_id

    def speak(self):
        super().speak()
        print("school: ", self.school)
        print("id: ", self.my_id)

    def run(self, v, times):
        print(
            "student",
            self.my_id,
            " ran ",
            v * times,
        )


class CollegeStudent(Student):
    """
    编写 CollegeStudent 类继承 Student类，具有以下属性和方法：
        1. 属性：姓名name, 年龄age, 学校school, 学号my_id 和 语言language。
        2. 方法：speak（），打印出当前CollegeStudent对象的所有属性信息。
        3. 方法：coding ()，使用10秒钟打印出 ”I am coding . . . . . . . . . .”（十个点）。
    """

    def __init__(self, name="", age=0, school="", my_id="", language=""):
        super().__init__(name, age, school, my_id)
        self.language = language

    def speak(self):
        super().speak()
        print("language: ", self.language)

    def coding(self):
        print("I am coding ", end=" ")
        for i in range(9):
            print(".", end=" ")
            time.sleep(1)
        print(".")


def test_student():
    student = Student("Tom", 19, "xaut", "1001")
    super(Student, student).speak()
    print()
    student.speak()
    print()
    student.run(5,6)


def test_collegeStudent():
    collegeStudent = CollegeStudent("Jack", 20, "xaut", "1002", "CH")
    super(Student, collegeStudent).speak()
    print()
    super(CollegeStudent, collegeStudent).speak()
    print()
    collegeStudent.speak()
    print()
    collegeStudent.run(2, 3)
    print()
    collegeStudent.coding()


if __name__ == "__main__":
    test_student()
    print()
    test_collegeStudent()
