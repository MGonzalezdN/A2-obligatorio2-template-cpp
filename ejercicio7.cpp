#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;
int* intercalar(int* arr1, int* arr2,long long& resultado,int n1,int n2) {
  //int n1 = sizeof(arr1) / sizeof(arr1[0]);
  //int n2 = sizeof(arr2) / sizeof(arr2[0]);
  int* ret = new int[n1 + n2];
  // for (int i = 0; i < n1; i++)
  // {
  //   cout<<arr1[i]<<endl cout del 4/11;
  // }
  // for (int i = 0; i < n2; i++)
  // {
  //   cout<<arr2[i]<<endl;
  // }
  int i = 0, j = 0, k = 0, l=0;
  while (i < n1 && j < n2) {
    // if((float)arr1[i]/2>arr2[j]){
    //     resultado+=(n1-i);
    // }
    if ((float)arr1[i] < arr2[j]) {
      ret[k++] = arr1[i++];
    } else {
        while(l<n1&&(float)arr1[l]/2<=arr2[j]){
          l++;
        }
        resultado+=n1-l;  
        ret[k++] = arr2[j++];
    }
  }

  while (i < n1) {
    ret[k++] = arr1[i++];
  }

  while (j < n2) {
    ret[k++] = arr2[j++];
  }

  return ret;
}

int* mergeSort(int* valores, int inicio, int fin,long long &resultado){
  if(inicio == fin){
    int* ret = new int[1];
    ret[0] = valores[inicio];
    return ret;
  }
  int mitad = (inicio + fin) / 2;

  int* ord1 = mergeSort(valores, inicio, mitad,resultado);
  int* ord2 = mergeSort(valores, mitad + 1, fin,resultado);
  int n1=mitad-inicio+1;
  int n2=fin-mitad;
  return intercalar(ord1, ord2,resultado,n1,n2);
  
}
int main()
{
    int n;
    cin>>n;
    int* llegada=new int[n];
    for (int i = 0; i < n; i++)
    {
        int idCorredor;
        cin>>idCorredor;
        llegada[i]=idCorredor;        
    }
    long long resultado=0;
    mergeSort(llegada,0,n-1, resultado);
    cout<<resultado<<endl;
    
    return 0;
}


