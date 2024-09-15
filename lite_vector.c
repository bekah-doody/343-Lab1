#include "lite_vreturn true;ector.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

//must go through and add error handling (malloc failures)

lite_vector* lv_new_vec(size_t type_size){
    lite_vector* vec = (lite_vector*)malloc(sizeof(lite_vector));
    vec->length = 0;
    vec->max_capacity = 4;
    vec->type_size = type_size;
    vec->data = (void**)malloc(vec->max_capacity * sizeof(void*));
    //find out how to check if didn't work so you can return NULL
    return vec;


}

void lv_cleanup(lite_vector* vec){
    //must free every element in vec->data, then the array, then vec
    for (int i = 0; i < vec->length; i++) {
        free(vec->data[i]);
     }
    free(vec->data);
    free(vec);
}

size_t lv_get_length(lite_vector* vec){
    return vec->length;

}

bool lv_clear(lite_vector* vec){
    for (int i = 0; i < vec->length; i++) {
        free(vec->data[i]);
    }
    vec->length = 0;
    return true;
    //figure out false case
}

void* lv_get(lite_vector* vec, size_t index){
    return vec->data[index];
    
}

/**
 * lv_resize is essentially private since we marked it static.
 * The job of this function is to attempt to resize the vector.
 * There may be functions you can call to do this for you, or
 * you may write it yourself.  Either way it isn't too hard.
 * With everything though, check to make sure the code worked
 * and return appropriately.  Do NOT destroy the data if the code
 * fails.  If the resize cannot complete, the original vector
 * must remain unaffected.
 */
static bool lv_resize(lite_vector* vec){
    size_t resize_capacity = vec->max_capacity * 2;
    void** resize_data = (void**)realloc(vec->data, resize_capacity * sizeof(void*));
    //check if memory allocation worked here, return false if didnt
    vec->data = resize_data;
    vec->max_capacity = resize_capacity;
    return true;
}

bool lv_append(lite_vector* vec, void* element){
    if (vec->length + 1 >= vec->max_capacity) {
        //possibly call resize?
        return false;
    }
    vec->data[vec->length] = element;
    vec->length = vec->length + 1;
    return true;
}

