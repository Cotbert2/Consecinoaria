#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <ios>
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
    long int id; //cedula
    char fullName[stringSize];
    char email[stringSize];
    char direction[stringSize];
    char cellPhoneNumber[stringSize];
};

struct Sell{
    int id;
    //date
    float totalTaxes;
    Client dataClient;
    Car dataCar;
};


void seeUsers(){
    int counter = 0;
    Client client;

    string cedula, Name, email, mobile, direction; 
    ifstream reader("./db/Users.txt", ios::in);
    while (!reader.eof()) {
        reader >> cedula;
        reader >> Name;
        reader >> email;
        reader >> mobile;
        reader >> direction;
        if(cedula == ""){
            printf("[-] No hay informacion para mostrar");
        } else {
            printf("*************************************** \n");
            cout << "*\tCedula: " << cedula <<  "            *\n";
            printf("***************************************\n");
            cout << "Nombre: " << Name <<  "\n";
            cout << "Telefono: " << mobile <<  "\n";
            cout << "Direccion: " << direction <<  "\n";
            cout << "Email: " << email <<  "\n";
        }
    }
    reader.close();
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
    sell->id = randomNum();
    getDataClient(&sell->dataClient.id);
}

void addNewUser (ofstream &myFile ){
    myFile.open("Users.txt", ios::out | ios::app);
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
        if (!hasAlreadyExistCarPrint(modelToFind))
            printf("[-] No se ha encontrado al auto \n");
    }while(!hasAlreadyExistCar(modelToFind) && modelToFind == "8");
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

            case 3: // New Sell
                inNewSell(&sell);
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
        

            case 13: //DONE
                goodBye();
                break;
            
            default:
                printf("La opcion que Ingresaste no existe");                
                break;
        }
    }while(option != 13);
}

int main(){
    system("clear");
    welcome();
    branch();
    menu();
    return 0;
}

