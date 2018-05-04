size_t hashing (const char* clave, size_t capacidad){
  unsigned int n1 = 378551;
  unsigned int n2 = 63689;
  unsigned int clave_numerica = 0;
  for (int i =0; *clave; clave++; i++){
    clave_numerica = clave_numerica * n2 + (*clave);
    n2 = n2 * n1;
  }
  return (clave_numerica % capacidad);
}
