#include "zmytest/test.hpp"
#include "zlasdtest/test.hpp"
#include "thread"
#include "string"
#include <iostream>

/* ************************************************************************** */

using namespace std;

int main() {
    string alt;

    while (true) {
        cout << "--------Test LASD 2024--------" << endl;
        cout << "1: Test personale" << endl;
        cout << "2: Test professore" << endl;
        cout << "3: Esci" << endl;
        cout << "\nInserisci un numero: ";
        getline(cin, alt);

        if (alt == "1") {
            test();
            cout << "\n\nRitorno al menù principale...\n\n" << endl;
        } else if (alt == "2") {
            lasdtest();
            cout << "\n\nTest completati!\n\nRitorno al menù principale...\n\n" << endl;
            
        } else if (alt == "3") {
            break; 
        } else {
            cout << "\nScelta non valida! Riprova.\n" << endl;
        }
    }

    cout << "\n\nProgramma terminato.\n\nAntonio De Martino\nN86004701" << endl;
    return 0;
}

