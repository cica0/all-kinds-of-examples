# coding: UTF-8

def createDataSet():
    dataSet = [[1,1,'yes'],[1,1,'yes'],[1,0,'no'],[0,1,'no'],[1,0,'no']]
    labels = ['no surfacing', 'flippers']
    return dataSet,labels

from math import log


def calcShannonEnt(dataSet):
    num = len(dataSet)
    labelsCounts = {}
    for featVec in dataSet:
        currentLabel = featVec[-1]
        if currentLabel not in labelsCounts.keys():
            labelsCounts[currentLabel]=0
        labelsCounts[currentLabel]+=1
    shannonEnt=0.0
    for key in labelsCounts:
        prob = float(labelsCounts[key]) / num
        shannonEnt -= prob * log(prob, 2)
    return shannonEnt    


#把第axis列所有值为value的dataSet提取出来
def splitDataSet(dataSet, axis, value):
    retDataSet=[]
    for featVec in dataSet:
        if featVec[axis]==value:
            reduceFeatVec=featVec[:axis]
            reduceFeatVec.extend(featVec[axis+1:])
            retDataSet.append(reduceFeatVec)
    return retDataSet


def choostBestFeatureToSplit(dataSet):
    numFeature=len(dataSet[0])-1
    baseEntropy=calcShannonEnt(dataSet)
    bestInfoGain=0
    bestFeature=1
    for i in range(numFeature):
        featList=[number[i] for number in dataSet]
        uniqualVals=set(featList)
        newEntropy=0
        for value in uniqualVals:
            subDataSet=splitDataSet(dataSet, i, value)
            prob=len(subDataSet)/float(len(dataSet))
            newEntropy+=prob*calcShannonEnt(subDataSet)
        infoGain=baseEntropy-newEntropy
        if(infoGain>bestInfoGain):
            bestInfoGain=infoGain
            bestFeature=i
    return bestFeature

            

