#include <iostream>

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
tipoFecha fecha;
tipoHora hora;

}tipoInstante;

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

void mostrarFecha(tipoFecha date){
cout<<date.day<<" / "<<date.month<<" / "<<date.year<<endl;
}

bool esFechaMayor(tipoFecha f1,tipoFecha f2){
bool esMayor=false;
if((f1.year>f2.year) or (f1.year==f2.year and f1.month>f2.month) or (f1.year==f2.year and f1.month==f2.month and f1.day>f2.day))
esMayor=true;

    return esMayor;

}

void leerHora(tipoHora &hora){
cout<<"hora "<<endl;
cin>>hora.hour>>hora.minute>>hora.sec;
}
void mostrarHora(tipoHora hora){
cout<<hora.hour<<" : "<<hora.minute<<" : "<<hora.sec<<endl;
}


void leerInstante(tipoInstante &instante){
cout<<"Instante "<<endl;
leerFecha(instante.fecha);
leerHora(instante.hora);
}

void mostrarInstante(tipoInstante instante){
mostrarFecha(instante.fecha);
mostrarHora(instante.hora);

}

bool esHoraValida(tipoHora hora)
{


    if(hora.minute < 0 or hora.minute >= 60 or hora.sec < 0 or hora.sec >= 60 or hora.hour < 0 or hora.hour >= 24)
        return false;


    //Si ha pasado todas estas condiciones, la fecha es valida
    return true;


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


void sumarSegundo(tipoHora &hora){
int aSegundos = hora.hour*3600+(hora.minute*60)+hora.sec;
aSegundos += 1;

hora.hour = aSegundos / 3600;
hora.minute = ((aSegundos /60)-(hora.hour*60));
hora.sec=(aSegundos-(hora.minute*60)-(hora.hour*3600));

}

bool esHoraMayor(tipoHora h1,tipoHora h2){
bool esMayor=false;
if((h1.hour>h2.hour) or (h1.hour==h2.hour and h1.minute>h2.minute) or (h1.hour==h2.hour and h1.minute==h2.minute and h1.sec>h2.sec))
esMayor=true;

    return esMayor;

}
/////////// 8 INSTANTES
bool esInstanteValido(tipoInstante instante){


    if(esFechaValida(instante.fecha) and esHoraValida(instante.hora))
        return true;
    else
        return false;

}


bool esInstanteMayor(tipoInstante instante1,tipoInstante instante2){
if(esHoraMayor(instante1.hora,instante2.hora))
        return true;

if(esFechaMayor(instante1.fecha,instante2.fecha))
return true;

// si ninguna se cumple ahi muere
return false;

}

void sumarAinstante(tipoInstante &instante, int n){
    for(int i = 0;i<n;i++)
sumarSegundo(instante.hora);

}


//// 9 ACTIVIDADES
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


bool esActividadMasCorta(tipoActividad actividad1, tipoActividad actividad2){


int horaInicial1ToSec = actividad1.horaInicial.hour*3600+(actividad1.horaInicial.minute*60)+actividad1.horaInicial.sec;
int horaInicial2ToSec = actividad2.horaInicial.hour*3600+(actividad2.horaInicial.minute*60)+actividad2.horaInicial.sec;

int horaFinal1ToSec = actividad1.horaFinal.hour*3600+(actividad1.horaFinal.minute*60)+actividad1.horaFinal.sec;
int horaFinal2ToSec = actividad2.horaFinal.hour*3600+(actividad2.horaFinal.minute*60)+actividad2.horaFinal.sec;

int diferencial1=horaFinal1ToSec-horaInicial1ToSec;
int diferencial2=horaFinal2ToSec-horaInicial1ToSec;

if(diferencial1>diferencial2)
    return true;
    else
    return false;


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
bool empezoPrimero(tipoActividad &actividad){

return true;
else
    return false;

}
bool terminoPrimero(tipoActividad &actividad){

return true;
else
    return false;

}
////////////////////////MAIN
int main()
{


    //fechas
        tipoFecha fecha;
    tipoHora hora;



    int nfechas;
    tipoFecha fechaMayor={0,0,0};
    cout<<"cuantas fechas va a ingresar? ";
    cin>>nfechas;
    for(int i = 0;i<nfechas;i++){

        leerFecha(fecha);
        if(!esFechaValida(fecha)){
                cout<<"flaco esta fecha no vale eh"<<endl;

        }
        if(i==0)
            fechaMayor=fecha;

        if(esFechaMayor(fecha,fechaMayor))
            fechaMayor=fecha;
    }
    cout<<"la  fecha mayor es ";
    mostrarFecha(fechaMayor);
    cout<<endl;

//horas
int k;

leerHora(hora);
if(!esHoraValida(hora)){
    cout<<"flaco esta hora no vale eh "<<endl;
}
cout<<"cuantos segundos desea aumentar? "; cin>>k;
cout<<endl;
for(int i=0;i<k;i++)
sumarSegundo(hora);



cout<<"Nueva hora"<<endl;
mostrarHora(hora);



// ejercicio 8 instantes
tipoInstante instante, instanteMayor,instanteDePrueba;
int nInstantes, segundos;


//if(esInstanteValido(instante))
//mostrarInstante(instante);
//else
//cout<<"flaco ese instante no vale "<<endl;




cout<<"cuantos instantes va a ingresar "<<endl; cin>>nInstantes;


for(int i = 0;i<nInstantes;i++){

        leerInstante(instante);
        if(!esInstanteValido(instante)){
                cout<<"flaco ese instante no vale eh"<<endl;

        }
        if(i==0)
        instanteMayor=instante;

        if(esInstanteMayor(instante,instanteMayor))
            instanteMayor=instante;
    }
    cout<<"el instante mayor es ";
    mostrarInstante(instanteMayor);


   cout<<"cuantos segundos va a aumentar "<<endl; cin>>segundos;
   leerInstante(instanteDePrueba);
    sumarAinstante(instanteDePrueba,segundos);
    mostrarInstante(instanteDePrueba);

//EJERCICIO 9 ACTIVIDAD

int numActividades;
tipoActividad actividad, actividadDeMenosTiempo;
cout<<"cuantas actividades va a ingresar "<<endl; cin>>numActividades;



for(int i = 0;i<numActividades;i++){
        leerActividad(actividad);
        if(i==0)
        actividadDeMenosTiempo=actividad;

        if(esActividadMasCorta(actividad,actividadDeMenosTiempo))
            actividadDeMenosTiempo=actividad;
}

cout<<"de todas las ingresadas, la actividad que toma menos tiempo es "<<endl;
mostrarActividad(actividadDeMenosTiempo);
//mostrarActividad(actividad1);
    return 0;
}
