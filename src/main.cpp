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
    char color[stringSize];
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
        if(myCed == ){

        }
    }
    return true;
}

void printUser(Client client){
    printf("Cedula: %li", client.id);
    printf("Nombre: %s", client.fullName);
    printf("Telefono: %s", client.cellPhoneNumber);
    printf("Direccion:  %s", client.direction);
    printf("Email: %s", client.email);
}

int usersNum(){
    int counter = 0;
    ifstream reader("./db/Users.txt", ios::in);
    while (!reader.eof()) {
        counter++;    
    }
    reader.close();    
    return counter;
}

bool seeUsers(char myCed[stringSize]){
    int counter = 0;
    ifstream reader("./db/Users.txt", ios::in);
    while (!reader.eof()) {
        counter++;    
    }
    
    reader.close();
    char Nom[stringSize];
}

/*bool hasAlreadyExist(string id_ced){
    ifstream myRead("./db/Users.txt");
    string Name;
    string Ced;
    string LastName;
    myRead >> Name;
    while(!myRead.eof()){
        myRead>>
    }
}*/


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
                goodBye();
                break;
            case 13:
                goodBye();
                break;
            default:
                
            break;
        }
    }while(option != 13);
}

int main(){
    hasAlreadyExist();
    welcome();
    branch();
    menu();
    return 0;
}

