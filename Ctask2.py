n1 = int(input("n1= "))
n2 = int(input("n2= "))

x = list(str(n1))
x.sort()
x = int("".join(x))

y = list(str(n2))
y.sort()
y = int("".join(y))

if x==y:
    print("Anagram")
else :
    print("Not Anagram")