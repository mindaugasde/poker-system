/* Pokerio sistema - kursinis darbas */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//----------Globalūs kintamieji----------
struct kalade
{
    char reiksme;
    char tipas;
};
struct kalade mas[51];

struct game
{
    char zaidejas[25];
    char reiksme1;
    char tipas1;
    char reiksme2;
    char tipas2;
    int prio;
    char rink[100];
};
struct game gas[8];

int choice,i,j,n=51,m,tf,zaid,check,kortu,stdprio,ss,bb,kk,cc,sk;
char r1,t1,r2,t2,r3,t3,r4,t4,r5,t5;
char h1[10],h2[10],h3[10],winner[200],hand[100];

//----------Menu----------
void menu()
{
    printf("Pokerio tikimybiu apskaiciavimo programa. Pasirinkite: \n");
    printf("(1) Pradeti zaidima \n");
    printf("(2) Instrukcijos \n");
    printf("(3) Baigti programos darba \n\n");
}

//----------Instrukcija----------
void instructions()
{
    printf("(1) Prie stalo gali sedeti iki 9 zmoniu \n\
(2) Kortu kalade sudaro 52 (4x13) kortos is kuriu: \n\
(2.1) 4 tipai - Sirdys(s), Bugnai(b), Kryziai(k), Cirvai(c) \n\
(2.2) 13 reiksmiu - Tuzas(A), Karalius(K), Dama(Q), Bartukas(J), Desimt(T), Devyni(9), Astuoni(8), Septyni(7), Sesi(6), Penki(5), Keturi(4), Trys(3), Du(2) \n\
(3) Kortos ivedamos principu - reiksme tipas. Pvz.: As (Tuzas sirdziu), Tk (Desimt kryziu), 7c (Septyni cirvu) \n\
(4) Kortu kombinacijos pagal prioriteta: \n\
(4.1) Karaliskas pakilimas \n\
(4.2) Tiesus pakilimas \n\
(4.3) Keturios vienodos \n\
(4.4) Pilnas namas \n\
(4.5) Pakilimas \n\
(4.6) Tiesus \n\
(4.7) Trys vienodos \n\
(4.8) Dvi poros \n\
(4.9) Pora \n\
(4.10) Auksciausia korta \n\n");
}

//----------Kortų nuskaitymas----------
void nuskaitymas()
{
    mas[0].reiksme = 'A'; mas[0].tipas = 's'; mas[1].reiksme = 'A'; mas[1].tipas = 'b';
    mas[2].reiksme = 'A'; mas[2].tipas = 'k'; mas[3].reiksme = 'A'; mas[3].tipas = 'c';
    mas[4].reiksme = 'K'; mas[4].tipas = 's'; mas[5].reiksme = 'K'; mas[5].tipas = 'b';
    mas[6].reiksme = 'K'; mas[6].tipas = 'k'; mas[7].reiksme = 'K'; mas[7].tipas = 'c';
    mas[8].reiksme = 'Q'; mas[8].tipas = 's'; mas[9].reiksme = 'Q'; mas[9].tipas = 'b';
    mas[10].reiksme = 'Q'; mas[10].tipas = 'k'; mas[11].reiksme = 'Q'; mas[11].tipas = 'c';
    mas[12].reiksme = 'J'; mas[12].tipas = 's'; mas[13].reiksme = 'J'; mas[13].tipas = 'b';
    mas[14].reiksme = 'J'; mas[14].tipas = 'k'; mas[15].reiksme = 'J'; mas[15].tipas = 'c';
    mas[16].reiksme = 'T'; mas[16].tipas = 's'; mas[17].reiksme = 'T'; mas[17].tipas = 'b';
    mas[18].reiksme = 'T'; mas[18].tipas = 'k'; mas[19].reiksme = 'T'; mas[19].tipas = 'c';
    mas[20].reiksme = '9'; mas[20].tipas = 's'; mas[21].reiksme = '9'; mas[21].tipas = 'b';
    mas[22].reiksme = '9'; mas[22].tipas = 'k'; mas[23].reiksme = '9'; mas[23].tipas = 'c';
    mas[24].reiksme = '8'; mas[24].tipas = 's'; mas[25].reiksme = '8'; mas[25].tipas = 'b';
    mas[26].reiksme = '8'; mas[26].tipas = 'k'; mas[27].reiksme = '8'; mas[27].tipas = 'c';
    mas[28].reiksme = '7'; mas[28].tipas = 's'; mas[29].reiksme = '7'; mas[29].tipas = 'b';
    mas[30].reiksme = '7'; mas[30].tipas = 'k'; mas[31].reiksme = '7'; mas[31].tipas = 'c';
    mas[32].reiksme = '6'; mas[32].tipas = 's'; mas[33].reiksme = '6'; mas[33].tipas = 'b';
    mas[34].reiksme = '6'; mas[34].tipas = 'k'; mas[35].reiksme = '6'; mas[35].tipas = 'c';
    mas[36].reiksme = '5'; mas[36].tipas = 's'; mas[37].reiksme = '5'; mas[37].tipas = 'b';
    mas[38].reiksme = '5'; mas[38].tipas = 'k'; mas[39].reiksme = '5'; mas[39].tipas = 'c';
    mas[40].reiksme = '4'; mas[40].tipas = 's'; mas[41].reiksme = '4'; mas[41].tipas = 'b';
    mas[42].reiksme = '4'; mas[42].tipas = 'k'; mas[43].reiksme = '4'; mas[43].tipas = 'c';
    mas[44].reiksme = '3'; mas[44].tipas = 's'; mas[45].reiksme = '3'; mas[45].tipas = 'b';
    mas[46].reiksme = '3'; mas[46].tipas = 'k'; mas[47].reiksme = '3'; mas[47].tipas = 'c';
    mas[48].reiksme = '2'; mas[48].tipas = 's'; mas[49].reiksme = '2'; mas[49].tipas = 'b';
    mas[50].reiksme = '2'; mas[50].tipas = 'k'; mas[51].reiksme = '2'; mas[51].tipas = 'c';
}

//----------Tikrinimai----------
void se()
{
    ss=0; if (gas[i].tipas1 == 's') ss++; if (gas[i].tipas2 == 's') ss++; if (t1 == 's') ss++;
    if (t2 == 's') ss++; if (t3 == 's') ss++; if (t4 == 's') ss++; if (t5 == 's') ss++;
}
void be()
{
    bb=0; if (gas[i].tipas1 == 'b') bb++; if (gas[i].tipas2 == 'b') bb++; if (t1 == 'b') bb++;
    if (t2 == 'b') bb++; if (t3 == 'b') bb++; if (t4 == 'b') bb++; if (t5 == 'b') bb++;
}
void ke()
{
    kk=0; if (gas[i].tipas1 == 'k') kk++; if (gas[i].tipas2 == 'k') kk++; if (t1 == 'k') kk++;
    if (t2 == 'k') kk++; if (t3 == 'k') kk++; if (t4 == 'k') kk++; if (t5 == 'k') kk++;
}
void ce()
{
    cc=0; if (gas[i].tipas1 == 'c') cc++; if (gas[i].tipas2 == 'c') cc++; if (t1 == 'c') cc++;
    if (t2 == 'c') cc++; if (t3 == 'c') cc++; if (t4 == 'c') cc++; if (t5 == 'c') cc++;
}

//----------Kortų kombinacijos---------
void rinkiniai()
{
    for (i=0; i<=m; i++)
    {
        if (gas[i].tipas1 != ' ')
        {
            strcpy(winner,"");
            if ( (gas[i].reiksme1 == '2') || (gas[i].reiksme2 == '2') || (r1 == '2') || (r2 == '2') || (r3 == '2') || (r4 == '2') || (r5 == '2') )
            {
                gas[i].prio = 1; strcpy(gas[i].rink,"Auksciausia korta (2)");
            }
            if ( (gas[i].reiksme1 == '3') || (gas[i].reiksme2 == '3') || (r1 == '3') || (r2 == '3') || (r3 == '3') || (r4 == '3') || (r5 == '3') )
            {
                gas[i].prio = 2; strcpy(gas[i].rink,"Auksciausia korta (3)");
            }
            if ( (gas[i].reiksme1 == '4') || (gas[i].reiksme2 == '4') || (r1 == '4') || (r2 == '4') || (r3 == '4') || (r4 == '4') || (r5 == '4') )
            {
                gas[i].prio = 3; strcpy(gas[i].rink,"Auksciausia korta (4)");
            }
            if ( (gas[i].reiksme1 == '5') || (gas[i].reiksme2 == '5') || (r1 == '5') || (r2 == '5') || (r3 == '5') || (r4 == '5') || (r5 == '5') )
            {
                gas[i].prio = 4; strcpy(gas[i].rink,"Auksciausia korta (5)");
            }
            if ( (gas[i].reiksme1 == '6') || (gas[i].reiksme2 == '6') || (r1 == '6') || (r2 == '6') || (r3 == '6') || (r4 == '6') || (r5 == '6') )
            {
                gas[i].prio = 5; strcpy(gas[i].rink,"Auksciausia korta (6)");
            }
            if ( (gas[i].reiksme1 == '7') || (gas[i].reiksme2 == '7') || (r1 == '7') || (r2 == '7') || (r3 == '7') || (r4 == '7') || (r5 == '7') )
            {
                gas[i].prio = 6; strcpy(gas[i].rink,"Auksciausia korta (7)");
            }
            if ( (gas[i].reiksme1 == '8') || (gas[i].reiksme2 == '8') || (r1 == '8') || (r2 == '8') || (r3 == '8') || (r4 == '8') || (r5 == '8') )
            {
                gas[i].prio = 7; strcpy(gas[i].rink,"Auksciausia korta (8)");
            }
            if ( (gas[i].reiksme1 == '9') || (gas[i].reiksme2 == '9') || (r1 == '9') || (r2 == '9') || (r3 == '9') || (r4 == '9') || (r5 == '9') )
            {
                gas[i].prio = 8; strcpy(gas[i].rink,"Auksciausia korta (9)");
            }
            if ( (gas[i].reiksme1 == 'T') || (gas[i].reiksme2 == 'T') || (r1 == 'T') || (r2 == 'T') || (r3 == 'T') || (r4 == 'T') || (r5 == 'T') )
            {
                gas[i].prio = 9; strcpy(gas[i].rink,"Auksciausia korta (T)");
            }
            if ( (gas[i].reiksme1 == 'J') || (gas[i].reiksme2 == 'J') || (r1 == 'J') || (r2 == 'J') || (r3 == 'J') || (r4 == 'J') || (r5 == 'J') )
            {
                gas[i].prio = 10; strcpy(gas[i].rink,"Auksciausia korta (J)");
            }
            if ( (gas[i].reiksme1 == 'Q') || (gas[i].reiksme2 == 'Q') || (r1 == 'Q') || (r2 == 'Q') || (r3 == 'Q') || (r4 == 'Q') || (r5 == 'Q') )
            {
                gas[i].prio = 11; strcpy(gas[i].rink,"Auksciausia korta (Q)");
            }
            if ( (gas[i].reiksme1 == 'K') || (gas[i].reiksme2 == 'K') || (r1 == 'K') || (r2 == 'K') || (r3 == 'K') || (r4 == 'K') || (r5 == 'K') )
            {
                gas[i].prio = 12; strcpy(gas[i].rink,"Auksciausia korta (K)");
            }
            if ( (gas[i].reiksme1 == 'A') || (gas[i].reiksme2 == 'A') || (r1 == 'A') || (r2 == 'A') || (r3 == 'A') || (r4 == 'A') || (r5 == 'A') )
            {
                gas[i].prio = 13; strcpy(gas[i].rink,"Auksciausia korta (A)");
            }
            if ( ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2')) || ((r1 == '2') && (r3 == '2')) ||
                 ((r1 == '2') && (r4 == '2')) || ((r1 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2')) || ((r2 == '2') && (r4 == '2')) ||
                 ((r2 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2')) || ((r3 == '2') && (r5 == '2')) || ((r4 == '2') && (r5 == '2')) )
            {
                gas[i].prio = 14; strcpy(gas[i].rink,"Pora (2)");
            }
            if ( ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3')) || ((r1 == '3') && (r3 == '3')) ||
                 ((r1 == '3') && (r4 == '3')) || ((r1 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3')) || ((r2 == '3') && (r4 == '3')) ||
                 ((r2 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3')) || ((r3 == '3') && (r5 == '3')) || ((r4 == '3') && (r5 == '3')) )
            {
                gas[i].prio = 15; strcpy(gas[i].rink,"Pora (3)");
            }
            if ( ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4')) || ((r1 == '4') && (r3 == '4')) ||
                 ((r1 == '4') && (r4 == '4')) || ((r1 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4')) || ((r2 == '4') && (r4 == '4')) ||
                 ((r2 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4')) || ((r3 == '4') && (r5 == '4')) || ((r4 == '4') && (r5 == '4')) )
            {
                gas[i].prio = 16; strcpy(gas[i].rink,"Pora (4)");
            }
            if ( ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5')) || ((r1 == '5') && (r3 == '5')) ||
                 ((r1 == '5') && (r4 == '5')) || ((r1 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5')) || ((r2 == '5') && (r4 == '5')) ||
                 ((r2 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5')) || ((r3 == '5') && (r5 == '5')) || ((r4 == '5') && (r5 == '5')) )
            {
                gas[i].prio = 17; strcpy(gas[i].rink,"Pora (5)");
            }
            if ( ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6')) || ((r1 == '6') && (r3 == '6')) ||
                 ((r1 == '6') && (r4 == '6')) || ((r1 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6')) || ((r2 == '6') && (r4 == '6')) ||
                 ((r2 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6')) || ((r3 == '6') && (r5 == '6')) || ((r4 == '6') && (r5 == '6')) )
            {
                gas[i].prio = 18; strcpy(gas[i].rink,"Pora (6)");
            }
            if ( ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7')) || ((r1 == '7') && (r3 == '7')) ||
                 ((r1 == '7') && (r4 == '7')) || ((r1 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7')) || ((r2 == '7') && (r4 == '7')) ||
                 ((r2 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7')) || ((r3 == '7') && (r5 == '7')) || ((r4 == '7') && (r5 == '7')) )
            {
                gas[i].prio = 19; strcpy(gas[i].rink,"Pora (7)");
            }
            if ( ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8')) || ((r1 == '8') && (r3 == '8')) ||
                 ((r1 == '8') && (r4 == '8')) || ((r1 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8')) || ((r2 == '8') && (r4 == '8')) ||
                 ((r2 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8')) || ((r3 == '8') && (r5 == '8')) || ((r4 == '8') && (r5 == '8')) )
            {
                gas[i].prio = 20; strcpy(gas[i].rink,"Pora (8)");
            }
            if ( ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9')) || ((r1 == '9') && (r3 == '9')) ||
                 ((r1 == '9') && (r4 == '9')) || ((r1 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9')) || ((r2 == '9') && (r4 == '9')) ||
                 ((r2 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9')) || ((r3 == '9') && (r5 == '9')) || ((r4 == '9') && (r5 == '9')) )
            {
                gas[i].prio = 21; strcpy(gas[i].rink,"Pora (9)");
            }
            if ( ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T')) || ((r1 == 'T') && (r3 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T')) || ((r2 == 'T') && (r4 == 'T')) ||
                 ((r2 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T')) || ((r3 == 'T') && (r5 == 'T')) || ((r4 == 'T') && (r5 == 'T')) )
            {
                gas[i].prio = 22; strcpy(gas[i].rink,"Pora (T)");
            }
            if ( ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J')) || ((r1 == 'J') && (r3 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J')) || ((r2 == 'J') && (r4 == 'J')) ||
                 ((r2 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J')) || ((r3 == 'J') && (r5 == 'J')) || ((r4 == 'J') && (r5 == 'J')) )
            {
                gas[i].prio = 23; strcpy(gas[i].rink,"Pora (J)");
            }
            if ( ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q')) || ((r2 == 'Q') && (r4 == 'Q')) ||
                 ((r2 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q')) || ((r3 == 'Q') && (r5 == 'Q')) || ((r4 == 'Q') && (r5 == 'Q')) )
            {
                gas[i].prio = 24; strcpy(gas[i].rink,"Pora (Q)");
            }
            if ( ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K')) || ((r1 == 'K') && (r3 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K')) || ((r2 == 'K') && (r4 == 'K')) ||
                 ((r2 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K')) || ((r3 == 'K') && (r5 == 'K')) || ((r4 == 'K') && (r5 == 'K')) )
            {
                gas[i].prio = 25; strcpy(gas[i].rink,"Pora (K)");
            }
            if ( ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A')) || ((r1 == 'A') && (r3 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A')) || ((r2 == 'A') && (r4 == 'A')) ||
                 ((r2 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A')) || ((r3 == 'A') && (r5 == 'A')) || ((r4 == 'A') && (r5 == 'A')) )
            {
                gas[i].prio = 26; strcpy(gas[i].rink,"Pora (A)");
            }
            if ( (((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2')) || ((r1 == '2') && (r3 == '2')) ||
                 ((r1 == '2') && (r4 == '2')) || ((r1 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2')) || ((r2 == '2') && (r4 == '2')) ||
                 ((r2 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2')) || ((r3 == '2') && (r5 == '2')) || ((r4 == '2') && (r5 == '2'))) &&
                 (((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3')) || ((r1 == '3') && (r3 == '3')) ||
                 ((r1 == '3') && (r4 == '3')) || ((r1 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3')) || ((r2 == '3') && (r4 == '3')) ||
                 ((r2 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3')) || ((r3 == '3') && (r5 == '3')) || ((r4 == '3') && (r5 == '3'))) )
            {
                gas[i].prio = 27; strcpy(gas[i].rink,"Dvi poros (3-2)");
            }
            if ( (((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2')) || ((r1 == '2') && (r3 == '2')) ||
                 ((r1 == '2') && (r4 == '2')) || ((r1 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2')) || ((r2 == '2') && (r4 == '2')) ||
                 ((r2 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2')) || ((r3 == '2') && (r5 == '2')) || ((r4 == '2') && (r5 == '2'))) &&
                 (((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4')) || ((r1 == '4') && (r3 == '4')) ||
                 ((r1 == '4') && (r4 == '4')) || ((r1 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4')) || ((r2 == '4') && (r4 == '4')) ||
                 ((r2 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4')) || ((r3 == '4') && (r5 == '4')) || ((r4 == '4') && (r5 == '4'))) )
            {
                gas[i].prio = 28; strcpy(gas[i].rink,"Dvi poros (4-2)");
            }
            if ( (((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3')) || ((r1 == '3') && (r3 == '3')) ||
                 ((r1 == '3') && (r4 == '3')) || ((r1 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3')) || ((r2 == '3') && (r4 == '3')) ||
                 ((r2 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3')) || ((r3 == '3') && (r5 == '3')) || ((r4 == '3') && (r5 == '3'))) &&
                 (((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4')) || ((r1 == '4') && (r3 == '4')) ||
                 ((r1 == '4') && (r4 == '4')) || ((r1 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4')) || ((r2 == '4') && (r4 == '4')) ||
                 ((r2 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4')) || ((r3 == '4') && (r5 == '4')) || ((r4 == '4') && (r5 == '4'))) )
            {
                gas[i].prio = 29; strcpy(gas[i].rink,"Dvi poros (4-3)");
            }
            if ( (((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2')) || ((r1 == '2') && (r3 == '2')) ||
                 ((r1 == '2') && (r4 == '2')) || ((r1 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2')) || ((r2 == '2') && (r4 == '2')) ||
                 ((r2 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2')) || ((r3 == '2') && (r5 == '2')) || ((r4 == '2') && (r5 == '2'))) &&
                 (((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5')) || ((r1 == '5') && (r3 == '5')) ||
                 ((r1 == '5') && (r4 == '5')) || ((r1 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5')) || ((r2 == '5') && (r4 == '5')) ||
                 ((r2 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5')) || ((r3 == '5') && (r5 == '5')) || ((r4 == '5') && (r5 == '5'))) )
            {
                gas[i].prio = 30; strcpy(gas[i].rink,"Dvi poros (5-2)");
            }
            if ( (((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3')) || ((r1 == '3') && (r3 == '3')) ||
                 ((r1 == '3') && (r4 == '3')) || ((r1 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3')) || ((r2 == '3') && (r4 == '3')) ||
                 ((r2 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3')) || ((r3 == '3') && (r5 == '3')) || ((r4 == '3') && (r5 == '3'))) &&
                 (((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5')) || ((r1 == '5') && (r3 == '5')) ||
                 ((r1 == '5') && (r4 == '5')) || ((r1 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5')) || ((r2 == '5') && (r4 == '5')) ||
                 ((r2 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5')) || ((r3 == '5') && (r5 == '5')) || ((r4 == '5') && (r5 == '5'))) )
            {
                gas[i].prio = 31; strcpy(gas[i].rink,"Dvi poros (5-3)");
            }
            if ( (((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4')) || ((r1 == '4') && (r3 == '4')) ||
                 ((r1 == '4') && (r4 == '4')) || ((r1 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4')) || ((r2 == '4') && (r4 == '4')) ||
                 ((r2 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4')) || ((r3 == '4') && (r5 == '4')) || ((r4 == '4') && (r5 == '4'))) &&
                 (((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5')) || ((r1 == '5') && (r3 == '5')) ||
                 ((r1 == '5') && (r4 == '5')) || ((r1 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5')) || ((r2 == '5') && (r4 == '5')) ||
                 ((r2 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5')) || ((r3 == '5') && (r5 == '5')) || ((r4 == '5') && (r5 == '5'))) )
            {
                gas[i].prio = 32; strcpy(gas[i].rink,"Dvi poros (5-4)");
            }
            if ( (((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2')) || ((r1 == '2') && (r3 == '2')) ||
                 ((r1 == '2') && (r4 == '2')) || ((r1 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2')) || ((r2 == '2') && (r4 == '2')) ||
                 ((r2 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2')) || ((r3 == '2') && (r5 == '2')) || ((r4 == '2') && (r5 == '2'))) &&
                 (((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6')) || ((r1 == '6') && (r3 == '6')) ||
                 ((r1 == '6') && (r4 == '6')) || ((r1 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6')) || ((r2 == '6') && (r4 == '6')) ||
                 ((r2 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6')) || ((r3 == '6') && (r5 == '6')) || ((r4 == '6') && (r5 == '6'))) )
            {
                gas[i].prio = 33; strcpy(gas[i].rink,"Dvi poros (6-2)");
            }
            if ( (((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3')) || ((r1 == '3') && (r3 == '3')) ||
                 ((r1 == '3') && (r4 == '3')) || ((r1 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3')) || ((r2 == '3') && (r4 == '3')) ||
                 ((r2 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3')) || ((r3 == '3') && (r5 == '3')) || ((r4 == '3') && (r5 == '3'))) &&
                 (((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6')) || ((r1 == '6') && (r3 == '6')) ||
                 ((r1 == '6') && (r4 == '6')) || ((r1 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6')) || ((r2 == '6') && (r4 == '6')) ||
                 ((r2 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6')) || ((r3 == '6') && (r5 == '6')) || ((r4 == '6') && (r5 == '6'))) )
            {
                gas[i].prio = 34; strcpy(gas[i].rink,"Dvi poros (6-3)");
            }
            if ( (((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4')) || ((r1 == '4') && (r3 == '4')) ||
                 ((r1 == '4') && (r4 == '4')) || ((r1 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4')) || ((r2 == '4') && (r4 == '4')) ||
                 ((r2 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4')) || ((r3 == '4') && (r5 == '4')) || ((r4 == '4') && (r5 == '4'))) &&
                 (((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6')) || ((r1 == '6') && (r3 == '6')) ||
                 ((r1 == '6') && (r4 == '6')) || ((r1 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6')) || ((r2 == '6') && (r4 == '6')) ||
                 ((r2 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6')) || ((r3 == '6') && (r5 == '6')) || ((r4 == '6') && (r5 == '6'))) )
            {
                gas[i].prio = 35; strcpy(gas[i].rink,"Dvi poros (6-4)");
            }
            if ( (((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5')) || ((r1 == '5') && (r3 == '5')) ||
                 ((r1 == '5') && (r4 == '5')) || ((r1 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5')) || ((r2 == '5') && (r4 == '5')) ||
                 ((r2 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5')) || ((r3 == '5') && (r5 == '5')) || ((r4 == '5') && (r5 == '5'))) &&
                 (((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6')) || ((r1 == '6') && (r3 == '6')) ||
                 ((r1 == '6') && (r4 == '6')) || ((r1 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6')) || ((r2 == '6') && (r4 == '6')) ||
                 ((r2 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6')) || ((r3 == '6') && (r5 == '6')) || ((r4 == '6') && (r5 == '6'))) )
            {
                gas[i].prio = 36; strcpy(gas[i].rink,"Dvi poros (6-5)");
            }
            if ( (((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2')) || ((r1 == '2') && (r3 == '2')) ||
                 ((r1 == '2') && (r4 == '2')) || ((r1 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2')) || ((r2 == '2') && (r4 == '2')) ||
                 ((r2 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2')) || ((r3 == '2') && (r5 == '2')) || ((r4 == '2') && (r5 == '2'))) &&
                 (((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7')) || ((r1 == '7') && (r3 == '7')) ||
                 ((r1 == '7') && (r4 == '7')) || ((r1 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7')) || ((r2 == '7') && (r4 == '7')) ||
                 ((r2 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7')) || ((r3 == '7') && (r5 == '7')) || ((r4 == '7') && (r5 == '7'))) )
            {
                gas[i].prio = 37; strcpy(gas[i].rink,"Dvi poros (7-2)");
            }
            if ( (((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3')) || ((r1 == '3') && (r3 == '3')) ||
                 ((r1 == '3') && (r4 == '3')) || ((r1 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3')) || ((r2 == '3') && (r4 == '3')) ||
                 ((r2 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3')) || ((r3 == '3') && (r5 == '3')) || ((r4 == '3') && (r5 == '3'))) &&
                 (((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7')) || ((r1 == '7') && (r3 == '7')) ||
                 ((r1 == '7') && (r4 == '7')) || ((r1 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7')) || ((r2 == '7') && (r4 == '7')) ||
                 ((r2 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7')) || ((r3 == '7') && (r5 == '7')) || ((r4 == '7') && (r5 == '7'))) )
            {
                gas[i].prio = 38; strcpy(gas[i].rink,"Dvi poros (7-3)");
            }
            if ( (((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4')) || ((r1 == '4') && (r3 == '4')) ||
                 ((r1 == '4') && (r4 == '4')) || ((r1 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4')) || ((r2 == '4') && (r4 == '4')) ||
                 ((r2 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4')) || ((r3 == '4') && (r5 == '4')) || ((r4 == '4') && (r5 == '4'))) &&
                 (((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7')) || ((r1 == '7') && (r3 == '7')) ||
                 ((r1 == '7') && (r4 == '7')) || ((r1 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7')) || ((r2 == '7') && (r4 == '7')) ||
                 ((r2 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7')) || ((r3 == '7') && (r5 == '7')) || ((r4 == '7') && (r5 == '7'))) )
            {
                gas[i].prio = 39; strcpy(gas[i].rink,"Dvi poros (7-4)");
            }
            if ( (((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5')) || ((r1 == '5') && (r3 == '5')) ||
                 ((r1 == '5') && (r4 == '5')) || ((r1 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5')) || ((r2 == '5') && (r4 == '5')) ||
                 ((r2 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5')) || ((r3 == '5') && (r5 == '5')) || ((r4 == '5') && (r5 == '5'))) &&
                 (((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7')) || ((r1 == '7') && (r3 == '7')) ||
                 ((r1 == '7') && (r4 == '7')) || ((r1 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7')) || ((r2 == '7') && (r4 == '7')) ||
                 ((r2 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7')) || ((r3 == '7') && (r5 == '7')) || ((r4 == '7') && (r5 == '7'))) )
            {
                gas[i].prio = 40; strcpy(gas[i].rink,"Dvi poros (7-5)");
            }
            if ( (((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6')) || ((r1 == '6') && (r3 == '6')) ||
                 ((r1 == '6') && (r4 == '6')) || ((r1 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6')) || ((r2 == '6') && (r4 == '6')) ||
                 ((r2 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6')) || ((r3 == '6') && (r5 == '6')) || ((r4 == '6') && (r5 == '6'))) &&
                 (((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7')) || ((r1 == '7') && (r3 == '7')) ||
                 ((r1 == '7') && (r4 == '7')) || ((r1 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7')) || ((r2 == '7') && (r4 == '7')) ||
                 ((r2 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7')) || ((r3 == '7') && (r5 == '7')) || ((r4 == '7') && (r5 == '7'))) )
            {
                gas[i].prio = 41; strcpy(gas[i].rink,"Dvi poros (7-6)");
            }
            if ( (((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2')) || ((r1 == '2') && (r3 == '2')) ||
                 ((r1 == '2') && (r4 == '2')) || ((r1 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2')) || ((r2 == '2') && (r4 == '2')) ||
                 ((r2 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2')) || ((r3 == '2') && (r5 == '2')) || ((r4 == '2') && (r5 == '2'))) &&
                 (((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8')) || ((r1 == '8') && (r3 == '8')) ||
                 ((r1 == '8') && (r4 == '8')) || ((r1 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8')) || ((r2 == '8') && (r4 == '8')) ||
                 ((r2 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8')) || ((r3 == '8') && (r5 == '8')) || ((r4 == '8') && (r5 == '8'))) )
            {
                gas[i].prio = 42; strcpy(gas[i].rink,"Dvi poros (8-2)");
            }
            if ( (((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3')) || ((r1 == '3') && (r3 == '3')) ||
                 ((r1 == '3') && (r4 == '3')) || ((r1 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3')) || ((r2 == '3') && (r4 == '3')) ||
                 ((r2 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3')) || ((r3 == '3') && (r5 == '3')) || ((r4 == '3') && (r5 == '3'))) &&
                 (((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8')) || ((r1 == '8') && (r3 == '8')) ||
                 ((r1 == '8') && (r4 == '8')) || ((r1 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8')) || ((r2 == '8') && (r4 == '8')) ||
                 ((r2 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8')) || ((r3 == '8') && (r5 == '8')) || ((r4 == '8') && (r5 == '8'))) )
            {
                gas[i].prio = 43; strcpy(gas[i].rink,"Dvi poros (8-3)");
            }
            if ( (((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4')) || ((r1 == '4') && (r3 == '4')) ||
                 ((r1 == '4') && (r4 == '4')) || ((r1 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4')) || ((r2 == '4') && (r4 == '4')) ||
                 ((r2 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4')) || ((r3 == '4') && (r5 == '4')) || ((r4 == '4') && (r5 == '4'))) &&
                 (((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8')) || ((r1 == '8') && (r3 == '8')) ||
                 ((r1 == '8') && (r4 == '8')) || ((r1 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8')) || ((r2 == '8') && (r4 == '8')) ||
                 ((r2 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8')) || ((r3 == '8') && (r5 == '8')) || ((r4 == '8') && (r5 == '8'))) )
            {
                gas[i].prio = 44; strcpy(gas[i].rink,"Dvi poros (8-4)");
            }
            if ( (((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5')) || ((r1 == '5') && (r3 == '5')) ||
                 ((r1 == '5') && (r4 == '5')) || ((r1 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5')) || ((r2 == '5') && (r4 == '5')) ||
                 ((r2 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5')) || ((r3 == '5') && (r5 == '5')) || ((r4 == '5') && (r5 == '5'))) &&
                 (((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8')) || ((r1 == '8') && (r3 == '8')) ||
                 ((r1 == '8') && (r4 == '8')) || ((r1 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8')) || ((r2 == '8') && (r4 == '8')) ||
                 ((r2 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8')) || ((r3 == '8') && (r5 == '8')) || ((r4 == '8') && (r5 == '8'))) )
            {
                gas[i].prio = 45; strcpy(gas[i].rink,"Dvi poros (8-5)");
            }
            if ( (((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6')) || ((r1 == '6') && (r3 == '6')) ||
                 ((r1 == '6') && (r4 == '6')) || ((r1 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6')) || ((r2 == '6') && (r4 == '6')) ||
                 ((r2 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6')) || ((r3 == '6') && (r5 == '6')) || ((r4 == '6') && (r5 == '6'))) &&
                 (((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8')) || ((r1 == '8') && (r3 == '8')) ||
                 ((r1 == '8') && (r4 == '8')) || ((r1 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8')) || ((r2 == '8') && (r4 == '8')) ||
                 ((r2 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8')) || ((r3 == '8') && (r5 == '8')) || ((r4 == '8') && (r5 == '8'))) )
            {
                gas[i].prio = 46; strcpy(gas[i].rink,"Dvi poros (8-6)");
            }
            if ( (((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7')) || ((r1 == '7') && (r3 == '7')) ||
                 ((r1 == '7') && (r4 == '7')) || ((r1 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7')) || ((r2 == '7') && (r4 == '7')) ||
                 ((r2 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7')) || ((r3 == '7') && (r5 == '7')) || ((r4 == '7') && (r5 == '7'))) &&
                 (((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8')) || ((r1 == '8') && (r3 == '8')) ||
                 ((r1 == '8') && (r4 == '8')) || ((r1 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8')) || ((r2 == '8') && (r4 == '8')) ||
                 ((r2 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8')) || ((r3 == '8') && (r5 == '8')) || ((r4 == '8') && (r5 == '8'))) )
            {
                gas[i].prio = 47; strcpy(gas[i].rink,"Dvi poros (8-7)");
            }
            if ( (((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2')) || ((r1 == '2') && (r3 == '2')) ||
                 ((r1 == '2') && (r4 == '2')) || ((r1 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2')) || ((r2 == '2') && (r4 == '2')) ||
                 ((r2 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2')) || ((r3 == '2') && (r5 == '2')) || ((r4 == '2') && (r5 == '2'))) &&
                 (((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9')) || ((r1 == '9') && (r3 == '9')) ||
                 ((r1 == '9') && (r4 == '9')) || ((r1 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9')) || ((r2 == '9') && (r4 == '9')) ||
                 ((r2 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9')) || ((r3 == '9') && (r5 == '9')) || ((r4 == '9') && (r5 == '9'))) )
            {
                gas[i].prio = 48; strcpy(gas[i].rink,"Dvi poros (9-2)");
            }
            if ( (((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3')) || ((r1 == '3') && (r3 == '3')) ||
                 ((r1 == '3') && (r4 == '3')) || ((r1 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3')) || ((r2 == '3') && (r4 == '3')) ||
                 ((r2 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3')) || ((r3 == '3') && (r5 == '3')) || ((r4 == '3') && (r5 == '3'))) &&
                 (((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9')) || ((r1 == '9') && (r3 == '9')) ||
                 ((r1 == '9') && (r4 == '9')) || ((r1 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9')) || ((r2 == '9') && (r4 == '9')) ||
                 ((r2 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9')) || ((r3 == '9') && (r5 == '9')) || ((r4 == '9') && (r5 == '9'))) )
            {
                gas[i].prio = 49; strcpy(gas[i].rink,"Dvi poros (9-3)");
            }
            if ( (((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4')) || ((r1 == '4') && (r3 == '4')) ||
                 ((r1 == '4') && (r4 == '4')) || ((r1 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4')) || ((r2 == '4') && (r4 == '4')) ||
                 ((r2 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4')) || ((r3 == '4') && (r5 == '4')) || ((r4 == '4') && (r5 == '4'))) &&
                 (((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9')) || ((r1 == '9') && (r3 == '9')) ||
                 ((r1 == '9') && (r4 == '9')) || ((r1 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9')) || ((r2 == '9') && (r4 == '9')) ||
                 ((r2 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9')) || ((r3 == '9') && (r5 == '9')) || ((r4 == '9') && (r5 == '9'))) )
            {
                gas[i].prio = 50; strcpy(gas[i].rink,"Dvi poros (9-4)");
            }
            if ( (((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5')) || ((r1 == '5') && (r3 == '5')) ||
                 ((r1 == '5') && (r4 == '5')) || ((r1 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5')) || ((r2 == '5') && (r4 == '5')) ||
                 ((r2 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5')) || ((r3 == '5') && (r5 == '5')) || ((r4 == '5') && (r5 == '5'))) &&
                 (((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9')) || ((r1 == '9') && (r3 == '9')) ||
                 ((r1 == '9') && (r4 == '9')) || ((r1 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9')) || ((r2 == '9') && (r4 == '9')) ||
                 ((r2 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9')) || ((r3 == '9') && (r5 == '9')) || ((r4 == '9') && (r5 == '9'))) )
            {
                gas[i].prio = 51; strcpy(gas[i].rink,"Dvi poros (9-5)");
            }
            if ( (((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6')) || ((r1 == '6') && (r3 == '6')) ||
                 ((r1 == '6') && (r4 == '6')) || ((r1 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6')) || ((r2 == '6') && (r4 == '6')) ||
                 ((r2 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6')) || ((r3 == '6') && (r5 == '6')) || ((r4 == '6') && (r5 == '6'))) &&
                 (((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9')) || ((r1 == '9') && (r3 == '9')) ||
                 ((r1 == '9') && (r4 == '9')) || ((r1 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9')) || ((r2 == '9') && (r4 == '9')) ||
                 ((r2 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9')) || ((r3 == '9') && (r5 == '9')) || ((r4 == '9') && (r5 == '9'))) )
            {
                gas[i].prio = 52; strcpy(gas[i].rink,"Dvi poros (9-6)");
            }
            if ( (((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7')) || ((r1 == '7') && (r3 == '7')) ||
                 ((r1 == '7') && (r4 == '7')) || ((r1 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7')) || ((r2 == '7') && (r4 == '7')) ||
                 ((r2 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7')) || ((r3 == '7') && (r5 == '7')) || ((r4 == '7') && (r5 == '7'))) &&
                 (((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9')) || ((r1 == '9') && (r3 == '9')) ||
                 ((r1 == '9') && (r4 == '9')) || ((r1 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9')) || ((r2 == '9') && (r4 == '9')) ||
                 ((r2 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9')) || ((r3 == '9') && (r5 == '9')) || ((r4 == '9') && (r5 == '9'))) )
            {
                gas[i].prio = 53; strcpy(gas[i].rink,"Dvi poros (9-7)");
            }
            if ( (((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8')) || ((r1 == '8') && (r3 == '8')) ||
                 ((r1 == '8') && (r4 == '8')) || ((r1 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8')) || ((r2 == '8') && (r4 == '8')) ||
                 ((r2 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8')) || ((r3 == '8') && (r5 == '8')) || ((r4 == '8') && (r5 == '8'))) &&
                 (((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9')) || ((r1 == '9') && (r3 == '9')) ||
                 ((r1 == '9') && (r4 == '9')) || ((r1 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9')) || ((r2 == '9') && (r4 == '9')) ||
                 ((r2 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9')) || ((r3 == '9') && (r5 == '9')) || ((r4 == '9') && (r5 == '9'))) )
            {
                gas[i].prio = 54; strcpy(gas[i].rink,"Dvi poros (9-8)");
            }
            if ( (((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2')) || ((r1 == '2') && (r3 == '2')) ||
                 ((r1 == '2') && (r4 == '2')) || ((r1 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2')) || ((r2 == '2') && (r4 == '2')) ||
                 ((r2 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2')) || ((r3 == '2') && (r5 == '2')) || ((r4 == '2') && (r5 == '2'))) &&
                 (((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T')) || ((r1 == 'T') && (r3 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T')) || ((r2 == 'T') && (r4 == 'T')) ||
                 ((r2 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T')) || ((r3 == 'T') && (r5 == 'T')) || ((r4 == 'T') && (r5 == 'T'))) )
            {
                gas[i].prio = 55; strcpy(gas[i].rink,"Dvi poros (T-2)");
            }
            if ( (((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3')) || ((r1 == '3') && (r3 == '3')) ||
                 ((r1 == '3') && (r4 == '3')) || ((r1 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3')) || ((r2 == '3') && (r4 == '3')) ||
                 ((r2 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3')) || ((r3 == '3') && (r5 == '3')) || ((r4 == '3') && (r5 == '3'))) &&
                 (((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T')) || ((r1 == 'T') && (r3 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T')) || ((r2 == 'T') && (r4 == 'T')) ||
                 ((r2 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T')) || ((r3 == 'T') && (r5 == 'T')) || ((r4 == 'T') && (r5 == 'T'))) )
            {
                gas[i].prio = 56; strcpy(gas[i].rink,"Dvi poros (T-3)");
            }
            if ( (((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4')) || ((r1 == '4') && (r3 == '4')) ||
                 ((r1 == '4') && (r4 == '4')) || ((r1 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4')) || ((r2 == '4') && (r4 == '4')) ||
                 ((r2 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4')) || ((r3 == '4') && (r5 == '4')) || ((r4 == '4') && (r5 == '4'))) &&
                 (((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T')) || ((r1 == 'T') && (r3 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T')) || ((r2 == 'T') && (r4 == 'T')) ||
                 ((r2 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T')) || ((r3 == 'T') && (r5 == 'T')) || ((r4 == 'T') && (r5 == 'T'))) )
            {
                gas[i].prio = 57; strcpy(gas[i].rink,"Dvi poros (T-4)");
            }
            if ( (((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5')) || ((r1 == '5') && (r3 == '5')) ||
                 ((r1 == '5') && (r4 == '5')) || ((r1 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5')) || ((r2 == '5') && (r4 == '5')) ||
                 ((r2 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5')) || ((r3 == '5') && (r5 == '5')) || ((r4 == '5') && (r5 == '5'))) &&
                 (((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T')) || ((r1 == 'T') && (r3 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T')) || ((r2 == 'T') && (r4 == 'T')) ||
                 ((r2 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T')) || ((r3 == 'T') && (r5 == 'T')) || ((r4 == 'T') && (r5 == 'T'))) )
            {
                gas[i].prio = 58; strcpy(gas[i].rink,"Dvi poros (T-5)");
            }
            if ( (((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6')) || ((r1 == '6') && (r3 == '6')) ||
                 ((r1 == '6') && (r4 == '6')) || ((r1 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6')) || ((r2 == '6') && (r4 == '6')) ||
                 ((r2 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6')) || ((r3 == '6') && (r5 == '6')) || ((r4 == '6') && (r5 == '6'))) &&
                 (((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T')) || ((r1 == 'T') && (r3 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T')) || ((r2 == 'T') && (r4 == 'T')) ||
                 ((r2 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T')) || ((r3 == 'T') && (r5 == 'T')) || ((r4 == 'T') && (r5 == 'T'))) )
            {
                gas[i].prio = 59; strcpy(gas[i].rink,"Dvi poros (T-6)");
            }
            if ( (((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7')) || ((r1 == '7') && (r3 == '7')) ||
                 ((r1 == '7') && (r4 == '7')) || ((r1 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7')) || ((r2 == '7') && (r4 == '7')) ||
                 ((r2 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7')) || ((r3 == '7') && (r5 == '7')) || ((r4 == '7') && (r5 == '7'))) &&
                 (((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T')) || ((r1 == 'T') && (r3 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T')) || ((r2 == 'T') && (r4 == 'T')) ||
                 ((r2 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T')) || ((r3 == 'T') && (r5 == 'T')) || ((r4 == 'T') && (r5 == 'T'))) )
            {
                gas[i].prio = 60; strcpy(gas[i].rink,"Dvi poros (T-7)");
            }
            if ( (((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8')) || ((r1 == '8') && (r3 == '8')) ||
                 ((r1 == '8') && (r4 == '8')) || ((r1 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8')) || ((r2 == '8') && (r4 == '8')) ||
                 ((r2 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8')) || ((r3 == '8') && (r5 == '8')) || ((r4 == '8') && (r5 == '8'))) &&
                 (((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T')) || ((r1 == 'T') && (r3 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T')) || ((r2 == 'T') && (r4 == 'T')) ||
                 ((r2 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T')) || ((r3 == 'T') && (r5 == 'T')) || ((r4 == 'T') && (r5 == 'T'))) )
            {
                gas[i].prio = 61; strcpy(gas[i].rink,"Dvi poros (T-8)");
            }
            if ( (((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9')) || ((r1 == '9') && (r3 == '9')) ||
                 ((r1 == '9') && (r4 == '9')) || ((r1 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9')) || ((r2 == '9') && (r4 == '9')) ||
                 ((r2 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9')) || ((r3 == '9') && (r5 == '9')) || ((r4 == '9') && (r5 == '9'))) &&
                 (((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T')) || ((r1 == 'T') && (r3 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T')) || ((r2 == 'T') && (r4 == 'T')) ||
                 ((r2 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T')) || ((r3 == 'T') && (r5 == 'T')) || ((r4 == 'T') && (r5 == 'T'))) )
            {
                gas[i].prio = 62; strcpy(gas[i].rink,"Dvi poros (T-9)");
            }
            if ( (((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2')) || ((r1 == '2') && (r3 == '2')) ||
                 ((r1 == '2') && (r4 == '2')) || ((r1 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2')) || ((r2 == '2') && (r4 == '2')) ||
                 ((r2 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2')) || ((r3 == '2') && (r5 == '2')) || ((r4 == '2') && (r5 == '2'))) &&
                 (((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J')) || ((r1 == 'J') && (r3 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J')) || ((r2 == 'J') && (r4 == 'J')) ||
                 ((r2 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J')) || ((r3 == 'J') && (r5 == 'J')) || ((r4 == 'J') && (r5 == 'J'))) )
            {
                gas[i].prio = 63; strcpy(gas[i].rink,"Dvi poros (J-2)");
            }
            if ( (((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3')) || ((r1 == '3') && (r3 == '3')) ||
                 ((r1 == '3') && (r4 == '3')) || ((r1 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3')) || ((r2 == '3') && (r4 == '3')) ||
                 ((r2 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3')) || ((r3 == '3') && (r5 == '3')) || ((r4 == '3') && (r5 == '3'))) &&
                 (((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J')) || ((r1 == 'J') && (r3 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J')) || ((r2 == 'J') && (r4 == 'J')) ||
                 ((r2 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J')) || ((r3 == 'J') && (r5 == 'J')) || ((r4 == 'J') && (r5 == 'J'))) )
            {
                gas[i].prio = 64; strcpy(gas[i].rink,"Dvi poros (J-3)");
            }
            if ( (((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4')) || ((r1 == '4') && (r3 == '4')) ||
                 ((r1 == '4') && (r4 == '4')) || ((r1 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4')) || ((r2 == '4') && (r4 == '4')) ||
                 ((r2 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4')) || ((r3 == '4') && (r5 == '4')) || ((r4 == '4') && (r5 == '4'))) &&
                 (((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J')) || ((r1 == 'J') && (r3 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J')) || ((r2 == 'J') && (r4 == 'J')) ||
                 ((r2 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J')) || ((r3 == 'J') && (r5 == 'J')) || ((r4 == 'J') && (r5 == 'J'))) )
            {
                gas[i].prio = 65; strcpy(gas[i].rink,"Dvi poros (J-4)");
            }
            if ( (((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5')) || ((r1 == '5') && (r3 == '5')) ||
                 ((r1 == '5') && (r4 == '5')) || ((r1 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5')) || ((r2 == '5') && (r4 == '5')) ||
                 ((r2 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5')) || ((r3 == '5') && (r5 == '5')) || ((r4 == '5') && (r5 == '5'))) &&
                 (((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J')) || ((r1 == 'J') && (r3 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J')) || ((r2 == 'J') && (r4 == 'J')) ||
                 ((r2 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J')) || ((r3 == 'J') && (r5 == 'J')) || ((r4 == 'J') && (r5 == 'J'))) )
            {
                gas[i].prio = 66; strcpy(gas[i].rink,"Dvi poros (J-5)");
            }
            if ( (((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6')) || ((r1 == '6') && (r3 == '6')) ||
                 ((r1 == '6') && (r4 == '6')) || ((r1 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6')) || ((r2 == '6') && (r4 == '6')) ||
                 ((r2 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6')) || ((r3 == '6') && (r5 == '6')) || ((r4 == '6') && (r5 == '6'))) &&
                 (((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J')) || ((r1 == 'J') && (r3 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J')) || ((r2 == 'J') && (r4 == 'J')) ||
                 ((r2 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J')) || ((r3 == 'J') && (r5 == 'J')) || ((r4 == 'J') && (r5 == 'J'))) )
            {
                gas[i].prio = 67; strcpy(gas[i].rink,"Dvi poros (J-6)");
            }
            if ( (((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7')) || ((r1 == '7') && (r3 == '7')) ||
                 ((r1 == '7') && (r4 == '7')) || ((r1 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7')) || ((r2 == '7') && (r4 == '7')) ||
                 ((r2 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7')) || ((r3 == '7') && (r5 == '7')) || ((r4 == '7') && (r5 == '7'))) &&
                 (((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J')) || ((r1 == 'J') && (r3 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J')) || ((r2 == 'J') && (r4 == 'J')) ||
                 ((r2 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J')) || ((r3 == 'J') && (r5 == 'J')) || ((r4 == 'J') && (r5 == 'J'))) )
            {
                gas[i].prio = 68; strcpy(gas[i].rink,"Dvi poros (J-7)");
            }
            if ( (((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8')) || ((r1 == '8') && (r3 == '8')) ||
                 ((r1 == '8') && (r4 == '8')) || ((r1 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8')) || ((r2 == '8') && (r4 == '8')) ||
                 ((r2 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8')) || ((r3 == '8') && (r5 == '8')) || ((r4 == '8') && (r5 == '8'))) &&
                 (((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J')) || ((r1 == 'J') && (r3 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J')) || ((r2 == 'J') && (r4 == 'J')) ||
                 ((r2 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J')) || ((r3 == 'J') && (r5 == 'J')) || ((r4 == 'J') && (r5 == 'J'))) )
            {
                gas[i].prio = 69; strcpy(gas[i].rink,"Dvi poros (J-8)");
            }
            if ( (((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9')) || ((r1 == '9') && (r3 == '9')) ||
                 ((r1 == '9') && (r4 == '9')) || ((r1 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9')) || ((r2 == '9') && (r4 == '9')) ||
                 ((r2 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9')) || ((r3 == '9') && (r5 == '9')) || ((r4 == '9') && (r5 == '9'))) &&
                 (((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J')) || ((r1 == 'J') && (r3 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J')) || ((r2 == 'J') && (r4 == 'J')) ||
                 ((r2 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J')) || ((r3 == 'J') && (r5 == 'J')) || ((r4 == 'J') && (r5 == 'J'))) )
            {
                gas[i].prio = 70; strcpy(gas[i].rink,"Dvi poros (J-9)");
            }
            if ( (((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T')) || ((r1 == 'T') && (r3 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T')) || ((r2 == 'T') && (r4 == 'T')) ||
                 ((r2 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T')) || ((r3 == 'T') && (r5 == 'T')) || ((r4 == 'T') && (r5 == 'T'))) &&
                 (((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J')) || ((r1 == 'J') && (r3 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J')) || ((r2 == 'J') && (r4 == 'J')) ||
                 ((r2 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J')) || ((r3 == 'J') && (r5 == 'J')) || ((r4 == 'J') && (r5 == 'J'))) )
            {
                gas[i].prio = 71; strcpy(gas[i].rink,"Dvi poros (J-T)");
            }
            if ( (((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2')) || ((r1 == '2') && (r3 == '2')) ||
                 ((r1 == '2') && (r4 == '2')) || ((r1 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2')) || ((r2 == '2') && (r4 == '2')) ||
                 ((r2 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2')) || ((r3 == '2') && (r5 == '2')) || ((r4 == '2') && (r5 == '2'))) &&
                 (((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q')) || ((r2 == 'Q') && (r4 == 'Q')) ||
                 ((r2 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q')) || ((r3 == 'Q') && (r5 == 'Q')) || ((r4 == 'Q') && (r5 == 'Q'))) )
            {
                gas[i].prio = 72; strcpy(gas[i].rink,"Dvi poros (Q-2)");
            }
            if ( (((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3')) || ((r1 == '3') && (r3 == '3')) ||
                 ((r1 == '3') && (r4 == '3')) || ((r1 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3')) || ((r2 == '3') && (r4 == '3')) ||
                 ((r2 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3')) || ((r3 == '3') && (r5 == '3')) || ((r4 == '3') && (r5 == '3'))) &&
                 (((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q')) || ((r2 == 'Q') && (r4 == 'Q')) ||
                 ((r2 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q')) || ((r3 == 'Q') && (r5 == 'Q')) || ((r4 == 'Q') && (r5 == 'Q'))) )
            {
                gas[i].prio = 73; strcpy(gas[i].rink,"Dvi poros (Q-3)");
            }
            if ( (((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4')) || ((r1 == '4') && (r3 == '4')) ||
                 ((r1 == '4') && (r4 == '4')) || ((r1 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4')) || ((r2 == '4') && (r4 == '4')) ||
                 ((r2 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4')) || ((r3 == '4') && (r5 == '4')) || ((r4 == '4') && (r5 == '4'))) &&
                 (((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q')) || ((r2 == 'Q') && (r4 == 'Q')) ||
                 ((r2 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q')) || ((r3 == 'Q') && (r5 == 'Q')) || ((r4 == 'Q') && (r5 == 'Q'))) )
            {
                gas[i].prio = 74; strcpy(gas[i].rink,"Dvi poros (Q-4)");
            }
            if ( (((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5')) || ((r1 == '5') && (r3 == '5')) ||
                 ((r1 == '5') && (r4 == '5')) || ((r1 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5')) || ((r2 == '5') && (r4 == '5')) ||
                 ((r2 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5')) || ((r3 == '5') && (r5 == '5')) || ((r4 == '5') && (r5 == '5'))) &&
                 (((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q')) || ((r2 == 'Q') && (r4 == 'Q')) ||
                 ((r2 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q')) || ((r3 == 'Q') && (r5 == 'Q')) || ((r4 == 'Q') && (r5 == 'Q'))) )
            {
                gas[i].prio = 75; strcpy(gas[i].rink,"Dvi poros (Q-5)");
            }
            if ( (((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6')) || ((r1 == '6') && (r3 == '6')) ||
                 ((r1 == '6') && (r4 == '6')) || ((r1 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6')) || ((r2 == '6') && (r4 == '6')) ||
                 ((r2 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6')) || ((r3 == '6') && (r5 == '6')) || ((r4 == '6') && (r5 == '6'))) &&
                 (((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q')) || ((r2 == 'Q') && (r4 == 'Q')) ||
                 ((r2 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q')) || ((r3 == 'Q') && (r5 == 'Q')) || ((r4 == 'Q') && (r5 == 'Q'))) )
            {
                gas[i].prio = 76; strcpy(gas[i].rink,"Dvi poros (Q-6)");
            }
            if ( (((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7')) || ((r1 == '7') && (r3 == '7')) ||
                 ((r1 == '7') && (r4 == '7')) || ((r1 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7')) || ((r2 == '7') && (r4 == '7')) ||
                 ((r2 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7')) || ((r3 == '7') && (r5 == '7')) || ((r4 == '7') && (r5 == '7'))) &&
                 (((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q')) || ((r2 == 'Q') && (r4 == 'Q')) ||
                 ((r2 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q')) || ((r3 == 'Q') && (r5 == 'Q')) || ((r4 == 'Q') && (r5 == 'Q'))) )
            {
                gas[i].prio = 77; strcpy(gas[i].rink,"Dvi poros (Q-7)");
            }
            if ( (((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8')) || ((r1 == '8') && (r3 == '8')) ||
                 ((r1 == '8') && (r4 == '8')) || ((r1 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8')) || ((r2 == '8') && (r4 == '8')) ||
                 ((r2 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8')) || ((r3 == '8') && (r5 == '8')) || ((r4 == '8') && (r5 == '8'))) &&
                 (((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q')) || ((r2 == 'Q') && (r4 == 'Q')) ||
                 ((r2 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q')) || ((r3 == 'Q') && (r5 == 'Q')) || ((r4 == 'Q') && (r5 == 'Q'))) )
            {
                gas[i].prio = 78; strcpy(gas[i].rink,"Dvi poros (Q-8)");
            }
            if ( (((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9')) || ((r1 == '9') && (r3 == '9')) ||
                 ((r1 == '9') && (r4 == '9')) || ((r1 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9')) || ((r2 == '9') && (r4 == '9')) ||
                 ((r2 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9')) || ((r3 == '9') && (r5 == '9')) || ((r4 == '9') && (r5 == '9'))) &&
                 (((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q')) || ((r2 == 'Q') && (r4 == 'Q')) ||
                 ((r2 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q')) || ((r3 == 'Q') && (r5 == 'Q')) || ((r4 == 'Q') && (r5 == 'Q'))) )
            {
                gas[i].prio = 79; strcpy(gas[i].rink,"Dvi poros (Q-9)");
            }
            if ( (((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T')) || ((r1 == 'T') && (r3 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T')) || ((r2 == 'T') && (r4 == 'T')) ||
                 ((r2 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T')) || ((r3 == 'T') && (r5 == 'T')) || ((r4 == 'T') && (r5 == 'T'))) &&
                 (((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q')) || ((r2 == 'Q') && (r4 == 'Q')) ||
                 ((r2 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q')) || ((r3 == 'Q') && (r5 == 'Q')) || ((r4 == 'Q') && (r5 == 'Q'))) )
            {
                gas[i].prio = 80; strcpy(gas[i].rink,"Dvi poros (Q-T)");
            }
            if ( (((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J')) || ((r1 == 'J') && (r3 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J')) || ((r2 == 'J') && (r4 == 'J')) ||
                 ((r2 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J')) || ((r3 == 'J') && (r5 == 'J')) || ((r4 == 'J') && (r5 == 'J'))) &&
                 (((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q')) || ((r2 == 'Q') && (r4 == 'Q')) ||
                 ((r2 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q')) || ((r3 == 'Q') && (r5 == 'Q')) || ((r4 == 'Q') && (r5 == 'Q'))) )
            {
                gas[i].prio = 81; strcpy(gas[i].rink,"Dvi poros (Q-J)");
            }
            if ( (((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2')) || ((r1 == '2') && (r3 == '2')) ||
                 ((r1 == '2') && (r4 == '2')) || ((r1 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2')) || ((r2 == '2') && (r4 == '2')) ||
                 ((r2 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2')) || ((r3 == '2') && (r5 == '2')) || ((r4 == '2') && (r5 == '2'))) &&
                 (((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K')) || ((r1 == 'K') && (r3 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K')) || ((r2 == 'K') && (r4 == 'K')) ||
                 ((r2 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K')) || ((r3 == 'K') && (r5 == 'K')) || ((r4 == 'K') && (r5 == 'K'))) )
            {
                gas[i].prio = 82; strcpy(gas[i].rink,"Dvi poros (K-2)");
            }
            if ( (((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3')) || ((r1 == '3') && (r3 == '3')) ||
                 ((r1 == '3') && (r4 == '3')) || ((r1 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3')) || ((r2 == '3') && (r4 == '3')) ||
                 ((r2 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3')) || ((r3 == '3') && (r5 == '3')) || ((r4 == '3') && (r5 == '3'))) &&
                 (((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K')) || ((r1 == 'K') && (r3 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K')) || ((r2 == 'K') && (r4 == 'K')) ||
                 ((r2 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K')) || ((r3 == 'K') && (r5 == 'K')) || ((r4 == 'K') && (r5 == 'K'))) )
            {
                gas[i].prio = 83; strcpy(gas[i].rink,"Dvi poros (K-3)");
            }
            if ( (((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4')) || ((r1 == '4') && (r3 == '4')) ||
                 ((r1 == '4') && (r4 == '4')) || ((r1 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4')) || ((r2 == '4') && (r4 == '4')) ||
                 ((r2 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4')) || ((r3 == '4') && (r5 == '4')) || ((r4 == '4') && (r5 == '4'))) &&
                 (((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K')) || ((r1 == 'K') && (r3 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K')) || ((r2 == 'K') && (r4 == 'K')) ||
                 ((r2 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K')) || ((r3 == 'K') && (r5 == 'K')) || ((r4 == 'K') && (r5 == 'K'))) )
            {
                gas[i].prio = 84; strcpy(gas[i].rink,"Dvi poros (K-4)");
            }
            if ( (((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5')) || ((r1 == '5') && (r3 == '5')) ||
                 ((r1 == '5') && (r4 == '5')) || ((r1 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5')) || ((r2 == '5') && (r4 == '5')) ||
                 ((r2 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5')) || ((r3 == '5') && (r5 == '5')) || ((r4 == '5') && (r5 == '5'))) &&
                 (((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K')) || ((r1 == 'K') && (r3 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K')) || ((r2 == 'K') && (r4 == 'K')) ||
                 ((r2 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K')) || ((r3 == 'K') && (r5 == 'K')) || ((r4 == 'K') && (r5 == 'K'))) )
            {
                gas[i].prio = 85; strcpy(gas[i].rink,"Dvi poros (K-5)");
            }
            if ( (((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6')) || ((r1 == '6') && (r3 == '6')) ||
                 ((r1 == '6') && (r4 == '6')) || ((r1 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6')) || ((r2 == '6') && (r4 == '6')) ||
                 ((r2 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6')) || ((r3 == '6') && (r5 == '6')) || ((r4 == '6') && (r5 == '6'))) &&
                 (((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K')) || ((r1 == 'K') && (r3 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K')) || ((r2 == 'K') && (r4 == 'K')) ||
                 ((r2 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K')) || ((r3 == 'K') && (r5 == 'K')) || ((r4 == 'K') && (r5 == 'K'))) )
            {
                gas[i].prio = 86; strcpy(gas[i].rink,"Dvi poros (K-6)");
            }
            if ( (((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7')) || ((r1 == '7') && (r3 == '7')) ||
                 ((r1 == '7') && (r4 == '7')) || ((r1 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7')) || ((r2 == '7') && (r4 == '7')) ||
                 ((r2 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7')) || ((r3 == '7') && (r5 == '7')) || ((r4 == '7') && (r5 == '7'))) &&
                 (((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K')) || ((r1 == 'K') && (r3 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K')) || ((r2 == 'K') && (r4 == 'K')) ||
                 ((r2 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K')) || ((r3 == 'K') && (r5 == 'K')) || ((r4 == 'K') && (r5 == 'K'))) )
            {
                gas[i].prio = 87; strcpy(gas[i].rink,"Dvi poros (K-7)");
            }
            if ( (((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8')) || ((r1 == '8') && (r3 == '8')) ||
                 ((r1 == '8') && (r4 == '8')) || ((r1 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8')) || ((r2 == '8') && (r4 == '8')) ||
                 ((r2 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8')) || ((r3 == '8') && (r5 == '8')) || ((r4 == '8') && (r5 == '8'))) &&
                 (((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K')) || ((r1 == 'K') && (r3 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K')) || ((r2 == 'K') && (r4 == 'K')) ||
                 ((r2 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K')) || ((r3 == 'K') && (r5 == 'K')) || ((r4 == 'K') && (r5 == 'K'))) )
            {
                gas[i].prio = 88; strcpy(gas[i].rink,"Dvi poros (K-8)");
            }
            if ( (((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9')) || ((r1 == '9') && (r3 == '9')) ||
                 ((r1 == '9') && (r4 == '9')) || ((r1 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9')) || ((r2 == '9') && (r4 == '9')) ||
                 ((r2 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9')) || ((r3 == '9') && (r5 == '9')) || ((r4 == '9') && (r5 == '9'))) &&
                 (((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K')) || ((r1 == 'K') && (r3 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K')) || ((r2 == 'K') && (r4 == 'K')) ||
                 ((r2 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K')) || ((r3 == 'K') && (r5 == 'K')) || ((r4 == 'K') && (r5 == 'K'))) )
            {
                gas[i].prio = 89; strcpy(gas[i].rink,"Dvi poros (K-9)");
            }
            if ( (((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T')) || ((r1 == 'T') && (r3 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T')) || ((r2 == 'T') && (r4 == 'T')) ||
                 ((r2 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T')) || ((r3 == 'T') && (r5 == 'T')) || ((r4 == 'T') && (r5 == 'T'))) &&
                 (((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K')) || ((r1 == 'K') && (r3 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K')) || ((r2 == 'K') && (r4 == 'K')) ||
                 ((r2 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K')) || ((r3 == 'K') && (r5 == 'K')) || ((r4 == 'K') && (r5 == 'K'))) )
            {
                gas[i].prio = 90; strcpy(gas[i].rink,"Dvi poros (K-T)");
            }
            if ( (((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J')) || ((r1 == 'J') && (r3 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J')) || ((r2 == 'J') && (r4 == 'J')) ||
                 ((r2 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J')) || ((r3 == 'J') && (r5 == 'J')) || ((r4 == 'J') && (r5 == 'J'))) &&
                 (((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K')) || ((r1 == 'K') && (r3 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K')) || ((r2 == 'K') && (r4 == 'K')) ||
                 ((r2 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K')) || ((r3 == 'K') && (r5 == 'K')) || ((r4 == 'K') && (r5 == 'K'))) )
            {
                gas[i].prio = 91; strcpy(gas[i].rink,"Dvi poros (K-J)");
            }
            if ( (((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q')) || ((r2 == 'Q') && (r4 == 'Q')) ||
                 ((r2 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q')) || ((r3 == 'Q') && (r5 == 'Q')) || ((r4 == 'Q') && (r5 == 'Q'))) &&
                 (((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K')) || ((r1 == 'K') && (r3 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K')) || ((r2 == 'K') && (r4 == 'K')) ||
                 ((r2 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K')) || ((r3 == 'K') && (r5 == 'K')) || ((r4 == 'K') && (r5 == 'K'))) )
            {
                gas[i].prio = 92; strcpy(gas[i].rink,"Dvi poros (K-Q)");
            }
            if ( (((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2')) || ((r1 == '2') && (r3 == '2')) ||
                 ((r1 == '2') && (r4 == '2')) || ((r1 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2')) || ((r2 == '2') && (r4 == '2')) ||
                 ((r2 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2')) || ((r3 == '2') && (r5 == '2')) || ((r4 == '2') && (r5 == '2'))) &&
                 (((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A')) || ((r1 == 'A') && (r3 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A')) || ((r2 == 'A') && (r4 == 'A')) ||
                 ((r2 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A')) || ((r3 == 'A') && (r5 == 'A')) || ((r4 == 'A') && (r5 == 'A'))) )
            {
                gas[i].prio = 93; strcpy(gas[i].rink,"Dvi poros (A-2)");
            }
            if ( (((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3')) || ((r1 == '3') && (r3 == '3')) ||
                 ((r1 == '3') && (r4 == '3')) || ((r1 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3')) || ((r2 == '3') && (r4 == '3')) ||
                 ((r2 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3')) || ((r3 == '3') && (r5 == '3')) || ((r4 == '3') && (r5 == '3'))) &&
                 (((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A')) || ((r1 == 'A') && (r3 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A')) || ((r2 == 'A') && (r4 == 'A')) ||
                 ((r2 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A')) || ((r3 == 'A') && (r5 == 'A')) || ((r4 == 'A') && (r5 == 'A'))) )
            {
                gas[i].prio = 94; strcpy(gas[i].rink,"Dvi poros (A-3)");
            }
            if ( (((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4')) || ((r1 == '4') && (r3 == '4')) ||
                 ((r1 == '4') && (r4 == '4')) || ((r1 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4')) || ((r2 == '4') && (r4 == '4')) ||
                 ((r2 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4')) || ((r3 == '4') && (r5 == '4')) || ((r4 == '4') && (r5 == '4'))) &&
                 (((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A')) || ((r1 == 'A') && (r3 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A')) || ((r2 == 'A') && (r4 == 'A')) ||
                 ((r2 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A')) || ((r3 == 'A') && (r5 == 'A')) || ((r4 == 'A') && (r5 == 'A'))) )
            {
                gas[i].prio = 95; strcpy(gas[i].rink,"Dvi poros (A-4)");
            }
            if ( (((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5')) || ((r1 == '5') && (r3 == '5')) ||
                 ((r1 == '5') && (r4 == '5')) || ((r1 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5')) || ((r2 == '5') && (r4 == '5')) ||
                 ((r2 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5')) || ((r3 == '5') && (r5 == '5')) || ((r4 == '5') && (r5 == '5'))) &&
                 (((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A')) || ((r1 == 'A') && (r3 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A')) || ((r2 == 'A') && (r4 == 'A')) ||
                 ((r2 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A')) || ((r3 == 'A') && (r5 == 'A')) || ((r4 == 'A') && (r5 == 'A'))) )
            {
                gas[i].prio = 96; strcpy(gas[i].rink,"Dvi poros (A-5)");
            }
            if ( (((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6')) || ((r1 == '6') && (r3 == '6')) ||
                 ((r1 == '6') && (r4 == '6')) || ((r1 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6')) || ((r2 == '6') && (r4 == '6')) ||
                 ((r2 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6')) || ((r3 == '6') && (r5 == '6')) || ((r4 == '6') && (r5 == '6'))) &&
                 (((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A')) || ((r1 == 'A') && (r3 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A')) || ((r2 == 'A') && (r4 == 'A')) ||
                 ((r2 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A')) || ((r3 == 'A') && (r5 == 'A')) || ((r4 == 'A') && (r5 == 'A'))) )
            {
                gas[i].prio = 97; strcpy(gas[i].rink,"Dvi poros (A-6)");
            }
            if ( (((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7')) || ((r1 == '7') && (r3 == '7')) ||
                 ((r1 == '7') && (r4 == '7')) || ((r1 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7')) || ((r2 == '7') && (r4 == '7')) ||
                 ((r2 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7')) || ((r3 == '7') && (r5 == '7')) || ((r4 == '7') && (r5 == '7'))) &&
                 (((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A')) || ((r1 == 'A') && (r3 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A')) || ((r2 == 'A') && (r4 == 'A')) ||
                 ((r2 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A')) || ((r3 == 'A') && (r5 == 'A')) || ((r4 == 'A') && (r5 == 'A'))) )
            {
                gas[i].prio = 98; strcpy(gas[i].rink,"Dvi poros (A-7)");
            }
            if ( (((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8')) || ((r1 == '8') && (r3 == '8')) ||
                 ((r1 == '8') && (r4 == '8')) || ((r1 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8')) || ((r2 == '8') && (r4 == '8')) ||
                 ((r2 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8')) || ((r3 == '8') && (r5 == '8')) || ((r4 == '8') && (r5 == '8'))) &&
                 (((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A')) || ((r1 == 'A') && (r3 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A')) || ((r2 == 'A') && (r4 == 'A')) ||
                 ((r2 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A')) || ((r3 == 'A') && (r5 == 'A')) || ((r4 == 'A') && (r5 == 'A'))) )
            {
                gas[i].prio = 99; strcpy(gas[i].rink,"Dvi poros (A-8)");
            }
            if ( (((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9')) || ((r1 == '9') && (r3 == '9')) ||
                 ((r1 == '9') && (r4 == '9')) || ((r1 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9')) || ((r2 == '9') && (r4 == '9')) ||
                 ((r2 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9')) || ((r3 == '9') && (r5 == '9')) || ((r4 == '9') && (r5 == '9'))) &&
                 (((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A')) || ((r1 == 'A') && (r3 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A')) || ((r2 == 'A') && (r4 == 'A')) ||
                 ((r2 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A')) || ((r3 == 'A') && (r5 == 'A')) || ((r4 == 'A') && (r5 == 'A'))) )
            {
                gas[i].prio = 100; strcpy(gas[i].rink,"Dvi poros (A-9)");
            }
            if ( (((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T')) || ((r1 == 'T') && (r3 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T')) || ((r2 == 'T') && (r4 == 'T')) ||
                 ((r2 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T')) || ((r3 == 'T') && (r5 == 'T')) || ((r4 == 'T') && (r5 == 'T'))) &&
                 (((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A')) || ((r1 == 'A') && (r3 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A')) || ((r2 == 'A') && (r4 == 'A')) ||
                 ((r2 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A')) || ((r3 == 'A') && (r5 == 'A')) || ((r4 == 'A') && (r5 == 'A'))) )
            {
                gas[i].prio = 101; strcpy(gas[i].rink,"Dvi poros (A-T)");
            }
            if ( (((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J')) || ((r1 == 'J') && (r3 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J')) || ((r2 == 'J') && (r4 == 'J')) ||
                 ((r2 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J')) || ((r3 == 'J') && (r5 == 'J')) || ((r4 == 'J') && (r5 == 'J'))) &&
                 (((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A')) || ((r1 == 'A') && (r3 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A')) || ((r2 == 'A') && (r4 == 'A')) ||
                 ((r2 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A')) || ((r3 == 'A') && (r5 == 'A')) || ((r4 == 'A') && (r5 == 'A'))) )
            {
                gas[i].prio = 102; strcpy(gas[i].rink,"Dvi poros (A-J)");
            }
            if ( (((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q')) || ((r2 == 'Q') && (r4 == 'Q')) ||
                 ((r2 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q')) || ((r3 == 'Q') && (r5 == 'Q')) || ((r4 == 'Q') && (r5 == 'Q'))) &&
                 (((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A')) || ((r1 == 'A') && (r3 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A')) || ((r2 == 'A') && (r4 == 'A')) ||
                 ((r2 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A')) || ((r3 == 'A') && (r5 == 'A')) || ((r4 == 'A') && (r5 == 'A'))) )
            {
                gas[i].prio = 103; strcpy(gas[i].rink,"Dvi poros (A-Q)");
            }
            if ( (((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K')) || ((r1 == 'K') && (r3 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K')) || ((r2 == 'K') && (r4 == 'K')) ||
                 ((r2 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K')) || ((r3 == 'K') && (r5 == 'K')) || ((r4 == 'K') && (r5 == 'K'))) &&
                 (((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A')) || ((r1 == 'A') && (r3 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A')) || ((r2 == 'A') && (r4 == 'A')) ||
                 ((r2 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A')) || ((r3 == 'A') && (r5 == 'A')) || ((r4 == 'A') && (r5 == 'A'))) )
            {
                gas[i].prio = 104; strcpy(gas[i].rink,"Dvi poros (A-K)");
            }
            if ( ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r5 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r1 == '2') && (r5 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r2 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r4 == '2') && (r5 == '2')) || ((gas[i].reiksme2 == '2') && (r1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2') && (r3 == '2')) || ((gas[i].reiksme2 == '2') && (r1 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2') && (r5 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r3 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2') && (r3 == '2')) || ((r1 == '2') && (r2 == '2') && (r4 == '2')) ||
                 ((r1 == '2') && (r2 == '2') && (r5 == '2')) || ((r1 == '2') && (r3 == '2') && (r4 == '2')) || ((r1 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((r1 == '2') && (r4 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2') && (r4 == '2')) || ((r2 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((r2 == '2') && (r4 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2') && (r5 == '2')) )
            {
                gas[i].prio = 105; strcpy(gas[i].rink,"Trys vienodos (2)");
            }
            if ( ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r5 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r1 == '3') && (r5 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r2 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r4 == '3') && (r5 == '3')) || ((gas[i].reiksme2 == '3') && (r1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3') && (r3 == '3')) || ((gas[i].reiksme2 == '3') && (r1 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3') && (r5 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r3 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3') && (r3 == '3')) || ((r1 == '3') && (r2 == '3') && (r4 == '3')) ||
                 ((r1 == '3') && (r2 == '3') && (r5 == '3')) || ((r1 == '3') && (r3 == '3') && (r4 == '3')) || ((r1 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((r1 == '3') && (r4 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3') && (r4 == '3')) || ((r2 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((r2 == '3') && (r4 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3') && (r5 == '3')) )
            {
                gas[i].prio = 106; strcpy(gas[i].rink,"Trys vienodos (3)");
            }
            if ( ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r5 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r1 == '4') && (r5 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r2 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r4 == '4') && (r5 == '4')) || ((gas[i].reiksme2 == '4') && (r1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4') && (r3 == '4')) || ((gas[i].reiksme2 == '4') && (r1 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4') && (r5 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r3 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4') && (r3 == '4')) || ((r1 == '4') && (r2 == '4') && (r4 == '4')) ||
                 ((r1 == '4') && (r2 == '4') && (r5 == '4')) || ((r1 == '4') && (r3 == '4') && (r4 == '4')) || ((r1 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((r1 == '4') && (r4 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4') && (r4 == '4')) || ((r2 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((r2 == '4') && (r4 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4') && (r5 == '4')) )
            {
                gas[i].prio = 107; strcpy(gas[i].rink,"Trys vienodos (4)");
            }
            if ( ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r5 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r1 == '5') && (r5 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r2 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r4 == '5') && (r5 == '5')) || ((gas[i].reiksme2 == '5') && (r1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5') && (r3 == '5')) || ((gas[i].reiksme2 == '5') && (r1 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5') && (r5 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r3 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5') && (r3 == '5')) || ((r1 == '5') && (r2 == '5') && (r4 == '5')) ||
                 ((r1 == '5') && (r2 == '5') && (r5 == '5')) || ((r1 == '5') && (r3 == '5') && (r4 == '5')) || ((r1 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((r1 == '5') && (r4 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5') && (r4 == '5')) || ((r2 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((r2 == '5') && (r4 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5') && (r5 == '5')) )
            {
                gas[i].prio = 108; strcpy(gas[i].rink,"Trys vienodos (5)");
            }
            if ( ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r5 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r1 == '6') && (r5 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r2 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r4 == '6') && (r5 == '6')) || ((gas[i].reiksme2 == '6') && (r1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6') && (r3 == '6')) || ((gas[i].reiksme2 == '6') && (r1 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6') && (r5 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r3 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6') && (r3 == '6')) || ((r1 == '6') && (r2 == '6') && (r4 == '6')) ||
                 ((r1 == '6') && (r2 == '6') && (r5 == '6')) || ((r1 == '6') && (r3 == '6') && (r4 == '6')) || ((r1 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((r1 == '6') && (r4 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6') && (r4 == '6')) || ((r2 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((r2 == '6') && (r4 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6') && (r5 == '6')) )
            {
                gas[i].prio = 109; strcpy(gas[i].rink,"Trys vienodos (6)");
            }
            if ( ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r5 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r1 == '7') && (r5 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r2 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r4 == '7') && (r5 == '7')) || ((gas[i].reiksme2 == '7') && (r1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7') && (r3 == '7')) || ((gas[i].reiksme2 == '7') && (r1 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7') && (r5 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r3 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7') && (r3 == '7')) || ((r1 == '7') && (r2 == '7') && (r4 == '7')) ||
                 ((r1 == '7') && (r2 == '7') && (r5 == '7')) || ((r1 == '7') && (r3 == '7') && (r4 == '7')) || ((r1 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((r1 == '7') && (r4 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7') && (r4 == '7')) || ((r2 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((r2 == '7') && (r4 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7') && (r5 == '7')) )
            {
                gas[i].prio = 110; strcpy(gas[i].rink,"Trys vienodos (7)");
            }
            if ( ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r5 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r1 == '8') && (r5 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r2 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r4 == '8') && (r5 == '8')) || ((gas[i].reiksme2 == '8') && (r1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8') && (r3 == '8')) || ((gas[i].reiksme2 == '8') && (r1 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8') && (r5 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r3 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8') && (r3 == '8')) || ((r1 == '8') && (r2 == '8') && (r4 == '8')) ||
                 ((r1 == '8') && (r2 == '8') && (r5 == '8')) || ((r1 == '8') && (r3 == '8') && (r4 == '8')) || ((r1 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((r1 == '8') && (r4 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8') && (r4 == '8')) || ((r2 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((r2 == '8') && (r4 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8') && (r5 == '8')) )
            {
                gas[i].prio = 111; strcpy(gas[i].rink,"Trys vienodos (8)");
            }
            if ( ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r5 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r1 == '9') && (r5 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r2 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r4 == '9') && (r5 == '9')) || ((gas[i].reiksme2 == '9') && (r1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9') && (r3 == '9')) || ((gas[i].reiksme2 == '9') && (r1 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9') && (r5 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r3 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9') && (r3 == '9')) || ((r1 == '9') && (r2 == '9') && (r4 == '9')) ||
                 ((r1 == '9') && (r2 == '9') && (r5 == '9')) || ((r1 == '9') && (r3 == '9') && (r4 == '9')) || ((r1 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((r1 == '9') && (r4 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9') && (r4 == '9')) || ((r2 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((r2 == '9') && (r4 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9') && (r5 == '9')) )
            {
                gas[i].prio = 112; strcpy(gas[i].rink,"Trys vienodos (9)");
            }
            if ( ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r5 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r5 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T') && (r3 == 'T')) || ((r1 == 'T') && (r2 == 'T') && (r4 == 'T')) ||
                 ((r1 == 'T') && (r2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((r2 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((r2 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T') && (r5 == 'T')) )
            {
                gas[i].prio = 113; strcpy(gas[i].rink,"Trys vienodos (T)");
            }
            if ( ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r5 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r5 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J') && (r3 == 'J')) || ((r1 == 'J') && (r2 == 'J') && (r4 == 'J')) ||
                 ((r1 == 'J') && (r2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((r2 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((r2 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J') && (r5 == 'J')) )
            {
                gas[i].prio = 114; strcpy(gas[i].rink,"Trys vienodos (J)");
            }
            if ( ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) ||
                 ((r1 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((r2 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) )
            {
                gas[i].prio = 115; strcpy(gas[i].rink,"Trys vienodos (Q)");
            }
            if ( ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r5 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r5 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K') && (r3 == 'K')) || ((r1 == 'K') && (r2 == 'K') && (r4 == 'K')) ||
                 ((r1 == 'K') && (r2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((r2 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((r2 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K') && (r5 == 'K')) )
            {
                gas[i].prio = 116; strcpy(gas[i].rink,"Trys vienodos (K)");
            }
            if ( ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r5 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r5 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A') && (r3 == 'A')) || ((r1 == 'A') && (r2 == 'A') && (r4 == 'A')) ||
                 ((r1 == 'A') && (r2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((r2 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((r2 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A') && (r5 == 'A')) )
            {
                gas[i].prio = 117; strcpy(gas[i].rink,"Trys vienodos (A)");
            }
            if ( ((gas[i].reiksme1 == '2') || (gas[i].reiksme2 == '2') || (r1 == '2') || (r2 == '2') || (r3 == '2') || (r4 == '2') || (r5 == '2')) &&
                 ((gas[i].reiksme1 == '3') || (gas[i].reiksme2 == '3') || (r1 == '3') || (r2 == '3') || (r3 == '3') || (r4 == '3') || (r5 == '3')) &&
                 ((gas[i].reiksme1 == '4') || (gas[i].reiksme2 == '4') || (r1 == '4') || (r2 == '4') || (r3 == '4') || (r4 == '4') || (r5 == '4')) &&
                 ((gas[i].reiksme1 == '5') || (gas[i].reiksme2 == '5') || (r1 == '5') || (r2 == '5') || (r3 == '5') || (r4 == '5') || (r5 == '5')) &&
                 ((gas[i].reiksme1 == 'A') || (gas[i].reiksme2 == 'A') || (r1 == 'A') || (r2 == 'A') || (r3 == 'A') || (r4 == 'A') || (r5 == 'A')) )
            {
                gas[i].prio = 118; strcpy(gas[i].rink,"Tiesus (5-A)");
            }
            if ( ((gas[i].reiksme1 == '2') || (gas[i].reiksme2 == '2') || (r1 == '2') || (r2 == '2') || (r3 == '2') || (r4 == '2') || (r5 == '2')) &&
                 ((gas[i].reiksme1 == '3') || (gas[i].reiksme2 == '3') || (r1 == '3') || (r2 == '3') || (r3 == '3') || (r4 == '3') || (r5 == '3')) &&
                 ((gas[i].reiksme1 == '4') || (gas[i].reiksme2 == '4') || (r1 == '4') || (r2 == '4') || (r3 == '4') || (r4 == '4') || (r5 == '4')) &&
                 ((gas[i].reiksme1 == '5') || (gas[i].reiksme2 == '5') || (r1 == '5') || (r2 == '5') || (r3 == '5') || (r4 == '5') || (r5 == '5')) &&
                 ((gas[i].reiksme1 == '6') || (gas[i].reiksme2 == '6') || (r1 == '6') || (r2 == '6') || (r3 == '6') || (r4 == '6') || (r5 == '6')) )
            {
                gas[i].prio = 119; strcpy(gas[i].rink,"Tiesus (6-2)");
            }
            if ( ((gas[i].reiksme1 == '3') || (gas[i].reiksme2 == '3') || (r1 == '3') || (r2 == '3') || (r3 == '3') || (r4 == '3') || (r5 == '3')) &&
                 ((gas[i].reiksme1 == '4') || (gas[i].reiksme2 == '4') || (r1 == '4') || (r2 == '4') || (r3 == '4') || (r4 == '4') || (r5 == '4')) &&
                 ((gas[i].reiksme1 == '5') || (gas[i].reiksme2 == '5') || (r1 == '5') || (r2 == '5') || (r3 == '5') || (r4 == '5') || (r5 == '5')) &&
                 ((gas[i].reiksme1 == '6') || (gas[i].reiksme2 == '6') || (r1 == '6') || (r2 == '6') || (r3 == '6') || (r4 == '6') || (r5 == '6')) &&
                 ((gas[i].reiksme1 == '7') || (gas[i].reiksme2 == '7') || (r1 == '7') || (r2 == '7') || (r3 == '7') || (r4 == '7') || (r5 == '7')) )
            {
                gas[i].prio = 120; strcpy(gas[i].rink,"Tiesus (7-3)");
            }
            if ( ((gas[i].reiksme1 == '4') || (gas[i].reiksme2 == '4') || (r1 == '4') || (r2 == '4') || (r3 == '4') || (r4 == '4') || (r5 == '4')) &&
                 ((gas[i].reiksme1 == '5') || (gas[i].reiksme2 == '5') || (r1 == '5') || (r2 == '5') || (r3 == '5') || (r4 == '5') || (r5 == '5')) &&
                 ((gas[i].reiksme1 == '6') || (gas[i].reiksme2 == '6') || (r1 == '6') || (r2 == '6') || (r3 == '6') || (r4 == '6') || (r5 == '6')) &&
                 ((gas[i].reiksme1 == '7') || (gas[i].reiksme2 == '7') || (r1 == '7') || (r2 == '7') || (r3 == '7') || (r4 == '7') || (r5 == '7')) &&
                 ((gas[i].reiksme1 == '8') || (gas[i].reiksme2 == '8') || (r1 == '8') || (r2 == '8') || (r3 == '8') || (r4 == '8') || (r5 == '8')) )
            {
                gas[i].prio = 121; strcpy(gas[i].rink,"Tiesus (8-4)");
            }
            if ( ((gas[i].reiksme1 == '5') || (gas[i].reiksme2 == '5') || (r1 == '5') || (r2 == '5') || (r3 == '5') || (r4 == '5') || (r5 == '5')) &&
                 ((gas[i].reiksme1 == '6') || (gas[i].reiksme2 == '6') || (r1 == '6') || (r2 == '6') || (r3 == '6') || (r4 == '6') || (r5 == '6')) &&
                 ((gas[i].reiksme1 == '7') || (gas[i].reiksme2 == '7') || (r1 == '7') || (r2 == '7') || (r3 == '7') || (r4 == '7') || (r5 == '7')) &&
                 ((gas[i].reiksme1 == '8') || (gas[i].reiksme2 == '8') || (r1 == '8') || (r2 == '8') || (r3 == '8') || (r4 == '8') || (r5 == '8')) &&
                 ((gas[i].reiksme1 == '9') || (gas[i].reiksme2 == '9') || (r1 == '9') || (r2 == '9') || (r3 == '9') || (r4 == '9') || (r5 == '9')) )
            {
                gas[i].prio = 122; strcpy(gas[i].rink,"Tiesus (9-5)");
            }
            if ( ((gas[i].reiksme1 == '6') || (gas[i].reiksme2 == '6') || (r1 == '6') || (r2 == '6') || (r3 == '6') || (r4 == '6') || (r5 == '6')) &&
                 ((gas[i].reiksme1 == '7') || (gas[i].reiksme2 == '7') || (r1 == '7') || (r2 == '7') || (r3 == '7') || (r4 == '7') || (r5 == '7')) &&
                 ((gas[i].reiksme1 == '8') || (gas[i].reiksme2 == '8') || (r1 == '8') || (r2 == '8') || (r3 == '8') || (r4 == '8') || (r5 == '8')) &&
                 ((gas[i].reiksme1 == '9') || (gas[i].reiksme2 == '9') || (r1 == '9') || (r2 == '9') || (r3 == '9') || (r4 == '9') || (r5 == '9')) &&
                 ((gas[i].reiksme1 == 'T') || (gas[i].reiksme2 == 'T') || (r1 == 'T') || (r2 == 'T') || (r3 == 'T') || (r4 == 'T') || (r5 == 'T')) )
            {
                gas[i].prio = 123; strcpy(gas[i].rink,"Tiesus (T-6)");
            }
            if ( ((gas[i].reiksme1 == '7') || (gas[i].reiksme2 == '7') || (r1 == '7') || (r2 == '7') || (r3 == '7') || (r4 == '7') || (r5 == '7')) &&
                 ((gas[i].reiksme1 == '8') || (gas[i].reiksme2 == '8') || (r1 == '8') || (r2 == '8') || (r3 == '8') || (r4 == '8') || (r5 == '8')) &&
                 ((gas[i].reiksme1 == '9') || (gas[i].reiksme2 == '9') || (r1 == '9') || (r2 == '9') || (r3 == '9') || (r4 == '9') || (r5 == '9')) &&
                 ((gas[i].reiksme1 == 'T') || (gas[i].reiksme2 == 'T') || (r1 == 'T') || (r2 == 'T') || (r3 == 'T') || (r4 == 'T') || (r5 == 'T')) &&
                 ((gas[i].reiksme1 == 'J') || (gas[i].reiksme2 == 'J') || (r1 == 'J') || (r2 == 'J') || (r3 == 'J') || (r4 == 'J') || (r5 == 'J')) )
            {
                gas[i].prio = 124; strcpy(gas[i].rink,"Tiesus (J-7)");
            }
            if ( ((gas[i].reiksme1 == '8') || (gas[i].reiksme2 == '8') || (r1 == '8') || (r2 == '8') || (r3 == '8') || (r4 == '8') || (r5 == '8')) &&
                 ((gas[i].reiksme1 == '9') || (gas[i].reiksme2 == '9') || (r1 == '9') || (r2 == '9') || (r3 == '9') || (r4 == '9') || (r5 == '9')) &&
                 ((gas[i].reiksme1 == 'T') || (gas[i].reiksme2 == 'T') || (r1 == 'T') || (r2 == 'T') || (r3 == 'T') || (r4 == 'T') || (r5 == 'T')) &&
                 ((gas[i].reiksme1 == 'J') || (gas[i].reiksme2 == 'J') || (r1 == 'J') || (r2 == 'J') || (r3 == 'J') || (r4 == 'J') || (r5 == 'J')) &&
                 ((gas[i].reiksme1 == 'Q') || (gas[i].reiksme2 == 'Q') || (r1 == 'Q') || (r2 == 'Q') || (r3 == 'Q') || (r4 == 'Q') || (r5 == 'Q')) )
            {
                gas[i].prio = 125; strcpy(gas[i].rink,"Tiesus (Q-8)");
            }
            if ( ((gas[i].reiksme1 == '9') || (gas[i].reiksme2 == '9') || (r1 == '9') || (r2 == '9') || (r3 == '9') || (r4 == '9') || (r5 == '9')) &&
                 ((gas[i].reiksme1 == 'T') || (gas[i].reiksme2 == 'T') || (r1 == 'T') || (r2 == 'T') || (r3 == 'T') || (r4 == 'T') || (r5 == 'T')) &&
                 ((gas[i].reiksme1 == 'J') || (gas[i].reiksme2 == 'J') || (r1 == 'J') || (r2 == 'J') || (r3 == 'J') || (r4 == 'J') || (r5 == 'J')) &&
                 ((gas[i].reiksme1 == 'Q') || (gas[i].reiksme2 == 'Q') || (r1 == 'Q') || (r2 == 'Q') || (r3 == 'Q') || (r4 == 'Q') || (r5 == 'Q')) &&
                 ((gas[i].reiksme1 == 'K') || (gas[i].reiksme2 == 'K') || (r1 == 'K') || (r2 == 'K') || (r3 == 'K') || (r4 == 'K') || (r5 == 'K')) )
            {
                gas[i].prio = 126; strcpy(gas[i].rink,"Tiesus (K-9)");
            }
            if ( ((gas[i].reiksme1 == 'T') || (gas[i].reiksme2 == 'T') || (r1 == 'T') || (r2 == 'T') || (r3 == 'T') || (r4 == 'T') || (r5 == 'T')) &&
                 ((gas[i].reiksme1 == 'J') || (gas[i].reiksme2 == 'J') || (r1 == 'J') || (r2 == 'J') || (r3 == 'J') || (r4 == 'J') || (r5 == 'J')) &&
                 ((gas[i].reiksme1 == 'Q') || (gas[i].reiksme2 == 'Q') || (r1 == 'Q') || (r2 == 'Q') || (r3 == 'Q') || (r4 == 'Q') || (r5 == 'Q')) &&
                 ((gas[i].reiksme1 == 'K') || (gas[i].reiksme2 == 'K') || (r1 == 'K') || (r2 == 'K') || (r3 == 'K') || (r4 == 'K') || (r5 == 'K')) &&
                 ((gas[i].reiksme1 == 'A') || (gas[i].reiksme2 == 'A') || (r1 == 'A') || (r2 == 'A') || (r3 == 'A') || (r4 == 'A') || (r5 == 'A')) )
            {
                gas[i].prio = 127; strcpy(gas[i].rink,"Tiesus (A-T)");
            }
            if ( ((gas[i].reiksme1 == '7') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == '7') && (gas[i].tipas2 == 's')) ||
                 ((r1 == '7') && (t1 == 's')) || ((r2 == '7') && (t2 == 's')) || ((r3 == '7') && (t3 == 's')) ||
                 ((r4 == '7') && (t4 == 's')) || ((r5 == '7') && (t5 == 's')) )
            {
                se();
                if (ss >= 5)
                {
                    gas[i].prio = 128; strcpy(gas[i].rink,"Pakilimas - sirdziu (Auksciausia korta - 7)");
                }
            }
            if ( ((gas[i].reiksme1 == '7') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == '7') && (gas[i].tipas2 == 'b')) ||
                 ((r1 == '7') && (t1 == 'b')) || ((r2 == '7') && (t2 == 'b')) || ((r3 == '7') && (t3 == 'b')) ||
                 ((r4 == '7') && (t4 == 'b')) || ((r5 == '7') && (t5 == 'b')) )
            {
                be();
                if (bb >= 5)
                {
                    gas[i].prio = 128; strcpy(gas[i].rink,"Pakilimas - bugnu (Auksciausia korta - 7)");
                }
            }
            if ( ((gas[i].reiksme1 == '7') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == '7') && (gas[i].tipas2 == 'k')) ||
                 ((r1 == '7') && (t1 == 'k')) || ((r2 == '7') && (t2 == 'k')) || ((r3 == '7') && (t3 == 'k')) ||
                 ((r4 == '7') && (t4 == 'k')) || ((r5 == '7') && (t5 == 'k')) )
            {
                ke();
                if (kk >= 5)
                {
                    gas[i].prio = 128; strcpy(gas[i].rink,"Pakilimas - kryziu (Auksciausia korta - 7)");
                }
            }
            if ( ((gas[i].reiksme1 == '7') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == '7') && (gas[i].tipas2 == 'c')) ||
                 ((r1 == '7') && (t1 == 'c')) || ((r2 == '7') && (t2 == 'c')) || ((r3 == '7') && (t3 == 'c')) ||
                 ((r4 == '7') && (t4 == 'c')) || ((r5 == '7') && (t5 == 'c')) )
            {
                ce();
                if (cc >= 5)
                {
                    gas[i].prio = 128; strcpy(gas[i].rink,"Pakilimas - cirvu (Auksciausia korta - 7)");
                }
            }
            if ( ((gas[i].reiksme1 == '8') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == '8') && (gas[i].tipas2 == 's')) ||
                 ((r1 == '8') && (t1 == 's')) || ((r2 == '8') && (t2 == 's')) || ((r3 == '8') && (t3 == 's')) ||
                 ((r4 == '8') && (t4 == 's')) || ((r5 == '8') && (t5 == 's')) )
            {
                se();
                if (ss >= 5)
                {
                    gas[i].prio = 129; strcpy(gas[i].rink,"Pakilimas - sirdziu (Auksciausia korta - 8)");
                }
            }
            if ( ((gas[i].reiksme1 == '8') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == '8') && (gas[i].tipas2 == 'b')) ||
                 ((r1 == '8') && (t1 == 'b')) || ((r2 == '8') && (t2 == 'b')) || ((r3 == '8') && (t3 == 'b')) ||
                 ((r4 == '8') && (t4 == 'b')) || ((r5 == '8') && (t5 == 'b')) )
            {
                be();
                if (bb >= 5)
                {
                    gas[i].prio = 129; strcpy(gas[i].rink,"Pakilimas - bugnu (Auksciausia korta - 8)");
                }
            }
            if ( ((gas[i].reiksme1 == '8') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == '8') && (gas[i].tipas2 == 'k')) ||
                 ((r1 == '8') && (t1 == 'k')) || ((r2 == '8') && (t2 == 'k')) || ((r3 == '8') && (t3 == 'k')) ||
                 ((r4 == '8') && (t4 == 'k')) || ((r5 == '8') && (t5 == 'k')) )
            {
                ke();
                if (kk >= 5)
                {
                    gas[i].prio = 129; strcpy(gas[i].rink,"Pakilimas - kryziu (Auksciausia korta - 8)");
                }
            }
            if ( ((gas[i].reiksme1 == '8') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == '8') && (gas[i].tipas2 == 'c')) ||
                 ((r1 == '8') && (t1 == 'c')) || ((r2 == '8') && (t2 == 'c')) || ((r3 == '8') && (t3 == 'c')) ||
                 ((r4 == '8') && (t4 == 'c')) || ((r5 == '8') && (t5 == 'c')) )
            {
                ce();
                if (cc >= 5)
                {
                    gas[i].prio = 129; strcpy(gas[i].rink,"Pakilimas - cirvu (Auksciausia korta - 8)");
                }
            }
            if ( ((gas[i].reiksme1 == '9') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == '9') && (gas[i].tipas2 == 's')) ||
                 ((r1 == '9') && (t1 == 's')) || ((r2 == '9') && (t2 == 's')) || ((r3 == '9') && (t3 == 's')) ||
                 ((r4 == '9') && (t4 == 's')) || ((r5 == '9') && (t5 == 's')) )
            {
                se();
                if (ss >= 5)
                {
                    gas[i].prio = 130; strcpy(gas[i].rink,"Pakilimas - sirdziu (Auksciausia korta - 9)");
                }
            }
            if ( ((gas[i].reiksme1 == '9') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == '9') && (gas[i].tipas2 == 'b')) ||
                 ((r1 == '9') && (t1 == 'b')) || ((r2 == '9') && (t2 == 'b')) || ((r3 == '9') && (t3 == 'b')) ||
                 ((r4 == '9') && (t4 == 'b')) || ((r5 == '9') && (t5 == 'b')) )
            {
                be();
                if (bb >= 5)
                {
                    gas[i].prio = 130; strcpy(gas[i].rink,"Pakilimas - bugnu (Auksciausia korta - 9)");
                }
            }
            if ( ((gas[i].reiksme1 == '9') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == '9') && (gas[i].tipas2 == 'k')) ||
                 ((r1 == '9') && (t1 == 'k')) || ((r2 == '9') && (t2 == 'k')) || ((r3 == '9') && (t3 == 'k')) ||
                 ((r4 == '9') && (t4 == 'k')) || ((r5 == '9') && (t5 == 'k')) )
            {
                ke();
                if (kk >= 5)
                {
                    gas[i].prio = 130; strcpy(gas[i].rink,"Pakilimas - kryziu (Auksciausia korta - 9)");
                }
            }
            if ( ((gas[i].reiksme1 == '9') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == '9') && (gas[i].tipas2 == 'c')) ||
                 ((r1 == '9') && (t1 == 'c')) || ((r2 == '9') && (t2 == 'c')) || ((r3 == '9') && (t3 == 'c')) ||
                 ((r4 == '9') && (t4 == 'c')) || ((r5 == '9') && (t5 == 'c')) )
            {
                ce();
                if (cc >= 5)
                {
                    gas[i].prio = 130; strcpy(gas[i].rink,"Pakilimas - cirvu (Auksciausia korta - 9)");
                }
            }
            if ( ((gas[i].reiksme1 == 'T') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == 'T') && (gas[i].tipas2 == 's')) ||
                 ((r1 == 'T') && (t1 == 's')) || ((r2 == 'T') && (t2 == 's')) || ((r3 == 'T') && (t3 == 's')) ||
                 ((r4 == 'T') && (t4 == 's')) || ((r5 == 'T') && (t5 == 's')) )
            {
                se();
                if (ss >= 5)
                {
                    gas[i].prio = 131; strcpy(gas[i].rink,"Pakilimas - sirdziu (Auksciausia korta - T)");
                }
            }
            if ( ((gas[i].reiksme1 == 'T') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == 'T') && (gas[i].tipas2 == 'b')) ||
                 ((r1 == 'T') && (t1 == 'b')) || ((r2 == 'T') && (t2 == 'b')) || ((r3 == 'T') && (t3 == 'b')) ||
                 ((r4 == 'T') && (t4 == 'b')) || ((r5 == 'T') && (t5 == 'b')) )
            {
                be();
                if (bb >= 5)
                {
                    gas[i].prio = 131; strcpy(gas[i].rink,"Pakilimas - bugnu (Auksciausia korta - T)");
                }
            }
            if ( ((gas[i].reiksme1 == 'T') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == 'T') && (gas[i].tipas2 == 'k')) ||
                 ((r1 == 'T') && (t1 == 'k')) || ((r2 == 'T') && (t2 == 'k')) || ((r3 == 'T') && (t3 == 'k')) ||
                 ((r4 == 'T') && (t4 == 'k')) || ((r5 == 'T') && (t5 == 'k')) )
            {
                ke();
                if (kk >= 5)
                {
                    gas[i].prio = 131; strcpy(gas[i].rink,"Pakilimas - kryziu (Auksciausia korta - T)");
                }
            }
            if ( ((gas[i].reiksme1 == 'T') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == 'T') && (gas[i].tipas2 == 'c')) ||
                 ((r1 == 'T') && (t1 == 'c')) || ((r2 == 'T') && (t2 == 'c')) || ((r3 == 'T') && (t3 == 'c')) ||
                 ((r4 == 'T') && (t4 == 'c')) || ((r5 == 'T') && (t5 == 'c')) )
            {
                ce();
                if (cc >= 5)
                {
                    gas[i].prio = 131; strcpy(gas[i].rink,"Pakilimas - cirvu (Auksciausia korta - T)");
                }
            }
            if ( ((gas[i].reiksme1 == 'J') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == 'J') && (gas[i].tipas2 == 's')) ||
                 ((r1 == 'J') && (t1 == 's')) || ((r2 == 'J') && (t2 == 's')) || ((r3 == 'J') && (t3 == 's')) ||
                 ((r4 == 'J') && (t4 == 's')) || ((r5 == 'J') && (t5 == 's')) )
            {
                se();
                if (ss >= 5)
                {
                    gas[i].prio = 132; strcpy(gas[i].rink,"Pakilimas - sirdziu (Auksciausia korta - J)");
                }
            }
            if ( ((gas[i].reiksme1 == 'J') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == 'J') && (gas[i].tipas2 == 'b')) ||
                 ((r1 == 'J') && (t1 == 'b')) || ((r2 == 'J') && (t2 == 'b')) || ((r3 == 'J') && (t3 == 'b')) ||
                 ((r4 == 'J') && (t4 == 'b')) || ((r5 == 'J') && (t5 == 'b')) )
            {
                be();
                if (bb >= 5)
                {
                    gas[i].prio = 132; strcpy(gas[i].rink,"Pakilimas - bugnu (Auksciausia korta - J)");
                }
            }
            if ( ((gas[i].reiksme1 == 'J') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == 'J') && (gas[i].tipas2 == 'k')) ||
                 ((r1 == 'J') && (t1 == 'k')) || ((r2 == 'J') && (t2 == 'k')) || ((r3 == 'J') && (t3 == 'k')) ||
                 ((r4 == 'J') && (t4 == 'k')) || ((r5 == 'J') && (t5 == 'k')) )
            {
                ke();
                if (kk >= 5)
                {
                    gas[i].prio = 132; strcpy(gas[i].rink,"Pakilimas - kryziu (Auksciausia korta - J)");
                }
            }
            if ( ((gas[i].reiksme1 == 'J') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == 'J') && (gas[i].tipas2 == 'c')) ||
                 ((r1 == 'J') && (t1 == 'c')) || ((r2 == 'J') && (t2 == 'c')) || ((r3 == 'J') && (t3 == 'c')) ||
                 ((r4 == 'J') && (t4 == 'c')) || ((r5 == 'J') && (t5 == 'c')) )
            {
                ce();
                if (cc >= 5)
                {
                    gas[i].prio = 132; strcpy(gas[i].rink,"Pakilimas - cirvu (Auksciausia korta - J)");
                }
            }
            if ( ((gas[i].reiksme1 == 'Q') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == 'Q') && (gas[i].tipas2 == 's')) ||
                 ((r1 == 'Q') && (t1 == 's')) || ((r2 == 'Q') && (t2 == 's')) || ((r3 == 'Q') && (t3 == 's')) ||
                 ((r4 == 'Q') && (t4 == 's')) || ((r5 == 'Q') && (t5 == 's')) )
            {
                se();
                if (ss >= 5)
                {
                    gas[i].prio = 133; strcpy(gas[i].rink,"Pakilimas - sirdziu (Auksciausia korta - Q)");
                }
            }
            if ( ((gas[i].reiksme1 == 'Q') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == 'Q') && (gas[i].tipas2 == 'b')) ||
                 ((r1 == 'Q') && (t1 == 'b')) || ((r2 == 'Q') && (t2 == 'b')) || ((r3 == 'Q') && (t3 == 'b')) ||
                 ((r4 == 'Q') && (t4 == 'b')) || ((r5 == 'Q') && (t5 == 'b')) )
            {
                be();
                if (bb >= 5)
                {
                    gas[i].prio = 133; strcpy(gas[i].rink,"Pakilimas - bugnu (Auksciausia korta - Q)");
                }
            }
            if ( ((gas[i].reiksme1 == 'Q') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == 'Q') && (gas[i].tipas2 == 'k')) ||
                 ((r1 == 'Q') && (t1 == 'k')) || ((r2 == 'Q') && (t2 == 'k')) || ((r3 == 'Q') && (t3 == 'k')) ||
                 ((r4 == 'Q') && (t4 == 'k')) || ((r5 == 'Q') && (t5 == 'k')) )
            {
                ke();
                if (kk >= 5)
                {
                    gas[i].prio = 133; strcpy(gas[i].rink,"Pakilimas - kryziu (Auksciausia korta - Q)");
                }
            }
            if ( ((gas[i].reiksme1 == 'Q') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == 'Q') && (gas[i].tipas2 == 'c')) ||
                 ((r1 == 'Q') && (t1 == 'c')) || ((r2 == 'Q') && (t2 == 'c')) || ((r3 == 'Q') && (t3 == 'c')) ||
                 ((r4 == 'Q') && (t4 == 'c')) || ((r5 == 'Q') && (t5 == 'c')) )
            {
                ce();
                if (cc >= 5)
                {
                    gas[i].prio = 133; strcpy(gas[i].rink,"Pakilimas - cirvu (Auksciausia korta - Q)");
                }
            }
            if ( ((gas[i].reiksme1 == 'K') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == 'K') && (gas[i].tipas2 == 's')) ||
                 ((r1 == 'K') && (t1 == 's')) || ((r2 == 'K') && (t2 == 's')) || ((r3 == 'K') && (t3 == 's')) ||
                 ((r4 == 'K') && (t4 == 's')) || ((r5 == 'K') && (t5 == 's')) )
            {
                se();
                if (ss >= 5)
                {
                    gas[i].prio = 134; strcpy(gas[i].rink,"Pakilimas - sirdziu (Auksciausia korta - K)");
                }
            }
            if ( ((gas[i].reiksme1 == 'K') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == 'K') && (gas[i].tipas2 == 'b')) ||
                 ((r1 == 'K') && (t1 == 'b')) || ((r2 == 'K') && (t2 == 'b')) || ((r3 == 'K') && (t3 == 'b')) ||
                 ((r4 == 'K') && (t4 == 'b')) || ((r5 == 'K') && (t5 == 'b')) )
            {
                be();
                if (bb >= 5)
                {
                    gas[i].prio = 134; strcpy(gas[i].rink,"Pakilimas - bugnu (Auksciausia korta - K)");
                }
            }
            if ( ((gas[i].reiksme1 == 'K') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == 'K') && (gas[i].tipas2 == 'k')) ||
                 ((r1 == 'K') && (t1 == 'k')) || ((r2 == 'K') && (t2 == 'k')) || ((r3 == 'K') && (t3 == 'k')) ||
                 ((r4 == 'K') && (t4 == 'k')) || ((r5 == 'K') && (t5 == 'k')) )
            {
                ke();
                if (kk >= 5)
                {
                    gas[i].prio = 134; strcpy(gas[i].rink,"Pakilimas - kryziu (Auksciausia korta - K)");
                }
            }
            if ( ((gas[i].reiksme1 == 'K') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == 'K') && (gas[i].tipas2 == 'c')) ||
                 ((r1 == 'K') && (t1 == 'c')) || ((r2 == 'K') && (t2 == 'c')) || ((r3 == 'K') && (t3 == 'c')) ||
                 ((r4 == 'K') && (t4 == 'c')) || ((r5 == 'K') && (t5 == 'c')) )
            {
                ce();
                if (cc >= 5)
                {
                    gas[i].prio = 134; strcpy(gas[i].rink,"Pakilimas - cirvu (Auksciausia korta - K)");
                }
            }
            if ( ((gas[i].reiksme1 == 'A') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == 'A') && (gas[i].tipas2 == 's')) ||
                 ((r1 == 'A') && (t1 == 's')) || ((r2 == 'A') && (t2 == 's')) || ((r3 == 'A') && (t3 == 's')) ||
                 ((r4 == 'A') && (t4 == 's')) || ((r5 == 'A') && (t5 == 's')) )
            {
                se();
                if (ss >= 5)
                {
                    gas[i].prio = 135; strcpy(gas[i].rink,"Pakilimas - sirdziu (Auksciausia korta - A)");
                }
            }
            if ( ((gas[i].reiksme1 == 'A') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == 'A') && (gas[i].tipas2 == 'b')) ||
                 ((r1 == 'A') && (t1 == 'b')) || ((r2 == 'A') && (t2 == 'b')) || ((r3 == 'A') && (t3 == 'b')) ||
                 ((r4 == 'A') && (t4 == 'b')) || ((r5 == 'A') && (t5 == 'b')) )
            {
                be();
                if (bb >= 5)
                {
                    gas[i].prio = 135; strcpy(gas[i].rink,"Pakilimas - bugnu (Auksciausia korta - A)");
                }
            }
            if ( ((gas[i].reiksme1 == 'A') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == 'A') && (gas[i].tipas2 == 'k')) ||
                 ((r1 == 'A') && (t1 == 'k')) || ((r2 == 'k') && (t2 == 'k')) || ((r3 == 'A') && (t3 == 'k')) ||
                 ((r4 == 'A') && (t4 == 'k')) || ((r5 == 'k') && (t5 == 'k')) )
            {
                ke();
                if (kk >= 5)
                {
                    gas[i].prio = 135; strcpy(gas[i].rink,"Pakilimas - kryziu (Auksciausia korta - A)");
                }
            }
            if ( ((gas[i].reiksme1 == 'A') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == 'A') && (gas[i].tipas2 == 'c')) ||
                 ((r1 == 'A') && (t1 == 'c')) || ((r2 == 'A') && (t2 == 'c')) || ((r3 == 'A') && (t3 == 'c')) ||
                 ((r4 == 'A') && (t4 == 'c')) || ((r5 == 'A') && (t5 == 'c')) )
            {
                ce();
                if (cc >= 5)
                {
                    gas[i].prio = 135; strcpy(gas[i].rink,"Pakilimas - cirvu (Auksciausia korta - A)");
                }
            }
            if ( (((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r5 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r1 == '2') && (r5 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r2 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r4 == '2') && (r5 == '2')) || ((gas[i].reiksme2 == '2') && (r1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2') && (r3 == '2')) || ((gas[i].reiksme2 == '2') && (r1 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2') && (r5 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r3 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2') && (r3 == '2')) || ((r1 == '2') && (r2 == '2') && (r4 == '2')) ||
                 ((r1 == '2') && (r2 == '2') && (r5 == '2')) || ((r1 == '2') && (r3 == '2') && (r4 == '2')) || ((r1 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((r1 == '2') && (r4 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2') && (r4 == '2')) || ((r2 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((r2 == '2') && (r4 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2') && (r5 == '2'))) &&
                 (((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3')) || ((r1 == '3') && (r3 == '3')) ||
                 ((r1 == '3') && (r4 == '3')) || ((r1 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3')) || ((r2 == '3') && (r4 == '3')) ||
                 ((r2 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3')) || ((r3 == '3') && (r5 == '3')) || ((r4 == '3') && (r5 == '3'))) )
            {
                gas[i].prio = 136; strcpy(gas[i].rink,"Pilnas namas (2-3)");
            }
            if ( (((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r5 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r1 == '2') && (r5 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r2 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r4 == '2') && (r5 == '2')) || ((gas[i].reiksme2 == '2') && (r1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2') && (r3 == '2')) || ((gas[i].reiksme2 == '2') && (r1 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2') && (r5 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r3 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2') && (r3 == '2')) || ((r1 == '2') && (r2 == '2') && (r4 == '2')) ||
                 ((r1 == '2') && (r2 == '2') && (r5 == '2')) || ((r1 == '2') && (r3 == '2') && (r4 == '2')) || ((r1 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((r1 == '2') && (r4 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2') && (r4 == '2')) || ((r2 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((r2 == '2') && (r4 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2') && (r5 == '2'))) &&
                 (((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4')) || ((r1 == '4') && (r3 == '4')) ||
                 ((r1 == '4') && (r4 == '4')) || ((r1 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4')) || ((r2 == '4') && (r4 == '4')) ||
                 ((r2 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4')) || ((r3 == '4') && (r5 == '4')) || ((r4 == '4') && (r5 == '4'))) )
            {
                gas[i].prio = 137; strcpy(gas[i].rink,"Pilnas namas (2-4)");
            }
            if ( (((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r5 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r1 == '2') && (r5 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r2 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r4 == '2') && (r5 == '2')) || ((gas[i].reiksme2 == '2') && (r1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2') && (r3 == '2')) || ((gas[i].reiksme2 == '2') && (r1 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2') && (r5 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r3 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2') && (r3 == '2')) || ((r1 == '2') && (r2 == '2') && (r4 == '2')) ||
                 ((r1 == '2') && (r2 == '2') && (r5 == '2')) || ((r1 == '2') && (r3 == '2') && (r4 == '2')) || ((r1 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((r1 == '2') && (r4 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2') && (r4 == '2')) || ((r2 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((r2 == '2') && (r4 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2') && (r5 == '2'))) &&
                 (((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5')) || ((r1 == '5') && (r3 == '5')) ||
                 ((r1 == '5') && (r4 == '5')) || ((r1 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5')) || ((r2 == '5') && (r4 == '5')) ||
                 ((r2 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5')) || ((r3 == '5') && (r5 == '5')) || ((r4 == '5') && (r5 == '5'))) )
            {
                gas[i].prio = 138; strcpy(gas[i].rink,"Pilnas namas (2-5)");
            }
            if ( (((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r5 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r1 == '2') && (r5 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r2 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r4 == '2') && (r5 == '2')) || ((gas[i].reiksme2 == '2') && (r1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2') && (r3 == '2')) || ((gas[i].reiksme2 == '2') && (r1 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2') && (r5 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r3 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2') && (r3 == '2')) || ((r1 == '2') && (r2 == '2') && (r4 == '2')) ||
                 ((r1 == '2') && (r2 == '2') && (r5 == '2')) || ((r1 == '2') && (r3 == '2') && (r4 == '2')) || ((r1 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((r1 == '2') && (r4 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2') && (r4 == '2')) || ((r2 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((r2 == '2') && (r4 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2') && (r5 == '2'))) &&
                 (((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6')) || ((r1 == '6') && (r3 == '6')) ||
                 ((r1 == '6') && (r4 == '6')) || ((r1 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6')) || ((r2 == '6') && (r4 == '6')) ||
                 ((r2 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6')) || ((r3 == '6') && (r5 == '6')) || ((r4 == '6') && (r5 == '6'))) )
            {
                gas[i].prio = 139; strcpy(gas[i].rink,"Pilnas namas (2-6)");
            }
            if ( (((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r5 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r1 == '2') && (r5 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r2 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r4 == '2') && (r5 == '2')) || ((gas[i].reiksme2 == '2') && (r1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2') && (r3 == '2')) || ((gas[i].reiksme2 == '2') && (r1 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2') && (r5 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r3 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2') && (r3 == '2')) || ((r1 == '2') && (r2 == '2') && (r4 == '2')) ||
                 ((r1 == '2') && (r2 == '2') && (r5 == '2')) || ((r1 == '2') && (r3 == '2') && (r4 == '2')) || ((r1 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((r1 == '2') && (r4 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2') && (r4 == '2')) || ((r2 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((r2 == '2') && (r4 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2') && (r5 == '2'))) &&
                 (((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7')) || ((r1 == '7') && (r3 == '7')) ||
                 ((r1 == '7') && (r4 == '7')) || ((r1 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7')) || ((r2 == '7') && (r4 == '7')) ||
                 ((r2 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7')) || ((r3 == '7') && (r5 == '7')) || ((r4 == '7') && (r5 == '7'))) )
            {
                gas[i].prio = 140; strcpy(gas[i].rink,"Pilnas namas (2-7)");
            }
            if ( (((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r5 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r1 == '2') && (r5 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r2 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r4 == '2') && (r5 == '2')) || ((gas[i].reiksme2 == '2') && (r1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2') && (r3 == '2')) || ((gas[i].reiksme2 == '2') && (r1 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2') && (r5 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r3 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2') && (r3 == '2')) || ((r1 == '2') && (r2 == '2') && (r4 == '2')) ||
                 ((r1 == '2') && (r2 == '2') && (r5 == '2')) || ((r1 == '2') && (r3 == '2') && (r4 == '2')) || ((r1 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((r1 == '2') && (r4 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2') && (r4 == '2')) || ((r2 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((r2 == '2') && (r4 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2') && (r5 == '2'))) &&
                 (((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8')) || ((r1 == '8') && (r3 == '8')) ||
                 ((r1 == '8') && (r4 == '8')) || ((r1 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8')) || ((r2 == '8') && (r4 == '8')) ||
                 ((r2 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8')) || ((r3 == '8') && (r5 == '8')) || ((r4 == '8') && (r5 == '8'))) )
            {
                gas[i].prio = 141; strcpy(gas[i].rink,"Pilnas namas (2-8)");
            }
            if ( (((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r5 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r1 == '2') && (r5 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r2 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r4 == '2') && (r5 == '2')) || ((gas[i].reiksme2 == '2') && (r1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2') && (r3 == '2')) || ((gas[i].reiksme2 == '2') && (r1 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2') && (r5 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r3 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2') && (r3 == '2')) || ((r1 == '2') && (r2 == '2') && (r4 == '2')) ||
                 ((r1 == '2') && (r2 == '2') && (r5 == '2')) || ((r1 == '2') && (r3 == '2') && (r4 == '2')) || ((r1 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((r1 == '2') && (r4 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2') && (r4 == '2')) || ((r2 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((r2 == '2') && (r4 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2') && (r5 == '2'))) &&
                 (((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9')) || ((r1 == '9') && (r3 == '9')) ||
                 ((r1 == '9') && (r4 == '9')) || ((r1 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9')) || ((r2 == '9') && (r4 == '9')) ||
                 ((r2 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9')) || ((r3 == '9') && (r5 == '9')) || ((r4 == '9') && (r5 == '9'))) )
            {
                gas[i].prio = 142; strcpy(gas[i].rink,"Pilnas namas (2-9)");
            }
            if ( (((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r5 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r1 == '2') && (r5 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r2 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r4 == '2') && (r5 == '2')) || ((gas[i].reiksme2 == '2') && (r1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2') && (r3 == '2')) || ((gas[i].reiksme2 == '2') && (r1 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2') && (r5 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r3 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2') && (r3 == '2')) || ((r1 == '2') && (r2 == '2') && (r4 == '2')) ||
                 ((r1 == '2') && (r2 == '2') && (r5 == '2')) || ((r1 == '2') && (r3 == '2') && (r4 == '2')) || ((r1 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((r1 == '2') && (r4 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2') && (r4 == '2')) || ((r2 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((r2 == '2') && (r4 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2') && (r5 == '2'))) &&
                 (((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T')) || ((r1 == 'T') && (r3 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T')) || ((r2 == 'T') && (r4 == 'T')) ||
                 ((r2 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T')) || ((r3 == 'T') && (r5 == 'T')) || ((r4 == 'T') && (r5 == 'T'))) )
            {
                gas[i].prio = 143; strcpy(gas[i].rink,"Pilnas namas (2-T)");
            }
            if ( (((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r5 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r1 == '2') && (r5 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r2 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r4 == '2') && (r5 == '2')) || ((gas[i].reiksme2 == '2') && (r1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2') && (r3 == '2')) || ((gas[i].reiksme2 == '2') && (r1 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2') && (r5 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r3 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2') && (r3 == '2')) || ((r1 == '2') && (r2 == '2') && (r4 == '2')) ||
                 ((r1 == '2') && (r2 == '2') && (r5 == '2')) || ((r1 == '2') && (r3 == '2') && (r4 == '2')) || ((r1 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((r1 == '2') && (r4 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2') && (r4 == '2')) || ((r2 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((r2 == '2') && (r4 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2') && (r5 == '2'))) &&
                 (((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J')) || ((r1 == 'J') && (r3 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J')) || ((r2 == 'J') && (r4 == 'J')) ||
                 ((r2 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J')) || ((r3 == 'J') && (r5 == 'J')) || ((r4 == 'J') && (r5 == 'J'))) )
            {
                gas[i].prio = 144; strcpy(gas[i].rink,"Pilnas namas (2-J)");
            }
            if ( (((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r5 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r1 == '2') && (r5 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r2 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r4 == '2') && (r5 == '2')) || ((gas[i].reiksme2 == '2') && (r1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2') && (r3 == '2')) || ((gas[i].reiksme2 == '2') && (r1 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2') && (r5 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r3 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2') && (r3 == '2')) || ((r1 == '2') && (r2 == '2') && (r4 == '2')) ||
                 ((r1 == '2') && (r2 == '2') && (r5 == '2')) || ((r1 == '2') && (r3 == '2') && (r4 == '2')) || ((r1 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((r1 == '2') && (r4 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2') && (r4 == '2')) || ((r2 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((r2 == '2') && (r4 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2') && (r5 == '2'))) &&
                 (((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q')) || ((r2 == 'Q') && (r4 == 'Q')) ||
                 ((r2 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q')) || ((r3 == 'Q') && (r5 == 'Q')) || ((r4 == 'Q') && (r5 == 'Q'))) )
            {
                gas[i].prio = 145; strcpy(gas[i].rink,"Pilnas namas (2-Q)");
            }
            if ( (((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r5 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r1 == '2') && (r5 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r2 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r4 == '2') && (r5 == '2')) || ((gas[i].reiksme2 == '2') && (r1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2') && (r3 == '2')) || ((gas[i].reiksme2 == '2') && (r1 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2') && (r5 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r3 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2') && (r3 == '2')) || ((r1 == '2') && (r2 == '2') && (r4 == '2')) ||
                 ((r1 == '2') && (r2 == '2') && (r5 == '2')) || ((r1 == '2') && (r3 == '2') && (r4 == '2')) || ((r1 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((r1 == '2') && (r4 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2') && (r4 == '2')) || ((r2 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((r2 == '2') && (r4 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2') && (r5 == '2'))) &&
                 (((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K')) || ((r1 == 'K') && (r3 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K')) || ((r2 == 'K') && (r4 == 'K')) ||
                 ((r2 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K')) || ((r3 == 'K') && (r5 == 'K')) || ((r4 == 'K') && (r5 == 'K'))) )
            {
                gas[i].prio = 146; strcpy(gas[i].rink,"Pilnas namas (2-K)");
            }
            if ( (((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2') && (r5 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r1 == '2') && (r5 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r2 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r4 == '2') && (r5 == '2')) || ((gas[i].reiksme2 == '2') && (r1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2') && (r3 == '2')) || ((gas[i].reiksme2 == '2') && (r1 == '2') && (r4 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2') && (r5 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r3 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2') && (r3 == '2')) || ((r1 == '2') && (r2 == '2') && (r4 == '2')) ||
                 ((r1 == '2') && (r2 == '2') && (r5 == '2')) || ((r1 == '2') && (r3 == '2') && (r4 == '2')) || ((r1 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((r1 == '2') && (r4 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2') && (r4 == '2')) || ((r2 == '2') && (r3 == '2') && (r5 == '2')) ||
                 ((r2 == '2') && (r4 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2') && (r5 == '2'))) &&
                 (((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A')) || ((r1 == 'A') && (r3 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A')) || ((r2 == 'A') && (r4 == 'A')) ||
                 ((r2 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A')) || ((r3 == 'A') && (r5 == 'A')) || ((r4 == 'A') && (r5 == 'A'))) )
            {
                gas[i].prio = 147; strcpy(gas[i].rink,"Pilnas namas (2-A)");
            }
            if ( (((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r5 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r1 == '3') && (r5 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r2 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r4 == '3') && (r5 == '3')) || ((gas[i].reiksme2 == '3') && (r1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3') && (r3 == '3')) || ((gas[i].reiksme2 == '3') && (r1 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3') && (r5 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r3 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3') && (r3 == '3')) || ((r1 == '3') && (r2 == '3') && (r4 == '3')) ||
                 ((r1 == '3') && (r2 == '3') && (r5 == '3')) || ((r1 == '3') && (r3 == '3') && (r4 == '3')) || ((r1 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((r1 == '3') && (r4 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3') && (r4 == '3')) || ((r2 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((r2 == '3') && (r4 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3') && (r5 == '3'))) &&
                 (((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2')) || ((r1 == '2') && (r3 == '2')) ||
                 ((r1 == '2') && (r4 == '2')) || ((r1 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2')) || ((r2 == '2') && (r4 == '2')) ||
                 ((r2 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2')) || ((r3 == '2') && (r5 == '2')) || ((r4 == '2') && (r5 == '2'))) )
            {
                gas[i].prio = 148; strcpy(gas[i].rink,"Pilnas namas (3-2)");
            }
            if ( (((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r5 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r1 == '3') && (r5 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r2 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r4 == '3') && (r5 == '3')) || ((gas[i].reiksme2 == '3') && (r1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3') && (r3 == '3')) || ((gas[i].reiksme2 == '3') && (r1 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3') && (r5 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r3 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3') && (r3 == '3')) || ((r1 == '3') && (r2 == '3') && (r4 == '3')) ||
                 ((r1 == '3') && (r2 == '3') && (r5 == '3')) || ((r1 == '3') && (r3 == '3') && (r4 == '3')) || ((r1 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((r1 == '3') && (r4 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3') && (r4 == '3')) || ((r2 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((r2 == '3') && (r4 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3') && (r5 == '3'))) &&
                 (((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4')) || ((r1 == '4') && (r3 == '4')) ||
                 ((r1 == '4') && (r4 == '4')) || ((r1 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4')) || ((r2 == '4') && (r4 == '4')) ||
                 ((r2 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4')) || ((r3 == '4') && (r5 == '4')) || ((r4 == '4') && (r5 == '4'))) )
            {
                gas[i].prio = 149; strcpy(gas[i].rink,"Pilnas namas (3-4)");
            }
            if ( (((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r5 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r1 == '3') && (r5 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r2 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r4 == '3') && (r5 == '3')) || ((gas[i].reiksme2 == '3') && (r1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3') && (r3 == '3')) || ((gas[i].reiksme2 == '3') && (r1 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3') && (r5 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r3 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3') && (r3 == '3')) || ((r1 == '3') && (r2 == '3') && (r4 == '3')) ||
                 ((r1 == '3') && (r2 == '3') && (r5 == '3')) || ((r1 == '3') && (r3 == '3') && (r4 == '3')) || ((r1 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((r1 == '3') && (r4 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3') && (r4 == '3')) || ((r2 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((r2 == '3') && (r4 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3') && (r5 == '3'))) &&
                 (((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5')) || ((r1 == '5') && (r3 == '5')) ||
                 ((r1 == '5') && (r4 == '5')) || ((r1 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5')) || ((r2 == '5') && (r4 == '5')) ||
                 ((r2 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5')) || ((r3 == '5') && (r5 == '5')) || ((r4 == '5') && (r5 == '5'))) )
            {
                gas[i].prio = 150; strcpy(gas[i].rink,"Pilnas namas (3-5)");
            }
            if ( (((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r5 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r1 == '3') && (r5 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r2 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r4 == '3') && (r5 == '3')) || ((gas[i].reiksme2 == '3') && (r1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3') && (r3 == '3')) || ((gas[i].reiksme2 == '3') && (r1 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3') && (r5 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r3 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3') && (r3 == '3')) || ((r1 == '3') && (r2 == '3') && (r4 == '3')) ||
                 ((r1 == '3') && (r2 == '3') && (r5 == '3')) || ((r1 == '3') && (r3 == '3') && (r4 == '3')) || ((r1 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((r1 == '3') && (r4 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3') && (r4 == '3')) || ((r2 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((r2 == '3') && (r4 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3') && (r5 == '3'))) &&
                 (((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6')) || ((r1 == '6') && (r3 == '6')) ||
                 ((r1 == '6') && (r4 == '6')) || ((r1 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6')) || ((r2 == '6') && (r4 == '6')) ||
                 ((r2 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6')) || ((r3 == '6') && (r5 == '6')) || ((r4 == '6') && (r5 == '6'))) )
            {
                gas[i].prio = 151; strcpy(gas[i].rink,"Pilnas namas (3-6)");
            }
            if ( (((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r5 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r1 == '3') && (r5 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r2 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r4 == '3') && (r5 == '3')) || ((gas[i].reiksme2 == '3') && (r1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3') && (r3 == '3')) || ((gas[i].reiksme2 == '3') && (r1 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3') && (r5 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r3 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3') && (r3 == '3')) || ((r1 == '3') && (r2 == '3') && (r4 == '3')) ||
                 ((r1 == '3') && (r2 == '3') && (r5 == '3')) || ((r1 == '3') && (r3 == '3') && (r4 == '3')) || ((r1 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((r1 == '3') && (r4 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3') && (r4 == '3')) || ((r2 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((r2 == '3') && (r4 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3') && (r5 == '3'))) &&
                 (((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7')) || ((r1 == '7') && (r3 == '7')) ||
                 ((r1 == '7') && (r4 == '7')) || ((r1 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7')) || ((r2 == '7') && (r4 == '7')) ||
                 ((r2 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7')) || ((r3 == '7') && (r5 == '7')) || ((r4 == '7') && (r5 == '7'))) )
            {
                gas[i].prio = 152; strcpy(gas[i].rink,"Pilnas namas (3-7)");
            }
            if ( (((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r5 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r1 == '3') && (r5 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r2 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r4 == '3') && (r5 == '3')) || ((gas[i].reiksme2 == '3') && (r1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3') && (r3 == '3')) || ((gas[i].reiksme2 == '3') && (r1 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3') && (r5 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r3 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3') && (r3 == '3')) || ((r1 == '3') && (r2 == '3') && (r4 == '3')) ||
                 ((r1 == '3') && (r2 == '3') && (r5 == '3')) || ((r1 == '3') && (r3 == '3') && (r4 == '3')) || ((r1 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((r1 == '3') && (r4 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3') && (r4 == '3')) || ((r2 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((r2 == '3') && (r4 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3') && (r5 == '3'))) &&
                 (((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8')) || ((r1 == '8') && (r3 == '8')) ||
                 ((r1 == '8') && (r4 == '8')) || ((r1 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8')) || ((r2 == '8') && (r4 == '8')) ||
                 ((r2 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8')) || ((r3 == '8') && (r5 == '8')) || ((r4 == '8') && (r5 == '8'))) )
            {
                gas[i].prio = 153; strcpy(gas[i].rink,"Pilnas namas (3-8)");
            }
            if ( (((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r5 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r1 == '3') && (r5 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r2 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r4 == '3') && (r5 == '3')) || ((gas[i].reiksme2 == '3') && (r1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3') && (r3 == '3')) || ((gas[i].reiksme2 == '3') && (r1 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3') && (r5 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r3 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3') && (r3 == '3')) || ((r1 == '3') && (r2 == '3') && (r4 == '3')) ||
                 ((r1 == '3') && (r2 == '3') && (r5 == '3')) || ((r1 == '3') && (r3 == '3') && (r4 == '3')) || ((r1 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((r1 == '3') && (r4 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3') && (r4 == '3')) || ((r2 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((r2 == '3') && (r4 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3') && (r5 == '3'))) &&
                 (((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9')) || ((r1 == '9') && (r3 == '9')) ||
                 ((r1 == '9') && (r4 == '9')) || ((r1 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9')) || ((r2 == '9') && (r4 == '9')) ||
                 ((r2 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9')) || ((r3 == '9') && (r5 == '9')) || ((r4 == '9') && (r5 == '9'))) )
            {
                gas[i].prio = 154; strcpy(gas[i].rink,"Pilnas namas (3-9)");
            }
            if ( (((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r5 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r1 == '3') && (r5 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r2 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r4 == '3') && (r5 == '3')) || ((gas[i].reiksme2 == '3') && (r1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3') && (r3 == '3')) || ((gas[i].reiksme2 == '3') && (r1 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3') && (r5 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r3 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3') && (r3 == '3')) || ((r1 == '3') && (r2 == '3') && (r4 == '3')) ||
                 ((r1 == '3') && (r2 == '3') && (r5 == '3')) || ((r1 == '3') && (r3 == '3') && (r4 == '3')) || ((r1 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((r1 == '3') && (r4 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3') && (r4 == '3')) || ((r2 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((r2 == '3') && (r4 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3') && (r5 == '3'))) &&
                 (((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T')) || ((r1 == 'T') && (r3 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T')) || ((r2 == 'T') && (r4 == 'T')) ||
                 ((r2 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T')) || ((r3 == 'T') && (r5 == 'T')) || ((r4 == 'T') && (r5 == 'T'))) )
            {
                gas[i].prio = 155; strcpy(gas[i].rink,"Pilnas namas (3-T)");
            }
            if ( (((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r5 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r1 == '3') && (r5 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r2 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r4 == '3') && (r5 == '3')) || ((gas[i].reiksme2 == '3') && (r1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3') && (r3 == '3')) || ((gas[i].reiksme2 == '3') && (r1 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3') && (r5 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r3 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3') && (r3 == '3')) || ((r1 == '3') && (r2 == '3') && (r4 == '3')) ||
                 ((r1 == '3') && (r2 == '3') && (r5 == '3')) || ((r1 == '3') && (r3 == '3') && (r4 == '3')) || ((r1 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((r1 == '3') && (r4 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3') && (r4 == '3')) || ((r2 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((r2 == '3') && (r4 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3') && (r5 == '3'))) &&
                 (((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J')) || ((r1 == 'J') && (r3 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J')) || ((r2 == 'J') && (r4 == 'J')) ||
                 ((r2 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J')) || ((r3 == 'J') && (r5 == 'J')) || ((r4 == 'J') && (r5 == 'J'))) )
            {
                gas[i].prio = 156; strcpy(gas[i].rink,"Pilnas namas (3-J)");
            }
            if ( (((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r5 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r1 == '3') && (r5 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r2 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r4 == '3') && (r5 == '3')) || ((gas[i].reiksme2 == '3') && (r1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3') && (r3 == '3')) || ((gas[i].reiksme2 == '3') && (r1 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3') && (r5 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r3 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3') && (r3 == '3')) || ((r1 == '3') && (r2 == '3') && (r4 == '3')) ||
                 ((r1 == '3') && (r2 == '3') && (r5 == '3')) || ((r1 == '3') && (r3 == '3') && (r4 == '3')) || ((r1 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((r1 == '3') && (r4 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3') && (r4 == '3')) || ((r2 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((r2 == '3') && (r4 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3') && (r5 == '3'))) &&
                 (((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q')) || ((r2 == 'Q') && (r4 == 'Q')) ||
                 ((r2 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q')) || ((r3 == 'Q') && (r5 == 'Q')) || ((r4 == 'Q') && (r5 == 'Q'))) )
            {
                gas[i].prio = 157; strcpy(gas[i].rink,"Pilnas namas (3-Q)");
            }
            if ( (((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r5 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r1 == '3') && (r5 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r2 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r4 == '3') && (r5 == '3')) || ((gas[i].reiksme2 == '3') && (r1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3') && (r3 == '3')) || ((gas[i].reiksme2 == '3') && (r1 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3') && (r5 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r3 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3') && (r3 == '3')) || ((r1 == '3') && (r2 == '3') && (r4 == '3')) ||
                 ((r1 == '3') && (r2 == '3') && (r5 == '3')) || ((r1 == '3') && (r3 == '3') && (r4 == '3')) || ((r1 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((r1 == '3') && (r4 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3') && (r4 == '3')) || ((r2 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((r2 == '3') && (r4 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3') && (r5 == '3'))) &&
                 (((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K')) || ((r1 == 'K') && (r3 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K')) || ((r2 == 'K') && (r4 == 'K')) ||
                 ((r2 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K')) || ((r3 == 'K') && (r5 == 'K')) || ((r4 == 'K') && (r5 == 'K'))) )
            {
                gas[i].prio = 158; strcpy(gas[i].rink,"Pilnas namas (3-K)");
            }
            if ( (((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3') && (r5 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r1 == '3') && (r5 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r2 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r4 == '3') && (r5 == '3')) || ((gas[i].reiksme2 == '3') && (r1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3') && (r3 == '3')) || ((gas[i].reiksme2 == '3') && (r1 == '3') && (r4 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3') && (r5 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r3 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3') && (r3 == '3')) || ((r1 == '3') && (r2 == '3') && (r4 == '3')) ||
                 ((r1 == '3') && (r2 == '3') && (r5 == '3')) || ((r1 == '3') && (r3 == '3') && (r4 == '3')) || ((r1 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((r1 == '3') && (r4 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3') && (r4 == '3')) || ((r2 == '3') && (r3 == '3') && (r5 == '3')) ||
                 ((r2 == '3') && (r4 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3') && (r5 == '3'))) &&
                 (((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A')) || ((r1 == 'A') && (r3 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A')) || ((r2 == 'A') && (r4 == 'A')) ||
                 ((r2 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A')) || ((r3 == 'A') && (r5 == 'A')) || ((r4 == 'A') && (r5 == 'A'))) )
            {
                gas[i].prio = 159; strcpy(gas[i].rink,"Pilnas namas (3-A)");
            }
            if ( (((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r5 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r1 == '4') && (r5 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r2 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r4 == '4') && (r5 == '4')) || ((gas[i].reiksme2 == '4') && (r1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4') && (r3 == '4')) || ((gas[i].reiksme2 == '4') && (r1 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4') && (r5 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r3 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4') && (r3 == '4')) || ((r1 == '4') && (r2 == '4') && (r4 == '4')) ||
                 ((r1 == '4') && (r2 == '4') && (r5 == '4')) || ((r1 == '4') && (r3 == '4') && (r4 == '4')) || ((r1 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((r1 == '4') && (r4 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4') && (r4 == '4')) || ((r2 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((r2 == '4') && (r4 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4') && (r5 == '4'))) &&
                 (((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2')) || ((r1 == '2') && (r3 == '2')) ||
                 ((r1 == '2') && (r4 == '2')) || ((r1 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2')) || ((r2 == '2') && (r4 == '2')) ||
                 ((r2 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2')) || ((r3 == '2') && (r5 == '2')) || ((r4 == '2') && (r5 == '2'))) )
            {
                gas[i].prio = 160; strcpy(gas[i].rink,"Pilnas namas (4-2)");
            }
            if ( (((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r5 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r1 == '4') && (r5 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r2 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r4 == '4') && (r5 == '4')) || ((gas[i].reiksme2 == '4') && (r1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4') && (r3 == '4')) || ((gas[i].reiksme2 == '4') && (r1 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4') && (r5 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r3 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4') && (r3 == '4')) || ((r1 == '4') && (r2 == '4') && (r4 == '4')) ||
                 ((r1 == '4') && (r2 == '4') && (r5 == '4')) || ((r1 == '4') && (r3 == '4') && (r4 == '4')) || ((r1 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((r1 == '4') && (r4 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4') && (r4 == '4')) || ((r2 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((r2 == '4') && (r4 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4') && (r5 == '4'))) &&
                 (((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3')) || ((r1 == '3') && (r3 == '3')) ||
                 ((r1 == '3') && (r4 == '3')) || ((r1 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3')) || ((r2 == '3') && (r4 == '3')) ||
                 ((r2 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3')) || ((r3 == '3') && (r5 == '3')) || ((r4 == '3') && (r5 == '3'))) )
            {
                gas[i].prio = 161; strcpy(gas[i].rink,"Pilnas namas (4-3)");
            }
            if ( (((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r5 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r1 == '4') && (r5 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r2 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r4 == '4') && (r5 == '4')) || ((gas[i].reiksme2 == '4') && (r1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4') && (r3 == '4')) || ((gas[i].reiksme2 == '4') && (r1 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4') && (r5 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r3 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4') && (r3 == '4')) || ((r1 == '4') && (r2 == '4') && (r4 == '4')) ||
                 ((r1 == '4') && (r2 == '4') && (r5 == '4')) || ((r1 == '4') && (r3 == '4') && (r4 == '4')) || ((r1 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((r1 == '4') && (r4 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4') && (r4 == '4')) || ((r2 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((r2 == '4') && (r4 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4') && (r5 == '4'))) &&
                 (((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5')) || ((r1 == '5') && (r3 == '5')) ||
                 ((r1 == '5') && (r4 == '5')) || ((r1 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5')) || ((r2 == '5') && (r4 == '5')) ||
                 ((r2 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5')) || ((r3 == '5') && (r5 == '5')) || ((r4 == '5') && (r5 == '5'))) )
            {
                gas[i].prio = 162; strcpy(gas[i].rink,"Pilnas namas (4-5)");
            }
            if ( (((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r5 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r1 == '4') && (r5 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r2 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r4 == '4') && (r5 == '4')) || ((gas[i].reiksme2 == '4') && (r1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4') && (r3 == '4')) || ((gas[i].reiksme2 == '4') && (r1 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4') && (r5 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r3 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4') && (r3 == '4')) || ((r1 == '4') && (r2 == '4') && (r4 == '4')) ||
                 ((r1 == '4') && (r2 == '4') && (r5 == '4')) || ((r1 == '4') && (r3 == '4') && (r4 == '4')) || ((r1 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((r1 == '4') && (r4 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4') && (r4 == '4')) || ((r2 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((r2 == '4') && (r4 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4') && (r5 == '4'))) &&
                 (((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6')) || ((r1 == '6') && (r3 == '6')) ||
                 ((r1 == '6') && (r4 == '6')) || ((r1 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6')) || ((r2 == '6') && (r4 == '6')) ||
                 ((r2 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6')) || ((r3 == '6') && (r5 == '6')) || ((r4 == '6') && (r5 == '6'))) )
            {
                gas[i].prio = 163; strcpy(gas[i].rink,"Pilnas namas (4-6)");
            }
            if ( (((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r5 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r1 == '4') && (r5 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r2 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r4 == '4') && (r5 == '4')) || ((gas[i].reiksme2 == '4') && (r1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4') && (r3 == '4')) || ((gas[i].reiksme2 == '4') && (r1 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4') && (r5 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r3 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4') && (r3 == '4')) || ((r1 == '4') && (r2 == '4') && (r4 == '4')) ||
                 ((r1 == '4') && (r2 == '4') && (r5 == '4')) || ((r1 == '4') && (r3 == '4') && (r4 == '4')) || ((r1 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((r1 == '4') && (r4 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4') && (r4 == '4')) || ((r2 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((r2 == '4') && (r4 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4') && (r5 == '4'))) &&
                 (((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7')) || ((r1 == '7') && (r3 == '7')) ||
                 ((r1 == '7') && (r4 == '7')) || ((r1 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7')) || ((r2 == '7') && (r4 == '7')) ||
                 ((r2 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7')) || ((r3 == '7') && (r5 == '7')) || ((r4 == '7') && (r5 == '7'))) )
            {
                gas[i].prio = 164; strcpy(gas[i].rink,"Pilnas namas (4-7)");
            }
            if ( (((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r5 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r1 == '4') && (r5 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r2 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r4 == '4') && (r5 == '4')) || ((gas[i].reiksme2 == '4') && (r1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4') && (r3 == '4')) || ((gas[i].reiksme2 == '4') && (r1 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4') && (r5 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r3 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4') && (r3 == '4')) || ((r1 == '4') && (r2 == '4') && (r4 == '4')) ||
                 ((r1 == '4') && (r2 == '4') && (r5 == '4')) || ((r1 == '4') && (r3 == '4') && (r4 == '4')) || ((r1 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((r1 == '4') && (r4 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4') && (r4 == '4')) || ((r2 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((r2 == '4') && (r4 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4') && (r5 == '4'))) &&
                 (((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8')) || ((r1 == '8') && (r3 == '8')) ||
                 ((r1 == '8') && (r4 == '8')) || ((r1 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8')) || ((r2 == '8') && (r4 == '8')) ||
                 ((r2 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8')) || ((r3 == '8') && (r5 == '8')) || ((r4 == '8') && (r5 == '8'))) )
            {
                gas[i].prio = 165; strcpy(gas[i].rink,"Pilnas namas (4-8)");
            }
            if ( (((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r5 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r1 == '4') && (r5 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r2 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r4 == '4') && (r5 == '4')) || ((gas[i].reiksme2 == '4') && (r1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4') && (r3 == '4')) || ((gas[i].reiksme2 == '4') && (r1 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4') && (r5 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r3 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4') && (r3 == '4')) || ((r1 == '4') && (r2 == '4') && (r4 == '4')) ||
                 ((r1 == '4') && (r2 == '4') && (r5 == '4')) || ((r1 == '4') && (r3 == '4') && (r4 == '4')) || ((r1 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((r1 == '4') && (r4 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4') && (r4 == '4')) || ((r2 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((r2 == '4') && (r4 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4') && (r5 == '4'))) &&
                 (((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9')) || ((r1 == '9') && (r3 == '9')) ||
                 ((r1 == '9') && (r4 == '9')) || ((r1 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9')) || ((r2 == '9') && (r4 == '9')) ||
                 ((r2 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9')) || ((r3 == '9') && (r5 == '9')) || ((r4 == '9') && (r5 == '9'))) )
            {
                gas[i].prio = 166; strcpy(gas[i].rink,"Pilnas namas (4-9)");
            }
            if ( (((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r5 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r1 == '4') && (r5 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r2 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r4 == '4') && (r5 == '4')) || ((gas[i].reiksme2 == '4') && (r1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4') && (r3 == '4')) || ((gas[i].reiksme2 == '4') && (r1 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4') && (r5 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r3 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4') && (r3 == '4')) || ((r1 == '4') && (r2 == '4') && (r4 == '4')) ||
                 ((r1 == '4') && (r2 == '4') && (r5 == '4')) || ((r1 == '4') && (r3 == '4') && (r4 == '4')) || ((r1 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((r1 == '4') && (r4 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4') && (r4 == '4')) || ((r2 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((r2 == '4') && (r4 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4') && (r5 == '4'))) &&
                 (((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T')) || ((r1 == 'T') && (r3 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T')) || ((r2 == 'T') && (r4 == 'T')) ||
                 ((r2 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T')) || ((r3 == 'T') && (r5 == 'T')) || ((r4 == 'T') && (r5 == 'T'))) )
            {
                gas[i].prio = 167; strcpy(gas[i].rink,"Pilnas namas (4-T)");
            }
            if ( (((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r5 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r1 == '4') && (r5 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r2 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r4 == '4') && (r5 == '4')) || ((gas[i].reiksme2 == '4') && (r1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4') && (r3 == '4')) || ((gas[i].reiksme2 == '4') && (r1 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4') && (r5 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r3 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4') && (r3 == '4')) || ((r1 == '4') && (r2 == '4') && (r4 == '4')) ||
                 ((r1 == '4') && (r2 == '4') && (r5 == '4')) || ((r1 == '4') && (r3 == '4') && (r4 == '4')) || ((r1 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((r1 == '4') && (r4 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4') && (r4 == '4')) || ((r2 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((r2 == '4') && (r4 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4') && (r5 == '4'))) &&
                 (((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J')) || ((r1 == 'J') && (r3 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J')) || ((r2 == 'J') && (r4 == 'J')) ||
                 ((r2 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J')) || ((r3 == 'J') && (r5 == 'J')) || ((r4 == 'J') && (r5 == 'J'))) )
            {
                gas[i].prio = 168; strcpy(gas[i].rink,"Pilnas namas (4-J)");
            }
            if ( (((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r5 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r1 == '4') && (r5 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r2 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r4 == '4') && (r5 == '4')) || ((gas[i].reiksme2 == '4') && (r1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4') && (r3 == '4')) || ((gas[i].reiksme2 == '4') && (r1 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4') && (r5 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r3 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4') && (r3 == '4')) || ((r1 == '4') && (r2 == '4') && (r4 == '4')) ||
                 ((r1 == '4') && (r2 == '4') && (r5 == '4')) || ((r1 == '4') && (r3 == '4') && (r4 == '4')) || ((r1 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((r1 == '4') && (r4 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4') && (r4 == '4')) || ((r2 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((r2 == '4') && (r4 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4') && (r5 == '4'))) &&
                 (((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q')) || ((r2 == 'Q') && (r4 == 'Q')) ||
                 ((r2 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q')) || ((r3 == 'Q') && (r5 == 'Q')) || ((r4 == 'Q') && (r5 == 'Q'))) )
            {
                gas[i].prio = 169; strcpy(gas[i].rink,"Pilnas namas (4-Q)");
            }
            if ( (((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r5 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r1 == '4') && (r5 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r2 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r4 == '4') && (r5 == '4')) || ((gas[i].reiksme2 == '4') && (r1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4') && (r3 == '4')) || ((gas[i].reiksme2 == '4') && (r1 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4') && (r5 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r3 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4') && (r3 == '4')) || ((r1 == '4') && (r2 == '4') && (r4 == '4')) ||
                 ((r1 == '4') && (r2 == '4') && (r5 == '4')) || ((r1 == '4') && (r3 == '4') && (r4 == '4')) || ((r1 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((r1 == '4') && (r4 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4') && (r4 == '4')) || ((r2 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((r2 == '4') && (r4 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4') && (r5 == '4'))) &&
                 (((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K')) || ((r1 == 'K') && (r3 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K')) || ((r2 == 'K') && (r4 == 'K')) ||
                 ((r2 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K')) || ((r3 == 'K') && (r5 == 'K')) || ((r4 == 'K') && (r5 == 'K'))) )
            {
                gas[i].prio = 170; strcpy(gas[i].rink,"Pilnas namas (4-K)");
            }
            if ( (((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4') && (r5 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r1 == '4') && (r5 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r2 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r4 == '4') && (r5 == '4')) || ((gas[i].reiksme2 == '4') && (r1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4') && (r3 == '4')) || ((gas[i].reiksme2 == '4') && (r1 == '4') && (r4 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4') && (r5 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r3 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4') && (r3 == '4')) || ((r1 == '4') && (r2 == '4') && (r4 == '4')) ||
                 ((r1 == '4') && (r2 == '4') && (r5 == '4')) || ((r1 == '4') && (r3 == '4') && (r4 == '4')) || ((r1 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((r1 == '4') && (r4 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4') && (r4 == '4')) || ((r2 == '4') && (r3 == '4') && (r5 == '4')) ||
                 ((r2 == '4') && (r4 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4') && (r5 == '4'))) &&
                 (((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A')) || ((r1 == 'A') && (r3 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A')) || ((r2 == 'A') && (r4 == 'A')) ||
                 ((r2 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A')) || ((r3 == 'A') && (r5 == 'A')) || ((r4 == 'A') && (r5 == 'A'))) )
            {
                gas[i].prio = 171; strcpy(gas[i].rink,"Pilnas namas (4-A)");
            }
            if ( (((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r5 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r1 == '5') && (r5 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r2 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r4 == '5') && (r5 == '5')) || ((gas[i].reiksme2 == '5') && (r1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5') && (r3 == '5')) || ((gas[i].reiksme2 == '5') && (r1 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5') && (r5 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r3 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5') && (r3 == '5')) || ((r1 == '5') && (r2 == '5') && (r4 == '5')) ||
                 ((r1 == '5') && (r2 == '5') && (r5 == '5')) || ((r1 == '5') && (r3 == '5') && (r4 == '5')) || ((r1 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((r1 == '5') && (r4 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5') && (r4 == '5')) || ((r2 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((r2 == '5') && (r4 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5') && (r5 == '5'))) &&
                 (((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2')) || ((r1 == '2') && (r3 == '2')) ||
                 ((r1 == '2') && (r4 == '2')) || ((r1 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2')) || ((r2 == '2') && (r4 == '2')) ||
                 ((r2 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2')) || ((r3 == '2') && (r5 == '2')) || ((r4 == '2') && (r5 == '2'))) )
            {
                gas[i].prio = 172; strcpy(gas[i].rink,"Pilnas namas (5-2)");
            }
            if ( (((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r5 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r1 == '5') && (r5 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r2 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r4 == '5') && (r5 == '5')) || ((gas[i].reiksme2 == '5') && (r1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5') && (r3 == '5')) || ((gas[i].reiksme2 == '5') && (r1 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5') && (r5 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r3 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5') && (r3 == '5')) || ((r1 == '5') && (r2 == '5') && (r4 == '5')) ||
                 ((r1 == '5') && (r2 == '5') && (r5 == '5')) || ((r1 == '5') && (r3 == '5') && (r4 == '5')) || ((r1 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((r1 == '5') && (r4 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5') && (r4 == '5')) || ((r2 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((r2 == '5') && (r4 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5') && (r5 == '5'))) &&
                 (((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3')) || ((r1 == '3') && (r3 == '3')) ||
                 ((r1 == '3') && (r4 == '3')) || ((r1 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3')) || ((r2 == '3') && (r4 == '3')) ||
                 ((r2 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3')) || ((r3 == '3') && (r5 == '3')) || ((r4 == '3') && (r5 == '3'))) )
            {
                gas[i].prio = 173; strcpy(gas[i].rink,"Pilnas namas (5-3)");
            }
            if ( (((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r5 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r1 == '5') && (r5 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r2 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r4 == '5') && (r5 == '5')) || ((gas[i].reiksme2 == '5') && (r1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5') && (r3 == '5')) || ((gas[i].reiksme2 == '5') && (r1 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5') && (r5 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r3 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5') && (r3 == '5')) || ((r1 == '5') && (r2 == '5') && (r4 == '5')) ||
                 ((r1 == '5') && (r2 == '5') && (r5 == '5')) || ((r1 == '5') && (r3 == '5') && (r4 == '5')) || ((r1 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((r1 == '5') && (r4 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5') && (r4 == '5')) || ((r2 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((r2 == '5') && (r4 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5') && (r5 == '5'))) &&
                 (((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4')) || ((r1 == '4') && (r3 == '4')) ||
                 ((r1 == '4') && (r4 == '4')) || ((r1 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4')) || ((r2 == '4') && (r4 == '4')) ||
                 ((r2 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4')) || ((r3 == '4') && (r5 == '4')) || ((r4 == '4') && (r5 == '4'))) )
            {
                gas[i].prio = 174; strcpy(gas[i].rink,"Pilnas namas (5-4)");
            }
            if ( (((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r5 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r1 == '5') && (r5 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r2 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r4 == '5') && (r5 == '5')) || ((gas[i].reiksme2 == '5') && (r1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5') && (r3 == '5')) || ((gas[i].reiksme2 == '5') && (r1 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5') && (r5 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r3 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5') && (r3 == '5')) || ((r1 == '5') && (r2 == '5') && (r4 == '5')) ||
                 ((r1 == '5') && (r2 == '5') && (r5 == '5')) || ((r1 == '5') && (r3 == '5') && (r4 == '5')) || ((r1 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((r1 == '5') && (r4 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5') && (r4 == '5')) || ((r2 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((r2 == '5') && (r4 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5') && (r5 == '5'))) &&
                 (((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6')) || ((r1 == '6') && (r3 == '6')) ||
                 ((r1 == '6') && (r4 == '6')) || ((r1 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6')) || ((r2 == '6') && (r4 == '6')) ||
                 ((r2 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6')) || ((r3 == '6') && (r5 == '6')) || ((r4 == '6') && (r5 == '6'))) )
            {
                gas[i].prio = 175; strcpy(gas[i].rink,"Pilnas namas (5-6)");
            }
            if ( (((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r5 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r1 == '5') && (r5 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r2 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r4 == '5') && (r5 == '5')) || ((gas[i].reiksme2 == '5') && (r1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5') && (r3 == '5')) || ((gas[i].reiksme2 == '5') && (r1 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5') && (r5 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r3 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5') && (r3 == '5')) || ((r1 == '5') && (r2 == '5') && (r4 == '5')) ||
                 ((r1 == '5') && (r2 == '5') && (r5 == '5')) || ((r1 == '5') && (r3 == '5') && (r4 == '5')) || ((r1 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((r1 == '5') && (r4 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5') && (r4 == '5')) || ((r2 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((r2 == '5') && (r4 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5') && (r5 == '5'))) &&
                 (((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7')) || ((r1 == '7') && (r3 == '7')) ||
                 ((r1 == '7') && (r4 == '7')) || ((r1 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7')) || ((r2 == '7') && (r4 == '7')) ||
                 ((r2 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7')) || ((r3 == '7') && (r5 == '7')) || ((r4 == '7') && (r5 == '7'))) )
            {
                gas[i].prio = 176; strcpy(gas[i].rink,"Pilnas namas (5-7)");
            }
            if ( (((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r5 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r1 == '5') && (r5 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r2 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r4 == '5') && (r5 == '5')) || ((gas[i].reiksme2 == '5') && (r1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5') && (r3 == '5')) || ((gas[i].reiksme2 == '5') && (r1 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5') && (r5 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r3 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5') && (r3 == '5')) || ((r1 == '5') && (r2 == '5') && (r4 == '5')) ||
                 ((r1 == '5') && (r2 == '5') && (r5 == '5')) || ((r1 == '5') && (r3 == '5') && (r4 == '5')) || ((r1 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((r1 == '5') && (r4 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5') && (r4 == '5')) || ((r2 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((r2 == '5') && (r4 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5') && (r5 == '5'))) &&
                 (((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8')) || ((r1 == '8') && (r3 == '8')) ||
                 ((r1 == '8') && (r4 == '8')) || ((r1 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8')) || ((r2 == '8') && (r4 == '8')) ||
                 ((r2 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8')) || ((r3 == '8') && (r5 == '8')) || ((r4 == '8') && (r5 == '8'))) )
            {
                gas[i].prio = 177; strcpy(gas[i].rink,"Pilnas namas (5-8)");
            }
            if ( (((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r5 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r1 == '5') && (r5 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r2 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r4 == '5') && (r5 == '5')) || ((gas[i].reiksme2 == '5') && (r1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5') && (r3 == '5')) || ((gas[i].reiksme2 == '5') && (r1 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5') && (r5 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r3 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5') && (r3 == '5')) || ((r1 == '5') && (r2 == '5') && (r4 == '5')) ||
                 ((r1 == '5') && (r2 == '5') && (r5 == '5')) || ((r1 == '5') && (r3 == '5') && (r4 == '5')) || ((r1 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((r1 == '5') && (r4 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5') && (r4 == '5')) || ((r2 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((r2 == '5') && (r4 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5') && (r5 == '5'))) &&
                 (((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9')) || ((r1 == '9') && (r3 == '9')) ||
                 ((r1 == '9') && (r4 == '9')) || ((r1 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9')) || ((r2 == '9') && (r4 == '9')) ||
                 ((r2 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9')) || ((r3 == '9') && (r5 == '9')) || ((r4 == '9') && (r5 == '9'))) )
            {
                gas[i].prio = 178; strcpy(gas[i].rink,"Pilnas namas (5-9)");
            }
            if ( (((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r5 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r1 == '5') && (r5 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r2 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r4 == '5') && (r5 == '5')) || ((gas[i].reiksme2 == '5') && (r1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5') && (r3 == '5')) || ((gas[i].reiksme2 == '5') && (r1 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5') && (r5 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r3 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5') && (r3 == '5')) || ((r1 == '5') && (r2 == '5') && (r4 == '5')) ||
                 ((r1 == '5') && (r2 == '5') && (r5 == '5')) || ((r1 == '5') && (r3 == '5') && (r4 == '5')) || ((r1 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((r1 == '5') && (r4 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5') && (r4 == '5')) || ((r2 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((r2 == '5') && (r4 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5') && (r5 == '5'))) &&
                 (((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T')) || ((r1 == 'T') && (r3 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T')) || ((r2 == 'T') && (r4 == 'T')) ||
                 ((r2 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T')) || ((r3 == 'T') && (r5 == 'T')) || ((r4 == 'T') && (r5 == 'T'))) )
            {
                gas[i].prio = 179; strcpy(gas[i].rink,"Pilnas namas (5-T)");
            }
            if ( (((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r5 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r1 == '5') && (r5 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r2 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r4 == '5') && (r5 == '5')) || ((gas[i].reiksme2 == '5') && (r1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5') && (r3 == '5')) || ((gas[i].reiksme2 == '5') && (r1 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5') && (r5 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r3 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5') && (r3 == '5')) || ((r1 == '5') && (r2 == '5') && (r4 == '5')) ||
                 ((r1 == '5') && (r2 == '5') && (r5 == '5')) || ((r1 == '5') && (r3 == '5') && (r4 == '5')) || ((r1 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((r1 == '5') && (r4 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5') && (r4 == '5')) || ((r2 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((r2 == '5') && (r4 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5') && (r5 == '5'))) &&
                 (((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J')) || ((r1 == 'J') && (r3 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J')) || ((r2 == 'J') && (r4 == 'J')) ||
                 ((r2 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J')) || ((r3 == 'J') && (r5 == 'J')) || ((r4 == 'J') && (r5 == 'J'))) )
            {
                gas[i].prio = 180; strcpy(gas[i].rink,"Pilnas namas (5-J)");
            }
            if ( (((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r5 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r1 == '5') && (r5 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r2 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r4 == '5') && (r5 == '5')) || ((gas[i].reiksme2 == '5') && (r1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5') && (r3 == '5')) || ((gas[i].reiksme2 == '5') && (r1 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5') && (r5 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r3 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5') && (r3 == '5')) || ((r1 == '5') && (r2 == '5') && (r4 == '5')) ||
                 ((r1 == '5') && (r2 == '5') && (r5 == '5')) || ((r1 == '5') && (r3 == '5') && (r4 == '5')) || ((r1 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((r1 == '5') && (r4 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5') && (r4 == '5')) || ((r2 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((r2 == '5') && (r4 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5') && (r5 == '5'))) &&
                 (((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q')) || ((r2 == 'Q') && (r4 == 'Q')) ||
                 ((r2 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q')) || ((r3 == 'Q') && (r5 == 'Q')) || ((r4 == 'Q') && (r5 == 'Q'))) )
            {
                gas[i].prio = 181; strcpy(gas[i].rink,"Pilnas namas (5-Q)");
            }
            if ( (((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r5 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r1 == '5') && (r5 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r2 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r4 == '5') && (r5 == '5')) || ((gas[i].reiksme2 == '5') && (r1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5') && (r3 == '5')) || ((gas[i].reiksme2 == '5') && (r1 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5') && (r5 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r3 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5') && (r3 == '5')) || ((r1 == '5') && (r2 == '5') && (r4 == '5')) ||
                 ((r1 == '5') && (r2 == '5') && (r5 == '5')) || ((r1 == '5') && (r3 == '5') && (r4 == '5')) || ((r1 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((r1 == '5') && (r4 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5') && (r4 == '5')) || ((r2 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((r2 == '5') && (r4 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5') && (r5 == '5'))) &&
                 (((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K')) || ((r1 == 'K') && (r3 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K')) || ((r2 == 'K') && (r4 == 'K')) ||
                 ((r2 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K')) || ((r3 == 'K') && (r5 == 'K')) || ((r4 == 'K') && (r5 == 'K'))) )
            {
                gas[i].prio = 182; strcpy(gas[i].rink,"Pilnas namas (5-K)");
            }
            if ( (((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5') && (r5 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r1 == '5') && (r5 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r2 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r4 == '5') && (r5 == '5')) || ((gas[i].reiksme2 == '5') && (r1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5') && (r3 == '5')) || ((gas[i].reiksme2 == '5') && (r1 == '5') && (r4 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5') && (r5 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r3 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5') && (r3 == '5')) || ((r1 == '5') && (r2 == '5') && (r4 == '5')) ||
                 ((r1 == '5') && (r2 == '5') && (r5 == '5')) || ((r1 == '5') && (r3 == '5') && (r4 == '5')) || ((r1 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((r1 == '5') && (r4 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5') && (r4 == '5')) || ((r2 == '5') && (r3 == '5') && (r5 == '5')) ||
                 ((r2 == '5') && (r4 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5') && (r5 == '5'))) &&
                 (((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A')) || ((r1 == 'A') && (r3 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A')) || ((r2 == 'A') && (r4 == 'A')) ||
                 ((r2 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A')) || ((r3 == 'A') && (r5 == 'A')) || ((r4 == 'A') && (r5 == 'A'))) )
            {
                gas[i].prio = 183; strcpy(gas[i].rink,"Pilnas namas (5-A)");
            }
            if ( (((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r5 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r1 == '6') && (r5 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r2 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r4 == '6') && (r5 == '6')) || ((gas[i].reiksme2 == '6') && (r1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6') && (r3 == '6')) || ((gas[i].reiksme2 == '6') && (r1 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6') && (r5 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r3 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6') && (r3 == '6')) || ((r1 == '6') && (r2 == '6') && (r4 == '6')) ||
                 ((r1 == '6') && (r2 == '6') && (r5 == '6')) || ((r1 == '6') && (r3 == '6') && (r4 == '6')) || ((r1 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((r1 == '6') && (r4 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6') && (r4 == '6')) || ((r2 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((r2 == '6') && (r4 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6') && (r5 == '6'))) &&
                 (((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2')) || ((r1 == '2') && (r3 == '2')) ||
                 ((r1 == '2') && (r4 == '2')) || ((r1 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2')) || ((r2 == '2') && (r4 == '2')) ||
                 ((r2 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2')) || ((r3 == '2') && (r5 == '2')) || ((r4 == '2') && (r5 == '2'))) )
            {
                gas[i].prio = 184; strcpy(gas[i].rink,"Pilnas namas (6-2)");
            }
            if ( (((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r5 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r1 == '6') && (r5 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r2 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r4 == '6') && (r5 == '6')) || ((gas[i].reiksme2 == '6') && (r1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6') && (r3 == '6')) || ((gas[i].reiksme2 == '6') && (r1 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6') && (r5 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r3 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6') && (r3 == '6')) || ((r1 == '6') && (r2 == '6') && (r4 == '6')) ||
                 ((r1 == '6') && (r2 == '6') && (r5 == '6')) || ((r1 == '6') && (r3 == '6') && (r4 == '6')) || ((r1 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((r1 == '6') && (r4 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6') && (r4 == '6')) || ((r2 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((r2 == '6') && (r4 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6') && (r5 == '6'))) &&
                 (((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3')) || ((r1 == '3') && (r3 == '3')) ||
                 ((r1 == '3') && (r4 == '3')) || ((r1 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3')) || ((r2 == '3') && (r4 == '3')) ||
                 ((r2 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3')) || ((r3 == '3') && (r5 == '3')) || ((r4 == '3') && (r5 == '3'))) )
            {
                gas[i].prio = 185; strcpy(gas[i].rink,"Pilnas namas (6-3)");
            }
            if ( (((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r5 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r1 == '6') && (r5 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r2 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r4 == '6') && (r5 == '6')) || ((gas[i].reiksme2 == '6') && (r1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6') && (r3 == '6')) || ((gas[i].reiksme2 == '6') && (r1 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6') && (r5 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r3 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6') && (r3 == '6')) || ((r1 == '6') && (r2 == '6') && (r4 == '6')) ||
                 ((r1 == '6') && (r2 == '6') && (r5 == '6')) || ((r1 == '6') && (r3 == '6') && (r4 == '6')) || ((r1 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((r1 == '6') && (r4 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6') && (r4 == '6')) || ((r2 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((r2 == '6') && (r4 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6') && (r5 == '6'))) &&
                 (((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4')) || ((r1 == '4') && (r3 == '4')) ||
                 ((r1 == '4') && (r4 == '4')) || ((r1 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4')) || ((r2 == '4') && (r4 == '4')) ||
                 ((r2 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4')) || ((r3 == '4') && (r5 == '4')) || ((r4 == '4') && (r5 == '4'))) )
            {
                gas[i].prio = 186; strcpy(gas[i].rink,"Pilnas namas (6-4)");
            }
            if ( (((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r5 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r1 == '6') && (r5 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r2 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r4 == '6') && (r5 == '6')) || ((gas[i].reiksme2 == '6') && (r1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6') && (r3 == '6')) || ((gas[i].reiksme2 == '6') && (r1 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6') && (r5 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r3 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6') && (r3 == '6')) || ((r1 == '6') && (r2 == '6') && (r4 == '6')) ||
                 ((r1 == '6') && (r2 == '6') && (r5 == '6')) || ((r1 == '6') && (r3 == '6') && (r4 == '6')) || ((r1 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((r1 == '6') && (r4 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6') && (r4 == '6')) || ((r2 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((r2 == '6') && (r4 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6') && (r5 == '6'))) &&
                 (((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5')) || ((r1 == '5') && (r3 == '5')) ||
                 ((r1 == '5') && (r4 == '5')) || ((r1 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5')) || ((r2 == '5') && (r4 == '5')) ||
                 ((r2 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5')) || ((r3 == '5') && (r5 == '5')) || ((r4 == '5') && (r5 == '5'))) )
            {
                gas[i].prio = 187; strcpy(gas[i].rink,"Pilnas namas (6-5)");
            }
            if ( (((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r5 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r1 == '6') && (r5 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r2 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r4 == '6') && (r5 == '6')) || ((gas[i].reiksme2 == '6') && (r1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6') && (r3 == '6')) || ((gas[i].reiksme2 == '6') && (r1 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6') && (r5 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r3 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6') && (r3 == '6')) || ((r1 == '6') && (r2 == '6') && (r4 == '6')) ||
                 ((r1 == '6') && (r2 == '6') && (r5 == '6')) || ((r1 == '6') && (r3 == '6') && (r4 == '6')) || ((r1 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((r1 == '6') && (r4 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6') && (r4 == '6')) || ((r2 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((r2 == '6') && (r4 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6') && (r5 == '6'))) &&
                 (((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7')) || ((r1 == '7') && (r3 == '7')) ||
                 ((r1 == '7') && (r4 == '7')) || ((r1 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7')) || ((r2 == '7') && (r4 == '7')) ||
                 ((r2 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7')) || ((r3 == '7') && (r5 == '7')) || ((r4 == '7') && (r5 == '7'))) )
            {
                gas[i].prio = 188; strcpy(gas[i].rink,"Pilnas namas (6-7)");
            }
            if ( (((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r5 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r1 == '6') && (r5 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r2 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r4 == '6') && (r5 == '6')) || ((gas[i].reiksme2 == '6') && (r1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6') && (r3 == '6')) || ((gas[i].reiksme2 == '6') && (r1 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6') && (r5 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r3 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6') && (r3 == '6')) || ((r1 == '6') && (r2 == '6') && (r4 == '6')) ||
                 ((r1 == '6') && (r2 == '6') && (r5 == '6')) || ((r1 == '6') && (r3 == '6') && (r4 == '6')) || ((r1 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((r1 == '6') && (r4 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6') && (r4 == '6')) || ((r2 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((r2 == '6') && (r4 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6') && (r5 == '6'))) &&
                 (((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8')) || ((r1 == '8') && (r3 == '8')) ||
                 ((r1 == '8') && (r4 == '8')) || ((r1 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8')) || ((r2 == '8') && (r4 == '8')) ||
                 ((r2 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8')) || ((r3 == '8') && (r5 == '8')) || ((r4 == '8') && (r5 == '8'))) )
            {
                gas[i].prio = 189; strcpy(gas[i].rink,"Pilnas namas (6-8)");
            }
            if ( (((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r5 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r1 == '6') && (r5 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r2 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r4 == '6') && (r5 == '6')) || ((gas[i].reiksme2 == '6') && (r1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6') && (r3 == '6')) || ((gas[i].reiksme2 == '6') && (r1 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6') && (r5 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r3 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6') && (r3 == '6')) || ((r1 == '6') && (r2 == '6') && (r4 == '6')) ||
                 ((r1 == '6') && (r2 == '6') && (r5 == '6')) || ((r1 == '6') && (r3 == '6') && (r4 == '6')) || ((r1 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((r1 == '6') && (r4 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6') && (r4 == '6')) || ((r2 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((r2 == '6') && (r4 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6') && (r5 == '6'))) &&
                 (((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9')) || ((r1 == '9') && (r3 == '9')) ||
                 ((r1 == '9') && (r4 == '9')) || ((r1 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9')) || ((r2 == '9') && (r4 == '9')) ||
                 ((r2 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9')) || ((r3 == '9') && (r5 == '9')) || ((r4 == '9') && (r5 == '9'))) )
            {
                gas[i].prio = 190; strcpy(gas[i].rink,"Pilnas namas (6-9)");
            }
            if ( (((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r5 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r1 == '6') && (r5 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r2 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r4 == '6') && (r5 == '6')) || ((gas[i].reiksme2 == '6') && (r1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6') && (r3 == '6')) || ((gas[i].reiksme2 == '6') && (r1 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6') && (r5 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r3 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6') && (r3 == '6')) || ((r1 == '6') && (r2 == '6') && (r4 == '6')) ||
                 ((r1 == '6') && (r2 == '6') && (r5 == '6')) || ((r1 == '6') && (r3 == '6') && (r4 == '6')) || ((r1 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((r1 == '6') && (r4 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6') && (r4 == '6')) || ((r2 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((r2 == '6') && (r4 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6') && (r5 == '6'))) &&
                 (((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T')) || ((r1 == 'T') && (r3 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T')) || ((r2 == 'T') && (r4 == 'T')) ||
                 ((r2 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T')) || ((r3 == 'T') && (r5 == 'T')) || ((r4 == 'T') && (r5 == 'T'))) )
            {
                gas[i].prio = 191; strcpy(gas[i].rink,"Pilnas namas (6-T)");
            }
            if ( (((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r5 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r1 == '6') && (r5 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r2 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r4 == '6') && (r5 == '6')) || ((gas[i].reiksme2 == '6') && (r1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6') && (r3 == '6')) || ((gas[i].reiksme2 == '6') && (r1 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6') && (r5 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r3 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6') && (r3 == '6')) || ((r1 == '6') && (r2 == '6') && (r4 == '6')) ||
                 ((r1 == '6') && (r2 == '6') && (r5 == '6')) || ((r1 == '6') && (r3 == '6') && (r4 == '6')) || ((r1 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((r1 == '6') && (r4 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6') && (r4 == '6')) || ((r2 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((r2 == '6') && (r4 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6') && (r5 == '6'))) &&
                 (((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J')) || ((r1 == 'J') && (r3 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J')) || ((r2 == 'J') && (r4 == 'J')) ||
                 ((r2 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J')) || ((r3 == 'J') && (r5 == 'J')) || ((r4 == 'J') && (r5 == 'J'))) )
            {
                gas[i].prio = 192; strcpy(gas[i].rink,"Pilnas namas (6-J)");
            }
            if ( (((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r5 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r1 == '6') && (r5 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r2 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r4 == '6') && (r5 == '6')) || ((gas[i].reiksme2 == '6') && (r1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6') && (r3 == '6')) || ((gas[i].reiksme2 == '6') && (r1 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6') && (r5 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r3 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6') && (r3 == '6')) || ((r1 == '6') && (r2 == '6') && (r4 == '6')) ||
                 ((r1 == '6') && (r2 == '6') && (r5 == '6')) || ((r1 == '6') && (r3 == '6') && (r4 == '6')) || ((r1 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((r1 == '6') && (r4 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6') && (r4 == '6')) || ((r2 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((r2 == '6') && (r4 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6') && (r5 == '6'))) &&
                 (((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q')) || ((r2 == 'Q') && (r4 == 'Q')) ||
                 ((r2 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q')) || ((r3 == 'Q') && (r5 == 'Q')) || ((r4 == 'Q') && (r5 == 'Q'))) )
            {
                gas[i].prio = 193; strcpy(gas[i].rink,"Pilnas namas (6-Q)");
            }
            if ( (((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r5 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r1 == '6') && (r5 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r2 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r4 == '6') && (r5 == '6')) || ((gas[i].reiksme2 == '6') && (r1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6') && (r3 == '6')) || ((gas[i].reiksme2 == '6') && (r1 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6') && (r5 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r3 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6') && (r3 == '6')) || ((r1 == '6') && (r2 == '6') && (r4 == '6')) ||
                 ((r1 == '6') && (r2 == '6') && (r5 == '6')) || ((r1 == '6') && (r3 == '6') && (r4 == '6')) || ((r1 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((r1 == '6') && (r4 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6') && (r4 == '6')) || ((r2 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((r2 == '6') && (r4 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6') && (r5 == '6'))) &&
                 (((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K')) || ((r1 == 'K') && (r3 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K')) || ((r2 == 'K') && (r4 == 'K')) ||
                 ((r2 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K')) || ((r3 == 'K') && (r5 == 'K')) || ((r4 == 'K') && (r5 == 'K'))) )
            {
                gas[i].prio = 194; strcpy(gas[i].rink,"Pilnas namas (6-K)");
            }
            if ( (((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6') && (r5 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r1 == '6') && (r5 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r2 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r4 == '6') && (r5 == '6')) || ((gas[i].reiksme2 == '6') && (r1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6') && (r3 == '6')) || ((gas[i].reiksme2 == '6') && (r1 == '6') && (r4 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6') && (r5 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r3 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6') && (r3 == '6')) || ((r1 == '6') && (r2 == '6') && (r4 == '6')) ||
                 ((r1 == '6') && (r2 == '6') && (r5 == '6')) || ((r1 == '6') && (r3 == '6') && (r4 == '6')) || ((r1 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((r1 == '6') && (r4 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6') && (r4 == '6')) || ((r2 == '6') && (r3 == '6') && (r5 == '6')) ||
                 ((r2 == '6') && (r4 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6') && (r5 == '6'))) &&
                 (((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A')) || ((r1 == 'A') && (r3 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A')) || ((r2 == 'A') && (r4 == 'A')) ||
                 ((r2 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A')) || ((r3 == 'A') && (r5 == 'A')) || ((r4 == 'A') && (r5 == 'A'))) )
            {
                gas[i].prio = 195; strcpy(gas[i].rink,"Pilnas namas (6-A)");
            }
            if ( (((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r5 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r1 == '7') && (r5 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r2 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r4 == '7') && (r5 == '7')) || ((gas[i].reiksme2 == '7') && (r1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7') && (r3 == '7')) || ((gas[i].reiksme2 == '7') && (r1 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7') && (r5 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r3 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7') && (r3 == '7')) || ((r1 == '7') && (r2 == '7') && (r4 == '7')) ||
                 ((r1 == '7') && (r2 == '7') && (r5 == '7')) || ((r1 == '7') && (r3 == '7') && (r4 == '7')) || ((r1 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((r1 == '7') && (r4 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7') && (r4 == '7')) || ((r2 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((r2 == '7') && (r4 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7') && (r5 == '7'))) &&
                 (((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2')) || ((r1 == '2') && (r3 == '2')) ||
                 ((r1 == '2') && (r4 == '2')) || ((r1 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2')) || ((r2 == '2') && (r4 == '2')) ||
                 ((r2 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2')) || ((r3 == '2') && (r5 == '2')) || ((r4 == '2') && (r5 == '2'))) )
            {
                gas[i].prio = 196; strcpy(gas[i].rink,"Pilnas namas (7-2)");
            }
            if ( (((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r5 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r1 == '7') && (r5 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r2 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r4 == '7') && (r5 == '7')) || ((gas[i].reiksme2 == '7') && (r1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7') && (r3 == '7')) || ((gas[i].reiksme2 == '7') && (r1 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7') && (r5 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r3 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7') && (r3 == '7')) || ((r1 == '7') && (r2 == '7') && (r4 == '7')) ||
                 ((r1 == '7') && (r2 == '7') && (r5 == '7')) || ((r1 == '7') && (r3 == '7') && (r4 == '7')) || ((r1 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((r1 == '7') && (r4 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7') && (r4 == '7')) || ((r2 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((r2 == '7') && (r4 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7') && (r5 == '7'))) &&
                 (((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3')) || ((r1 == '3') && (r3 == '3')) ||
                 ((r1 == '3') && (r4 == '3')) || ((r1 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3')) || ((r2 == '3') && (r4 == '3')) ||
                 ((r2 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3')) || ((r3 == '3') && (r5 == '3')) || ((r4 == '3') && (r5 == '3'))) )
            {
                gas[i].prio = 197; strcpy(gas[i].rink,"Pilnas namas (7-3)");
            }
            if ( (((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r5 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r1 == '7') && (r5 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r2 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r4 == '7') && (r5 == '7')) || ((gas[i].reiksme2 == '7') && (r1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7') && (r3 == '7')) || ((gas[i].reiksme2 == '7') && (r1 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7') && (r5 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r3 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7') && (r3 == '7')) || ((r1 == '7') && (r2 == '7') && (r4 == '7')) ||
                 ((r1 == '7') && (r2 == '7') && (r5 == '7')) || ((r1 == '7') && (r3 == '7') && (r4 == '7')) || ((r1 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((r1 == '7') && (r4 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7') && (r4 == '7')) || ((r2 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((r2 == '7') && (r4 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7') && (r5 == '7'))) &&
                 (((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4')) || ((r1 == '4') && (r3 == '4')) ||
                 ((r1 == '4') && (r4 == '4')) || ((r1 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4')) || ((r2 == '4') && (r4 == '4')) ||
                 ((r2 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4')) || ((r3 == '4') && (r5 == '4')) || ((r4 == '4') && (r5 == '4'))) )
            {
                gas[i].prio = 198; strcpy(gas[i].rink,"Pilnas namas (7-4)");
            }
            if ( (((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r5 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r1 == '7') && (r5 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r2 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r4 == '7') && (r5 == '7')) || ((gas[i].reiksme2 == '7') && (r1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7') && (r3 == '7')) || ((gas[i].reiksme2 == '7') && (r1 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7') && (r5 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r3 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7') && (r3 == '7')) || ((r1 == '7') && (r2 == '7') && (r4 == '7')) ||
                 ((r1 == '7') && (r2 == '7') && (r5 == '7')) || ((r1 == '7') && (r3 == '7') && (r4 == '7')) || ((r1 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((r1 == '7') && (r4 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7') && (r4 == '7')) || ((r2 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((r2 == '7') && (r4 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7') && (r5 == '7'))) &&
                 (((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5')) || ((r1 == '5') && (r3 == '5')) ||
                 ((r1 == '5') && (r4 == '5')) || ((r1 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5')) || ((r2 == '5') && (r4 == '5')) ||
                 ((r2 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5')) || ((r3 == '5') && (r5 == '5')) || ((r4 == '5') && (r5 == '5'))) )
            {
                gas[i].prio = 199; strcpy(gas[i].rink,"Pilnas namas (7-5)");
            }
            if ( (((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r5 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r1 == '7') && (r5 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r2 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r4 == '7') && (r5 == '7')) || ((gas[i].reiksme2 == '7') && (r1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7') && (r3 == '7')) || ((gas[i].reiksme2 == '7') && (r1 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7') && (r5 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r3 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7') && (r3 == '7')) || ((r1 == '7') && (r2 == '7') && (r4 == '7')) ||
                 ((r1 == '7') && (r2 == '7') && (r5 == '7')) || ((r1 == '7') && (r3 == '7') && (r4 == '7')) || ((r1 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((r1 == '7') && (r4 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7') && (r4 == '7')) || ((r2 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((r2 == '7') && (r4 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7') && (r5 == '7'))) &&
                 (((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6')) || ((r1 == '6') && (r3 == '6')) ||
                 ((r1 == '6') && (r4 == '6')) || ((r1 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6')) || ((r2 == '6') && (r4 == '6')) ||
                 ((r2 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6')) || ((r3 == '6') && (r5 == '6')) || ((r4 == '6') && (r5 == '6'))) )
            {
                gas[i].prio = 200; strcpy(gas[i].rink,"Pilnas namas (7-6)");
            }
            if ( (((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r5 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r1 == '7') && (r5 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r2 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r4 == '7') && (r5 == '7')) || ((gas[i].reiksme2 == '7') && (r1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7') && (r3 == '7')) || ((gas[i].reiksme2 == '7') && (r1 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7') && (r5 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r3 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7') && (r3 == '7')) || ((r1 == '7') && (r2 == '7') && (r4 == '7')) ||
                 ((r1 == '7') && (r2 == '7') && (r5 == '7')) || ((r1 == '7') && (r3 == '7') && (r4 == '7')) || ((r1 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((r1 == '7') && (r4 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7') && (r4 == '7')) || ((r2 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((r2 == '7') && (r4 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7') && (r5 == '7'))) &&
                 (((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8')) || ((r1 == '8') && (r3 == '8')) ||
                 ((r1 == '8') && (r4 == '8')) || ((r1 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8')) || ((r2 == '8') && (r4 == '8')) ||
                 ((r2 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8')) || ((r3 == '8') && (r5 == '8')) || ((r4 == '8') && (r5 == '8'))) )
            {
                gas[i].prio = 201; strcpy(gas[i].rink,"Pilnas namas (7-8)");
            }
            if ( (((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r5 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r1 == '7') && (r5 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r2 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r4 == '7') && (r5 == '7')) || ((gas[i].reiksme2 == '7') && (r1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7') && (r3 == '7')) || ((gas[i].reiksme2 == '7') && (r1 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7') && (r5 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r3 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7') && (r3 == '7')) || ((r1 == '7') && (r2 == '7') && (r4 == '7')) ||
                 ((r1 == '7') && (r2 == '7') && (r5 == '7')) || ((r1 == '7') && (r3 == '7') && (r4 == '7')) || ((r1 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((r1 == '7') && (r4 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7') && (r4 == '7')) || ((r2 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((r2 == '7') && (r4 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7') && (r5 == '7'))) &&
                 (((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9')) || ((r1 == '9') && (r3 == '9')) ||
                 ((r1 == '9') && (r4 == '9')) || ((r1 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9')) || ((r2 == '9') && (r4 == '9')) ||
                 ((r2 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9')) || ((r3 == '9') && (r5 == '9')) || ((r4 == '9') && (r5 == '9'))) )
            {
                gas[i].prio = 202; strcpy(gas[i].rink,"Pilnas namas (7-9)");
            }
            if ( (((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r5 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r1 == '7') && (r5 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r2 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r4 == '7') && (r5 == '7')) || ((gas[i].reiksme2 == '7') && (r1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7') && (r3 == '7')) || ((gas[i].reiksme2 == '7') && (r1 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7') && (r5 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r3 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7') && (r3 == '7')) || ((r1 == '7') && (r2 == '7') && (r4 == '7')) ||
                 ((r1 == '7') && (r2 == '7') && (r5 == '7')) || ((r1 == '7') && (r3 == '7') && (r4 == '7')) || ((r1 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((r1 == '7') && (r4 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7') && (r4 == '7')) || ((r2 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((r2 == '7') && (r4 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7') && (r5 == '7'))) &&
                 (((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T')) || ((r1 == 'T') && (r3 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T')) || ((r2 == 'T') && (r4 == 'T')) ||
                 ((r2 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T')) || ((r3 == 'T') && (r5 == 'T')) || ((r4 == 'T') && (r5 == 'T'))) )
            {
                gas[i].prio = 203; strcpy(gas[i].rink,"Pilnas namas (7-T)");
            }
            if ( (((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r5 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r1 == '7') && (r5 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r2 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r4 == '7') && (r5 == '7')) || ((gas[i].reiksme2 == '7') && (r1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7') && (r3 == '7')) || ((gas[i].reiksme2 == '7') && (r1 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7') && (r5 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r3 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7') && (r3 == '7')) || ((r1 == '7') && (r2 == '7') && (r4 == '7')) ||
                 ((r1 == '7') && (r2 == '7') && (r5 == '7')) || ((r1 == '7') && (r3 == '7') && (r4 == '7')) || ((r1 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((r1 == '7') && (r4 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7') && (r4 == '7')) || ((r2 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((r2 == '7') && (r4 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7') && (r5 == '7'))) &&
                 (((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J')) || ((r1 == 'J') && (r3 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J')) || ((r2 == 'J') && (r4 == 'J')) ||
                 ((r2 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J')) || ((r3 == 'J') && (r5 == 'J')) || ((r4 == 'J') && (r5 == 'J'))) )
            {
                gas[i].prio = 204; strcpy(gas[i].rink,"Pilnas namas (7-J)");
            }
            if ( (((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r5 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r1 == '7') && (r5 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r2 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r4 == '7') && (r5 == '7')) || ((gas[i].reiksme2 == '7') && (r1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7') && (r3 == '7')) || ((gas[i].reiksme2 == '7') && (r1 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7') && (r5 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r3 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7') && (r3 == '7')) || ((r1 == '7') && (r2 == '7') && (r4 == '7')) ||
                 ((r1 == '7') && (r2 == '7') && (r5 == '7')) || ((r1 == '7') && (r3 == '7') && (r4 == '7')) || ((r1 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((r1 == '7') && (r4 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7') && (r4 == '7')) || ((r2 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((r2 == '7') && (r4 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7') && (r5 == '7'))) &&
                 (((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q')) || ((r2 == 'Q') && (r4 == 'Q')) ||
                 ((r2 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q')) || ((r3 == 'Q') && (r5 == 'Q')) || ((r4 == 'Q') && (r5 == 'Q'))) )
            {
                gas[i].prio = 205; strcpy(gas[i].rink,"Pilnas namas (7-Q)");
            }
            if ( (((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r5 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r1 == '7') && (r5 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r2 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r4 == '7') && (r5 == '7')) || ((gas[i].reiksme2 == '7') && (r1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7') && (r3 == '7')) || ((gas[i].reiksme2 == '7') && (r1 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7') && (r5 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r3 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7') && (r3 == '7')) || ((r1 == '7') && (r2 == '7') && (r4 == '7')) ||
                 ((r1 == '7') && (r2 == '7') && (r5 == '7')) || ((r1 == '7') && (r3 == '7') && (r4 == '7')) || ((r1 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((r1 == '7') && (r4 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7') && (r4 == '7')) || ((r2 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((r2 == '7') && (r4 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7') && (r5 == '7'))) &&
                 (((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K')) || ((r1 == 'K') && (r3 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K')) || ((r2 == 'K') && (r4 == 'K')) ||
                 ((r2 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K')) || ((r3 == 'K') && (r5 == 'K')) || ((r4 == 'K') && (r5 == 'K'))) )
            {
                gas[i].prio = 206; strcpy(gas[i].rink,"Pilnas namas (7-K)");
            }
            if ( (((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7') && (r5 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r1 == '7') && (r5 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r2 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r4 == '7') && (r5 == '7')) || ((gas[i].reiksme2 == '7') && (r1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7') && (r3 == '7')) || ((gas[i].reiksme2 == '7') && (r1 == '7') && (r4 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7') && (r5 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r3 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7') && (r3 == '7')) || ((r1 == '7') && (r2 == '7') && (r4 == '7')) ||
                 ((r1 == '7') && (r2 == '7') && (r5 == '7')) || ((r1 == '7') && (r3 == '7') && (r4 == '7')) || ((r1 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((r1 == '7') && (r4 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7') && (r4 == '7')) || ((r2 == '7') && (r3 == '7') && (r5 == '7')) ||
                 ((r2 == '7') && (r4 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7') && (r5 == '7'))) &&
                 (((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A')) || ((r1 == 'A') && (r3 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A')) || ((r2 == 'A') && (r4 == 'A')) ||
                 ((r2 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A')) || ((r3 == 'A') && (r5 == 'A')) || ((r4 == 'A') && (r5 == 'A'))) )
            {
                gas[i].prio = 207; strcpy(gas[i].rink,"Pilnas namas (7-A)");
            }
            if ( (((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r5 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r1 == '8') && (r5 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r2 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r4 == '8') && (r5 == '8')) || ((gas[i].reiksme2 == '8') && (r1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8') && (r3 == '8')) || ((gas[i].reiksme2 == '8') && (r1 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8') && (r5 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r3 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8') && (r3 == '8')) || ((r1 == '8') && (r2 == '8') && (r4 == '8')) ||
                 ((r1 == '8') && (r2 == '8') && (r5 == '8')) || ((r1 == '8') && (r3 == '8') && (r4 == '8')) || ((r1 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((r1 == '8') && (r4 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8') && (r4 == '8')) || ((r2 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((r2 == '8') && (r4 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8') && (r5 == '8'))) &&
                 (((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2')) || ((r1 == '2') && (r3 == '2')) ||
                 ((r1 == '2') && (r4 == '2')) || ((r1 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2')) || ((r2 == '2') && (r4 == '2')) ||
                 ((r2 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2')) || ((r3 == '2') && (r5 == '2')) || ((r4 == '2') && (r5 == '2'))) )
            {
                gas[i].prio = 208; strcpy(gas[i].rink,"Pilnas namas (8-2)");
            }
            if ( (((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r5 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r1 == '8') && (r5 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r2 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r4 == '8') && (r5 == '8')) || ((gas[i].reiksme2 == '8') && (r1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8') && (r3 == '8')) || ((gas[i].reiksme2 == '8') && (r1 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8') && (r5 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r3 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8') && (r3 == '8')) || ((r1 == '8') && (r2 == '8') && (r4 == '8')) ||
                 ((r1 == '8') && (r2 == '8') && (r5 == '8')) || ((r1 == '8') && (r3 == '8') && (r4 == '8')) || ((r1 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((r1 == '8') && (r4 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8') && (r4 == '8')) || ((r2 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((r2 == '8') && (r4 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8') && (r5 == '8'))) &&
                 (((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3')) || ((r1 == '3') && (r3 == '3')) ||
                 ((r1 == '3') && (r4 == '3')) || ((r1 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3')) || ((r2 == '3') && (r4 == '3')) ||
                 ((r2 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3')) || ((r3 == '3') && (r5 == '3')) || ((r4 == '3') && (r5 == '3'))) )
            {
                gas[i].prio = 209; strcpy(gas[i].rink,"Pilnas namas (8-3)");
            }
            if ( (((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r5 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r1 == '8') && (r5 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r2 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r4 == '8') && (r5 == '8')) || ((gas[i].reiksme2 == '8') && (r1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8') && (r3 == '8')) || ((gas[i].reiksme2 == '8') && (r1 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8') && (r5 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r3 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8') && (r3 == '8')) || ((r1 == '8') && (r2 == '8') && (r4 == '8')) ||
                 ((r1 == '8') && (r2 == '8') && (r5 == '8')) || ((r1 == '8') && (r3 == '8') && (r4 == '8')) || ((r1 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((r1 == '8') && (r4 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8') && (r4 == '8')) || ((r2 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((r2 == '8') && (r4 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8') && (r5 == '8'))) &&
                 (((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4')) || ((r1 == '4') && (r3 == '4')) ||
                 ((r1 == '4') && (r4 == '4')) || ((r1 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4')) || ((r2 == '4') && (r4 == '4')) ||
                 ((r2 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4')) || ((r3 == '4') && (r5 == '4')) || ((r4 == '4') && (r5 == '4'))) )
            {
                gas[i].prio = 210; strcpy(gas[i].rink,"Pilnas namas (8-4)");
            }
            if ( (((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r5 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r1 == '8') && (r5 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r2 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r4 == '8') && (r5 == '8')) || ((gas[i].reiksme2 == '8') && (r1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8') && (r3 == '8')) || ((gas[i].reiksme2 == '8') && (r1 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8') && (r5 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r3 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8') && (r3 == '8')) || ((r1 == '8') && (r2 == '8') && (r4 == '8')) ||
                 ((r1 == '8') && (r2 == '8') && (r5 == '8')) || ((r1 == '8') && (r3 == '8') && (r4 == '8')) || ((r1 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((r1 == '8') && (r4 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8') && (r4 == '8')) || ((r2 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((r2 == '8') && (r4 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8') && (r5 == '8'))) &&
                 (((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5')) || ((r1 == '5') && (r3 == '5')) ||
                 ((r1 == '5') && (r4 == '5')) || ((r1 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5')) || ((r2 == '5') && (r4 == '5')) ||
                 ((r2 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5')) || ((r3 == '5') && (r5 == '5')) || ((r4 == '5') && (r5 == '5'))) )
            {
                gas[i].prio = 211; strcpy(gas[i].rink,"Pilnas namas (8-5)");
            }
            if ( (((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r5 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r1 == '8') && (r5 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r2 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r4 == '8') && (r5 == '8')) || ((gas[i].reiksme2 == '8') && (r1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8') && (r3 == '8')) || ((gas[i].reiksme2 == '8') && (r1 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8') && (r5 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r3 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8') && (r3 == '8')) || ((r1 == '8') && (r2 == '8') && (r4 == '8')) ||
                 ((r1 == '8') && (r2 == '8') && (r5 == '8')) || ((r1 == '8') && (r3 == '8') && (r4 == '8')) || ((r1 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((r1 == '8') && (r4 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8') && (r4 == '8')) || ((r2 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((r2 == '8') && (r4 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8') && (r5 == '8'))) &&
                 (((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6')) || ((r1 == '6') && (r3 == '6')) ||
                 ((r1 == '6') && (r4 == '6')) || ((r1 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6')) || ((r2 == '6') && (r4 == '6')) ||
                 ((r2 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6')) || ((r3 == '6') && (r5 == '6')) || ((r4 == '6') && (r5 == '6'))) )
            {
                gas[i].prio = 212; strcpy(gas[i].rink,"Pilnas namas (8-6)");
            }
            if ( (((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r5 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r1 == '8') && (r5 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r2 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r4 == '8') && (r5 == '8')) || ((gas[i].reiksme2 == '8') && (r1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8') && (r3 == '8')) || ((gas[i].reiksme2 == '8') && (r1 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8') && (r5 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r3 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8') && (r3 == '8')) || ((r1 == '8') && (r2 == '8') && (r4 == '8')) ||
                 ((r1 == '8') && (r2 == '8') && (r5 == '8')) || ((r1 == '8') && (r3 == '8') && (r4 == '8')) || ((r1 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((r1 == '8') && (r4 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8') && (r4 == '8')) || ((r2 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((r2 == '8') && (r4 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8') && (r5 == '8'))) &&
                 (((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7')) || ((r1 == '7') && (r3 == '7')) ||
                 ((r1 == '7') && (r4 == '7')) || ((r1 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7')) || ((r2 == '7') && (r4 == '7')) ||
                 ((r2 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7')) || ((r3 == '7') && (r5 == '7')) || ((r4 == '7') && (r5 == '7'))) )
            {
                gas[i].prio = 213; strcpy(gas[i].rink,"Pilnas namas (8-7)");
            }
            if ( (((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r5 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r1 == '8') && (r5 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r2 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r4 == '8') && (r5 == '8')) || ((gas[i].reiksme2 == '8') && (r1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8') && (r3 == '8')) || ((gas[i].reiksme2 == '8') && (r1 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8') && (r5 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r3 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8') && (r3 == '8')) || ((r1 == '8') && (r2 == '8') && (r4 == '8')) ||
                 ((r1 == '8') && (r2 == '8') && (r5 == '8')) || ((r1 == '8') && (r3 == '8') && (r4 == '8')) || ((r1 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((r1 == '8') && (r4 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8') && (r4 == '8')) || ((r2 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((r2 == '8') && (r4 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8') && (r5 == '8'))) &&
                 (((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9')) || ((r1 == '9') && (r3 == '9')) ||
                 ((r1 == '9') && (r4 == '9')) || ((r1 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9')) || ((r2 == '9') && (r4 == '9')) ||
                 ((r2 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9')) || ((r3 == '9') && (r5 == '9')) || ((r4 == '9') && (r5 == '9'))) )
            {
                gas[i].prio = 214; strcpy(gas[i].rink,"Pilnas namas (8-9)");
            }
            if ( (((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r5 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r1 == '8') && (r5 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r2 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r4 == '8') && (r5 == '8')) || ((gas[i].reiksme2 == '8') && (r1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8') && (r3 == '8')) || ((gas[i].reiksme2 == '8') && (r1 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8') && (r5 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r3 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8') && (r3 == '8')) || ((r1 == '8') && (r2 == '8') && (r4 == '8')) ||
                 ((r1 == '8') && (r2 == '8') && (r5 == '8')) || ((r1 == '8') && (r3 == '8') && (r4 == '8')) || ((r1 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((r1 == '8') && (r4 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8') && (r4 == '8')) || ((r2 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((r2 == '8') && (r4 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8') && (r5 == '8'))) &&
                 (((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T')) || ((r1 == 'T') && (r3 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T')) || ((r2 == 'T') && (r4 == 'T')) ||
                 ((r2 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T')) || ((r3 == 'T') && (r5 == 'T')) || ((r4 == 'T') && (r5 == 'T'))) )
            {
                gas[i].prio = 215; strcpy(gas[i].rink,"Pilnas namas (8-T)");
            }
            if ( (((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r5 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r1 == '8') && (r5 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r2 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r4 == '8') && (r5 == '8')) || ((gas[i].reiksme2 == '8') && (r1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8') && (r3 == '8')) || ((gas[i].reiksme2 == '8') && (r1 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8') && (r5 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r3 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8') && (r3 == '8')) || ((r1 == '8') && (r2 == '8') && (r4 == '8')) ||
                 ((r1 == '8') && (r2 == '8') && (r5 == '8')) || ((r1 == '8') && (r3 == '8') && (r4 == '8')) || ((r1 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((r1 == '8') && (r4 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8') && (r4 == '8')) || ((r2 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((r2 == '8') && (r4 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8') && (r5 == '8'))) &&
                 (((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J')) || ((r1 == 'J') && (r3 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J')) || ((r2 == 'J') && (r4 == 'J')) ||
                 ((r2 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J')) || ((r3 == 'J') && (r5 == 'J')) || ((r4 == 'J') && (r5 == 'J'))) )
            {
                gas[i].prio = 216; strcpy(gas[i].rink,"Pilnas namas (8-J)");
            }
            if ( (((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r5 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r1 == '8') && (r5 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r2 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r4 == '8') && (r5 == '8')) || ((gas[i].reiksme2 == '8') && (r1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8') && (r3 == '8')) || ((gas[i].reiksme2 == '8') && (r1 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8') && (r5 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r3 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8') && (r3 == '8')) || ((r1 == '8') && (r2 == '8') && (r4 == '8')) ||
                 ((r1 == '8') && (r2 == '8') && (r5 == '8')) || ((r1 == '8') && (r3 == '8') && (r4 == '8')) || ((r1 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((r1 == '8') && (r4 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8') && (r4 == '8')) || ((r2 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((r2 == '8') && (r4 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8') && (r5 == '8'))) &&
                 (((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q')) || ((r2 == 'Q') && (r4 == 'Q')) ||
                 ((r2 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q')) || ((r3 == 'Q') && (r5 == 'Q')) || ((r4 == 'Q') && (r5 == 'Q'))) )
            {
                gas[i].prio = 217; strcpy(gas[i].rink,"Pilnas namas (8-Q)");
            }
            if ( (((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r5 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r1 == '8') && (r5 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r2 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r4 == '8') && (r5 == '8')) || ((gas[i].reiksme2 == '8') && (r1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8') && (r3 == '8')) || ((gas[i].reiksme2 == '8') && (r1 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8') && (r5 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r3 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8') && (r3 == '8')) || ((r1 == '8') && (r2 == '8') && (r4 == '8')) ||
                 ((r1 == '8') && (r2 == '8') && (r5 == '8')) || ((r1 == '8') && (r3 == '8') && (r4 == '8')) || ((r1 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((r1 == '8') && (r4 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8') && (r4 == '8')) || ((r2 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((r2 == '8') && (r4 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8') && (r5 == '8'))) &&
                 (((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K')) || ((r1 == 'K') && (r3 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K')) || ((r2 == 'K') && (r4 == 'K')) ||
                 ((r2 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K')) || ((r3 == 'K') && (r5 == 'K')) || ((r4 == 'K') && (r5 == 'K'))) )
            {
                gas[i].prio = 218; strcpy(gas[i].rink,"Pilnas namas (8-K)");
            }
            if ( (((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8') && (r5 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r1 == '8') && (r5 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r2 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r4 == '8') && (r5 == '8')) || ((gas[i].reiksme2 == '8') && (r1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8') && (r3 == '8')) || ((gas[i].reiksme2 == '8') && (r1 == '8') && (r4 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8') && (r5 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r3 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8') && (r3 == '8')) || ((r1 == '8') && (r2 == '8') && (r4 == '8')) ||
                 ((r1 == '8') && (r2 == '8') && (r5 == '8')) || ((r1 == '8') && (r3 == '8') && (r4 == '8')) || ((r1 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((r1 == '8') && (r4 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8') && (r4 == '8')) || ((r2 == '8') && (r3 == '8') && (r5 == '8')) ||
                 ((r2 == '8') && (r4 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8') && (r5 == '8'))) &&
                 (((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A')) || ((r1 == 'A') && (r3 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A')) || ((r2 == 'A') && (r4 == 'A')) ||
                 ((r2 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A')) || ((r3 == 'A') && (r5 == 'A')) || ((r4 == 'A') && (r5 == 'A'))) )
            {
                gas[i].prio = 219; strcpy(gas[i].rink,"Pilnas namas (8-A)");
            }
            if ( (((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r5 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r1 == '9') && (r5 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r2 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r4 == '9') && (r5 == '9')) || ((gas[i].reiksme2 == '9') && (r1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9') && (r3 == '9')) || ((gas[i].reiksme2 == '9') && (r1 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9') && (r5 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r3 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9') && (r3 == '9')) || ((r1 == '9') && (r2 == '9') && (r4 == '9')) ||
                 ((r1 == '9') && (r2 == '9') && (r5 == '9')) || ((r1 == '9') && (r3 == '9') && (r4 == '9')) || ((r1 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((r1 == '9') && (r4 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9') && (r4 == '9')) || ((r2 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((r2 == '9') && (r4 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9') && (r5 == '9'))) &&
                 (((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2')) || ((r1 == '2') && (r3 == '2')) ||
                 ((r1 == '2') && (r4 == '2')) || ((r1 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2')) || ((r2 == '2') && (r4 == '2')) ||
                 ((r2 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2')) || ((r3 == '2') && (r5 == '2')) || ((r4 == '2') && (r5 == '2'))) )
            {
                gas[i].prio = 220; strcpy(gas[i].rink,"Pilnas namas (9-2)");
            }
            if ( (((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r5 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r1 == '9') && (r5 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r2 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r4 == '9') && (r5 == '9')) || ((gas[i].reiksme2 == '9') && (r1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9') && (r3 == '9')) || ((gas[i].reiksme2 == '9') && (r1 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9') && (r5 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r3 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9') && (r3 == '9')) || ((r1 == '9') && (r2 == '9') && (r4 == '9')) ||
                 ((r1 == '9') && (r2 == '9') && (r5 == '9')) || ((r1 == '9') && (r3 == '9') && (r4 == '9')) || ((r1 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((r1 == '9') && (r4 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9') && (r4 == '9')) || ((r2 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((r2 == '9') && (r4 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9') && (r5 == '9'))) &&
                 (((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3')) || ((r1 == '3') && (r3 == '3')) ||
                 ((r1 == '3') && (r4 == '3')) || ((r1 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3')) || ((r2 == '3') && (r4 == '3')) ||
                 ((r2 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3')) || ((r3 == '3') && (r5 == '3')) || ((r4 == '3') && (r5 == '3'))) )
            {
                gas[i].prio = 221; strcpy(gas[i].rink,"Pilnas namas (9-3)");
            }
            if ( (((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r5 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r1 == '9') && (r5 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r2 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r4 == '9') && (r5 == '9')) || ((gas[i].reiksme2 == '9') && (r1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9') && (r3 == '9')) || ((gas[i].reiksme2 == '9') && (r1 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9') && (r5 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r3 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9') && (r3 == '9')) || ((r1 == '9') && (r2 == '9') && (r4 == '9')) ||
                 ((r1 == '9') && (r2 == '9') && (r5 == '9')) || ((r1 == '9') && (r3 == '9') && (r4 == '9')) || ((r1 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((r1 == '9') && (r4 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9') && (r4 == '9')) || ((r2 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((r2 == '9') && (r4 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9') && (r5 == '9'))) &&
                 (((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4')) || ((r1 == '4') && (r3 == '4')) ||
                 ((r1 == '4') && (r4 == '4')) || ((r1 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4')) || ((r2 == '4') && (r4 == '4')) ||
                 ((r2 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4')) || ((r3 == '4') && (r5 == '4')) || ((r4 == '4') && (r5 == '4'))) )
            {
                gas[i].prio = 222; strcpy(gas[i].rink,"Pilnas namas (9-4)");
            }
            if ( (((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r5 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r1 == '9') && (r5 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r2 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r4 == '9') && (r5 == '9')) || ((gas[i].reiksme2 == '9') && (r1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9') && (r3 == '9')) || ((gas[i].reiksme2 == '9') && (r1 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9') && (r5 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r3 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9') && (r3 == '9')) || ((r1 == '9') && (r2 == '9') && (r4 == '9')) ||
                 ((r1 == '9') && (r2 == '9') && (r5 == '9')) || ((r1 == '9') && (r3 == '9') && (r4 == '9')) || ((r1 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((r1 == '9') && (r4 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9') && (r4 == '9')) || ((r2 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((r2 == '9') && (r4 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9') && (r5 == '9'))) &&
                 (((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5')) || ((r1 == '5') && (r3 == '5')) ||
                 ((r1 == '5') && (r4 == '5')) || ((r1 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5')) || ((r2 == '5') && (r4 == '5')) ||
                 ((r2 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5')) || ((r3 == '5') && (r5 == '5')) || ((r4 == '5') && (r5 == '5'))) )
            {
                gas[i].prio = 223; strcpy(gas[i].rink,"Pilnas namas (9-5)");
            }
            if ( (((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r5 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r1 == '9') && (r5 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r2 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r4 == '9') && (r5 == '9')) || ((gas[i].reiksme2 == '9') && (r1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9') && (r3 == '9')) || ((gas[i].reiksme2 == '9') && (r1 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9') && (r5 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r3 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9') && (r3 == '9')) || ((r1 == '9') && (r2 == '9') && (r4 == '9')) ||
                 ((r1 == '9') && (r2 == '9') && (r5 == '9')) || ((r1 == '9') && (r3 == '9') && (r4 == '9')) || ((r1 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((r1 == '9') && (r4 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9') && (r4 == '9')) || ((r2 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((r2 == '9') && (r4 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9') && (r5 == '9'))) &&
                 (((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6')) || ((r1 == '6') && (r3 == '6')) ||
                 ((r1 == '6') && (r4 == '6')) || ((r1 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6')) || ((r2 == '6') && (r4 == '6')) ||
                 ((r2 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6')) || ((r3 == '6') && (r5 == '6')) || ((r4 == '6') && (r5 == '6'))) )
            {
                gas[i].prio = 224; strcpy(gas[i].rink,"Pilnas namas (9-6)");
            }
            if ( (((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r5 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r1 == '9') && (r5 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r2 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r4 == '9') && (r5 == '9')) || ((gas[i].reiksme2 == '9') && (r1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9') && (r3 == '9')) || ((gas[i].reiksme2 == '9') && (r1 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9') && (r5 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r3 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9') && (r3 == '9')) || ((r1 == '9') && (r2 == '9') && (r4 == '9')) ||
                 ((r1 == '9') && (r2 == '9') && (r5 == '9')) || ((r1 == '9') && (r3 == '9') && (r4 == '9')) || ((r1 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((r1 == '9') && (r4 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9') && (r4 == '9')) || ((r2 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((r2 == '9') && (r4 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9') && (r5 == '9'))) &&
                 (((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7')) || ((r1 == '7') && (r3 == '7')) ||
                 ((r1 == '7') && (r4 == '7')) || ((r1 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7')) || ((r2 == '7') && (r4 == '7')) ||
                 ((r2 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7')) || ((r3 == '7') && (r5 == '7')) || ((r4 == '7') && (r5 == '7'))) )
            {
                gas[i].prio = 225; strcpy(gas[i].rink,"Pilnas namas (9-7)");
            }
            if ( (((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r5 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r1 == '9') && (r5 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r2 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r4 == '9') && (r5 == '9')) || ((gas[i].reiksme2 == '9') && (r1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9') && (r3 == '9')) || ((gas[i].reiksme2 == '9') && (r1 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9') && (r5 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r3 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9') && (r3 == '9')) || ((r1 == '9') && (r2 == '9') && (r4 == '9')) ||
                 ((r1 == '9') && (r2 == '9') && (r5 == '9')) || ((r1 == '9') && (r3 == '9') && (r4 == '9')) || ((r1 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((r1 == '9') && (r4 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9') && (r4 == '9')) || ((r2 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((r2 == '9') && (r4 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9') && (r5 == '9'))) &&
                 (((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8')) || ((r1 == '8') && (r3 == '8')) ||
                 ((r1 == '8') && (r4 == '8')) || ((r1 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8')) || ((r2 == '8') && (r4 == '8')) ||
                 ((r2 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8')) || ((r3 == '8') && (r5 == '8')) || ((r4 == '8') && (r5 == '8'))) )
            {
                gas[i].prio = 226; strcpy(gas[i].rink,"Pilnas namas (9-8)");
            }
            if ( (((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r5 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r1 == '9') && (r5 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r2 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r4 == '9') && (r5 == '9')) || ((gas[i].reiksme2 == '9') && (r1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9') && (r3 == '9')) || ((gas[i].reiksme2 == '9') && (r1 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9') && (r5 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r3 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9') && (r3 == '9')) || ((r1 == '9') && (r2 == '9') && (r4 == '9')) ||
                 ((r1 == '9') && (r2 == '9') && (r5 == '9')) || ((r1 == '9') && (r3 == '9') && (r4 == '9')) || ((r1 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((r1 == '9') && (r4 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9') && (r4 == '9')) || ((r2 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((r2 == '9') && (r4 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9') && (r5 == '9'))) &&
                 (((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T')) || ((r1 == 'T') && (r3 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T')) || ((r2 == 'T') && (r4 == 'T')) ||
                 ((r2 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T')) || ((r3 == 'T') && (r5 == 'T')) || ((r4 == 'T') && (r5 == 'T'))) )
            {
                gas[i].prio = 227; strcpy(gas[i].rink,"Pilnas namas (9-T)");
            }
            if ( (((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r5 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r1 == '9') && (r5 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r2 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r4 == '9') && (r5 == '9')) || ((gas[i].reiksme2 == '9') && (r1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9') && (r3 == '9')) || ((gas[i].reiksme2 == '9') && (r1 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9') && (r5 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r3 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9') && (r3 == '9')) || ((r1 == '9') && (r2 == '9') && (r4 == '9')) ||
                 ((r1 == '9') && (r2 == '9') && (r5 == '9')) || ((r1 == '9') && (r3 == '9') && (r4 == '9')) || ((r1 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((r1 == '9') && (r4 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9') && (r4 == '9')) || ((r2 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((r2 == '9') && (r4 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9') && (r5 == '9'))) &&
                 (((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J')) || ((r1 == 'J') && (r3 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J')) || ((r2 == 'J') && (r4 == 'J')) ||
                 ((r2 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J')) || ((r3 == 'J') && (r5 == 'J')) || ((r4 == 'J') && (r5 == 'J'))) )
            {
                gas[i].prio = 228; strcpy(gas[i].rink,"Pilnas namas (9-J)");
            }
            if ( (((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r5 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r1 == '9') && (r5 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r2 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r4 == '9') && (r5 == '9')) || ((gas[i].reiksme2 == '9') && (r1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9') && (r3 == '9')) || ((gas[i].reiksme2 == '9') && (r1 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9') && (r5 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r3 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9') && (r3 == '9')) || ((r1 == '9') && (r2 == '9') && (r4 == '9')) ||
                 ((r1 == '9') && (r2 == '9') && (r5 == '9')) || ((r1 == '9') && (r3 == '9') && (r4 == '9')) || ((r1 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((r1 == '9') && (r4 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9') && (r4 == '9')) || ((r2 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((r2 == '9') && (r4 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9') && (r5 == '9'))) &&
                 (((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q')) || ((r2 == 'Q') && (r4 == 'Q')) ||
                 ((r2 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q')) || ((r3 == 'Q') && (r5 == 'Q')) || ((r4 == 'Q') && (r5 == 'Q'))) )
            {
                gas[i].prio = 229; strcpy(gas[i].rink,"Pilnas namas (9-Q)");
            }
            if ( (((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r5 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r1 == '9') && (r5 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r2 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r4 == '9') && (r5 == '9')) || ((gas[i].reiksme2 == '9') && (r1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9') && (r3 == '9')) || ((gas[i].reiksme2 == '9') && (r1 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9') && (r5 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r3 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9') && (r3 == '9')) || ((r1 == '9') && (r2 == '9') && (r4 == '9')) ||
                 ((r1 == '9') && (r2 == '9') && (r5 == '9')) || ((r1 == '9') && (r3 == '9') && (r4 == '9')) || ((r1 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((r1 == '9') && (r4 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9') && (r4 == '9')) || ((r2 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((r2 == '9') && (r4 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9') && (r5 == '9'))) &&
                 (((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K')) || ((r1 == 'K') && (r3 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K')) || ((r2 == 'K') && (r4 == 'K')) ||
                 ((r2 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K')) || ((r3 == 'K') && (r5 == 'K')) || ((r4 == 'K') && (r5 == 'K'))) )
            {
                gas[i].prio = 230; strcpy(gas[i].rink,"Pilnas namas (9-K)");
            }
            if ( (((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9') && (r5 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r1 == '9') && (r5 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r2 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r4 == '9') && (r5 == '9')) || ((gas[i].reiksme2 == '9') && (r1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9') && (r3 == '9')) || ((gas[i].reiksme2 == '9') && (r1 == '9') && (r4 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9') && (r5 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r3 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9') && (r3 == '9')) || ((r1 == '9') && (r2 == '9') && (r4 == '9')) ||
                 ((r1 == '9') && (r2 == '9') && (r5 == '9')) || ((r1 == '9') && (r3 == '9') && (r4 == '9')) || ((r1 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((r1 == '9') && (r4 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9') && (r4 == '9')) || ((r2 == '9') && (r3 == '9') && (r5 == '9')) ||
                 ((r2 == '9') && (r4 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9') && (r5 == '9'))) &&
                 (((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A')) || ((r1 == 'A') && (r3 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A')) || ((r2 == 'A') && (r4 == 'A')) ||
                 ((r2 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A')) || ((r3 == 'A') && (r5 == 'A')) || ((r4 == 'A') && (r5 == 'A'))) )
            {
                gas[i].prio = 231; strcpy(gas[i].rink,"Pilnas namas (9-A)");
            }
            if ( (((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r5 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r5 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T') && (r3 == 'T')) || ((r1 == 'T') && (r2 == 'T') && (r4 == 'T')) ||
                 ((r1 == 'T') && (r2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((r2 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((r2 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T') && (r5 == 'T'))) &&
                 (((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2')) || ((r1 == '2') && (r3 == '2')) ||
                 ((r1 == '2') && (r4 == '2')) || ((r1 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2')) || ((r2 == '2') && (r4 == '2')) ||
                 ((r2 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2')) || ((r3 == '2') && (r5 == '2')) || ((r4 == '2') && (r5 == '2'))) )
            {
                gas[i].prio = 232; strcpy(gas[i].rink,"Pilnas namas (T-2)");
            }
            if ( (((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r5 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r5 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T') && (r3 == 'T')) || ((r1 == 'T') && (r2 == 'T') && (r4 == 'T')) ||
                 ((r1 == 'T') && (r2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((r2 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((r2 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T') && (r5 == 'T'))) &&
                 (((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3')) || ((r1 == '3') && (r3 == '3')) ||
                 ((r1 == '3') && (r4 == '3')) || ((r1 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3')) || ((r2 == '3') && (r4 == '3')) ||
                 ((r2 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3')) || ((r3 == '3') && (r5 == '3')) || ((r4 == '3') && (r5 == '3'))) )
            {
                gas[i].prio = 233; strcpy(gas[i].rink,"Pilnas namas (T-3)");
            }
            if ( (((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r5 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r5 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T') && (r3 == 'T')) || ((r1 == 'T') && (r2 == 'T') && (r4 == 'T')) ||
                 ((r1 == 'T') && (r2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((r2 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((r2 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T') && (r5 == 'T'))) &&
                 (((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4')) || ((r1 == '4') && (r3 == '4')) ||
                 ((r1 == '4') && (r4 == '4')) || ((r1 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4')) || ((r2 == '4') && (r4 == '4')) ||
                 ((r2 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4')) || ((r3 == '4') && (r5 == '4')) || ((r4 == '4') && (r5 == '4'))) )
            {
                gas[i].prio = 234; strcpy(gas[i].rink,"Pilnas namas (T-4)");
            }
            if ( (((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r5 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r5 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T') && (r3 == 'T')) || ((r1 == 'T') && (r2 == 'T') && (r4 == 'T')) ||
                 ((r1 == 'T') && (r2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((r2 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((r2 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T') && (r5 == 'T'))) &&
                 (((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5')) || ((r1 == '5') && (r3 == '5')) ||
                 ((r1 == '5') && (r4 == '5')) || ((r1 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5')) || ((r2 == '5') && (r4 == '5')) ||
                 ((r2 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5')) || ((r3 == '5') && (r5 == '5')) || ((r4 == '5') && (r5 == '5'))) )
            {
                gas[i].prio = 235; strcpy(gas[i].rink,"Pilnas namas (T-5)");
            }
            if ( (((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r5 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r5 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T') && (r3 == 'T')) || ((r1 == 'T') && (r2 == 'T') && (r4 == 'T')) ||
                 ((r1 == 'T') && (r2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((r2 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((r2 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T') && (r5 == 'T'))) &&
                 (((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6')) || ((r1 == '6') && (r3 == '6')) ||
                 ((r1 == '6') && (r4 == '6')) || ((r1 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6')) || ((r2 == '6') && (r4 == '6')) ||
                 ((r2 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6')) || ((r3 == '6') && (r5 == '6')) || ((r4 == '6') && (r5 == '6'))) )
            {
                gas[i].prio = 236; strcpy(gas[i].rink,"Pilnas namas (T-6)");
            }
            if ( (((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r5 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r5 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T') && (r3 == 'T')) || ((r1 == 'T') && (r2 == 'T') && (r4 == 'T')) ||
                 ((r1 == 'T') && (r2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((r2 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((r2 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T') && (r5 == 'T'))) &&
                 (((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7')) || ((r1 == '7') && (r3 == '7')) ||
                 ((r1 == '7') && (r4 == '7')) || ((r1 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7')) || ((r2 == '7') && (r4 == '7')) ||
                 ((r2 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7')) || ((r3 == '7') && (r5 == '7')) || ((r4 == '7') && (r5 == '7'))) )
            {
                gas[i].prio = 237; strcpy(gas[i].rink,"Pilnas namas (T-7)");
            }
            if ( (((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r5 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r5 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T') && (r3 == 'T')) || ((r1 == 'T') && (r2 == 'T') && (r4 == 'T')) ||
                 ((r1 == 'T') && (r2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((r2 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((r2 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T') && (r5 == 'T'))) &&
                 (((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8')) || ((r1 == '8') && (r3 == '8')) ||
                 ((r1 == '8') && (r4 == '8')) || ((r1 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8')) || ((r2 == '8') && (r4 == '8')) ||
                 ((r2 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8')) || ((r3 == '8') && (r5 == '8')) || ((r4 == '8') && (r5 == '8'))) )
            {
                gas[i].prio = 238; strcpy(gas[i].rink,"Pilnas namas (T-8)");
            }
            if ( (((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r5 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r5 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T') && (r3 == 'T')) || ((r1 == 'T') && (r2 == 'T') && (r4 == 'T')) ||
                 ((r1 == 'T') && (r2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((r2 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((r2 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T') && (r5 == 'T'))) &&
                 (((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9')) || ((r1 == '9') && (r3 == '9')) ||
                 ((r1 == '9') && (r4 == '9')) || ((r1 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9')) || ((r2 == '9') && (r4 == '9')) ||
                 ((r2 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9')) || ((r3 == '9') && (r5 == '9')) || ((r4 == '9') && (r5 == '9'))) )
            {
                gas[i].prio = 239; strcpy(gas[i].rink,"Pilnas namas (T-9)");
            }
            if ( (((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r5 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r5 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T') && (r3 == 'T')) || ((r1 == 'T') && (r2 == 'T') && (r4 == 'T')) ||
                 ((r1 == 'T') && (r2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((r2 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((r2 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T') && (r5 == 'T'))) &&
                 (((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J')) || ((r1 == 'J') && (r3 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J')) || ((r2 == 'J') && (r4 == 'J')) ||
                 ((r2 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J')) || ((r3 == 'J') && (r5 == 'J')) || ((r4 == 'J') && (r5 == 'J'))) )
            {
                gas[i].prio = 240; strcpy(gas[i].rink,"Pilnas namas (T-J)");
            }
            if ( (((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r5 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r5 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T') && (r3 == 'T')) || ((r1 == 'T') && (r2 == 'T') && (r4 == 'T')) ||
                 ((r1 == 'T') && (r2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((r2 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((r2 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T') && (r5 == 'T'))) &&
                 (((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q')) || ((r2 == 'Q') && (r4 == 'Q')) ||
                 ((r2 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q')) || ((r3 == 'Q') && (r5 == 'Q')) || ((r4 == 'Q') && (r5 == 'Q'))) )
            {
                gas[i].prio = 241; strcpy(gas[i].rink,"Pilnas namas (T-Q)");
            }
            if ( (((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r5 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r5 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T') && (r3 == 'T')) || ((r1 == 'T') && (r2 == 'T') && (r4 == 'T')) ||
                 ((r1 == 'T') && (r2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((r2 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((r2 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T') && (r5 == 'T'))) &&
                 (((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K')) || ((r1 == 'K') && (r3 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K')) || ((r2 == 'K') && (r4 == 'K')) ||
                 ((r2 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K')) || ((r3 == 'K') && (r5 == 'K')) || ((r4 == 'K') && (r5 == 'K'))) )
            {
                gas[i].prio = 242; strcpy(gas[i].rink,"Pilnas namas (T-K)");
            }
            if ( (((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r1 == 'T') && (r5 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r4 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T') && (r5 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T') && (r3 == 'T')) || ((r1 == 'T') && (r2 == 'T') && (r4 == 'T')) ||
                 ((r1 == 'T') && (r2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T') && (r4 == 'T')) || ((r2 == 'T') && (r3 == 'T') && (r5 == 'T')) ||
                 ((r2 == 'T') && (r4 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T') && (r5 == 'T'))) &&
                 (((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A')) || ((r1 == 'A') && (r3 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A')) || ((r2 == 'A') && (r4 == 'A')) ||
                 ((r2 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A')) || ((r3 == 'A') && (r5 == 'A')) || ((r4 == 'A') && (r5 == 'A'))) )
            {
                gas[i].prio = 243; strcpy(gas[i].rink,"Pilnas namas (T-A)");
            }
            if ( (((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r5 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r5 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J') && (r3 == 'J')) || ((r1 == 'J') && (r2 == 'J') && (r4 == 'J')) ||
                 ((r1 == 'J') && (r2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((r2 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((r2 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J') && (r5 == 'J'))) &&
                 (((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2')) || ((r1 == '2') && (r3 == '2')) ||
                 ((r1 == '2') && (r4 == '2')) || ((r1 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2')) || ((r2 == '2') && (r4 == '2')) ||
                 ((r2 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2')) || ((r3 == '2') && (r5 == '2')) || ((r4 == '2') && (r5 == '2'))) )
            {
                gas[i].prio = 244; strcpy(gas[i].rink,"Pilnas namas (J-2)");
            }
            if ( (((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r5 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r5 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J') && (r3 == 'J')) || ((r1 == 'J') && (r2 == 'J') && (r4 == 'J')) ||
                 ((r1 == 'J') && (r2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((r2 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((r2 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J') && (r5 == 'J'))) &&
                 (((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3')) || ((r1 == '3') && (r3 == '3')) ||
                 ((r1 == '3') && (r4 == '3')) || ((r1 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3')) || ((r2 == '3') && (r4 == '3')) ||
                 ((r2 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3')) || ((r3 == '3') && (r5 == '3')) || ((r4 == '3') && (r5 == '3'))) )
            {
                gas[i].prio = 245; strcpy(gas[i].rink,"Pilnas namas (J-3)");
            }
            if ( (((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r5 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r5 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J') && (r3 == 'J')) || ((r1 == 'J') && (r2 == 'J') && (r4 == 'J')) ||
                 ((r1 == 'J') && (r2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((r2 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((r2 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J') && (r5 == 'J'))) &&
                 (((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4')) || ((r1 == '4') && (r3 == '4')) ||
                 ((r1 == '4') && (r4 == '4')) || ((r1 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4')) || ((r2 == '4') && (r4 == '4')) ||
                 ((r2 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4')) || ((r3 == '4') && (r5 == '4')) || ((r4 == '4') && (r5 == '4'))) )
            {
                gas[i].prio = 246; strcpy(gas[i].rink,"Pilnas namas (J-4)");
            }
            if ( (((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r5 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r5 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J') && (r3 == 'J')) || ((r1 == 'J') && (r2 == 'J') && (r4 == 'J')) ||
                 ((r1 == 'J') && (r2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((r2 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((r2 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J') && (r5 == 'J'))) &&
                 (((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5')) || ((r1 == '5') && (r3 == '5')) ||
                 ((r1 == '5') && (r4 == '5')) || ((r1 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5')) || ((r2 == '5') && (r4 == '5')) ||
                 ((r2 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5')) || ((r3 == '5') && (r5 == '5')) || ((r4 == '5') && (r5 == '5'))) )
            {
                gas[i].prio = 247; strcpy(gas[i].rink,"Pilnas namas (J-5)");
            }
            if ( (((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r5 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r5 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J') && (r3 == 'J')) || ((r1 == 'J') && (r2 == 'J') && (r4 == 'J')) ||
                 ((r1 == 'J') && (r2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((r2 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((r2 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J') && (r5 == 'J'))) &&
                 (((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6')) || ((r1 == '6') && (r3 == '6')) ||
                 ((r1 == '6') && (r4 == '6')) || ((r1 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6')) || ((r2 == '6') && (r4 == '6')) ||
                 ((r2 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6')) || ((r3 == '6') && (r5 == '6')) || ((r4 == '6') && (r5 == '6'))) )
            {
                gas[i].prio = 248; strcpy(gas[i].rink,"Pilnas namas (J-6)");
            }
            if ( (((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r5 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r5 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J') && (r3 == 'J')) || ((r1 == 'J') && (r2 == 'J') && (r4 == 'J')) ||
                 ((r1 == 'J') && (r2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((r2 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((r2 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J') && (r5 == 'J'))) &&
                 (((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7')) || ((r1 == '7') && (r3 == '7')) ||
                 ((r1 == '7') && (r4 == '7')) || ((r1 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7')) || ((r2 == '7') && (r4 == '7')) ||
                 ((r2 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7')) || ((r3 == '7') && (r5 == '7')) || ((r4 == '7') && (r5 == '7'))) )
            {
                gas[i].prio = 249; strcpy(gas[i].rink,"Pilnas namas (J-7)");
            }
            if ( (((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r5 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r5 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J') && (r3 == 'J')) || ((r1 == 'J') && (r2 == 'J') && (r4 == 'J')) ||
                 ((r1 == 'J') && (r2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((r2 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((r2 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J') && (r5 == 'J'))) &&
                 (((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8')) || ((r1 == '8') && (r3 == '8')) ||
                 ((r1 == '8') && (r4 == '8')) || ((r1 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8')) || ((r2 == '8') && (r4 == '8')) ||
                 ((r2 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8')) || ((r3 == '8') && (r5 == '8')) || ((r4 == '8') && (r5 == '8'))) )
            {
                gas[i].prio = 250; strcpy(gas[i].rink,"Pilnas namas (J-8)");
            }
            if ( (((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r5 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r5 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J') && (r3 == 'J')) || ((r1 == 'J') && (r2 == 'J') && (r4 == 'J')) ||
                 ((r1 == 'J') && (r2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((r2 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((r2 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J') && (r5 == 'J'))) &&
                 (((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9')) || ((r1 == '9') && (r3 == '9')) ||
                 ((r1 == '9') && (r4 == '9')) || ((r1 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9')) || ((r2 == '9') && (r4 == '9')) ||
                 ((r2 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9')) || ((r3 == '9') && (r5 == '9')) || ((r4 == '9') && (r5 == '9'))) )
            {
                gas[i].prio = 251; strcpy(gas[i].rink,"Pilnas namas (J-9)");
            }
            if ( (((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r5 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r5 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J') && (r3 == 'J')) || ((r1 == 'J') && (r2 == 'J') && (r4 == 'J')) ||
                 ((r1 == 'J') && (r2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((r2 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((r2 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J') && (r5 == 'J'))) &&
                 (((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T')) || ((r1 == 'T') && (r3 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T')) || ((r2 == 'T') && (r4 == 'T')) ||
                 ((r2 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T')) || ((r3 == 'T') && (r5 == 'T')) || ((r4 == 'T') && (r5 == 'T'))) )
            {
                gas[i].prio = 252; strcpy(gas[i].rink,"Pilnas namas (J-T)");
            }
            if ( (((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r5 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r5 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J') && (r3 == 'J')) || ((r1 == 'J') && (r2 == 'J') && (r4 == 'J')) ||
                 ((r1 == 'J') && (r2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((r2 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((r2 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J') && (r5 == 'J'))) &&
                 (((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q')) || ((r2 == 'Q') && (r4 == 'Q')) ||
                 ((r2 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q')) || ((r3 == 'Q') && (r5 == 'Q')) || ((r4 == 'Q') && (r5 == 'Q'))) )
            {
                gas[i].prio = 253; strcpy(gas[i].rink,"Pilnas namas (J-Q)");
            }
            if ( (((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r5 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r5 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J') && (r3 == 'J')) || ((r1 == 'J') && (r2 == 'J') && (r4 == 'J')) ||
                 ((r1 == 'J') && (r2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((r2 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((r2 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J') && (r5 == 'J'))) &&
                 (((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K')) || ((r1 == 'K') && (r3 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K')) || ((r2 == 'K') && (r4 == 'K')) ||
                 ((r2 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K')) || ((r3 == 'K') && (r5 == 'K')) || ((r4 == 'K') && (r5 == 'K'))) )
            {
                gas[i].prio = 254; strcpy(gas[i].rink,"Pilnas namas (J-K)");
            }
            if ( (((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r1 == 'J') && (r5 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r4 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J') && (r5 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J') && (r3 == 'J')) || ((r1 == 'J') && (r2 == 'J') && (r4 == 'J')) ||
                 ((r1 == 'J') && (r2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J') && (r4 == 'J')) || ((r2 == 'J') && (r3 == 'J') && (r5 == 'J')) ||
                 ((r2 == 'J') && (r4 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J') && (r5 == 'J'))) &&
                 (((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A')) || ((r1 == 'A') && (r3 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A')) || ((r2 == 'A') && (r4 == 'A')) ||
                 ((r2 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A')) || ((r3 == 'A') && (r5 == 'A')) || ((r4 == 'A') && (r5 == 'A'))) )
            {
                gas[i].prio = 255; strcpy(gas[i].rink,"Pilnas namas (J-A)");
            }
            if ( (((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) ||
                 ((r1 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((r2 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q') && (r5 == 'Q'))) &&
                 (((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2')) || ((r1 == '2') && (r3 == '2')) ||
                 ((r1 == '2') && (r4 == '2')) || ((r1 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2')) || ((r2 == '2') && (r4 == '2')) ||
                 ((r2 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2')) || ((r3 == '2') && (r5 == '2')) || ((r4 == '2') && (r5 == '2'))) )
            {
                gas[i].prio = 256; strcpy(gas[i].rink,"Pilnas namas (Q-2)");
            }
            if ( (((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) ||
                 ((r1 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((r2 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q') && (r5 == 'Q'))) &&
                 (((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3')) || ((r1 == '3') && (r3 == '3')) ||
                 ((r1 == '3') && (r4 == '3')) || ((r1 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3')) || ((r2 == '3') && (r4 == '3')) ||
                 ((r2 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3')) || ((r3 == '3') && (r5 == '3')) || ((r4 == '3') && (r5 == '3'))) )
            {
                gas[i].prio = 257; strcpy(gas[i].rink,"Pilnas namas (Q-3)");
            }
            if ( (((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) ||
                 ((r1 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((r2 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q') && (r5 == 'Q'))) &&
                 (((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4')) || ((r1 == '4') && (r3 == '4')) ||
                 ((r1 == '4') && (r4 == '4')) || ((r1 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4')) || ((r2 == '4') && (r4 == '4')) ||
                 ((r2 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4')) || ((r3 == '4') && (r5 == '4')) || ((r4 == '4') && (r5 == '4'))) )
            {
                gas[i].prio = 258; strcpy(gas[i].rink,"Pilnas namas (Q-4)");
            }
            if ( (((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) ||
                 ((r1 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((r2 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q') && (r5 == 'Q'))) &&
                 (((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5')) || ((r1 == '5') && (r3 == '5')) ||
                 ((r1 == '5') && (r4 == '5')) || ((r1 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5')) || ((r2 == '5') && (r4 == '5')) ||
                 ((r2 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5')) || ((r3 == '5') && (r5 == '5')) || ((r4 == '5') && (r5 == '5'))) )
            {
                gas[i].prio = 259; strcpy(gas[i].rink,"Pilnas namas (Q-5)");
            }
            if ( (((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) ||
                 ((r1 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((r2 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q') && (r5 == 'Q'))) &&
                 (((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6')) || ((r1 == '6') && (r3 == '6')) ||
                 ((r1 == '6') && (r4 == '6')) || ((r1 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6')) || ((r2 == '6') && (r4 == '6')) ||
                 ((r2 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6')) || ((r3 == '6') && (r5 == '6')) || ((r4 == '6') && (r5 == '6'))) )
            {
                gas[i].prio = 260; strcpy(gas[i].rink,"Pilnas namas (Q-6)");
            }
            if ( (((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) ||
                 ((r1 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((r2 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q') && (r5 == 'Q'))) &&
                 (((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7')) || ((r1 == '7') && (r3 == '7')) ||
                 ((r1 == '7') && (r4 == '7')) || ((r1 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7')) || ((r2 == '7') && (r4 == '7')) ||
                 ((r2 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7')) || ((r3 == '7') && (r5 == '7')) || ((r4 == '7') && (r5 == '7'))) )
            {
                gas[i].prio = 261; strcpy(gas[i].rink,"Pilnas namas (Q-7)");
            }
            if ( (((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) ||
                 ((r1 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((r2 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q') && (r5 == 'Q'))) &&
                 (((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8')) || ((r1 == '8') && (r3 == '8')) ||
                 ((r1 == '8') && (r4 == '8')) || ((r1 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8')) || ((r2 == '8') && (r4 == '8')) ||
                 ((r2 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8')) || ((r3 == '8') && (r5 == '8')) || ((r4 == '8') && (r5 == '8'))) )
            {
                gas[i].prio = 262; strcpy(gas[i].rink,"Pilnas namas (Q-8)");
            }
            if ( (((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) ||
                 ((r1 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((r2 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q') && (r5 == 'Q'))) &&
                 (((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9')) || ((r1 == '9') && (r3 == '9')) ||
                 ((r1 == '9') && (r4 == '9')) || ((r1 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9')) || ((r2 == '9') && (r4 == '9')) ||
                 ((r2 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9')) || ((r3 == '9') && (r5 == '9')) || ((r4 == '9') && (r5 == '9'))) )
            {
                gas[i].prio = 263; strcpy(gas[i].rink,"Pilnas namas (Q-9)");
            }
            if ( (((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) ||
                 ((r1 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((r2 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q') && (r5 == 'Q'))) &&
                 (((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T')) || ((r1 == 'T') && (r3 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T')) || ((r2 == 'T') && (r4 == 'T')) ||
                 ((r2 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T')) || ((r3 == 'T') && (r5 == 'T')) || ((r4 == 'T') && (r5 == 'T'))) )
            {
                gas[i].prio = 264; strcpy(gas[i].rink,"Pilnas namas (Q-T)");
            }
            if ( (((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) ||
                 ((r1 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((r2 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q') && (r5 == 'Q'))) &&
                 (((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J')) || ((r1 == 'J') && (r3 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J')) || ((r2 == 'J') && (r4 == 'J')) ||
                 ((r2 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J')) || ((r3 == 'J') && (r5 == 'J')) || ((r4 == 'J') && (r5 == 'J'))) )
            {
                gas[i].prio = 265; strcpy(gas[i].rink,"Pilnas namas (Q-J)");
            }
            if ( (((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) ||
                 ((r1 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((r2 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q') && (r5 == 'Q'))) &&
                 (((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K')) || ((r1 == 'K') && (r3 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K')) || ((r2 == 'K') && (r4 == 'K')) ||
                 ((r2 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K')) || ((r3 == 'K') && (r5 == 'K')) || ((r4 == 'K') && (r5 == 'K'))) )
            {
                gas[i].prio = 266; strcpy(gas[i].rink,"Pilnas namas (Q-K)");
            }
            if ( (((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r1 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r4 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q') && (r5 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q') && (r3 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q') && (r4 == 'Q')) ||
                 ((r1 == 'Q') && (r2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q') && (r4 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q') && (r5 == 'Q')) ||
                 ((r2 == 'Q') && (r4 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q') && (r5 == 'Q'))) &&
                 (((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A')) || ((r1 == 'A') && (r3 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A')) || ((r2 == 'A') && (r4 == 'A')) ||
                 ((r2 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A')) || ((r3 == 'A') && (r5 == 'A')) || ((r4 == 'A') && (r5 == 'A'))) )
            {
                gas[i].prio = 267; strcpy(gas[i].rink,"Pilnas namas (Q-A)");
            }
            if ( (((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r5 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r5 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K') && (r3 == 'K')) || ((r1 == 'K') && (r2 == 'K') && (r4 == 'K')) ||
                 ((r1 == 'K') && (r2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((r2 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((r2 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K') && (r5 == 'K'))) &&
                 (((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2')) || ((r1 == '2') && (r3 == '2')) ||
                 ((r1 == '2') && (r4 == '2')) || ((r1 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2')) || ((r2 == '2') && (r4 == '2')) ||
                 ((r2 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2')) || ((r3 == '2') && (r5 == '2')) || ((r4 == '2') && (r5 == '2'))) )
            {
                gas[i].prio = 268; strcpy(gas[i].rink,"Pilnas namas (K-2)");
            }
            if ( (((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r5 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r5 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K') && (r3 == 'K')) || ((r1 == 'K') && (r2 == 'K') && (r4 == 'K')) ||
                 ((r1 == 'K') && (r2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((r2 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((r2 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K') && (r5 == 'K'))) &&
                 (((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3')) || ((r1 == '3') && (r3 == '3')) ||
                 ((r1 == '3') && (r4 == '3')) || ((r1 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3')) || ((r2 == '3') && (r4 == '3')) ||
                 ((r2 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3')) || ((r3 == '3') && (r5 == '3')) || ((r4 == '3') && (r5 == '3'))) )
            {
                gas[i].prio = 269; strcpy(gas[i].rink,"Pilnas namas (K-3)");
            }
            if ( (((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r5 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r5 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K') && (r3 == 'K')) || ((r1 == 'K') && (r2 == 'K') && (r4 == 'K')) ||
                 ((r1 == 'K') && (r2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((r2 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((r2 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K') && (r5 == 'K'))) &&
                 (((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4')) || ((r1 == '4') && (r3 == '4')) ||
                 ((r1 == '4') && (r4 == '4')) || ((r1 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4')) || ((r2 == '4') && (r4 == '4')) ||
                 ((r2 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4')) || ((r3 == '4') && (r5 == '4')) || ((r4 == '4') && (r5 == '4'))) )
            {
                gas[i].prio = 270; strcpy(gas[i].rink,"Pilnas namas (K-4)");
            }
            if ( (((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r5 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r5 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K') && (r3 == 'K')) || ((r1 == 'K') && (r2 == 'K') && (r4 == 'K')) ||
                 ((r1 == 'K') && (r2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((r2 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((r2 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K') && (r5 == 'K'))) &&
                 (((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5')) || ((r1 == '5') && (r3 == '5')) ||
                 ((r1 == '5') && (r4 == '5')) || ((r1 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5')) || ((r2 == '5') && (r4 == '5')) ||
                 ((r2 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5')) || ((r3 == '5') && (r5 == '5')) || ((r4 == '5') && (r5 == '5'))) )
            {
                gas[i].prio = 271; strcpy(gas[i].rink,"Pilnas namas (K-5)");
            }
            if ( (((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r5 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r5 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K') && (r3 == 'K')) || ((r1 == 'K') && (r2 == 'K') && (r4 == 'K')) ||
                 ((r1 == 'K') && (r2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((r2 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((r2 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K') && (r5 == 'K'))) &&
                 (((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6')) || ((r1 == '6') && (r3 == '6')) ||
                 ((r1 == '6') && (r4 == '6')) || ((r1 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6')) || ((r2 == '6') && (r4 == '6')) ||
                 ((r2 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6')) || ((r3 == '6') && (r5 == '6')) || ((r4 == '6') && (r5 == '6'))) )
            {
                gas[i].prio = 272; strcpy(gas[i].rink,"Pilnas namas (K-6)");
            }
            if ( (((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r5 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r5 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K') && (r3 == 'K')) || ((r1 == 'K') && (r2 == 'K') && (r4 == 'K')) ||
                 ((r1 == 'K') && (r2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((r2 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((r2 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K') && (r5 == 'K'))) &&
                 (((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7')) || ((r1 == '7') && (r3 == '7')) ||
                 ((r1 == '7') && (r4 == '7')) || ((r1 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7')) || ((r2 == '7') && (r4 == '7')) ||
                 ((r2 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7')) || ((r3 == '7') && (r5 == '7')) || ((r4 == '7') && (r5 == '7'))) )
            {
                gas[i].prio = 273; strcpy(gas[i].rink,"Pilnas namas (K-7)");
            }
            if ( (((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r5 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r5 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K') && (r3 == 'K')) || ((r1 == 'K') && (r2 == 'K') && (r4 == 'K')) ||
                 ((r1 == 'K') && (r2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((r2 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((r2 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K') && (r5 == 'K'))) &&
                 (((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8')) || ((r1 == '8') && (r3 == '8')) ||
                 ((r1 == '8') && (r4 == '8')) || ((r1 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8')) || ((r2 == '8') && (r4 == '8')) ||
                 ((r2 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8')) || ((r3 == '8') && (r5 == '8')) || ((r4 == '8') && (r5 == '8'))) )
            {
                gas[i].prio = 274; strcpy(gas[i].rink,"Pilnas namas (K-8)");
            }
            if ( (((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r5 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r5 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K') && (r3 == 'K')) || ((r1 == 'K') && (r2 == 'K') && (r4 == 'K')) ||
                 ((r1 == 'K') && (r2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((r2 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((r2 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K') && (r5 == 'K'))) &&
                 (((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9')) || ((r1 == '9') && (r3 == '9')) ||
                 ((r1 == '9') && (r4 == '9')) || ((r1 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9')) || ((r2 == '9') && (r4 == '9')) ||
                 ((r2 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9')) || ((r3 == '9') && (r5 == '9')) || ((r4 == '9') && (r5 == '9'))) )
            {
                gas[i].prio = 275; strcpy(gas[i].rink,"Pilnas namas (K-9)");
            }
            if ( (((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r5 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r5 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K') && (r3 == 'K')) || ((r1 == 'K') && (r2 == 'K') && (r4 == 'K')) ||
                 ((r1 == 'K') && (r2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((r2 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((r2 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K') && (r5 == 'K'))) &&
                 (((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T')) || ((r1 == 'T') && (r3 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T')) || ((r2 == 'T') && (r4 == 'T')) ||
                 ((r2 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T')) || ((r3 == 'T') && (r5 == 'T')) || ((r4 == 'T') && (r5 == 'T'))) )
            {
                gas[i].prio = 276; strcpy(gas[i].rink,"Pilnas namas (K-T)");
            }
            if ( (((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r5 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r5 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K') && (r3 == 'K')) || ((r1 == 'K') && (r2 == 'K') && (r4 == 'K')) ||
                 ((r1 == 'K') && (r2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((r2 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((r2 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K') && (r5 == 'K'))) &&
                 (((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J')) || ((r1 == 'J') && (r3 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J')) || ((r2 == 'J') && (r4 == 'J')) ||
                 ((r2 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J')) || ((r3 == 'J') && (r5 == 'J')) || ((r4 == 'J') && (r5 == 'J'))) )
            {
                gas[i].prio = 277; strcpy(gas[i].rink,"Pilnas namas (K-J)");
            }
            if ( (((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r5 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r5 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K') && (r3 == 'K')) || ((r1 == 'K') && (r2 == 'K') && (r4 == 'K')) ||
                 ((r1 == 'K') && (r2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((r2 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((r2 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K') && (r5 == 'K'))) &&
                 (((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q')) || ((r2 == 'Q') && (r4 == 'Q')) ||
                 ((r2 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q')) || ((r3 == 'Q') && (r5 == 'Q')) || ((r4 == 'Q') && (r5 == 'Q'))) )
            {
                gas[i].prio = 278; strcpy(gas[i].rink,"Pilnas namas (K-Q)");
            }
            if ( (((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r1 == 'K') && (r5 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r4 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K') && (r5 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K') && (r3 == 'K')) || ((r1 == 'K') && (r2 == 'K') && (r4 == 'K')) ||
                 ((r1 == 'K') && (r2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K') && (r4 == 'K')) || ((r2 == 'K') && (r3 == 'K') && (r5 == 'K')) ||
                 ((r2 == 'K') && (r4 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K') && (r5 == 'K'))) &&
                 (((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A')) || ((r1 == 'A') && (r3 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A')) || ((r2 == 'A') && (r4 == 'A')) ||
                 ((r2 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A')) || ((r3 == 'A') && (r5 == 'A')) || ((r4 == 'A') && (r5 == 'A'))) )
            {
                gas[i].prio = 279; strcpy(gas[i].rink,"Pilnas namas (K-A)");
            }
            if ( (((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r5 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r5 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A') && (r3 == 'A')) || ((r1 == 'A') && (r2 == 'A') && (r4 == 'A')) ||
                 ((r1 == 'A') && (r2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((r2 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((r2 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A') && (r5 == 'A'))) &&
                 (((gas[i].reiksme1 == '2') && (gas[i].reiksme2 == '2')) || ((gas[i].reiksme1 == '2') && (r1 == '2')) || ((gas[i].reiksme1 == '2') && (r2 == '2')) ||
                 ((gas[i].reiksme1 == '2') && (r3 == '2')) || ((gas[i].reiksme1 == '2') && (r4 == '2')) || ((gas[i].reiksme1 == '2') && (r5 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r1 == '2')) || ((gas[i].reiksme2 == '2') && (r2 == '2')) || ((gas[i].reiksme2 == '2') && (r3 == '2')) ||
                 ((gas[i].reiksme2 == '2') && (r4 == '2')) || ((gas[i].reiksme2 == '2') && (r5 == '2')) || ((r1 == '2') && (r2 == '2')) || ((r1 == '2') && (r3 == '2')) ||
                 ((r1 == '2') && (r4 == '2')) || ((r1 == '2') && (r5 == '2')) || ((r2 == '2') && (r3 == '2')) || ((r2 == '2') && (r4 == '2')) ||
                 ((r2 == '2') && (r5 == '2')) || ((r3 == '2') && (r4 == '2')) || ((r3 == '2') && (r5 == '2')) || ((r4 == '2') && (r5 == '2'))) )
            {
                gas[i].prio = 280; strcpy(gas[i].rink,"Pilnas namas (A-2)");
            }
            if ( (((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r5 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r5 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A') && (r3 == 'A')) || ((r1 == 'A') && (r2 == 'A') && (r4 == 'A')) ||
                 ((r1 == 'A') && (r2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((r2 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((r2 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A') && (r5 == 'A'))) &&
                 (((gas[i].reiksme1 == '3') && (gas[i].reiksme2 == '3')) || ((gas[i].reiksme1 == '3') && (r1 == '3')) || ((gas[i].reiksme1 == '3') && (r2 == '3')) ||
                 ((gas[i].reiksme1 == '3') && (r3 == '3')) || ((gas[i].reiksme1 == '3') && (r4 == '3')) || ((gas[i].reiksme1 == '3') && (r5 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r1 == '3')) || ((gas[i].reiksme2 == '3') && (r2 == '3')) || ((gas[i].reiksme2 == '3') && (r3 == '3')) ||
                 ((gas[i].reiksme2 == '3') && (r4 == '3')) || ((gas[i].reiksme2 == '3') && (r5 == '3')) || ((r1 == '3') && (r2 == '3')) || ((r1 == '3') && (r3 == '3')) ||
                 ((r1 == '3') && (r4 == '3')) || ((r1 == '3') && (r5 == '3')) || ((r2 == '3') && (r3 == '3')) || ((r2 == '3') && (r4 == '3')) ||
                 ((r2 == '3') && (r5 == '3')) || ((r3 == '3') && (r4 == '3')) || ((r3 == '3') && (r5 == '3')) || ((r4 == '3') && (r5 == '3'))) )
            {
                gas[i].prio = 281; strcpy(gas[i].rink,"Pilnas namas (A-3)");
            }
            if ( (((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r5 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r5 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A') && (r3 == 'A')) || ((r1 == 'A') && (r2 == 'A') && (r4 == 'A')) ||
                 ((r1 == 'A') && (r2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((r2 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((r2 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A') && (r5 == 'A'))) &&
                 (((gas[i].reiksme1 == '4') && (gas[i].reiksme2 == '4')) || ((gas[i].reiksme1 == '4') && (r1 == '4')) || ((gas[i].reiksme1 == '4') && (r2 == '4')) ||
                 ((gas[i].reiksme1 == '4') && (r3 == '4')) || ((gas[i].reiksme1 == '4') && (r4 == '4')) || ((gas[i].reiksme1 == '4') && (r5 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r1 == '4')) || ((gas[i].reiksme2 == '4') && (r2 == '4')) || ((gas[i].reiksme2 == '4') && (r3 == '4')) ||
                 ((gas[i].reiksme2 == '4') && (r4 == '4')) || ((gas[i].reiksme2 == '4') && (r5 == '4')) || ((r1 == '4') && (r2 == '4')) || ((r1 == '4') && (r3 == '4')) ||
                 ((r1 == '4') && (r4 == '4')) || ((r1 == '4') && (r5 == '4')) || ((r2 == '4') && (r3 == '4')) || ((r2 == '4') && (r4 == '4')) ||
                 ((r2 == '4') && (r5 == '4')) || ((r3 == '4') && (r4 == '4')) || ((r3 == '4') && (r5 == '4')) || ((r4 == '4') && (r5 == '4'))) )
            {
                gas[i].prio = 282; strcpy(gas[i].rink,"Pilnas namas (A-4)");
            }
            if ( (((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r5 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r5 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A') && (r3 == 'A')) || ((r1 == 'A') && (r2 == 'A') && (r4 == 'A')) ||
                 ((r1 == 'A') && (r2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((r2 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((r2 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A') && (r5 == 'A'))) &&
                 (((gas[i].reiksme1 == '5') && (gas[i].reiksme2 == '5')) || ((gas[i].reiksme1 == '5') && (r1 == '5')) || ((gas[i].reiksme1 == '5') && (r2 == '5')) ||
                 ((gas[i].reiksme1 == '5') && (r3 == '5')) || ((gas[i].reiksme1 == '5') && (r4 == '5')) || ((gas[i].reiksme1 == '5') && (r5 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r1 == '5')) || ((gas[i].reiksme2 == '5') && (r2 == '5')) || ((gas[i].reiksme2 == '5') && (r3 == '5')) ||
                 ((gas[i].reiksme2 == '5') && (r4 == '5')) || ((gas[i].reiksme2 == '5') && (r5 == '5')) || ((r1 == '5') && (r2 == '5')) || ((r1 == '5') && (r3 == '5')) ||
                 ((r1 == '5') && (r4 == '5')) || ((r1 == '5') && (r5 == '5')) || ((r2 == '5') && (r3 == '5')) || ((r2 == '5') && (r4 == '5')) ||
                 ((r2 == '5') && (r5 == '5')) || ((r3 == '5') && (r4 == '5')) || ((r3 == '5') && (r5 == '5')) || ((r4 == '5') && (r5 == '5'))) )
            {
                gas[i].prio = 283; strcpy(gas[i].rink,"Pilnas namas (A-5)");
            }
            if ( (((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r5 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r5 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A') && (r3 == 'A')) || ((r1 == 'A') && (r2 == 'A') && (r4 == 'A')) ||
                 ((r1 == 'A') && (r2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((r2 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((r2 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A') && (r5 == 'A'))) &&
                 (((gas[i].reiksme1 == '6') && (gas[i].reiksme2 == '6')) || ((gas[i].reiksme1 == '6') && (r1 == '6')) || ((gas[i].reiksme1 == '6') && (r2 == '6')) ||
                 ((gas[i].reiksme1 == '6') && (r3 == '6')) || ((gas[i].reiksme1 == '6') && (r4 == '6')) || ((gas[i].reiksme1 == '6') && (r5 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r1 == '6')) || ((gas[i].reiksme2 == '6') && (r2 == '6')) || ((gas[i].reiksme2 == '6') && (r3 == '6')) ||
                 ((gas[i].reiksme2 == '6') && (r4 == '6')) || ((gas[i].reiksme2 == '6') && (r5 == '6')) || ((r1 == '6') && (r2 == '6')) || ((r1 == '6') && (r3 == '6')) ||
                 ((r1 == '6') && (r4 == '6')) || ((r1 == '6') && (r5 == '6')) || ((r2 == '6') && (r3 == '6')) || ((r2 == '6') && (r4 == '6')) ||
                 ((r2 == '6') && (r5 == '6')) || ((r3 == '6') && (r4 == '6')) || ((r3 == '6') && (r5 == '6')) || ((r4 == '6') && (r5 == '6'))) )
            {
                gas[i].prio = 284; strcpy(gas[i].rink,"Pilnas namas (A-6)");
            }
            if ( (((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r5 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r5 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A') && (r3 == 'A')) || ((r1 == 'A') && (r2 == 'A') && (r4 == 'A')) ||
                 ((r1 == 'A') && (r2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((r2 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((r2 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A') && (r5 == 'A'))) &&
                 (((gas[i].reiksme1 == '7') && (gas[i].reiksme2 == '7')) || ((gas[i].reiksme1 == '7') && (r1 == '7')) || ((gas[i].reiksme1 == '7') && (r2 == '7')) ||
                 ((gas[i].reiksme1 == '7') && (r3 == '7')) || ((gas[i].reiksme1 == '7') && (r4 == '7')) || ((gas[i].reiksme1 == '7') && (r5 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r1 == '7')) || ((gas[i].reiksme2 == '7') && (r2 == '7')) || ((gas[i].reiksme2 == '7') && (r3 == '7')) ||
                 ((gas[i].reiksme2 == '7') && (r4 == '7')) || ((gas[i].reiksme2 == '7') && (r5 == '7')) || ((r1 == '7') && (r2 == '7')) || ((r1 == '7') && (r3 == '7')) ||
                 ((r1 == '7') && (r4 == '7')) || ((r1 == '7') && (r5 == '7')) || ((r2 == '7') && (r3 == '7')) || ((r2 == '7') && (r4 == '7')) ||
                 ((r2 == '7') && (r5 == '7')) || ((r3 == '7') && (r4 == '7')) || ((r3 == '7') && (r5 == '7')) || ((r4 == '7') && (r5 == '7'))) )
            {
                gas[i].prio = 285; strcpy(gas[i].rink,"Pilnas namas (A-7)");
            }
            if ( (((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r5 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r5 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A') && (r3 == 'A')) || ((r1 == 'A') && (r2 == 'A') && (r4 == 'A')) ||
                 ((r1 == 'A') && (r2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((r2 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((r2 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A') && (r5 == 'A'))) &&
                 (((gas[i].reiksme1 == '8') && (gas[i].reiksme2 == '8')) || ((gas[i].reiksme1 == '8') && (r1 == '8')) || ((gas[i].reiksme1 == '8') && (r2 == '8')) ||
                 ((gas[i].reiksme1 == '8') && (r3 == '8')) || ((gas[i].reiksme1 == '8') && (r4 == '8')) || ((gas[i].reiksme1 == '8') && (r5 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r1 == '8')) || ((gas[i].reiksme2 == '8') && (r2 == '8')) || ((gas[i].reiksme2 == '8') && (r3 == '8')) ||
                 ((gas[i].reiksme2 == '8') && (r4 == '8')) || ((gas[i].reiksme2 == '8') && (r5 == '8')) || ((r1 == '8') && (r2 == '8')) || ((r1 == '8') && (r3 == '8')) ||
                 ((r1 == '8') && (r4 == '8')) || ((r1 == '8') && (r5 == '8')) || ((r2 == '8') && (r3 == '8')) || ((r2 == '8') && (r4 == '8')) ||
                 ((r2 == '8') && (r5 == '8')) || ((r3 == '8') && (r4 == '8')) || ((r3 == '8') && (r5 == '8')) || ((r4 == '8') && (r5 == '8'))) )
            {
                gas[i].prio = 286; strcpy(gas[i].rink,"Pilnas namas (A-8)");
            }
            if ( (((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r5 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r5 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A') && (r3 == 'A')) || ((r1 == 'A') && (r2 == 'A') && (r4 == 'A')) ||
                 ((r1 == 'A') && (r2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((r2 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((r2 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A') && (r5 == 'A'))) &&
                 (((gas[i].reiksme1 == '9') && (gas[i].reiksme2 == '9')) || ((gas[i].reiksme1 == '9') && (r1 == '9')) || ((gas[i].reiksme1 == '9') && (r2 == '9')) ||
                 ((gas[i].reiksme1 == '9') && (r3 == '9')) || ((gas[i].reiksme1 == '9') && (r4 == '9')) || ((gas[i].reiksme1 == '9') && (r5 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r1 == '9')) || ((gas[i].reiksme2 == '9') && (r2 == '9')) || ((gas[i].reiksme2 == '9') && (r3 == '9')) ||
                 ((gas[i].reiksme2 == '9') && (r4 == '9')) || ((gas[i].reiksme2 == '9') && (r5 == '9')) || ((r1 == '9') && (r2 == '9')) || ((r1 == '9') && (r3 == '9')) ||
                 ((r1 == '9') && (r4 == '9')) || ((r1 == '9') && (r5 == '9')) || ((r2 == '9') && (r3 == '9')) || ((r2 == '9') && (r4 == '9')) ||
                 ((r2 == '9') && (r5 == '9')) || ((r3 == '9') && (r4 == '9')) || ((r3 == '9') && (r5 == '9')) || ((r4 == '9') && (r5 == '9'))) )
            {
                gas[i].prio = 287; strcpy(gas[i].rink,"Pilnas namas (A-9)");
            }
            if ( (((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r5 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r5 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A') && (r3 == 'A')) || ((r1 == 'A') && (r2 == 'A') && (r4 == 'A')) ||
                 ((r1 == 'A') && (r2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((r2 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((r2 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A') && (r5 == 'A'))) &&
                 (((gas[i].reiksme1 == 'T') && (gas[i].reiksme2 == 'T')) || ((gas[i].reiksme1 == 'T') && (r1 == 'T')) || ((gas[i].reiksme1 == 'T') && (r2 == 'T')) ||
                 ((gas[i].reiksme1 == 'T') && (r3 == 'T')) || ((gas[i].reiksme1 == 'T') && (r4 == 'T')) || ((gas[i].reiksme1 == 'T') && (r5 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r1 == 'T')) || ((gas[i].reiksme2 == 'T') && (r2 == 'T')) || ((gas[i].reiksme2 == 'T') && (r3 == 'T')) ||
                 ((gas[i].reiksme2 == 'T') && (r4 == 'T')) || ((gas[i].reiksme2 == 'T') && (r5 == 'T')) || ((r1 == 'T') && (r2 == 'T')) || ((r1 == 'T') && (r3 == 'T')) ||
                 ((r1 == 'T') && (r4 == 'T')) || ((r1 == 'T') && (r5 == 'T')) || ((r2 == 'T') && (r3 == 'T')) || ((r2 == 'T') && (r4 == 'T')) ||
                 ((r2 == 'T') && (r5 == 'T')) || ((r3 == 'T') && (r4 == 'T')) || ((r3 == 'T') && (r5 == 'T')) || ((r4 == 'T') && (r5 == 'T'))) )
            {
                gas[i].prio = 288; strcpy(gas[i].rink,"Pilnas namas (A-T)");
            }
            if ( (((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r5 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r5 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A') && (r3 == 'A')) || ((r1 == 'A') && (r2 == 'A') && (r4 == 'A')) ||
                 ((r1 == 'A') && (r2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((r2 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((r2 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A') && (r5 == 'A'))) &&
                 (((gas[i].reiksme1 == 'J') && (gas[i].reiksme2 == 'J')) || ((gas[i].reiksme1 == 'J') && (r1 == 'J')) || ((gas[i].reiksme1 == 'J') && (r2 == 'J')) ||
                 ((gas[i].reiksme1 == 'J') && (r3 == 'J')) || ((gas[i].reiksme1 == 'J') && (r4 == 'J')) || ((gas[i].reiksme1 == 'J') && (r5 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r1 == 'J')) || ((gas[i].reiksme2 == 'J') && (r2 == 'J')) || ((gas[i].reiksme2 == 'J') && (r3 == 'J')) ||
                 ((gas[i].reiksme2 == 'J') && (r4 == 'J')) || ((gas[i].reiksme2 == 'J') && (r5 == 'J')) || ((r1 == 'J') && (r2 == 'J')) || ((r1 == 'J') && (r3 == 'J')) ||
                 ((r1 == 'J') && (r4 == 'J')) || ((r1 == 'J') && (r5 == 'J')) || ((r2 == 'J') && (r3 == 'J')) || ((r2 == 'J') && (r4 == 'J')) ||
                 ((r2 == 'J') && (r5 == 'J')) || ((r3 == 'J') && (r4 == 'J')) || ((r3 == 'J') && (r5 == 'J')) || ((r4 == 'J') && (r5 == 'J'))) )
            {
                gas[i].prio = 289; strcpy(gas[i].rink,"Pilnas namas (A-J)");
            }
            if ( (((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r5 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r5 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A') && (r3 == 'A')) || ((r1 == 'A') && (r2 == 'A') && (r4 == 'A')) ||
                 ((r1 == 'A') && (r2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((r2 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((r2 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A') && (r5 == 'A'))) &&
                 (((gas[i].reiksme1 == 'Q') && (gas[i].reiksme2 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r2 == 'Q')) ||
                 ((gas[i].reiksme1 == 'Q') && (r3 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme1 == 'Q') && (r5 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r1 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r2 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r3 == 'Q')) ||
                 ((gas[i].reiksme2 == 'Q') && (r4 == 'Q')) || ((gas[i].reiksme2 == 'Q') && (r5 == 'Q')) || ((r1 == 'Q') && (r2 == 'Q')) || ((r1 == 'Q') && (r3 == 'Q')) ||
                 ((r1 == 'Q') && (r4 == 'Q')) || ((r1 == 'Q') && (r5 == 'Q')) || ((r2 == 'Q') && (r3 == 'Q')) || ((r2 == 'Q') && (r4 == 'Q')) ||
                 ((r2 == 'Q') && (r5 == 'Q')) || ((r3 == 'Q') && (r4 == 'Q')) || ((r3 == 'Q') && (r5 == 'Q')) || ((r4 == 'Q') && (r5 == 'Q'))) )
            {
                gas[i].prio = 290; strcpy(gas[i].rink,"Pilnas namas (A-Q)");
            }
            if ( (((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r1 == 'A')) || ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (gas[i].reiksme2 == 'A') && (r5 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r1 == 'A') && (r5 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r2 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((gas[i].reiksme1 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme1 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r2 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r3 == 'A')) || ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r4 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r1 == 'A') && (r5 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r3 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r2 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((gas[i].reiksme2 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((gas[i].reiksme2 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r2 == 'A') && (r3 == 'A')) || ((r1 == 'A') && (r2 == 'A') && (r4 == 'A')) ||
                 ((r1 == 'A') && (r2 == 'A') && (r5 == 'A')) || ((r1 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((r1 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((r1 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r2 == 'A') && (r3 == 'A') && (r4 == 'A')) || ((r2 == 'A') && (r3 == 'A') && (r5 == 'A')) ||
                 ((r2 == 'A') && (r4 == 'A') && (r5 == 'A')) || ((r3 == 'A') && (r4 == 'A') && (r5 == 'A'))) &&
                 (((gas[i].reiksme1 == 'K') && (gas[i].reiksme2 == 'K')) || ((gas[i].reiksme1 == 'K') && (r1 == 'K')) || ((gas[i].reiksme1 == 'K') && (r2 == 'K')) ||
                 ((gas[i].reiksme1 == 'K') && (r3 == 'K')) || ((gas[i].reiksme1 == 'K') && (r4 == 'K')) || ((gas[i].reiksme1 == 'K') && (r5 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r1 == 'K')) || ((gas[i].reiksme2 == 'K') && (r2 == 'K')) || ((gas[i].reiksme2 == 'K') && (r3 == 'K')) ||
                 ((gas[i].reiksme2 == 'K') && (r4 == 'K')) || ((gas[i].reiksme2 == 'K') && (r5 == 'K')) || ((r1 == 'K') && (r2 == 'K')) || ((r1 == 'K') && (r3 == 'K')) ||
                 ((r1 == 'K') && (r4 == 'K')) || ((r1 == 'K') && (r5 == 'K')) || ((r2 == 'K') && (r3 == 'K')) || ((r2 == 'K') && (r4 == 'K')) ||
                 ((r2 == 'K') && (r5 == 'K')) || ((r3 == 'K') && (r4 == 'K')) || ((r3 == 'K') && (r5 == 'K')) || ((r4 == 'K') && (r5 == 'K'))) )
            {
                gas[i].prio = 291; strcpy(gas[i].rink,"Pilnas namas (A-K)");
            }
            if ( (gas[i].reiksme1 == '2') || (gas[i].reiksme2 == '2') || (r1 == '2') || (r2 == '2') || (r3 == '2') || (r4 == '2') || (r5 == '2') )
            {
                sk=0;
                if (gas[i].reiksme1 == '2') sk++;
                if (gas[i].reiksme2 == '2') sk++;
                if (r1 == '2') sk++;
                if (r2 == '2') sk++;
                if (r3 == '2') sk++;
                if (r4 == '2') sk++;
                if (r5 == '2') sk++;
                if (sk == 4)
                {
                    gas[i].prio = 292; strcpy(gas[i].rink,"Keturios vienodos (2)");
                }
            }
            if ( (gas[i].reiksme1 == '3') || (gas[i].reiksme2 == '3') || (r1 == '3') || (r2 == '3') || (r3 == '3') || (r4 == '3') || (r5 == '3') )
            {
                sk=0;
                if (gas[i].reiksme1 == '3') sk++;
                if (gas[i].reiksme2 == '3') sk++;
                if (r1 == '3') sk++;
                if (r2 == '3') sk++;
                if (r3 == '3') sk++;
                if (r4 == '3') sk++;
                if (r5 == '3') sk++;
                if (sk == 4)
                {
                    gas[i].prio = 293; strcpy(gas[i].rink,"Keturios vienodos (3)");
                }
            }
            if ( (gas[i].reiksme1 == '4') || (gas[i].reiksme2 == '4') || (r1 == '4') || (r2 == '4') || (r3 == '4') || (r4 == '4') || (r5 == '4') )
            {
                sk=0;
                if (gas[i].reiksme1 == '4') sk++;
                if (gas[i].reiksme2 == '4') sk++;
                if (r1 == '4') sk++;
                if (r2 == '4') sk++;
                if (r3 == '4') sk++;
                if (r4 == '4') sk++;
                if (r5 == '4') sk++;
                if (sk == 4)
                {
                    gas[i].prio = 294; strcpy(gas[i].rink,"Keturios vienodos (4)");
                }
            }
            if ( (gas[i].reiksme1 == '5') || (gas[i].reiksme2 == '5') || (r1 == '5') || (r2 == '5') || (r3 == '5') || (r4 == '5') || (r5 == '5') )
            {
                sk=0;
                if (gas[i].reiksme1 == '5') sk++;
                if (gas[i].reiksme2 == '5') sk++;
                if (r1 == '5') sk++;
                if (r2 == '5') sk++;
                if (r3 == '5') sk++;
                if (r4 == '5') sk++;
                if (r5 == '5') sk++;
                if (sk == 4)
                {
                    gas[i].prio = 295; strcpy(gas[i].rink,"Keturios vienodos (5)");
                }
            }
            if ( (gas[i].reiksme1 == '6') || (gas[i].reiksme2 == '6') || (r1 == '6') || (r2 == '6') || (r3 == '6') || (r4 == '6') || (r5 == '6') )
            {
                sk=0;
                if (gas[i].reiksme1 == '6') sk++;
                if (gas[i].reiksme2 == '6') sk++;
                if (r1 == '6') sk++;
                if (r2 == '6') sk++;
                if (r3 == '6') sk++;
                if (r4 == '6') sk++;
                if (r5 == '6') sk++;
                if (sk == 4)
                {
                    gas[i].prio = 296; strcpy(gas[i].rink,"Keturios vienodos (6)");
                }
            }
            if ( (gas[i].reiksme1 == '7') || (gas[i].reiksme2 == '7') || (r1 == '7') || (r2 == '7') || (r3 == '7') || (r4 == '7') || (r5 == '7') )
            {
                sk=0;
                if (gas[i].reiksme1 == '7') sk++;
                if (gas[i].reiksme2 == '7') sk++;
                if (r1 == '7') sk++;
                if (r2 == '7') sk++;
                if (r3 == '7') sk++;
                if (r4 == '7') sk++;
                if (r5 == '7') sk++;
                if (sk == 4)
                {
                    gas[i].prio = 297; strcpy(gas[i].rink,"Keturios vienodos (7)");
                }
            }
            if ( (gas[i].reiksme1 == '8') || (gas[i].reiksme2 == '8') || (r1 == '8') || (r2 == '8') || (r3 == '8') || (r4 == '8') || (r5 == '8') )
            {
                sk=0;
                if (gas[i].reiksme1 == '8') sk++;
                if (gas[i].reiksme2 == '8') sk++;
                if (r1 == '8') sk++;
                if (r2 == '8') sk++;
                if (r3 == '8') sk++;
                if (r4 == '8') sk++;
                if (r5 == '8') sk++;
                if (sk == 4)
                {
                    gas[i].prio = 298; strcpy(gas[i].rink,"Keturios vienodos (8)");
                }
            }
            if ( (gas[i].reiksme1 == '9') || (gas[i].reiksme2 == '9') || (r1 == '9') || (r2 == '9') || (r3 == '9') || (r4 == '9') || (r5 == '9') )
            {
                sk=0;
                if (gas[i].reiksme1 == '9') sk++;
                if (gas[i].reiksme2 == '9') sk++;
                if (r1 == '9') sk++;
                if (r2 == '9') sk++;
                if (r3 == '9') sk++;
                if (r4 == '9') sk++;
                if (r5 == '9') sk++;
                if (sk == 4)
                {
                    gas[i].prio = 299; strcpy(gas[i].rink,"Keturios vienodos (9)");
                }
            }
            if ( (gas[i].reiksme1 == 'T') || (gas[i].reiksme2 == 'T') || (r1 == 'T') || (r2 == 'T') || (r3 == 'T') || (r4 == 'T') || (r5 == 'T') )
            {
                sk=0;
                if (gas[i].reiksme1 == 'T') sk++;
                if (gas[i].reiksme2 == 'T') sk++;
                if (r1 == 'T') sk++;
                if (r2 == 'T') sk++;
                if (r3 == 'T') sk++;
                if (r4 == 'T') sk++;
                if (r5 == 'T') sk++;
                if (sk == 4)
                {
                    gas[i].prio = 300; strcpy(gas[i].rink,"Keturios vienodos (T)");
                }
            }
            if ( (gas[i].reiksme1 == 'J') || (gas[i].reiksme2 == 'J') || (r1 == 'J') || (r2 == 'J') || (r3 == 'J') || (r4 == 'J') || (r5 == 'J') )
            {
                sk=0;
                if (gas[i].reiksme1 == 'J') sk++;
                if (gas[i].reiksme2 == 'J') sk++;
                if (r1 == 'J') sk++;
                if (r2 == 'J') sk++;
                if (r3 == 'J') sk++;
                if (r4 == 'J') sk++;
                if (r5 == 'J') sk++;
                if (sk == 4)
                {
                    gas[i].prio = 301; strcpy(gas[i].rink,"Keturios vienodos (J)");
                }
            }
            if ( (gas[i].reiksme1 == 'Q') || (gas[i].reiksme2 == 'Q') || (r1 == 'Q') || (r2 == 'Q') || (r3 == 'Q') || (r4 == 'Q') || (r5 == 'Q') )
            {
                sk=0;
                if (gas[i].reiksme1 == 'Q') sk++;
                if (gas[i].reiksme2 == 'Q') sk++;
                if (r1 == 'Q') sk++;
                if (r2 == 'Q') sk++;
                if (r3 == 'Q') sk++;
                if (r4 == 'Q') sk++;
                if (r5 == 'Q') sk++;
                if (sk == 4)
                {
                    gas[i].prio = 302; strcpy(gas[i].rink,"Keturios vienodos (Q)");
                }
            }
            if ( (gas[i].reiksme1 == 'K') || (gas[i].reiksme2 == 'K') || (r1 == 'K') || (r2 == 'K') || (r3 == 'K') || (r4 == 'K') || (r5 == 'K') )
            {
                sk=0;
                if (gas[i].reiksme1 == 'K') sk++;
                if (gas[i].reiksme2 == 'K') sk++;
                if (r1 == 'K') sk++;
                if (r2 == 'K') sk++;
                if (r3 == 'K') sk++;
                if (r4 == 'K') sk++;
                if (r5 == 'K') sk++;
                if (sk == 4)
                {
                    gas[i].prio = 303; strcpy(gas[i].rink,"Keturios vienodos (K)");
                }
            }
            if ( (gas[i].reiksme1 == 'A') || (gas[i].reiksme2 == 'A') || (r1 == 'A') || (r2 == 'A') || (r3 == 'A') || (r4 == 'A') || (r5 == 'A') )
            {
                sk=0;
                if (gas[i].reiksme1 == 'A') sk++;
                if (gas[i].reiksme2 == 'A') sk++;
                if (r1 == 'A') sk++;
                if (r2 == 'A') sk++;
                if (r3 == 'A') sk++;
                if (r4 == 'A') sk++;
                if (r5 == 'A') sk++;
                if (sk == 4)
                {
                    gas[i].prio = 304; strcpy(gas[i].rink,"Keturios vienodos (A)");
                }
            }
            if ( (((gas[i].reiksme1 == '2') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == '2') && (gas[i].tipas2 == 's')) || ((r1 == '2') && (t1 == 's')) ||
                 ((r2 == '2') && (t2 == 's')) || ((r3 == '2') && (t3 == 's')) || ((r4 == '2') && (t4 == 's')) || ((r5 == '2') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == '3') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == '3') && (gas[i].tipas2 == 's')) || ((r1 == '3') && (t1 == 's')) ||
                 ((r2 == '3') && (t2 == 's')) || ((r3 == '3') && (t3 == 's')) || ((r4 == '3') && (t4 == 's')) || ((r5 == '3') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == '4') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == '4') && (gas[i].tipas2 == 's')) || ((r1 == '4') && (t1 == 's')) ||
                 ((r2 == '4') && (t2 == 's')) || ((r3 == '4') && (t3 == 's')) || ((r4 == '4') && (t4 == 's')) || ((r5 == '4') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == '5') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == '5') && (gas[i].tipas2 == 's')) || ((r1 == '5') && (t1 == 's')) ||
                 ((r2 == '5') && (t2 == 's')) || ((r3 == '5') && (t3 == 's')) || ((r4 == '5') && (t4 == 's')) || ((r5 == '5') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == 'A') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == 'A') && (gas[i].tipas2 == 's')) || ((r1 == 'A') && (t1 == 's')) ||
                 ((r2 == 'A') && (t2 == 's')) || ((r3 == 'A') && (t3 == 's')) || ((r4 == 'A') && (t4 == 's')) || ((r5 == 'A') && (t5 == 's'))) )
            {
                gas[i].prio = 305; strcpy(gas[i].rink,"Tiesus pakilimas - sirzdiu (5-A)");
            }
            if ( (((gas[i].reiksme1 == '2') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == '2') && (gas[i].tipas2 == 'b')) || ((r1 == '2') && (t1 == 'b')) ||
                 ((r2 == '2') && (t2 == 'b')) || ((r3 == '2') && (t3 == 'b')) || ((r4 == '2') && (t4 == 'b')) || ((r5 == '2') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == '3') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == '3') && (gas[i].tipas2 == 'b')) || ((r1 == '3') && (t1 == 'b')) ||
                 ((r2 == '3') && (t2 == 'b')) || ((r3 == '3') && (t3 == 'b')) || ((r4 == '3') && (t4 == 'b')) || ((r5 == '3') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == '4') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == '4') && (gas[i].tipas2 == 'b')) || ((r1 == '4') && (t1 == 'b')) ||
                 ((r2 == '4') && (t2 == 'b')) || ((r3 == '4') && (t3 == 'b')) || ((r4 == '4') && (t4 == 'b')) || ((r5 == '4') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == '5') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == '5') && (gas[i].tipas2 == 'b')) || ((r1 == '5') && (t1 == 'b')) ||
                 ((r2 == '5') && (t2 == 'b')) || ((r3 == '5') && (t3 == 'b')) || ((r4 == '5') && (t4 == 'b')) || ((r5 == '5') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == 'A') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == 'A') && (gas[i].tipas2 == 'b')) || ((r1 == 'A') && (t1 == 'b')) ||
                 ((r2 == 'A') && (t2 == 'b')) || ((r3 == 'A') && (t3 == 'b')) || ((r4 == 'A') && (t4 == 'b')) || ((r5 == 'A') && (t5 == 'b'))) )
            {
                gas[i].prio = 305; strcpy(gas[i].rink,"Tiesus pakilimas - bugnu (5-A)");
            }
            if ( (((gas[i].reiksme1 == '2') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == '2') && (gas[i].tipas2 == 'k')) || ((r1 == '2') && (t1 == 'k')) ||
                 ((r2 == '2') && (t2 == 'k')) || ((r3 == '2') && (t3 == 'k')) || ((r4 == '2') && (t4 == 'k')) || ((r5 == '2') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == '3') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == '3') && (gas[i].tipas2 == 'k')) || ((r1 == '3') && (t1 == 'k')) ||
                 ((r2 == '3') && (t2 == 'k')) || ((r3 == '3') && (t3 == 'k')) || ((r4 == '3') && (t4 == 'k')) || ((r5 == '3') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == '4') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == '4') && (gas[i].tipas2 == 'k')) || ((r1 == '4') && (t1 == 'k')) ||
                 ((r2 == '4') && (t2 == 'k')) || ((r3 == '4') && (t3 == 'k')) || ((r4 == '4') && (t4 == 'k')) || ((r5 == '4') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == '5') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == '5') && (gas[i].tipas2 == 'k')) || ((r1 == '5') && (t1 == 'k')) ||
                 ((r2 == '5') && (t2 == 'k')) || ((r3 == '5') && (t3 == 'k')) || ((r4 == '5') && (t4 == 'k')) || ((r5 == '5') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == 'A') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == 'A') && (gas[i].tipas2 == 'k')) || ((r1 == 'A') && (t1 == 'k')) ||
                 ((r2 == 'A') && (t2 == 'k')) || ((r3 == 'A') && (t3 == 'k')) || ((r4 == 'A') && (t4 == 'k')) || ((r5 == 'A') && (t5 == 'k'))) )
            {
                gas[i].prio = 305; strcpy(gas[i].rink,"Tiesus pakilimas - kryziu (5-A)");
            }
            if ( (((gas[i].reiksme1 == '2') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == '2') && (gas[i].tipas2 == 'c')) || ((r1 == '2') && (t1 == 'c')) ||
                 ((r2 == '2') && (t2 == 'c')) || ((r3 == '2') && (t3 == 'c')) || ((r4 == '2') && (t4 == 'c')) || ((r5 == '2') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == '3') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == '3') && (gas[i].tipas2 == 'c')) || ((r1 == '3') && (t1 == 'c')) ||
                 ((r2 == '3') && (t2 == 'c')) || ((r3 == '3') && (t3 == 'c')) || ((r4 == '3') && (t4 == 'c')) || ((r5 == '3') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == '4') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == '4') && (gas[i].tipas2 == 'c')) || ((r1 == '4') && (t1 == 'c')) ||
                 ((r2 == '4') && (t2 == 'c')) || ((r3 == '4') && (t3 == 'c')) || ((r4 == '4') && (t4 == 'c')) || ((r5 == '4') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == '5') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == '5') && (gas[i].tipas2 == 'c')) || ((r1 == '5') && (t1 == 'c')) ||
                 ((r2 == '5') && (t2 == 'c')) || ((r3 == '5') && (t3 == 'c')) || ((r4 == '5') && (t4 == 'c')) || ((r5 == '5') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == 'A') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == 'A') && (gas[i].tipas2 == 'c')) || ((r1 == 'A') && (t1 == 'c')) ||
                 ((r2 == 'A') && (t2 == 'c')) || ((r3 == 'A') && (t3 == 'c')) || ((r4 == 'A') && (t4 == 'c')) || ((r5 == 'A') && (t5 == 'c'))) )
            {
                gas[i].prio = 305; strcpy(gas[i].rink,"Tiesus pakilimas - cirvu (5-A)");
            }
            if ( (((gas[i].reiksme1 == '2') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == '2') && (gas[i].tipas2 == 's')) || ((r1 == '2') && (t1 == 's')) ||
                 ((r2 == '2') && (t2 == 's')) || ((r3 == '2') && (t3 == 's')) || ((r4 == '2') && (t4 == 's')) || ((r5 == '2') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == '3') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == '3') && (gas[i].tipas2 == 's')) || ((r1 == '3') && (t1 == 's')) ||
                 ((r2 == '3') && (t2 == 's')) || ((r3 == '3') && (t3 == 's')) || ((r4 == '3') && (t4 == 's')) || ((r5 == '3') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == '4') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == '4') && (gas[i].tipas2 == 's')) || ((r1 == '4') && (t1 == 's')) ||
                 ((r2 == '4') && (t2 == 's')) || ((r3 == '4') && (t3 == 's')) || ((r4 == '4') && (t4 == 's')) || ((r5 == '4') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == '5') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == '5') && (gas[i].tipas2 == 's')) || ((r1 == '5') && (t1 == 's')) ||
                 ((r2 == '5') && (t2 == 's')) || ((r3 == '5') && (t3 == 's')) || ((r4 == '5') && (t4 == 's')) || ((r5 == '5') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == '6') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == '6') && (gas[i].tipas2 == 's')) || ((r1 == '6') && (t1 == 's')) ||
                 ((r2 == '6') && (t2 == 's')) || ((r3 == '6') && (t3 == 's')) || ((r4 == '6') && (t4 == 's')) || ((r5 == '6') && (t5 == 's'))) )
            {
                gas[i].prio = 306; strcpy(gas[i].rink,"Tiesus pakilimas - sirzdiu (6-2)");
            }
            if ( (((gas[i].reiksme1 == '2') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == '2') && (gas[i].tipas2 == 'b')) || ((r1 == '2') && (t1 == 'b')) ||
                 ((r2 == '2') && (t2 == 'b')) || ((r3 == '2') && (t3 == 'b')) || ((r4 == '2') && (t4 == 'b')) || ((r5 == '2') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == '3') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == '3') && (gas[i].tipas2 == 'b')) || ((r1 == '3') && (t1 == 'b')) ||
                 ((r2 == '3') && (t2 == 'b')) || ((r3 == '3') && (t3 == 'b')) || ((r4 == '3') && (t4 == 'b')) || ((r5 == '3') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == '4') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == '4') && (gas[i].tipas2 == 'b')) || ((r1 == '4') && (t1 == 'b')) ||
                 ((r2 == '4') && (t2 == 'b')) || ((r3 == '4') && (t3 == 'b')) || ((r4 == '4') && (t4 == 'b')) || ((r5 == '4') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == '5') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == '5') && (gas[i].tipas2 == 'b')) || ((r1 == '5') && (t1 == 'b')) ||
                 ((r2 == '5') && (t2 == 'b')) || ((r3 == '5') && (t3 == 'b')) || ((r4 == '5') && (t4 == 'b')) || ((r5 == '5') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == '6') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == '6') && (gas[i].tipas2 == 'b')) || ((r1 == '6') && (t1 == 'b')) ||
                 ((r2 == '6') && (t2 == 'b')) || ((r3 == '6') && (t3 == 'b')) || ((r4 == '6') && (t4 == 'b')) || ((r5 == '6') && (t5 == 'b'))) )
            {
                gas[i].prio = 306; strcpy(gas[i].rink,"Tiesus pakilimas - bugnu (6-2)");
            }
            if ( (((gas[i].reiksme1 == '2') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == '2') && (gas[i].tipas2 == 'k')) || ((r1 == '2') && (t1 == 'k')) ||
                 ((r2 == '2') && (t2 == 'k')) || ((r3 == '2') && (t3 == 'k')) || ((r4 == '2') && (t4 == 'k')) || ((r5 == '2') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == '3') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == '3') && (gas[i].tipas2 == 'k')) || ((r1 == '3') && (t1 == 'k')) ||
                 ((r2 == '3') && (t2 == 'k')) || ((r3 == '3') && (t3 == 'k')) || ((r4 == '3') && (t4 == 'k')) || ((r5 == '3') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == '4') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == '4') && (gas[i].tipas2 == 'k')) || ((r1 == '4') && (t1 == 'k')) ||
                 ((r2 == '4') && (t2 == 'k')) || ((r3 == '4') && (t3 == 'k')) || ((r4 == '4') && (t4 == 'k')) || ((r5 == '4') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == '5') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == '5') && (gas[i].tipas2 == 'k')) || ((r1 == '5') && (t1 == 'k')) ||
                 ((r2 == '5') && (t2 == 'k')) || ((r3 == '5') && (t3 == 'k')) || ((r4 == '5') && (t4 == 'k')) || ((r5 == '5') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == '6') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == '6') && (gas[i].tipas2 == 'k')) || ((r1 == '6') && (t1 == 'k')) ||
                 ((r2 == '6') && (t2 == 'k')) || ((r3 == '6') && (t3 == 'k')) || ((r4 == '6') && (t4 == 'k')) || ((r5 == '6') && (t5 == 'k'))) )
            {
                gas[i].prio = 306; strcpy(gas[i].rink,"Tiesus pakilimas - kryziu (6-2)");
            }
            if ( (((gas[i].reiksme1 == '2') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == '2') && (gas[i].tipas2 == 'c')) || ((r1 == '2') && (t1 == 'c')) ||
                 ((r2 == '2') && (t2 == 'c')) || ((r3 == '2') && (t3 == 'c')) || ((r4 == '2') && (t4 == 'c')) || ((r5 == '2') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == '3') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == '3') && (gas[i].tipas2 == 'c')) || ((r1 == '3') && (t1 == 'c')) ||
                 ((r2 == '3') && (t2 == 'c')) || ((r3 == '3') && (t3 == 'c')) || ((r4 == '3') && (t4 == 'c')) || ((r5 == '3') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == '4') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == '4') && (gas[i].tipas2 == 'c')) || ((r1 == '4') && (t1 == 'c')) ||
                 ((r2 == '4') && (t2 == 'c')) || ((r3 == '4') && (t3 == 'c')) || ((r4 == '4') && (t4 == 'c')) || ((r5 == '4') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == '5') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == '5') && (gas[i].tipas2 == 'c')) || ((r1 == '5') && (t1 == 'c')) ||
                 ((r2 == '5') && (t2 == 'c')) || ((r3 == '5') && (t3 == 'c')) || ((r4 == '5') && (t4 == 'c')) || ((r5 == '5') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == '6') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == '6') && (gas[i].tipas2 == 'c')) || ((r1 == '6') && (t1 == 'c')) ||
                 ((r2 == '6') && (t2 == 'c')) || ((r3 == '6') && (t3 == 'c')) || ((r4 == '6') && (t4 == 'c')) || ((r5 == '6') && (t5 == 'c'))) )
            {
                gas[i].prio = 306; strcpy(gas[i].rink,"Tiesus pakilimas - cirvu (6-2)");
            }
            if ( (((gas[i].reiksme1 == '3') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == '3') && (gas[i].tipas2 == 's')) || ((r1 == '3') && (t1 == 's')) ||
                 ((r2 == '3') && (t2 == 's')) || ((r3 == '3') && (t3 == 's')) || ((r4 == '3') && (t4 == 's')) || ((r5 == '3') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == '4') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == '4') && (gas[i].tipas2 == 's')) || ((r1 == '4') && (t1 == 's')) ||
                 ((r2 == '4') && (t2 == 's')) || ((r3 == '4') && (t3 == 's')) || ((r4 == '4') && (t4 == 's')) || ((r5 == '4') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == '5') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == '5') && (gas[i].tipas2 == 's')) || ((r1 == '5') && (t1 == 's')) ||
                 ((r2 == '5') && (t2 == 's')) || ((r3 == '5') && (t3 == 's')) || ((r4 == '5') && (t4 == 's')) || ((r5 == '5') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == '6') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == '6') && (gas[i].tipas2 == 's')) || ((r1 == '6') && (t1 == 's')) ||
                 ((r2 == '6') && (t2 == 's')) || ((r3 == '6') && (t3 == 's')) || ((r4 == '6') && (t4 == 's')) || ((r5 == '6') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == '7') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == '7') && (gas[i].tipas2 == 's')) || ((r1 == '7') && (t1 == 's')) ||
                 ((r2 == '7') && (t2 == 's')) || ((r3 == '7') && (t3 == 's')) || ((r4 == '7') && (t4 == 's')) || ((r5 == '7') && (t5 == 's'))) )
            {
                gas[i].prio = 307; strcpy(gas[i].rink,"Tiesus pakilimas - sirzdiu (7-3)");
            }
            if ( (((gas[i].reiksme1 == '3') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == '3') && (gas[i].tipas2 == 'b')) || ((r1 == '3') && (t1 == 'b')) ||
                 ((r2 == '3') && (t2 == 'b')) || ((r3 == '3') && (t3 == 'b')) || ((r4 == '3') && (t4 == 'b')) || ((r5 == '3') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == '4') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == '4') && (gas[i].tipas2 == 'b')) || ((r1 == '4') && (t1 == 'b')) ||
                 ((r2 == '4') && (t2 == 'b')) || ((r3 == '4') && (t3 == 'b')) || ((r4 == '4') && (t4 == 'b')) || ((r5 == '4') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == '5') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == '5') && (gas[i].tipas2 == 'b')) || ((r1 == '5') && (t1 == 'b')) ||
                 ((r2 == '5') && (t2 == 'b')) || ((r3 == '5') && (t3 == 'b')) || ((r4 == '5') && (t4 == 'b')) || ((r5 == '5') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == '6') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == '6') && (gas[i].tipas2 == 'b')) || ((r1 == '6') && (t1 == 'b')) ||
                 ((r2 == '6') && (t2 == 'b')) || ((r3 == '6') && (t3 == 'b')) || ((r4 == '6') && (t4 == 'b')) || ((r5 == '6') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == '7') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == '7') && (gas[i].tipas2 == 'b')) || ((r1 == '7') && (t1 == 'b')) ||
                 ((r2 == '7') && (t2 == 'b')) || ((r3 == '7') && (t3 == 'b')) || ((r4 == '7') && (t4 == 'b')) || ((r5 == '7') && (t5 == 'b'))) )
            {
                gas[i].prio = 307; strcpy(gas[i].rink,"Tiesus pakilimas - bugnu (7-3)");
            }
            if ( (((gas[i].reiksme1 == '3') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == '3') && (gas[i].tipas2 == 'k')) || ((r1 == '3') && (t1 == 'k')) ||
                 ((r2 == '3') && (t2 == 'k')) || ((r3 == '3') && (t3 == 'k')) || ((r4 == '3') && (t4 == 'k')) || ((r5 == '3') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == '4') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == '4') && (gas[i].tipas2 == 'k')) || ((r1 == '4') && (t1 == 'k')) ||
                 ((r2 == '4') && (t2 == 'k')) || ((r3 == '4') && (t3 == 'k')) || ((r4 == '4') && (t4 == 'k')) || ((r5 == '4') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == '5') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == '5') && (gas[i].tipas2 == 'k')) || ((r1 == '5') && (t1 == 'k')) ||
                 ((r2 == '5') && (t2 == 'k')) || ((r3 == '5') && (t3 == 'k')) || ((r4 == '5') && (t4 == 'k')) || ((r5 == '5') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == '6') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == '6') && (gas[i].tipas2 == 'k')) || ((r1 == '6') && (t1 == 'k')) ||
                 ((r2 == '6') && (t2 == 'k')) || ((r3 == '6') && (t3 == 'k')) || ((r4 == '6') && (t4 == 'k')) || ((r5 == '6') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == '7') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == '7') && (gas[i].tipas2 == 'k')) || ((r1 == '7') && (t1 == 'k')) ||
                 ((r2 == '7') && (t2 == 'k')) || ((r3 == '7') && (t3 == 'k')) || ((r4 == '7') && (t4 == 'k')) || ((r5 == '7') && (t5 == 'k'))) )
            {
                gas[i].prio = 307; strcpy(gas[i].rink,"Tiesus pakilimas - kryziu (7-3)");
            }
            if ( (((gas[i].reiksme1 == '3') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == '3') && (gas[i].tipas2 == 'c')) || ((r1 == '3') && (t1 == 'c')) ||
                 ((r2 == '3') && (t2 == 'c')) || ((r3 == '3') && (t3 == 'c')) || ((r4 == '3') && (t4 == 'c')) || ((r5 == '3') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == '4') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == '4') && (gas[i].tipas2 == 'c')) || ((r1 == '4') && (t1 == 'c')) ||
                 ((r2 == '4') && (t2 == 'c')) || ((r3 == '4') && (t3 == 'c')) || ((r4 == '4') && (t4 == 'c')) || ((r5 == '4') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == '5') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == '5') && (gas[i].tipas2 == 'c')) || ((r1 == '5') && (t1 == 'c')) ||
                 ((r2 == '5') && (t2 == 'c')) || ((r3 == '5') && (t3 == 'c')) || ((r4 == '5') && (t4 == 'c')) || ((r5 == '5') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == '6') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == '6') && (gas[i].tipas2 == 'c')) || ((r1 == '6') && (t1 == 'c')) ||
                 ((r2 == '6') && (t2 == 'c')) || ((r3 == '6') && (t3 == 'c')) || ((r4 == '6') && (t4 == 'c')) || ((r5 == '6') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == '7') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == '7') && (gas[i].tipas2 == 'c')) || ((r1 == '7') && (t1 == 'c')) ||
                 ((r2 == '7') && (t2 == 'c')) || ((r3 == '7') && (t3 == 'c')) || ((r4 == '7') && (t4 == 'c')) || ((r5 == '7') && (t5 == 'c'))) )
            {
                gas[i].prio = 307; strcpy(gas[i].rink,"Tiesus pakilimas - cirvu (7-3)");
            }
            if ( (((gas[i].reiksme1 == '4') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == '4') && (gas[i].tipas2 == 's')) || ((r1 == '4') && (t1 == 's')) ||
                 ((r2 == '4') && (t2 == 's')) || ((r3 == '4') && (t3 == 's')) || ((r4 == '4') && (t4 == 's')) || ((r5 == '4') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == '5') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == '5') && (gas[i].tipas2 == 's')) || ((r1 == '5') && (t1 == 's')) ||
                 ((r2 == '5') && (t2 == 's')) || ((r3 == '5') && (t3 == 's')) || ((r4 == '5') && (t4 == 's')) || ((r5 == '5') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == '6') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == '6') && (gas[i].tipas2 == 's')) || ((r1 == '6') && (t1 == 's')) ||
                 ((r2 == '6') && (t2 == 's')) || ((r3 == '6') && (t3 == 's')) || ((r4 == '6') && (t4 == 's')) || ((r5 == '6') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == '7') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == '7') && (gas[i].tipas2 == 's')) || ((r1 == '7') && (t1 == 's')) ||
                 ((r2 == '7') && (t2 == 's')) || ((r3 == '7') && (t3 == 's')) || ((r4 == '7') && (t4 == 's')) || ((r5 == '7') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == '8') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == '8') && (gas[i].tipas2 == 's')) || ((r1 == '8') && (t1 == 's')) ||
                 ((r2 == '8') && (t2 == 's')) || ((r3 == '8') && (t3 == 's')) || ((r4 == '8') && (t4 == 's')) || ((r5 == '8') && (t5 == 's'))) )
            {
                gas[i].prio = 308; strcpy(gas[i].rink,"Tiesus pakilimas - sirzdiu (8-4)");
            }
            if ( (((gas[i].reiksme1 == '4') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == '4') && (gas[i].tipas2 == 'b')) || ((r1 == '4') && (t1 == 'b')) ||
                 ((r2 == '4') && (t2 == 'b')) || ((r3 == '4') && (t3 == 'b')) || ((r4 == '4') && (t4 == 'b')) || ((r5 == '4') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == '5') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == '5') && (gas[i].tipas2 == 'b')) || ((r1 == '5') && (t1 == 'b')) ||
                 ((r2 == '5') && (t2 == 'b')) || ((r3 == '5') && (t3 == 'b')) || ((r4 == '5') && (t4 == 'b')) || ((r5 == '5') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == '6') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == '6') && (gas[i].tipas2 == 'b')) || ((r1 == '6') && (t1 == 'b')) ||
                 ((r2 == '6') && (t2 == 'b')) || ((r3 == '6') && (t3 == 'b')) || ((r4 == '6') && (t4 == 'b')) || ((r5 == '6') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == '7') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == '7') && (gas[i].tipas2 == 'b')) || ((r1 == '7') && (t1 == 'b')) ||
                 ((r2 == '7') && (t2 == 'b')) || ((r3 == '7') && (t3 == 'b')) || ((r4 == '7') && (t4 == 'b')) || ((r5 == '7') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == '8') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == '8') && (gas[i].tipas2 == 'b')) || ((r1 == '8') && (t1 == 'b')) ||
                 ((r2 == '8') && (t2 == 'b')) || ((r3 == '8') && (t3 == 'b')) || ((r4 == '8') && (t4 == 'b')) || ((r5 == '8') && (t5 == 'b'))) )
            {
                gas[i].prio = 308; strcpy(gas[i].rink,"Tiesus pakilimas - bugnu (8-4)");
            }
            if ( (((gas[i].reiksme1 == '4') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == '4') && (gas[i].tipas2 == 'k')) || ((r1 == '4') && (t1 == 'k')) ||
                 ((r2 == '4') && (t2 == 'k')) || ((r3 == '4') && (t3 == 'k')) || ((r4 == '4') && (t4 == 'k')) || ((r5 == '4') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == '5') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == '5') && (gas[i].tipas2 == 'k')) || ((r1 == '5') && (t1 == 'k')) ||
                 ((r2 == '5') && (t2 == 'k')) || ((r3 == '5') && (t3 == 'k')) || ((r4 == '5') && (t4 == 'k')) || ((r5 == '5') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == '6') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == '6') && (gas[i].tipas2 == 'k')) || ((r1 == '6') && (t1 == 'k')) ||
                 ((r2 == '6') && (t2 == 'k')) || ((r3 == '6') && (t3 == 'k')) || ((r4 == '6') && (t4 == 'k')) || ((r5 == '6') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == '7') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == '7') && (gas[i].tipas2 == 'k')) || ((r1 == '7') && (t1 == 'k')) ||
                 ((r2 == '7') && (t2 == 'k')) || ((r3 == '7') && (t3 == 'k')) || ((r4 == '7') && (t4 == 'k')) || ((r5 == '7') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == '8') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == '8') && (gas[i].tipas2 == 'k')) || ((r1 == '8') && (t1 == 'k')) ||
                 ((r2 == '8') && (t2 == 'k')) || ((r3 == '8') && (t3 == 'k')) || ((r4 == '8') && (t4 == 'k')) || ((r5 == '8') && (t5 == 'k'))) )
            {
                gas[i].prio = 308; strcpy(gas[i].rink,"Tiesus pakilimas - kryziu (8-4)");
            }
            if ( (((gas[i].reiksme1 == '4') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == '4') && (gas[i].tipas2 == 'c')) || ((r1 == '4') && (t1 == 'c')) ||
                 ((r2 == '4') && (t2 == 'c')) || ((r3 == '4') && (t3 == 'c')) || ((r4 == '4') && (t4 == 'c')) || ((r5 == '4') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == '5') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == '5') && (gas[i].tipas2 == 'c')) || ((r1 == '5') && (t1 == 'c')) ||
                 ((r2 == '5') && (t2 == 'c')) || ((r3 == '5') && (t3 == 'c')) || ((r4 == '5') && (t4 == 'c')) || ((r5 == '5') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == '6') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == '6') && (gas[i].tipas2 == 'c')) || ((r1 == '6') && (t1 == 'c')) ||
                 ((r2 == '6') && (t2 == 'c')) || ((r3 == '6') && (t3 == 'c')) || ((r4 == '6') && (t4 == 'c')) || ((r5 == '6') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == '7') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == '7') && (gas[i].tipas2 == 'c')) || ((r1 == '7') && (t1 == 'c')) ||
                 ((r2 == '7') && (t2 == 'c')) || ((r3 == '7') && (t3 == 'c')) || ((r4 == '7') && (t4 == 'c')) || ((r5 == '7') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == '8') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == '8') && (gas[i].tipas2 == 'c')) || ((r1 == '8') && (t1 == 'c')) ||
                 ((r2 == '8') && (t2 == 'c')) || ((r3 == '8') && (t3 == 'c')) || ((r4 == '8') && (t4 == 'c')) || ((r5 == '8') && (t5 == 'c'))) )
            {
                gas[i].prio = 308; strcpy(gas[i].rink,"Tiesus pakilimas - cirvu (8-4)");
            }
            if ( (((gas[i].reiksme1 == '5') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == '5') && (gas[i].tipas2 == 's')) || ((r1 == '5') && (t1 == 's')) ||
                 ((r2 == '5') && (t2 == 's')) || ((r3 == '5') && (t3 == 's')) || ((r4 == '5') && (t4 == 's')) || ((r5 == '5') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == '6') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == '6') && (gas[i].tipas2 == 's')) || ((r1 == '6') && (t1 == 's')) ||
                 ((r2 == '6') && (t2 == 's')) || ((r3 == '6') && (t3 == 's')) || ((r4 == '6') && (t4 == 's')) || ((r5 == '6') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == '7') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == '7') && (gas[i].tipas2 == 's')) || ((r1 == '7') && (t1 == 's')) ||
                 ((r2 == '7') && (t2 == 's')) || ((r3 == '7') && (t3 == 's')) || ((r4 == '7') && (t4 == 's')) || ((r5 == '7') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == '8') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == '8') && (gas[i].tipas2 == 's')) || ((r1 == '8') && (t1 == 's')) ||
                 ((r2 == '8') && (t2 == 's')) || ((r3 == '8') && (t3 == 's')) || ((r4 == '8') && (t4 == 's')) || ((r5 == '8') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == '9') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == '9') && (gas[i].tipas2 == 's')) || ((r1 == '9') && (t1 == 's')) ||
                 ((r2 == '9') && (t2 == 's')) || ((r3 == '9') && (t3 == 's')) || ((r4 == '9') && (t4 == 's')) || ((r5 == '9') && (t5 == 's'))) )
            {
                gas[i].prio = 309; strcpy(gas[i].rink,"Tiesus pakilimas - sirzdiu (9-5)");
            }
            if ( (((gas[i].reiksme1 == '5') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == '5') && (gas[i].tipas2 == 'b')) || ((r1 == '5') && (t1 == 'b')) ||
                 ((r2 == '5') && (t2 == 'b')) || ((r3 == '5') && (t3 == 'b')) || ((r4 == '5') && (t4 == 'b')) || ((r5 == '5') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == '6') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == '6') && (gas[i].tipas2 == 'b')) || ((r1 == '6') && (t1 == 'b')) ||
                 ((r2 == '6') && (t2 == 'b')) || ((r3 == '6') && (t3 == 'b')) || ((r4 == '6') && (t4 == 'b')) || ((r5 == '6') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == '7') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == '7') && (gas[i].tipas2 == 'b')) || ((r1 == '7') && (t1 == 'b')) ||
                 ((r2 == '7') && (t2 == 'b')) || ((r3 == '7') && (t3 == 'b')) || ((r4 == '7') && (t4 == 'b')) || ((r5 == '7') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == '8') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == '8') && (gas[i].tipas2 == 'b')) || ((r1 == '8') && (t1 == 'b')) ||
                 ((r2 == '8') && (t2 == 'b')) || ((r3 == '8') && (t3 == 'b')) || ((r4 == '8') && (t4 == 'b')) || ((r5 == '8') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == '9') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == '9') && (gas[i].tipas2 == 'b')) || ((r1 == '9') && (t1 == 'b')) ||
                 ((r2 == '9') && (t2 == 'b')) || ((r3 == '9') && (t3 == 'b')) || ((r4 == '9') && (t4 == 'b')) || ((r5 == '9') && (t5 == 'b'))) )
            {
                gas[i].prio = 309; strcpy(gas[i].rink,"Tiesus pakilimas - bugnu (9-5)");
            }
            if ( (((gas[i].reiksme1 == '5') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == '5') && (gas[i].tipas2 == 'k')) || ((r1 == '5') && (t1 == 'k')) ||
                 ((r2 == '5') && (t2 == 'k')) || ((r3 == '5') && (t3 == 'k')) || ((r4 == '5') && (t4 == 'k')) || ((r5 == '5') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == '6') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == '6') && (gas[i].tipas2 == 'k')) || ((r1 == '6') && (t1 == 'k')) ||
                 ((r2 == '6') && (t2 == 'k')) || ((r3 == '6') && (t3 == 'k')) || ((r4 == '6') && (t4 == 'k')) || ((r5 == '6') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == '7') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == '7') && (gas[i].tipas2 == 'k')) || ((r1 == '7') && (t1 == 'k')) ||
                 ((r2 == '7') && (t2 == 'k')) || ((r3 == '7') && (t3 == 'k')) || ((r4 == '7') && (t4 == 'k')) || ((r5 == '7') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == '8') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == '8') && (gas[i].tipas2 == 'k')) || ((r1 == '8') && (t1 == 'k')) ||
                 ((r2 == '8') && (t2 == 'k')) || ((r3 == '8') && (t3 == 'k')) || ((r4 == '8') && (t4 == 'k')) || ((r5 == '8') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == '9') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == '9') && (gas[i].tipas2 == 'k')) || ((r1 == '9') && (t1 == 'k')) ||
                 ((r2 == '9') && (t2 == 'k')) || ((r3 == '9') && (t3 == 'k')) || ((r4 == '9') && (t4 == 'k')) || ((r5 == '9') && (t5 == 'k'))) )
            {
                gas[i].prio = 309; strcpy(gas[i].rink,"Tiesus pakilimas - kryziu (9-5)");
            }
            if ( (((gas[i].reiksme1 == '5') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == '5') && (gas[i].tipas2 == 'c')) || ((r1 == '5') && (t1 == 'c')) ||
                 ((r2 == '5') && (t2 == 'c')) || ((r3 == '5') && (t3 == 'c')) || ((r4 == '5') && (t4 == 'c')) || ((r5 == '5') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == '6') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == '6') && (gas[i].tipas2 == 'c')) || ((r1 == '6') && (t1 == 'c')) ||
                 ((r2 == '6') && (t2 == 'c')) || ((r3 == '6') && (t3 == 'c')) || ((r4 == '6') && (t4 == 'c')) || ((r5 == '6') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == '7') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == '7') && (gas[i].tipas2 == 'c')) || ((r1 == '7') && (t1 == 'c')) ||
                 ((r2 == '7') && (t2 == 'c')) || ((r3 == '7') && (t3 == 'c')) || ((r4 == '7') && (t4 == 'c')) || ((r5 == '7') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == '8') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == '8') && (gas[i].tipas2 == 'c')) || ((r1 == '8') && (t1 == 'c')) ||
                 ((r2 == '8') && (t2 == 'c')) || ((r3 == '8') && (t3 == 'c')) || ((r4 == '8') && (t4 == 'c')) || ((r5 == '8') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == '9') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == '9') && (gas[i].tipas2 == 'c')) || ((r1 == '9') && (t1 == 'c')) ||
                 ((r2 == '9') && (t2 == 'c')) || ((r3 == '9') && (t3 == 'c')) || ((r4 == '9') && (t4 == 'c')) || ((r5 == '9') && (t5 == 'c'))) )
            {
                gas[i].prio = 309; strcpy(gas[i].rink,"Tiesus pakilimas - cirvu (9-5)");
            }
            if ( (((gas[i].reiksme1 == '6') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == '6') && (gas[i].tipas2 == 's')) || ((r1 == '6') && (t1 == 's')) ||
                 ((r2 == '6') && (t2 == 's')) || ((r3 == '6') && (t3 == 's')) || ((r4 == '6') && (t4 == 's')) || ((r5 == '6') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == '7') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == '7') && (gas[i].tipas2 == 's')) || ((r1 == '7') && (t1 == 's')) ||
                 ((r2 == '7') && (t2 == 's')) || ((r3 == '7') && (t3 == 's')) || ((r4 == '7') && (t4 == 's')) || ((r5 == '7') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == '8') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == '8') && (gas[i].tipas2 == 's')) || ((r1 == '8') && (t1 == 's')) ||
                 ((r2 == '8') && (t2 == 's')) || ((r3 == '8') && (t3 == 's')) || ((r4 == '8') && (t4 == 's')) || ((r5 == '8') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == '9') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == '9') && (gas[i].tipas2 == 's')) || ((r1 == '9') && (t1 == 's')) ||
                 ((r2 == '9') && (t2 == 's')) || ((r3 == '9') && (t3 == 's')) || ((r4 == '9') && (t4 == 's')) || ((r5 == '9') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == 'T') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == 'T') && (gas[i].tipas2 == 's')) || ((r1 == 'T') && (t1 == 's')) ||
                 ((r2 == 'T') && (t2 == 's')) || ((r3 == 'T') && (t3 == 's')) || ((r4 == 'T') && (t4 == 's')) || ((r5 == 'T') && (t5 == 's'))) )
            {
                gas[i].prio = 310; strcpy(gas[i].rink,"Tiesus pakilimas - sirzdiu (T-6)");
            }
            if ( (((gas[i].reiksme1 == '6') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == '6') && (gas[i].tipas2 == 'b')) || ((r1 == '6') && (t1 == 'b')) ||
                 ((r2 == '6') && (t2 == 'b')) || ((r3 == '6') && (t3 == 'b')) || ((r4 == '6') && (t4 == 'b')) || ((r5 == '6') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == '7') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == '7') && (gas[i].tipas2 == 'b')) || ((r1 == '7') && (t1 == 'b')) ||
                 ((r2 == '7') && (t2 == 'b')) || ((r3 == '7') && (t3 == 'b')) || ((r4 == '7') && (t4 == 'b')) || ((r5 == '7') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == '8') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == '8') && (gas[i].tipas2 == 'b')) || ((r1 == '8') && (t1 == 'b')) ||
                 ((r2 == '8') && (t2 == 'b')) || ((r3 == '8') && (t3 == 'b')) || ((r4 == '8') && (t4 == 'b')) || ((r5 == '8') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == '9') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == '9') && (gas[i].tipas2 == 'b')) || ((r1 == '9') && (t1 == 'b')) ||
                 ((r2 == '9') && (t2 == 'b')) || ((r3 == '9') && (t3 == 'b')) || ((r4 == '9') && (t4 == 'b')) || ((r5 == '9') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == 'T') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == 'T') && (gas[i].tipas2 == 'b')) || ((r1 == 'T') && (t1 == 'b')) ||
                 ((r2 == 'T') && (t2 == 'b')) || ((r3 == 'T') && (t3 == 'b')) || ((r4 == 'T') && (t4 == 'b')) || ((r5 == 'T') && (t5 == 'b'))) )
            {
                gas[i].prio = 310; strcpy(gas[i].rink,"Tiesus pakilimas - bugnu (T-6)");
            }
            if ( (((gas[i].reiksme1 == '6') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == '6') && (gas[i].tipas2 == 'k')) || ((r1 == '6') && (t1 == 'k')) ||
                 ((r2 == '6') && (t2 == 'k')) || ((r3 == '6') && (t3 == 'k')) || ((r4 == '6') && (t4 == 'k')) || ((r5 == '6') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == '7') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == '7') && (gas[i].tipas2 == 'k')) || ((r1 == '7') && (t1 == 'k')) ||
                 ((r2 == '7') && (t2 == 'k')) || ((r3 == '7') && (t3 == 'k')) || ((r4 == '7') && (t4 == 'k')) || ((r5 == '7') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == '8') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == '8') && (gas[i].tipas2 == 'k')) || ((r1 == '8') && (t1 == 'k')) ||
                 ((r2 == '8') && (t2 == 'k')) || ((r3 == '8') && (t3 == 'k')) || ((r4 == '8') && (t4 == 'k')) || ((r5 == '8') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == '9') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == '9') && (gas[i].tipas2 == 'k')) || ((r1 == '9') && (t1 == 'k')) ||
                 ((r2 == '9') && (t2 == 'k')) || ((r3 == '9') && (t3 == 'k')) || ((r4 == '9') && (t4 == 'k')) || ((r5 == '9') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == 'T') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == 'T') && (gas[i].tipas2 == 'k')) || ((r1 == 'T') && (t1 == 'k')) ||
                 ((r2 == 'T') && (t2 == 'k')) || ((r3 == 'T') && (t3 == 'k')) || ((r4 == 'T') && (t4 == 'k')) || ((r5 == 'T') && (t5 == 'k'))) )
            {
                gas[i].prio = 310; strcpy(gas[i].rink,"Tiesus pakilimas - kryziu (T-6)");
            }
            if ( (((gas[i].reiksme1 == '6') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == '6') && (gas[i].tipas2 == 'c')) || ((r1 == '6') && (t1 == 'c')) ||
                 ((r2 == '6') && (t2 == 'c')) || ((r3 == '6') && (t3 == 'c')) || ((r4 == '6') && (t4 == 'c')) || ((r5 == '6') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == '7') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == '7') && (gas[i].tipas2 == 'c')) || ((r1 == '7') && (t1 == 'c')) ||
                 ((r2 == '7') && (t2 == 'c')) || ((r3 == '7') && (t3 == 'c')) || ((r4 == '7') && (t4 == 'c')) || ((r5 == '7') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == '8') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == '8') && (gas[i].tipas2 == 'c')) || ((r1 == '8') && (t1 == 'c')) ||
                 ((r2 == '8') && (t2 == 'c')) || ((r3 == '8') && (t3 == 'c')) || ((r4 == '8') && (t4 == 'c')) || ((r5 == '8') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == '9') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == '9') && (gas[i].tipas2 == 'c')) || ((r1 == '9') && (t1 == 'c')) ||
                 ((r2 == '9') && (t2 == 'c')) || ((r3 == '9') && (t3 == 'c')) || ((r4 == '9') && (t4 == 'c')) || ((r5 == '9') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == 'T') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == 'T') && (gas[i].tipas2 == 'c')) || ((r1 == 'T') && (t1 == 'c')) ||
                 ((r2 == 'T') && (t2 == 'c')) || ((r3 == 'T') && (t3 == 'c')) || ((r4 == 'T') && (t4 == 'c')) || ((r5 == 'T') && (t5 == 'c'))) )
            {
                gas[i].prio = 310; strcpy(gas[i].rink,"Tiesus pakilimas - cirvu (T-6)");
            }
            if ( (((gas[i].reiksme1 == '7') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == '7') && (gas[i].tipas2 == 's')) || ((r1 == '7') && (t1 == 's')) ||
                 ((r2 == '7') && (t2 == 's')) || ((r3 == '7') && (t3 == 's')) || ((r4 == '7') && (t4 == 's')) || ((r5 == '7') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == '8') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == '8') && (gas[i].tipas2 == 's')) || ((r1 == '8') && (t1 == 's')) ||
                 ((r2 == '8') && (t2 == 's')) || ((r3 == '8') && (t3 == 's')) || ((r4 == '8') && (t4 == 's')) || ((r5 == '8') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == '9') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == '9') && (gas[i].tipas2 == 's')) || ((r1 == '9') && (t1 == 's')) ||
                 ((r2 == '9') && (t2 == 's')) || ((r3 == '9') && (t3 == 's')) || ((r4 == '9') && (t4 == 's')) || ((r5 == '9') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == 'T') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == 'T') && (gas[i].tipas2 == 's')) || ((r1 == 'T') && (t1 == 's')) ||
                 ((r2 == 'T') && (t2 == 's')) || ((r3 == 'T') && (t3 == 's')) || ((r4 == 'T') && (t4 == 's')) || ((r5 == 'T') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == 'J') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == 'J') && (gas[i].tipas2 == 's')) || ((r1 == 'J') && (t1 == 's')) ||
                 ((r2 == 'J') && (t2 == 's')) || ((r3 == 'J') && (t3 == 's')) || ((r4 == 'J') && (t4 == 's')) || ((r5 == 'J') && (t5 == 's'))) )
            {
                gas[i].prio = 311; strcpy(gas[i].rink,"Tiesus pakilimas - sirzdiu (J-7)");
            }
            if ( (((gas[i].reiksme1 == '7') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == '7') && (gas[i].tipas2 == 'b')) || ((r1 == '7') && (t1 == 'b')) ||
                 ((r2 == '7') && (t2 == 'b')) || ((r3 == '7') && (t3 == 'b')) || ((r4 == '7') && (t4 == 'b')) || ((r5 == '7') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == '8') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == '8') && (gas[i].tipas2 == 'b')) || ((r1 == '8') && (t1 == 'b')) ||
                 ((r2 == '8') && (t2 == 'b')) || ((r3 == '8') && (t3 == 'b')) || ((r4 == '8') && (t4 == 'b')) || ((r5 == '8') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == '9') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == '9') && (gas[i].tipas2 == 'b')) || ((r1 == '9') && (t1 == 'b')) ||
                 ((r2 == '9') && (t2 == 'b')) || ((r3 == '9') && (t3 == 'b')) || ((r4 == '9') && (t4 == 'b')) || ((r5 == '9') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == 'T') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == 'T') && (gas[i].tipas2 == 'b')) || ((r1 == 'T') && (t1 == 'b')) ||
                 ((r2 == 'T') && (t2 == 'b')) || ((r3 == 'T') && (t3 == 'b')) || ((r4 == 'T') && (t4 == 'b')) || ((r5 == 'T') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == 'J') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == 'J') && (gas[i].tipas2 == 'b')) || ((r1 == 'J') && (t1 == 'b')) ||
                 ((r2 == 'J') && (t2 == 'b')) || ((r3 == 'J') && (t3 == 'b')) || ((r4 == 'J') && (t4 == 'b')) || ((r5 == 'J') && (t5 == 'b'))) )
            {
                gas[i].prio = 311; strcpy(gas[i].rink,"Tiesus pakilimas - bugnu (J-7)");
            }
            if ( (((gas[i].reiksme1 == '7') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == '7') && (gas[i].tipas2 == 'k')) || ((r1 == '7') && (t1 == 'k')) ||
                 ((r2 == '7') && (t2 == 'k')) || ((r3 == '7') && (t3 == 'k')) || ((r4 == '7') && (t4 == 'k')) || ((r5 == '7') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == '8') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == '8') && (gas[i].tipas2 == 'k')) || ((r1 == '8') && (t1 == 'k')) ||
                 ((r2 == '8') && (t2 == 'k')) || ((r3 == '8') && (t3 == 'k')) || ((r4 == '8') && (t4 == 'k')) || ((r5 == '8') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == '9') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == '9') && (gas[i].tipas2 == 'k')) || ((r1 == '9') && (t1 == 'k')) ||
                 ((r2 == '9') && (t2 == 'k')) || ((r3 == '9') && (t3 == 'k')) || ((r4 == '9') && (t4 == 'k')) || ((r5 == '9') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == 'T') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == 'T') && (gas[i].tipas2 == 'k')) || ((r1 == 'T') && (t1 == 'k')) ||
                 ((r2 == 'T') && (t2 == 'k')) || ((r3 == 'T') && (t3 == 'k')) || ((r4 == 'T') && (t4 == 'k')) || ((r5 == 'T') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == 'J') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == 'J') && (gas[i].tipas2 == 'k')) || ((r1 == 'J') && (t1 == 'k')) ||
                 ((r2 == 'J') && (t2 == 'k')) || ((r3 == 'J') && (t3 == 'k')) || ((r4 == 'J') && (t4 == 'k')) || ((r5 == 'J') && (t5 == 'k'))) )
            {
                gas[i].prio = 311; strcpy(gas[i].rink,"Tiesus pakilimas - kryziu (J-7)");
            }
            if ( (((gas[i].reiksme1 == '7') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == '7') && (gas[i].tipas2 == 'c')) || ((r1 == '7') && (t1 == 'c')) ||
                 ((r2 == '7') && (t2 == 'c')) || ((r3 == '7') && (t3 == 'c')) || ((r4 == '7') && (t4 == 'c')) || ((r5 == '7') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == '8') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == '8') && (gas[i].tipas2 == 'c')) || ((r1 == '8') && (t1 == 'c')) ||
                 ((r2 == '8') && (t2 == 'c')) || ((r3 == '8') && (t3 == 'c')) || ((r4 == '8') && (t4 == 'c')) || ((r5 == '8') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == '9') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == '9') && (gas[i].tipas2 == 'c')) || ((r1 == '9') && (t1 == 'c')) ||
                 ((r2 == '9') && (t2 == 'c')) || ((r3 == '9') && (t3 == 'c')) || ((r4 == '9') && (t4 == 'c')) || ((r5 == '9') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == 'T') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == 'T') && (gas[i].tipas2 == 'c')) || ((r1 == 'T') && (t1 == 'c')) ||
                 ((r2 == 'T') && (t2 == 'c')) || ((r3 == 'T') && (t3 == 'c')) || ((r4 == 'T') && (t4 == 'c')) || ((r5 == 'T') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == 'J') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == 'J') && (gas[i].tipas2 == 'c')) || ((r1 == 'J') && (t1 == 'c')) ||
                 ((r2 == 'J') && (t2 == 'c')) || ((r3 == 'J') && (t3 == 'c')) || ((r4 == 'J') && (t4 == 'c')) || ((r5 == 'J') && (t5 == 'c'))) )
            {
                gas[i].prio = 311; strcpy(gas[i].rink,"Tiesus pakilimas - cirvu (J-7)");
            }
            if ( (((gas[i].reiksme1 == '8') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == '8') && (gas[i].tipas2 == 's')) || ((r1 == '8') && (t1 == 's')) ||
                 ((r2 == '8') && (t2 == 's')) || ((r3 == '8') && (t3 == 's')) || ((r4 == '8') && (t4 == 's')) || ((r5 == '8') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == '9') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == '9') && (gas[i].tipas2 == 's')) || ((r1 == '9') && (t1 == 's')) ||
                 ((r2 == '9') && (t2 == 's')) || ((r3 == '9') && (t3 == 's')) || ((r4 == '9') && (t4 == 's')) || ((r5 == '9') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == 'T') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == 'T') && (gas[i].tipas2 == 's')) || ((r1 == 'T') && (t1 == 's')) ||
                 ((r2 == 'T') && (t2 == 's')) || ((r3 == 'T') && (t3 == 's')) || ((r4 == 'T') && (t4 == 's')) || ((r5 == 'T') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == 'J') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == 'J') && (gas[i].tipas2 == 's')) || ((r1 == 'J') && (t1 == 's')) ||
                 ((r2 == 'J') && (t2 == 's')) || ((r3 == 'J') && (t3 == 's')) || ((r4 == 'J') && (t4 == 's')) || ((r5 == 'J') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == 'Q') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == 'Q') && (gas[i].tipas2 == 's')) || ((r1 == 'Q') && (t1 == 's')) ||
                 ((r2 == 'Q') && (t2 == 's')) || ((r3 == 'Q') && (t3 == 's')) || ((r4 == 'Q') && (t4 == 's')) || ((r5 == 'Q') && (t5 == 's'))) )
            {
                gas[i].prio = 312; strcpy(gas[i].rink,"Tiesus pakilimas - sirzdiu (Q-8)");
            }
            if ( (((gas[i].reiksme1 == '8') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == '8') && (gas[i].tipas2 == 'b')) || ((r1 == '8') && (t1 == 'b')) ||
                 ((r2 == '8') && (t2 == 'b')) || ((r3 == '8') && (t3 == 'b')) || ((r4 == '8') && (t4 == 'b')) || ((r5 == '8') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == '9') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == '9') && (gas[i].tipas2 == 'b')) || ((r1 == '9') && (t1 == 'b')) ||
                 ((r2 == '9') && (t2 == 'b')) || ((r3 == '9') && (t3 == 'b')) || ((r4 == '9') && (t4 == 'b')) || ((r5 == '9') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == 'T') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == 'T') && (gas[i].tipas2 == 'b')) || ((r1 == 'T') && (t1 == 'b')) ||
                 ((r2 == 'T') && (t2 == 'b')) || ((r3 == 'T') && (t3 == 'b')) || ((r4 == 'T') && (t4 == 'b')) || ((r5 == 'T') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == 'J') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == 'J') && (gas[i].tipas2 == 'b')) || ((r1 == 'J') && (t1 == 'b')) ||
                 ((r2 == 'J') && (t2 == 'b')) || ((r3 == 'J') && (t3 == 'b')) || ((r4 == 'J') && (t4 == 'b')) || ((r5 == 'J') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == 'Q') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == 'Q') && (gas[i].tipas2 == 'b')) || ((r1 == 'Q') && (t1 == 'b')) ||
                 ((r2 == 'Q') && (t2 == 'b')) || ((r3 == 'Q') && (t3 == 'b')) || ((r4 == 'Q') && (t4 == 'b')) || ((r5 == 'Q') && (t5 == 'b'))) )
            {
                gas[i].prio = 312; strcpy(gas[i].rink,"Tiesus pakilimas - bugnu (Q-8)");
            }
            if ( (((gas[i].reiksme1 == '8') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == '8') && (gas[i].tipas2 == 'k')) || ((r1 == '8') && (t1 == 'k')) ||
                 ((r2 == '8') && (t2 == 'k')) || ((r3 == '8') && (t3 == 'k')) || ((r4 == '8') && (t4 == 'k')) || ((r5 == '8') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == '9') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == '9') && (gas[i].tipas2 == 'k')) || ((r1 == '9') && (t1 == 'k')) ||
                 ((r2 == '9') && (t2 == 'k')) || ((r3 == '9') && (t3 == 'k')) || ((r4 == '9') && (t4 == 'k')) || ((r5 == '9') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == 'T') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == 'T') && (gas[i].tipas2 == 'k')) || ((r1 == 'T') && (t1 == 'k')) ||
                 ((r2 == 'T') && (t2 == 'k')) || ((r3 == 'T') && (t3 == 'k')) || ((r4 == 'T') && (t4 == 'k')) || ((r5 == 'T') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == 'J') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == 'J') && (gas[i].tipas2 == 'k')) || ((r1 == 'J') && (t1 == 'k')) ||
                 ((r2 == 'J') && (t2 == 'k')) || ((r3 == 'J') && (t3 == 'k')) || ((r4 == 'J') && (t4 == 'k')) || ((r5 == 'J') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == 'Q') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == 'Q') && (gas[i].tipas2 == 'k')) || ((r1 == 'Q') && (t1 == 'k')) ||
                 ((r2 == 'Q') && (t2 == 'k')) || ((r3 == 'Q') && (t3 == 'k')) || ((r4 == 'Q') && (t4 == 'k')) || ((r5 == 'Q') && (t5 == 'k'))) )
            {
                gas[i].prio = 312; strcpy(gas[i].rink,"Tiesus pakilimas - kryziu (Q-8)");
            }
            if ( (((gas[i].reiksme1 == '8') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == '8') && (gas[i].tipas2 == 'c')) || ((r1 == '8') && (t1 == 'c')) ||
                 ((r2 == '8') && (t2 == 'c')) || ((r3 == '8') && (t3 == 'c')) || ((r4 == '8') && (t4 == 'c')) || ((r5 == '8') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == '9') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == '9') && (gas[i].tipas2 == 'c')) || ((r1 == '9') && (t1 == 'c')) ||
                 ((r2 == '9') && (t2 == 'c')) || ((r3 == '9') && (t3 == 'c')) || ((r4 == '9') && (t4 == 'c')) || ((r5 == '9') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == 'T') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == 'T') && (gas[i].tipas2 == 'c')) || ((r1 == 'T') && (t1 == 'c')) ||
                 ((r2 == 'T') && (t2 == 'c')) || ((r3 == 'T') && (t3 == 'c')) || ((r4 == 'T') && (t4 == 'c')) || ((r5 == 'T') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == 'J') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == 'J') && (gas[i].tipas2 == 'c')) || ((r1 == 'J') && (t1 == 'c')) ||
                 ((r2 == 'J') && (t2 == 'c')) || ((r3 == 'J') && (t3 == 'c')) || ((r4 == 'J') && (t4 == 'c')) || ((r5 == 'J') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == 'Q') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == 'Q') && (gas[i].tipas2 == 'c')) || ((r1 == 'Q') && (t1 == 'c')) ||
                 ((r2 == 'Q') && (t2 == 'c')) || ((r3 == 'Q') && (t3 == 'c')) || ((r4 == 'Q') && (t4 == 'c')) || ((r5 == 'Q') && (t5 == 'c'))) )
            {
                gas[i].prio = 312; strcpy(gas[i].rink,"Tiesus pakilimas - cirvu (Q-8)");
            }
            if ( (((gas[i].reiksme1 == '9') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == '9') && (gas[i].tipas2 == 's')) || ((r1 == '9') && (t1 == 's')) ||
                 ((r2 == '9') && (t2 == 's')) || ((r3 == '9') && (t3 == 's')) || ((r4 == '9') && (t4 == 's')) || ((r5 == '9') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == 'T') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == 'T') && (gas[i].tipas2 == 's')) || ((r1 == 'T') && (t1 == 's')) ||
                 ((r2 == 'T') && (t2 == 's')) || ((r3 == 'T') && (t3 == 's')) || ((r4 == 'T') && (t4 == 's')) || ((r5 == 'T') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == 'J') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == 'J') && (gas[i].tipas2 == 's')) || ((r1 == 'J') && (t1 == 's')) ||
                 ((r2 == 'J') && (t2 == 's')) || ((r3 == 'J') && (t3 == 's')) || ((r4 == 'J') && (t4 == 's')) || ((r5 == 'J') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == 'Q') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == 'Q') && (gas[i].tipas2 == 's')) || ((r1 == 'Q') && (t1 == 's')) ||
                 ((r2 == 'Q') && (t2 == 's')) || ((r3 == 'Q') && (t3 == 's')) || ((r4 == 'Q') && (t4 == 's')) || ((r5 == 'Q') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == 'K') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == 'K') && (gas[i].tipas2 == 's')) || ((r1 == 'K') && (t1 == 's')) ||
                 ((r2 == 'K') && (t2 == 's')) || ((r3 == 'K') && (t3 == 's')) || ((r4 == 'K') && (t4 == 's')) || ((r5 == 'K') && (t5 == 's'))) )
            {
                gas[i].prio = 313; strcpy(gas[i].rink,"Tiesus pakilimas - sirzdiu (K-9)");
            }
            if ( (((gas[i].reiksme1 == '9') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == '9') && (gas[i].tipas2 == 'b')) || ((r1 == '9') && (t1 == 'b')) ||
                 ((r2 == '9') && (t2 == 'b')) || ((r3 == '9') && (t3 == 'b')) || ((r4 == '9') && (t4 == 'b')) || ((r5 == '9') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == 'T') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == 'T') && (gas[i].tipas2 == 'b')) || ((r1 == 'T') && (t1 == 'b')) ||
                 ((r2 == 'T') && (t2 == 'b')) || ((r3 == 'T') && (t3 == 'b')) || ((r4 == 'T') && (t4 == 'b')) || ((r5 == 'T') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == 'J') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == 'J') && (gas[i].tipas2 == 'b')) || ((r1 == 'J') && (t1 == 'b')) ||
                 ((r2 == 'J') && (t2 == 'b')) || ((r3 == 'J') && (t3 == 'b')) || ((r4 == 'J') && (t4 == 'b')) || ((r5 == 'J') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == 'Q') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == 'Q') && (gas[i].tipas2 == 'b')) || ((r1 == 'Q') && (t1 == 'b')) ||
                 ((r2 == 'Q') && (t2 == 'b')) || ((r3 == 'Q') && (t3 == 'b')) || ((r4 == 'Q') && (t4 == 'b')) || ((r5 == 'Q') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == 'K') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == 'K') && (gas[i].tipas2 == 'b')) || ((r1 == 'K') && (t1 == 'b')) ||
                 ((r2 == 'K') && (t2 == 'b')) || ((r3 == 'K') && (t3 == 'b')) || ((r4 == 'K') && (t4 == 'b')) || ((r5 == 'K') && (t5 == 'b'))) )
            {
                gas[i].prio = 313; strcpy(gas[i].rink,"Tiesus pakilimas - bugnu (K-9)");
            }
            if ( (((gas[i].reiksme1 == '9') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == '9') && (gas[i].tipas2 == 'k')) || ((r1 == '9') && (t1 == 'k')) ||
                 ((r2 == '9') && (t2 == 'k')) || ((r3 == '9') && (t3 == 'k')) || ((r4 == '9') && (t4 == 'k')) || ((r5 == '9') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == 'T') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == 'T') && (gas[i].tipas2 == 'k')) || ((r1 == 'T') && (t1 == 'k')) ||
                 ((r2 == 'T') && (t2 == 'k')) || ((r3 == 'T') && (t3 == 'k')) || ((r4 == 'T') && (t4 == 'k')) || ((r5 == 'T') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == 'J') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == 'J') && (gas[i].tipas2 == 'k')) || ((r1 == 'J') && (t1 == 'k')) ||
                 ((r2 == 'J') && (t2 == 'k')) || ((r3 == 'J') && (t3 == 'k')) || ((r4 == 'J') && (t4 == 'k')) || ((r5 == 'J') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == 'Q') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == 'Q') && (gas[i].tipas2 == 'k')) || ((r1 == 'Q') && (t1 == 'k')) ||
                 ((r2 == 'Q') && (t2 == 'k')) || ((r3 == 'Q') && (t3 == 'k')) || ((r4 == 'Q') && (t4 == 'k')) || ((r5 == 'Q') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == 'K') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == 'K') && (gas[i].tipas2 == 'k')) || ((r1 == 'K') && (t1 == 'k')) ||
                 ((r2 == 'K') && (t2 == 'k')) || ((r3 == 'K') && (t3 == 'k')) || ((r4 == 'K') && (t4 == 'k')) || ((r5 == 'K') && (t5 == 'k'))) )
            {
                gas[i].prio = 313; strcpy(gas[i].rink,"Tiesus pakilimas - kryziu (K-9)");
            }
            if ( (((gas[i].reiksme1 == '9') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == '9') && (gas[i].tipas2 == 'c')) || ((r1 == '9') && (t1 == 'c')) ||
                 ((r2 == '9') && (t2 == 'c')) || ((r3 == '9') && (t3 == 'c')) || ((r4 == '9') && (t4 == 'c')) || ((r5 == '9') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == 'T') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == 'T') && (gas[i].tipas2 == 'c')) || ((r1 == 'T') && (t1 == 'c')) ||
                 ((r2 == 'T') && (t2 == 'c')) || ((r3 == 'T') && (t3 == 'c')) || ((r4 == 'T') && (t4 == 'c')) || ((r5 == 'T') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == 'J') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == 'J') && (gas[i].tipas2 == 'c')) || ((r1 == 'J') && (t1 == 'c')) ||
                 ((r2 == 'J') && (t2 == 'c')) || ((r3 == 'J') && (t3 == 'c')) || ((r4 == 'J') && (t4 == 'c')) || ((r5 == 'J') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == 'Q') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == 'Q') && (gas[i].tipas2 == 'c')) || ((r1 == 'Q') && (t1 == 'c')) ||
                 ((r2 == 'Q') && (t2 == 'c')) || ((r3 == 'Q') && (t3 == 'c')) || ((r4 == 'Q') && (t4 == 'c')) || ((r5 == 'Q') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == 'K') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == 'K') && (gas[i].tipas2 == 'c')) || ((r1 == 'K') && (t1 == 'c')) ||
                 ((r2 == 'K') && (t2 == 'c')) || ((r3 == 'K') && (t3 == 'c')) || ((r4 == 'K') && (t4 == 'c')) || ((r5 == 'K') && (t5 == 'c'))) )
            {
                gas[i].prio = 313; strcpy(gas[i].rink,"Tiesus pakilimas - cirvu (K-9)");
            }
            if ( (((gas[i].reiksme1 == 'T') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == 'T') && (gas[i].tipas2 == 's')) || ((r1 == 'T') && (t1 == 's')) ||
                 ((r2 == 'T') && (t2 == 's')) || ((r3 == 'T') && (t3 == 's')) || ((r4 == 'T') && (t4 == 's')) || ((r5 == 'T') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == 'J') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == 'J') && (gas[i].tipas2 == 's')) || ((r1 == 'J') && (t1 == 's')) ||
                 ((r2 == 'J') && (t2 == 's')) || ((r3 == 'J') && (t3 == 's')) || ((r4 == 'J') && (t4 == 's')) || ((r5 == 'J') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == 'Q') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == 'Q') && (gas[i].tipas2 == 's')) || ((r1 == 'Q') && (t1 == 's')) ||
                 ((r2 == 'Q') && (t2 == 's')) || ((r3 == 'Q') && (t3 == 's')) || ((r4 == 'Q') && (t4 == 's')) || ((r5 == 'Q') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == 'K') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == 'K') && (gas[i].tipas2 == 's')) || ((r1 == 'K') && (t1 == 's')) ||
                 ((r2 == 'K') && (t2 == 's')) || ((r3 == 'K') && (t3 == 's')) || ((r4 == 'K') && (t4 == 's')) || ((r5 == 'K') && (t5 == 's'))) &&
                 (((gas[i].reiksme1 == 'A') && (gas[i].tipas1 == 's')) || ((gas[i].reiksme2 == 'A') && (gas[i].tipas2 == 's')) || ((r1 == 'A') && (t1 == 's')) ||
                 ((r2 == 'A') && (t2 == 's')) || ((r3 == 'A') && (t3 == 's')) || ((r4 == 'A') && (t4 == 's')) || ((r5 == 'A') && (t5 == 's'))) )
            {
                gas[i].prio = 314; strcpy(gas[i].rink,"Karaliskas pakilimas - sirzdiu");
            }
            if ( (((gas[i].reiksme1 == 'T') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == 'T') && (gas[i].tipas2 == 'b')) || ((r1 == 'T') && (t1 == 'b')) ||
                 ((r2 == 'T') && (t2 == 'b')) || ((r3 == 'T') && (t3 == 'b')) || ((r4 == 'T') && (t4 == 'b')) || ((r5 == 'T') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == 'J') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == 'J') && (gas[i].tipas2 == 'b')) || ((r1 == 'J') && (t1 == 'b')) ||
                 ((r2 == 'J') && (t2 == 'b')) || ((r3 == 'J') && (t3 == 'b')) || ((r4 == 'J') && (t4 == 'b')) || ((r5 == 'J') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == 'Q') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == 'Q') && (gas[i].tipas2 == 'b')) || ((r1 == 'Q') && (t1 == 'b')) ||
                 ((r2 == 'Q') && (t2 == 'b')) || ((r3 == 'Q') && (t3 == 'b')) || ((r4 == 'Q') && (t4 == 'b')) || ((r5 == 'Q') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == 'K') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == 'K') && (gas[i].tipas2 == 'b')) || ((r1 == 'K') && (t1 == 'b')) ||
                 ((r2 == 'K') && (t2 == 'b')) || ((r3 == 'K') && (t3 == 'b')) || ((r4 == 'K') && (t4 == 'b')) || ((r5 == 'K') && (t5 == 'b'))) &&
                 (((gas[i].reiksme1 == 'A') && (gas[i].tipas1 == 'b')) || ((gas[i].reiksme2 == 'A') && (gas[i].tipas2 == 'b')) || ((r1 == 'A') && (t1 == 'b')) ||
                 ((r2 == 'A') && (t2 == 'b')) || ((r3 == 'A') && (t3 == 'b')) || ((r4 == 'A') && (t4 == 'b')) || ((r5 == 'A') && (t5 == 'b'))) )
            {
                gas[i].prio = 314; strcpy(gas[i].rink,"Karaliskas pakilimas - bugnu");
            }
            if ( (((gas[i].reiksme1 == 'T') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == 'T') && (gas[i].tipas2 == 'k')) || ((r1 == 'T') && (t1 == 'k')) ||
                 ((r2 == 'T') && (t2 == 'k')) || ((r3 == 'T') && (t3 == 'k')) || ((r4 == 'T') && (t4 == 'k')) || ((r5 == 'T') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == 'J') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == 'J') && (gas[i].tipas2 == 'k')) || ((r1 == 'J') && (t1 == 'k')) ||
                 ((r2 == 'J') && (t2 == 'k')) || ((r3 == 'J') && (t3 == 'k')) || ((r4 == 'J') && (t4 == 'k')) || ((r5 == 'J') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == 'Q') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == 'Q') && (gas[i].tipas2 == 'k')) || ((r1 == 'Q') && (t1 == 'k')) ||
                 ((r2 == 'Q') && (t2 == 'k')) || ((r3 == 'Q') && (t3 == 'k')) || ((r4 == 'Q') && (t4 == 'k')) || ((r5 == 'Q') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == 'K') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == 'K') && (gas[i].tipas2 == 'k')) || ((r1 == 'K') && (t1 == 'k')) ||
                 ((r2 == 'K') && (t2 == 'k')) || ((r3 == 'K') && (t3 == 'k')) || ((r4 == 'K') && (t4 == 'k')) || ((r5 == 'K') && (t5 == 'k'))) &&
                 (((gas[i].reiksme1 == 'A') && (gas[i].tipas1 == 'k')) || ((gas[i].reiksme2 == 'A') && (gas[i].tipas2 == 'k')) || ((r1 == 'A') && (t1 == 'k')) ||
                 ((r2 == 'A') && (t2 == 'k')) || ((r3 == 'A') && (t3 == 'k')) || ((r4 == 'A') && (t4 == 'k')) || ((r5 == 'A') && (t5 == 'k'))) )
            {
                gas[i].prio = 314; strcpy(gas[i].rink,"Karaliskas pakilimas - kryziu");
            }
            if ( (((gas[i].reiksme1 == 'T') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == 'T') && (gas[i].tipas2 == 'c')) || ((r1 == 'T') && (t1 == 'c')) ||
                 ((r2 == 'T') && (t2 == 'c')) || ((r3 == 'T') && (t3 == 'c')) || ((r4 == 'T') && (t4 == 'c')) || ((r5 == 'T') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == 'J') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == 'J') && (gas[i].tipas2 == 'c')) || ((r1 == 'J') && (t1 == 'c')) ||
                 ((r2 == 'J') && (t2 == 'c')) || ((r3 == 'J') && (t3 == 'c')) || ((r4 == 'J') && (t4 == 'c')) || ((r5 == 'J') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == 'Q') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == 'Q') && (gas[i].tipas2 == 'c')) || ((r1 == 'Q') && (t1 == 'c')) ||
                 ((r2 == 'Q') && (t2 == 'c')) || ((r3 == 'Q') && (t3 == 'c')) || ((r4 == 'Q') && (t4 == 'c')) || ((r5 == 'Q') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == 'K') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == 'K') && (gas[i].tipas2 == 'c')) || ((r1 == 'K') && (t1 == 'c')) ||
                 ((r2 == 'K') && (t2 == 'c')) || ((r3 == 'K') && (t3 == 'c')) || ((r4 == 'K') && (t4 == 'c')) || ((r5 == 'K') && (t5 == 'c'))) &&
                 (((gas[i].reiksme1 == 'A') && (gas[i].tipas1 == 'c')) || ((gas[i].reiksme2 == 'A') && (gas[i].tipas2 == 'c')) || ((r1 == 'A') && (t1 == 'c')) ||
                 ((r2 == 'A') && (t2 == 'c')) || ((r3 == 'A') && (t3 == 'c')) || ((r4 == 'A') && (t4 == 'c')) || ((r5 == 'A') && (t5 == 'c'))) )
            {
                gas[i].prio = 314; strcpy(gas[i].rink,"Karaliskas pakilimas - cirvu");
            }
        }
    }
}

//----------Tikrinimas----------
void tikrinimas()
{
    printf("\n");
    for (i=0; i<=m; i++)
    {
        if (gas[i].tipas1 != ' ')
        {
            printf("Ar %s tesia zaidima (1 - taip, 0 - ne)\n",gas[i].zaidejas);
            scanf("%d",&tf);
            if (tf == 0)
            {
                gas[i].tipas1 = ' ';
                zaid--;
            }
        }
    }
}

//----------Zaidimo algoritmas---------
void zaidimas()
{
    printf("Iveskite zaideju skaiciu prie stalo\n");
    scanf("%d",&zaid);
    printf("\n");
    m=zaid-1;
    check=0;

    for (i=0; i<=m; i++)
    {
        printf("Iveskite %d zaidejo varda ir dvi kortas (Pvz. Mindaugas As 9b)\n",i+1);
        scanf("%s %c%c %c%c",&gas[i].zaidejas,&gas[i].reiksme1,&gas[i].tipas1,&gas[i].reiksme2,&gas[i].tipas2);
        for (j=0; j<=n; j++)
        {
            if (gas[i].reiksme1 == mas[j].reiksme && gas[i].tipas1 == mas[j].tipas)
            {
                mas[j].reiksme = ' '; mas[j].tipas = ' ';
                check++;
            }
            else if (gas[i].reiksme2 == mas[j].reiksme && gas[i].tipas2 == mas[j].tipas)
            {
                mas[j].reiksme = ' '; mas[j].tipas = ' ';
                check++;
            }
        }
    }
    kortu = 2 * zaid;
    if (check != kortu)
    {
        printf("\nIvedete korta antra karta, arba neteisinga kortu jungini. Siulome pries zaidziant perskaityti zaidimo instrukcija (3)\n\n");
        return;
    }

    tikrinimas();
    if (zaid == 0)
    {
        printf("\nVisi zaidejai pasavo, zaidimas baigtas\n\n");
        return;
    }
    else if (zaid == 1)
    {
        for (i=0; i<=m; i++)
        {
            if (gas[i].tipas1 != ' ')
            {
                printf("\n%s laimejo\n\n",gas[i].zaidejas);
            }
        }
        return;
    }

    printf("\nIveskite ejimo pavadinima ir 3 kortas ant stalo (Pvz. flop 6s 7s 8s)\n");
    scanf("%s %c%c %c%c %c%c",&h1,&r1,&t1,&r2,&t2,&r3,&t3);
    for (j=0; j<=n; j++)
    {
        if (r1 == mas[j].reiksme && t1 == mas[j].tipas)
        {
            mas[j].reiksme = ' '; mas[j].tipas = ' ';
            check++;
        }
        else if (r2 == mas[j].reiksme && t2 == mas[j].tipas)
        {
            mas[j].reiksme = ' '; mas[j].tipas = ' ';
            check++;
        }
        else if (r3 == mas[j].reiksme && t3 == mas[j].tipas)
        {
            mas[j].reiksme = ' '; mas[j].tipas = ' ';
            check++;
        }
    }
    kortu = kortu + 3;
    if (check != kortu)
    {
        printf("\nIvedete korta antra karta, arba neteisinga kortu jungini. Siulome pries zaidziant perskaityti zaidimo instrukcija (3)\n\n");
        return;
    }

    tikrinimas();
    if (zaid == 0)
    {
        printf("\nVisi zaidejai pasavo, zaidimas baigtas\n\n");
        return;
    }
    else if (zaid == 1)
    {
        for (i=0; i<=m; i++)
        {
            if (gas[i].tipas1 != ' ')
            {
                printf("\n%s laimejo\n\n",gas[i].zaidejas);
            }
        }
        return;
    }

    printf("\nIveskite ejimo pavadinima ir 4 korta ant stalo (Pvz. turn 2c)\n");
    scanf("%s %c%c",&h2,&r4,&t4);
    for (j=0; j<=n; j++)
    {
        if (r4 == mas[j].reiksme && t4 == mas[j].tipas)
        {
            mas[j].reiksme = ' '; mas[j].tipas = ' ';
            check++;
        }
    }
    kortu++;
    if (check != kortu)
    {
        printf("\nIvedete korta antra karta, arba neteisinga kortu jungini. Siulome pries zaidziant perskaityti zaidimo instrukcija (3)\n\n");
        return;
    }

    tikrinimas();
    if (zaid == 0)
    {
        printf("\nVisi zaidejai pasavo, zaidimas baigtas\n\n");
        return;
    }
    else if (zaid == 1)
    {
        for (i=0; i<=m; i++)
        {
            if (gas[i].tipas1 != ' ')
            {
                printf("\n%s laimejo\n\n",gas[i].zaidejas);
            }
        }
        return;
    }

    printf("\nIveskite ejimo pavadinima ir 5 korta ant stalo (Pvz. river Qk)\n");
    scanf("%s %c%c",&h3,&r5,&t5);
    for (j=0; j<=n; j++)
    {
        if (r5 == mas[j].reiksme && t5 == mas[j].tipas)
        {
            mas[j].reiksme = ' '; mas[j].tipas = ' ';
            check++;
        }
    }
    kortu++;
    if (check != kortu)
    {
        printf("\nIvedete korta antra karta, arba neteisinga kortu jungini. Siulome pries zaidziant perskaityti zaidimo instrukcija (3)\n\n");
        return;
    }

    tikrinimas();
    if (zaid == 0)
    {
        printf("\nVisi zaidejai pasavo, zaidimas baigtas\n\n");
        return;
    }
    else if (zaid == 1)
    {
        for (i=0; i<=m; i++)
        {
            if (gas[i].tipas1 != ' ')
            {
                printf("\n%s laimejo\n\n",gas[i].zaidejas);
            }
        }
        return;
    }

    system("cls");
    printf("Zaideju kortos:\n");
    for (i=0; i<=m; i++)
    {
        if (gas[i].tipas1 != ' ')
        {
            printf("%s %c%c %c%c\n",gas[i].zaidejas,gas[i].reiksme1,gas[i].tipas1,gas[i].reiksme2,gas[i].tipas2);
        }
    }
    printf("\nStalo kortos:\n");
    printf("%c%c %c%c %c%c %c%c %c%c\n\n",r1,t1,r2,t2,r3,t3,r4,t4,r5,t5);

    rinkiniai();
    stdprio = 0;
    for (i=0; i<=m; i++)
    {
        if (gas[i].tipas1 != ' ')
        {
            if (gas[i].prio >= stdprio)
            {
                stdprio = gas[i].prio;
            }
        }
    }

    for (i=0; i<=m; i++)
    {
        if (gas[i].tipas1 != ' ')
        {
            if (gas[i].prio == stdprio)
            {
                strcat(winner,gas[i].zaidejas);
                strcat(winner," ");
                strcpy(hand,gas[i].rink);
            }
        }
    }
printf("Nugalejo:\n%ssurinke(-s) kortu rinkini - %s\n\n",winner,hand);
}
//----------Pagrindinė programa----------
int main()
{
    while (choice != 4)
    {
        nuskaitymas();
        menu();
        printf("Jusu pasirinkimas: \n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: system("cls"); zaidimas(); break;
            case 2: system("cls"); instructions(); break;
            case 3: system("cls"); printf("Iki pasimatymo.. \n\n"); return 0;
            default: system("cls"); printf("Blogas pasirinkimas.. \n\n");
        }
    }
system("pause");
return 0;
}
