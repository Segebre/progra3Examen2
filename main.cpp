#include <iostream>
#include <list>
#include <fstream>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include "Gato.h"
#include "Evaluador.h"
#include "NodoTrinario.h"
#include <algorithm>

using namespace std;

//Escribe los datos del objeto gato (dado) en un archivo binario con el nombre dado en la posicion dada
//Nota: Se deben poder agregar varios gatos en un solo archivo
void escribir(string nombre_archivo, Gato*gato, int posicion)//appppppppppppppppppppppppppppppppppp
{
    ofstream out(nombre_archivo.c_str(), ios::app);
    out.seekp(posicion*25);
    out.write((char*)&gato->edad, 4);
    out.write((char*)&gato->sexo, 1);
    out.write(gato->nombre.c_str(), 10);
    out.write(gato->raza.c_str(), 10);
}

//Devuelve un gato previamente escrito (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varios gatos de un solo archivo
Gato* leer(string nombre_archivo, int posicion)
{
    Gato *gato = new Gato(0,' ',"","");
    ifstream in(nombre_archivo.c_str());
    in.seekg(posicion*25, ios::beg);
    int eda;
    char sex;
    char nom[10];
    char raz[10];
    in.read((char*)&eda, 4);
    in.read((char*)&sex, 1);
    in.read(nom, 10);
    in.read(raz, 10);
    gato->edad=eda;
    gato->sexo=sex;
    gato->nombre=nom;
    gato->raza=raz;
    return gato;
}

//Devuelve el promedio de la edad de todos los gatos guardados en el archivo con nombre dado
double getPromedioDeEdad(string nombre_archivo)
{
    int tot = 0;
    int temp;
    double suma = 0;
    ifstream in(nombre_archivo.c_str());
    in.seekg(0, ios::end);
    int sizeF = in.tellg();
    for(int i = 0; i<sizeF/25; i++)
    {
        in.seekg(i*25, ios::beg);
        in.read((char*)&temp, 4);
        suma+=temp;
        tot++;
    }
    return suma/tot;
}

//Devuelve el numero mayor almacenado en mi_set (dado)
int getMayor(set<int> mi_set)
{
    int mayor = -1000;
    for(set<int>::iterator i=mi_set.begin(); i!=mi_set.end(); i++)
    {
        if(mayor < (*i))
            mayor = (*i);
    }
    return mayor;
}

//Mezcla el contenido de a y b (dados) y lo devuelve en un set ordenado alfabeticamente
set<char> mezclarAlfabeticamente(queue<char> a, stack<char> b)
{
    set<char> resultado;
    vector<char> sortear;
    while(!a.empty())
    {
        sortear.push_back(a.front());
        a.pop();
    }
    while(!b.empty())
    {
        sortear.push_back(b.top());
        b.pop();
    }
    sort(sortear.begin(), sortear.end());
    for(int i = 0; i < sortear.size(); i++)
    {
        resultado.insert(sortear[i]);
    }
    return resultado;
}

//Devuelve true si buscada (dada) existe en mi_mapa (dado), de lo contrario devuelve false
//Se debe de buscar en las llaves y en los valores almacenados en cada vector del mapa
bool existe(map<string,vector<string> >mi_mapa, string buscada)
{
    return false;
}

//Devuelve el valor mayor almacenado en el arbol con raiz dada
int getMayor(NodoTrinario* raiz)
{
    return -1;
}

//Busca y reemplaza dado los valores buscado y reemplazo en el arbol con raiz dada
void buscarYReemplazar(NodoTrinario* raiz,int buscado, int reemplazo)
{
}

char retener3Bits(char byte)
{
    return 0;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}

