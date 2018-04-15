int raiz(int n){
  return _raiz(n,1,n);
}

int _raiz(int n, int inicio, int fin){
  /* division y conquista */
  int medio = (inicio + fin)/2;

  int cuadrado = medio *medio;
  if (cuadrado == n){
    return medio;
  }

  if (cuadrado > n){
    return _raiz(n, )
  }
}







int pila_sumar(pila_t* pila){
  //caso base
  if (pila_esta_vacia(pila)){
    return 0;
  }

  int valor = *(int*)pila_desapilar(pila);
  int suma = pila_sumar(pila);

  //cuando termina las llamadas recursivas el caso de retorno
  //empiezo a dejar la pila en estado original
  pila_apilar(&valor);

  return suma + valor;
}

// Calculamos la Optimizacion del algorimo mediante el TEOREMA MAESTRO

T(n) = A * T(n/b) + F(n)

Complejidad ALGORITMICA notacion de Landau...


log = c  ---> O( n^c * log (n))
log < c  --->
log > c  --->

A = cantidad de llamadas recursivas
B = en cuantas partes se divide el problema
