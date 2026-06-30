#include <stdio.h>
#include "../include/hash.h"
#include "../include/menu.h"

int main(void) {

    printf("inicializando sistema...\n");
    tabela_hash_t *sistema = th_criar(1031);

    interface();

    th_destruir(sistema);

    printf("Sistema encerrado. Memoria liberada.\n");
    return 0;
}
