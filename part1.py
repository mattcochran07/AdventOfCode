import sys
import re

def remove_all_instances_of(lineList, keyChar):
    for elem in lineList:
        if elem == keyChar:
            lineList.remove(elem)

def num_occurances(lineList, key):
    numOccurances = 0
    for elem in lineList:
        if elem == key:
            numOccurances += 1
    return numOccurances

def remove_all_empty_elements_from_list(lineList):
    for elem in lineList:
        if len(elem) == 0:
            lineList.remove(elem)

if len(sys.argv) == 2:
    inputFilename = sys.argv[1]
    
    f = open(inputFilename, 'r')
    lines = f.readlines()
    #initialize lists
    list1 = []
    list2 = []
    for line in lines:
        #print(line)
        lineList = line.split(" ")
        #lineList.strip()
        remove_all_empty_elements_from_list(lineList)
        remove_all_empty_elements_from_list(lineList)
        #print(lineList)
        list1.append(int(lineList[0]))
        list2.append(int(lineList[1]))
    list1.sort()
    list2.sort()
    print(list1)
    print(list2)
    sumDif = 0
    for i in range(len(list1)):
        sumDif += abs(list1[i] - list2[i])
    print("sum = ", sumDif)
