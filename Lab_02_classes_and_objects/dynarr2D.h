#ifndef DYNARR2D_H_INCLUDED 
#define DYNARR2D_H_INCLUDED 

template<class T>
class dynArr2D
{
private:
    T** data;
    int rows;
    int cols;

public:
    dynArr2D();
    dynArr2D(int, int);
    ~dynArr2D();
    void setValue(int, int, T);
    T getValue(int, int);
    void allocate(int, int);
};
#endif