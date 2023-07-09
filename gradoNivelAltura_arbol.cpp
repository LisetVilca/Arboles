#include<iostream>
using namespace std;

struct nodo{
	char n;
	nodo *izq;
	nodo *der;
};
// CREACIÓN DE ARBOL
void crearArbol(nodo *&raiz){
	char op;
	nodo *x;
	
	cout<<"NODO: "; cin>>raiz->n;
	
	cout<<raiz->n<<" tiene rama izquierda? (S/N): "; cin>>op;
	if(op=='s' || op=='S'){
		x = new(nodo);
		raiz->izq = x;
		crearArbol(x);
	}
	else{
		raiz->izq = NULL;
	}
	
	cout<<raiz->n<<" tiene rama derecha? (S/N): "; cin>>op;
	if(op=='s' || op=='S'){
		x = new(nodo);
		raiz->der = x;
		crearArbol(x);
	}
	else{
		raiz->der = NULL;
	}
}

// MANERAS DE MOSTRAR ELEMENTOS DEL ARBOL
void preorden(nodo *raiz){
	if(raiz !=NULL){
		cout<<raiz->n<<" ";
		preorden(raiz->izq);
		preorden(raiz->der);
	}		
}
void inorden(nodo *raiz){
	if(raiz !=NULL){
		inorden(raiz->izq);
		cout<<raiz->n<<" ";
		inorden(raiz->der);
	}
}
void postorden(nodo *raiz){
	if(raiz !=NULL){
		postorden(raiz->izq);
		postorden(raiz->der);
		cout<<raiz->n<<" ";
	}
}

// DETERMINAR EL GRADO DE CADA NODO
void gradoNodo(nodo *raiz){
	int grado = 0;
	
	if(raiz != NULL){
		if(raiz->izq != NULL){
			grado = grado+1;
			gradoNodo(raiz->izq);
		}
		if(raiz->der != NULL){
			grado = grado+1;
			gradoNodo(raiz->der);
		}
		cout<<"Grado de ["<<raiz->n<<"] = "<<grado<<endl;
	}	
}
/* función gradoNodo con menor cantidad de líneas de código, usando CONDICIONAL TERNARIO
variable = (condición) ? valor_si_verdadero : valor_si_falso;
int maximo = (a > b) ? a : b;
	
	void gradoNodo(nodo *raiz){
		int grado = 0;
		if(raiz != NULL){
			(raiz->izq != NULL)? (grado++, gradoNodo(raiz->izq)) : void();
		    (raiz->der != NULL)? (grado++, gradoNodo(raiz->der)) : void();
			cout<<"Grado de ["<<raiz->n<<"] = "<<grado<<endl;
		}
	}

*/

// DETERMINAR GRADO DEL ARBOL
void grado_Arbol(nodo *raiz, int &gradoMayor){
	int grado = 0;
	if(raiz != NULL){
		(raiz->izq != NULL)? (grado++, grado_Arbol(raiz->izq, gradoMayor)) : void();
		(raiz->der != NULL)? (grado++, grado_Arbol(raiz->der, gradoMayor)) : void();
	    if(grado > gradoMayor) gradoMayor = grado;
	}	
}

// DETERMINAR NIVEL de cada nodo
void nivelNodo(nodo *raiz, int nivelActual) {
    if (raiz != NULL) {
        cout << "Nivel del nodo [" << raiz->n << "] = " << nivelActual << endl;
        nivelNodo(raiz->izq, nivelActual + 1);
        nivelNodo(raiz->der, nivelActual + 1);
    }
}


//DETERMINAR NIVEL DEL ÁRBOL
void nivel_Arbol(nodo *raiz, int nivel, int &nivelMayor) {
    if (raiz != NULL) {
        if (nivel > nivelMayor) nivelMayor = nivel;
        nivel_Arbol(raiz->izq, nivel + 1, nivelMayor);
        nivel_Arbol(raiz->der, nivel + 1, nivelMayor);
    }
}















int main(){
	nodo *raiz = NULL;
	raiz = new(nodo);
	int gradoMayor=0;
	int nivelMayor=1;
	
	crearArbol(raiz);
	cout<<endl<<"PREORDEN: "<<endl;
	preorden(raiz);
	cout<<endl<<"INORDEN: "<<endl;
	inorden(raiz);
	cout<<endl<<"POSTORDEN: "<<endl;
	postorden(raiz);
	cout<<endl<<"GRADOS DE LOS NODOS: "<<endl;
	gradoNodo(raiz);
	cout<<endl<<"GRADO DEL ARBOL: ";
	grado_Arbol(raiz, gradoMayor);
	cout<<gradoMayor<<endl;
	cout<<endl<<"NIVEL DE LOS NODOS: "<<endl;
	nivelNodo(raiz, 1);
	cout<<endl<<"NIVEL DEL ARBOL: ";
	nivel_Arbol(raiz, 1, nivelMayor);
	cout<<nivelMayor<<endl;
	
	
	return 0;
}