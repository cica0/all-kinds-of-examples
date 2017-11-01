set -xe

THRIFT_PREFIX=thrift
export PATH=$PATH:$THRIFT_PREFIX/bin

# 生成 cpp 文件
rm -rf gen-cpp
thrift -strict  --gen cpp shared.thrift
thrift -strict  --gen cpp tutorial.thrift 
