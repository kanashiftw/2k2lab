#include <vector>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>

//Окей, мы просто играем в жизнь
//Часто не понимая роль
//Наши сюжеты — это белый лист
//Где мы вместе напишем свой
class Shop
{
private:
    std::string title;//Название магазина
    std::string address;//Адрес магазина
    int year;//Год основания
    int number;//Номер телефона
    int networth;//Суммарная прибыль
public:
    //КОНСТРУКТОР
    Shop(std::string _title = "Название не указано",
        std::string _address = "Адрес не указан",
        int _year = 000, 
        int _number = 000, 
        int _networth = 000) {
        title = _title;
        address = _address;
        year = _year;
        number = _number;
        networth = _networth;
    }
    //СЕТТЕР
    void setter() {

            std::cout << "Введите название: " << std::endl;
            std::string tmpx;
            std::cin >> tmpx;
            title = tmpx;

            std::cout << "Введите адрес: " << std::endl;
            std::string tmpk;
            std::cin >> tmpk;
            title = tmpk; 

            std::cout << "Введите год: " << std::endl;
            int tmpy;
            std::cin >> tmpy;
            year = tmpy;
 
            std::cout << "Введите номер: " << std::endl;
            int tmpz;
            std::cin >> tmpz;
            number = tmpz;
     
            std::cout << "Введите заработок: " << std::endl;
            int tmpv;
            std::cin >> tmpv;
            networth = tmpv;
        
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
    //ЧТЕНИЕ ОБЪЕКТА ИЗ ФАЙЛА
    void deseriallize(const std::string filename) {
        std::ifstream fin;
        fin.open(filename);
        fin >> title >> year >> number >> networth;
        fin.close();
    }
};
int main()
{
    setlocale(LC_ALL, "Russian");
    std::vector<Shop> shop;
    std::cout << "Пример элемента класса Shop: ";
    Shop example("Пятерочка","Арбат  24", 1998, 88005555505, 178000000000);
    shop.push_back(example);
    example.displayShop();
    example.seriallize("file.txt");
    Shop first;
    first.setter();
    shop.push_back(first);
    std::cout << "Вы ввели: "<<std::endl;
    first.displayShop();
    Shop second;
    second.setter();
    shop.push_back(second);
    std::cout << "Вы ввели: " << std::endl;
    second.displayShop();
}
