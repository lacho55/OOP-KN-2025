#### Наследяването е един от 4-те принципа на ООП-то (досега сме учили за Енкапсулация и Абстракция).

### 1. Проблем
Нека да имаме 3 класа, които описват коли с член данни марка на колата, колко струва и колко километри е изминала, тип на колата (автобус, лека кола и джип).Също нека всеки клас да има метод за извеждане на информацията на конзолата и метод, който нулира километрите. Също нека леката кола да има метод за пускане на нитро, който другите две коли нямат. Решението би било да си напишем 3 класа, всеки с тези член данни и методи, с разлика, че леката кола ще има специален метод за нитро и всеки би трябвало да има фиксирана член данна за типа си. Но ако сте правили нещо подобно ще знаете, че това е едно копи пействане на един и същи клас. 

### 2. Решение чрез наследяване
Чрез силата на наследяването можем да си направим клас Vehicle с член данни марка на превозното средство, колко струва и какви километри са изминати с него. В този клас можем също да обобщим метод за принитране на тези данни и за нулиране на километража. След това може да си правим 3-те класа Bus, Car, Jeep, който ще наследят тези обобщителните член данни и няма да има нужда да ги пишем във всеки клас.

``` c++
#include <iostream>
#include <cstring>

class Vehicle {
protected: // protected дава достъп на наследници да достъпват private член данните
    char brand[10];
    double price;
    double kmPassed;
public:
    Vehicle() {
        strcpy(brand,"Golf");
        price = 0;
        kmPassed = 0;
    }
    Vehicle(const char* _brand,double _price, double _kmPassed) {
        strcpy(brand, _brand);
        price = _price;
        kmPassed = _kmPassed; // имаме достъп до тези данни без да са в клас Car
    } 
    void nullifyKm() {
        kmPassed = 0;
    }
    void printVehicleInfo() {
        std::cout << brand << std::endl;
        std::cout << price << std::endl;
        std::cout << kmPassed << std::endl << std::endl;
    }
};
class Car : public Vehicle { // така Car наследява класa Vehicle
private:
    const int carType = 1; 
    // технически можем и тази член данна да я сложим в Vehicle, но за примера показваме, че не всички член може да се наследяват, зависи от нивото на обобщението.  
public:
    // можем да извикаме дефолтния конструктор на Vehicle като :Vehicle ще се изпълни 
    // ПРЕДИ тялото на дефолтния конструктор на Car
    Car() : Vehicle() {} 
    // по същия начин можем и за конструктора с параметри.
    Car(const char* _brand,double _price, double _kmPassed) : Vehicle(_brand,_price,_kmPassed) {}
    void printCarType() {
        std::cout << "Car type is: " << carType << std::endl;
    }
    void launchNitro() {
        std::cout << "Launching Nitro!" << std::endl;
    }
};
class Bus : public Vehicle {
private:
    const int busType = 2;
public:
    Bus() : Vehicle() {}
    Bus(const char* _brand,double _price, double _kmPassed) : Vehicle(_brand,_price,_kmPassed) {}
    void printBusType() {
        std::cout << "Bus type is: " << busType << std::endl;
    }
};
int main() {
    Car c1;
    c1.printVehicleInfo();
    c1.printCarType();
    c1.launchNitro();
    Car c2("Honda",10000,100);
    c2.printVehicleInfo();
    c2.nullifyKm(); // още един метод написан само в клас Vehicle
    Bus c3("Vento",100000,1231); // използваме класът бус по подобен начин на Car тъй като наследяват един и същи клас
    c3.printVehicleInfo(); 
    c3.nullifyKm();
}
```
