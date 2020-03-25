array = [4,5,6]

for i in range(0,len(array)+3):
    print(array[i%3], array[(i+1)%3], array[(i+2)%3])