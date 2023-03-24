#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void inicializarResp ();
void tabelaInicial ();
void escolha ();
void attTabela ();
void gerarDNVletra (char resposta0);

char perguntas[7][89] = {"Qual jogo famoso tem um encanador como protagonista?","Quem foi o ganhador do GOTY do ano passado?","Que franquia famosa de jogos de futebol e (re)lancada todos os anos?","Qual o nome da franquia de jogos sobre yakuza's?","Qual o nome da famosa franquia de jogos onde voce controla animais em batalhas dolorosas?","Em que ano foi lancado GTA 5?","Qual o nome da franquia de jogos onde os personagens gritam PERSOONAAAA?"};
char respostas[7][11] = {"mario","eldenring","fifa","yakuza","pokemon","2013","persona"};
int mododejogo, opcao, pontuacao, erros;
char universal[7][11];

void inicializarResp (){
    printf ("\nVoce deseja jogar acertando por letra ou palavras inteiras? '0' para letra e '1' para palavras inteiras: ");
    scanf ("%i", &mododejogo);
    fflush(stdin);
    for (int i = 0; i < 7; i++){
        for (int j = 0; j < 11; j++){
            if (respostas[i][j] != '\0'){
                universal[i][j] = ' ';
            }else{
                universal[i][j] = '*';                
            }
        }
    }
}

void tabelaInicial (){
    for (int i = 0; i < 7; i++){
        for (int j = 0; j < 11; j++){
            printf ("|%c |", universal[i][j]);
        }
        printf ("\n");
    }       
    escolha();
}

void escolha (){
    printf ("\nQual pergunta deseja escolher? de 1 a 7\n");
    for (int i = 0; i < 7; i++){
        printf ("\n%i.", i+1);
        for (int j = 0; j < 89; j++){
            printf ("%c", perguntas[i][j]);
        }
    }
    printf ("\n");
    scanf ("%i", &opcao);
    fflush(stdin);
    attTabela();
}
void attTabela (){
    char resposta0, resposta1[10];
    if (mododejogo == 0){
        printf ("\nDigite a letra: ");
        scanf ("%c", &resposta0);
        fflush(stdin);
        printf ("\n");
        gerarDNVletra(resposta0);
    }else if(mododejogo == 1){
        printf ("\nDigite a resposta (palavra completa): ");
        gets(resposta1);
        fflush(stdin); 
        printf ("\n");
        if (!strcmp(resposta1, respostas[opcao-1])){
            strcpy(universal[opcao-1], respostas[opcao-1]);
            int tamanho = strlen(respostas[opcao-1]);
            universal[opcao-1][tamanho] = '*';
            pontuacao++;
            if (pontuacao != 7){
                tabelaInicial();
            }else{
                for (int i = 0; i < 7; i++){
                    for (int j = 0; j < 11; j++){
                        printf ("|%c |", universal[i][j]);
                    }   
                printf ("\n");
                }
                printf ("\nVitoria!!!");    
            }
        }else{
            printf ("Resposta errada");
        }  
    }
}

void gerarDNVletra (char resposta0){
    int acertou = 0;
    for (int i = 0; i < 25; i++){
        if (respostas[opcao-1][i] == resposta0 && universal[opcao-1][i] != resposta0){
            universal[opcao-1][i] = resposta0;
            acertou = 1;
            pontuacao++;
            break; 
        }
    }
    if (acertou == 0){
        erros++;
        if (erros != 7){
            printf ("\nErrou, chances disponiveis: %i\n", 7-erros);
            tabelaInicial();
        }else{
            printf ("\nDerrota");
        }
    }else{
        int pontmax = strlen(respostas[0])+strlen(respostas[1])+strlen(respostas[2])+strlen(respostas[3])+strlen(respostas[4])+strlen(respostas[5])+strlen(respostas[6]);
        if (pontuacao != pontmax){
            tabelaInicial();
        }else{
            for (int i = 0; i < 7; i++){
                for (int j = 0; j < 11; j++){
                    printf ("|%c |", universal[i][j]);
                }
                printf ("\n");
            }
            printf ("\nVitoria!!!");
        }
    }
}