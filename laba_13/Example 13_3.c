#include<stdio.h>
#include<stdlib.h>
//#include <windows.h>

const int N = 10;

int main()
{
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);

    int i, A[N];
    FILE *fp; // вказівник на файл
    fp = fopen("/Users/olga/Documents/laba_13/laba_13/input_13_3.txt","r");

    if(fp!=NULL)
    {
        printf("Файл успішно прочитано \n");
    }
    else
    {
        fprintf(stderr,"Файл не знайдено\n");
        return 1;
    }

    for(i=0; i<N; i++)
    {
        if(1!=fscanf(fp,"%d",&A[i]))
        {
            printf("Не вистачає данних");
            return 1;
        }
        else
            fprintf(stdout,"A[%d]=%d \n",i,A[i]);
    }


    int a;
    FILE *neparni, *parni;
    neparni = fopen("/Users/olga/Documents/laba_13/laba_13/neparni.txt","w");
    parni = fopen("/Users/olga/Documents/laba_13/laba_13/parni.txt","w");
    rewind(fp);

    FILE *tmpf;
    tmpf = tmpfile();

    while (fscanf(fp, "%d", &a) == 1)
    {
        if(a%2==0)
        fprintf(parni, "%d ", a);
        else
        fprintf(neparni, "%d ", a);
    }
    fclose(parni);
    fclose(neparni);
    fclose(fp);
}
