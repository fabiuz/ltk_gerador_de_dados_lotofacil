#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>

static long horizontal_id[6][6][6][6][6][2];
static long vertical_id[6][6][6][6][6][2];
static long diagonal_id[6][6][6][6][6][2];
static long cruzeta_id[6][6][6][6][6][2];

const long QT_TOTAL_DE_BOLAS = 5;
const unsigned long QT_TOTAL_DE_BOLAS_ALOCADAS = sizeof(long) * static_cast<unsigned long>(pow(6, 5)) * 2L;

/*!
 * \brief obter_horizontal_id
 * \param qt_hrz_1  Quantidade de bolas na seção horizontal 1.
 * \param qt_hrz_2  Quantidade de bolas na seção horizontal 2.
 * \param qt_hrz_3  Quantidade de bolas na seção horizontal 3.
 * \param qt_hrz_4  Quantidade de bolas na seção horizontal 4.
 * \param qt_hrz_5  Quantidade de bolas na seção horizontal 5.
 * \return
 *  Retorna o identificador da combinação horizontal se válido, ou,
 * retorna -1 se a combinação for inválida.
 */
long obter_horizontal_id(long qt_hrz_1, long qt_hrz_2, long qt_hrz_3, long qt_hrz_4, long qt_hrz_5){

    bool b_qt_hrz = (qt_hrz_1 >= 0) && (qt_hrz_1 <= QT_TOTAL_DE_BOLAS) &&
                    (qt_hrz_2 >= 0) && (qt_hrz_2 <= QT_TOTAL_DE_BOLAS) &&
                    (qt_hrz_3 >= 0) && (qt_hrz_3 <= QT_TOTAL_DE_BOLAS) &&
                    (qt_hrz_4 >= 0) && (qt_hrz_4 <= QT_TOTAL_DE_BOLAS) &&
                    (qt_hrz_5 >= 0) && (qt_hrz_5 <= QT_TOTAL_DE_BOLAS);

    if(!b_qt_hrz)
        return -1;

    long soma_qt_hrz = qt_hrz_1 + qt_hrz_2 + qt_hrz_3 + qt_hrz_4 + qt_hrz_5;
    bool b_soma_qt_hrz = (soma_qt_hrz >= 15) && (soma_qt_hrz <= 18);

    if(!b_soma_qt_hrz)
        return -1;

    return horizontal_id[qt_hrz_1][qt_hrz_2][qt_hrz_3][qt_hrz_4][qt_hrz_5][0];
}

/*!
 * \brief obter_vertical_id
 * \param qt_vrt_1  Quantidade de bolas na seção vertical 1.
 * \param qt_vrt_2  Quantidade de bolas na seção vertical 2.
 * \param qt_vrt_3  Quantidade de bolas na seção vertical 3.
 * \param qt_vrt_4  Quantidade de bolas na seção vertical 4.
 * \param qt_vrt_5  Quantidade de bolas na seção vertical 5.
 * \return
 *  Retorna o identificador da combinação vertical se válido, ou,
 * retorna -1 se a combinação for inválida.
 */
long obter_vertical_id(long qt_vrt_1, long qt_vrt_2, long qt_vrt_3, long qt_vrt_4, long qt_vrt_5){

    bool b_qt_vrt = (qt_vrt_1 >= 0) && (qt_vrt_1 <= QT_TOTAL_DE_BOLAS) &&
                    (qt_vrt_2 >= 0) && (qt_vrt_2 <= QT_TOTAL_DE_BOLAS) &&
                    (qt_vrt_3 >= 0) && (qt_vrt_3 <= QT_TOTAL_DE_BOLAS) &&
                    (qt_vrt_4 >= 0) && (qt_vrt_4 <= QT_TOTAL_DE_BOLAS) &&
                    (qt_vrt_5 >= 0) && (qt_vrt_5 <= QT_TOTAL_DE_BOLAS);

    if(!b_qt_vrt)
        return -1;

    long soma_qt_vrt = qt_vrt_1 + qt_vrt_2 + qt_vrt_3 + qt_vrt_4 + qt_vrt_5;
    bool b_soma_qt_vrt = (soma_qt_vrt >= 15) && (soma_qt_vrt <= 18);

    if(!b_soma_qt_vrt)
        return -1;

    return vertical_id[qt_vrt_1][qt_vrt_2][qt_vrt_3][qt_vrt_4][qt_vrt_5][0];
}

/*!
 * \brief obter_diagonal_id
 * \param qt_dg_1  Quantidade de bolas na seção diagonal 1.
 * \param qt_dg_2  Quantidade de bolas na seção diagonal 2.
 * \param qt_dg_3  Quantidade de bolas na seção diagonal 3.
 * \param qt_dg_4  Quantidade de bolas na seção diagonal 4.
 * \param qt_dg_5  Quantidade de bolas na seção diagonal 5.
 * \return
 *  Retorna o identificador da combinação diagonal se válido, ou,
 * retorna -1 se a combinação for inválida.
 */
long obter_diagonal_id(long qt_dg_1, long qt_dg_2, long qt_dg_3, long qt_dg_4, long qt_dg_5){

    bool b_qt_dg =  (qt_dg_1 >= 0) && (qt_dg_1 <= QT_TOTAL_DE_BOLAS) &&
                    (qt_dg_2 >= 0) && (qt_dg_2 <= QT_TOTAL_DE_BOLAS) &&
                    (qt_dg_3 >= 0) && (qt_dg_3 <= QT_TOTAL_DE_BOLAS) &&
                    (qt_dg_4 >= 0) && (qt_dg_4 <= QT_TOTAL_DE_BOLAS) &&
                    (qt_dg_5 >= 0) && (qt_dg_5 <= QT_TOTAL_DE_BOLAS);

    if(!b_qt_dg)
        return -1;

    long soma_qt_dg = qt_dg_1 + qt_dg_2 + qt_dg_3 + qt_dg_4 + qt_dg_5;
    bool b_soma_qt_dg = (soma_qt_dg >= 15) && (soma_qt_dg <= 18);

    if(!b_soma_qt_dg)
        return -1;

    return diagonal_id[qt_dg_1][qt_dg_2][qt_dg_3][qt_dg_4][qt_dg_5][0];
}

/*!
 * \brief obter_cruzeta_id
 * \param qt_crz_1  Quantidade de bolas na seção cruzeta 1.
 * \param qt_crz_2  Quantidade de bolas na seção cruzeta 2.
 * \param qt_crz_3  Quantidade de bolas na seção cruzeta 3.
 * \param qt_crz_4  Quantidade de bolas na seção cruzeta 4.
 * \param qt_crz_5  Quantidade de bolas na seção cruzeta 5.
 * \return
 *  Retorna o identificador da combinação cruzeta se válido, ou,
 * retorna -1 se a combinação for inválida.
 */
long obter_cruzeta_id(long qt_crz_1, long qt_crz_2, long qt_crz_3, long qt_crz_4, long qt_crz_5){

    bool b_qt_crz = (qt_crz_1 >= 0) && (qt_crz_1 <= QT_TOTAL_DE_BOLAS) &&
                    (qt_crz_2 >= 0) && (qt_crz_2 <= QT_TOTAL_DE_BOLAS) &&
                    (qt_crz_3 >= 0) && (qt_crz_3 <= QT_TOTAL_DE_BOLAS) &&
                    (qt_crz_4 >= 0) && (qt_crz_4 <= QT_TOTAL_DE_BOLAS) &&
                    (qt_crz_5 >= 0) && (qt_crz_5 <= QT_TOTAL_DE_BOLAS);

    if(!b_qt_crz)
        return -1;

    long soma_qt_crz = qt_crz_1 + qt_crz_2 + qt_crz_3 + qt_crz_4 + qt_crz_5;
    bool b_soma_qt_crz = (soma_qt_crz >= 15) && (soma_qt_crz <= 18);

    if(!b_soma_qt_crz)
        return -1;

    return cruzeta_id[qt_crz_1][qt_crz_2][qt_crz_3][qt_crz_4][qt_crz_5][0];
}

/*!
 * \brief gerar_combinacao_com_5_bolas
 * Gera um arquivo csv com todas as combinações válidas e atribui pra cada combinação válida
 * um identificador.
 * Nesta função são geradas as combinações abaixo:
 * horizontal, no arquivo lotofacil_id_horizontal.csv;
 * vertical, no arquivo lotofacil_id_vertical.csv;
 * diagonal, no arquivo lotofacil_id_diagonal.csv;
 * cruzeta, no arquivo lotofacil_id_cruzeta.csv
 *
 * \return
 */
bool gerar_combinacao_com_5_bolas(){
    FILE * f_horizontal = fopen("./arquivos_csv/lotofacil_id_horizontal.csv", "w");
    if(!f_horizontal){
        fprintf(stderr, "Erro ao abrir arquivo lotofacil_id_horizontal.csv pra gravaçao");
        return false;
    }

    FILE * f_vertical = fopen("./arquivos_csv/lotofacil_id_vertical.csv", "w");
    if(!f_vertical){
        fprintf(stderr, "Erro ao abrir arquivo lotofacil_id_vertical.csv pra gravaçao");
        return false;
    }

    FILE * f_diagonal = fopen("./arquivos_csv/lotofacil_id_diagonal.csv", "w");
    if(!f_diagonal){
        fprintf(stderr, "Erro ao abrir arquivo lotofacil_id_diagonal.csv pra gravaçao");
        return false;
    }

    FILE * f_cruzeta = fopen("./arquivos_csv/lotofacil_id_cruzeta.csv", "w");
    if(!f_cruzeta){
        fprintf(stderr, "Erro ao abrir arquivo lotofacil_id_cruzeta.csv pra gravaçao");
        return false;
    }

    int id_combinacao = 0;

    // Grava cabecalho.
    fprintf(f_horizontal, "hrz_id;hrz_qt;hrz_1;hrz_2;hrz_3;hrz_4;hrz_5");
    fprintf(f_vertical, "vrt_id;vrt_qt;vrt_1;vrt_2;vrt_3;vrt_4;vrt_5");
    fprintf(f_diagonal, "dg_id;dg_qt;dg_1;dg_2;dg_3;dg_4;dg_5");
    fprintf(f_cruzeta, "crz_id;crz_qt;crz_1;crz_2;crz_3;crz_4;crz_5");

    // Reseta o valor das variaveis
    memset(horizontal_id, 0, QT_TOTAL_DE_BOLAS_ALOCADAS);
    memset(vertical_id, 0, QT_TOTAL_DE_BOLAS_ALOCADAS);
    memset(diagonal_id, 0, QT_TOTAL_DE_BOLAS_ALOCADAS);
    memset(cruzeta_id, 0, QT_TOTAL_DE_BOLAS_ALOCADAS);

    for(int b1 = 0; b1 <= 5; b1++)
    for(int b2 = 0; b2 <= 5; b2++)
    for(int b3 = 0; b3 <= 5; b3++)
    for(int b4 = 0; b4 <= 5; b4++)
    for(int b5 = 0; b5 <= 5; b5++){
        int soma_combinacao = b1 + b2 + b3 + b4 + b5;
        if((soma_combinacao >= 15) && (soma_combinacao <= 18)){
            id_combinacao++;

            horizontal_id[b1][b2][b3][b4][b5][0] = id_combinacao;
            vertical_id[b1][b2][b3][b4][b5][0] = id_combinacao;
            diagonal_id[b1][b2][b3][b4][b5][0] = id_combinacao;
            cruzeta_id[b1][b2][b3][b4][b5][0] = id_combinacao;

            horizontal_id[b1][b2][b3][b4][b5][1] = 0;
            vertical_id[b1][b2][b3][b4][b5][1] = 0;
            diagonal_id[b1][b2][b3][b4][b5][1] = 0;
            cruzeta_id[b1][b2][b3][b4][b5][1] = 0;

            fprintf(f_horizontal, "\n%i;%i;%i;%i;%i;%i;%i", id_combinacao, soma_combinacao, b1, b2, b3, b4, b5);
            fprintf(f_vertical, "\n%i;%i;%i;%i;%i;%i;%i", id_combinacao, soma_combinacao, b1, b2, b3, b4, b5);
            fprintf(f_diagonal, "\n%i;%i;%i;%i;%i;%i;%i", id_combinacao, soma_combinacao, b1, b2, b3, b4, b5);
            fprintf(f_cruzeta, "\n%i;%i;%i;%i;%i;%i;%i", id_combinacao, soma_combinacao, b1, b2, b3, b4, b5);

            if(ferror(f_horizontal) ||
               ferror(f_vertical) ||
               ferror(f_diagonal) ||
               ferror(f_cruzeta)){
                fprintf(stderr, "Erro ao gravar em um dos arquivos: lotofacil_id_horizontal,"
                                "lotofacil_id_vertical, lotofacil_id_diagonal, lotofacil_id_cruzeta");
                return false;
            }
        }
    }

    fclose(f_horizontal);
    fclose(f_vertical);
    fclose(f_diagonal);
    fclose(f_cruzeta);

    return true;
}
