#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector> 
//Метод вычисления факториала
int  fact(int N)
{
    if (N < 0) return 0;   
    if (N == 0) return 1;   
    else return N * fact(N - 1);
}
//Класс матрикс
class Matrix {
private:
    int row = 0;
    int col = 0;
    int * mass;
public:
    //Конструктор без параметров
    Matrix() {
        row = 0;
        col = 0;
        mass = NULL;
    }
    //Конструктор лего
    Matrix(int _col) {
        col = _col;
        mass = new int[col];
    }
    //Передаю привет Михаилу Милюшникову
    Matrix(int _row, int _col) {
        row = _row;
        col = _col;
        mass = new int[row * col];
    }
    //Хочу пельменей
    void generate() {   
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col;j++) {
                mass[i * j] = fact(i + j);
            }
        }
    }
    //А они меня нет АхаХХАХаХАХАХ=)
    int at(int i, int j) {
        return mass[i * j];
    }
    //Ладно, следующий комментарий будет нормальным
    void SetAt(int i, int j) {
        int tmp;
        std::cout << "Введите желаемое значение"<<std::endl;
        std::cin >> tmp;
        mass[i * j] = tmp;
    }
    //Генерация матрицы
    Matrix generateFin(Matrix a) {
        Matrix y(15);
        int k = 0;
            for (int i = 0; i < a.row; i += 2) {
                for (int j = 0; j < a.col; j++) {
                    y.mass[k] = a.mass[i * j];     
                    k++;
                }
            }
        return y;
    }
    //Выводы напрашиваются сами собой
    void printMatrix() {
        if (row <= 1) {
            std::cout << "Сгенерированная матрица: " << std::endl<<std::endl;
            for (int i = 0; i < col; i++) {
                    std::cout << std::setw(8) << mass[i];
                    if (i == 4 || i == 9 || i == 14) {
                        std::cout<<"\n";
                }
            }
        }
        //Ельсе
        else {
            std::cout << "Сгенерированная матрица: " << std::endl;
            for (int i = 0; i < row; i++) {
                std::cout << "\n";
                for (int j = 0; j < col; j++) {
                    std::cout << std::setw(8) << mass[i * j];
                }
            }
            std::cout << "\n";
        }
    }
};
//класс Виктор, а почему не Сашок=)
class Vector {
private:
    std::vector<Matrix> listofmatrixes;
public:
    //Виктор на легке
    Vector() {
        this->listofmatrixes = listofmatrixes;
    }
    //Виктор приблатненный сегодня
    Vector(Matrix a) {
        this->listofmatrixes = listofmatrixes;
        this->listofmatrixes.push_back(a);
    }
    //инт оператор квадратный
    int& operator [] (int a);
    ~Vector() {}
};
//главный(Я)
int main()
{
    setlocale(LC_ALL, "Russian");
    Matrix z(5, 5);
    z.generate();
    z.printMatrix();
    Vector a(z);
    Matrix o=z.generateFin(z);
    o.printMatrix();
}
