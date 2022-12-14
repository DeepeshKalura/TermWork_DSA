#include <stdio.h>


void swap(int *p, int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}

int main(){

    int n;
    printf("Enter The Number:   ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter The Value in array:    ");
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++){ // i to n
        if(arr[i]>0){ // if pos
            for (int j = i + 1; j < n; j++){ // then i+1 to n
                if(arr[j]<0){ // if neg
                    while(arr[i]>0){ // then 
                        swap(&arr[j], &arr[j - 1]);
                        j--;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    
    
        return 0;
}