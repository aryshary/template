#include <iostream>
#include "Windows.h"

using namespace std;

//template<class T>
//float ave(T array[], size_t size)
//{
//    float arraySum = 0;
//    for (int i = 0; i < size; i++) {
//        arraySum += array[i];
//    }
//    return arraySum / size;
//}

template<class T>
class Matrix
{
private:
    T** array;
    int rows;
    int cols;

public:
    Matrix(int row, int col) : rows{ row }, cols(col) {
        array = new T * [rows];
        for (int i = 0; i < rows; i++) {
            array[i] = new T[cols];
        }
    }

    void randArray() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                array[i][j] = rand() % 9;
            }
        }
    }

    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << array[i][j] << ' ';
            }
            cout << endl;
        }
    }

    int maxElement() {
        T maxElement = array[0][0];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (array[i][j] > maxElement) maxElement = array[i][j];
            }
        }
        return maxElement;
    }

    int minElement() {
        T minElement = array[0][0];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (array[i][j] < minElement) minElement = array[i][j];
            }
        }
        return minElement;
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] array[i];
        }
        delete array;
    }
};



int main()
{
    srand(time(0));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Matrix<int> matrix(5, 6);
    matrix.randArray();
    matrix.print();
    cout << "max - " << matrix.maxElement() << "; min - " << matrix.minElement() << endl;



    /*const size_t intSize = 3;
    int intArray[intSize]{ 4, 5, 5 };
    cout << ave<int>(intArray, intSize) << endl;

    const size_t floatSize = 3;
    float floatArray[floatSize]{ 4.5, 5.3, 5.1 };
    cout << ave<float>(floatArray, floatSize) << endl;*/

    return 0;
}