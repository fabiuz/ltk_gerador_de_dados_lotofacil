/**
 *
 * Objetivo:    Gerar id pra a análise baseada em algarismo na casa das dezenas.
 * Autor:       Fábio Moura de Oliveira.
 * Data:        17/4/2018
 * Descrição:
 *      Em matemática um número é composto de algarismo, se o número
 *      é da base 10, então, os algarismos são: 0, 1, 2, 3, 4, 5, 6, 7, 8 e 9.
 *      Um algarismo em um número pode ter um valor absoluto e um valor relativo.
 *      Valor absoluto de um algarismo
 *
 **/

#include "lotofacil_algarismo_na_dezena.hpp"

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <list>
using namespace std;

/**
 * @brief gerar_algarismo_na_dezena_id_comum
 * Uma combinação é comum a outra, se e somente, se
 * a quantidade de bolas de uma combinação é diferente da outra combinação
 * e ao retirar a diferença de um dos conjuntos, a quantidade de bolas
 * de cada conjunto seja igua
 * @return
 */
bool gerar_algarismo_na_dezena_id_subconjunto(){
    const long incremento_decremento[20][3] = {
        { 0, 0, 0 },
        { 0, 0, 1 },
        { 0, 0, 2 },
        { 0, 0, 3 },
        { 0, 1, 0 },
        { 0, 1, 1 },
        { 0, 1, 2 },
        { 0, 2, 0 },
        { 0, 2, 1 },
        { 0, 3, 0 },
        { 1, 0, 0 },
        { 1, 0, 1 },
        { 1, 0, 2 },
        { 1, 1, 0 },
        { 1, 1, 1 },
        { 1, 2, 0 },
        { 2, 0, 0 },
        { 2, 0, 1 },
        { 2, 1, 0 },
        { 3, 0, 0 },
    };

    FILE * f_algarismo_na_dezena_id_comum = fopen("./arquivos_csv/lotofacil_id_algarismo_na_dezena_subconjunto.csv", "w");

    if(!f_algarismo_na_dezena_id_comum){
        return false;
    }

    // Cabeçalho do arquivo.
    fprintf(f_algarismo_na_dezena_id_comum, "id_comum;dz_id;dz_id_comum");

    // Valor máximo de cada coluna da esquerda pra direita da combinação 'algarismo_na_dezena':
    // qt_dezena_0: 9  ítens, números de 1 a 9.
    // qt_dezena_1: 10 ítens, números de 10 a 19.
    // qt_dezena_2: 6 ítens, números de 20 a 25.

    // Iremos comparar cada combinação válida pra 'algarismo_na_dezena' com
    // todas as outras combinações também válidas pra 'algarismo_na_dezena'
    // se a combinação for subconjunto da outra combinação iremos
    // gravar uma nova linha no arquivo com neste formato:
    // id_comum;dz_id;dz_id_comum.

    long id_comum = 0;
    for(long qt_dezena_0 = 0; qt_dezena_0 <= 9; qt_dezena_0++)
    {
        for(long qt_dezena_1 = 0; qt_dezena_1 <= 10; qt_dezena_1++)
        {
            for(long qt_dezena_2 = 0; qt_dezena_2 <= 6; qt_dezena_2++)
            {
                long qt_soma_dezena = qt_dezena_0 + qt_dezena_1 + qt_dezena_2;
                long id_dezena_0_1_2 = obter_algarismo_na_dezena_id(qt_dezena_0, qt_dezena_1, qt_dezena_2);

                // Um combinação só é valida se a quantidade de bolas for válida na lotofacil
                // se não for continuar o loop.
                if(!((qt_soma_dezena >= 15) && (qt_soma_dezena <= 18))){
                    continue;
                }

                // Pra identificar que a combinação formada por
                // qt_dezena_0, qt_dezena_1 e qt_dezena está contida em ou contém
                // a outra combinação, iremos aplicar pra cada conjunto desta combinação
                // um incremento e um decremento conforme o valor armazenado no
                // arranjo incremento_decremento, se após este decremento
                // o valor de cada elemento do conjunto da esquerda pra direita da combinação
                // for igual a outra combinação quer dizer que é subconjunto.

                for(long qt_dezena_3 = 0; qt_dezena_3 <= 9; qt_dezena_3++)
                {
                    for(long qt_dezena_4 = 0; qt_dezena_4 <= 10; qt_dezena_4++)
                    {
                        for(long qt_dezena_5 = 0; qt_dezena_5 <= 6; qt_dezena_5++)
                        {
                            long qt_soma_dezena = qt_dezena_3 + qt_dezena_4 + qt_dezena_5;

                            // Um combinação só é valida se a quantidade de bolas for válida na lotofacil
                            // se não for continuar o loop.
                            if(!((qt_soma_dezena >= 15) && (qt_soma_dezena <= 18))){
                                continue;
                            }

                            // Agora, iremos aplicar incremento e decremento
                            // Se após o incremento e/ou decremento os valores de cada
                            // subconjunto da combinação for igual a outra combinação
                            // quer dizer que uma combinação é complementar a outra.
                            std::list<long> lista_de_id = list<long>();
                            lista_de_id.clear();

                            for(long uA = 0; uA < 20; uA++)
                            {
                                long qt_dezena_6 = qt_dezena_3 + incremento_decremento[uA][0];
                                long qt_dezena_7 = qt_dezena_4 + incremento_decremento[uA][1];
                                long qt_dezena_8 = qt_dezena_5 + incremento_decremento[uA][2];

                                // Um combinação só é valida se a quantidade de bolas for válida na lotofacil
                                // se não for continuar o loop.
                                long qt_soma_dezena = qt_dezena_6 + qt_dezena_7 + qt_dezena_8;

                                // Verifica se a quantidade de bolas está dentro da faixa de
                                // quantidade de bolas válidas da lotofacil.
                                if((qt_soma_dezena >= 15) && (qt_soma_dezena <= 18)){
                                    // Agora, verifica se a quantidade de bolas está dentro da faixa
                                    // válida pra a análise 'algarismo_na_dezena'.
                                    if(
                                            (qt_dezena_6 >= 0) && (qt_dezena_6 <= 9) &&
                                            (qt_dezena_7 >= 0) && (qt_dezena_7 <= 10) &&
                                            (qt_dezena_8 >= 0) && (qt_dezena_8 <= 6))
                                    {
                                        // Agora, verificar se cada combinação é subconjunta de outra.
                                        if(
                                                (qt_dezena_0 == qt_dezena_6) &&
                                                (qt_dezena_1 == qt_dezena_7) &&
                                                (qt_dezena_2 == qt_dezena_8))
                                        {
                                            long id_dezena_3_4_5 = obter_algarismo_na_dezena_id(qt_dezena_3, qt_dezena_4, qt_dezena_5);
                                            lista_de_id.push_back(id_dezena_3_4_5);
                                        }
                                    }
                                }

                                qt_dezena_6 = qt_dezena_3 - incremento_decremento[uA][0];
                                qt_dezena_7 = qt_dezena_4 - incremento_decremento[uA][1];
                                qt_dezena_8 = qt_dezena_5 - incremento_decremento[uA][2];

                                // Um combinação só é valida se a quantidade de bolas for válida na lotofacil
                                // se não for continuar o loop.
                                qt_soma_dezena = qt_dezena_6 + qt_dezena_7 + qt_dezena_8;

                                // Verifica se a quantidade de bolas está dentro da faixa de
                                // quantidade de bolas válidas da lotofacil.
                                if((qt_soma_dezena >= 15) && (qt_soma_dezena <= 18)){
                                    // Agora, verifica se a quantidade de bolas está dentro da faixa
                                    // válida pra a análise 'algarismo_na_dezena'.
                                    if(
                                            (qt_dezena_6 >= 0) && (qt_dezena_6 <= 9) &&
                                            (qt_dezena_7 >= 0) && (qt_dezena_7 <= 10) &&
                                            (qt_dezena_8 >= 0) && (qt_dezena_8 <= 6))
                                    {
                                        // Agora, verificar se cada combinação é subconjunta de outra.
                                        if(
                                                (qt_dezena_0 == qt_dezena_6) &&
                                                (qt_dezena_1 == qt_dezena_7) &&
                                                (qt_dezena_2 == qt_dezena_8))
                                        {
                                            long id_dezena_3_4_5 = obter_algarismo_na_dezena_id(qt_dezena_3, qt_dezena_4, qt_dezena_5);
                                            lista_de_id.push_back(id_dezena_3_4_5);
                                        }
                                    }
                                }
                            }

                            if(!lista_de_id.empty()){
                                lista_de_id.unique();
                                lista_de_id.sort();


                                for(std::list<long>::iterator it = lista_de_id.begin(); it != lista_de_id.end(); ++it){
                                    fprintf(f_algarismo_na_dezena_id_comum, "\n%li;%li;%li", ++id_comum, id_dezena_0_1_2, *it);
                                }
                                lista_de_id.clear();
                            }

                        }
                    }
                }
            }
        }
    }

    fclose(f_algarismo_na_dezena_id_comum);

    return true;
}


/**
 * @brief gerar_algarismo_na_dezena_id
 * Gera id referente a contabilização de quantas bolas começa com 0, 1 ou 2.
 * Ou seja, o algarismo na posição da dezena, identifica se a bola começa
 * com 0, 1 ou 2.
 * Por exemplo, a combinação:
 * 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
 * tem 9 bolas que começa com 1;
 * tem 6 bolas que começa com 2;
 * @return
 */
bool gerar_algarismo_na_dezena_id(){

    FILE * f_algarismo_na_dezena = fopen("./arquivos_csv/lotofacil_id_algarismo_na_dezena.csv", "w");

    if(!f_algarismo_na_dezena){
        return false;
    }

    fprintf(f_algarismo_na_dezena, "dz_id;ltf_qt;qt_dz_0;qt_dz_1;qt_dz_2");

    long dezena_id = 0;

    // Vamos gerar todos os ids de 15 bolas, depois 16, 17 e 18.
    for(long ltf_qt = 15; ltf_qt <= 18; ltf_qt++){
        for(long qt_dezena_0 = 0; qt_dezena_0 <= 9; qt_dezena_0++)
            for(long qt_dezena_1 = 0; qt_dezena_1 <= 10; qt_dezena_1++)
                for(long qt_dezena_2 = 0; qt_dezena_2 <= 6; qt_dezena_2++)
                {
                    long qt_soma = qt_dezena_0 + qt_dezena_1 + qt_dezena_2;

                    if(qt_soma == ltf_qt)
                    {
                        dezena_id++;
                        fprintf(f_algarismo_na_dezena,
                                "\n%li;%li;%li;%li;%li",
                                dezena_id,
                                ltf_qt,
                                qt_dezena_0,
                                qt_dezena_1,
                                qt_dezena_2
                                );
                        algarismo_na_dezena_id[qt_dezena_0][qt_dezena_1][qt_dezena_2] = dezena_id;
                    }
                }
    }

    fclose(f_algarismo_na_dezena);

    gerar_algarismo_na_dezena_id_subconjunto();

    return true;
}

/**
 * @brief obter_algarismo_na_dezena_id
 *  Obtém o identificador conforme a quantidade de bolas que começa com 0, 1 e 2.
 * Retorna -1, se houver algum erro.
 * @param qt_dezena_0
 * @param qt_dezena_1
 * @param qt_dezena_2
 * @return
 */
long obter_algarismo_na_dezena_id(long qt_dezena_0, long qt_dezena_1, long qt_dezena_2){

    if((qt_dezena_0 < 0) || (qt_dezena_0 > 9))
        return -1;

    if((qt_dezena_1 < 0) || (qt_dezena_1 > 10))
        return -1;

    if((qt_dezena_2 < 0) || (qt_dezena_2 > 6))
        return -1;

    long qt_soma = qt_dezena_0 + qt_dezena_1 + qt_dezena_2;

    if((qt_soma < 15) && (qt_soma > 18))
        return - 1;

    return algarismo_na_dezena_id[qt_dezena_0][qt_dezena_1][qt_dezena_2];
}
