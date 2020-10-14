/*
    <Rodrigo Quiroz Reyes> <A01026546>
    <Esteban Manrique de Lara Sirvent> <A01027077>
    <Andres Barragan Salas> <A01026567>
*/

int main()
{
    int a [5]= {11,22,33,44,55};
    //double b;
    //char c;
    int *b = a;
    int counter=0;
    while(counter<10) //It prints the 5 values in the array and 5 other outside; this is done to validate the question stipulated in the document
    {
        printf("%d\n",*(b+counter));
        counter++;
    }
}
