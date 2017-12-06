#include <cstdlib>
#include <cstdio>

void gerar_lotofacil_soma(long ltf_id, long ltf_qt, const long * const lotofacil_bolas, FILE * f_arquivo){
    bool b_qt = (ltf_qt >= 15) && (ltf_qt <= 18);
    if(!b_qt){
        fprintf(stderr, "Erro: ltf_qt=%li, mas valor deve estar entre 15 e 18", ltf_qt);
        exit(-3);
    }

    long soma_bola = 0;
    for(long uA = 1; uA <= ltf_qt; uA++){
        soma_bola += lotofacil_bolas[uA];
    }

    fprintf(f_arquivo, "\n%li;%li;%li", ltf_id, ltf_qt, soma_bola);
    if(ferror(f_arquivo)){
        fprintf(stderr, "Erro ao gravar no arquivo: lotofacil_soma.csv,");
        exit(-3);
    }
}
