import time


class Mytime:
    def __init__(self, hour, min, sec):
        self.hour = hour
        self.min = min
        self.sec = sec

    def run(self):
        self.sec += 1
        if self.sec > 60:
            self.min = self.min + 1
            self.sec = 0
        if self.min > 60:
            self.hour = self.hour + 1
            self.min = 0
        if self.hour > 24:
            self.hour = 0

    def show(self):
        print("%02d:%02d:%02d" % (self.hour, self.min, self.sec))


def main():
    x = Mytime(1, 2, 3)
    while True:
        x.show()
        time.sleep(1)
        x.run()


main()
