#include <iostream>


template <typename T>
class Base {
public:
    void foo() {
        std::cout << "Base::foo()" << std::endl;
    }
};

template <typename T>
class Derived : public Base<T> {
public:
    void bar() {
        // Corretto: utilizzo di this-> per accesso esplicito al membro della classe base
	this->foo();
        
        // Errato: accesso diretto ai membri della classe base, può causare errori di compilazione
        //foo();
    }
};


int main () {
	std::cout << "No errori compilazione." << std::endl;
}
