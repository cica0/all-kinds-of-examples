#include <iostream>
#include <algorithm>
using namespace std;
bool compare(const int &a,const int &b) {
    return a > b;
}

bool is_odd (const int &a) {
    return a%2;
}
int main() {
    vector<int> array ;
    for(int i =1;i<10;++i) array.push_back(i);
    random_shuffle(array.begin(), array.end());
    cout << "初始数列为：" << endl;
    for(unsigned int i =0;i<array.size();++i)
        cout << array[i]  << "," ;
    cout << endl;

    cout << "sort之后：" << endl;
    sort(array.begin(), array.end());
    for(unsigned int i =0;i<array.size();++i)
        cout << array[i]  << "," ;
    cout << endl;

    //使用特定的比较函数进行排序
    random_shuffle(array.begin(), array.end());
    cout << "将数组打乱为：" << endl;
    for(unsigned int i =0;i<array.size();++i)
        cout << array[i]  << "," ;
    cout << endl;
    cout << "使用compare函数进行sort之后：" << endl;
    sort(array.begin(), array.end(), compare);
    for(unsigned int i =0;i<array.size();++i)
        cout << array[i]  << "," ;
    cout << endl;

    //部分排序，只排从第一个参数到第二个参数之间的个数个排序, 底层采用堆排序
    random_shuffle(array.begin(), array.end());
    cout << "将数组打乱为：" << endl;
    for(unsigned int i =0;i<array.size();++i)
        cout << array[i]  << "," ;
    cout << endl;
    cout << "partial_sort(参数为(0,3))之后:" << endl;
    partial_sort(array.begin(), array.begin()+3, array.end());
    for(unsigned int i =0;i<array.size();++i)
        cout << array[i]  << "," ;
    cout << endl;

    //第二个参数所在的位置为排好序之后此位置的元素,注意array.begin()为第一个，以此类推
    random_shuffle(array.begin(), array.end());
    cout << "将数组打乱为：" << endl;
    for(unsigned int i =0;i<array.size();++i)
        cout << array[i]  << "," ;
    cout << endl;
    cout << "nth_element(参数为第三位)之后：" << endl;
    nth_element(array.begin(), array.begin()+2, array.end());
    for(unsigned int i =0;i<array.size();++i)
        cout << array[i]  << "," ;
    cout << endl;

    //将整个数组分成两部分，以is_odd函数为真的在前部分，为假的在后半部分
    random_shuffle(array.begin(), array.end());
    cout << "将数组打乱为：" << endl;
    for(unsigned int i =0;i<array.size();++i)
        cout << array[i]  << "," ;
    cout << endl;
    cout << "partition(使用is_odd函数比较)之后：" << endl;
    partition(array.begin(), array.end(), is_odd);
    for(unsigned int i =0;i<array.size();++i)
        cout << array[i]  << "," ;
    cout << endl;
    return 0;
}
