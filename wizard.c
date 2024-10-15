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
void tipo_alt(double vAnt, double vNovo){
    if(vAnt > vNovo){
        printf("Alteração de Downgrade\n");
    }else{
        printf("Alteração de Upgrade\n");
    }
}
double calc_prop(double vAnt, double vNew, int dia, int periodo){
    double pMetade, sMetade, valor_proporcional;

    pMetade = (vAnt / periodo) * dia;
    sMetade = (vNew / periodo) * (periodo - dia);

    valor_proporcional = pMetade + sMetade;

    return valor_proporcional;
}
void dados_proporcional(int dia, int mes, int ano, double valor_prop){
    printf("Dados da parcela proporcional:\n");
    printf("\tVencimento: %d/%d/%d\n", dia, mes, ano);
    printf("\tValor da parcela proporcional: %.2lf\n", valor_prop);
}
int main(){
    double valorAntigo, valorNovo, proporcional;
    int vencimentoFixo, periodo;
    struct tm *p;
    time_t segundos;

    time(&segundos);
    p = localtime(&segundos);
    periodo = tamanho_periodo(p);

    printf("Qual o dia fixo de vencimento: ");
    scanf("%d", &vencimentoFixo);
    printf("Qual o valor do plano antigo? ");
    scanf("%lf", &valorAntigo);
    printf("Qual o valor do plano novo? ");
    scanf("%lf", &valorNovo);

    tipo_alt(valorAntigo, valorNovo);
    proporcional = calc_prop(valorAntigo, valorNovo, p->tm_mday, periodo);

    dados_proporcional(vencimentoFixo, p->tm_mon+2, p->tm_year+1900, proporcional);

    return 0;
}