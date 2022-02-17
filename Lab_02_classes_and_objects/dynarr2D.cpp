#include "dynarr2D.h" 
#include <iostream> 
using namespace std;

dynArr2D::dynArr2D()
{
    data = NULL;
    rows = 0;
    cols = 0;
}
dynArr2D::dynArr2D(int r, int c)
{
    data = new int* [r];
    for (int i = 0; i < r; i++)
    {
        data[i] = new int[c];
    }
    rows = r;
    cols = c;
}

dynArr2D::~dynArr2D()
{
    for (int i = 0; i < rows; i++)
    {
        delete[] data[i];
    }
    delete[] data;
}
int dynArr2D::getValue(int r, int c)
{
    return data[r][c];
}
void dynArr2D::setValue(int r, int c, int value)
{
    data[r][c] = value;
}

void dynArr2D::allocate(int r, int c)
{
    if (r >= rows && c >= cols)
    {
        int** temp = data;
        int oldRows = rows;
        int oldCols = cols;
        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }
        delete[] data;
        data = new int* [r];
        for (int i = 0; i < r; i++)
        {
            data[i] = new int[c];
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