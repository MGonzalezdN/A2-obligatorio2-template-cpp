#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;
int largoMax;
char* letras;
int cantLetras;

long long pasarANumero(string sumando, int* valorDeCadaLetra){
    long long valor=0;
    for(int i=0;i<sumando.length();i++){
        long long numero=valorDeCadaLetra[sumando[i]-'A'];
        if(numero==-1){
            return -1;
        }else{
            //potencia de 10
            for(int j=sumando.length()-1-i; j>0; j--){
                numero*=10;
            }
        }
        valor+=numero;
    
    }
    return valor;
}
// Funciones helper
bool esSolucion(string* sumandos, int largoSumandos, int* valorDeCadaLetra, int pos) {
    if (pos==cantLetras){
        
        string resultado=sumandos[largoSumandos-1];
        long long suma=0;
        //me fijo si asigno todas las letras
        for(int i=0;i<largoSumandos-1;i++){
            long long num=pasarANumero(sumandos[i],valorDeCadaLetra);
            if(num==-1){
                return false;
            }
            suma+=num;
        }
        long long resultadoNum=pasarANumero(resultado, valorDeCadaLetra);
        return resultadoNum!=-1&&resultadoNum==suma;
    }else{
        return false;
    }
    
    // Verifica si llegamos a una solución
}
bool esMejorSolucion(string* sumandos, int largoSumandos, long long resultadoNum, int*valorDeCadaLetra, long long &mejorResultado, int* mejorValorDeCadaLetra){
    if(resultadoNum<mejorResultado){
        return true;
    }
    if(resultadoNum==mejorResultado){
        //compararSumandos
        for(int i=0;i<largoSumandos-1;i++){
            if(pasarANumero(sumandos[i], valorDeCadaLetra)>pasarANumero(sumandos[i],mejorValorDeCadaLetra)){
                return false;
            }
            if(pasarANumero(sumandos[i], valorDeCadaLetra)<pasarANumero(sumandos[i],mejorValorDeCadaLetra)){
                return true;
            }
        }
    }
    return false;
}
void clonarSolucion(string* sumandos, int largoSumandos, int* valorDeCadaLetra, string& mejorSolucion,int*mejorValorDeCadaLetra){
    for(int i=0;i<26;i++){
        mejorValorDeCadaLetra[i]=valorDeCadaLetra[i];
    }
    
    mejorSolucion="";
    for(int i=0;i<largoSumandos-2;i++){
        mejorSolucion+=to_string(pasarANumero(sumandos[i],valorDeCadaLetra)) + " + ";
    }
    mejorSolucion+= to_string(pasarANumero(sumandos[largoSumandos-2],valorDeCadaLetra));
    mejorSolucion+= " = " ;
    mejorSolucion+= to_string(pasarANumero(sumandos[largoSumandos-1],valorDeCadaLetra));
}

bool puedoAplicarMovimiento(string * sumandos,int largoSumandos, int *valorDeCadaLetra, bool* valoresAsignados,int pos, int valorLetra){
//si la letra no se ya asignada
    if(pos>=cantLetras){
        return false;
    }
    char letra=letras[pos];
    if(valorDeCadaLetra[letra-'A']!=-1 || valoresAsignados[valorLetra]){
        return false;
    }
    valorDeCadaLetra[letra-'A']=valorLetra;
    //si la letra está al principio de una palabra de largo>1, y el valor es 0 no lo puedo aplicar
    string resultado=sumandos[largoSumandos-1];
    bool puedo=true;
    int carry=0;
    if(valorLetra == 0){
        for(int i=0; i<largoSumandos; i++){
            if(sumandos[i].length() > 1 && sumandos[i][0] == letra){
                valorDeCadaLetra[letra-'A']=-1;
                return false;
            }
        }
    }
//    int posicion = sumandos[i].length() - 1 - columna;
    for(int columna=0;columna<largoMax;columna++){
        int sumaColumna=carry;
        bool hayValorDesconocido=false;
        for(int i=0;i<largoSumandos-1;i++){
            int posicion=sumandos[i].length()-1-columna;
            if(posicion>=0){
                int valorPos=valorDeCadaLetra[sumandos[i][posicion]-'A'];
                if(valorPos==-1){
                    hayValorDesconocido=true;
                    break;
                }
                sumaColumna+=valorPos;
            }
        }
        if(hayValorDesconocido){
            valorDeCadaLetra[letra-'A']=-1;
            return true;
        }
        int digitoResultado=valorDeCadaLetra[resultado[resultado.length()-1-columna]-'A'];
        if(digitoResultado!=-1&&sumaColumna%10!=digitoResultado){
            puedo=false;
            break;
        }
        carry=sumaColumna/10;
    }  

    valorDeCadaLetra[letra-'A']=-1;
    return puedo;
}


void aplicarMovimiento(int* valorDeCadaLetra, bool* valoresAsignados, char letra, int valor) {
    valoresAsignados[valor]=true;
    valorDeCadaLetra[letra-'A']=valor;    
}

void deshacerMovimiento(int* valorDeCadaLetra, bool* valoresAsignados, char letra, int valor) {
    valoresAsignados[valor]=false;
    valorDeCadaLetra[letra-'A']=-1;
}
bool puedoPodar(string* sumandos, int largoSumandos, int* valorDeCadaLetra, bool*valoresAsignados, long long mejorResultado){
    int min=9;
    for(int i=0; 9>=i && min==9; i++){
        if(!valoresAsignados[i]){
            min=i;
        }
    }
    string resultado=sumandos[largoSumandos-1];
    long long resultadoNum=0;
    for(int i=0;i<resultado.length();i++){
        long long columna=0;
        if(valorDeCadaLetra[resultado[i]-'A']==-1){
            columna=min;
            //siguienteMax
        }else{
            columna=valorDeCadaLetra[resultado[i]-'A'];
        }
        for(int j=resultado.length()-1-i; j>0; j--){
            columna*=10;
        }
        
        resultadoNum+=columna;
    }
    return resultadoNum>mejorResultado;
}
//min valor del más grande

void backtracking(bool* valoresAsignados, string* sumandos, int largoSumandos, int* valorDeCadaLetra,
    long long &mejorResultado, string &mejorSolucion, int pos, int*mejorValorDeCadaLetra) {
    if (!puedoPodar(sumandos,largoSumandos, valorDeCadaLetra, valoresAsignados, mejorResultado)) {  // PODA!
        if (esSolucion(sumandos,largoSumandos,valorDeCadaLetra,pos)) {
            long long resultadoNum=pasarANumero(sumandos[largoSumandos-1],valorDeCadaLetra);
            if (esMejorSolucion(sumandos, largoSumandos, resultadoNum, valorDeCadaLetra,mejorResultado, mejorValorDeCadaLetra)) {
                clonarSolucion(sumandos, largoSumandos, valorDeCadaLetra, mejorSolucion, mejorValorDeCadaLetra);
                mejorResultado = resultadoNum;  // Actualizar mejor
            }
        } else {
            
            // Para cada movimiento posible
        //para cada numero probamos con una letra, 
        for (int i=0;i<10;i++) {
                
            if (puedoAplicarMovimiento(sumandos,largoSumandos, valorDeCadaLetra, valoresAsignados,pos,i )){
                aplicarMovimiento(valorDeCadaLetra,valoresAsignados, letras[pos],i);
                backtracking(valoresAsignados, sumandos, largoSumandos, valorDeCadaLetra, mejorResultado, mejorSolucion, pos+1,mejorValorDeCadaLetra);
                deshacerMovimiento(valorDeCadaLetra,valoresAsignados, letras[pos],i);
            
            }
            
        }

        }
    }
}

char* asignarLetras(string* sumandos,int largoSumandos,int &cantLetras){
    bool* aparecen=new bool[26]();
    for(int i=0;i<largoSumandos;i++){
        for(int j=0;j<sumandos[i].length();j++){
            if(!aparecen[sumandos[i][j]-'A']){
                aparecen[sumandos[i][j]-'A']=true;
                cantLetras++;
            }
        }
    }
    char* ret=new char[cantLetras];
    int pos=0;
    for(int i=0;i<26;i++){
        if(aparecen[i]){
            ret[pos]=i+'A';
            pos++;
        }
    }
    delete[]aparecen;
    return ret;
}


/*valor decada letra debe ser inicializado en -1*/
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
        largoMax=resultado.length();
        sumandos[k]=resultado;
        bool* valoresAsignados=new bool[10]();
        int* valorDeCadaLetra=new int[26];
        int* mejorValorDeCadaLetra=new int[26]();
        for(int i=0;i<26;i++){
            valorDeCadaLetra[i]=-1;
            mejorValorDeCadaLetra[i]=-1;
        }
        string mejorSolucion="";
        
        cantLetras=0;
        letras=asignarLetras(sumandos,k+1, cantLetras);
        long long intmax= numeric_limits<long long>::max();
        bool imposible=false;
        for(int i=0;i<k;i++){
            if(sumandos[i].length()>sumandos[k].length()){
                imposible=true;
            }
        }
        if(!imposible){
            backtracking(valoresAsignados,sumandos,k+1,valorDeCadaLetra,intmax,mejorSolucion,0,mejorValorDeCadaLetra);
        }
        if(mejorSolucion=="" || imposible){
            cout<<"imposible"<<endl;
        }else{
            cout<<mejorSolucion<<endl;

        }
    }
}