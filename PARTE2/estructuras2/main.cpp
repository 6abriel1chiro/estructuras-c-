#include <iostream>
#define TAM 100
using namespace std;

typedef struct {
int day;
int month;
int year;

}tipoFecha;
typedef struct {
int hour;
int minute;
int sec;

}tipoHora;

typedef struct {
string  descripcion;
tipoFecha fecha;
tipoHora horaInicial;
tipoHora horaFinal;
char estado ; // P o R

}tipoActividad;

void leerFecha(tipoFecha &date){
    cout<<"fecha "<<endl;

cin>>date.day>>date.month>>date.year;
}
void leerFechas(tipoFecha date[TAM],int tam){
for(int i=0;i<tam;i++){

leerFecha(date[i]);

}
}
void mostrarFecha(tipoFecha date){
cout<<date.day<<" / "<<date.month<<" / "<<date.year<<endl;
}
void mostrarFechas(tipoFecha date[TAM],int tam){
for(int i=0;i<tam;i++){

mostrarFecha(date[i]);

}
}
bool esFechaValida(tipoFecha fecha)
{
int dias_mes[] = {31, 28, 31, 30,31, 30, 31, 31, 30, 31, 30, 31};
    //Comprobar si el ano es bisiesto y anadir dia en febrero en caso afirmativo
    if((fecha.year%4 == 0 and fecha.year%100 != 0) or fecha.year%400 == 0)
        dias_mes[1]++;

    //Comprobar que el mes sea valido
    if(fecha.month < 1 or fecha.month > 12)
        return false;

    //Comprobar que el dia sea valido
    fecha.month = fecha.month-1;
    if(fecha.day <= 0 or fecha.day > dias_mes[fecha.month])
        return false;

    //Si ha pasado todas estas condiciones, la fecha es valida
    return true;
}
bool esFechaMayor(tipoFecha f1,tipoFecha f2){
bool esMayor=false;
if((f1.year>f2.year) or (f1.year==f2.year and f1.month>f2.month) or (f1.year==f2.year and f1.month==f2.month and f1.day>f2.day))
esMayor=true;

    return esMayor;

}

void ordenarFechas(tipoFecha fecha[TAM] ,int nfechas){
    tipoFecha fechaMayor={0,0,0};
    for(int i = 0;i<nfechas;i++){
             for(int j = i+1;j<nfechas;j++){
                if(esFechaMayor(fecha[i],fecha[j])){
            fechaMayor=fecha[i];
            fecha[i]=fecha[j];
            fecha[j]=fechaMayor;
            }

        }


    }
}


void leerHora(tipoHora &hora){
cout<<"hora "<<endl;
cin>>hora.hour>>hora.minute>>hora.sec;
}
void mostrarHora(tipoHora hora){
cout<<hora.hour<<" : "<<hora.minute<<" : "<<hora.sec<<endl;
}


 tipoActividad leerActividad(tipoActividad &actividad){
 cout<<" descripcion "<<endl;
 cin>>actividad.descripcion;
  cout<<" fecha "<<endl;
 leerFecha(actividad.fecha);
  cout<<" hora de inicio  "<<endl;
 leerHora(actividad.horaInicial);
  cout<<" hora de conlusion  "<<endl;
 leerHora(actividad.horaFinal);
  cout<<" estado  "<<endl;
 cin>>actividad.estado;
return actividad;
 }

 void leerActividades(tipoActividad actividad[TAM],int tam){
for(int i=0;i<tam;i++){

leerActividad(date[i]);

}
}
 void mostrarActividad(tipoActividad actividad){

     cout<<" descripcion "<<endl;
 cout<<actividad.descripcion;
  cout<<" fecha "<<endl;
 mostrarFecha(actividad.fecha);
  cout<<" hora de inicio  "<<endl;
 mostrarHora(actividad.horaInicial);
  cout<<" hora de conlusion  "<<endl;
mostrarHora(actividad.horaFinal);
  cout<<" estado  "<<endl;
 cout<<actividad.estado;


}
void mostrarActividades(tipoActividad actividad[TAM],int tam){
for(int i=0;i<tam;i++){

mostrarActividad(date[i]);

}
}

void ordenarActividades(tipoActividad actividad[TAM] ,int n){
    tipoActividad actividad={0,0,0};
    for(int i = 0;i<nfechas;i++){
             for(int j = i+1;j<nfechas;j++){
                if(esFechaMayor(fecha[i],fecha[j])){
            fechaMayor=fecha[i];
            fecha[i]=fecha[j];
            fecha[j]=fechaMayor;
            }

        }


    }
}
////////////////3
typedef struct{
tipoFecha fechaNacimiento;
tipoFecha fechaIngreso;
string nombre;
char sexo; // H,M

}tipoEmpleado;

void leerEmpleado(tipoEmpleado &empleado){
cout<<"fecha de nacimiento "; leerFecha(empleado.fechaNacimiento);
cout<<"fecha de ingreso "; leerFecha(empleado.fechaIngreso);
cout<<"nombre ";cin>>empleado.nombre;
cout<<"sexo: ";cin>>empleado.sexo;
}
void mostrarEmpleado(tipoEmpleado empleado){
cout<<"fecha de nacimiento ";mostrarFecha(empleado.fechaNacimiento);
cout<<"fecha de ingreso "; mostrarFecha(empleado.fechaIngreso);
cout<<"nombre ";cout<<empleado.nombre;
cout<<"sexo: ";cout<<empleado.sexo;

}

bool esMasJoven(tipoEmpleado empleado1,tipoEmpleado empleado2){

return true;
}
void mostrarMujeres(tipoEmpleado &empleado){

}
int main()
{
    int nfechas,nactividades;
    tipoFecha fechas[TAM];
    tipoActividad actividades[TAM];
    //// 1
    cout<<"cuantas fechas desea ingresar "; cin>>nfechas;
    leerFechas(fechas,nfechas);
    cout<<"fechas : "<<endl;
    mostrarFechas(fechas,nfechas);
    ordenarFechas(fechas,nfechas);
    cout<<"fechas ordenadas: "<<endl;
    mostrarFechas(fechas,nfechas);
    ///////////////2
    cout<<"cuantas Actividades desea ingresar "; cin>>nactividades;
    leerActividades(actividades,nactividades);
        cout<<"Actividades : "<<endl;
    mostrarActividades(fechas,nfechas);


    return 0;
}
