#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define TAMANHO_BUFFER 100
#define TAMANHO_MENSAGEM 150


// Função para enviar uma mensagem e armazená-la em um buffer
int enviarMensagem(char mensagem[]){

    if(strlen(mensagem) >= TAMANHO_BUFFER -1){
        printf("Erro: Tamanho da mensagem excede o tamanho do buffer.\n\n\n");
        return 1;
    }

    char buffer[TAMANHO_BUFFER]; // Buffer para armazenar a mensagem
    strcpy(buffer, mensagem); // Copia a mensagem para o buffer
    printf("\n\n\n A mensagem contida no buffer é: %s\n\n\n", buffer); // Exibe a mensagem armazenada no buffer
    return 0;
}

void receberMensagem(char buffer[]) {
    // Exibe o texto armazenado no buffer
    printf("Mensagem recebida: %s\n", buffer);
}


int main() {
    char mensagem[TAMANHO_MENSAGEM]; // Define um array para armazenar a mensagem
    printf("Tamanho do buffer: %ld\n", strlen(mensagem));
    char continuar = 'S';

    while (continuar == 'S' || continuar == 's')
    {
        printf("Digite a mensagem a ser enviada:");
        fgets(mensagem, TAMANHO_BUFFER, stdin); // Lê a mensagem fornecida pelo usuário

        // Chama a função para enviar a mensagem
        int resultado_envio = enviarMensagem(mensagem);

        if(resultado_envio == 1){
            break;
        }

        // Chama a função para receber a mensagem
        receberMensagem(mensagem);
       
        printf("Deseja enviar outra mensagem? (S/N): ");
        scanf(" %c", &continuar); // Espaço em branco antes de %c para ignorar a quebra de linha residual

        // Limpa o buffer de entrada
        printf("Limpando buffer de entrada...\n");
        while (getchar() != '\n');

        // Limpa o buffer de mensagem
        memset(mensagem, '\0', TAMANHO_BUFFER);

        // Imprime o valor do buffer de mensagem (agora limpo)
        printf("O valor do buffer de mensagem é: %lu\n", strlen(mensagem));
    }
    

    return 0;
}