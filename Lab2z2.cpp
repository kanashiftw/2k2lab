#include <iostream>
int middle(int a, int b) {
    int tmp;
    tmp = a * b;
    while (a != 0 && b != 0) {
        (a > b) ? a = a % b : b = b % a;
    }
    return tmp / (a + b);
}

class Fraction
{
private:
    int x;//Числитель
    int y;//Знаменатель
public:
    Fraction(int tx, int ty)
    {
        if (ty == 0)
        {
            x = 0;
            y = 1;
            exit(0);
        }
        else
        {
            x = tx;
            y = ty;
        }
    }
    //МЕТОД ДЛЯ ВЫВОДА ДРОБИ
    void PrintAsFraction(Fraction xaxa)
    {
        std::cout << xaxa.x << "/" << xaxa.y << std::endl;
    }

    //МЕТОД ДЛЯ ВЫЧИСЛЕНИЯ НОД
    float gcd(Fraction z) {
        int a = z.x;
        int b = z.y;
        while (a && b) {
            if (a > b) a %= b;
            else b %= a;
            return a + b;
        }
    }
    //МЕТОД ДЛЯ СОКРАЩЕНИЯ ДРОБИ
    void reduce(Fraction z) {
        int nod = gcd(z);
        z.x /= nod;
        z.y /= nod;
    }
    //МЕТОД ДЛЯ РАСЧЕТА ПРОИЗВЕДЕНИЯ
    Fraction product(Fraction a, Fraction b) {
        a.x *= b.x;
        a.y *= b.y;
        a.reduce(a);
        return a;
    }
    //МЕТОД ДЛЯ РАСЧЕТА ЧАСТНОГО
    Fraction quot(Fraction a, Fraction b) {
        a.x *= b.y;
        a.y *= b.x;
        a.reduce(a);
        return a;
    }
    //МЕТОД ДЛЯ РАСЧЕТА СУММЫ
    Fraction sum(Fraction a, Fraction b) {
        int tmp = a.y;
        Fraction c (a.y, b.y);
        a.y = middle(a.y, b.y);
        if (tmp != a.y) {
            if (tmp > a.y) {
                a.x = a.x / (tmp / a.y);
            }
            else {
                a.x = a.x * (a.y/tmp);
            }
        }
            a.x += b.x;
            a.reduce(a);
        return a;
    }
    //МЕТОД ДЛЯ РАСЧЕТА РАЗНОСТИ
    Fraction diff(Fraction a, Fraction b) {
        int tmp = a.y;
        Fraction c(a.y, b.y);
        a.y = middle(a.y, b.y);
        if (tmp != a.y) {
            if (tmp > a.y) {
                a.x = a.x / (tmp / a.y);
            }
            else {
                a.x = a.x * (a.y / tmp);
            }
        }
            a.x -= b.x;
        a.reduce(a);
        return a;
    }
};

    int main()
    {
        setlocale(LC_ALL, "Russian");
        Fraction z(4 , 6);
        Fraction l(6, 12);
        double decimal_fraction = 0.3435;
        decimal_fraction = round(decimal_fraction * 100) / 100;
        Fraction v(decimal_fraction*100, 100);
        z.reduce(z);
        l.reduce(l);
        v.reduce(v);
        std::cout << "Дробь 1 в сокращенном виде: ";
        z.PrintAsFraction(z);
        std::cout << "Дробь 2 в сокращенном виде: ";
        l.PrintAsFraction(l);
        std::cout << "Дробь 3 в сокращенном виде: ";
        v.PrintAsFraction(v);
        std::cout << "Произведение дробей: ";
        z.PrintAsFraction(z.product(z,l));
        std::cout << "Частное дробей: ";
        z.PrintAsFraction(z.quot(z,l));
        std::cout << "Сумма дробей: ";
        z.PrintAsFraction(z.sum(z, l));
        std::cout << "Разность дробей: ";
        z.PrintAsFraction(z.diff(z, l));
        std::cout << z.gcd(l);
    }

