/**
  Autor:    Fábio Moura de Oliveira

  Algoritmo pra gerar id pra cada combinação primo x não-primos válidas na lotofacil.

*/

#include <cstdlib>
#include <cstdio>
#include <cstring>

bool gerar_primo_nao_primo_comum_id();
bool gerar_primo_nao_primo_id();

const int QT_DE_PRIMOS = 9;
const int QT_DE_NAO_PRIMOS = 16;
const int QT_DE_PRIMOS_ALOCADOS = QT_DE_PRIMOS + 1;
const int QT_DE_NAO_PRIMOS_ALOCADOS = QT_DE_NAO_PRIMOS + 1;
const unsigned int QT_DE_BOLAS_ALOCADAS = sizeof(long) * QT_DE_PRIMOS_ALOCADOS * QT_DE_NAO_PRIMOS_ALOCADOS * 2;

static long primo_nao_primo_id[QT_DE_PRIMOS_ALOCADOS][QT_DE_NAO_PRIMOS_ALOCADOS][2];

/*!
 * \brief obter_primo_nao_primo_id
 * \param qt_primo  Quantidade de números primos.
 * \param qt_nao_primo  Quantidade de números não-primos.
 * \return Retorna um identificador da combinação primo x não-primo,
 * se a combinação de qt_primo x qt_nao_primo formar uma combinação
 * primo x não-primo válida na lotofacil.
 * Retorna -1 se a combinação fornecida pelos parâmetros qt_primo x qt_nao_primo
 * for inválida na lotofacil.
 */
long obter_primo_nao_primo_id(long qt_primo, long qt_nao_primo){

    long soma_primo_nao_primo = qt_primo + qt_nao_primo;
    bool b_soma_primo_nao_primo = (soma_primo_nao_primo >= 15) && (soma_primo_nao_primo <= 18);

    if(!b_soma_primo_nao_primo)
        return -1;

    bool b_primo = (qt_primo >= 0) && (qt_primo <= QT_DE_PRIMOS);

    if(!b_primo)
        return -1;

    bool b_nao_primo = (qt_nao_primo >= 0) && (qt_nao_primo <= QT_DE_NAO_PRIMOS);

    if(!b_nao_primo)
        return -1;

    return primo_nao_primo_id[qt_primo][qt_nao_primo][0];
}

/*!
 * \brief gerar_primo_nao_primo_id
 * \return
 */
bool gerar_primo_nao_primo_id(){

    FILE * f_primo_nao_primo = fopen("./arquivos_csv/lotofacil_id_primo_nao_primo.csv", "w");
    if(!f_primo_nao_primo){
        fprintf(stderr, "Erro ao abrir arquivo: lotofacil_id_primo_nao_primo.csv");
        return false;
    }

    fprintf(f_primo_nao_primo, "prm_id;prm_qt;primo;nao_primo");

    memset(primo_nao_primo_id, 0, QT_DE_BOLAS_ALOCADAS);

    long id_primo_nao_primo = 0;
    long soma_primo_nao_primo = 0;

    for(int primo = 0; primo <= QT_DE_PRIMOS; primo++)
    for(int nao_primo = 0; nao_primo <= QT_DE_NAO_PRIMOS; nao_primo++){
        soma_primo_nao_primo = primo + nao_primo;

        if((soma_primo_nao_primo >= 15) && (soma_primo_nao_primo <= 18)){
            id_primo_nao_primo++;
            primo_nao_primo_id[primo][nao_primo][0] = id_primo_nao_primo;
            primo_nao_primo_id[primo][nao_primo][1] = id_primo_nao_primo;

            fprintf(f_primo_nao_primo, "\n%li;%li;%i;%i", id_primo_nao_primo, soma_primo_nao_primo, primo, nao_primo);
        }
    }

    fclose(f_primo_nao_primo);
    return gerar_primo_nao_primo_comum_id();
}

/*!
 * \brief gerar_primo_nao_primo_comum_id
 * \return
 */
bool gerar_primo_nao_primo_comum_id(){

    FILE * f_primo_nao_primo_comum = fopen("./arquivos_csv/lotofacil_id_primo_nao_primo_comum.csv", "w");

    if(!f_primo_nao_primo_comum){
        fprintf(stderr, "Erro ao abrir arquivo: lotofacil_id_primo_nao_primo.csv");
        return false;
    }

    fprintf(f_primo_nao_primo_comum, "comum_id;prm_id;prm_id_comum");

    long soma_primo_nao_primo_1 = 0;
    long soma_primo_nao_primo_2 = 0;
    long comum_id = 0;

    for(int primo_1 = 0; primo_1 <= QT_DE_PRIMOS; primo_1++)
    for(int nao_primo_1 = 0; nao_primo_1 <= QT_DE_NAO_PRIMOS; nao_primo_1++){

        soma_primo_nao_primo_1 = primo_1 + nao_primo_1;

        if((soma_primo_nao_primo_1 >= 15) && (soma_primo_nao_primo_1 <= 18)){

                long id_primo_nao_primo_1 = primo_nao_primo_id[primo_1][nao_primo_1][0];

                for(int primo_2 = 0; primo_2 <= QT_DE_PRIMOS; primo_2++)
                for(int nao_primo_2 = 0; nao_primo_2 <= QT_DE_NAO_PRIMOS; nao_primo_2++){

                    long soma_primo_nao_primo_2 = primo_2 + nao_primo_2;

                    if((soma_primo_nao_primo_2 >= 15) && (soma_primo_nao_primo_2 <= 18)){
                        long id_primo_nao_primo_2 = primo_nao_primo_id[primo_2][nao_primo_2][0];
                        bool comum_localizado = false;

                        // Vamos detectar possivel combinacao comum.
                        for(int uA = 0; uA <= 3; uA++){
                            long nao_primo_3 = uA;
                            for(long primo_3 = 0; primo_3 <= uA; primo_3++){
                                long primo_4 = primo_1 + primo_3;
                                long nao_primo_4 = nao_primo_1 + nao_primo_3;

                                if((primo_4 == primo_2) && (nao_primo_4 == nao_primo_2)){
                                    comum_localizado = true;
                                    break;
                                }

                                primo_4 = primo_1 - primo_3;
                                nao_primo_4 = nao_primo_1 - nao_primo_3;

                                if((primo_4 == primo_2) && (nao_primo_4 == nao_primo_2)){
                                    comum_localizado = true;
                                    break;
                                }
                                nao_primo_3--;
                            }
                            if(comum_localizado){
                                break;
                            }
                        }

                    if(comum_localizado)
                    {
                        comum_id++;

                            fprintf(f_primo_nao_primo_comum, "\n%li;%li;%li", comum_id, id_primo_nao_primo_1, id_primo_nao_primo_2);
                        }
                    }
                }
        }
    }

    fclose(f_primo_nao_primo_comum);
    return true;
}
