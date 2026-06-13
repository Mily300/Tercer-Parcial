#include "PersonaPOO.h"

PersonaPOO::PersonaPOO() : nombre(""), edad(0) {}
PersonaPOO::PersonaPOO(string n, int e) : nombre(n), edad(e) {}

void PersonaPOO::imprimir() const {
    cout << nombre << " (" << edad << " anos)";
}

bool PersonaPOO::operator<(const PersonaPOO& otra) const {
    return this->edad < otra.edad;
}

ostream& operator<<(ostream& os, const PersonaPOO& p) {
    os << p.nombre << " (" << p.edad << " anos)";
    return os;
}
