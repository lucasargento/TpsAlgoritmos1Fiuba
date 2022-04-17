#include <stdio.h>
float parteDecimal (float* numero) {
   // cuando usamos literales numericos y los asignamos a una variable de tipo float
   // es correcto que le pongamos f al final para indicarselo al compilador
   float numero;
   int parte_entera = (int)numero;
   numero = numero - (float)parte_entera; // se vuele a castear para evitar la warning de conversion
   return numero;
}