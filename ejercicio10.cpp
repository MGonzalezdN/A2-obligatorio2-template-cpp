#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;
int numeroDe (char letra, char* letrasAsignadas, int cantLetras){
    for (int i = 0; i < cantLetras; i++)
    {
        if(letrasAsignadas[i]==letra){
            return i;
        }
    }
    
}
long long transformarANum(string sumando, char* letrasAsignadas, int cantLetras){
    long long transformarANum=0;
    for(int i=sumando.length()-1;i>=0;i--){
        int posLetrasAsignadas=numeroDe(sumando[i], letrasAsignadas,cantLetras);
        for(int j=0;j<i;j++){
            posLetrasAsignadas=posLetrasAsignadas*10;
        }
        transformarANum+=posLetrasAsignadas;
        
    }
    return transformarANum;
}

// Funciones helper
bool esSolucion(char* letrasAsignadas, string*sumandos, int k) {
    string resultado=sumandos[k];
    long long suma=0;
    //me fijo si asigno todas las letras
    for(int i=0;i<10;i++){
        if(letrasAsignadas[i]=='a'){
            return false;
        }
    }
    for(int i=0;i<k;i++){
        suma+=transformarANum(sumandos[i], letrasAsignadas, cantLetras);
    }
    return suma==transformarANum(resultado, letrasAsignadas, cantLetras);
    // Verifica si llegamos a una solución
}

bool puedoAplicarMovimiento(string* sumandos, char* letrasAsignadas, char* letrasTotales, int valorLetra, int j, int k) {
    //me tengo que fijar que la letra no esté asignada
    //necesito array con todas las letras
    //verificar que j sea menor que 10
    //borrar letraNueva, letraNueva es letrasTotales[j]ç
    //hay k sumandos
    if(j>=10){
        return false;
    }
    if(letrasAsignadas[valorLetra]!='a'){
        return false; //ya está asignada
    }/*
    for(int i=0;i<k;i++){
        for(int j=0;j<maximoLargo(sumandos);j++){
            if(sumandos[i].length()>j){
                sumandos[i][j]
            }
        }
    }
        letraNueva=letrasTotales[j];
    for(int i)
    */
    

    
}

void aplicarMovimiento(char* letrasAsignadas, char letraNueva, int n /*n es el valor*/) {
    letrasAsignadas[n]=letraNueva;
    
    
}

void deshacerMovimiento(char* letrasAsignadas, char letraNueva, int n) {
   letrasAsignadas[n]='a';
}

// Función principal de backtracking
void backtracking(char* letrasAsignadas, string* sumandos, int k, char* letrasTotales, int j/*j arranca en 0*/) {
    if (esSolucion(letrasAsignadas,sumandos,k)) {
        for(int i=0;i<k-1;i++){
            cout<<transformarANum(sumandos[i], letrasAsignadas)<< " + ";
        }
        cout<<transformarANum(sumandos[k-1], letrasAsignadas)<< " = ";
        cout<<transformarANum(sumandos[k], letrasAsignadas)<<endl;
    } else {
        // Para cada movimiento posible
        //para cada numero probamos con una letra
        for (int i=0;i<10;i++) {
                //letrasTotales son todas las letras
                if (puedoAplicarMovimiento(sumandos,letrasAsignadas,letrasTotales,i,j,k)) {
                aplicarMovimiento(letrasAsignadas,letrasTotales[j],i);
                backtracking(letrasAsignadas,sumandos,k,letrasTotales,j+1);
                deshacerMovimiento(letrasAsignadas,letrasTotales[j],i);
            
            }
            
        }
    }
}


int main()
{
    int T;
    cin>>T;
    string resultados="";
    for(int i=0;i<T;i++){
        int k;
        cin>>k;
        string* sumandos=new string[k+1];
        for(int j=0;j<k;j++){
            cin>>sumandos[j];
        }
        string resultado;
        cin>>resultado;
        sumandos[k]=resultado;
        string=backtracking(sumandos);
    }
}