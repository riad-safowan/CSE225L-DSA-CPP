#ifndef GENERIC
#define GENERIC

template<class T>
class myClass
{
private:
    T value;
public:
    myClass();
    myClass(T);
    ~myClass();
    T getValue();
    void setValue(T);
};
#endif

