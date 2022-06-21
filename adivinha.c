// tudo que começa com #, chamamos de diretiva
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// a define deixa a gente definir uma constante.
//#define NUMERO_DE_TENTATIVAS 5

int main() {

    

    printf("\n\n          P  /_\\  P                            \n");
    printf("         /_\\_|_|_/_\\                              \n");
    printf("     n_n | ||. .|| | n_n         Bem vindo ao       \n");
    printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação!   \n");
    printf("    |" "  |  |_|  |"  " |                           \n");
    printf("    |_____| ' _ ' |_____|                           \n");
    printf("          \\__|_|__/                            \n\n\n");

    

    
    int segundos = time(0);
    srand(segundos);
    
    int numerogrande = rand();
    
    int chute;
    int numerosecreto = numerogrande % 100;
    

    double pontos = 1000;
    
    int acertou = 0;

    int nivel;
    printf("Escolha o nivel de dificuldade:\n");
    printf("1 - Facil\n2 - Medio\n3 - Dificil\n");
    scanf("%d", &nivel);

    int numerodetentativas;

    switch(nivel){
        case 1:
            numerodetentativas = 20;
            break;

        case 2:
            numerodetentativas = 15;
            break;

        case 3:
            numerodetentativas = 7;
            break;
    }
    
    
    int i = 1;
    for(i = 1; i <= numerodetentativas; i++){

        printf("\nTentantiva %d" , i);
        printf("\nDigite seu chute: ");
        
        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        if (chute < 0){
            printf("Digito invalido\n");
            //irmao do break, faz com que o bloco va direto pro i++
            continue;
        }

        acertou = chute == numerosecreto;
        int maior = chute > numerosecreto;

        if(acertou){
            break;
        }
                
        else if(maior){
            printf("Seu numero eh maior que o numero secreto\n");
        }
        
        else {
            printf("seu numero eh menor que o numero secreto\n");
        }
        
        //abs = numero absoluto, se alguem chutar um numero menor do que
        //o numero secreto, ele ira passar pra positivo e podendo assim diminiur
        //para fazer o calculo dos pontos exato
        double pontosperdidos = abs(chute - numerosecreto) / (double)2;
        pontos = pontos - pontosperdidos;
    }
    
    if(acertou){
        printf("\nVoce Ganhou!\n");
        printf("\nVc acertou em %d tentativas\n", i);
        printf("Total de pontos: %.1f\n", pontos);
    } 
  
    else {
        printf("\nVoce perdeu :(\nGame Over\n");
    }
}
