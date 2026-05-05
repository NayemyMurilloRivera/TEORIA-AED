
void fl::popback() {
    if (cabeza == nullptr) {
        cout << "No hay que borrar";
        return;
    }
    if (cabeza->next == nullptr) {
        delete cabeza;
        cabeza = nullptr;

    }
    Cnodo* temporal=cabeza;
    for (; temporal->next->next != nullptr; temporal = temporal->next);
    delete temporal->next;
    temporal->next = nullptr;



}
void fl::popfront() {
    if (cabeza == nullptr) {
        cout << "No hay que borrar";
        return;
    }
    if (cabeza->next == nullptr) {
        delete cabeza;
        cabeza = nullptr;

    }
    Cnodo* temporal = cabeza;
    cabeza = cabeza->next;
    delete temporal;



}



fl::fl() {
    cabeza = nullptr;
    cola = nullptr;


}

void fl::pushfront(int num) {
    if (cabeza == nullptr) {
        cabeza = new Cnodo(num);
        return;

    }
    Cnodo* temporal = new Cnodo(num);
    temporal->next = cabeza;
    cabeza = temporal;
}


void fl::pushback(int num) {
    if (cabeza == nullptr) {
        cabeza = new Cnodo(num);
        return;

    }
    Cnodo* temporal = cabeza;
    for (; temporal->next != nullptr; temporal = temporal->next);
    temporal->next = new Cnodo(num);


}

int& fl::operator [](int i) {
    Cnodo* temporal = cabeza;

    for (int j = 0; j < i; j++) {
        temporal = temporal->next;

    }
    return temporal->value;

}

void fl::impresion()
{
    Cnodo* temporal = cabeza;

    for (; temporal!= nullptr; temporal = temporal->next)
    {
        cout << "[" << temporal->value << "]" << "->";

    }
    cout << endl;


}

int main()
{
    fl listita;
    listita.pushback(1);
    listita.pushback(2);
    listita.pushback(3);
    listita.impresion();
    listita.pushfront(0);
    listita.impresion();
    listita.popback();
    listita.impresion();
    listita.popfront();
    listita.impresion();
}
