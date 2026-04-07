// Practica de vector.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

class cvector {
public:
	cvector(int longitud);
	~cvector();
	void expansion();
	void push_back(int numero);
	void pop_back();
	void push_front(int numero);
	void pop_front();
	int& operator[](unsigned long i);
	int nelem();



private:
	unsigned long  size, posicion;
	int* v;

};
int cvector::nelem() {
	return posicion;
}

cvector::cvector(int longitud) {
	size = longitud;
	v = new int[size]; // v=0 posicion
	posicion = 0;// para posiciones
}

cvector::~cvector() {
	delete[] v;

}
int& cvector:: operator[](unsigned long  i) {
	// *(v + 1);
	return v[i];
}

void cvector::expansion() {
	cout << "Se expandio" << endl;

	int* p = new int[size * 2];
	for (unsigned long i = 0; i < posicion; i++) {
		p[i] = v[i];
	}
	delete[] v;
	v = p;
	size = size * 2;
}

void cvector::push_back(int numero) {
	if (posicion == size) {

		expansion();

	}
	v[posicion] = numero;
	posicion++;

}
void cvector::pop_back() {
	if (posicion == 0) {
		cout << " Esta vacio no hay nada que borrar";
		return;
	}
	// aqui le pones "v[posicion] = NULL;" porque tu pensaste que era un puntero y no hay problema en ponerlo
	//pero lo que va a ocasionar es salirse de la memoria cuando este sea igual al tamaño de memoria 

	--posicion;  
}
void cvector::push_front(int numero) {
	if (posicion == size) {
		expansion();

	}
	for (unsigned long i = posicion   ; i > 0;i--) {
		v[i] = v[i-1];
	}  
	v[0] = numero;

	posicion++;
}

void cvector::pop_front() {
	if (posicion == 0) {
		cout << "No hay nada que borrar";
		return;

	}
	for (unsigned long i =0; i < posicion-1; i++) {
		v[i] = v[i + 1];
	}
	posicion--;

}

int main()
{
	int tam = 4;
	cvector vetito(tam);
	vetito.push_back(1);
	vetito.push_back(2);
	vetito.push_back(3);
	vetito.push_back(4);
	vetito.pop_back();
	vetito.pop_back();
	vetito.pop_back();
	vetito.pop_back();

	vetito.push_front(1);
	vetito.push_front(2);
	vetito.push_front(1);
	vetito.push_front(2);
	vetito.push_front(1);
	vetito.push_front(2);
	vetito.pop_front();
	vetito.pop_front();

	for (int i = 0; i < vetito.nelem(); i++) {
		cout << vetito[i];

	}



}
