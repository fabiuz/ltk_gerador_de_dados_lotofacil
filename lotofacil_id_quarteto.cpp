/*!
  Autor:        Fábio Moura de Oliveira

  Descrição:    Gera um arquivo 'lotofacil_id_quarteto.csv' com todas as combinações
  de quartetos válidas na lotofacil e também relacionada a cada combinação é atribuído
  um identificador exclusivo pra aquela combinação.

  Um quarteto é um grupo de 4 bolas.
  Na lotofacil, há 25 bolas, então, é possível ter 6 quartetos, restando 1 bola.
  Neste caso, a bola restante, fica no último quarteto.
  Então, haverá 5 quartetos com 4 bolas e excepcionalmente, uma quarteto com 5 bolas.
  Por este motivo, um das quantidade no arranjo é maior que 1 das demais.
*/


#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>

static long quarteto_id[5][5][5][5][5][6][2];

const long QT_TOTAL_DE_BOLAS = 4;
const long QT_TOTAL_DE_BOLAS_ULTIMO_INDICE = QT_TOTAL_DE_BOLAS + 1;
const unsigned long QT_BOLAS_ALOCADAS = static_cast<unsigned long>(pow(5, 5)) * 6 * 2;

/*!
 * \brief obter_quarteto_id
 * \param qt_qrt_1  Quantidade de bolas na seção quarteto 1.
 * \param qt_qrt_2  Quantidade de bolas na seção quarteto 2.
 * \param qt_qrt_3  Quantidade de bolas na seção quarteto 3.
 * \param qt_qrt_4  Quantidade de bolas na seção quarteto 4.
 * \param qt_qrt_5  Quantidade de bolas na seção quarteto 5.
 * \return
 *  Retorna o identificador da combinação quarteto se válido, ou,
 * retorna -1 se a combinação for inválida.
 */
long obter_quarteto_id(long qt_qrt_1, long qt_qrt_2, long qt_qrt_3, long qt_qrt_4, long qt_qrt_5, long qt_qrt_6){

    bool b_qt_qrt = (qt_qrt_1 >= 0) && (qt_qrt_1 <= QT_TOTAL_DE_BOLAS) &&
                    (qt_qrt_2 >= 0) && (qt_qrt_2 <= QT_TOTAL_DE_BOLAS) &&
                    (qt_qrt_3 >= 0) && (qt_qrt_3 <= QT_TOTAL_DE_BOLAS) &&
                    (qt_qrt_4 >= 0) && (qt_qrt_4 <= QT_TOTAL_DE_BOLAS) &&
                    (qt_qrt_5 >= 0) && (qt_qrt_5 <= QT_TOTAL_DE_BOLAS) &&
                    (qt_qrt_6 >= 0) && (qt_qrt_6 <= QT_TOTAL_DE_BOLAS_ULTIMO_INDICE);

    if(!b_qt_qrt)
        return -1;

    long soma_qt_qrt = qt_qrt_1 + qt_qrt_2 + qt_qrt_3 + qt_qrt_4 + qt_qrt_5 + qt_qrt_6;
    bool b_soma_qt_qrt = (soma_qt_qrt >= 15) && (soma_qt_qrt <= 18);

    if(!b_soma_qt_qrt)
        return -1;

    return quarteto_id[qt_qrt_1][qt_qrt_2][qt_qrt_3][qt_qrt_4][qt_qrt_5][qt_qrt_6][0];
}



bool gerar_quarteto_id(){
    FILE * f_quarteto = fopen("./arquivos_csv/lotofacil_id_quarteto.csv", "w");
    if(!f_quarteto){
        fprintf(stderr, "Erro ao abrir arquivo lotofacil_id_quarteto.csv pra gravaçao");
        return false;
    }

    int id_combinacao = 0;

    // Grava cabecalho.
    fprintf(f_quarteto, "qrt_id;qrt_qt;qrt_1;qrt_2;qrt_3;qrt_4;qrt_5;qrt_6");

    if(ferror(f_quarteto)){
        fprintf(stderr, "Erro ao gravar cabecalho no arquivo lotofacil_id_quarteto.cpp");
        return false;
    }

    // Reseta o valor das variaveis
    memset(quarteto_id, 0, sizeof(long) * QT_BOLAS_ALOCADAS);

    for(int b1 = 0; b1 <= QT_TOTAL_DE_BOLAS; b1++)
    for(int b2 = 0; b2 <= QT_TOTAL_DE_BOLAS; b2++)
    for(int b3 = 0; b3 <= QT_TOTAL_DE_BOLAS; b3++)
    for(int b4 = 0; b4 <= QT_TOTAL_DE_BOLAS; b4++)
    for(int b5 = 0; b5 <= QT_TOTAL_DE_BOLAS; b5++)
    for(int b6 = 0; b6 <= QT_TOTAL_DE_BOLAS_ULTIMO_INDICE; b6++) {
        int soma_combinacao = b1 + b2 + b3 + b4 + b5 + b6;
        if((soma_combinacao >= 15) && (soma_combinacao <= 18)){
            id_combinacao++;

            quarteto_id[b1][b2][b3][b4][b5][b6][0] = id_combinacao;
            quarteto_id[b1][b2][b3][b4][b5][b6][1] = 0;

            fprintf(f_quarteto, "\n%i;%i;%i;%i;%i;%i;%i;%i", id_combinacao, soma_combinacao, b1, b2, b3, b4, b5, b6);

            if(ferror(f_quarteto)){
                fprintf(stderr, "Erro ao gravar em um dos arquivos: lotofacil_id_quarteto,"
                                "lotofacil_id_vertical, lotofacil_id_diagonal, lotofacil_id_cruzeta");
                return false;
            }
        }
    }

    fclose(f_quarteto);
    return true;
}
