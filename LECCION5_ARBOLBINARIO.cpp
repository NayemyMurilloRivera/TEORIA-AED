#include <iostream>
using namespace std;

class cnodo {
public:
    cnodo* izquierda, * derecha;
    int value;
    cnodo(int val) {
        izquierda = derecha = nullptr;
        value = val;

    }
};

class arbol_binario {
public:
    arbol_binario();
    bool find(int num, cnodo**& p);
    bool insertar(int num);
    bool remover(int num);
    cnodo** decisidor_menor_mayores(cnodo** q);
    void impresion();
    void inorder(cnodo* n);
    void post(cnodo* n);
    void pre(cnodo* n);
    void reverse(cnodo* n);
    


private:
    cnodo* root;
    bool decision;

};

arbol_binario::arbol_binario() {
    root = nullptr;
    decision = 0;


}
bool arbol_binario::find(int num, cnodo**& p) 
{
    p = &root;
    while (*p && (*p)->value != num) {
        if ((*p)->value > num) {
            p = &((*p)->izquierda);
        }
        else{
            p = &((*p)->derecha);
        }
        
    }
    return *p != 0;
}

bool arbol_binario::insertar(int num)
{
    cnodo** p;
    if (find(num, p)) { // find(num,p)==true
        return 0;
    }
    *p = new cnodo(num);
    return 1;

}
cnodo** arbol_binario::decisidor_menor_mayores(cnodo** q) {
    cnodo** q1;
    if (decision==1) {
        q1 = &((*q)->derecha);
        for (; (*q1) && (*q1)->izquierda != nullptr; q1 = &((*q1)->izquierda)) {}; // menor de los mayores
       
    }
    else {
        q1 = &((*q)->izquierda);
        for (; (*q1) && (*q1)->derecha != nullptr; q1 = &((*q1)->derecha) ){};
    }
    return q1;
}


bool arbol_binario::remover(int num) {
    cnodo** p;
    if (find(num, p) != true) // find(num,p) == false 
    {
        cout << "Que borro si no esta en el arbol";
        return 0;

    }

    cnodo* t = *p;
   
    if ((*p)->derecha && (*p)->izquierda) {
        t= *(decisidor_menor_mayores(p));
        (*p)->value = t->value;
        decision = !decision;
        *p = t;
        

    }
 

    if ((*p)->derecha)
    {
        *p = (*p)->derecha;
    }
    else {
        *p = (*p)->izquierda;
    }
    delete t;
    return true;
  
  
}

void arbol_binario::impresion() {
    cout << "inorder "; inorder(root); std::cout << "\n";
    cout << "preorder "; pre(root); std::cout << "\n";
    cout << "posorder "; post(root); std::cout << "\n";
   
    cout << "reverse "; reverse(root); std::cout << "\n";
    cout << "";
    
}

void arbol_binario::inorder(cnodo* n) {
    if (!n) { return; }
    inorder(n->izquierda);
    cout << n->value << "   ";
    inorder(n->derecha);

}

void arbol_binario::post(cnodo* n) {
    if (!n) return;
    post(n->izquierda);
    post(n->derecha);
    cout << n->value << "  ";

}
void arbol_binario::pre(cnodo* n) {
    if (!n) return;
    cout << n->value << "  ";
    pre(n->izquierda);
    pre(n->derecha);
    

}
void arbol_binario::reverse(cnodo* n) {
    if (!n) return;
    cout << n->value << "  ";
    reverse(n->derecha);
    reverse(n->izquierda);
}

int main()
{
    arbol_binario arb;
    arb.insertar(61);
    arb.insertar(50);
    arb.insertar(63);
    arb.insertar(62);
    arb.insertar(60);
    arb.impresion();
    arb.remover(60);
    arb.impresion();



}
