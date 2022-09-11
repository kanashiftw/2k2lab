#include <iostream>
unsigned static int count = 0;
class Fraction
{
private:
    int x;//Числитель
    int y;//Знаменатель
public:
    Fraction(int tx = 0, int ty = 1)
    {
        if (ty == 0)
        {
            x = 0;
            y = 1;
            exit(0);
        }
        else
        {
            count++;
            x = tx;
            y = ty;
        }
    }
    ~Fraction() {}//Деструктор
    //МЕТОД ДЛЯ ВЫВОДА ДРОБИ
    void PrintAsFraction(Fraction xaxa)
    {
        std::cout << xaxa.x << "/" << xaxa.y << std::endl;
    }

    //МЕТОД ДЛЯ ВЫЧИСЛЕНИЯ НОД
    int gcd(Fraction z) {
        int a = z.x;
        int b = z.y;
        while (a && b) {
            if (a > b) a %= b;
            else b %= a;
            return a + b;
        }
    }
    //МЕТОД ДЛЯ СОКРАЩЕНИЯ ДРОБИ
    void reduce()
    {
        for (int i = x; i > 1;i--)
        {
            if (x % i == 0 && y % i == 0)
            {
                x = x / i;
                y = y / i;
            }
        }
    }
        //ОПЕРАТОР +
        Fraction operator + (Fraction a) {
            Fraction temp;
            temp.x = x * a.y + y * a.x;
            temp.y = y * a.y;
            return temp;
        }
        //ОПЕРАТОР -
        Fraction operator - (Fraction a) {
            Fraction temp;
            temp.x = x * a.y - y * a.x;
            temp.y = y * a.y;
            return temp;
        }
        //ОПЕРАТОР *
        Fraction operator * (Fraction a) {
            Fraction temp;
            temp.x = x * a.x;
            temp.y = y * a.y;
            return temp;
        }
        //ОПЕРАТОР /
        Fraction operator / (Fraction a) {
            Fraction temp;
            temp.x = x * a.y;
            temp.y = y * a.x;
            return temp;
        }
};

    int main()
    {
        setlocale(LC_ALL, "Russian");
        Fraction z(4, 6);
        Fraction l(6, 12);
        double decimal_fraction = 0.3435;
        decimal_fraction = round(decimal_fraction * 100) / 100;
        Fraction v(decimal_fraction * 100, 100);
        z.reduce();
        l.reduce();
        v.reduce();
        std::cout << "Дробь 1 в сокращенном виде: ";
        z.PrintAsFraction(z);
        std::cout << "Дробь 2 в сокращенном виде: ";
        l.PrintAsFraction(l);
        std::cout << "Дробь 3 в сокращенном виде: ";
        v.PrintAsFraction(v);
        std::cout << "Произведение дробей: ";
        z.PrintAsFraction(z * l);
        std::cout << "Частное дробей: ";
        z.PrintAsFraction(z / l);
        std::cout << "Сумма дробей: ";
        z.PrintAsFraction(z + l);
        std::cout << "Разность дробей: ";
        z.PrintAsFraction(z - l);
        std::cout<< "Количество объектов типа Fraction: "<<count;
        z.~Fraction();
        l.~Fraction();
    }

