#include <stdio.h>
#include <stdbool.h>

// Constantes (strings como define porque todavia no las vimos formalmente)
#define PREGUNTA1 "\n1) Estás saliendo de tu casa, y te enteras que hay paro de trenes, ¿Qué otro transporte elegís?\nOpciones:\n\nTrineo (T)\nNave Espacial (N)\nCamión (C)\nAlfombra (A)."
#define PREGUNTA2 "\n2) En medio del camino te encontras con una manifestación, ¿Que medio utilizas para deshacerte de la manifestación?\nOpciones:\n\nBolas de nieve (B)\nPium pium (P)\nKuchau (K)\nGenio (G)"
#define PREGUNTA3 "\n3) Lograste superar la manifestación, ¿A qué hora conseguiste llegar a la universidad?\n"
#define PREGUNTA4  "\n4) Por fin llegó la nota del parcial! ¿Qué nota lograste sacarte?\n"
#define BIENVENIDA "\n - Hola! Cansadx de llegar tarde al parcial?\n\nNecesitas ayuda para aprobar tu primer cuatrimestre en fiuba?\n\nAlguno de estos 4 cracks te puede ayudar!\n\nVamos a hacerte un par de preguntas para ver quien es el o la mas indicada!..\n"
#define SALTOCORTO "\n-----\n"
#define SALTOLARGO "\n\n\n------------------\n"
#define RESPUESTAINVALIDA "\nRespuesta inválida, intenta de nuevo: "

// Constantes: letras rtas y puntajes preg 1
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
            printf("\nRespuesta inválida, intenta de nuevo: ");
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
            printf("\nRespuesta inválida, intenta de nuevo: ");
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

void preguntar3(float* hora_llegada){
    printf(SALTOCORTO);
    printf(PREGUNTA3);
    printf("\n\n> Cual es tu respuesta? [Responde en formato HH.MM (donde H: hora y M: Minuto)]: ");
    scanf(" %f", hora_llegada);

    // horas en la parte entera y minutos en la decimal
    int horas = (int)*hora_llegada;
    float minutos = *hora_llegada - horas;

    // validacion 
    while (horas < limite_inf_horas || horas > limite_sup_horas || minutos < limite_inf_minutos || minutos > limite_sup_minutos) {
        printf("\nRespuesta inválida, intenta de nuevo: ");
        scanf(" %f", hora_llegada);
        horas = (int)*hora_llegada;
        minutos = *hora_llegada - horas;
    }
    
    // No hace falta asignar puntaje en esta pregunta. Utilizaremos el valor de respuesta, que es la hora de llegada, para tomar decisiones
}

void preguntar4(int* nota, int* ref_puntaje){
    printf(SALTOCORTO);
    printf(PREGUNTA4);
    printf("\n\n> Cual es tu respuesta? [Las notas posibles son números del 1 al 10]: ");
    scanf(" %i",nota);

    // validacion
    while (*nota < 1 || *nota > 10) {
        printf("\nRespuesta inválida, intenta de nuevo: ");
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
    return (*puntaje1) + (*puntaje2) * (*puntaje4);
}

char decidirPersonaje(int* puntaje_total, float* hora_llegada_parcial){
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
    preguntar1(&rta1,&puntaje1);
    preguntar2(&rta2,&puntaje2);
    preguntar3(&rta3);
    preguntar4(&rta4, &puntaje4);

    // Toma de decision
    int puntaje_total = calcularPuntaje(&puntaje1, &puntaje2, &puntaje4);
    char personaje_definitivo = decidirPersonaje(&puntaje_total, &rta3);

    printf(SALTOLARGO);

    // Informo el resultado final 
    if (personaje_definitivo == olaf) {
        printf("\n--> Con un puntaje de %i puntos se definió el personaje - Olaf (O) -.", puntaje_total);
    } else if (personaje_definitivo == stich) {
        printf("\n--> Con un puntaje de %i puntos se definió el personaje - Stich (S) -.", puntaje_total);
    } else if (personaje_definitivo == jasmin) {
        printf("\n--> Con un puntaje de %i puntos se definió el personaje - Jasmin (J) -.", puntaje_total);
    } else if (personaje_definitivo == rayo) {
        printf("\n--> Con un puntaje de %i puntos se definió el personaje - Rayo (R) -.", puntaje_total);
    } else {
        printf("\n--> Ups! Algo salio mal.");
    }

    printf(SALTOLARGO);

    return 0;
}