#include <cstdlib>
#include <cstring>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>

void welcome(){
    printf("\t\t**********************************\n");
    printf("\t\t|    Bienvenido a G.I.S Motors     |\n");
    printf("\t\t**********************************\n");
}

void branch(){
    printf("\n        GGGGGGGGGGGGGIIIIIIIIII   SSSSSSSSSSSSSSS\n     GGG::::::::::::GI::::::::I SS:::::::::::::::S\n   GG:::::::::::::::GI::::::::IS:::::SSSSSS::::::S\n  G:::::GGGGGGGG::::GII::::::IIS:::::S     SSSSSSS\n G:::::G       GGGGGG  I::::I  S:::::S            \nG:::::G                I::::I  S:::::S            \nG:::::G                I::::I   S::::SSSS         \nG:::::G    GGGGGGGGGG  I::::I    SS::::::SSSSS    \nG:::::G    G::::::::G  I::::I      SSS::::::::SS  \nG:::::G    GGGGG::::G  I::::I         SSSSSS::::S \nG:::::G        G::::G  I::::I              S:::::S\n G:::::G       G::::G  I::::I              S:::::S\n  G:::::GGGGGGGG::::GII::::::IISSSSSSS     S:::::S\n   GG:::::::::::::::GI::::::::IS::::::SSSSSS:::::S\n     GGG::::::GGG:::GI::::::::IS:::::::::::::::SS \n        GGGGGG   GGGGIIIIIIIIII SSSSSSSSSSSSSSS        Motors\n\n\n\n");
}

void printMenu(){
    //Create
    printf("1. Ingresar nuevo cliente\n");
    printf("2. Ingresar un nuevo auto\n");
    printf("3. Registrar un nueva venta \n");
    //Update
    printf("4. Modificar Informacion de un Auto\n");
    printf("5. Modificar Informacion de un Cliente\n");
    printf("6. Modificar Informacion de la venta\n");
    //Read
    printf("7. Ver todos los clientes\n");
    printf("8. Ver todos los autos \n");
    printf("9. Buscar Cliente\n");
    printf("10.Buscar auto\n");
    printf("11.Eliminar Cliente\n");
    printf("12.Eliminar Auto\n");
    printf("13.Ver Ventas\n");
    printf("0.Salir\n");


    printf("Ingresa una opcion: ");
}

void menuClient(){
    printf("Que dato desea cambiar\n");
    printf("1. Nombre\n");
    printf("2. Correo\n");
    printf("3. Dirección\n");
    printf("4. Numero de telefono\n");
    printf("5. Salir\n");
}

void goodBye(){
    printf("Gracias por usar el sistema ;) \n");
}

void defaultOption(){
    printf("[-] La opcion que ingresaste no existe \n");
}

void seePhoto(char route[]){
    char command[100] = "xdg-open ./public/";
    strcat(command, route);
    system(command);
}

int randomNum(){
   int maximo=99999;
   int minimo=0;
   int numero_aleatorio;
   srand(time(NULL));
   numero_aleatorio = minimo + rand() % (maximo - minimo + 1);
   return (numero_aleatorio);
}

float makeTaxes(float value){
    return (value * 0.12);
}

