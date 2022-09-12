#include <vector>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <Windows.h>
//Окей, мы просто играем в жизнь
//Часто не понимая роль
//Наши сюжеты — это белый лист
//Где мы вместе напишем свой

//Класс 
class Shop
{
private:
    std::string title;//Название магазина
    std::string address;//Адрес магазина
    int year;//Год основания
    long long number;//Номер телефона
    long long  networth;//Суммарная прибыль
public:
    //КОНСТРУКТОР
    Shop(std::string _title = "Название не указано",
        std::string _address = "Адрес не указан",
       int _year = 000,
        long long  _number = 000,
        long long  _networth = 000) {
        title = _title;
        address = _address;
        year = _year;
        number = _number;
        networth = _networth;
    }
    ~Shop(){} //Деструктор
    //СЕТТЕР
    void setter() {
        std::cout << "Введите название: " << std::endl;
        if (char(std::cin.peek()) == '\n')//Очистка буффера ввода
            std::cin.ignore();

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
        std::getline(std::cin, title);

        std::cout << "Введите адрес: " << std::endl;
        std::getline(std::cin, address);

        std::cout << "Введите год: " << std::endl;
        std::cin >> year;


        std::cout << "Введите номер: " << std::endl;
        std::cin >> number;

        std::cout << "Введите заработок: " << std::endl;
        std::cin >> networth;

    }


    
    //МЕТОД ДЛЯ ОТОБРАЖЕНИЯ МАГАЗИНА
    void displayShop() {
        std::cout << title << "\n"
            <<"Адрес: "<<address<<"\n"
            << year << " года основания\n" 
            << "Номер телефона: " << number << "\n"
            << "Суммарная прибыль: " << networth<<" руб."<<"\n"<<std::endl;
    }
    //ЗАПИСЬ ОБЪЕКТА В ФАЙЛ
    void seriallize(const std::string filename) {
        std::ofstream fout;
        fout.open(filename);
            fout <<title<<"\n"<< year << "\n"<<number <<"\n"<< networth;
            fout.close();
    }
    std::string getTitle(Shop a) {
        return a.title;
    }
    //ЧТЕНИЕ ОБЪЕКТА ИЗ ФАЙЛА
    void deseriallize(const std::string filename) {
        std::ifstream fin;
        fin.open(filename);
        fin >> title >> year >> number >> networth;
        fin.close();
    }
};
//Класс доходов
class Income {
private:
    Shop ss;
    int* array;
public:
    Income(Shop _ss, int* _array) {
        ss = _ss;
        array = new int[3];
        for (int i = 0; i < 3;i++) {
            array[i] = _array[i];
        }
    }
    ~Income(){}//Деструктор
    //Расчет общей прибыли
    int allIncome() {
        for (int i = 1; i < 3; i++) {
            array[0] += array[i];
        }
        return array[0];
    }
    //Расчет среднего прироста
    int midIncome() {
        int midinc = ((array[2] - array[1]) + (array[1] - array[0]))/2;
        return midinc;
    }
    //Сортировка по общей прибыли
    void sortbyAll(Income a, Income b, Income c) {
        std::cout << "\nСортировка по общему доходу:\n"<<std::endl;
        if (compareInc(a, b) && compareInc(a, c)) {
            if (compareInc(b, c)) {
                printb(a, b, c);
            }
            else printb(a, c, b);
        }
        if (compareInc(b, c) && compareInc(b, a)) {
            if (compareInc(a, c)) {
                printb(b, a, c);
            }
            else printb(b, c, a);
        }
        if (compareInc(c, b) && compareInc(c, a)) {
            if (compareInc(a, b)) {
                printb(c, a, b);
            }
            else printb(c, b, a);
        }
        }  
    //Сортировка по средней прибыли
    void sortbyMid(Income a, Income b, Income c) {
        std::cout << "\nСортировка по приросту среднего дохода:\n" << std::endl;
        if (compareMidInc(a, b) && compareMidInc(a, c)) {
            if (compareMidInc(b, c)) {
                printa(a, b, c);
            }
            else printa(a, c, b);
        }
        if (compareMidInc(b, c) && compareMidInc(b, a)) {
            if (compareMidInc(a, c)) {
                printa(b, a, c);
            }
            else printa(b, c, a);
        }
        if (compareMidInc(c, b) && compareMidInc(c, a)) {
            if (compareMidInc(a, b)) {
                printa(c, a, b);
            }
            else printa(c, b, a);
        }
    }
    //Метод сравнения общей прибыли
    bool compareInc(Income a, Income b) {
        if (a.allIncome() > b.allIncome()) return true;
        else return false;
    }
    //Метод сравнения средней прибыли
    bool compareMidInc(Income a, Income b) {
        if (a.midIncome() > b.midIncome()) return true;
        else return false;
    }
    //Вывод списка, сортированного по среднему приросту 
    void printa(Income a, Income b, Income c) {
        std::cout << a.ss.getTitle(a.ss) << " - " << a.midIncome() << std::endl;
        std::cout << b.ss.getTitle(b.ss) << " - " << b.midIncome() << std::endl;
        std::cout << c.ss.getTitle(c.ss) << " - " << c.midIncome() << std::endl;
    }
    //Вывод списка, сортированного по общему приросту
    void printb(Income a, Income b, Income c) {
        std::cout << a.ss.getTitle(a.ss) << " - " << a.allIncome()<<std::endl;
        std::cout << b.ss.getTitle(b.ss) << " - " << b.allIncome()<<std::endl;
        std::cout << c.ss.getTitle(c.ss) << " - " << c.allIncome()<<std::endl;
    }
};
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::vector<Shop> shop;
    std::cout << "Пример элемента класса Shop: ";
    Shop example("Пятерочка", "Арбат  24", 1998, 88005555505, 178000000000);
    shop.push_back(example);
    example.displayShop();
    example.seriallize("file.txt");
    Shop first;
    first.setter();
    shop.push_back(first);
    first.seriallize("file.txt");
    std::cout << "\nВы ввели: " << std::endl;
    first.displayShop();
    std::cout << "\n";
    Shop second;
    second.setter();
    shop.push_back(second);
    second.seriallize("file.txt");
    second.deseriallize("file.txt");
    std::cout << "\nВы ввели: " << std::endl;
    second.displayShop();
    int mounth1[3] = {23000, 25000, 26005};
    int mounth2[3] = { 92000, 108000, 97000 };
    int mounth3[3] = { 32000, 31000, 20000 };  
    Income a(example, mounth1);
    Income b(first, mounth2);
    Income c(second, mounth3);
    a.sortbyMid(a, b, c);
    a.sortbyAll(a, b, c);
    example.~Shop();
    first.~Shop();
    second.~Shop();
    a.~Income();
    b.~Income();
    c.~Income();
}

