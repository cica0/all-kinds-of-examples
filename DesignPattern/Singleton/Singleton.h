#ifndef _SINGLETON_H_
#define _SINGLETON_H_
#include <boost/noncopyable.hpp>
#include <memory>

template<typename T>
class Singleton : boost::noncopyable {
public:
    static T* getInstance() {
        if(instance_ == NULL)
            instance_ = new T();
        return instance_; 
    }

private:
    Singleton(){};
    ~Singleton(){};
    static T* instance_;
    class SingletonDelete {
    public:
        ~SingletonDelete() {
            if (Singleton::instance_)
                delete Singleton::instance_;
        }
    };
    static SingletonDelete singledelete_;
};

template<typename T>
T* Singleton<T>::instance_ = NULL;

#endif   // #define _SINGLETON_H_
