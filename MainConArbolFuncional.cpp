#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

struct pedido {
  char domicilio[30];
  int zona;
  char comercio [30];
  char rubro [30];
  float importe;
};

//Para recorrer el archivo
struct aux {
  char nombre[30];
  char domicilio[30];
  char comercio[30];
  int zona;
};

struct Nodo {
  pedido info;
  Nodo* sig;
};

//Nodo de reparto
struct NodoReparto {
  pedido info;
  NodoReparto* next;
};

//Elegir opciones
char menu();

//Hacer la Lista
void insertar(Nodo*&primero, pedido pedi, FILE *f);

//Ingresar por teclado
void ingresarPorTeclado(pedido pedido);

//Eliminar de lista principal y llevar a los repartidores
void repartir(Nodo*&primero, int cantRepart,NodoReparto*& primerReparto);

//Copiar pedidos y pasarlos a repartos
void copiar(Nodo temp, Nodo*&primero, NodoReparto *p);

//Chequear si el nombre esta en el archivo
bool chequearNombre(char nom[30], FILE *f);

int main() {
  FILE *f;
  pedido pedi;

  int nrozona, cantRepart;
  char nom[30];

  Nodo* primero1 = NULL;
  Nodo* primero2 = NULL;
  Nodo* primero3 = NULL;
  Nodo* primero4 = NULL;
  Nodo* primero5 = NULL;
  Nodo* primero6 = NULL;

  NodoReparto* primerReparto = NULL;

  int respuesta = menu();

  f = fopen("parrilas.dat", "wb+");

  if (respuesta = 1) {
    ingresarPorTeclado(pedi);
    switch (pedi.zona) {
      case 1:
        insertar(primero1, pedi, f);
        break;
      case 2:
        insertar(primero2, pedi, f);
        break;
      case 3:
        insertar(primero3, pedi, f);
        break;
      case 4:
        insertar(primero4, pedi, f);
        break;
      case 5:
        insertar(primero5, pedi, f);
        break;
      case 6:
        insertar(primero6, pedi, f);
        break;
    }

  }
  else if (respuesta = 2){
    cout << "Nombre del repartidor: " << endl;
    cin >> nom;
    chequearNombre(nom, f);
    cout << "De que zona venis?" << endl;
    cin >> nrozona;
    cout << "Cuantos pedidos vas a repartir?" <<endl;
    cin >> cantRepart;
    switch (nrozona) {
      case 1:
        repartir(primero1, cantRepart, primerReparto);
        break;
      case 2:
        repartir(primero2, cantRepart, primerReparto);
        break;
      case 3:
        repartir(primero3, cantRepart, primerReparto);
        break;
      case 4:
        repartir(primero4, cantRepart, primerReparto);
        break;
      case 5:
        repartir(primero5, cantRepart, primerReparto);
        break;
      case 6:
        repartir(primero6, cantRepart, primerReparto);
        break;
    }
  }
  else if (respuesta = 3) {
    //mostrar();
  }
  else if (respuesta = 4) {
    for(int i=0;i<=comercio.size;i++) //Se ordenan los comercios hasta que no encuentre mas en el struct
    {
        n = comercio[i];
        insertarOrdenado(r,n);
    }
    listar(r);
    return 0;
  }

    return 0;
}

void insertar(Nodo*&primero, pedido pedi, FILE *f){
    aux auxiliar;
    fread(&auxiliar, sizeof(aux), 1, f);
    while (!feof(f)) {
      if (strcmp(pedi.comercio, auxiliar.comercio)==0 && pedi.zona == auxiliar.zona) {
        Nodo*p, *r,*ant=NULL;
        p=new Nodo;
        p->info=pedi;
        r=primero;
        while(r!=NULL){
          ant=r;
          r=r->sig;
        }
        p->sig=r;
        if (r!=primero){
          ant->sig=p;
        }
        else{
          primero=p;
        }
      }
      else {
        cout << "No concuerda con el archivo" << endl;
      }

      fread(&auxiliar, sizeof(aux), 1, f);
      ingresarPorTeclado(pedi);
    }

    fclose(f);

}

char menu() {
  int respuesta;
  cout << "Seleccionar opcion: " << endl;
  cout <<"1. Hacer pedido."<<endl<<" 2. Asignar a repartidor."<<endl<< "3. Mostrar pedido"<< endl<< "4. Salir."<<endl;
  cin >> respuesta;
  return respuesta;
}

void ingresarPorTeclado(pedido pedido){
  cout << "Digite el domicilio: " << endl;
  cin >> pedido.domicilio;
  cout << "Zona: " << endl;
  cin >> pedido.zona;
  cout << "Comercio: " << endl;
  cin >> pedido.comercio;
  cout << "Rubro: " << endl;
  cin >> pedido.rubro;
  cout << "Importe: " << endl;
  cin >> pedido.importe;
}

void repartir(Nodo*&primero, int cantRepart,NodoReparto*& primerReparto){
  Nodo temp;
  //temp para guardar los datos temporalmente
  //if(primero!=NULL){
  NodoReparto *p, *q,*ant=NULL;

  for (int i = 0; i < cantRepart; i++) {
    //Copiar el pedido en un nodo temporal
    copiar(temp, primero, p);

    q=primerReparto;
    q=q->next;
    p->next = q;

    if (q != primerReparto)
      ant->next = p;
    else
      primerReparto = p;

    Nodo *w = primero;
    primero = primero->sig;
    delete w;
    }
}

void copiar(Nodo temp, Nodo*&primero, NodoReparto *p) {
  //Copiar el pedido en un nodo temporal
  strcpy(temp.info.domicilio, primero->info.domicilio);
  strcpy(temp.info.comercio, primero->info.comercio);
  temp.info.zona = primero->info.zona;
  strcpy(temp.info.rubro, primero->info.rubro);
  temp.info.importe = primero->info.importe;

  p = new NodoReparto;

  //Pasar info de nodo temporal al nodo de reparto
  strcpy(p->info.domicilio, temp.info.domicilio);
  strcpy(p->info.comercio, temp.info.comercio);
  p->info.zona = temp.info.zona;
  strcpy(p->info.rubro, temp.info.rubro);
  p->info.importe = temp.info.importe;
}

bool chequearNombre(char nom[30], FILE *f) {
  aux auxiliar;
  f = fopen("parrilas.dat", "rb");
  while (!feof(f) && strcmp(nom, auxiliar.nombre) == 1) {
    fread(&auxiliar, sizeof(aux), 1, f);
  }
  if ( strcmp(auxiliar.nombre, nom) == 0)
    return true;
  else
    return false;

}
void listar(Nodoarbol*raiz) //Listado entreorden
{
    if(raiz!=NULL)
    {
        listar(raiz->izq);
        cout<<raiz->info<<endl;
        listar(raiz->der);
    }
}

void insertarOrdenado(Nodoarbol*&raiz,int dato)
{
	FILE* f;
	aux auxiliar;
	char chasize[50]; //Caracteres maximos a evaluar para la comparacion con el archivo (por linea)
    Nodoarbol*p,*ant,*n=new Nodoarbol;
    n->info=dato;
    n->izq=n->der=NULL;
    p=raiz;
    int j = 0;
    f = fopen("Comercios.dat", "ab+"); //Abro el archivo
    fread(&auxiliar, sizeof(aux), 1, f);
    for(j = 0; j < comercio.size; j++) //Mientras existan mas comercios inserto nodos en el arbol alfabeticamente
    {
       while(!feof(f))
       {
            temporal = fgets (chasize, 50, f); //Guardo caracteres temporalmente para comparar con los comercios debajo
            if(comercio[j] == temporal)
            {
                 while(p!=NULL) //Ubico el nodo ordenado
                {
                    ant=p;
                    if(dato < p->info)
                    p=p->izq;
                    else
                    p=p->der;
                }

                if(raiz==NULL) //Enlazo el nodo ya ordenado
                    raiz=n;
                else
                {
                    if(dato < ant->info)
                    {
                        ant->izq=n;
                    }
                    else
                    {
                        ant->der=n;
                    }

                }
            }

        }
    }
    fclose(f); //Cierro el archivo


}
