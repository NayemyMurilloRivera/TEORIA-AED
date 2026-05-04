#include <iostream>
using namespace std;
struct cn
{
	int valor_de_cn;
	cn* siguiente_enlace, * antes_enlace;
	cn(int valor)
	{
		valor_de_cn = valor;
		siguiente_enlace = antes_enlace = nullptr;
	}

};

class lista_enlazada
{
public:
	lista_enlazada();
	~lista_enlazada();

	void push_back(int ningreso);
	//int & operator[](int i);

	void push_front(int ningreso);
	void pop_front();
	void pop_back();
	void print();



private:
	cn* cabeza, * cola;

};
lista_enlazada::lista_enlazada(){
	cola = nullptr;
	cabeza = nullptr;
}
lista_enlazada::~lista_enlazada(){

}
void lista_enlazada::push_back(int ningreso) {

	if (cabeza == nullptr) {
		cabeza = new cn(ningreso);
		cola = cabeza;// misma direccion 
	}
	else {
		cn* aux = new cn(ningreso);
		cola->siguiente_enlace = aux;
		aux->antes_enlace = cola;
		cola = aux;
	}
}
 
/*int& lista_enlazada::operator[](int i) {
	return;
}*/

void lista_enlazada::push_front(int ningreso) {
	if (cabeza == nullptr) {
		cabeza = new cn(ningreso);
		cola = cabeza;
	}
	else {
		cn* aux = new cn(ningreso);
		cabeza->antes_enlace = aux;
		aux->siguiente_enlace = cabeza;
		cabeza = aux;

	}

}
void lista_enlazada::pop_front() {
	if (cabeza == nullptr) {
		cout << " Esta vacio beba" << endl;
		return;
	}


}
void lista_enlazada::pop_back() {
	if (cabeza == nullptr) {
		cout << " Esta vacio beba" << endl;
		return;
	}
	cn* eliminado = cola;
	cn* aux = cola->antes_enlace;
	aux->siguiente_enlace = nullptr;
	cola = aux;
	delete eliminado;

}

void lista_enlazada::print() {
	cn* aux = cabeza;
	
	for (; aux != nullptr; aux = aux->siguiente_enlace) {
		cout << "<-(" << aux->valor_de_cn << ")->";


	}
	cout << endl;
	

}


int main()
{
	lista_enlazada listad;
	listad.push_back(1);
	listad.push_back(2);
	listad.push_back(3);

	listad.print();
	listad.push_front(0);

	listad.print();

	listad.pop_back();

	listad.print();

}
