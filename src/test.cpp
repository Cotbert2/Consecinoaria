#include <fstream>
#include<string.h>
#include<stdio.h>

using namespace std;

void modificar(ifstream &Lec){
    string id, Modelo, ano, precio, ruta;
    Lec.open("./db/Cars.txt", ios::in);
    ofstream aux("auxiliar.txt", ios::out);
    while (!Lec.eof()) {
        Lec >> id;
        Lec >> Modelo;
        Lec >> ano;
        Lec >> precio;
        Lec >> ruta;
        if(id == "1"){

        }
    }
}


int main(){
    return 0;
}