#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

typedef struct Simple
{
    int val;
    struct Simple* sig;
};

void inOrdeSi(int input);
void inPrinSi(int input);
void inUltiSi(int input);
void elDatoSi(int input);
void imSi();
struct Simple* crSimple(int input);

#endif

