class Calculator:
    def __init__(self,a,b):

        self.add = a+b
        self.sub = a-b
        self.mul = a*b
        self.div = a/b

    def show(self):
        print(f" \n {self.add} \n {self.sub} \n {self.mul} \n {self.div}")

a=float(input("Enter 1st no="))
b=float(input("Enter 2nd no="))

c= Calculator(a,b)
c.show()