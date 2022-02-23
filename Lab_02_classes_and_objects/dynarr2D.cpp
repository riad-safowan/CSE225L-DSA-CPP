#include <iostream> 
#include "dynarr2D.h" 
using namespace std;

template<class T>
dynArr2D<T>::dynArr2D()
{
    data = NULL;
    rows = 0;
    cols = 0;
}
template<class T>
dynArr2D<T>::dynArr2D(int r, int c)
{
    data = new T * [r];
    for (int i = 0; i < r; i++)
    {
        data[i] = new T[c];
    }
    rows = r;
    cols = c;
}

template<class T>
dynArr2D<T>::~dynArr2D()
{
    for (int i = 0; i < rows; i++)
    {
        delete[] data[i];
    }
    delete[] data;
}
template<class T>
T dynArr2D<T>::getValue(int r, int c)
{
    return data[r][c];
}
template<class T>
void dynArr2D<T>::setValue(int r, int c, T value)
{
    data[r][c] = value;
}

template<class T>
void dynArr2D<T>::allocate(int r, int c)
{
    if (r >= rows && c >= cols)
    {
        T** temp = data;
        int oldRows = rows;
        int oldCols = cols;
        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }
        delete[] data;
        data = new T* [r];
        for (int i = 0; i < r; i++)
        {
            data[i] = new T[c];
        }

        for (int i = 0; i < oldRows; i++)
        {
            for (int j = 0; j < oldCols; j++)
            {
                data[i][j] = temp[i][j];
            }
        }

        rows = r;
        cols = c;
        for (int i = 0; i < oldRows; i++)
        {
            delete[] temp[i];
        }
        delete[] temp;
    }
}