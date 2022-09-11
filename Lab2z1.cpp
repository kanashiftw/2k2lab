#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector> 
//Метод вычисления факториала
int  fact(int N)
{
    if (N < 0) return -1;
    if (N == 0) return 1;   
    else return N * fact(N - 1);
}
//Класс матрикс
class Matrix{
private:
    int row = 0;
    int col = 0;
    int** mass;
    //Метод инициализации матрицы
    void init()
    {
        mass = new int* [col];
        for (int i = 0; i < col; i++)
        {
            mass[i] = new int[row];
        }
    }
    //Метод заполнения матрицы
    void fill()
    {
        for (int i = 0; i < col; i++)
        {
            for (int j = 0; j < row; j++)
            {
                mass[i][j] = fact(i+j);
            }
        }
    }
public:
    //Конструктор без параметров
    Matrix() {
        row = 0;
        col = 0;
        mass = NULL;
    }
    //Матрица
    Matrix(int _col) {
        row = 1;
        col = _col;
        init();
        fill();
    }
    //Двумерная матрица
    Matrix(int _row, int _col) {
        row = _row;
        col = _col;
        init();
        fill();
    }
    //Метод поиска значения по индексу
    int at(int i, int j) {
        return mass[i][j];
    }
    //Метод замены значения по индексу
    void SetAt(int i, int j) {
        int tmp;
        std::cout << "Введите желаемое значение"<<std::endl;
        std::cin >> tmp;
        mass[i][j] = tmp;
    }
    //Генерация матрицы
    Matrix generateFin(Matrix a) {
        Matrix y(15);
        int k = 0;
            for (int i = 0; i < a.row; i += 2) {
                for (int j = 0; j < a.col; j++) {
                    y.mass[k][0] = a.mass[i][ j];
                    k++;
                }
            }
        return y;
    }
    //Метод вывода матрицы в консоль
    void printMatrix() {
        if (row <= 1) { //Матрица с одной строкой
            std::cout << "Сгенерированная матрица: " << std::endl<<std::endl;
            for (int i = 0; i < col; i++) {
                    std::cout << std::setw(8) << mass[i][0];
                    if (i == 4 || i == 9 || i == 14) {
                        std::cout<<"\n";
                }
            }
        }
        else { //Матрица многа строк
            std::cout << "Сгенерированная матрица: " << std::endl;
            for (int i = 0; i < row; i++) {
                std::cout << "\n";
                for (int j = 0; j < col; j++) {
                    std::cout << std::setw(8) << mass[i][j];
                }
            }
            std::cout << "\n";
        }
    }
    //Деструктор класса
    ~Matrix() {}
};
//класс Вектор
class Vector {
private:
    std::vector<Matrix> listofmatrixes;
public:
    //Без параметров
    Vector() {
        this->listofmatrixes = listofmatrixes;
    }
    //Не без параметров
    Vector(Matrix a) {
        this->listofmatrixes = listofmatrixes;
        this->listofmatrixes.push_back(a);
    }
 
    //Последнее значение из вектора
    void Printv(Vector z) {
        for (auto i : listofmatrixes)
            i.printMatrix();
    }
    //Оператор инициализации
    int& operator [] (int a);
    //Деструктор класса
    ~Vector(){}
};
int main()
{
    setlocale(LC_ALL, "Russian");
    Matrix z(5, 5);
    z.printMatrix();
    Vector a(z);
    Matrix o=z.generateFin(z);
    o.printMatrix();
    std::cout << "Содержимое вектора: "<<std::endl;
    a.Printv(a);
    a.~Vector();
    z.~Matrix();
}
