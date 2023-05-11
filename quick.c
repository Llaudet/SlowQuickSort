#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000000

// void quickSort(int arr[], int low, int high) {
//     int i = low, j = high;
//     int temp, pivot = arr[(low + high) / 2];
//     while (i <= j) {
//         while (arr[i] < pivot) {
//             i++;
//         }
//         while (arr[j] > pivot) {
//             j--;
//         }
//         if (i <= j) {
//             temp = arr[i];
//             arr[i] = arr[j];
//             arr[j] = temp;
//             i++;
//             j--;
//         }
//     }
//     if (low < j) 
//         quickSort(arr, low, j);
//     if (i < high) 
//         quickSort(arr, i, high);
// }


int particionar(int *arr, int nextToPivot, int fin, int pivot){
  int j = nextToPivot;

  for(int i = nextToPivot; i <= fin; i++){

    if(arr[i] <= pivot){

      int aux = arr[i];
      arr[i] = arr[j];
      arr[j] = aux;
      j++;
    }
  }
  int cantMenoresAPivot = j;
  return cantMenoresAPivot;
}

void quickSort(int *arr, int ini, int fin){

  if((fin - ini + 1) < 2)return;

  int aux;
  int pivot = arr[ini];

  int cantMenoresAPivot = particionar(arr, ini + 1, fin, pivot); 
  int indiceBorde = cantMenoresAPivot - 1;

  aux = arr[ini];
  arr[ini] = arr[indiceBorde];
  arr[indiceBorde] = aux;


  quickSort(arr, ini, indiceBorde - 1);
  quickSort(arr, indiceBorde + 1, fin);
}

int main(){
  srand (time(NULL));   

  int *arr = malloc(sizeof(int) * MAX);

  for (int i = 0; i < MAX; i++)
    arr[i] = rand() % 100;

  // for (int i = 0; i < MAX; i++)
  //   printf("%d-",arr[i]);

  quickSort(arr, 0, MAX - 1);


// puts("");
//   for (int i = 0; i < MAX; i++)
//       printf("%d-",arr[i]);

  free(arr);

  return 0;
}