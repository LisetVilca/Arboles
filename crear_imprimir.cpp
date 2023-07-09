#include<iostream>
using namespace std;

struct nodo{
	char n;
	nodo *izq, *der;
};

void crear(nodo *raiz){
	char op;
	nodo *x;
	
	cout<<" DATO: "; cin>>raiz->n;
	cout<<" ["<<raiz->n<<"]"<<" tiene rama izquierda? (S/N): ";  cin>>op;
	if(op=='s' || op=='S'){
		x=new(nodo);
		raiz->izq = x;
		crear(raiz->izq);	
	}
	else{
		raiz->izq = NULL;
	}
	
	cout<<" ["<<raiz->n<<"]"<<" tiene rama derecha? (S/N): ";  cin>>op;
	if(op=='s' || op=='S'){
		x = new(nodo);
		raiz->der = x;
		crear(raiz->der);
	}
	else{
		raiz->der = NULL;
	}
}

void preorden(nodo *raiz){
	if(raiz != NULL){
		cout<<raiz->n<<" ";
		preorden(raiz->izq);
		preorden(raiz->der);
	}
}

void inorden(nodo *raiz){
	if(raiz != NULL){
		inorden(raiz->izq);
		cout<<raiz->n<<" ";
		inorden(raiz->der);
	}
}

void postorden(nodo *raiz){
	if(raiz != NULL){
		postorden(raiz->izq);
		postorden(raiz->der);
		cout<<raiz->n;
	}
}

void nivelNodo(nodo* raiz, int nivel) {
    if (raiz != NULL) {
        cout << "Nodo " << raiz->n << " - Nivel: " << nivel << endl;
        nivelNodo(raiz->izq, nivel + 1);
        nivelNodo(raiz->der, nivel + 1);
    }
}

int alturaArbol(nodo* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    else {
        int alturaIzq = alturaArbol(raiz->izq);
        int alturaDer = alturaArbol(raiz->der);
        return 1 + max(alturaIzq, alturaDer);
    }
}

int gradoNodo(nodo* nodo) {
    if (nodo == NULL) {
        return 0;
    }
    else {
        int grado = 0;
        if (nodo->izq != NULL) {
            grado++;
        }
        if (nodo->der != NULL) {
            grado++;
        }
        return grado;
    }
}

void calcularGradoNodos(nodo* raiz) {
    if (raiz != NULL) {
        cout << "Grado del nodo " << raiz->n << ": " << gradoNodo(raiz) << endl;
        calcularGradoNodos(raiz->izq);
        calcularGradoNodos(raiz->der);
    }
}


int main(){
	nodo *raiz = NULL;
	raiz = new(nodo);
	crear(raiz);
	cout<<"PREORDEN: "<<endl;
	preorden(raiz);
	cout<<endl<<"INORDEN: "<<endl;
	inorden(raiz);
	cout<<endl<<"POSTORDEN: "<<endl;
	postorden(raiz);
	cout << endl << "NIVEL DE NODOS: " << endl;
    nivelNodo(raiz, 0);
    int altura = alturaArbol(raiz);
    cout << "Altura del arbol: " << altura << endl;
    calcularGradoNodos(raiz);
	
	
	return 0;
}












