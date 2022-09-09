#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector> 
const int arr_size_x = 5;
const int arr_size_y = 5;
int  fact(int N)
{
    if (N < 0)
        return 0;
    if (N == 0)
        return 1;
    else
        return N * fact(N - 1);
}
class Matrix {
private:
    int row = 0;
    int col = 0;
    int * mass;
public:
    Matrix() {
        row = 0;
        col = 0;
        mass = NULL;
    }
    Matrix(int _row, int _col) {
        row = _row;
        col = _col;
        mass = new int[row * col];
    }
    void generate() {   
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col;j++) {
                mass[i * j] = fact(i + j);
            }
        }
    }
    int at(int i, int j) {
        return mass[i * j];
    }
    void SetAt(int i, int j) {
        int tmp;
        std::cout << "Введите желаемое значение"<<std::endl;
        std::cin >> tmp;
        mass[i * j] = tmp;
    }
    void generateFin(Matrix a) {
        for (int i = 0; i < row; i+=2) {
            for (int j = 0; j < col; j++) {
                mass[i] = a.mass[i * j];
            }
        }
    }
    void printMatrix() {
        std::cout << "Сгенерированная матрица: " << std::endl;
        for (int i = 0; i < row; i++) {
            std::cout << "\n";
            for (int j = 0; j < col; j++) {
                if (i == 0 && j == 0) {
                    std::cout << std::setw(8)<< mass[i * j];
                }
                else {
                    std::cout << std::setw(8) << mass[i * j];
                }
            }
        }
        
    }
};
class Vector {
private:
    std::vector<Matrix> listofmatrixes;
public:
    Vector() {
        this->listofmatrixes = listofmatrixes;
    }
    Vector(Matrix a) {
        this->listofmatrixes = listofmatrixes;
        this->listofmatrixes.push_back(a);
    }
    ~Vector() {}
};

int main()
{
    setlocale(LC_ALL, "Russian");
    Matrix z(arr_size_x, arr_size_y);
    z.generate();
    z.printMatrix();
    Vector a(z);
}
