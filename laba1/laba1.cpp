#include <iostream>
#include <string>
#include <windows.h>

char bufRus[256];
char* Rus(const char* text) {
    CharToOemA(text, bufRus);
    return bufRus;
}

using namespace std;

class HR {
public:
    HR(string n, int w, int h, int p, double t) {
        title = n;
        workers = w;
        hours = h;
        price = p;
        tax = t;
        if (w < 0)
        {
            workers = 0;
        }
        else
        {
            workers = w;
        }
        if (h < 0)
        {
            hours = 0;
        }
        else
        {
            hours = h;
        }
        if (p < 0)
        {
            price = 0;
        }
        else
        {
            price = p;
        }
        if (t < 0)
        {
            tax = 0;
        }
        else {
            tax = t;
        }
    }

    double get_total_tax_paiment() {
        return workers * hours * price * tax/100;
    }

    string get_name()
    {
        return title;
    }
    void set_workers(int w) {
        workers = w;
    }
    void set_hourss(int h) {
        hours = h;
    }
    void set_price(int p) {
        price = p;
    }
    void set_tax(double t) {
        tax = t;
    }
    void set_name(string n)
    {
        title = n;
    }

private:

    string title;
    int workers;
    int hours;
    int price;
    double tax;
};

int main() {
    HR Yandex("Yandex", 1000, 200, 240, 20);
    printf(Rus("Для компании %s выплата: %f"), Yandex.get_name().c_str(), Yandex.get_total_tax_paiment());
    return 0;
}