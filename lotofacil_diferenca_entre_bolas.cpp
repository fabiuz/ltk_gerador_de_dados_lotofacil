#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/**
 * @brief qt_diferencas
 *
 */
//static short qt_diferenca[18][18][18][18][18][18][18][18][18][18][18][2];
static short *pt_diferenca = 0;

bool iniciar_arranjo_qt_diferenca(){
    unsigned long long valor = static_cast<unsigned long long>(pow(18, 11));
    cout << "Valor: " << valor << endl;


    // pt_diferenca = new short[sizeof(short) * static_cast<unsigned short>(pow(18, 11))];

    unsigned long id_diferenca = 0;

    for(short b1 = 0; b1 < 18; b1++)
        for(short b2 = 0; b2 < 18; b2++)
            for(short b3 = 0; b3 < 18; b3++)
                for(short b4 = 0; b4 < 18; b4++)
                    for(short b5 = 0; b5 < 18; b5++)
                        for(short b6 = 0; b6 < 18; b6++)
                            for(short b7 = 0; b7 < 18; b7++)
                                for(short b8 = 0; b8 < 18; b8++)
                                    for(short b9 = 0; b9 < 18; b9++)
                                        for(short b10 = 0; b10 < 18; b10++)
                                            for(short b11 = 0; b11 < 18; b11++){
                                                long b_soma = b1 + b2 + b3 + b4 + b5 + b6 + b7 + b8 + b9 + b10 + b11;

                                                if(b_soma >= 14 && b_soma <= 17){
                                                    id_diferenca++;
                                                    // qt_diferenca[b1][b2][b3][b4][b5][b6][b7][b8][b9][b10][b11][0] = id_diferenca;
                                                    //qt_diferenca[b1][b2][b3][b4][b5][b6][b7][b8][b9][b10][b11][1] = 1;
                                                }else{
                                                    //qt_diferenca[b1][b2][b3][b4][b5][b6][b7][b8][b9][b10][b11][1] = 0;
                                                }
                                            }
    return true;
}
