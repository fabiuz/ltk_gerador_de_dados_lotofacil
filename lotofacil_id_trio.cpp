/**
  Autor:    Fábio Moura de Oliveira

  Descrição:    Gera um arquivo 'lotofacil_id_trio.csv' com todas as combinações
  de trios válidas na lotofacil e atribui a cada combinação um identificador exclusivo.

  Trio na lotofacil, é um grupo de 3 bolas distintas entre si.
  Há na lotofacil 25 bolas, sendo possível ter 8 trios, restando uma bola.
  Neste caso, a bola restante fica em um dos trios.
  Então haverá 23 trios e 1 trio com 4 bolas.

**/

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>

static long trio_id[4][4][4][4][4][4][4][5][2];

const long QT_TOTAL_DE_BOLAS = 3;
const long QT_TOTAL_DE_BOLAS_ULTIMO_INDICE = 4;
const unsigned long QT_BOLAS_ALOCADAS = static_cast<unsigned long>(pow(4, 7)) * 5 * 2;

/*!
 * \brief obter_trio_id
 * \param qt_trio_1  Quantidade de bolas na seção trio 1.
 * \param qt_trio_2  Quantidade de bolas na seção trio 2.
 * \param qt_trio_3  Quantidade de bolas na seção trio 3.
 * \param qt_trio_4  Quantidade de bolas na seção trio 4.
 * \param qt_trio_5  Quantidade de bolas na seção trio 5.
 * \param qt_trio_6  Quantidade de bolas na seção trio 6.
 * \param qt_trio_7  Quantidade de bolas na seção trio 7.
 * \param qt_trio_8  Quantidade de bolas na seção trio 8.
 * \return
 *  Retorna o identificador da combinação trio se válido, ou,
 * retorna -1 se a combinação for inválida.
 */
long obter_trio_id(long qt_trio_1, long qt_trio_2, long qt_trio_3,
                              long qt_trio_4, long qt_trio_5, long qt_trio_6,
                              long qt_trio_7, long qt_trio_8){

    bool b_qt_trio = (qt_trio_1 >= 0) && (qt_trio_1 <= QT_TOTAL_DE_BOLAS) &&
                    (qt_trio_2 >= 0) && (qt_trio_2 <= QT_TOTAL_DE_BOLAS) &&
                    (qt_trio_3 >= 0) && (qt_trio_3 <= QT_TOTAL_DE_BOLAS) &&
                    (qt_trio_4 >= 0) && (qt_trio_4 <= QT_TOTAL_DE_BOLAS) &&
                    (qt_trio_5 >= 0) && (qt_trio_5 <= QT_TOTAL_DE_BOLAS) &&
                    (qt_trio_6 >= 0) && (qt_trio_6 <= QT_TOTAL_DE_BOLAS) &&
                    (qt_trio_7 >= 0) && (qt_trio_7 <= QT_TOTAL_DE_BOLAS) &&
                    (qt_trio_8 >= 0) && (qt_trio_8 <= QT_TOTAL_DE_BOLAS_ULTIMO_INDICE);

    if(!b_qt_trio)
        return -1;

    long soma_qt_trio = qt_trio_1 + qt_trio_2 + qt_trio_3 + qt_trio_4 + qt_trio_5 + qt_trio_6 +
                        qt_trio_7 + qt_trio_8;
    bool b_soma_qt_trio = (soma_qt_trio >= 15) && (soma_qt_trio <= 18);

    if(!b_soma_qt_trio)
        return -1;

    return trio_id[qt_trio_1][qt_trio_2][qt_trio_3][qt_trio_4][qt_trio_5][qt_trio_6][qt_trio_7][qt_trio_8][0];
}

bool gerar_trio_id(){
    FILE * f_trio = fopen("./arquivos_csv/lotofacil_id_trio.csv", "w");
    if(!f_trio){
        fprintf(stderr, "Erro ao abrir arquivo lotofacil_id_trio.csv pra gravaçao");
        return false;
    }

    int id_combinacao = 0;

    // Grava cabecalho.
    fprintf(f_trio, "tr_id;tr_qt;tr_1;tr_2;tr_3;tr_4;tr_5;tr_6;tr_7;tr_8");

    if(ferror(f_trio)){
        fprintf(stderr, "Erro ao gravar cabecalho no arquivo lotofacil_id_trio.cpp");
        return false;
    }

    // Reseta o valor das variaveis
    memset(trio_id, 0, sizeof(long) * QT_BOLAS_ALOCADAS);

    for(int b1 = 0; b1 <= QT_TOTAL_DE_BOLAS; b1++)
    for(int b2 = 0; b2 <= QT_TOTAL_DE_BOLAS; b2++)
    for(int b3 = 0; b3 <= QT_TOTAL_DE_BOLAS; b3++)
    for(int b4 = 0; b4 <= QT_TOTAL_DE_BOLAS; b4++)
    for(int b5 = 0; b5 <= QT_TOTAL_DE_BOLAS; b5++)
    for(int b6 = 0; b6 <= QT_TOTAL_DE_BOLAS; b6++)
    for(int b7 = 0; b7 <= QT_TOTAL_DE_BOLAS; b7++)
    for(int b8 = 0; b8 <= QT_TOTAL_DE_BOLAS_ULTIMO_INDICE; b8++)
    {
        int soma_combinacao = b1 + b2 + b3 + b4 + b5 + b6 + b7 + b8;
        if((soma_combinacao >= 15) && (soma_combinacao <= 18)){
            id_combinacao++;

            trio_id[b1][b2][b3][b4][b5][b6][b7][b8][0] = id_combinacao;
            trio_id[b1][b2][b3][b4][b5][b6][b7][b8][1] = 0;

            fprintf(f_trio, "\n%i;%i;%i;%i;%i;%i;%i;%i;%i;%i", id_combinacao, soma_combinacao, b1, b2, b3, b4, b5, b6, b7, b8);

            if(ferror(f_trio)){
                fprintf(stderr, "Erro ao gravar em um dos arquivos: lotofacil_id_trio,"
                                "lotofacil_id_vertical, lotofacil_id_diagonal, lotofacil_id_cruzeta");
                return false;
            }
        }
    }

    fclose(f_trio);
    return true;
}
