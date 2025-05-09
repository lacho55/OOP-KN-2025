# Полиморфизъм
#### Главен проблем № 1 - Искам по - силна абстракция и възможността да направя вектор от фигури, които може да са правоъгълник, триъгълник или кръг и да ги пазя всичките едновременно в този вектор. Как тогава ще стане наследяването и и имплементациите на тези фигури, когато те са с различни имплементации за търсене на лице и обиколка? 

### Отговорът е Полиморфизъм - това е принципът, който казва, че един клас може да е базов и да е шаблонен от гледна точка, че казва какви методи ще има всеки клас, който го наследи, а всеки клас, който го наследява ще имплементира тези по свой собствен начин. В примера по - долу ще стане по - ясно. 

``` c++
#include <iostream>
#include <cmath>
class Shape {
public:
    // така казваме, че тези функции ще бъдат чисто виртуални и няма да има нужда да им пишем имплементация
    virtual void printPerimeter() const = 0; 
    virtual void printArea() const = 0;
};

class Rectangle : public Shape {
private:
    int sideA;
    int sideB;
public:
    Rectangle(int _sideA, int _sideB) : sideA(_sideA), sideB(_sideB) {}

    // тъй като наследяваме чисто абстрактен клас (всичките му методи са напълно виртуални)
    // всички напълно виртуални методи трябва да бъдат имплементирани в клас Rectangle и това
    // е аналогично за всички други класове, които наследяват Shape;
    void printPerimeter() const override { 
        std::cout << "Perimeter rectangle is: " << 2 * (sideA + sideB) << std::endl;
    }

    void printArea() const override { // когато предефинираме метод не е зле да пишем по един "override"
        std::cout << "Area rectangle is: " << sideA * sideB << std::endl;
    }
};

class Circle : public Shape {
private:
    double radius;
    const double PI = 3.141592;
public:
    Circle(int _radius) : radius(_radius) {}

    void printPerimeter() const override { 
        std::cout << "Perimeter of circle is: " << 2.0 * PI * radius << std::endl;
    }

    void printArea() const override {
        std::cout << "Area of circle is: " << PI * radius * radius << std::endl;
    }
};

class Triangle : public Shape {
private:
    int sideA;
    int sideB;
    int sideC;

public:
    Triangle(int _sideA, int _sideB, int _sideC) : sideA(_sideA), sideB(_sideB), sideC(_sideC) {}

    void printPerimeter() const override { 
        std::cout << "Perimeter of triangle is: " << sideA + sideB + sideC << std::endl; 
    }

    void printArea() const override {
        double p = (sideA + sideB + sideC) / 2.0;
        std::cout << "Area of triangle is: " << sqrt(p * (p - sideA) * (p - sideB) * (p - sideC)) << std::endl;
    }
};


int main () {
    Triangle triangle1(3,4,5); // напълно нормален клас

    triangle1.printPerimeter();
    triangle1.printArea();

    std::cout << std::endl;

    // абстрактен клас, който приема формата на триъгълник като насочва указател към новосъздадения обект.
    Shape* shape1 = new Triangle(3,4,5); // работи аналогично с горния клас.
    shape1->printPerimeter();
    shape1->printArea();

    // тук Shape приема формата на правоъгълник! От тук идва и името Поли- (много) морф- (форма) изъм;
    Shape* shape2 = new Rectangle(10,5); 
    shape2->printArea();
    shape2->printArea();

    delete shape1; // когато пишем new трябва и delete.
    delete shape2; 
    std::cout << std::endl;

    // Този принцип ни позволява пък да направим следното.
    Shape** shapes = new Shape*[5];
    shapes[0] = new Triangle(1,2,2);
    shapes[1] = new Rectangle(3,4);
    shapes[2] = new Circle(5);
    shapes[3] = new Triangle(3,4,5);
    shapes[4] = new Circle(3);

    for (size_t i = 0; i < 5; i++) {
        shapes[i]->printPerimeter();
        shapes[i]->printArea();
        std::cout << std::endl;
    }
}
```

## Да не забравим, че можем да имаме полу - интерфеисни класове, от които можем да наследим някои методи и член данни но също да имаме полу - виртуални методи, които да предефинираме. Пример по - долу

``` c++
#include <iostream>
#include <cmath>
class Square {
protected:
    int sideA;
public:
    Square(int _sideA) : sideA(_sideA) {} 

    virtual void printPerimeter() const {
        std::cout << "Perimeter of square is: " << 4 * sideA << std::endl;
    }; 

    virtual void printArea() const {
        std::cout << "Area of square is: " << sideA * sideA << std::endl;
    };
};

class Rectangle : public Square {
private:
    int sideB;
public:
    Rectangle(int _sideA, int _sideB) : Square(_sideA), sideB(_sideB) {}

    // предефинираме горните два метода, но си взимаме едната член данна
    // SideA от клас Square.
    void printPerimeter() const override { 
        std::cout << "Perimeter rectangle is: " << 2 * (sideA + sideB) << std::endl;
    }

    void printArea() const override { 
        std::cout << "Area rectangle is: " << sideA * sideB << std::endl;
    }
};



int main () {
    Square square(1);
    Rectangle rect(2,3);

    square.printPerimeter();
    square.printArea();

    std::cout << std::endl;
    rect.printPerimeter();
    rect.printArea();
}
```

![image](https://user-images.githubusercontent.com/37977687/234769072-e78c6e12-4f87-483b-9330-59cac2d39936.png)
