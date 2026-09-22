class Calculator:

    def add():
        a=float(input("Enter 1st no="))
        b=float(input("Enter 2nd no="))
        additon =a+b
        print("Addition = ",additon)

    def sub():
        a=float(input("Enter 1st no="))
        b=float(input("Enter 2nd no="))
        subtraction =a-b
        print("Subtraction = ", subtraction)

    def mul():
        a=float(input("Enter 1st no="))
        b=float(input("Enter 2nd no="))
        multiplication =a*b
        print("Multiplication = ",multiplication)

    def div():
        a=float(input("Enter 1st no="))
        b=float(input("Enter 2nd no="))
        division =a/b
        print("Division = ",division)

while True:
    print("\n1.Addition \n2.Subtraction \n3.Multiplication \n4.Division")
    choice=int(input("enter your choice ="))

    if choice==1:
        Calculator.add()
    elif choice==2:
        Calculator.sub()
    elif choice==3:
        Calculator.mul()
    elif choice==4:
        Calculator.div()
    else:
        print("Invalid Choice...!")
        break
        