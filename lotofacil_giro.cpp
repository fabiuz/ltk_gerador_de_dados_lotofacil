/**
  Programa:     ltk_gerador_de_dados_lotofacil
  Autor:        Fábio Moura de Oliveira
  Arquivo:      lotofacil_giro.cpp
  Descrição:    Função pra girar uma combinação de 15, 16, 17 ou 18 bolas, em 90 graus, 180 graus, 270 graus.
**/

#include <cstring>
#include "lotofacil_deslocamento.hpp"
#include "lotofacil_giro.hpp"

long gerar_lotofacil_giro(long ltf_id, long ltf_qt, const long * lotofacil_bolas, FILE * f_lotofacil_giro)
{
    long retorno = 0;
    retorno += gerar_lotofacil_giro_90_graus(ltf_id, ltf_qt, lotofacil_bolas, f_lotofacil_giro);
    retorno += gerar_lotofacil_giro_180_graus(ltf_id, ltf_qt, lotofacil_bolas, f_lotofacil_giro);
    retorno += gerar_lotofacil_giro_270_graus(ltf_id, ltf_qt, lotofacil_bolas, f_lotofacil_giro);

    return 0;
}

/*!
 * \brief lotofacil_girar_90_graus Gera a combinação girada 90 graus pra direita e grava o conteúdo no arquivo
 * apontado por f_lotofacil_giro.
 * \param ltf_id
 * \param ltf_qt
 * \param lotofacil_bolas
 * \param f_lotofacil_giro
 * \return Retorna 0, se houver sucesso, senão retorna um valor diferente de zero.
 */
long gerar_lotofacil_giro_90_graus(long ltf_id, long ltf_qt, const long * lotofacil_num, FILE * f_lotofacil_giro)
{
    if(!(ltf_qt >= 15 && ltf_qt <= 18))
        return 1;

    long * lotofacil_num_giradas = new long[26];
    long * lotofacil_bolas_giradas = new long[ltf_qt+1];

    // Zera todos os valores do arranjo pra evitar lixo de memória.
    memset(lotofacil_num_giradas, 0, 26UL * sizeof(long));
    memset(lotofacil_bolas_giradas, 0, static_cast<size_t>(ltf_qt * sizeof(long)));



    // O índice indica a posição de origem, o valor indica a posição de destino.
    const long ltf_giro[26] = {
                           0,
                           5, 10, 15, 20, 25,
                           4,  9, 14, 19, 24,
                           3,  8, 13, 18, 23,
                           2,  7, 12, 17, 22,
                           1,  6, 11, 16, 21
                          };

    // Aqui, iremos mover o valor da posição de origem pra a posição de destino.
    // [1] => [5]
    // [2] => [10]
    // e assim por diante...
    for(long uA = 1; uA <= 25; uA++){
        lotofacil_num_giradas[ltf_giro[uA]] = lotofacil_num[uA];
    }

    // Pega as bolas em ordem crescente.
    long indice_bolas = 1;
    for(long uA = 1; uA <= 25; uA++){
        if(lotofacil_num_giradas[uA]){
            lotofacil_bolas_giradas[indice_bolas] = uA;
            indice_bolas++;
        }
    }

    // Verifica as bolas comuns.
    long qt_de_bolas_em_comum = 0;
    for(long uA = 1; uA <= 25; uA++){
        // Se o valor é zero, continua.
        if(!lotofacil_num_giradas[uA]){
            continue;
        }

        if(lotofacil_num_giradas[uA] == lotofacil_num[uA]){
            qt_de_bolas_em_comum++;
        }
    }

    long ltf_id_girado = 0;
    switch (ltf_qt) {
    case 15:
        ltf_id_girado = obter_deslocamento_15_bolas(
                lotofacil_bolas_giradas[1], lotofacil_bolas_giradas[2],
                lotofacil_bolas_giradas[3], lotofacil_bolas_giradas[4],
                lotofacil_bolas_giradas[5], lotofacil_bolas_giradas[6],
                lotofacil_bolas_giradas[7], lotofacil_bolas_giradas[8],
                lotofacil_bolas_giradas[9], lotofacil_bolas_giradas[10],
                lotofacil_bolas_giradas[11], lotofacil_bolas_giradas[12],
                lotofacil_bolas_giradas[13], lotofacil_bolas_giradas[14],
                lotofacil_bolas_giradas[15]);
        break;
    case 16:
        ltf_id_girado = obter_deslocamento_16_bolas(
                lotofacil_bolas_giradas[1], lotofacil_bolas_giradas[2],
                lotofacil_bolas_giradas[3], lotofacil_bolas_giradas[4],
                lotofacil_bolas_giradas[5], lotofacil_bolas_giradas[6],
                lotofacil_bolas_giradas[7], lotofacil_bolas_giradas[8],
                lotofacil_bolas_giradas[9], lotofacil_bolas_giradas[10],
                lotofacil_bolas_giradas[11], lotofacil_bolas_giradas[12],
                lotofacil_bolas_giradas[13], lotofacil_bolas_giradas[14],
                lotofacil_bolas_giradas[15], lotofacil_bolas_giradas[16]);
        break;
    case 17:
        ltf_id_girado = obter_deslocamento_17_bolas(
                lotofacil_bolas_giradas[1], lotofacil_bolas_giradas[2],
                lotofacil_bolas_giradas[3], lotofacil_bolas_giradas[4],
                lotofacil_bolas_giradas[5], lotofacil_bolas_giradas[6],
                lotofacil_bolas_giradas[7], lotofacil_bolas_giradas[8],
                lotofacil_bolas_giradas[9], lotofacil_bolas_giradas[10],
                lotofacil_bolas_giradas[11], lotofacil_bolas_giradas[12],
                lotofacil_bolas_giradas[13], lotofacil_bolas_giradas[14],
                lotofacil_bolas_giradas[15], lotofacil_bolas_giradas[16],
                lotofacil_bolas_giradas[17]);
        break;
    case 18:
        ltf_id_girado = obter_deslocamento_18_bolas(
                lotofacil_bolas_giradas[1], lotofacil_bolas_giradas[2],
                lotofacil_bolas_giradas[3], lotofacil_bolas_giradas[4],
                lotofacil_bolas_giradas[5], lotofacil_bolas_giradas[6],
                lotofacil_bolas_giradas[7], lotofacil_bolas_giradas[8],
                lotofacil_bolas_giradas[9], lotofacil_bolas_giradas[10],
                lotofacil_bolas_giradas[11], lotofacil_bolas_giradas[12],
                lotofacil_bolas_giradas[13], lotofacil_bolas_giradas[14],
                lotofacil_bolas_giradas[15], lotofacil_bolas_giradas[16],
                lotofacil_bolas_giradas[17], lotofacil_bolas_giradas[18]
                );
        break;
    }

    fprintf(f_lotofacil_giro, "\n%li;%li;%li;%li;%li", ltf_id, ltf_qt, ltf_id_girado, 90L, qt_de_bolas_em_comum);

    delete[] lotofacil_num_giradas;
    delete[] lotofacil_bolas_giradas;

    return 0;

}


/*!
 * \brief lotofacil_girar_180_graus Gera a combinação girada 90 graus pra direita e grava o conteúdo no arquivo
 * apontado por f_lotofacil_giro.
 * \param ltf_id
 * \param ltf_qt
 * \param lotofacil_bolas
 * \param f_lotofacil_giro
 * \return Retorna 0, se houver sucesso, senão retorna um valor diferente de zero.
 */
long gerar_lotofacil_giro_180_graus(long ltf_id, long ltf_qt, const long * lotofacil_num, FILE * f_lotofacil_giro)
{
    if(!(ltf_qt >= 15 && ltf_qt <= 18))
        return 1;

    long * lotofacil_num_giradas = new long[26];
    long * lotofacil_bolas_giradas = new long[ltf_qt+1];

    // Zera todos os valores do arranjo pra evitar lixo de memória.
    memset(lotofacil_num_giradas, 0, 26UL * sizeof(long));
    memset(lotofacil_bolas_giradas, 0, static_cast<size_t>(ltf_qt * sizeof(long)));

    // Cada valor do arranjo lotofacil_num_giradas, será pra uma nova
    // posição.
    // No arranjo abaixo, por exemplo,
    const long ltf_giro[26] = {
                           0,
                            25, 24, 23, 22, 21,
                            20, 19, 18, 17, 16,
                            15, 14, 13, 12, 11,
                            10,  9,  8,  7,  6,
                             5,  4,  3,  2,  1,
                          };

    // Aqui, iremos mover o valor da posição de origem pra a posição de destino.
    // [1] => [5]
    // [2] => [10]
    // e assim por diante...
    for(long uA = 1; uA <= 25; uA++){
        lotofacil_num_giradas[ltf_giro[uA]] = lotofacil_num[uA];
    }

    // Pega as bolas em ordem crescente.
    long indice_bolas = 1;
    for(long uA = 1; uA <= 25; uA++){
        if(lotofacil_num_giradas[uA]){
            lotofacil_bolas_giradas[indice_bolas] = uA;
            indice_bolas++;
        }
    }

    // Verifica as bolas comuns.
    long qt_de_bolas_em_comum = 0;
    for(long uA = 1; uA <= 25; uA++){
        // Se o valor é zero, continua.
        if(!lotofacil_num_giradas[uA]){
            continue;
        }

        if(lotofacil_num_giradas[uA] == lotofacil_num[uA]){
            qt_de_bolas_em_comum++;
        }
    }

    long ltf_id_girado = 0;
    switch (ltf_qt) {
    case 15:
        ltf_id_girado = obter_deslocamento_15_bolas(
                lotofacil_bolas_giradas[1], lotofacil_bolas_giradas[2],
                lotofacil_bolas_giradas[3], lotofacil_bolas_giradas[4],
                lotofacil_bolas_giradas[5], lotofacil_bolas_giradas[6],
                lotofacil_bolas_giradas[7], lotofacil_bolas_giradas[8],
                lotofacil_bolas_giradas[9], lotofacil_bolas_giradas[10],
                lotofacil_bolas_giradas[11], lotofacil_bolas_giradas[12],
                lotofacil_bolas_giradas[13], lotofacil_bolas_giradas[14],
                lotofacil_bolas_giradas[15]);
        break;
    case 16:
        ltf_id_girado = obter_deslocamento_16_bolas(
                lotofacil_bolas_giradas[1], lotofacil_bolas_giradas[2],
                lotofacil_bolas_giradas[3], lotofacil_bolas_giradas[4],
                lotofacil_bolas_giradas[5], lotofacil_bolas_giradas[6],
                lotofacil_bolas_giradas[7], lotofacil_bolas_giradas[8],
                lotofacil_bolas_giradas[9], lotofacil_bolas_giradas[10],
                lotofacil_bolas_giradas[11], lotofacil_bolas_giradas[12],
                lotofacil_bolas_giradas[13], lotofacil_bolas_giradas[14],
                lotofacil_bolas_giradas[15], lotofacil_bolas_giradas[16]);
        break;
    case 17:
        ltf_id_girado = obter_deslocamento_17_bolas(
                lotofacil_bolas_giradas[1], lotofacil_bolas_giradas[2],
                lotofacil_bolas_giradas[3], lotofacil_bolas_giradas[4],
                lotofacil_bolas_giradas[5], lotofacil_bolas_giradas[6],
                lotofacil_bolas_giradas[7], lotofacil_bolas_giradas[8],
                lotofacil_bolas_giradas[9], lotofacil_bolas_giradas[10],
                lotofacil_bolas_giradas[11], lotofacil_bolas_giradas[12],
                lotofacil_bolas_giradas[13], lotofacil_bolas_giradas[14],
                lotofacil_bolas_giradas[15], lotofacil_bolas_giradas[16],
                lotofacil_bolas_giradas[17]);
        break;
    case 18:
        ltf_id_girado = obter_deslocamento_18_bolas(
                lotofacil_bolas_giradas[1], lotofacil_bolas_giradas[2],
                lotofacil_bolas_giradas[3], lotofacil_bolas_giradas[4],
                lotofacil_bolas_giradas[5], lotofacil_bolas_giradas[6],
                lotofacil_bolas_giradas[7], lotofacil_bolas_giradas[8],
                lotofacil_bolas_giradas[9], lotofacil_bolas_giradas[10],
                lotofacil_bolas_giradas[11], lotofacil_bolas_giradas[12],
                lotofacil_bolas_giradas[13], lotofacil_bolas_giradas[14],
                lotofacil_bolas_giradas[15], lotofacil_bolas_giradas[16],
                lotofacil_bolas_giradas[17], lotofacil_bolas_giradas[18]
                );
        break;
    }

    fprintf(f_lotofacil_giro, "\n%li;%li;%li;%li;%li", ltf_id, ltf_qt, ltf_id_girado, 180L, qt_de_bolas_em_comum);

    delete[] lotofacil_num_giradas;
    delete[] lotofacil_bolas_giradas;

    return 0;

}

/*!
 * \brief lotofacil_girar_270_graus Gera a combinação girada 90 graus pra direita e grava o conteúdo no arquivo
 * apontado por f_lotofacil_giro.
 * \param ltf_id
 * \param ltf_qt
 * \param lotofacil_bolas
 * \param f_lotofacil_giro
 * \return Retorna 0, se houver sucesso, senão retorna um valor diferente de zero.
 */
long gerar_lotofacil_giro_270_graus(long ltf_id, long ltf_qt, const long * lotofacil_num, FILE * f_lotofacil_giro)
{
    if(!(ltf_qt >= 15 && ltf_qt <= 18))
        return 1;

    long * lotofacil_num_giradas = new long[26];
    long * lotofacil_bolas_giradas = new long[ltf_qt+1];

    // Zera todos os valores do arranjo pra evitar lixo de memória.
    memset(lotofacil_num_giradas, 0, 26UL * sizeof(long));
    memset(lotofacil_bolas_giradas, 0, static_cast<size_t>(ltf_qt * sizeof(long)));

    // Cada valor do arranjo lotofacil_num_giradas, será pra uma nova
    // posição.
    // No arranjo abaixo, por exemplo,
    const long ltf_giro[26] = {
                           0,
                            21, 16, 11, 6,  1,
                            22, 17, 12, 7,  2,
                            23, 18, 13, 8,  3,
                            24, 19, 14, 9,  4,
                            25, 20, 15, 10, 5
                          };

    // Aqui, iremos mover o valor da posição de origem pra a posição de destino.
    // [1] => [5]
    // [2] => [10]
    // e assim por diante...
    for(long uA = 1; uA <= 25; uA++){
        lotofacil_num_giradas[ltf_giro[uA]] = lotofacil_num[uA];
    }

    // Pega as bolas em ordem crescente.
    long indice_bolas = 1;
    for(long uA = 1; uA <= 25; uA++){
        if(lotofacil_num_giradas[uA]){
            lotofacil_bolas_giradas[indice_bolas] = uA;
            indice_bolas++;
        }
    }

    // Verifica as bolas comuns.
    long qt_de_bolas_em_comum = 0;
    for(long uA = 1; uA <= 25; uA++){
        // Se o valor é zero, continua.
        if(!lotofacil_num_giradas[uA]){
            continue;
        }

        if(lotofacil_num_giradas[uA] == lotofacil_num[uA]){
            qt_de_bolas_em_comum++;
        }
    }

    long ltf_id_girado = 0;
    switch (ltf_qt) {
    case 15:
        ltf_id_girado = obter_deslocamento_15_bolas(
                lotofacil_bolas_giradas[1], lotofacil_bolas_giradas[2],
                lotofacil_bolas_giradas[3], lotofacil_bolas_giradas[4],
                lotofacil_bolas_giradas[5], lotofacil_bolas_giradas[6],
                lotofacil_bolas_giradas[7], lotofacil_bolas_giradas[8],
                lotofacil_bolas_giradas[9], lotofacil_bolas_giradas[10],
                lotofacil_bolas_giradas[11], lotofacil_bolas_giradas[12],
                lotofacil_bolas_giradas[13], lotofacil_bolas_giradas[14],
                lotofacil_bolas_giradas[15]);
        break;
    case 16:
        ltf_id_girado = obter_deslocamento_16_bolas(
                lotofacil_bolas_giradas[1], lotofacil_bolas_giradas[2],
                lotofacil_bolas_giradas[3], lotofacil_bolas_giradas[4],
                lotofacil_bolas_giradas[5], lotofacil_bolas_giradas[6],
                lotofacil_bolas_giradas[7], lotofacil_bolas_giradas[8],
                lotofacil_bolas_giradas[9], lotofacil_bolas_giradas[10],
                lotofacil_bolas_giradas[11], lotofacil_bolas_giradas[12],
                lotofacil_bolas_giradas[13], lotofacil_bolas_giradas[14],
                lotofacil_bolas_giradas[15], lotofacil_bolas_giradas[16]);
        break;
    case 17:
        ltf_id_girado = obter_deslocamento_17_bolas(
                lotofacil_bolas_giradas[1], lotofacil_bolas_giradas[2],
                lotofacil_bolas_giradas[3], lotofacil_bolas_giradas[4],
                lotofacil_bolas_giradas[5], lotofacil_bolas_giradas[6],
                lotofacil_bolas_giradas[7], lotofacil_bolas_giradas[8],
                lotofacil_bolas_giradas[9], lotofacil_bolas_giradas[10],
                lotofacil_bolas_giradas[11], lotofacil_bolas_giradas[12],
                lotofacil_bolas_giradas[13], lotofacil_bolas_giradas[14],
                lotofacil_bolas_giradas[15], lotofacil_bolas_giradas[16],
                lotofacil_bolas_giradas[17]);
        break;
    case 18:
        ltf_id_girado = obter_deslocamento_18_bolas(
                lotofacil_bolas_giradas[1], lotofacil_bolas_giradas[2],
                lotofacil_bolas_giradas[3], lotofacil_bolas_giradas[4],
                lotofacil_bolas_giradas[5], lotofacil_bolas_giradas[6],
                lotofacil_bolas_giradas[7], lotofacil_bolas_giradas[8],
                lotofacil_bolas_giradas[9], lotofacil_bolas_giradas[10],
                lotofacil_bolas_giradas[11], lotofacil_bolas_giradas[12],
                lotofacil_bolas_giradas[13], lotofacil_bolas_giradas[14],
                lotofacil_bolas_giradas[15], lotofacil_bolas_giradas[16],
                lotofacil_bolas_giradas[17], lotofacil_bolas_giradas[18]
                );
        break;
    }


    fprintf(f_lotofacil_giro, "\n%li;%li;%li;%li;%li", ltf_id, ltf_qt, ltf_id_girado, 270L, qt_de_bolas_em_comum);

    delete[] lotofacil_num_giradas;
    delete[] lotofacil_bolas_giradas;


    return 0;

}




