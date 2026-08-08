no = int(input("no ="))
count=0
for d in range(2,no):
    if no%d==0:
        count+=1;

if count==0:
    print("Prime no");
else :
    print("Not a Prime no");