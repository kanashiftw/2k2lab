#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector> 
const int arr_size_x = 5;
const int arr_size_y = 5;
int ary[arr_size_x][arr_size_y];
std::vector  <int>  vctrx(arr_size_x);
std::vector < std::vector <int> > vctry(arr_size_x, std::vector <int>(arr_size_y));
int  fact(int N)
{
    if (N < 0)
        return 0;
    if (N == 0)
        return 1;
    else
        return N * fact(N - 1);
}
class Vector{
public:
    Vector(int array[arr_size_x]) {
        for (int i = 0; i < arr_size_x;i++) {
            vctrx[i] = array[i];
        }
    }
    Vector(int array[arr_size_x][arr_size_y]) {
        for (int i = 0; i < arr_size_x; i++)
            for (int j = 0; j < arr_size_y; j++)
            {
                vctry[i][j] = fact(i + j);
            }
    }
    void printVector() {
        std::cout << "Заполненный массив:\n";
        for (int i = 0; i < arr_size_x; i++) {
            std::cout << "\n";
            for (int k = 0; k < arr_size_y; k++) {
                if (k == 0) {
                    std::cout << vctry[i][k];
                }
                else {
                    std::cout << std::setw(8) << vctry[i][k];
                }
            }
        }
    }
    ~Vector(){}
};
/*class Matrix {
private:
    int row = 0;
    int col = 0;
    int** mass;
public:
    Matrix(){
        this->row = 0;
        this->col = 0;
        this->mass = NULL;
    }
    Matrix(int _row, int _col) {
        for (int i = 0; i < _row; i++) {
            for (int j = 0; j < _col; j++) {
                mass[i][j] = fact(i + j);
            }
        }
    }
};*/

void printnewArray(int array[arr_size_x][arr_size_y]) {
    std::cout << "Измененный массив:\n" << std::endl;
    int solo[(arr_size_x * arr_size_y) - (2 * arr_size_x)];
    for (unsigned int i = 0; i < arr_size_x; i += 2) {
        for (unsigned int k = 0; k < arr_size_y; k++) {
            if (i == 0 && k == 0) {
                solo[i] = ary[i][k];
                std::cout << solo[i];
            }
            else {
                solo[i] = ary[i][k];
                std::cout << std::setw(8) << solo[i];
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    Vector a(ary);
    a.printVector();
    a.~Vector();
}

