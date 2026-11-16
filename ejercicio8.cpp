#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;
int max(int n1,int n2){
    if(n1>n2){
        return n1;
    }
    return n2;
}
int main()
{
    int n;
    cin>>n;
    int w;
    cin>>w;
    int l1,l2,l3,l0;
    cin>>l0;
    cin>>l1;
    cin>>l2;
    cin>>l3;
    int* pesos=new int[n+1];
    int* satisfaccion=new int[n+1];
    int* categoria=new int[n+1];
    for(int i=1;i<=n;i++){
        int p,s,c;
        cin>>p;
        cin>>s;
        cin>>c;
        pesos[i]=p;
        satisfaccion[i]=s;
        categoria[i]=c;
    }
    int****** tab=new int*****[w+1];
    for (int i = 0; i <= w; i++)
    {
        tab[i]=new int****[n+1];
        for (int producto = 0; producto <=n ; producto++)
        {
            tab[i][producto]=new int***[l0+1];

            for (int l0i = 0; l0i <= l0; l0i++)
            {
                tab[i][producto][l0i]=new int**[l1+1];
                for (int l1i = 0; l1i <= l1; l1i++)
                {
                    tab[i][producto][l0i][l1i]=new int*[l2+1];
                    for (int l2i = 0; l2i <=l2; l2i++)
                    {
                        tab[i][producto][l0i][l1i][l2i]=new int[l3+1];

                        for (int l3i = 0; l3i <= l3; l3i++)
                        {
                            tab[i][producto][l0i][l1i][l2i][l3i]=0;

                    
                        }
                    
                    }
                    
                }
            }
            
        }
        
    }
    for (int i = 1; i <= w; i++)
    {
        for (int producto = 1; producto <=n ; producto++)
        {

            for (int l0i = 0; l0i <= l0; l0i++)
            {
                for (int l1i = 0; l1i <= l1; l1i++)
                {
                    for (int l2i = 0; l2i <= l2; l2i++)
                    {

                        for (int l3i = 0; l3i <= l3; l3i++)
                        {
                            int usarProd=-1;
                            if(i-pesos[producto]>=0){
                                if(categoria[producto]==0&&l0i-1>=0){
                                    usarProd=satisfaccion[producto]+tab[i-pesos[producto]][producto-1][l0i-1][l1i][l2i][l3i];

                                }
                                if(categoria[producto]==1&&l1i-1>=0){
                                    usarProd=satisfaccion[producto]+tab[i-pesos[producto]][producto-1][l0i][l1i-1][l2i][l3i];

                                }
                                if(categoria[producto]==2&&l2i-1>=0){
                                    usarProd=satisfaccion[producto]+tab[i-pesos[producto]][producto-1][l0i][l1i][l2i-1][l3i];

                                }
                                if(categoria[producto]==3&&l3i-1>=0){
                                    usarProd=satisfaccion[producto]+tab[i-pesos[producto]][producto-1][l0i][l1i][l2i][l3i-1];

                                }
                            }
                            int noUsarProd=tab[i][producto-1][l0i][l1i][l2i][l3i];
                            tab[i][producto][l0i][l1i][l2i][l3i]=max(usarProd,noUsarProd);
                    
                        }
                    
                    }
                    
                }
            }
            
        }
        
    }
    cout<<tab[w][n][l0][l1][l2][l3]<<endl;
    // Liberar la tabla
for (int i = 0; i <= w; i++)
{
    for (int producto = 0; producto <= n; producto++)
    {
        for (int l0i = 0; l0i <= l0; l0i++)
        {
            for (int l1i = 0; l1i <= l1; l1i++)
            {
                for (int l2i = 0; l2i <= l2; l2i++)
                {
                    delete[] tab[i][producto][l0i][l1i][l2i];
                }

                delete[] tab[i][producto][l0i][l1i];
            }

            delete[] tab[i][producto][l0i];
        }

        delete[] tab[i][producto];
    }

    delete[] tab[i];
}

delete[] tab;

// Liberar los arreglos de productos
delete[] pesos;
delete[] satisfaccion;
delete[] categoria;
    return 0;
}