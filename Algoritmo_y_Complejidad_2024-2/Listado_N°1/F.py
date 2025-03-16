n = input()
n = n.split()
cont = 0
t = 0
l = []
while (cont < int(n[1])):
    x = int(input())
    if x not in l:
        l.append(x)
        t += 1
    cont += 1
l.sort()
for x in range(int(n[0])):
    if x not in l:
        print(x)
print("Mario got " + str(t)+" of the dangerous obstacles.")