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

//DETERMINAR ALTURA (mayor nivel) DEL ÁRBOL
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
	int op;
	int aux = 0;

	do{
		system("cls");
		cout<<"        M  E  N  U      "<<endl;
		cout<<"========================"<<endl;
		cout<<" 1. CREAR ARBOL"<<endl;
		cout<<" 2. MOSTRAR (PREORDEN)"<<endl;
		cout<<" 3. MOSTRAR (INORDEN)"<<endl;
		cout<<" 4. MOSTRAR (POSTORDEN)"<<endl;
		cout<<" 5. GRADO DE LOS NODOS"<<endl;
		cout<<" 6. GRADO DEL ARBOL"<<endl;
		cout<<" 7. NIVEL DE CADA NODO"<<endl;
		cout<<" 8. ALTURA DEL ARBOL"<<endl;
		cout<<" 9. SALIR"<<endl;
		cout<<"ELIJA UNA OPCION: "; cin>>op;
		system("cls");
		
		 if (op != 1 && aux==0 && op<9) {
            cout << "Primero debe crear el arbol" << endl;
            system("pause");
            continue; //para pasar a la siguiente iteración del bucle sin ejecutar el código restante en el bloque de bucle actual.
        }
        
		switch(op){
			case 1:
				if(aux==0){
					crearArbol(raiz);
					aux = 1;
				}
				else{
					cout<<"EL ARBOL YA FUE CREADO"<<endl;
				}					
				break;
			case 2:
                cout << endl << "PREORDEN: " << endl;
                preorden(raiz);
                cout << endl;
                break;
			case 3:
				cout<<"INORDEN:"<<endl;
				inorden(raiz);
                cout << endl;
				break;
			case 4:
				cout<<endl<<"POSTORDEN: "<<endl;
				postorden(raiz);
                cout << endl;
				break;
			case 5:
				cout<<endl<<"GRADO DE LOS NODOS: "<<endl;
				gradoNodo(raiz);
				break;
			case 6:
				cout<<endl<<"GRADO DEL ARBOL: ";
				grado_Arbol(raiz, gradoMayor);
				cout<<gradoMayor<<endl;
				break;
			case 7:
				cout<<endl<<"NIVEL DE LOS NODOS: "<<endl;
				nivelNodo(raiz, 1);
				break;
			case 8:
				cout<<endl<<"ALTURA DEL ARBOL: ";
				nivel_Arbol(raiz, 1, nivelMayor);
				cout<<nivelMayor<<endl;
				break;
			case 9:
				cout<<"SALIENDO..."<<endl;
				break;		
		}
		system("pause");	
	}while(op!=9);

	return 0;
}