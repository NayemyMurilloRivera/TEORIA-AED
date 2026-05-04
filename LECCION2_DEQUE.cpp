
#include <iostream>
using namespace std;
class Cdeque {
public:
    int& operator [](int i);
    Cdeque(int size_m, int size_a);
    void pushback(int num);
    void expansion();
    void pushfront(int num);
    void impresion();
    void pop_back();
    void pop_front();

private:
    int** mapa;
    int size_map, size_pos, nelem;
    //marcadores
    int inicio_mapa, final_mapa;
    int inicio_pos, final_pos;
  
    

};

void Cdeque::pop_back() {

    if (nelem==0) {
        cout << " Esta vacio , no hay nada que hacer";
        return;
    }
    else {
        if (final_pos == 0) {
            final_mapa--;
            final_pos = size_pos -1; // sube a la segunda parte;



        }
        else {
            final_pos--;
        }
        nelem--;
    }
    cout << "POP BACK:";
}


void Cdeque::pop_front() {

    if (nelem == 0) {
        cout << " Esta vacio , no hay nada que hacer";
        return;
    }
    else {
        if (inicio_pos== size_pos-1) {
            inicio_mapa++;
            inicio_pos = 0;
        }
        else {
            inicio_pos++;
        }
        nelem--;
    }
    cout << "POP FRONT:";
}
Cdeque::Cdeque(int size_m, int size_a){

    size_map = size_m;
    size_pos = size_a;
    nelem = 0;
    inicio_mapa = size_map / 2;
    final_mapa = inicio_mapa;
    inicio_pos = size_pos / 2;
    final_pos= inicio_pos;
    mapa = new int* [size_map];
    // hay una diferencia cuando creas memoria apunta a direcciones aleatorias 
    // pero debemosa saber a donde va;
    for (int i = 0; i < size_map; i++) {
        mapa[i] = nullptr;// bloque
    }
}
int& Cdeque:: operator [](int i) {
    int prueba = 0;
    if (i < 0 || i >= nelem) {
        cout << "Una mrd tu codigo";
        return prueba;
    }
    int bloque = inicio_mapa + (inicio_pos + i)/ size_pos;
    int posicion = (inicio_pos + i) % size_pos;
    

   
    if (mapa[bloque] == nullptr) // el bloque ni existe en esa posicion
    {
        mapa[bloque] = new int[size_pos];

    }
    return mapa[bloque][posicion];

}

void Cdeque::pushback(int num)
{
    if (mapa[final_mapa] == nullptr) {
        mapa[final_mapa] = new int[size_pos];
        mapa[final_mapa][final_pos] = num;
        nelem++;
        return;

    }
    else {
        if (final_pos < (size_pos - 1)) {
            final_pos++;
            mapa[final_mapa][final_pos] = num;
            nelem++;//tamaño total del deque

            return;


        }
        if (final_pos == (size_pos - 1))
        {
            if (final_mapa == size_map-1) {
                expansion();
              

            }
            final_mapa++;
            final_pos = 0;

            if (mapa[final_mapa] == nullptr) { // por si no existe a donde agregarias?
                mapa[final_mapa] = new int[size_pos];
            }

            mapa[final_mapa][final_pos] = num;
            nelem++;
            return;


            
        }
    }

    
}

void Cdeque::impresion()
{
    for (int i = 0; i < nelem; i++) {
        cout << "[" << operator[](i) << "] ";
    }
    cout << endl;
    
}


void Cdeque::expansion()
{
    int duplicado = size_map * 2;
    int** mapa2 = new int* [duplicado];
    for (int i = 0; i < duplicado; i++) {
        mapa2[i] = nullptr;
    }
    
    int rangoganado = (duplicado - size_map) / 2;
    for (int i = 0; i < size_map; i++) {
        if (mapa[i] != nullptr) //osea si hay algo creado
        {
            mapa2[i + rangoganado] = mapa[i];
        }
    
    }
    delete[] mapa;
    mapa = mapa2;
    inicio_mapa = inicio_mapa + rangoganado; 
    final_mapa += rangoganado;
    size_map = duplicado;

 

}


void Cdeque::pushfront(int num) {

    if (mapa[inicio_mapa] == nullptr) {
        mapa[inicio_mapa] = new int[size_pos];
        mapa[inicio_mapa][inicio_pos] = num;
        nelem++;
        return;

    }
    else {
        if (inicio_pos > 0) {
            inicio_pos--;
            mapa[inicio_mapa][inicio_pos] = num;
            nelem++;//tamaño total del deque

            return;


        }
        if (inicio_pos==0)
        {
            if (inicio_mapa == 0) {
                expansion();


            }
            inicio_mapa--;
            inicio_pos = size_pos-1;

            if (mapa[inicio_mapa] == nullptr) { // por si no existe a donde agregarias?
                mapa[inicio_mapa] = new int[size_pos];
            }

            mapa[inicio_mapa][inicio_pos] = num;
            nelem++;
            return;



        }
    }
}
int main()
{
    Cdeque dequesito(5,3);
    dequesito.pushfront(-4);
    dequesito.pushfront(-3);
    dequesito.pushfront(-2);
    dequesito.pushfront(1);
    dequesito.pushback(1);
    dequesito.pushback(2);
    dequesito.pushback(3);
    dequesito.pushback(4);
    dequesito.pushfront(-5);
    dequesito.pushback(5);
    dequesito.impresion();

    dequesito.pop_back();
    dequesito.pop_back();
   

    dequesito.impresion();

    dequesito.pop_front();

    dequesito.impresion();

}
