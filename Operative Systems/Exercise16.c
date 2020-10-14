/*
    <Esteban Manrique de Lara Sirvent> <A01027077>
    <Rodrigo Quiroz Reyes> <A01026546>
    <Andres Barragan Salas> <A01026567>
*/
int main()
{
    int in = 10;
    char ch = 'j';
    double db = 10.5;

    int *pIn = &in;
    char *pCh = &ch;
    double *pDb = &db;

    printf("%d\n",in);
    printf("%llu\n", sizeof(in));
    printf("%p\n",pIn);
    printf("%llu\n", sizeof(pIn));

    printf("%c\n",ch);
    printf("%llu\n", sizeof(ch));
    printf("%p\n",pCh);
    printf("%llu\n", sizeof(pCh));

    printf("%f\n",db);
    printf("%llu\n", sizeof(db));
    printf("%p\n",pDb);
    printf("%llu\n", sizeof(pDb));
}
