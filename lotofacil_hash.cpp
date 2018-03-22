/**
 *  Gera um arquivo
 *
 *
 *
 *
 */
#include <cstdio>
#include <cstdlib>

static long int ltf_hash[26][26];
static bool b_hash_iniciado = false;
static unsigned long indice_ultimo_hash = 0;

void iniciar_hash(){
    long hash_id = -1;
    for(long uA = 0; uA <= 25; uA++)
        for(long uB = 0; uB <= 25; uB++){
            hash_id++;
            ltf_hash[uA][uB] = hash_id;
        }
    hash_id++;
    indice_ultimo_hash = hash_id;

    b_hash_iniciado = true;

}

void gerar_lotofacil_hash(long ltf_id, long ltf_qt, long * lotofacil_bolas, FILE * f_lotofacil_hash){
    bool b_ltf_qt = (ltf_qt >= 15) && (ltf_qt <= 18);
    if(!b_ltf_qt){
        fprintf(stderr, "ltf_qt inválido: %li", ltf_qt);
        exit(-1);
    }

    if(!b_hash_iniciado){
        iniciar_hash();
        b_hash_iniciado = true;
    }

    unsigned long hash_soma = 0;
    long hash_pos = 0;
    for(long uA = 1; uA <= ltf_qt; uA++){
        if(uA > 1){
            hash_pos++;
            hash_soma += (hash_pos * indice_ultimo_hash) * ltf_hash[lotofacil_bolas[uA-1]][lotofacil_bolas[uA]];
        }
    }

    fprintf(f_lotofacil_hash, "\n%li;%li;%lu", ltf_id, ltf_qt, hash_soma);
    if(ferror(f_lotofacil_hash)){
        fprintf(stderr, "Erro ao gravar no arquivo: 'lotofacil_hash.csv'");
        exit(-1);
    }
}


