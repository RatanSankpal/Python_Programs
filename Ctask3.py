no = int(input("no ="))

temp = no
digits = len(str(no))
sum = 0

while no > 0:
    dig = no % 10
    sum = sum + dig**digits
    no = no//10


if temp == sum:
    print("Armstrong no")
else :
    print("Not Armstrong no")
