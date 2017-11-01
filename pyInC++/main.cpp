#include "python2.7/Python.h"
#include <iostream>
using namespace std;



//int main()
//{
//    Py_Initialize();  
//        
//    PyRun_SimpleString("print 'hello'");
//
//    Py_Finalize();  
//}
//
int main()
{
    Py_Initialize();    // 初始化

    // 将Python工作路径切换到待调用模块所在目录，一定要保证路径名的正确性
    string path = "/home/chang/study/pyInC++/chang";
    string chdir_cmd = string("sys.path.append(\"") + path + "\")";
    const char* cstr_cmd = chdir_cmd.c_str();
    PyRun_SimpleString("import sys");
    PyRun_SimpleString(cstr_cmd);

    // 加载模块
    PyObject* moduleName = PyString_FromString("add"); //模块名，不是文件名
    PyObject* pModule = PyImport_Import(moduleName);
//    const char* moduleName=string("chang").c_str();    //这个是被调用的py文件模块名字
//    PyObject* pModule = PyImport_ImportModule(moduleName);

    if (!pModule) // 加载模块失败
    {
        cout << "[ERROR] Python get module failed." << endl;
        return 0;
    }
    cout << "[INFO] Python get module succeed." << endl;

    // 加载函数
    const char* funcName=string("test_add").c_str();  //这是此py文件模块中被调用的函数名字
//    PyObject* pv = PyObject_GetAttrString(pModule, "test_add");
    PyObject* pv = PyObject_GetAttrString(pModule, funcName);
//    if (!pv || !PyCallable_Check(pv))  // 验证是否加载成功
    if (!pv)  // 验证是否加载成功
    {
        cout << "[ERROR] Can't find funftion (test_add)" << endl;
        return 0;
    }
    cout << "[INFO] Get function (test_add) succeed." << endl;

    // 设置参数
    PyObject* args = PyTuple_New(2);   // 2个参数
    PyObject* arg1 = PyInt_FromLong(4);    // 参数一设为4
    PyObject* arg2 = PyInt_FromLong(3);    // 参数二设为3
    PyTuple_SetItem(args, 0, arg1);
    PyTuple_SetItem(args, 1, arg2);

    // 调用函数
    PyObject* pRet = PyObject_CallObject(pv, args);

    // 获取参数
    if (pRet)  // 验证是否调用成功
    {
        long result = PyInt_AsLong(pRet);
        cout << "result:" << result << endl;
    }

    Py_Finalize();      
//## 释放资源

    return 0;
}
