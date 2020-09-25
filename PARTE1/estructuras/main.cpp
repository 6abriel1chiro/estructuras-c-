#include <iostream>
#include <conio.h>
#include <windows.h>

#define COLORNORMAL 7
using namespace std;
void gotoxy(short x, short y)
{
   COORD pos = { x, y };
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void color(WORD col)
{
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),col);
}


typedef struct{

    int posicionx,posiciony,dimension,color;
    char caracterDibujo, codigo;




}tipoFigura;

void dibujaLineaHorizontal(tipoFigura figura)
//dibuja una linea con el car de un tamanio del color pintura, a partir de la posx,posy
{
    color(figura.color);
    for (int i=0;i<figura.dimension;i++)
    {
        gotoxy(figura.posicionx+i,figura.posiciony);
        cout<<figura.caracterDibujo;

    }
    color(COLORNORMAL);
}

void mostrarFigura(tipoFigura figura){

if(figura.codigo=='c'){
    for(int i = 0;i<figura.dimension;i++){
        gotoxy(figura.posicionx,figura.posiciony);
        for(int j = 0;j<figura.dimension;j++){
            cout<<figura.caracterDibujo<<" ";


    }
     figura.posiciony++;

    }
}

if(figura.codigo=='t'){

    //color(figura.color);
    for(int i = 1; i <= figura.dimension;i++)
    {
        gotoxy(figura.posicionx,figura.posiciony);
        for(int j = 1; j <= i;j++)
        {
            cout <<figura.caracterDibujo<<" ";
        }
        figura.posiciony++;
        //cout << "\n";
    }
}
if(figura.codigo=='r'){

    for(int i = 0;i<figura.dimension;i++){
            gotoxy(figura.posicionx,figura.posiciony);
        for(int j = 0;j<figura.dimension+1;j++){
            cout<<figura.caracterDibujo<<" ";


       }
       figura.posiciony++;
         //cout<<endl;

    }

}
if(figura.codigo=='o'){
int i,j,k;
for (i = 1; i <= figura.dimension; i++)

    {

          for (j = 0; j < (figura.dimension - i); j++)

            cout << " ";

          for (j = 1; j <= i; j++)
            gotoxy(figura.posicionx,figura.posiciony);
            cout << figura.caracterDibujo;

          for (k = 1; k < i; k++)

               cout << figura.caracterDibujo;
            figura.posiciony++;
          //cout << "\n";

    }



    for (i = figura.dimension - 1; i >= 1; i--)

    {

          for (j = 0; j < (figura.dimension - i); j++)

                cout << " ";

          for (j = 1; j <= i; j++)
                gotoxy(figura.posicionx,figura.posiciony);
                cout << figura.caracterDibujo;

          for (k = 1; k < i; k++)

                cout << figura.caracterDibujo;
            figura.posiciony++;
          //cout << "\n";

    }
    figura.posiciony++;
    //cout << "\n";
}


}


void borrarFigura(tipoFigura figura)
{
   for (int i=0;i<figura.dimension;i++)
    {
        dibujaLineaHorizontal(figura);
        figura.posiciony++;
    }

}
int main()
{

    tipoFigura cuadrado={0,0,4,0,'*','c'};
    tipoFigura triangulo={20,0,4,0,'*','t'};
    tipoFigura rectangulo={40,0,4,0,'*','r'};
    tipoFigura rombo={60,0,4,0,'*','o'};
    mostrarFigura(cuadrado);
    cout<<endl;
    mostrarFigura(triangulo);
    cout<<endl;
    mostrarFigura(rectangulo);
    cout<<endl;
    mostrarFigura(rombo);


    return 0;
}
