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

bool hasAlreadyExist(char myCed[stringSize]){
    ifstream reader("./db/Users.txt", ios::in);
    char Nom[stringSize];
    reader >> Nom;
    printf("%s", Nom);
    while(!reader.eof()){
        reader >> Nom;
//        if(myCed == ){

  //      }
    }
    return true;
}

int usersNum(){
    Client client;
    int counter = 0;
    ifstream reader("./db/Users.txt", ios::in);
    while (!reader.eof()) {

    }
    reader.close();    

    return counter;
}

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
    printf("Ingrese el modelo: ");
    scanf(" %[^\n]",car->car.model);
    car->car.year =  validateYearCar();
    printf("Ingrese el color: ");
    scanf(" %[^\n]",car->car.model);
    car->car.price = validatePrice();
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

void menu(){
    int option;
    Client client;
    Car car;
    Sell sell;
    ofstream myFyle;
    do {
        printMenu();
        scanf("%i",&option);
        switch (option) {
            case 1:
                system("clear");
                inClient();
                break;

            case 2:
                inNewCar(&car);
                break;
            case 3:
                inNewSell(&sell);
                break;

            case 7:
                system("clear");
                seeUsers();
                break;

            case 9:
                system("clear");
                findClient();
                break;
            case 13:
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

