#include <iostream>
#include <string.h>
#define TAM 100
using namespace std;


typedef struct{
    char materia[20];
    int notaFinal;
}tipoNotas;



typedef struct{
    int ci;
    char nom[50],sexo,direc[100];
    int cantidadNotas;
    tipoNotas notas[TAM];
}tipoKardex;



void leerNotas(tipoNotas notas[TAM],int n){

    for(int i=0;i<n;i++){
cout<<"Materia: "; cin>>notas[i].materia;
cout<<"nota final: "; cin>>notas[i].notaFinal;

}

}
void mostrarNotas(tipoNotas notas[TAM],int n){

    for(int i=0;i<n;i++){
cout<<"\nMateria: "; cout<<notas[i].materia;
cout<<"\nnota final: "; cout<<notas[i].notaFinal;

}

}

void leerKardex(tipoKardex &kardex){

cout<<"CI: "; cin>>kardex.ci;
cout<<"NOMBRE : "; cin>>kardex.nom;
cout<<"SEXO : "; cin>>kardex.sexo;
cout<<"DIRECCION : "; cin>>kardex.direc;
cout<<"CANTIDAD DE NOTAS  : "; cin>>kardex.cantidadNotas;
cout<<"notas : "; leerNotas(kardex.notas,kardex.cantidadNotas);

}

void leerListaKardex(tipoKardex listaDeKardex[TAM],int n){
for(int i=0;i<n;i++){
cout<<"kardex "<<i<<" : ";
leerKardex(listaDeKardex[i]);
}
}

void mostrarKardex(tipoKardex kardex){

cout<<"\nCI: "; cout<<kardex.ci;
cout<<"\nNOMBRE : "; cout<<kardex.nom;
cout<<"\nSEXO : "; cout<<kardex.sexo;
cout<<"\nDIRECCION : "; cout<<kardex.direc;
cout<<"\nCANTIDAD DE NOTAS  : "; cout<<kardex.cantidadNotas;
cout<<"\nnotas : "; mostrarNotas(kardex.notas,kardex.cantidadNotas);
cout<<endl;

}

void mostrarListaKardex(tipoKardex listaDeKardex[TAM],int n){
    for(int i=0;i<n;i++){
cout<<"kardex "<<i<<" : ";
mostrarKardex(listaDeKardex[i]);
}
}

void buscarCI(tipoKardex listaKardex[TAM],int nkardex,int carnet){
for(int i=0;i<nkardex;i++){

    if(carnet==listaKardex[i].ci){
        mostrarNotas(listaKardex[i].notas,listaKardex[i].cantidadNotas);
    }
}
}
int calcularPromedio(tipoNotas notas[TAM],int num){
int promedio;
int suma=0;
for(int i=0;i<num;i++){

    suma=suma+notas[i].notaFinal;
}
promedio=suma/num;
return promedio;
}

void mostrarPromedio(tipoKardex kardex){


cout<<"\nALUMNO : "; cout<<kardex.nom;

cout<<"\nPROMEDIO : "<<calcularPromedio(kardex.notas,kardex.cantidadNotas)<<endl;
cout<<endl;

}

void mostrarPromedios(tipoKardex listaDeKardex[TAM],int n){
    for(int i=0;i<n;i++){
cout<<"kardex "<<i<<" : ";
mostrarPromedio(listaDeKardex[i]);
}
}

int obtenerAprobados(tipoKardex listaKardex[TAM],int nKardex,char materia[TAM] ){
    int contador=0;
    for(int i=0;i<nKardex;i++){


if(strcmp(listaKardex[i].notas[i].materia,materia)==0){
        for(int j=0;i<listaKardex[i].cantidadNotas;j++){

    if(calcularPromedio(listaKardex[j].notas,listaKardex[j].cantidadNotas)>50){
        contador++;
    }
}
}

    }

    return contador;
}

void mostrarAprobacionesReprobaciones(tipoKardex listaKardex[TAM],int nKardex){
int aprobaciones=0,reprobaciones=0;
for(int i=0;i<nKardex;i++){
        cout<<listaKardex[i].nom<<" : "<<endl;

    for(int j=0;j<listaKardex[i].cantidadNotas;j++){
    if(calcularPromedio(listaKardex[j].notas,listaKardex[j].cantidadNotas)>50){
        aprobaciones ++;
    }
    else
        reprobaciones++;
        }
        cout<<"aprobo "<<aprobaciones<<" y reprobo "<<reprobaciones<<endl;
}

}

int main()
{
    int nkardex;
    int carnet;
    char materia[TAM];
    tipoKardex listaKardex[TAM];
    cout<<" cuantos kardex ";cin>>nkardex;
    leerListaKardex(listaKardex,nkardex);
cout<<"LO QUE INGRESASTE ES "<<endl;
cout<<endl;
    mostrarListaKardex(listaKardex,nkardex);

    cout<<"ingrese un carnet a buscar "; cin>>carnet;
    buscarCI(listaKardex,nkardex,carnet);
    cout<<endl;

    cout<<"PROMEDIOS "<<endl;
    mostrarPromedios(listaKardex,nkardex);

     cout<<"INGRESE UNA MATERIA PARA VER SUS APROBADOS "<<endl;
     cin>>materia;
     cout<<"LA CANTIDAD DE APROBADOS EN LA MATERIA DE "<<materia<<" es : ";
     obtenerAprobados(listaKardex,nkardex,materia);
     cout<<endl;

     cout<<"cantidad de reprobaciones y aprobaciones de cada alumno "<<endl;
mostrarAprobacionesReprobaciones(listaKardex,nkardex);




    return 0;
}
