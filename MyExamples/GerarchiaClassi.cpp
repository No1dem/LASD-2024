#include <iostream>

// Classe base A
class A {
public:
    A() {
        std::cout << "Costruttore A" << std::endl;
    }
};

// Classe B deriva da A      
class B : /*virtual*/ public A {     //Prova a mettere virtual qui e in C
public:
    B() {
        std::cout << "Costruttore B" << std::endl;
    }
};

// Classe C deriva da A
class C : /*virtual*/ public A {	//Prova a mettere virtual qui e in B
public:
    C() {
        std::cout << "Costruttore C" << std::endl;
    }
};

// Classe D deriva da B
class D : public B {
public:
    D() {
        std::cout << "Costruttore D" << std::endl;
    }
};

// Classe E deriva da D e C
class E : public D, public C {
public:
    E() {
        std::cout << "Costruttore E" << std::endl;
    }
};

int main() {
    E e;
    return 0;
}
