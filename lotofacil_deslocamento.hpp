/**
    Gera os valores ltf_id de cada combinação,
    na nossa tabela lotofacil_num, lotofacil_bolas, e outras,
    pra cada combinação, haverá um identificador de nome 'ltf_id',
    todas as combinações de 15, 16, 17 e 18 bolas estarão na mesma combinação.
    Aqui, primeiro iremos gerar os ids de todas as combinações de 15 bolas, depois
    16 bolas, depois 17 bolas e assim por diante.
    Aqui, não iremos resetar o campo ltf_id a cada combinação de bolas maior que a anterior.

*/



#ifndef LOTOFACIL_DESLOCAMENTO_HPP
#define LOTOFACIL_DESLOCAMENTO_HPP

/**
   Tabela de deslocamento pra lotofacil
   Autor: Fábio Moura de Oliveira.
  **/
static const long lotofacil_deslocamento[19][26] =
{
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1  },
    {0, 276, 253, 231, 210, 190, 171, 153, 136, 120,105, 91, 78, 66, 55, 45, 36, 28, 21, 15, 10, 6, 3, 1, 0},
    {0, 2024,1771,1540,1330,1140,969,816,680,560,455,364,286,220,165,120,84,56,35,20,10,4,1,0,0 },
    {0, 10626,8855,7315,5985,4845,3876,3060,2380,1820,1365,1001,715,495,330,210,126,70,35,15,5,1, 0, 0, 0},
    {0, 42504,33649,26334,20349,15504,11628,8568,6188,4368,3003,2002,1287,792,462,252,126,56,21,6,1, 0, 0, 0, 0},
    {0, 134596,100947,74613,54264,38760,27132,18564,12376,8008,5005,3003,1716,924,462,210,84,28,7,1, 0, 0, 0, 0, 0},
    {0, 346104,245157,170544,116280,77520,50388,31824,19448,11440,6435,3432,1716,792,330,120,36,8,1, 0, 0, 0, 0, 0, 0},
    {0, 735471,490314,319770,203490,125970,75582,43758,24310,12870,6435,3003,1287,495,165,45,9,1, 0, 0, 0, 0, 0, 0, 0},
    {0, 1307504,817190,497420,293930,167960,92378,48620,24310,11440,5005,2002,715,220,55,10,1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1961256, 1144066,646646,352716,184756,92378,43758,19448,8008,3003,1001,286,66,11,1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 2496144,1352078,705432,352716,167960,75582,31824,12376,4368,1365,364,78,12,1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 2704156,1352078,646646,293930,125970,50388,18564,6188,1820,455,91,13,1,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 2496144,1144066,497420,203490,77520,27132,8568,2380,560,105,14,1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1961256,817190,319770,116280,38760,11628,3060,680,120,15,1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1307504,490314,170544, 54264,15504,3876,816,136,16,1,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 735471, 245157, 74613, 20349, 4845, 969, 153, 17, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 346104, 100947, 26334,  5985, 1140, 171,  18,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 134596,  33649,  7315,  1330,  190,  19,   1,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

};

inline long obter_deslocamento_14_bolas(long b1, long b2, long b3, long b4, long b5,
                                long b6, long b7, long b8, long b9, long b10,
                                long b11, long b12, long b13, long b14)
{
    // Pra cada combinação de qt_bolas, haverá um deslocamento inicial, por exemplo,
    // pra a combinação de 15 bolas, o deslocamento vai de 1 a 3268760, entretanto,
    // a função, aqui, retorna a primeira combinação com o valor 0, por isto,
    // devemos indicar o primeiro valor.
    long deslocamento_inicial = 1;
    long soma_deslocamento = 0;

    for(long uA = 0; uA < b1; uA++)
        soma_deslocamento += lotofacil_deslocamento[13][uA];

    for(long uA = b1 + 1; uA < b2; uA++)
        soma_deslocamento += lotofacil_deslocamento[12][uA];

    for(long uA = b2 + 1; uA < b3; uA++)
        soma_deslocamento += lotofacil_deslocamento[11][uA];

    for(long uA = b3 + 1; uA < b4; uA++)
        soma_deslocamento += lotofacil_deslocamento[10][uA];

    for(long uA = b4 + 1; uA < b5; uA++)
        soma_deslocamento += lotofacil_deslocamento[9][uA];

    for(long uA = b5 + 1; uA < b6; uA++)
        soma_deslocamento += lotofacil_deslocamento[8][uA];

    for(long uA = b6 + 1; uA < b7; uA++)
        soma_deslocamento += lotofacil_deslocamento[7][uA];

    for(long uA = b7 + 1; uA < b8; uA++)
        soma_deslocamento += lotofacil_deslocamento[6][uA];

    for(long uA = b8 + 1; uA < b9; uA++)
        soma_deslocamento += lotofacil_deslocamento[5][uA];

    for(long uA = b9 + 1; uA < b10; uA++)
        soma_deslocamento += lotofacil_deslocamento[4][uA];

    for(long uA = b10 + 1; uA < b11; uA++)
        soma_deslocamento += lotofacil_deslocamento[3][uA];

    for(long uA = b11 + 1; uA < b12; uA++)
        soma_deslocamento += lotofacil_deslocamento[2][uA];

    for(long uA = b12 + 1; uA < b13; uA++)
        soma_deslocamento += lotofacil_deslocamento[1][uA];

    for(long uA = b13 + 1; uA < b14; uA++)
        soma_deslocamento += 1;


    return soma_deslocamento + deslocamento_inicial;
}

inline long obter_deslocamento_13_bolas(long b1, long b2, long b3, long b4, long b5,
                                long b6, long b7, long b8, long b9, long b10,
                                long b11, long b12, long b13)
{
    // Pra cada combinação de qt_bolas, haverá um deslocamento inicial, por exemplo,
    // pra a combinação de 15 bolas, o deslocamento vai de 1 a 3268760, entretanto,
    // a função, aqui, retorna a primeira combinação com o valor 0, por isto,
    // devemos indicar o primeiro valor.
    long deslocamento_inicial = 1;
    long soma_deslocamento = 0;

    for(long uA = 0; uA < b1; uA++)
        soma_deslocamento += lotofacil_deslocamento[12][uA];

    for(long uA = b1 + 1; uA < b2; uA++)
        soma_deslocamento += lotofacil_deslocamento[11][uA];

    for(long uA = b2 + 1; uA < b3; uA++)
        soma_deslocamento += lotofacil_deslocamento[10][uA];

    for(long uA = b3 + 1; uA < b4; uA++)
        soma_deslocamento += lotofacil_deslocamento[9][uA];

    for(long uA = b4 + 1; uA < b5; uA++)
        soma_deslocamento += lotofacil_deslocamento[8][uA];

    for(long uA = b5 + 1; uA < b6; uA++)
        soma_deslocamento += lotofacil_deslocamento[7][uA];

    for(long uA = b6 + 1; uA < b7; uA++)
        soma_deslocamento += lotofacil_deslocamento[6][uA];

    for(long uA = b7 + 1; uA < b8; uA++)
        soma_deslocamento += lotofacil_deslocamento[5][uA];

    for(long uA = b8 + 1; uA < b9; uA++)
        soma_deslocamento += lotofacil_deslocamento[4][uA];

    for(long uA = b9 + 1; uA < b10; uA++)
        soma_deslocamento += lotofacil_deslocamento[3][uA];

    for(long uA = b10 + 1; uA < b11; uA++)
        soma_deslocamento += lotofacil_deslocamento[2][uA];

    for(long uA = b11 + 1; uA < b12; uA++)
        soma_deslocamento += lotofacil_deslocamento[1][uA];

    for(long uA = b12 + 1; uA < b13; uA++)
        soma_deslocamento += 1;


    return soma_deslocamento + deslocamento_inicial;
}

inline long obter_deslocamento_12_bolas(long b1, long b2, long b3, long b4, long b5,
                                long b6, long b7, long b8, long b9, long b10,
                                long b11, long b12)
{
    // Pra cada combinação de qt_bolas, haverá um deslocamento inicial, por exemplo,
    // pra a combinação de 15 bolas, o deslocamento vai de 1 a 3268760, entretanto,
    // a função, aqui, retorna a primeira combinação com o valor 0, por isto,
    // devemos indicar o primeiro valor.
    long deslocamento_inicial = 1;
    long soma_deslocamento = 0;

    for(long uA = 0; uA < b1; uA++)
        soma_deslocamento += lotofacil_deslocamento[11][uA];

    for(long uA = b1 + 1; uA < b2; uA++)
        soma_deslocamento += lotofacil_deslocamento[10][uA];

    for(long uA = b2 + 1; uA < b3; uA++)
        soma_deslocamento += lotofacil_deslocamento[9][uA];

    for(long uA = b3 + 1; uA < b4; uA++)
        soma_deslocamento += lotofacil_deslocamento[8][uA];

    for(long uA = b4 + 1; uA < b5; uA++)
        soma_deslocamento += lotofacil_deslocamento[7][uA];

    for(long uA = b5 + 1; uA < b6; uA++)
        soma_deslocamento += lotofacil_deslocamento[6][uA];

    for(long uA = b6 + 1; uA < b7; uA++)
        soma_deslocamento += lotofacil_deslocamento[5][uA];

    for(long uA = b7 + 1; uA < b8; uA++)
        soma_deslocamento += lotofacil_deslocamento[4][uA];

    for(long uA = b8 + 1; uA < b9; uA++)
        soma_deslocamento += lotofacil_deslocamento[3][uA];

    for(long uA = b9 + 1; uA < b10; uA++)
        soma_deslocamento += lotofacil_deslocamento[2][uA];

    for(long uA = b10 + 1; uA < b11; uA++)
        soma_deslocamento += lotofacil_deslocamento[1][uA];

    for(long uA = b11 + 1; uA < b12; uA++)
        soma_deslocamento += 1;


    return soma_deslocamento + deslocamento_inicial;
}

inline long obter_deslocamento_11_bolas(long b1, long b2, long b3, long b4, long b5,
                                long b6, long b7, long b8, long b9, long b10,
                                long b11)
{
    // Pra cada combinação de qt_bolas, haverá um deslocamento inicial, por exemplo,
    // pra a combinação de 15 bolas, o deslocamento vai de 1 a 3268760, entretanto,
    // a função, aqui, retorna a primeira combinação com o valor 0, por isto,
    // devemos indicar o primeiro valor.
    long deslocamento_inicial = 1;
    long soma_deslocamento = 0;

    for(long uA = 0; uA < b1; uA++)
        soma_deslocamento += lotofacil_deslocamento[10][uA];

    for(long uA = b1 + 1; uA < b2; uA++)
        soma_deslocamento += lotofacil_deslocamento[9][uA];

    for(long uA = b2 + 1; uA < b3; uA++)
        soma_deslocamento += lotofacil_deslocamento[8][uA];

    for(long uA = b3 + 1; uA < b4; uA++)
        soma_deslocamento += lotofacil_deslocamento[7][uA];

    for(long uA = b4 + 1; uA < b5; uA++)
        soma_deslocamento += lotofacil_deslocamento[6][uA];

    for(long uA = b5 + 1; uA < b6; uA++)
        soma_deslocamento += lotofacil_deslocamento[5][uA];

    for(long uA = b6 + 1; uA < b7; uA++)
        soma_deslocamento += lotofacil_deslocamento[4][uA];

    for(long uA = b7 + 1; uA < b8; uA++)
        soma_deslocamento += lotofacil_deslocamento[3][uA];

    for(long uA = b8 + 1; uA < b9; uA++)
        soma_deslocamento += lotofacil_deslocamento[2][uA];

    for(long uA = b9 + 1; uA < b10; uA++)
        soma_deslocamento += lotofacil_deslocamento[1][uA];

    for(long uA = b10 + 1; uA < b11; uA++)
        soma_deslocamento += 1;


    return soma_deslocamento + deslocamento_inicial;
}

inline long obter_deslocamento_10_bolas(long b1, long b2, long b3, long b4, long b5,
                                long b6, long b7, long b8, long b9, long b10)
{
    // Pra cada combinação de qt_bolas, haverá um deslocamento inicial, por exemplo,
    // pra a combinação de 15 bolas, o deslocamento vai de 1 a 3268760, entretanto,
    // a função, aqui, retorna a primeira combinação com o valor 0, por isto,
    // devemos indicar o primeiro valor.
    long deslocamento_inicial = 1;
    long soma_deslocamento = 0;

    for(long uA = 0; uA < b1; uA++)
        soma_deslocamento += lotofacil_deslocamento[9][uA];

    for(long uA = b1 + 1; uA < b2; uA++)
        soma_deslocamento += lotofacil_deslocamento[8][uA];

    for(long uA = b2 + 1; uA < b3; uA++)
        soma_deslocamento += lotofacil_deslocamento[7][uA];

    for(long uA = b3 + 1; uA < b4; uA++)
        soma_deslocamento += lotofacil_deslocamento[6][uA];

    for(long uA = b4 + 1; uA < b5; uA++)
        soma_deslocamento += lotofacil_deslocamento[5][uA];

    for(long uA = b5 + 1; uA < b6; uA++)
        soma_deslocamento += lotofacil_deslocamento[4][uA];

    for(long uA = b6 + 1; uA < b7; uA++)
        soma_deslocamento += lotofacil_deslocamento[3][uA];

    for(long uA = b7 + 1; uA < b8; uA++)
        soma_deslocamento += lotofacil_deslocamento[2][uA];

    for(long uA = b8 + 1; uA < b9; uA++)
        soma_deslocamento += lotofacil_deslocamento[1][uA];

    for(long uA = b9 + 1; uA < b10; uA++)
        soma_deslocamento += 1;

    return soma_deslocamento + deslocamento_inicial;
}

inline long obter_deslocamento_9_bolas(long b1, long b2, long b3, long b4, long b5,
                                long b6, long b7, long b8, long b9)
{
    // Pra cada combinação de qt_bolas, haverá um deslocamento inicial, por exemplo,
    // pra a combinação de 15 bolas, o deslocamento vai de 1 a 3268760, entretanto,
    // a função, aqui, retorna a primeira combinação com o valor 0, por isto,
    // devemos indicar o primeiro valor.
    long deslocamento_inicial = 1;
    long soma_deslocamento = 0;

    for(long uA = 0; uA < b1; uA++)
        soma_deslocamento += lotofacil_deslocamento[8][uA];

    for(long uA = b1 + 1; uA < b2; uA++)
        soma_deslocamento += lotofacil_deslocamento[7][uA];

    for(long uA = b2 + 1; uA < b3; uA++)
        soma_deslocamento += lotofacil_deslocamento[6][uA];

    for(long uA = b3 + 1; uA < b4; uA++)
        soma_deslocamento += lotofacil_deslocamento[5][uA];

    for(long uA = b4 + 1; uA < b5; uA++)
        soma_deslocamento += lotofacil_deslocamento[4][uA];

    for(long uA = b5 + 1; uA < b6; uA++)
        soma_deslocamento += lotofacil_deslocamento[3][uA];

    for(long uA = b6 + 1; uA < b7; uA++)
        soma_deslocamento += lotofacil_deslocamento[2][uA];

    for(long uA = b7 + 1; uA < b8; uA++)
        soma_deslocamento += lotofacil_deslocamento[1][uA];

    for(long uA = b8 + 1; uA < b9; uA++)
        soma_deslocamento += 1;

    return soma_deslocamento + deslocamento_inicial;
}

inline long obter_deslocamento_8_bolas(long b1, long b2, long b3, long b4, long b5,
                                long b6, long b7, long b8)
{
    // Pra cada combinação de qt_bolas, haverá um deslocamento inicial, por exemplo,
    // pra a combinação de 15 bolas, o deslocamento vai de 1 a 3268760, entretanto,
    // a função, aqui, retorna a primeira combinação com o valor 0, por isto,
    // devemos indicar o primeiro valor.
    long deslocamento_inicial = 1;
    long soma_deslocamento = 0;

    for(long uA = 0; uA < b1; uA++)
        soma_deslocamento += lotofacil_deslocamento[7][uA];

    for(long uA = b1 + 1; uA < b2; uA++)
        soma_deslocamento += lotofacil_deslocamento[6][uA];

    for(long uA = b2 + 1; uA < b3; uA++)
        soma_deslocamento += lotofacil_deslocamento[5][uA];

    for(long uA = b3 + 1; uA < b4; uA++)
        soma_deslocamento += lotofacil_deslocamento[4][uA];

    for(long uA = b4 + 1; uA < b5; uA++)
        soma_deslocamento += lotofacil_deslocamento[3][uA];

    for(long uA = b5 + 1; uA < b6; uA++)
        soma_deslocamento += lotofacil_deslocamento[2][uA];

    for(long uA = b6 + 1; uA < b7; uA++)
        soma_deslocamento += lotofacil_deslocamento[1][uA];

    for(long uA = b7 + 1; uA < b8; uA++)
        soma_deslocamento += 1;

    return soma_deslocamento + deslocamento_inicial;
}

inline long obter_deslocamento_7_bolas(long b1, long b2, long b3, long b4, long b5,
                                long b6, long b7)
{
    // Pra cada combinação de qt_bolas, haverá um deslocamento inicial, por exemplo,
    // pra a combinação de 15 bolas, o deslocamento vai de 1 a 3268760, entretanto,
    // a função, aqui, retorna a primeira combinação com o valor 0, por isto,
    // devemos indicar o primeiro valor.
    long deslocamento_inicial = 1;
    long soma_deslocamento = 0;

    for(long uA = 0; uA < b1; uA++)
        soma_deslocamento += lotofacil_deslocamento[6][uA];

    for(long uA = b1 + 1; uA < b2; uA++)
        soma_deslocamento += lotofacil_deslocamento[5][uA];

    for(long uA = b2 + 1; uA < b3; uA++)
        soma_deslocamento += lotofacil_deslocamento[4][uA];

    for(long uA = b3 + 1; uA < b4; uA++)
        soma_deslocamento += lotofacil_deslocamento[3][uA];

    for(long uA = b4 + 1; uA < b5; uA++)
        soma_deslocamento += lotofacil_deslocamento[2][uA];

    for(long uA = b5 + 1; uA < b6; uA++)
        soma_deslocamento += lotofacil_deslocamento[1][uA];

    for(long uA = b6 + 1; uA < b7; uA++)
        soma_deslocamento += 1;

    return soma_deslocamento + deslocamento_inicial;
}

inline long obter_deslocamento_6_bolas(long b1, long b2, long b3, long b4, long b5,
                                long b6)
{
    // Pra cada combinação de qt_bolas, haverá um deslocamento inicial, por exemplo,
    // pra a combinação de 15 bolas, o deslocamento vai de 1 a 3268760, entretanto,
    // a função, aqui, retorna a primeira combinação com o valor 0, por isto,
    // devemos indicar o primeiro valor.
    long deslocamento_inicial = 1;
    long soma_deslocamento = 0;

    for(long uA = 0; uA < b1; uA++)
        soma_deslocamento += lotofacil_deslocamento[5][uA];

    for(long uA = b1 + 1; uA < b2; uA++)
        soma_deslocamento += lotofacil_deslocamento[4][uA];

    for(long uA = b2 + 1; uA < b3; uA++)
        soma_deslocamento += lotofacil_deslocamento[3][uA];

    for(long uA = b3 + 1; uA < b4; uA++)
        soma_deslocamento += lotofacil_deslocamento[2][uA];

    for(long uA = b4 + 1; uA < b5; uA++)
        soma_deslocamento += lotofacil_deslocamento[1][uA];

    for(long uA = b5 + 1; uA < b6; uA++)
        soma_deslocamento += 1;

    return soma_deslocamento + deslocamento_inicial;
}

inline long obter_deslocamento_5_bolas(long b1, long b2, long b3, long b4, long b5)
{
    // Pra cada combinação de qt_bolas, haverá um deslocamento inicial, por exemplo,
    // pra a combinação de 15 bolas, o deslocamento vai de 1 a 3268760, entretanto,
    // a função, aqui, retorna a primeira combinação com o valor 0, por isto,
    // devemos indicar o primeiro valor.
    long deslocamento_inicial = 1;
    long soma_deslocamento = 0;

    for(long uA = 0; uA < b1; uA++)
        soma_deslocamento += lotofacil_deslocamento[4][uA];

    for(long uA = b1 + 1; uA < b2; uA++)
        soma_deslocamento += lotofacil_deslocamento[3][uA];

    for(long uA = b2 + 1; uA < b3; uA++)
        soma_deslocamento += lotofacil_deslocamento[2][uA];

    for(long uA = b3 + 1; uA < b4; uA++)
        soma_deslocamento += lotofacil_deslocamento[1][uA];

    for(long uA = b4 + 1; uA < b5; uA++)
        soma_deslocamento += 1;

    return soma_deslocamento + deslocamento_inicial;
}

inline long obter_deslocamento_4_bolas(long b1, long b2, long b3, long b4)
{
    // Pra cada combinação de qt_bolas, haverá um deslocamento inicial, por exemplo,
    // pra a combinação de 15 bolas, o deslocamento vai de 1 a 3268760, entretanto,
    // a função, aqui, retorna a primeira combinação com o valor 0, por isto,
    // devemos indicar o primeiro valor.
    long deslocamento_inicial = 1;
    long soma_deslocamento = 0;

    for(long uA = 0; uA < b1; uA++)
        soma_deslocamento += lotofacil_deslocamento[3][uA];

    for(long uA = b1 + 1; uA < b2; uA++)
        soma_deslocamento += lotofacil_deslocamento[2][uA];

    for(long uA = b2 + 1; uA < b3; uA++)
        soma_deslocamento += lotofacil_deslocamento[1][uA];

    for(long uA = b3 + 1; uA < b4; uA++)
        soma_deslocamento += 1;

    return soma_deslocamento + deslocamento_inicial;
}

inline long obter_deslocamento_3_bolas(long b1, long b2, long b3)
{
    // Pra cada combinação de qt_bolas, haverá um deslocamento inicial, por exemplo,
    // pra a combinação de 15 bolas, o deslocamento vai de 1 a 3268760, entretanto,
    // a função, aqui, retorna a primeira combinação com o valor 0, por isto,
    // devemos indicar o primeiro valor.
    long deslocamento_inicial = 1;
    long soma_deslocamento = 0;

    for(long uA = 0; uA < b1; uA++)
        soma_deslocamento += lotofacil_deslocamento[2][uA];

    for(long uA = b1 + 1; uA < b2; uA++)
        soma_deslocamento += lotofacil_deslocamento[1][uA];

    for(long uA = b2 + 1; uA < b3; uA++)
        soma_deslocamento += 1;

    return soma_deslocamento + deslocamento_inicial;
}

inline long obter_deslocamento_2_bolas(long b1, long b2)
{
    // Pra cada combinação de qt_bolas, haverá um deslocamento inicial, por exemplo,
    // pra a combinação de 15 bolas, o deslocamento vai de 1 a 3268760, entretanto,
    // a função, aqui, retorna a primeira combinação com o valor 0, por isto,
    // devemos indicar o primeiro valor.
    long deslocamento_inicial = 1;
    long soma_deslocamento = 0;

    for(long uA = 0; uA < b1; uA++)
        soma_deslocamento += lotofacil_deslocamento[1][uA];

    for(long uA = b1 + 1; uA < b2; uA++)
        soma_deslocamento += 1;

    return soma_deslocamento + deslocamento_inicial;
}

inline long obter_deslocamento_1_bola(long b1)
{
    // Pra cada combinação de qt_bolas, haverá um deslocamento inicial, por exemplo,
    // pra a combinação de 15 bolas, o deslocamento vai de 1 a 3268760, entretanto,
    // a função, aqui, retorna a primeira combinação com o valor 0, por isto,
    // devemos indicar o primeiro valor.
    long deslocamento_inicial = 1;
    long soma_deslocamento = 0;

    for(long uA = 0; uA < b1; uA++)
        soma_deslocamento += lotofacil_deslocamento[0][uA];

    for(long uA = b1 + 1; uA < b1; uA++)
        soma_deslocamento += 1;

    return soma_deslocamento + deslocamento_inicial;
}


/*!
 * \brief obter_deslocamento_15_bolas
 * \param b1
 * \param b2
 * \param b3
 * \param b4
 * \param b5
 * \param b6
 * \param b7
 * \param b8
 * \param b9
 * \param b10
 * \param b11
 * \param b12
 * \param b13
 * \param b14
 * \param b15
 * \return Retorna o valor ltf_id da combinação
 */
inline long obter_deslocamento_15_bolas(long b1, long b2, long b3, long b4, long b5,
                                long b6, long b7, long b8, long b9, long b10,
                                long b11, long b12, long b13, long b14, long b15)
{
    // Pra cada combinação de qt_bolas, haverá um deslocamento inicial, por exemplo,
    // pra a combinação de 15 bolas, o deslocamento vai de 1 a 3268760, entretanto,
    // a função, aqui, retorna a primeira combinação com o valor 0, por isto,
    // devemos indicar o primeiro valor.
    long deslocamento_inicial = 1;
    long soma_deslocamento = 0;

    for(long uA = 0; uA < b1; uA++)
        soma_deslocamento += lotofacil_deslocamento[14][uA];

    for(long uA = b1 + 1; uA < b2; uA++)
        soma_deslocamento += lotofacil_deslocamento[13][uA];

    for(long uA = b2 + 1; uA < b3; uA++)
        soma_deslocamento += lotofacil_deslocamento[12][uA];

    for(long uA = b3 + 1; uA < b4; uA++)
        soma_deslocamento += lotofacil_deslocamento[11][uA];

    for(long uA = b4 + 1; uA < b5; uA++)
        soma_deslocamento += lotofacil_deslocamento[10][uA];

    for(long uA = b5 + 1; uA < b6; uA++)
        soma_deslocamento += lotofacil_deslocamento[9][uA];

    for(long uA = b6 + 1; uA < b7; uA++)
        soma_deslocamento += lotofacil_deslocamento[8][uA];

    for(long uA = b7 + 1; uA < b8; uA++)
        soma_deslocamento += lotofacil_deslocamento[7][uA];

    for(long uA = b8 + 1; uA < b9; uA++)
        soma_deslocamento += lotofacil_deslocamento[6][uA];

    for(long uA = b9 + 1; uA < b10; uA++)
        soma_deslocamento += lotofacil_deslocamento[5][uA];

    for(long uA = b10 + 1; uA < b11; uA++)
        soma_deslocamento += lotofacil_deslocamento[4][uA];

    for(long uA = b11 + 1; uA < b12; uA++)
        soma_deslocamento += lotofacil_deslocamento[3][uA];

    for(long uA = b12 + 1; uA < b13; uA++)
        soma_deslocamento += lotofacil_deslocamento[2][uA];

    for(long uA = b13 + 1; uA < b14; uA++)
        soma_deslocamento += lotofacil_deslocamento[1][uA];

    for(long uA = b14 + 1; uA < b15; uA++)
        soma_deslocamento += 1;


    return soma_deslocamento + deslocamento_inicial;
}

inline long obter_deslocamento_16_bolas(long b1, long b2, long b3, long b4, long b5,
                                long b6, long b7, long b8, long b9, long b10,
                                long b11, long b12, long b13, long b14, long b15, long b16)
{
    // Pra cada combinação de qt_bolas, haverá um deslocamento inicial, por exemplo,
    // pra a combinação de 15 bolas, o deslocamento vai de 3268761 a 5311735, entretanto,
    // a função, aqui, retorna a primeira combinação com o valor 0, por isto,
    // devemos indicar o primeiro valor.


    // Observe que pra os deslocamentos menores de 15 bolas, o deslocamento começa em 1.
    // Pra os deslocamentos de 16 a 18 bolas, os deslocamentos terão valor diferente de 1
    // Isto ocorre por que na tabela lotofacil_num e lotofacil_bolas, armazenará
    // as combinações de 15 a 18 bolas, por isso haverá um identificador pra cada combinação.
    // Por exemplo, na lotofacil há 25 bolas, em uma combinação de 15 bolas, é possível ter
    // 3268760 combinações, então, o primeiro id começa em 1 e o ultimo termina em 3268760.
    // Então, como estamos todas as combinações de 15 a 18 bolas em um unica tabela, por exemplo,
    // o id 3268761 corresponde a primeira combinação de 16 bolas, que é:
    // 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16.
    long deslocamento_inicial = 3268761;
    long soma_deslocamento = 0;

    for(long uA = 0; uA < b1; uA++)
        soma_deslocamento += lotofacil_deslocamento[15][uA];

    for(long uA = b1 + 1; uA < b2; uA++)
        soma_deslocamento += lotofacil_deslocamento[14][uA];

    for(long uA = b2 + 1; uA < b3; uA++)
        soma_deslocamento += lotofacil_deslocamento[13][uA];

    for(long uA = b3 + 1; uA < b4; uA++)
        soma_deslocamento += lotofacil_deslocamento[12][uA];

    for(long uA = b4 + 1; uA < b5; uA++)
        soma_deslocamento += lotofacil_deslocamento[11][uA];

    for(long uA = b5 + 1; uA < b6; uA++)
        soma_deslocamento += lotofacil_deslocamento[10][uA];

    for(long uA = b6 + 1; uA < b7; uA++)
        soma_deslocamento += lotofacil_deslocamento[9][uA];

    for(long uA = b7 + 1; uA < b8; uA++)
        soma_deslocamento += lotofacil_deslocamento[8][uA];

    for(long uA = b8 + 1; uA < b9; uA++)
        soma_deslocamento += lotofacil_deslocamento[7][uA];

    for(long uA = b9 + 1; uA < b10; uA++)
        soma_deslocamento += lotofacil_deslocamento[6][uA];

    for(long uA = b10 + 1; uA < b11; uA++)
        soma_deslocamento += lotofacil_deslocamento[5][uA];

    for(long uA = b11 + 1; uA < b12; uA++)
        soma_deslocamento += lotofacil_deslocamento[4][uA];

    for(long uA = b12 + 1; uA < b13; uA++)
        soma_deslocamento += lotofacil_deslocamento[3][uA];

    for(long uA = b13 + 1; uA < b14; uA++)
        soma_deslocamento += lotofacil_deslocamento[2][uA];

    for(long uA = b14 + 1; uA < b15; uA++)
        soma_deslocamento += lotofacil_deslocamento[1][uA];

    for(long uA = b15 + 1; uA < b16; uA++)
        soma_deslocamento += 1;

    return soma_deslocamento + deslocamento_inicial;
}

inline long obter_deslocamento_17_bolas(long b1, long b2, long b3, long b4, long b5,
                                long b6, long b7, long b8, long b9, long b10,
                                long b11, long b12, long b13, long b14, long b15, long b16, long b17)
{
    // Pra cada combinação de qt_bolas, haverá um deslocamento inicial, por exemplo,
    // pra a combinação de 15 bolas, o deslocamento vai de 5311736 a 6393310, entretanto,
    // a função, aqui, retorna a primeira combinação com o valor 0, por isto,
    // devemos indicar o primeiro valor.
    long deslocamento_inicial = 5311736;
    long soma_deslocamento = 0;

    for(long uA = 0; uA < b1; uA++)
        soma_deslocamento += lotofacil_deslocamento[16][uA];

    for(long uA = b1 + 1; uA < b2; uA++)
        soma_deslocamento += lotofacil_deslocamento[15][uA];

    for(long uA = b2 + 1; uA < b3; uA++)
        soma_deslocamento += lotofacil_deslocamento[14][uA];

    for(long uA = b3 + 1; uA < b4; uA++)
        soma_deslocamento += lotofacil_deslocamento[13][uA];

    for(long uA = b4 + 1; uA < b5; uA++)
        soma_deslocamento += lotofacil_deslocamento[12][uA];

    for(long uA = b5 + 1; uA < b6; uA++)
        soma_deslocamento += lotofacil_deslocamento[11][uA];

    for(long uA = b6 + 1; uA < b7; uA++)
        soma_deslocamento += lotofacil_deslocamento[10][uA];

    for(long uA = b7 + 1; uA < b8; uA++)
        soma_deslocamento += lotofacil_deslocamento[9][uA];

    for(long uA = b8 + 1; uA < b9; uA++)
        soma_deslocamento += lotofacil_deslocamento[8][uA];

    for(long uA = b9 + 1; uA < b10; uA++)
        soma_deslocamento += lotofacil_deslocamento[7][uA];

    for(long uA = b10 + 1; uA < b11; uA++)
        soma_deslocamento += lotofacil_deslocamento[6][uA];

    for(long uA = b11 + 1; uA < b12; uA++)
        soma_deslocamento += lotofacil_deslocamento[5][uA];

    for(long uA = b12 + 1; uA < b13; uA++)
        soma_deslocamento += lotofacil_deslocamento[4][uA];

    for(long uA = b13 + 1; uA < b14; uA++)
        soma_deslocamento += lotofacil_deslocamento[3][uA];

    for(long uA = b14 + 1; uA < b15; uA++)
        soma_deslocamento += lotofacil_deslocamento[2][uA];

    for(long uA = b15 + 1; uA < b16; uA++)
        soma_deslocamento += lotofacil_deslocamento[1][uA];

    for(long uA = b16 + 1; uA < b17; uA++)
        soma_deslocamento += 1;

    return soma_deslocamento + deslocamento_inicial;
}

inline long obter_deslocamento_18_bolas(long b1, long b2, long b3, long b4, long b5,
                                long b6, long b7, long b8, long b9, long b10,
                                long b11, long b12, long b13, long b14, long b15, long b16, long b17, long b18)
{
    // Pra cada combinação de qt_bolas, haverá um deslocamento inicial, por exemplo,
    // pra a combinação de 15 bolas, o deslocamento vai de 6393311 a 6393310, entretanto,
    // a função, aqui, retorna a primeira combinação com o valor 0, por isto,
    // devemos indicar o primeiro valor.
    long deslocamento_inicial = 6393311;
    long soma_deslocamento = 0;

    for(long uA = 0; uA < b1; uA++)
        soma_deslocamento += lotofacil_deslocamento[17][uA];

    for(long uA = b1 + 1; uA < b2; uA++)
        soma_deslocamento += lotofacil_deslocamento[16][uA];

    for(long uA = b2 + 1; uA < b3; uA++)
        soma_deslocamento += lotofacil_deslocamento[15][uA];

    for(long uA = b3 + 1; uA < b4; uA++)
        soma_deslocamento += lotofacil_deslocamento[14][uA];

    for(long uA = b4 + 1; uA < b5; uA++)
        soma_deslocamento += lotofacil_deslocamento[13][uA];

    for(long uA = b5 + 1; uA < b6; uA++)
        soma_deslocamento += lotofacil_deslocamento[12][uA];

    for(long uA = b6 + 1; uA < b7; uA++)
        soma_deslocamento += lotofacil_deslocamento[11][uA];

    for(long uA = b7 + 1; uA < b8; uA++)
        soma_deslocamento += lotofacil_deslocamento[10][uA];

    for(long uA = b8 + 1; uA < b9; uA++)
        soma_deslocamento += lotofacil_deslocamento[9][uA];

    for(long uA = b9 + 1; uA < b10; uA++)
        soma_deslocamento += lotofacil_deslocamento[8][uA];

    for(long uA = b10 + 1; uA < b11; uA++)
        soma_deslocamento += lotofacil_deslocamento[7][uA];

    for(long uA = b11 + 1; uA < b12; uA++)
        soma_deslocamento += lotofacil_deslocamento[6][uA];

    for(long uA = b12 + 1; uA < b13; uA++)
        soma_deslocamento += lotofacil_deslocamento[5][uA];

    for(long uA = b13 + 1; uA < b14; uA++)
        soma_deslocamento += lotofacil_deslocamento[4][uA];

    for(long uA = b14 + 1; uA < b15; uA++)
        soma_deslocamento += lotofacil_deslocamento[3][uA];

    for(long uA = b15 + 1; uA < b16; uA++)
        soma_deslocamento += lotofacil_deslocamento[2][uA];

    for(long uA = b16 + 1; uA < b17; uA++)
        soma_deslocamento += lotofacil_deslocamento[1][uA];

    for(long uA = b17 + 1; uA < b18; uA++)
        soma_deslocamento += 1;

    return soma_deslocamento + deslocamento_inicial;
}

#endif // LOTOFACIL_DESLOCAMENTO_HPP
