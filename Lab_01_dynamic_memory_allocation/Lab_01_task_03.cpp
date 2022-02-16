#include<iostream>
using namespace std;

/*Task 3: Using the new operator, allocate a two dimensional integer array. The number of rows and columns are going
to be provided by the user as input. However, in this task, all of the rows are not the same size (the array is uneven).
The user will specify how many elements the individual rows will have. Assign values to the array elements by taking
user inputs and then print the values. Finally de-allocate the array using the delete operator.  */

int main(int argc, char const* argv[])
{
    int rows;
    cout << "Enter the number of ROWS : ";
    cin >> rows;


    int** array = new int* [rows];
    int sizes[rows];
    for (int i = 0; i < rows; i++)
    {
        int cols;
        cout << "Enter the number of COLS for Row " << i << ": ";
        cin >> cols;
        array[i] = new int[cols];
        sizes[i] = cols;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < sizes[i]; j++)
        {
            cout << "Enter value for element " << i << " " << j << " : ";
            cin >> *(*(array + i) + j);
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < sizes[i]; j++)
        {
            cout << *(*(array + i) + j)<<" ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++)
    {
        delete[] array[i];
    }

    return 0;
}

