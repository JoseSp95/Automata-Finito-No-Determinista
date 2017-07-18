#include <iostream>
#include <cstring>
using namespace std;

int nroElementosDelAlfabeto;
int nroEstados;
char alfabeto [30];
char transiciones [30][30];
int estadosFinales[30];
int nroEstadosFinales;
char cadenaBuscada[30];

bool fnd(int estadoInicial, int contador){//cout<<endl<<"---Estado Inicial : "<<estadoInicial<<"  -- contador : "<<contador;
    int i,j;
    bool band;
    char letraBuscada = cadenaBuscada[contador];//cout<<endl<<"letra Bus : "<<letraBuscada;
    bool encontrada;
    for(i = 0; i < nroEstados ; i++){
        if( transiciones[estadoInicial][i] == letraBuscada ){//cout<<endl<<"Tran : "<<transiciones[estadoInicial][i]<<" i : "<<i<<" contador : "<<contador<<endl;
            if((strlen(cadenaBuscada)-1) == contador){
                band = false;
                for(j = 0; j < nroEstadosFinales && !band ; j++){
                    if(estadosFinales[j] == i){
                        band = true;
                    }
                }

                return band;
            }
            int envioContador = contador + 1;
            encontrada = fnd(i, envioContador);
            if(encontrada){
                return true;
            }
        }
    }
    return false;
}

int main() {

    int i;

    cout<<"\t\t\t AFD "<<endl;

    cout<< " Ingrese nro de Elementos del Alfabeto : ";
    cin>> nroElementosDelAlfabeto;
    cout<<endl;

    cout<< " Ingrese Alfabeto "<<endl;
    for(i = 0; i < nroElementosDelAlfabeto ; i++){
        cout<<"\t Dato #"<<i+1<<" : ";
        cin>> alfabeto[i];
    }

    //cout<<"Tamano del alfabeto : "<<strlen(alfabeto);

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

    cout<<endl<<endl;
    cout<< " Transiciones : ";
    bool band = true;
    bool verificar;
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

    cout<< " Nro de Estados finales : ";
    cin>>nroEstadosFinales;

    for( i = 0; i < nroEstadosFinales ; i++){
        cout<<" Estado final #"<<i+1<<" : ";
        cin>>estadosFinales[i];
    }

    bool preguntar = true;

    while(preguntar){


        cout<<endl;
        cout<< " Ingrese Cadena a probar : ";
        cin>>cadenaBuscada;

        /* inicio del algoritmo*/

        band = true;
        int estado = estadoInicial;
        i = 0;
        int j;

        bool encontrada = fnd(estado,i);

        if(encontrada){
            cout<<"CADENA ACEPTADA";
        }else{
            cout<<"CADENA RECHAZADA";
        }

        cout<<endl;
        cout<< " Realizar otra consulta ? Y/N : ";
        cin>> respuesta;


        if( respuesta == 'Y' || respuesta == 'y'){
            preguntar = true;
        }else{
            cout<<endl;
            cout<< " Seguro? Y/N : ";
            cin>>respuesta;
            if(respuesta == 'y'){
                preguntar = true;
            }else{
                preguntar = false;
            }

        }
        cout<<endl;
    }


    return 0;
}
