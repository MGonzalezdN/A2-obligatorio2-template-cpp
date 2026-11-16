#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int* placas=new int[1001]();
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        placas[m]++;

    }    
    int maxImpar=-1;
    for(int i=1000;i>=0&&maxImpar==-1;i--){
        if(placas[i]%2!=0){
            maxImpar=i;
        }
    }
    string ret="";
    if(maxImpar!=-1){
        ret=to_string(maxImpar);
    }
    for(int i=0;i<=1000;i++){
        while(placas[i]>1){
            if(ret==""){
                ret=to_string(i)+" "+to_string(i);
            }else{
                ret=to_string(i)+" "+ret+" "+to_string(i);
            }
            
            placas[i]-=2;
        }
    }

    cout<<ret<<endl;
    return 0;
}