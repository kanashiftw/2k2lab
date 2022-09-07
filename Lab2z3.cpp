#include <vector>
#include <iomanip>
#include <iostream>
#include <sstream>

//Окей, мы просто играем в жизнь
//Часто не понимая роль
//Наши сюжеты — это белый лист
//Где мы вместе напишем свой
class Shop
{
private:
    std::string title;//Название магазина
    int year;//Год основания
    int number;//Номер телефона
    int networth;//Суммарная прибыль
public:
    //КОНСТРУКТОР
    Shop(std::string _title = "Название не указано", 
        int _year = 000, 
        int _number = 000, 
        int _networth = 000) {
        title = _title;
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
            << year << " года основания\n" 
            << "Номер телефона: " << number << "\n"
            << "Суммарная прибыль: " << networth<<" руб."<<"\n"<<std::endl;
    }
};
int main()
{
    setlocale(LC_ALL, "Russian");
    std::vector<Shop> shop;
    Shop first("Пятерочка", 2003, +720132103, 28000000);
    first.displayShop();
    Shop a;
    a.setter();
    a.displayShop();
    shop.push_back(first);
    shop.push_back(a);
}

