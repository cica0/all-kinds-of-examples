set -xe

THRIFT_PREFIX=thrift
export PATH=$PATH:$THRIFT_PREFIX/bin

# 生成 cpp 文件
rm -rf gen-cpp
thrift -strict  --gen cpp student.thrift

# 生成 python
rm -rf gen-py
thrift -strict  --gen py student.thrift


