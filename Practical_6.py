"""This Code only works for a specific input file "input.txt" """



file = open("input.txt")

text = file.read()
print("INPUT RECEIVED : ")
print()
print(text)
print()

con = text.split("\n")
#print(con)
first = file.readline().split(" ")
#print(first)
d = {"L":4,"ST":4,"BR":2,"DS":4,"DC":4}

symbols=[]

for j in range(len(con)-2):
    if(con[j].split(" ")[1]=="START"):
      symbols.append(con[j].split(" ")[0])
      continue
    if(con[j].split(" ")[0]=="ENTRY"):
      x = con[j].split(" ")[1].split(",")
      for k in x:
        symbols.append(k)
      continue
    if(con[j].split(" ")[0]=="EXTRN"):
      x = con[j].split(" ")[1].split(",")
      for l in x:
        symbols.append(l)
      continue

start=con[0]
entry=con[1]
extrn=con[2]
#print(symbols)
esd = {}
idn = 1
for item in symbols:
    if item in start:
        esd[item] = "0"+str(idn)
        idn+=1
        continue
    if item in extrn:
        esd[item] = "0" + str(idn)
        
        idn+=1
        continue
    else:
        esd[item] = "-"

#print(esd)


loc=[]
rl = 0
f=0
loc.append(0)
loc.append(0)
for j in range(2,len(con)+1):
  f=0
  for k in d:
    #print(k)
    if k in con[j-1]:
      #print(con[j-1])
      f+=1
      rl+=d[k]
      loc.append(rl)
      break
  if(f==0):
    loc.append(rl)
  
#print(loc)

rel_E1 = 30
rel_E2 = 34

print("Added Relative Locations :")
print()
for x in range(len(con)):
  print(loc[x],"\t",con[x])

length = loc[len(loc)-1]


print()
print("-------------------------ESD Cards------------------------------")
print()
print("{}\t{}\t{}\t{}\t{}".format("Symbol","Type","ID","R.Loc","Length"))

for i in range(3):
  if i==0:
    line = "{}\t{}\t{}\t{}\t{}".format(symbols[0],"SD",esd[symbols[0]],0,length)
    print(line)
    continue
  elif i==1:
    line = "{}\t{}\t{}\t{}\t{}".format(symbols[1],"LD",esd[symbols[1]],"18","-")
    line1 = "{}\t{}\t{}\t{}\t{}".format(symbols[2],"LD",esd[symbols[2]],"22","-")
  
  else:
    line = "{}\t{}\t{}\t{}\t{}".format(symbols[3],"ER",esd[symbols[3]],"-","-")
    line1 = "{}\t{}\t{}\t{}\t{}".format(symbols[4],"ER",esd[symbols[4]],"-","-")
  print(line)
  print(line1)

print()
print("-------------------------TXT Cards------------------------------")
print()
print("{}\t{}".format("R.Loc","Content"))

print(rel_E1,"\t",0)
print(rel_E2,"\t",0)

#print(30,"\t",extrn.split()[1].split(",")[0])
#print(34,"\t",extrn.split()[1].split(",")[1])


print()
print("-------------------------RLD Cards------------------------------")
print()
print("{}\t{}\t{}\t{}".format("ESD ID","Length","Flag","R.Loc"))

print("{}\t{}\t{}\t{}".format(esd["E1"],4,"+",rel_E1))
print("{}\t{}\t{}\t{}".format(esd["E2"],4,"+",rel_E2))




