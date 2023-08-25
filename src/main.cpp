#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ios>
#include <ostream>
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include<iostream>
#include<fstream>
#include <string>
#include "headers/funs.h"
#include "headers/validation.h"

using namespace std;

#define stringSize 100

struct CarProperties{
    char model[stringSize];
    int year;
    double price;
    char photo[stringSize];
};


struct Car{
    int id;
    CarProperties car;
};



struct Client{
    long int id; 
    char fullName[stringSize];
    char email[stringSize];
    char direction[stringSize];
    char cellPhoneNumber[stringSize];
};

struct Sell{
    int id;
    int monthsToDelivery;
    float totalTaxes;
    Client dataClient;
    Car dataCar;
};


void seeUsers(){
    int counter = 0;
    Client client;

    string cedula, Name, LastName, email, mobile, direction; 
    ifstream reader("./db/Users.txt", ios::in);
    while (!reader.eof()) {
        reader >> cedula;
        reader >> Name;
        reader >> LastName;
        reader >> email;
        reader >> mobile;
        reader >> direction;
        if(cedula == ""){
            printf("[-] No hay informacion para mostrar");
        } else {
            printf("*************************************** \n");
            cout << "*\tCedula: " << cedula <<  "            *\n";
            printf("***************************************\n");
            cout << "Nombre: " << Name <<  LastName<<"\n";
            cout << "Telefono: " << mobile <<  "\n";
            cout << "Direccion: " << direction <<  "\n";
            cout << "Email: " << email <<  "\n";
        }
    }
    reader.close();
}

void printAllSales(){
    string id, comprador, modelo, precio, impuestos, meses; 
    ifstream reader("./db/Salles.txt", ios::in);
    while (!reader.eof()) {
        reader >> id;
        reader >> comprador;
        reader >> modelo;
        reader >> precio;
        reader >> impuestos;
        reader >> meses;
        if(id == ""){
            printf("[-] No hay informacion para mostrar");
        } else {
            printf("*************************************** \n");
            cout << "*\tCedula: " << id <<  "            *\n";
            printf("***************************************\n");
            cout << "-> Cédula del cliente: " << comprador <<"\n";
            cout << "-> Modelo: " << modelo <<  "\n";
            cout << "-> Precio: " << precio <<  "\n";
            cout << "IVA(12%):  " << impuestos<<  "\n";
            cout << "->Total:   " << std::stoi(precio) +std::stoi(impuestos) <<  "\n";  
        }
    }
}





void openImage(char path[]){
    char filePath[] = "./public/";
    strcat(filePath, path);
    system(filePath);
}


void seeCars(){
    int counter = 0;
    Client client;

    string id,Name,  year, cost, path; 
    ifstream reader("./db/Cars.txt", ios::in);
    while (!reader.eof()) {
        reader >> id;
        reader >> Name;
        reader >> year;
        reader >> cost;
        reader >> path;
        if(id == ""){
            printf("[-] No hay informacion para mostrar");
        } else {
            printf("*************************************** \n");
            cout << "*\t" << id << ". "<< Name <<  "            *\n";
            printf("***************************************\n");
            cout << "Año: " << year <<  "\n";
            cout << "Cost: " << cost <<  "\n";
        }
    }
    reader.close();
}





void inClient(){
    Client client;
    ofstream myFile;
    char name[stringSize], email[stringSize], direction[stringSize], cellNumber[stringSize];
    client.id = validateCed();
    validateName(client.fullName);
    validateEmail(client.email);
    validateDirecction(client.direction);
    validateMobile(client.cellPhoneNumber);
    myFile.open("./db/Users.txt", ios::out | ios::app);
    myFile<<client.id<<" "<<client.fullName<<" "<<client.email<<" "<< client.cellPhoneNumber<<" "<<client.direction<<" "<<endl;
    myFile.close();
    system("clear");
}


void inNewCar(Car * car){
    car->id = randomNum();
    ofstream myFile;
    do{
        printf("Ingrese el modelo: ");
        scanf(" %[^\n]",car->car.model);
        if (hasAlreadyExistCar(car->car.model))
            printf("El modelo Ya está registrado");
    }while(hasAlreadyExistCar(car->car.model));
    car->car.year =  validateYearCar();
    car->car.price = validatePrice();
    validatePath(car->car.photo);
    myFile.open("./db/Cars.txt", ios::out | ios::app);
    myFile<<car->id<<" "<<car->car.model<<" "<< car->car.price<<" "<< car->car.photo<<endl;
    myFile.close();
    system("clear");
}

void inNewSell(Sell *sell){
    ofstream myFile;
    sell->id = randomNum();
    sell->monthsToDelivery = valiateMonths();
    do{
        printf("Ingresa la cedula del cliente: ");
        scanf("%li",&sell->dataClient.id);
        if(!hasAlreadyExist(std::to_string(sell->dataClient.id)))
            printf("[-] El cliente no ha sido encontrado\n");
    }while(!hasAlreadyExist((std::to_string(sell->dataClient.id))));

    do{
        printf("Ingresa el modelo del auto: ");
        scanf(" %[^\n]",sell->dataCar.car.model);
        if(!hasAlreadyExistCar(sell->dataCar.car.model))
            printf("[-] El modelo no ha sido encontrado\n");
    }while(!hasAlreadyExistCar(sell->dataCar.car.model));
    sell->dataCar.car.price = carPrice(sell->dataCar.car.model);
    sell->totalTaxes = makeTaxes(sell->dataCar.car.price);
    myFile.open("./db/Salles.txt", ios::out | ios::app);
    myFile<<sell->id<<" "<<sell->dataClient.id<<" "<< sell->dataCar.car.model<<" "<< sell->dataCar.car.price<<" "<< sell->totalTaxes <<" "<< sell->monthsToDelivery<< endl;
    myFile.close();
    system("clear");
}



void findClient(){
    long int ced;
    system("clear");
    do{
        printf("Ingrese la cedula del cliente que desea buscar o ingrese 8 para salir: ");
        scanf("%li",&ced);
        if(ced == 8){
            printf("Volviendo al menu principal....\n");
            break;
        }
        if (!hasAlreadyExistPrint(std::to_string(ced)))
            printf("[-] No se ha encontrado al cliente \n");
    }while(!hasAlreadyExist(std::to_string(ced)) && ced == 8);
}

void findCar(){
    string modelToFind;
    system("clear");
    do{
        printf("Ingrese el modelo del auto que desea buscar o ingrese 8 para salir: ");
        cin>>modelToFind;
        if(modelToFind == "8"){
            printf("Volviendo al menu principal....\n");
            break;
        }
        if (hasAlreadyExistCarPrint(modelToFind))
            printf("[-] No se ha encontrado al auto \n");
    }while(!hasAlreadyExistCar(modelToFind) || modelToFind != "8");
}

void deleteCed(string cedToDelete){
    ifstream myRead;
    string cedula, Name, LastName, email, mobile, city;
    
    myRead.open("./db/Users.txt");
    ofstream aux("./db/auxiliciar.txt",ios::out);

    while(!myRead.eof()){
        myRead >> cedula;
        myRead >> Name;
        myRead >> LastName;
        myRead >> email;
        myRead >> mobile;
        myRead >> city;
        if(!(cedula == cedToDelete)){
            aux<<cedula<<" "<<Name<<" "<<LastName<<" "<< email<<" "<<mobile<<" "<<city<<" "<<endl;
        }
    }
    myRead.close();
    aux.close();
    remove("./db/Users.txt");
    rename("./db/auxiliciar.txt","./db/Users.txt");

}

void modifyModel(string myModel){
    ifstream myRead;
    string id, Model, year, price, path;
    
    myRead.open("./db/Cars.txt");
    ofstream aux("./db/auxiliciar.txt",ios::out);
    int yearAux = validateYearCar();
    float priceAux = validatePrice();
    char  pathAux[stringSize];
    validatePath(pathAux);


    while(!myRead.eof()){
        myRead >> id;
        myRead >> Model;
        myRead >> year;
        myRead >> price;
        myRead >> path;

        if(!(Model == myModel)){
            
            aux<<id<<" "<<Model<<" "<<year<<" "<< price<<" "<<path<<endl;
        }else {
            aux<<id<<" "<<Model<<" "<<yearAux<<" "<< priceAux<<" "<<pathAux<<endl;
        }
    }
    myRead.close();
    aux.close();
    remove("./db/Cars.txt");
    rename("./db/auxiliciar.txt","./db/Cars.txt");
}

void modifyCed(string cedToDelete){
    ifstream myRead;
    string cedula, Name, LastName, email, mobile, city;
    int opt;
    
    myRead.open("./db/Users.txt");
    ofstream aux("./db/auxiliciar.txt",ios::out);
    char NameAux[stringSize], emailAux[stringSize],directionAux[stringSize],mobileAux[stringSize];



    //TODO



    
    validateName(NameAux);
    validateEmail(emailAux);
    validateDirecction(directionAux);
    validateMobile(mobileAux);

    while(!myRead.eof()){
        myRead >> cedula;
        myRead >> Name;
        myRead >> LastName;
        myRead >> email;
        myRead >> mobile;
        myRead >> city;
        if(!(cedula == cedToDelete)){
            aux<<cedula<<" "<<Name<<" "<<LastName<<" "<< email<<" "<<mobile<<" "<<city<<" "<<endl;
        }else {
            aux<<cedula<<" "<<NameAux<<" "<< emailAux<<" "<<mobileAux<<" "<<directionAux<<" "<<endl;
        }
    }
    myRead.close();
    aux.close();
    remove("./db/Users.txt");
    rename("./db/auxiliciar.txt","./db/Users.txt");

}





void deleteModel(string myModel){
    ifstream myRead;
    string id, Model, year, price, path;
    
    myRead.open("./db/Cars.txt");
    ofstream aux("./db/auxiliciar.txt",ios::out);

    while(!myRead.eof()){
        myRead >> id;
        myRead >> Model;
        myRead >> year;
        myRead >> price;
        myRead >> path;

        if(!(Model == myModel)){
            
            aux<<id<<" "<<Model<<" "<<year<<" "<< price<<" "<<path<<endl;
        }
    }
    myRead.close();
    aux.close();
    remove("./db/Cars.txt");
    rename("./db/auxiliciar.txt","./db/Cars.txt");
}


void deleteUser(){
    long int ced;
    do{
        printf("Ingrese la cédula del usuario que desea eliminar, o ingrese 8 para salir\n");
        scanf("%li",&ced);
        if(ced == 8)
            return;
        if(!hasAlreadyExist(std::to_string(ced)) )
            printf("[-] No se encontró la cédula Ingresada");
    }while(!hasAlreadyExist(std::to_string(ced)));

    deleteCed(std::to_string(ced));
}

void deleteCar(){
    string myModel;
    do{
        printf("Ingrese el modelo de auto que desea eliminar, o ingrese 8 para salir\n");
        cin>>myModel;
        if(myModel == "8")
            return;
        if(!hasAlreadyExistCar(myModel ))
            printf("[-] No se encontró el modelo Ingresado\n");
    }while(!hasAlreadyExistCar(myModel));

    deleteModel(myModel);
}

void modifyCar(){
    string myModel;
    do{
        printf("Ingrese el modelo de auto que desea eliminar, o ingrese 8 para salir\n");
        cin>>myModel;
        if(myModel == "8")
            return;
        if(!hasAlreadyExistCar(myModel ))
            printf("[-] No se encontró el modelo Ingresado\n");
    }while(!hasAlreadyExistCar(myModel));
    modifyModel(myModel);
    //deleteModel(myModel);

}

void modifyUser(){
    long int ced;
    do{
        printf("Ingrese la cédula del usuario que desea modificar, o ingrese 8 para salir\n");
        scanf("%li",&ced);
        if(ced == 8)
            return;
        if(!hasAlreadyExist(std::to_string(ced)) )
            printf("[-] No se encontró la cédula Ingresada");
    }while(!hasAlreadyExist(std::to_string(ced)));
    modifyCed(std::to_string(ced));
}

void menu(){
    int option;
    Client client;
    Car car;
    Sell sell;
    ofstream myFyle;
    int carOptionView;
    string modelToView;
    do {
        printMenu();
        scanf("%i",&option);
        switch (option) {
            case 1: //New Client DONE
                system("clear");
                inClient();
                break;

            case 2: // Nuevo Auto DONE
                inNewCar(&car);
                break;

            case 3: // New Sell DONE
                system("clear");
                inNewSell(&sell);
                break;

            case 4: // Modificar Informacion de un auto // DONE
                system("clear");
                modifyCar();
                break;

            case 5: //Modificar Informacion de un cliente //DONE
                system("clear");
                modifyUser();
                break;
            
            case 6: //Modificar Informacion de la venta
                system("clear");
                break;

            case 7: //See All clients DONE
                system("clear");
                seeUsers();
                break;
            
            case 8: //See All Cars DONE
                system("clear");
                seeCars();
                break;

            case 9: //Find Client Info DONE
                system("clear");
                findClient();
                break;
            
            case 10: //Find Car Info DONE
                system("clear");
                findCar();
                break;

            case 11: //Delete user DONE
                system("clear");
                deleteUser();
                break;
            
            case 12: //Delete car DONE
                system("clear");
                deleteCar();
                break;

            case 13:
                printAllSales();
                break;

            case 0: //DONE
                goodBye();
                break;
            
            default: //DONE
                printf("La opcion que Ingresaste no existe\n");                
                break;
        }
    }while(option != 0);
}

int main(){
    system("clear");
    welcome();
    branch();
    menu();
    return 0;
}

