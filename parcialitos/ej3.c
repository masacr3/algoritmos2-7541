#include <include.h>
#include <stdlib.h>
#include <stdbool.h>

void es_magico( int arr[], size_t tam ){
	return _magico(arr,0,tam-1);
}

bool _magico( int arr[], size_t i, size_t f){
	if (i > f) return false;

	size_t medio = (i + f) /2;

	if( arr[medio] == medio ) return true;

	if ( arr[medio] > medio ) return _magico(arr, i, medio-1);

	else return _magico (arr, medio+1, f);
		
}
