#ifndef SINGLETON_H
#define SINGLETON_H

template < class T >
class Singleton
{
public:
    static bool isBuilt() {
        return (_instance != 0);
    }
    static T * instance(){
        if ( ! isBuilt() )
          _instance = new T();
        return _instance;
    }

protected:
    static T* _instance;

    Singleton(){}
    ~Singleton(){}
};

template<typename T>
T* Singleton<T>::_instance = 0;

#endif // SINGLETON_H
