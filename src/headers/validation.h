#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <regex>
#include <fstream>
#include <iostream>

using namespace std;

#define dim 100

long int validar_numeros_p (long int x){
    while(x<100000000||x>3100000000){
        printf("Cedula no valida !! Ingrese una cedula correcta: ");
        scanf("%ld",&x);
    }
    return (x);
}

long int validar_numeros_e (long int x){
    while(x>=2500000000 && x<3000000000){
        printf("Cedula no valida !! Ingrese una cedula correcta: ");
        scanf("%ld",&x);
    }
    return (x);
}

bool validar_cedula(long int x){
    int i,res,A[10],mul,sumaimpares=0,sumapares=0,sumat,s;
    long int coc;
    for(i=9;i>=0;i--)
    {
        coc=x/10;
        res=x%10;
        A[i]=res;
        x=coc;
    }
    for(i=0;i<9;i+=2)
    {
        mul=A[i]*2;
        if(mul>9)
            mul-=9;
        sumapares+=mul;
    }
    for(i=1;i<9;i+=2)
        sumaimpares+=A[i];

    sumat=sumapares+sumaimpares;
    res=sumat%10;
    s=10-res;
    if(s==10)
        s=0;
    if(s==A[9])
        return (true);
    else
        return (false);
}


bool hasAlreadyExist(string cedToFind){
    int counter = 0;
    bool exist = false;
    string cedula, Name, LastName, email, mobile, direction; 
    ifstream reader("./db/Users.txt", ios::in);
    while (!reader.eof()) {
        reader >> cedula;
        reader >> Name;
        reader >> LastName;
        reader >> email;
        reader >> mobile;
        reader >> direction;
        if(cedula == cedToFind){
            exist = true;
            break;
        }
    }

    reader.close();
    return exist;
}


bool hasAlreadyExistCar(string modelToFind){
    bool exist = false;
    string id, Model, year, cost, path; 
    ifstream reader("./db/Cars.txt", ios::in);
    while (!reader.eof()) {
        reader >> id;
        reader >> Model;
        reader >> year;
        reader >> cost;
        reader >> path;
        if(Model == modelToFind){
            exist = true;
            break;
        }
    }
    reader.close();
    return exist;
}

bool hasAlreadyExistCarPrint(string modelToFind){
    char tagPath[100];
    bool exist = false;
    string id, Model, year, cost, path; 
    ifstream reader("./db/Cars.txt", ios::in);
    while (!reader.eof()) {
        reader >> id;
        reader >> Model;
        reader >> year;
        reader >> cost;
        reader >> path;
        if(Model == modelToFind){
            printf("*************************************** \n");
            cout << "*\t" << id << ". "<< Model <<  "            *\n";
            printf("***************************************\n");
            cout << "Año: " << year <<  "\n";
            cout << "Cost: " << cost <<  "\n";
            path = "xdg-open ./public/" + path;
            system(strcpy(tagPath, path.c_str()));
        }
    }
    reader.close();
    return exist;
}


float carPrice(string modelToFind){
    char tagPath[100];
    bool exist = false;
    string id, Model, year, cost, path; 
    ifstream reader("./db/Cars.txt", ios::in);
    while (!reader.eof()) {
        reader >> id;
        reader >> Model;
        reader >> year;
        reader >> cost;
        reader >> path;
        if(Model == modelToFind){
            return (std::stof(cost));
        }
    }
    reader.close();
    return exist;
}


bool hasAlreadyExistPrint(string cedToFind){
    int counter = 0;
    bool exist = false;
    string cedula, Name, LastName, email, mobile, direction; 
    ifstream reader("./db/Users.txt", ios::in);
    while (!reader.eof()) {
        reader >> cedula;
        reader >> Name;
        reader >> LastName;
        reader >> email;
        reader >> mobile;
        reader >> direction;
        if(cedula == cedToFind){
            printf("*************************************** \n");
            cout << "*\tCedula: " << cedula <<  "            *\n";
            printf("***************************************\n");
            cout << "Nombre: " << Name <<  "\n";
            cout << "Telefono: " << mobile <<  "\n";
            cout << "Direccion: " << direction <<  "\n";
            cout << "Email: " << email <<  "\n";
            exist = true;
            break;
        }
    }

    reader.close();
    return exist;
}

bool validateNameBool(char nombre[dim]) {
    const regex expReg("^[A-Za-z]+ [A-Za-z]+$");
    return regex_match(nombre, expReg); 
}

bool validarEmailBool(char correo[dim]) {
    const regex expReg("[a-zA-Z0-9_]+([.][a-zA-Z0-9_]+)*@[a-zA-Z0-9_]+([.][a-zA-Z0-9_]+)*[.][a-zA-Z]{2,5}");
    return regex_match(correo, expReg);
}

bool validarPathBool(char myPath[dim]) {
    const regex expReg("^[a-zA-Z0-9.]+$");
    return regex_match(myPath, expReg);
}


bool validateDirectionBool(char direction[dim]){
    const regex expReg("^[A-Za-z]+$");
    return regex_match(direction, expReg);
}

bool validateMobileBool(char mobile[dim]){
    const regex expReg("^09[0-9]{8}$");
    return regex_match(mobile, expReg);
}


long int validateCed(){
    long int ced;
    do {
        printf("Ingresa la cedula: ");
        scanf("%li",&ced);
        if(!validar_cedula(ced))
            printf("[-] Ingrese una cedula valida \n");
        if(hasAlreadyExist(std::to_string(ced)))
            printf("[-] La cedula ingresada ya existe\n");
    }while(!validar_cedula(ced) || hasAlreadyExist(std::to_string(ced)));
    return ced;
}

void validateName(char name[dim]){
    do {
        printf("Ingrese el nombre: ");
        scanf(" %[^\n]", name);
        if(!validateNameBool(name))
            printf("[-] Nombre no valido \n");
    }while(!validateNameBool(name));
} 


void validateEmail(char email[dim]){
    do {
        printf("Ingrese el correo: ");
        scanf(" %[^\n]", email);
        if(!validarEmailBool(email))
            printf("[-] Correo no valido \n");
    }while(!validarEmailBool(email));
}

void validateDirecction(char direction[dim]){
    do {
        printf("Ingrese la direccion: ");
        scanf(" %[^\n]", direction);
        if(!validateDirectionBool(direction))
            printf("[-] Direccion no valido \n");
    }while(!validateDirectionBool(direction));
}

void validateMobile(char mobile[dim]){
    do {
        printf("Ingrese el numero de celulars: ");
        scanf(" %[^\n]", mobile);
        if(!validateMobileBool(mobile))
            printf("[-] Celular no valido \n");
    }while(!validateMobileBool(mobile));  
}

int validateYearCar(){
    int myYear;
    do{
        printf("Ingrese el año del carro: ");
        scanf("%i",&myYear);
        if(!(myYear > 1950 && myYear < 2024))
            printf("[-] Año Invalido \n");
    }while(!(myYear > 1950 && myYear < 2024));
    return myYear;
}

double validatePrice(){
    double price;
    do{
        printf("Ingrese el valor del carro: ");
        scanf("%lf",&price);
        if(!(price > 0))
            printf("[-] Ano Invalido \n");
    }while(!(price > 0));
    return price;
}

void getDataClient (long int *cedToFind) {
    scanf("%li",&cedToFind);
}

void validatePath(char myPath[dim]){
    printf("Recuerda que la foto debe ser añadido manualmente al directorio ./public\n");
    do {
        printf("Ingrese el nombre de la Imagen: ");
        scanf(" %[^\n]", myPath);
        if(!validarPathBool(myPath))
            printf("[-] Ruta no válida\n");
    }while(!validarPathBool(myPath));  
}
int valiateMonths(){
    int val;
    do{
        printf("Ingresa los meses en los que se entregará el auto: ");
        scanf("%i",&val);
        if(!(val > 0 && val <= 24))
            printf("[-] Cantidad de meses inválida \n");
    }while(!(val > 0 && val <= 24));
    return val;
}
