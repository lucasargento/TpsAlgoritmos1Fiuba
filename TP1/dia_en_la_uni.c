#include <stdio.h>

// Constantes (strings como define porque todavia no las vimos formalmente)
#define PREGUNTA1 "\n1) Estás saliendo de tu casa, y te enteras que hay paro de trenes, ¿Qué otro transporte elegís?\nOpciones:\n\nTrineo (T)\nNave Espacial (N)\nCamión (C)\nAlfombra (A)."
#define PREGUNTA2 "\n2) En medio del camino te encontras con una manifestación, ¿Que medio utilizas para deshacerte de la manifestación?\nOpciones:\n\nBolas de nieve (B)\nPium pium (P)\nKuchau (K)\nGenio (G)"
#define PREGUNTA3 "\n3) Lograste superar la manifestación, ¿A qué hora conseguiste llegar a la universidad?\n"
#define PREGUNTA4  "\n4) Por fin llegó la nota del parcial! ¿Qué nota lograste sacarte?\n"
#define BIENVENIDA "\n - Hola! Cansadx de llegar tarde al parcial?\n\nNecesitas ayuda para aprobar tu primer cuatrimestre en fiuba?\n\nAlguno de estos 4 cracks te puede ayudar!\n\nVamos a hacerte un par de preguntas para ver quien es el o la mas indicada!..\n"
#define SALTOCORTO "\n-----\n"
#define SALTOLARGO "\n\n\n------------------\n"
#define RESPUESTAINVALIDA "\nRespuesta inválida, intenta de nuevo: "

// Constantes: letras rtas y puntajes preg 1. Declaro tanto upper como lower case
// para no utilizar funciones de librerias externas (tolower y toupper)
const char trineo = 'T';
const char trineo_L = 't';
const char nave_espacial = 'N';
const char nave_espacial_L = 'n';
const char camion = 'C';
const char camion_L = 'c';
const char alfombra = 'A';
const char alfombra_L = 'a';
const int puntaje_trineo_nave = 10; 
const int puntaje_camion_alfombra = 20;
// Constantes: letras rtas y puntajes preg 2
const char bolas_nieve = 'B';
const char bolas_nieve_L = 'b';
const char pium_pium = 'P';
const char pium_pium_L = 'p';
const char kuchau = 'K';
const char kuchau_L = 'k';
const char genio = 'G';
const char genio_L = 'g';
const int puntaje_bolas_nieve = 3;
const int puntaje_pium_pium = 6;
const int puntaje_kuchau = 9;
const int puntaje_genio = 12;
// Constantes: letras rtas y puntajes preg 3
const int limite_inf_horas = 0;
const int limite_sup_horas = 23;
const int limite_inf_minutos = 0;
const float limite_sup_minutos = 0.59f;
// Constantes: decision de personaje 
const float hora_del_parcial = 15.30f;
const int olaf_stich_lim_inferior = 13;
const int olaf_stich_lim_superior = 41;
const int rayo_jasmin_lim_inferior = 42;
const int rayo_jasmin_lim_superior = 68;
// Personajes:
const char olaf = 'O';
const char rayo = 'R';
const char stich = 'S';
const char jasmin = 'J';


void preguntar1(char* ref_rta, int* ref_puntaje){
    /*  -> Funcion que imprime al usuario la primera pregunta y registra su respuesta
    [Pre]:
        - ref_rta: debe ser una referencia a la variable de la primera rta. Apunta a una variable
            de tipo Char.
        - ref_puntaje: debe ser una referencia a la variable del puntaje de la primera rta. Apunta a 
            una variable de tipo entero.
    [Post]:
        - La funcion no devuelve ningun valor. Las variables (parametros) de entrada de la función
        son modificadas por referencia.
        - ref_rta: la variable referenciada puede tomar los valores T, N, C, A segun la rta del usuario 
        (o sus analogos en lower case).
        - ref_puntaje: toma valor 10 si *ref_rta: T o N, y 20 si *ref_rta: C o A.
    */
    printf(PREGUNTA1);
    printf("\n\n> Cual es tu respuesta? [Solo el primer caracter será tomado en cuenta]: ");
    scanf(" %c",ref_rta);

    // Valido rta. case sensitive
    while((*ref_rta) != trineo &&
        (*ref_rta) != trineo_L && 
        (*ref_rta) != nave_espacial &&
        (*ref_rta) != nave_espacial_L && 
        (*ref_rta) != camion && 
        (*ref_rta) != camion_L && 
        (*ref_rta) != alfombra && 
        (*ref_rta) != alfombra_L) 
        {
            printf(RESPUESTAINVALIDA);
            scanf(" %c",ref_rta);
    };

    // Decisión de puntaje. case sensitive
    if ((*ref_rta) == trineo ||
            (*ref_rta) == trineo_L || 
            (*ref_rta) == nave_espacial ||
            (*ref_rta) == nave_espacial_L 
        ) {
            (*ref_puntaje) = (*ref_puntaje) + puntaje_trineo_nave;
    } else if ((*ref_rta) == camion ||
            (*ref_rta) == camion_L || 
            (*ref_rta) == alfombra ||
            (*ref_rta) == alfombra_L
            ) {
        (*ref_puntaje) = (*ref_puntaje) + puntaje_camion_alfombra;
    }
}

void preguntar2(char* ref_rta, int* ref_puntaje){
    /*  -> Funcion que imprime al usuario la segunda pregunta y registra su respuesta
    [Pre]:
        - ref_rta: debe ser una referencia a la variable de la segunda rta. Apunta a una variable
            de tipo Char.
        - ref_puntaje: debe ser una referencia a la variable del puntaje de la segunda rta. Apunta a 
            una variable de tipo entero.
    [Post]:
        - La funcion no devuelve ningun valor. Las variables (parametros) de entrada de la función
        son modificadas por referencia.
        - ref_rta: la variable referenciada puede tomar los valores B, P, K, G segun la rta del usuario 
        (o sus analogos en lower case).
        - ref_puntaje: la variable referenciada toma valor 
            3 si *ref_rta: B, 
            6 si *ref_rta: P,
            9 si *ref_rta: K,
            12 si *ref_rta: G,
    */
    printf(SALTOCORTO);
    printf(PREGUNTA2);
    printf("\n\n> Cual es tu respuesta? [Solo el primer caracter será tomado en cuenta]: ");
    scanf(" %c",ref_rta);

    // Valido rta. case sensitive
    while((*ref_rta) != bolas_nieve &&
        (*ref_rta) != bolas_nieve_L &&
        (*ref_rta) != pium_pium &&
        (*ref_rta) != pium_pium_L &&
        (*ref_rta) != kuchau &&
        (*ref_rta) != kuchau_L && 
        (*ref_rta) != genio &&
        (*ref_rta) != genio_L) 
        {
            printf(RESPUESTAINVALIDA);
            scanf(" %c",ref_rta);
    };
        
    // Decisión de puntaje. case sensitive
    if ((*ref_rta) == bolas_nieve || (*ref_rta) == bolas_nieve_L) {
        (*ref_puntaje) = (*ref_puntaje) + puntaje_bolas_nieve;
    } else if ((*ref_rta) == pium_pium || (*ref_rta) == pium_pium_L) {
        (*ref_puntaje) = (*ref_puntaje) + puntaje_pium_pium;
    } else if ((*ref_rta) == kuchau || (*ref_rta) == kuchau_L) {
        (*ref_puntaje) = (*ref_puntaje) + puntaje_kuchau;
    } else if ((*ref_rta) == genio || (*ref_rta) == genio_L) {
        (*ref_puntaje) = (*ref_puntaje) + puntaje_genio;
    } 
}

float parteDecimal (float num) {
   /*  -> Funcion que devuelve la parte decimal de un numero
    [Pre]:
        - num: debe ser un numero de punto flotante (float).
    [Post]:
        - La funcion devuelve "num", un numero de punto flotante (float) que representa la parte 
        decimal de un numero. Su valor esta comprendido entre 0 y 1.
    */
    int parte_entera = (int)num;
    num = num - (float)parte_entera;
    return num;
}

void preguntar3(float* hora_llegada){
    /*  -> Funcion que imprime al usuario la tercera pregunta y registra su respuesta
    [Pre]:
        - hora_llegada: debe ser una referencia a la variable de la tercera respuesta, la cual coincidirá
        con la hora de llegada del usuario. Apunta a una variable de tipo Float.
    [Post]:
        - La variable (parámetro) de entrada de la función es modificada por referencia, generando un float
        con parte entera entre 0 y 24 y parte decimal entre 0 y 0.59. La hora de llegada ingresada por el 
        usuario será utilizada posteriormente tanto como "puntaje de la respuesta 3" y como respuesta de 
        esta ("rta3"). 
    */
    printf(SALTOCORTO);
    printf(PREGUNTA3);
    printf("\n\n> Cual es tu respuesta? [Responde en formato HH.MM (donde H: hora y M: Minuto)]: ");
    scanf(" %f", hora_llegada);

    // horas en la parte entera y minutos en la decimal
    int horas = (int)*hora_llegada;
    //float minutos = *hora_llegada - horas;
    float minutos = parteDecimal(*hora_llegada);

    // validacion 
    while (horas < limite_inf_horas || horas > limite_sup_horas || minutos < limite_inf_minutos || minutos > limite_sup_minutos) {
        printf(RESPUESTAINVALIDA);
        scanf(" %f", hora_llegada);
        horas = (int)*hora_llegada;
        //minutos = *hora_llegada - horas;
        minutos = parteDecimal(*hora_llegada);
    }
    
    // No hace falta asignar puntaje en esta pregunta. Utilizaremos el valor de respuesta, que es la hora de llegada, para tomar decisiones
}

void preguntar4(int* nota, int* ref_puntaje){
    /*  -> Funcion que imprime al usuario la cuarta pregunta y registra su respuesta
    [Pre]:
        - nota: debe ser una referencia a la variable de la cuarta rta. Apunta a una variable
            de tipo entero. La respuesta de la cuarta pregunta equivale a la nota que se saco el usuario
            en el parcial.
        - ref_puntaje: debe ser una referencia a la variable del puntaje de la cuarta rta. Apunta a 
            una variable de tipo entero.
    [Post]:
        - Las variables (parametros) de entrada de la función son modificados por referencia.
        - Nota tomará valores enteros entre 1 y 10.
        - Ref_puntaje tomara el valor de un multiplicador en funcion de la nota registrada,
            donde:
                multiplicador: 1 si la nota esta entre 1 y 3,
                multiplicador: 2 si la nota esta entre 4 y 6,
                multiplicador: 3 si la nota esta entre 7 y 8,
                multiplicador: 4 si la nota esta entre 9 y 10,
    */
    printf(SALTOCORTO);
    printf(PREGUNTA4);
    printf("\n\n> Cual es tu respuesta? [Las notas posibles son números del 1 al 10]: ");
    scanf(" %i", nota);

    // validacion
    while (*nota < 1 || *nota > 10) {
        printf(RESPUESTAINVALIDA);
        scanf(" %i",nota);
    }

    // Decisión de puntaje: generacion del multiplicador
    if (*nota >= 1 && *nota <= 3) {
        *ref_puntaje = 1;
    } else if (*nota >= 4 && *nota <= 6) {
        *ref_puntaje = 2;
    } else if (*nota >= 7 && *nota <= 8) {
        *ref_puntaje = 3;
    } else if (*nota >= 9 && *nota <= 10) {
       *ref_puntaje = 4;
    }
}

int calcularPuntaje(int* puntaje1, int* puntaje2, int* puntaje4){
    /*  -> Funcion que calcula el puntaje total registrado luego de las preguntas
    [Pre]:
        - Puntaje1, puntaje2, puntaje4: referencias a los puntajes de las 1era, 2da y 4ta rtas respectivamente.
        las 3 deben apuntar a variables de tipo entero. El puntaje de la 3era rta no participa de este cálculo.
    [Post]:
        - La funcion devuelve un entero que corresponde al puntaje total calculado segun la formula:
        Ptotal = P1 + (P2 * P4)
    */
    return (*puntaje1) + (*puntaje2) * (*puntaje4);
}

char decidirPersonaje(int* puntaje_total, float* hora_llegada_parcial){
    /*  -> Funcion que toma la decision final sobre el personaje obtenido.
    [Pre]:
        - Puntaje_total: debe ser una referencia a la variable del puntaje total, previamente
        calculado. Apunta a una variable de tipo entero.
        - Hora_llegada_parcial: debe ser una referencia a la variable de la hora de llegada (rta3)
        registrado en la tercera pregunta. Apunta a una variable de tipo Float.
    [Post]:
        - La funcion devuelve una variable de tipo Char. La misma tomara los valores (S, O, J, R)
        segun el personaje decidido.
    */
    if (*puntaje_total >= olaf_stich_lim_inferior && *puntaje_total <= olaf_stich_lim_superior){
        // final olaf vs stich
        if (*hora_llegada_parcial < hora_del_parcial) {
            // llego antes --> stich
            return stich;
        } else {
            // llego despues --> olaf
            return olaf;
        }
    } else if (*puntaje_total >= rayo_jasmin_lim_inferior && *puntaje_total <= rayo_jasmin_lim_superior){
        if (*hora_llegada_parcial < hora_del_parcial) {
            // llego antes --> jasmin
            return jasmin;
        } else {
            // llego despues --> rayo
            return rayo;
        }
    }
    return '\0';
}

int main(){
    // Bienvenida
    printf(BIENVENIDA);
    printf(SALTOCORTO);

    // Variables
    int puntaje1 = 0;
    int puntaje2 = 0;
    int puntaje4 = 0;
    char rta1;
    char rta2;
    float rta3;
    int rta4;
    
    // Preguntas
    preguntar1(&rta1, &puntaje1);
    preguntar2(&rta2, &puntaje2);
    preguntar3(&rta3);
    preguntar4(&rta4, &puntaje4);

    // Toma de decision
    int puntaje_total = calcularPuntaje(&puntaje1, &puntaje2, &puntaje4);
    char personaje_definitivo = decidirPersonaje(&puntaje_total, &rta3);

    printf(SALTOLARGO);

    // Informo el resultado final, los prints originales estan comentados para pasar los tests del Chanutron.
    if (personaje_definitivo == olaf) {
        //printf("\n--> Con un puntaje de %i puntos se definió el personaje - Olaf (O) -.", puntaje_total);
        printf("-Olaf-");
    } else if (personaje_definitivo == stich) {
        //printf("\n--> Con un puntaje de %i puntos se definió el personaje - Stich (S) -.", puntaje_total);
        printf("-Stitch-");
    } else if (personaje_definitivo == jasmin) {
        //printf("\n--> Con un puntaje de %i puntos se definió el personaje - Jasmin (J) -.", puntaje_total);
        printf("-Jasmín-");
    } else if (personaje_definitivo == rayo) {
        //printf("\n--> Con un puntaje de %i puntos se definió el personaje - Rayo (R) -.", puntaje_total);
        printf("-Rayo McQueen-");
    } else {
        printf("\n--> Ups! Algo salio mal.");
    }

    printf(SALTOLARGO);

    return 0;
}