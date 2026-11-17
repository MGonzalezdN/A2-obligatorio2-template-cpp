#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;
int maxLikes(int* convierte,int* likes, int* bailo,int* memo, int k, int& diferenciaGoles){
    if(k==0){
        return 0;
    }
    if(memo[k]!=-1){
        return memo[k];
    }
    //puedoUsarla o no 
    int likesBailekConPadre=-1;
    int likesBaileSinPadre=-1;
    if(diferenciaGoles+convierte[k]>=1){
        //puedoBailarConElAnterior
         
        if(bailo[k-1]){
            likesBailekConPadre=likes[k]/2;
            likesBailekConPadre+=memo[k-1];
        }else{
            likesBailekConPadre=memo[k-1]+likes[k];
        }
        if(k-2>=1){
            likesBaileSinPadre=memo[k-2]+likes[k];
        }
        


    }
}
int main()
{
    int k;
    cin>>k;
    int* convierte=new int[k+1];
    int* likes=new int[k+1];
    int* memo=new int[k+1];
    for(int i=1;i<=k;i++){
        int ai;
        cin>>ai;
        convierte[i]=ai;
        likes[i]=ai;
        memo[i]=-1;
    }
    
    return 0;
}