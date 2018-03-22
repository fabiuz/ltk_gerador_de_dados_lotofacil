/**
  Autor:    Fábio Moura de Oliveira
  Programa: ltk_gerador_de_dados_lotofacil

  Algoritmo pra gerar ids pra cada combinação de externo x interno da lotofacil.

*/
#include <cstdlib>
#include <cstdio>
#include <cstring>

/**
    Na lotofacil, há no máximo 16 externos e 9 internos.
**/
const long QT_DE_EXTERNOS = 16;
const long QT_DE_INTERNOS = 9;
const unsigned long QT_DE_EXTERNOS_ALOCADOS = QT_DE_EXTERNOS + 1;
const unsigned long QT_DE_INTERNOS_ALOCADOS = QT_DE_INTERNOS + 1;
const unsigned long QT_DE_BOLAS_ALOCADAS = sizeof(long) * QT_DE_EXTERNOS_ALOCADOS * QT_DE_INTERNOS_ALOCADOS * 2;

static long externo_interno_id[QT_DE_EXTERNOS_ALOCADOS][QT_DE_INTERNOS_ALOCADOS][2];

bool gerar_externo_interno_comum_id();
bool gerar_externo_interno_id();

/**
 * @brief obter_externo_interno_id
 *  Retorna o id da combinação externa x interna válida na lotofacil.
 * @param qt_externo
 *  Quantidade de bolas na seção externa.
 * @param qt_interno
 *  Quantidade de bolas na seção interna.
 * @return
 *  Retorna o id da combinação externa x interna válida na lotofacil ou
 * retorna -1 se a combinação for inválida na lotofácil.
 */
long obter_externo_interno_id(long qt_externo, long qt_interno){

    long soma_externo_interno = qt_externo + qt_interno;
    bool b_soma_externo_interno = (soma_externo_interno >= 15) && (soma_externo_interno <= 18);

    if(!b_soma_externo_interno)
        return -1;

    bool b_externo = (qt_externo >= 0) && (qt_externo <= QT_DE_EXTERNOS);

    if(!b_externo)
        return -1;

    bool b_interno = (qt_interno >= 0) && (qt_interno <= QT_DE_INTERNOS);

    if(!b_interno)
        return -1;

    return externo_interno_id[qt_externo][qt_interno][0];
}


/**
    Gera as combinaçoes comuns a combinacao atual.
**/
bool gerar_externo_interno_comum_id(){

    FILE * f_externo_interno_comum = fopen("./arquivos_csv/lotofacil_id_externo_interno_comum.csv", "w");

    if(!f_externo_interno_comum){
        fprintf(stderr, "Erro ao abrir arquivo: lotofacil_id_externo_interno.csv");
        return false;
    }

    fprintf(f_externo_interno_comum, "comum_id;externo_interno_id;externo_interno_id_comum");

    long soma_externo_interno_1 = 0;
    long soma_externo_interno_2 = 0;
    long comum_id = 0;

    for(int externo_1 = 0; externo_1 <= QT_DE_EXTERNOS; externo_1++)
    for(int interno_1 = 0; interno_1 <= QT_DE_INTERNOS; interno_1++){

        soma_externo_interno_1 = externo_1 + interno_1;

        if((soma_externo_interno_1 >= 15) && (soma_externo_interno_1 <= 18)){

                long id_externo_interno_1 = externo_interno_id[externo_1][interno_1][0];

                for(int externo_2 = 0; externo_2 <= QT_DE_EXTERNOS; externo_2++)
                for(int interno_2 = 0; interno_2 <= QT_DE_INTERNOS; interno_2++){

                    long soma_externo_interno_2 = externo_2 + interno_2;

                    if((soma_externo_interno_2 >= 15) && (soma_externo_interno_2 <= 18)){
                        long id_externo_interno_2 = externo_interno_id[externo_2][interno_2][0];
                        bool comum_localizado = false;

                        // Vamos detectar possivel combinacao comum.
                        for(int uA = 0; uA <= 3; uA++){
                            long interno_3 = uA;
                            for(long externo_3 = 0; externo_3 <= uA; externo_3++){
                                long externo_4 = externo_1 + externo_3;
                                long interno_4 = interno_1 + interno_3;

                                if((externo_4 == externo_2) && (interno_4 == interno_2)){
                                    comum_localizado = true;
                                    break;
                                }

                                externo_4 = externo_1 - externo_3;
                                interno_4 = interno_1 - interno_3;

                                if((externo_4 == externo_2) && (interno_4 == interno_2)){
                                    comum_localizado = true;
                                    break;
                                }
                                interno_3--;
                            }
                            if(comum_localizado){
                                break;
                            }
                        }

                        if(comum_localizado)
                        {
                            comum_id++;

                            fprintf(f_externo_interno_comum, "\n%li;%li;%li", comum_id, id_externo_interno_1, id_externo_interno_2);

                            if(ferror(f_externo_interno_comum)){
                                fprintf(stderr, "Erro ao gravar dados no arquivo 'lotofacil_id_externo_interno.csv'.");
                                return false;
                            }
                        }
                    }
                }
        }
    }

    fclose(f_externo_interno_comum);
    return true;
}


/**
 * @brief gerar_externo_interno_id
 * Gera todas as combinações externo x interna válidas da lotofacil e atribui
 * a cada combinação um identificador
 * @return
 */
/*!
 * \brief gerar_externo_interno_id
 * \return
 */
bool gerar_externo_interno_id(){

    FILE * f_externo_interno = fopen("./arquivos_csv/lotofacil_id_externo_interno.csv", "w");
    if(!f_externo_interno){
        fprintf(stderr, "Erro ao abrir arquivo: lotofacil_id_externo_interno.csv");
        return false;
    }

    fprintf(f_externo_interno, "externo_interno_id;externo_interno_qt;externo;interno");

    memset(externo_interno_id, 0, QT_DE_BOLAS_ALOCADAS);

    long id_externo_interno = 0;
    long soma_externo_interno = 0;

    for(int externo = 0; externo <= QT_DE_EXTERNOS; externo++)
    for(int interno = 0; interno <= QT_DE_INTERNOS; interno++){
        soma_externo_interno = externo + interno;

        if((soma_externo_interno >= 15) && (soma_externo_interno <= 18)){
            id_externo_interno++;
            externo_interno_id[externo][interno][0] = id_externo_interno;
            externo_interno_id[externo][interno][1] = 0;

            fprintf(f_externo_interno, "\n%li;%li;%i;%i", id_externo_interno, soma_externo_interno, externo, interno);
        }
    }

    fclose(f_externo_interno);
    return gerar_externo_interno_comum_id();
}
