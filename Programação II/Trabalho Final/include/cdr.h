#ifndef TRABALHO_CDR_H
#define TRABALHO_CDR_H

// Esse código não deve ser modificado
typedef struct cdr cdr_t;
/*----------------------------------*/

cdr_t* criar_cdr(int ramal, char* destino, long long inicio, int duracao_seg, char* tipo);

void set_ramal_origem(cdr_t* cdr, int valor) ;
int get_ramal_origem(cdr_t* cdr);
void set_num_destino(cdr_t* cdr, char* destino_recebido);
char* get_num_destino (cdr_t* cdr);
void set_inicio(cdr_t* cdr, long long valor);
long long get_inicio(cdr_t* cdr);
void set_duracao_seg(cdr_t* cdr, int valor) ;
int get_duracao_seg(cdr_t* cdr);
void set_tipo_chamada(cdr_t* cdr, char* tipo);
char* get_tipo_chamada(cdr_t* cdr);

#endif //TRABALHO_CDR_H