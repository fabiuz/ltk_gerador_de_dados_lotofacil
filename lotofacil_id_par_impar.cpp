/**
  Autor:    Fábio Moura de Oliveira

  Algoritmo pra gerar id pra cada combinação par x ímpar da lotofacil.
  Na lotofacil, há 12 números pares e 13 números ímpares.


*/

#include <cstdlib>
#include <cstdio>
#include <cstring>

const long QT_MINIMA_PAR = 2;
const long QT_MINIMA_IMPAR = 3;

const long QT_MAXIMA_PAR = 12;
const long QT_MAXIMA_IMPAR = 13;

const unsigned long QT_PARES_ALOCADOS = QT_MAXIMA_PAR + 1;
const unsigned long QT_IMPARES_ALOCADOS = QT_MAXIMA_IMPAR + 1;
const unsigned long QT_DE_BOLAS_ALOCADAS = sizeof(long) * QT_PARES_ALOCADOS * QT_IMPARES_ALOCADOS * 2;

static long par_impar_id[QT_PARES_ALOCADOS][QT_IMPARES_ALOCADOS][2];

/*!
 * \brief obter_par_impar_id Obtém o identificador da combinação par x impar válida
 * na lotofacil.
 * \param qt_pares      Quantidade de números pares
 * \param qt_impares    Quantidade de números ímpares.
 * \return Retorna o identificador da combinação formada pelo parâmetros qt_pares e
 * qt_impares, se for válida na lotofacil ou retorna -1 se os parâmetros qt_pares e
 * qt_impares não forma uma combinação par x ímpares válida na lotofacil.
 *
 */
long obter_par_impar_id(long qt_pares, long qt_impares){

    long soma_par_impar = qt_pares + qt_impares;
    bool b_soma_par_impar = (soma_par_impar >= 15) && (soma_par_impar <= 18);

    if(!b_soma_par_impar)
        return -1;

    bool b_pares = (qt_pares >= QT_MINIMA_PAR) && (qt_pares <= QT_MAXIMA_PAR);

    if(!b_pares)
        return -1;

    bool b_impares = (qt_impares >= QT_MINIMA_IMPAR) && (qt_impares <= QT_MAXIMA_IMPAR);

    if(!b_impares)
        return -1;

    return par_impar_id[qt_pares][qt_impares][0];
}


/*!
 * \brief gerar_par_impar_comum_id
 * \return
 */
bool gerar_par_impar_comum_id(){

    FILE * f_par_impar_comum = fopen("./arquivos_csv/lotofacil_id_par_impar_comum.csv", "w");

    if(!f_par_impar_comum){
        fprintf(stderr, "Erro ao abrir arquivo: lotofacil_id_par_impar.csv");
        return false;
    }

    fprintf(f_par_impar_comum, "comum_id;par_impar_id;par_impar_id_comum");

    long soma_par_impar_1 = 0;
    long soma_par_impar_2 = 0;
    long comum_id = 0;

    for(int par_1 = QT_MINIMA_PAR; par_1 <= QT_MAXIMA_PAR; par_1++)
    for(int impar_1 = QT_MINIMA_IMPAR; impar_1 <= QT_MAXIMA_IMPAR; impar_1++){

        soma_par_impar_1 = par_1 + impar_1;

        if((soma_par_impar_1 >= 15) && (soma_par_impar_1 <= 18)){

                long id_par_impar_1 = par_impar_id[par_1][impar_1][0];

                for(int par_2 = QT_MINIMA_PAR; par_2 <= QT_MAXIMA_PAR; par_2++)
                for(int impar_2 = QT_MINIMA_IMPAR; impar_2 <= QT_MAXIMA_IMPAR; impar_2++){

                    long soma_par_impar_2 = par_2 + impar_2;

                    if((soma_par_impar_2 >= 15) && (soma_par_impar_2 <= 18)){
                        long id_par_impar_2 = par_impar_id[par_2][impar_2][0];
                        bool comum_localizado = false;

                        // Vamos detectar possivel combinacao comum.
                        for(int uA = 0; uA <= 3; uA++){
                            long impar_3 = uA;
                            for(long par_3 = 0; par_3 <= uA; par_3++){
                                long par_4 = par_1 + par_3;
                                long impar_4 = impar_1 + impar_3;

                                if((par_4 == par_2) && (impar_4 == impar_2)){
                                    comum_localizado = true;
                                    break;
                                }

                                par_4 = par_1 - par_3;
                                impar_4 = impar_1 - impar_3;

                                if((par_4 == par_2) && (impar_4 == impar_2)){
                                    comum_localizado = true;
                                    break;
                                }
                                impar_3--;
                            }
                            if(comum_localizado){
                                break;
                            }
                        }

                    if(comum_localizado)
                    {
                        comum_id++;

                            fprintf(f_par_impar_comum, "\n%li;%li;%li", comum_id, id_par_impar_1, id_par_impar_2);
                            if(ferror(f_par_impar_comum)){
                                fprintf(stderr, "Erro ao gravar dados em lotofacil_id_par_impar_comum");
                                return false;
                            }

                        }
                    }
                }
        }
    }

    fclose(f_par_impar_comum);
    return true;
}


/**
 * @brief gerar_par_impar_id
 * @return
 */
bool gerar_par_impar_id(){

    FILE * f_par_impar = fopen("./arquivos_csv/lotofacil_id_par_impar.csv", "w");
    if(!f_par_impar){
        fprintf(stderr, "Erro ao abrir arquivo: lotofacil_id_par_impar.csv\n");
        return false;
    }

    // Gerar cabeçalho do arquivo 'lotofacil_id_par_impar.csv'.
    fprintf(f_par_impar, "par_impar_id;par_impar_qt;par;impar");

    // Em C, C++, quando criamos um arranjo, o mesmo não é criado com valores padrões.
    // Pra evitar isto, zeramos cada elemento do arranjo.
    memset(par_impar_id, 0, QT_DE_BOLAS_ALOCADAS);

    long id_par_impar = 0;
    long soma_par_impar = 0;

    for(int par = QT_MINIMA_PAR; par <= QT_MAXIMA_PAR; par++)
    for(int impar = QT_MINIMA_IMPAR; impar <= QT_MAXIMA_IMPAR; impar++){
        soma_par_impar = par + impar;

        // Só iremos gerar id pra combinações de pares x ímpares válidas na lotofacil.
        if((soma_par_impar >= 15) && (soma_par_impar <= 18)){
            id_par_impar++;
            par_impar_id[par][impar][0] = id_par_impar;
            par_impar_id[par][impar][1] = 0;

            fprintf(f_par_impar, "\n%li;%li;%i;%i", id_par_impar, soma_par_impar, par, impar);
            if(ferror(f_par_impar)){
                fprintf(stderr, "Erro ao gravar dados no arquivo lotofacil_id_par_impar.csv\n");
                return false;
            }
        }
    }

    fclose(f_par_impar);
    return gerar_par_impar_comum_id();
}

