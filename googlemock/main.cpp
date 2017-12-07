#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"


class User {
public:
    User() {};
    ~User() {};
public:
    // 登录
    virtual bool Login(const std::string& username, const std::string& password) = 0;
    // 支付
    virtual bool Pay(int money) = 0;
    // 是否登录
    virtual bool Online() = 0;
};


class Biz {  
public:  
    void SetUser(User* user) {  
        _user = user;  
    }  

    std::string pay(const std::string& username, const std::string& password, int money) {  
        std::string ret;  
        if (!_user) {  
            ret = "pointer is null.";  
            return ret;  
        }  

        if (!_user->Online()) {  
            ret = "logout status.";  
            // 尚未登录，要求登录  
            if (!_user->Login(username, password)) {  
                // 登录失败  
                ret += "login error.";  
                return ret;  
            } else {  
                // 登录成功  
                ret += "login success.";  
            }  
        } else {  
            // 已登录  
            ret = "login.status";  
        }  

        if (!_user->Pay(money)) {  
            ret += "pay error.";  
        } else {  
            ret += "pay success.";  
        }  

        return ret;  
    }  

private:  
    User* _user;  
}; 

class TestUser : public User {
public:
    MOCK_METHOD2(Login, bool(const std::string&, const std::string&));
    MOCK_METHOD1(Pay, bool(int));
    MOCK_METHOD0(Online, bool());
};

//   EXPECT_CALL(mock_object, Method(argument-matchers))    //mock_object:所要调用的对象;Method:指要调用的方法
//       .With(multi-argument-matchers)                     //多个参数的匹配方式指定
//       .Times(cardinality)                                //可以被执行多少次，超过这个次数之后按照默认值返回
//       .InSequence(sequences)                             //指定函数执行的顺序
//       .After(expectations)                               //指定某个方法只能在另一个方法之后执行
//       .WillOnce(action)                                  //执行一次方法时，按照指定action返回，之后用默认值返回
//       .WillRepeatedly(action)                            //执行这个方法一直得到这个结果
//       .RetiresOnSaturation();
//
// where all clauses are optional, and .InSequence()/.After()/
// .WillOnce() can appear any number of times.


int main()
{
    TestUser test_user;
//    EXPECT_CALL(test_user, Online()).WillOnce(testing::Return(true));  
    EXPECT_CALL(test_user, Online()).WillOnce(testing::Return(false)).WillRepeatedly(testing::Return(true));
    //任何用户返回false
//    EXPECT_CALL(test_user, Login(testing::_,testing::_)).WillRepeatedly(testing::Return(false));
    //admin用户返回false
//    EXPECT_CALL(test_user, Login("admin",testing::_)).WillRepeatedly(testing::Return(false));
    //除了admin用户,其他都返回true
    EXPECT_CALL(test_user, Login(testing::StrNe("admin"),testing::_)).WillRepeatedly(testing::Return(true));
    //用户支付总是返回true
    EXPECT_CALL(test_user, Pay(testing::_)).WillRepeatedly(testing::Return(true));
    //非admin用户登录成功之后，只能成功支付两次，之后的支付都失败
    EXPECT_CALL(test_user, Pay(testing::_)).Times(3).WillOnce(testing::Return(true)).WillOnce(testing::Return(true)).WillRepeatedly(testing::Return(false));

    Biz biz;
    biz.SetUser(&test_user);
    std::string admin_ret;
    //std::string admin_ret = biz.pay("user","",1);
    //std::cout << admin_ret << std::endl;
    //admin_ret = biz.pay("user","",1);
    //std::cout << admin_ret << std::endl;
    admin_ret = biz.pay("usr","",1);
    std::cout << admin_ret << std::endl;
    admin_ret = biz.pay("usr","",1);
    std::cout << admin_ret << std::endl;
    admin_ret = biz.pay("usr","",1);
    std::cout << admin_ret << std::endl;
    return 0;
}
