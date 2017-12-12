#!/bin/python
# encoding=utf8

import tensorflow as tf
import numpy as np
import os
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'

'''
#定义一个常量
node1 = tf.constant(3.0, dtype=tf.float32)
node2 = tf.constant(4.0)
node3 = tf.add(node1, node2)

sess = tf.Session()
print (sess.run([node1,node2]))
print ("node3:",node3)
print (sess.run(node3))

#提供一个占位符，在使用sess.run使用的时候给传值
a = tf.placeholder(tf.float32)
b = tf.placeholder(tf.float32)
adder_node = a + b
print (sess.run(adder_node, {a:3,b:4.5}))
'''

#定义variable的时候，变量并不会被初始化，只有调用global_variables_initialize()的时候才会
W = tf.Variable([.3], dtype=tf.float32)
b = tf.Variable([-.3], dtype=tf.float32)
x = tf.placeholder(tf.float32)
linear_model = W*x+b
init = tf.global_variables_initializer()
sess = tf.Session()
sess.run(init)
print (sess.run(linear_model,{x:[1,2,3,4]}))
