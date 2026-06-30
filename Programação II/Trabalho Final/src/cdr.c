#include "../include/cdr.h"
#include <stdlib.h>
#include <string.h>

typedef struct cdr {
    int ramal_origem;
    char num_destino[32];
    long long inicio;
    int duracao_seg;
    char tipo[16];
} cdr_t;

cdr_t* criar_cdr(int ramal, char* destino, long long inicio, int duracao_seg, char* tipo) {
    cdr_t* novo_registro = (cdr_t*) malloc(sizeof(cdr_t));

    if (novo_registro != NULL) {
        novo_registro->ramal_origem = ramal;
        strcpy(novo_registro->num_destino, destino);
        novo_registro->inicio = inicio;
        novo_registro->duracao_seg = duracao_seg;
        strcpy(novo_registro->tipo, tipo);
    }
    return novo_registro;
}

// ==== Getting e Setting =====

void set_ramal_origem(cdr_t* cdr, int valor) {
    if (cdr) cdr->ramal_origem = valor;
}

int get_ramal_origem(cdr_t* cdr) {
    return cdr->ramal_origem;
}

void set_num_destino(cdr_t* cdr, char* destino_recebido) {
    if (cdr) strcpy(cdr->num_destino, destino_recebido);
}

char* get_num_destino(cdr_t* cdr) {
    return cdr->num_destino;
}

void set_inicio(cdr_t* cdr, long long valor) {
    if (cdr) cdr->inicio = valor;
}

long long get_inicio(cdr_t* cdr) {
    return cdr->inicio;
}

void set_duracao_seg(cdr_t* cdr, int valor) {
    if (cdr) cdr->duracao_seg = valor;
}

int get_duracao_seg(cdr_t* cdr) {
    return cdr->duracao_seg;
}

void set_tipo_chamada(cdr_t* cdr, char* tipo) {
    if (cdr) strcpy(cdr->tipo, tipo);
}

char* get_tipo_chamada(cdr_t* cdr) {
    return cdr->tipo;
}