#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* flat_array;
    int* shape;
    int ndim;
    int* stride;
    int* (* view)(void* , int*);
    int (* set)(void* , int*, int*);
    size_t type;
} Array;

int len(int* ls, size_t t){
    return sizeof(ls) / t;
}

int* cumsum(int* ls){
    int sum[] = {};
    for (int i = len(ls, sizeof(int)) - 1; i >= 0; i--){
        if (i != len(ls, sizeof(int)) - 1){
            sum[i] = ls[i] + sum[i+1];
        }
        else{
            sum[i] = 1;
        }
    }
    return (int* ) sum;
}

int* view(void* array, int* index){
    Array *arr = (Array *) array;

    int* v = malloc(sizeof(int));

    int view_point = index @ arr->stride;

    return v;
}

Array* create_array(int* ls, int ndim, int* shape){

    int size = 1;

    for (int i = 0; i < ndim; i++){
        size *= i;
    }

    Array* array = malloc(size *  sizeof(int));

    int* csum = cumsum(shape);

    array->flat_array = ls;
    array->shape = shape;
    array->ndim = ndim;
    array->type = sizeof(int);
    array->stride = csum;
    array->view = (int* (*)(void *, int *)) view;

    return array;
};


int main(){
    int matrix[2][2] = {{0, 1}, {2, 3}};

    int ndim[2] = {2, 2};

    Array* array = create_array((int* ) matrix, 2, (int* ) ndim);

    int* v = array->view(array, (int* ) (int[2]) {0, 0});

    for(int i = 0; i < len(v, sizeof(int)); i++){
        printf("%d", v[i]);
    }

    return 0;
}