import re
size = 156
with open("elaine_"+str(size)+".txt", 'r') as f:
   data = re.split(',|\n',f.read())
print(len(data))

with open("testBench"+str(size)+".txt", 'w') as f:
    for s in data:
        f.write("input <= std_logic_vector(to_unsigned(" + str(s) + ',8));\n' + "wait for  T;\n")
    f.write("wait for  "+str(size)+"*T;\n")

with open("inputMemoizated"+str(size)+".txt", 'w') as f:
    i = 0
    for s in data:
        f.write("std_logic_vector(to_unsigned(" + str(s) + ',8)),')
        i = i+1
        if i == size:
            f.write("\n     ")
            i = 0

with open("testBench"+str(size)+".h", 'w') as f:
    f.write("// "+str(size)+"x"+str(size)+" image size\n")
    f.write("unsigned char elaine_512_input["+str(size)+"*"+str(size)+"]= \n    {")
    i = 0
    for s in data:
        f.write(str(s) + ",")
        i = i+1
        if i == size:
            f.write("\n     ")
            i = 0
    f.write("};")

with open("result"+str(size)+".txt", 'r') as f:
   data = re.split(' |\n',f.read())
print(len(data))

with open("outputMemoizated"+str(size)+".txt", 'w') as f:
    i = 0
    for s in data:
        f.write("std_logic_vector(to_unsigned(" + str(s) + ',8)),')
        i = i+1
        if i == size:
            f.write("\n     ")
            i = 0
print("Done!")

