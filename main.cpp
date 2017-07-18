#include <iostream>
#include <cstring>
using namespace std;

bool fnd(){

}

int main() {

    int nroElementosDelAlfabeto;
    int nroEstados;
    int i;

    cout<<"\t\t\t AFD "<<endl;

    cout<< " Ingrese nro de Elementos del Alfabeto : ";
    cin>> nroElementosDelAlfabeto;
    cout<<endl;

    char alfabeto [nroElementosDelAlfabeto];

    cout<< " Ingrese Alfabeto "<<endl;
    for(i = 0; i < nroElementosDelAlfabeto ; i++){
        cout<<"\t Dato #"<<i+1<<" : ";
        cin>> alfabeto[i];
    }

    cout<<endl;
    cout<< " Ingrese nro de Estados : ";
    cin>> nroEstados;

    cout<<"\t ";
    for(i = 0; i < nroEstados ; i++){
        cout<<"q"<<i;
        if(i != nroEstados -1 ){
            cout<<" - ";
        }
    }

    char transiciones [nroEstados][nroEstados];

    cout<<endl<<endl;
    cout<< " Transiciones : ";
    bool band = true;
    bool verificar = false;
    char respuesta;
    int estadoInicial;
    int estadoFinal;
    char dato;

    cout<<endl;
    while(band){
        cout<< " Estado Inicial : ";
        cin>>estadoInicial;
        cout<< " Estado Termino : ";
        cin>>estadoFinal;
        cout<< " Dato           : ";
        cin>>dato;
        cout<<endl;

        /* verificar los datos ingresados si existen*/
        if( estadoInicial < nroEstados && estadoFinal < nroEstados){
            verificar = true;
        }else{
            verificar = false;
        }

        if(verificar){
            for( i = 0; i < nroElementosDelAlfabeto ; i++){
                if( alfabeto[i] == dato ){
                    verificar = true;
                    break;
                }else{
                    verificar = false;
                }
            }
        }

        if(verificar){
            transiciones[estadoInicial][estadoFinal] = dato;
        }else{
            cout<< " Existen datos incorrectos";
        }

        cout<<endl;
        cout<< " Ingresar otra transicion mas ? Y/N : ";
        cin>> respuesta;


        if(respuesta == 'Y' || respuesta == 'y'){
            band = true;
        }else{
            band = false;
        }
        cout<<endl;
    }

    cout<<" Estado Inicial del Automata : ";
    cin>>estadoInicial;
    cout<<endl;

    int nroEstadosFinales;

    cout<< " Nro de Estados finales : ";
    cin>>nroEstadosFinales;

    int estadosFinales[nroEstadosFinales];

    for( i = 0; i < nroEstadosFinales ; i++){
        cout<<" Estado final #"<<i+1<<" : ";
        cin>>estadosFinales[i];
    }

    bool preguntar = true;

    while(preguntar){

        char cadena[30];
        cout<<endl;
        cout<< " Ingrese Cadena a probar : ";
        cin>>cadena;

        /* inicio del algoritmo*/

        band = true;
        int estado = estadoInicial;
        i = 0;
        int j;





        cout<<endl;
        cout<< " Realizar otra consulta ? Y/N : ";
        cin>> respuesta;


        if( respuesta == 'Y' || respuesta == 'y'){
            preguntar = true;
        }else{
            preguntar = false;
        }
        cout<<endl;
    }


    return 0;
}
