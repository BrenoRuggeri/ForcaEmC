#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <time.h>
#include "forca.h"

// Variaveis Globais

char palavraRodada[TAMANHO_PALAVRA];
char chutesUsuario[TAMANHO_CHUTE];
int tentativaUsuario = 0;


// Função de abertura do programa

void aberturaJogo(){

    printf("================================\n");
    printf("|  BEM-VINDO AO JOGO DA FORCA  |\n");
    printf("================================\n\n");
}

// Função para adicionar palavras ao banco de dados

void adicionaPalavra(){

    int resposta = 1;

    printf("Você deseja adicionar mais palavras ao seu banco de dados ?\n");
    printf("Digite (1) para sim e (0) para não\n");
    scanf("%d",&resposta);

    if (resposta == 1){

        char novaPalavra[TAMANHO_PALAVRA];
        
        printf("Qual a nova palavra que você deseja adicionar ao jogo ? \n");
        scanf("%s", novaPalavra);

        FILE* f;

        f = fopen("palavrasJogo.txt", "r+");
        if (f == 0){
            printf("Falha ao comunicar com o banco de dados \n\n");
    
            exit(1);
        }

        int qtdPalavras;
        fscanf(f,"%d",&qtdPalavras);
        qtdPalavras++;

        fseek(f, 0, SEEK_SET);
        fprintf(f,"%d",qtdPalavras);

        fseek(f, 0, SEEK_END);
        fprintf(f,"\n%s",novaPalavra);

        fclose(f);


    }else {
        printf("Ok, você decidiu por não adicionar mais palavras ao jogo\n");
    }
}

// Função para pedir a palavra da rodada

void pedirPalavra(){

    FILE* f;

    f = fopen("palavrasJogo.txt", "r");  
    if (f == 0){
        printf("Falha ao comunicar com o banco de dados \n\n");

        exit(1);
    }

    int qtdPalavras;
    fscanf(f,"%d",&qtdPalavras);

    srand(time(0));

    int numeroRandomico = rand() % qtdPalavras;

    for(int i=0;i<=numeroRandomico;i++){
        fscanf(f,"%s", palavraRodada);
    }

    fclose(f);
}

// Função para pedir o chute do usuário

void chuta(){

    char chute;

    printf("Chute uma letra: \n");
    scanf(" %c",&chute);
    
    chutesUsuario[tentativaUsuario] = chute;
    tentativaUsuario++;
}

// Função para verificar o chute do usuário

int verificaChute(char letra){

    int descobriu = 0, j = 0;

    for(j; j< tentativaUsuario; j++){
        if(chutesUsuario[j] == letra){
            descobriu = 1;
            break;
        }
    }

    return descobriu;

}

void jogo(){

    int erros = contadorErros();

    printf("  _______\n");
    printf(" |/      |\n");
    printf(" |      %s\n", (erros >= 1 ? "(_)" : ""));
    printf(" |      %s\n", (erros >= 4 ? "\\|/" : (erros == 3 ? "|" : (erros == 2 ? "|" : ""))));
    printf(" |       %s\n", (erros >= 3 ? "|" : ""));
    printf(" |      %s\n", (erros >= 5 ? "/ \\" : (erros == 4 ? "/" : "")));
    printf(" |\n");
    printf("_|___\n");

    for(int i = 0; i < strlen(palavraRodada);i++){

        int descobriu = verificaChute(palavraRodada[i]);

        if(descobriu){
            printf("%c",palavraRodada[i]);
        }else{
            printf("_ ");
        }

    }
    printf("\n");

}

int contadorErros (){
    int erros = 0;

    for(int i = 0; i < tentativaUsuario;i++){

        int pertence = 0;

        for(int j = 0; j < strlen(palavraRodada);j++){
            if(chutesUsuario[i] == palavraRodada[j]){

                pertence = 1;
                break;
    
            }
        }

        if(!pertence){
            erros++;
        }   
    }
    return erros;
}

int perdeu(){

    return contadorErros() >= 5;   
}

int ganhou(){

    for(int i=0; i < strlen(palavraRodada);i++){

        if(!verificaChute(palavraRodada[i])){
            return 0;
        }
    }

    return 1;
}

int main() {

        aberturaJogo();
        pedirPalavra();

    do{
        chuta();
        jogo();

    } while(!ganhou() && !perdeu());

    if(ganhou()){
        printf("Parabéns ! Você Ganhou ! \n");
    }else{
        printf("Você Perdeu a palavra era (%s), continue jogando !\n",palavraRodada);
    }
    adicionaPalavra();
}