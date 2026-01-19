
array = [40,20,3,500,100,1];

for index in range(1,len(array)):
    currentValue = array[index];
    currentIndex = index;
    while currentIndex > 0 and currentValue < array[index - 1]:
        array[currentIndex] = array[currentIndex - 1];
        currentIndex-= 1;
    array[currentIndex] = currentValue;
print(array)
