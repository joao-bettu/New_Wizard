#include <stdio.h>
#include <time.h>

int tamanho_periodo(struct tm *p){
    int tamanho;

    if(p->tm_mon == 3 && p->tm_mon == 5 && p->tm_mon == 8 && p->tm_mon == 10){
        tamanho = 30;
    }else if(p->tm_mon == 1){
        tamanho = 28;
    }else{
        tamanho = 31;
    }

    return tamanho;
}
int main(){
    double valorAntigo, valorNovo, proporcional;
    int vencimentoFixo, mesAtual, diaAtual, periodo;
    struct tm *p;
    time_t segundos;

    time(&segundos);
    p = localtime(&segundos);

    mesAtual = p->tm_mon+1;
    diaAtual = p->tm_mday;
    
    periodo = tamanho_periodo(p);

    printf("Qual o dia fixo de vencimento: ");
    scanf("%d", &vencimentoFixo);
    printf("Qual o valor do plano antigo? ");
    scanf("%lf", &valorAntigo);
    printf("Qual o valor do plano novo? ");
    scanf("%lf", &valorNovo);

    if(valorAntigo > valorNovo){
        printf("Alteração de Downgrade\n");
    }else{
        printf("Alteração de Upgrade\n");
    }

    return 0;
}