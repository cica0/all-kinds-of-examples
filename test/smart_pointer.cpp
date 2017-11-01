//Author: chang
//This is a test of smart pointer

#include <iostream>
#include <memory>   //智能指针使用必须包含的头文件
#include <string>

using std::string;

class Base {
    public:
        Base(string s) {
            str = s;
        }
        ~Base() {
            std::cout << "base delete:" << str << std::endl;;
        }
        string& getStr() {
            return str;
        }
        void setStr(string s) {
            str = s;
        }
        void print() {
            std::cout << "print " << str << std::endl;;
        }
    private:
        string str;
};

//void AutoPtrTest(void)
//{
//    std::cout << "enter into AutoPtrTest" << std::endl;
//    std::auto_ptr<Base> p_auto1(new Base("123"));
//    std::auto_ptr<Base> p_auto2(new Base("456"));
//	//使用这种方式对auto_ptr进行判空
//	if (p_auto1.get() == NULL)
//		std::cout << "p_auto1 is null" << std::endl;
//	else
//		std::cout << "p_auto1 is not null" << std::endl;
//    //pTest2为空，析构时出现错误
//    //p_auto1 = p_auto2;
//    p_auto1->print();
//    p_auto2->print();
//
//}

void UniquePtrTest(void)
{
    std::cout << "enter into UniquePtrTest" << std::endl;
    std::unique_ptr<Base> p_unique1(new Base("123"));
    std::unique_ptr<Base> p_unique2(new Base("456"));
	//使用这种方式对unique_ptr进行判空
	if (p_unique1 == NULL)					
		std::cout << "p_unique1 is null" << std::endl;
	else
		std::cout << "p_unique1 is not null" << std::endl;
	Base* p_base = new Base("789");
    //首先p_unique2进行析构后为空，指针转移给p_unique1，p_unique2打印时出现错误
    //p_unique1 = std::move(p_unique2);
    p_unique1->print();
    p_unique2->print();
	//p_unique1.release();												//放弃指针的使用权，使unique_ptr置为空，但是所指向的内存并没有清空
	//p_unique1->print();												//release之后p_unique1为空，再进行打印会出现错误
	p_unique2.reset(p_base);											//将p_unique2的指针指向b_base,原指针内存清空
																		/////注意：这里reset内的指针不能是智能指针，需要是内置指针
	p_unique2->print();												
	p_unique2.reset();													//释放智能指针所指向的对象,在自动释放之前想要人工释放，可以使用这种方式
	//p_unique2->print();												//reset之后p_unique2为空，再进行打印会出现错误
}

void SharedPtrTest(void)
{
    std::cout << "enter into SharedPtrTest" << std::endl;
	std::shared_ptr<Base> p_shared(new Base("123"));
	p_shared->print();
	Base* p_base = p_shared.get();											//使用这种方式获取智能指针保存的指针,需小心，如果智能指针释放了对象，普通指针也为空
	std::cout << "p_shared.count:" << p_shared.use_count() << std::endl;	//与共享对象的shared_ptr的个数
	std::cout << "p_shared.unique:" << p_shared.unique() << std::endl;		//user_count返回1时候为true，否则为false
}

void WeakPtrTest(void)
{
    std::cout << "enter into WeakPtrTest" << std::endl;
	//weak_ptr并没有->和*操作符，不可以直接通过weak_ptr使用对象
    //std::weak_ptr<Base> p_weak(new Base("123"));
    std::shared_ptr<Base> p_shared(new Base("123"));
	std::weak_ptr<Base> p_weak(p_shared);
	std::cout << "p_weak.count:" << p_weak.use_count() << std::endl;		//与共享对象的shared_ptr的个数
	std::cout << "p_shared count:" <<p_shared.use_count() << std::endl;			//p_weak.use_count()返回0时候为true，否则为false
	std::shared_ptr<Base> p_shared2 = p_weak.lock();						//返回weak对象所指向的shared_ptr
	std::cout << "p_shared count:" <<p_shared.use_count() << std::endl;			//p_weak.use_count()返回0时候为true，否则为false
	std::cout << "p_weak.expired:" <<p_weak.expired() << std::endl;			//p_weak.use_count()返回0时候为true，否则为false

}
int main()
{
//    AutoPtrTest();
    UniquePtrTest();
	SharedPtrTest();
    WeakPtrTest();
	return 0;
}
