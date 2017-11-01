# -*- coding: UTF-8 -*- #

import argparse

parser = argparse.ArgumentParser()
parser.add_argument('integer', type=int, help='display an integer')
parser.add_argument('-string', type=str, dest='haha', default='abc', help='display an string')
args = parser.parse_args()

print args.integer

#if args.string:
#    print args.string
print args.haha
