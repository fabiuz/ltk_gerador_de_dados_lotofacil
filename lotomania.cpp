#include <cstdio>
#include <cstdlib>
#include <cstring>

const long LOTOMANIA_ULTIMA_BOLA = 99;
long lotomania_bolas[100];

struct lotomania_num
{
    unsigned long long lotomania_id;
    long b1,  b2,  b3, b4, b5, b6, b7, b8, b9, b10;
    long b11, b12, b13, b14, b15, b16, b17, b18, b19, b20;
};



void gerar_lotomania(){
    unsigned long lotomania_id = 0;

    FILE * f_arquivo = fopen("./lotomania_25_par_25_impar.csv", "w");
    if(!f_arquivo){
        fprintf(stderr, "Erro ao abrir arquivo: 'lotomania_25_par_impar.csv'");
        exit(-1);
    }

    fprintf(f_arquivo, "lotomania_id");
    for(long uA = 1; uA <= 50; uA++){
        fprintf(f_arquivo, ";b_%li", uA);
    }
    fflush(stdout);

    memset(&lotomania_bolas[0], 0, sizeof(long) * 100);

    unsigned long long contador = 0;

    printf("Valor: %llu", 0xFFFFFFFFFFFFFFULL);
    fflush(stdout);

    for(int b1 = 0; b1 <= LOTOMANIA_ULTIMA_BOLA; b1++)
    for(int b2 = b1 + 1; b2 <= LOTOMANIA_ULTIMA_BOLA; b2++)
    for(int b3 = b2 + 1; b3 <= LOTOMANIA_ULTIMA_BOLA; b3++)
    for(int b4 = b3 + 1; b4 <= LOTOMANIA_ULTIMA_BOLA; b4++)
    for(int b5 = b4 + 1; b5 <= LOTOMANIA_ULTIMA_BOLA; b5++)
    for(int b6 = b5 + 1; b6 <= LOTOMANIA_ULTIMA_BOLA; b6++)
    for(int b7 = b6 + 1; b7 <= LOTOMANIA_ULTIMA_BOLA; b7++)
    for(int b8 = b7 + 1; b8 <= LOTOMANIA_ULTIMA_BOLA; b8++)
    for(int b9 = b8 + 1; b9 <= LOTOMANIA_ULTIMA_BOLA; b9++)

    for(int b10 = b9 + 1; b10 <= LOTOMANIA_ULTIMA_BOLA; b10++)
    for(int b11 = b10 + 1; b11 <= LOTOMANIA_ULTIMA_BOLA; b11++)
    for(int b12 = b11 + 1; b12 <= LOTOMANIA_ULTIMA_BOLA; b12++)
    for(int b13 = b12 + 1; b13 <= LOTOMANIA_ULTIMA_BOLA; b13++)
    for(int b14 = b13 + 1; b14 <= LOTOMANIA_ULTIMA_BOLA; b14++)
    for(int b15 = b14 + 1; b15 <= LOTOMANIA_ULTIMA_BOLA; b15++)
    for(int b16 = b15 + 1; b16 <= LOTOMANIA_ULTIMA_BOLA; b16++)
    for(int b17 = b16 + 1; b17 <= LOTOMANIA_ULTIMA_BOLA; b17++)
    for(int b18 = b17 + 1; b18 <= LOTOMANIA_ULTIMA_BOLA; b18++)
    for(int b19 = b18 + 1; b19 <= LOTOMANIA_ULTIMA_BOLA; b19++)

    for(int b20 = b19 + 1; b20 <= LOTOMANIA_ULTIMA_BOLA; b20++)
    for(int b21 = b20 + 1; b21 <= LOTOMANIA_ULTIMA_BOLA; b21++)
    for(int b22 = b21 + 1; b22 <= LOTOMANIA_ULTIMA_BOLA; b22++)
    for(int b23 = b22 + 1; b23 <= LOTOMANIA_ULTIMA_BOLA; b23++)
    for(int b24 = b23 + 1; b24 <= LOTOMANIA_ULTIMA_BOLA; b24++)
    for(int b25 = b24 + 1; b25 <= LOTOMANIA_ULTIMA_BOLA; b25++)
    for(int b26 = b25 + 1; b26 <= LOTOMANIA_ULTIMA_BOLA; b26++)
    for(int b27 = b26 + 1; b27 <= LOTOMANIA_ULTIMA_BOLA; b27++)
    for(int b28 = b27 + 1; b28 <= LOTOMANIA_ULTIMA_BOLA; b28++)
    for(int b29 = b28 + 1; b29 <= LOTOMANIA_ULTIMA_BOLA; b29++)

    for(int b30 = b29 + 1; b30 <= LOTOMANIA_ULTIMA_BOLA; b30++)
    for(int b31 = b30 + 1; b31 <= LOTOMANIA_ULTIMA_BOLA; b31++)
    for(int b32 = b31 + 1; b32 <= LOTOMANIA_ULTIMA_BOLA; b32++)
    for(int b33 = b32 + 1; b33 <= LOTOMANIA_ULTIMA_BOLA; b33++)
    for(int b34 = b33 + 1; b34 <= LOTOMANIA_ULTIMA_BOLA; b34++)
    for(int b35 = b34 + 1; b35 <= LOTOMANIA_ULTIMA_BOLA; b35++)
    for(int b36 = b35 + 1; b36 <= LOTOMANIA_ULTIMA_BOLA; b36++)
    for(int b37 = b36 + 1; b37 <= LOTOMANIA_ULTIMA_BOLA; b37++)
    for(int b38 = b37 + 1; b38 <= LOTOMANIA_ULTIMA_BOLA; b38++)
    for(int b39 = b38 + 1; b39 <= LOTOMANIA_ULTIMA_BOLA; b39++)

    for(int b40 = b39 + 1; b40 <= LOTOMANIA_ULTIMA_BOLA; b40++)
    for(int b41 = b40 + 1; b41 <= LOTOMANIA_ULTIMA_BOLA; b41++)
    for(int b42 = b41 + 1; b42 <= LOTOMANIA_ULTIMA_BOLA; b42++)
    for(int b43 = b42 + 1; b43 <= LOTOMANIA_ULTIMA_BOLA; b43++)
    for(int b44 = b43 + 1; b44 <= LOTOMANIA_ULTIMA_BOLA; b44++)
    for(int b45 = b44 + 1; b45 <= LOTOMANIA_ULTIMA_BOLA; b45++)
    for(int b46 = b45 + 1; b46 <= LOTOMANIA_ULTIMA_BOLA; b46++)
    for(int b47 = b46 + 1; b47 <= LOTOMANIA_ULTIMA_BOLA; b47++)
    for(int b48 = b47 + 1; b48 <= LOTOMANIA_ULTIMA_BOLA; b48++)
    for(int b49 = b48 + 1; b49 <= LOTOMANIA_ULTIMA_BOLA; b49++)
    for(int b50 = b49 + 1; b50 <= LOTOMANIA_ULTIMA_BOLA; b50++){
        long qt_impares = 0;

        if(++contador==0xFFFFFFFFFFFFFFULL /* 1_000_000_000_000_000_000 */ ){
            contador = 0;
            printf("1 quintilhão...");
        }

        /*
        lotomania_bolas[0] = b1;
        lotomania_bolas[1] = b2;
        lotomania_bolas[2] = b3;
        lotomania_bolas[3] = b4;
        lotomania_bolas[4] = b5;
        lotomania_bolas[5] = b6;
        lotomania_bolas[6] = b7;
        lotomania_bolas[7] = b8;
        lotomania_bolas[8] = b9;
        lotomania_bolas[9] = b10;

        lotomania_bolas[0] = b1;
        lotomania_bolas[1] = b2;
        lotomania_bolas[2] = b3;
        lotomania_bolas[3] = b4;
        lotomania_bolas[4] = b5;
        lotomania_bolas[5] = b6;
        lotomania_bolas[6] = b7;
        lotomania_bolas[7] = b8;
        lotomania_bolas[8] = b9;
        lotomania_bolas[9] = b10;

        qt_impares =    (b1 % 2) + (b2 % 2) + (b3 % 2) + (b4 % 2) + (b5 % 2) +
                        (b6 % 2) + (b7 % 2) + (b8 % 2) + (b9 % 2) + (b10 % 2) +
                (b11 % 2) + (b12 % 2) + (b13 % 2) + (b14 % 2) + (b15 % 2) +
                (b16 % 2) + (b17 % 2) + (b18 % 2) + (b19 % 2) + (b20 % 2) +
                (b21 % 2) + (b22 % 2) + (b23 % 2) + (b24 % 2) + (b25 % 2) +
                (b26 % 2) + (b27 % 2) + (b28 % 2) + (b29 % 2) + (b30 % 2) +
                (b31 % 2) + (b32 % 2) + (b33 % 2) + (b34 % 2) + (b35 % 2) +
                (b36 % 2) + (b37 % 2) + (b38 % 2) + (b39 % 2) + (b40 % 2) +
                (b41 % 2) + (b42 % 2) + (b43 % 2) + (b44 % 2) + (b45 % 2) +
                (b46 % 2) + (b47 % 2) + (b48 % 2) + (b49 % 2) + (b50 % 2);

        if(qt_impares != 25)
            continue;

        lotomania_id++;
        */
    }

    printf("Contador: %llu", contador);

}
