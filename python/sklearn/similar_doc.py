#!/usr/bin/python$
# -*- coding: utf-8 -*-

import pandas,bumpy,codecs,os,jieba
from sklearn.metrics import pairwise_distances
## 创建语料库
#corpos=pandas.DataFrame(columns=['filepath','content'])
#for root,dirs,files in os.walk('文件夹路径')：#储存文章的文件夹
#     for name in files:
#           filepath=root+'/'+name
#           f=codecs.open(filepath,'r','utf-8')
#           content=f.read()
#           f.close()
#           corpos.loc[len(corpos)+1]=[filepath,content.strip()]
##分词
#filepaths=[]
#segments=[]
#for i in range(len(corpos)):
#    file=corpos.loc[i].filepath
#    segs=jieba.cut(corpos.loc[i].content)
#    for seg in segs:
#        if len(seg.strip())>1:
#            filepaths.append(file)
#            segments.append(seg)
##创建数据框储存数据
#segmentsDF=pandas.DataFrame({'filepath':filepaths,'segment':segments}
#
##去杂词
#stopwords=pandas.read_table('文档路径'）
#fsegments=segmentsDF[~segmentDF.segments.isin(stopwords.stopword)]
#
##按文章进行词频的统计
#seg_group=fsegments.groupby(['filepath','segment'])['segment'].agg({'count':bumpy.size}).
#reset_index().sort(columns='segment',ascending=False)
#seg_group=seg_group[seg_group.count>1]
#
##进行文本向量计算，其中index为行，columns为列
#textvector=seg_group.pivot_table(values='count',index='filepath',columns='segment',
#fill_values=0,aggfunc=[numpy.size])
#from sklearn.metrics import pairwise_distances
#distance_matrix=pairwise_distance(textvector,metric='cosine')
#df_distance=pandas.DataFrame(distance_matrix)
#
## 匹配结果series排序用order（ascending=True）升序，dataframe 用sort（columns=） 或者sort_index(axis=,ascending=)
#for i in range(len(corpos)):
#    tagis=textvector.index[df_distance.loc[:,i].order(ascending=True)[1:6].index]
#    print(text vector.index[i]+'相似文章'）
#    print('\n'.join(tagis))
#    print('\n')
#
