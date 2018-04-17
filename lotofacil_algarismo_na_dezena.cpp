#include "lotofacil_algarismo_na_dezena.hpp"

#include <cstdio>

/**
 * @brief gerar_algarismo_na_dezena_id_comum
 * Uma combinação é comum a outra, se e somente, se
 * a quantidade de bolas de uma combinação é diferente da outra combinação
 * e ao retirar a diferença de um dos conjuntos, a quantidade de bolas
 * de cada conjunto seja igua
 * @return
 */
bool gerar_algarismo_na_dezena_id_comum(){

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
