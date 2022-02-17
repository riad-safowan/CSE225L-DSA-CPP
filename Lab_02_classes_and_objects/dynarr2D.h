#ifndef DYNARR2D_H_INCLUDED 
#define DYNARR2D_H_INCLUDED 
class dynArr2D
{
private:
    int** data;
    int rows;
    int cols;

public:
    dynArr2D();
    dynArr2D(int, int);
    ~dynArr2D();
    void setValue(int, int, int);
    int getValue(int, int);
    void allocate(int, int);
};
#endif