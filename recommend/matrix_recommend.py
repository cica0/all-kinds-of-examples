#!/usr/bin/python
import numpy

def read_data():
    with open("tmp_data") as fp:
        array = fp.readlines()
        num = len(array)
        returnMat = numpy.zeros((num,3))
        index = 0
        for line in array:
            line = line.strip()
            linelist = line.split(',')
            returnMat[index,:]=linelist[0:3]
            index+=1
        return returnMat

if __name__=="__main__":
    matrix = read_data()
    print matrix
