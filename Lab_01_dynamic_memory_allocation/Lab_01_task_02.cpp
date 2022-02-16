#include<iostream>
using namespace std;

/*Task  2:  Using the new operator, allocate a two dimensional character array. Again the number of rows and columns
are going to be provided by the user as input. All of the rows are the same size. Take character strings as input from
the user and then print the strings. Finally de-allocate the array using the delete operator. */

int main(int argc, char const* argv[])
{
    int rows, cols;
    cout << "Enter the number of ROWS : ";
    cin >> rows;
    cout << "Enter the number of COLS : ";
    cin >> cols;

    char** array = new char* [rows];
    for (int i = 0; i < rows; i++)
    {
        array[i] = new char[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter value for element " << i << " " << j << " : ";
            cin >> *(*(array + i) + j);
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
        {
            cout << *(*(array + i) + j);
        }
        cout << endl;
    }

    delete[] array;
    return 0;
}

