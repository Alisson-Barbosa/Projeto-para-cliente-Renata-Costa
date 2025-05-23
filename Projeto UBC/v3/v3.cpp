#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct fda {
		char nome[50];
		int rgm;
		int a1;
		int a2;
		int af;
	};
	
int main ()
{
	
	struct fda info_aluno[100];
    int opcao;
    int i, numero_de_alunos = 0 ;
    int rgm_busca;
    char status_de_aprovacao[20]; 
    int media;
    int media_af;
	int valido;
	char rgm_str[20];
    
    printf("\n BEM VINDO AO CALCULO DE MEDIA PARA SEUS ALUNOS!!!\n");
    
	do{
		printf("\n Escolha uma das opcoes para prosseguirmos:\n");
        printf("\n 1 - Registrar informacoes do aluno;\n");
        printf(" 2 - Apresentar lista de alunos;\n");
        printf(" 3 - Atualizar informacoes do aluno;\n");
        printf(" 4 - Remover aluno da lista;\n");
        printf(" 0 - Finalizar programa.\n");
        scanf("%d", &opcao);
			switch (opcao) 
		{
			case 1:
				if (numero_de_alunos < 100) { 
                    
					do {
					    valido = 1;
					    printf("Digite o nome do aluno (apenas letras): ");
					    scanf("%s", info_aluno[numero_de_alunos].nome);
					
					    for (int k = 0; k < strlen(info_aluno[numero_de_alunos].nome); k++) {
					        if (!isalpha(info_aluno[numero_de_alunos].nome[k])) {
					            printf("Nome invalido. Use apenas letras.\n");
					            valido = 0;
					            break;
					        }
					    }
					} while (!valido);
					
					
					
                    do {
					    valido = 1;
					    printf("Digite o RGM do aluno (apenas numeros): ");
					    scanf("%s", rgm_str);
					
					    for (int k = 0; k < strlen(rgm_str); k++) {
					        if (!isdigit(rgm_str[k])) {
					            printf("RGM invalido. Use apenas numeros.\n");
					            valido = 0;
					            break;
					        }
					    }
					} while (!valido);
					
					info_aluno[numero_de_alunos].rgm = atoi(rgm_str);
				    do {
                        printf("Digite a nota da A1 do aluno (1-5): ");
                        scanf("%d", &info_aluno[numero_de_alunos].a1);
                        if (info_aluno[numero_de_alunos].a1 <= 0 || info_aluno[numero_de_alunos].a1 >= 6) {
                            printf("Nota invalida. Digite novamente.\n");
                        }
                    } while (info_aluno[numero_de_alunos].a1 <= 0 || info_aluno[numero_de_alunos].a1 >= 6);

                    do {
                        printf("Digite a nota da A2 do aluno (1-5): ");
                        scanf("%d", &info_aluno[numero_de_alunos].a2);
                        if (info_aluno[numero_de_alunos].a2 <= 0 || info_aluno[numero_de_alunos].a2 >= 6) {
                            printf("Nota invalida. Digite novamente.\n");
                        }
                    } while (info_aluno[numero_de_alunos].a2 <= 0 || info_aluno[numero_de_alunos].a2 >= 6);
                    
					do {
                        printf("Digite a nota da AF do aluno (1-5, ou 0 se nao fez): ");
                        scanf("%d", &info_aluno[numero_de_alunos].af);
                        if (info_aluno[numero_de_alunos].af < 0 || info_aluno[numero_de_alunos].af >= 6) {
                            printf("Nota invalida. Digite novamente.\n");
                        }
                    } while (info_aluno[numero_de_alunos].af < 0 || info_aluno[numero_de_alunos].af >= 6);

                    numero_de_alunos++; 
                } else {
                    printf("Limite de alunos atingido.\n");
                }
				break;
			case 2:
				 printf("\n Lista de Alunos:\n");
                for (i = 0; i < numero_de_alunos; i++) {
                    media = (info_aluno[i].a1 + info_aluno[i].a2);
                    if (media < 6) {
                        if ( info_aluno[i].a1 >> info_aluno[i].a2){
                        	media = (info_aluno[i].a1 + info_aluno[i].af);
                        	if (media >= 6) {
	                        strcpy(status_de_aprovacao, "Aprovado com uso de af");
		                    } else {
		                        strcpy(status_de_aprovacao, "Reprovado com uso de af");
		                    }
						}else{
							media = (info_aluno[i].a2 + info_aluno[i].af);
							if (media >= 6) {
	                        strcpy(status_de_aprovacao, "Aprovado com uso de af");
		                    } else {
		                        strcpy(status_de_aprovacao, "Reprovado com uso de af");
		                    }
						}
                    } else {
	                    if (media >= 6) {
	                        strcpy(status_de_aprovacao, "Aprovado");
	                    } else {
	                        strcpy(status_de_aprovacao, "Reprovado");
	                    }
					}
                    
                    printf("Nome: %s, RGM: %d, Media: %d, Status: %s\n",
                           info_aluno[i].nome, info_aluno[i].rgm, media, status_de_aprovacao);
                }
				break;
			case 3:
				printf("Digite o RGM do aluno que deseja atualizar: ");
                scanf("%d", &rgm_busca);

                for (i = 0; i < numero_de_alunos; i++) {
                    if (info_aluno[i].rgm == rgm_busca) {
                        
						do {
						    valido = 1;
						    printf("Digite o nome do aluno (apenas letras): ");
						    scanf("%s", info_aluno[numero_de_alunos].nome);
						
						    for (int k = 0; k < strlen(info_aluno[numero_de_alunos].nome); k++) {
						        if (!isalpha(info_aluno[numero_de_alunos].nome[k])) {
						            printf("Nome invalido. Use apenas letras.\n");
						            valido = 0;
						            break;
						        }
						    }
						} while (!valido);
                        
						do {
						    valido = 1;
						    printf("Digite o novo RGM do aluno (apenas numeros): ");
						    scanf("%s", rgm_str);
						
						    for (int k = 0; k < strlen(rgm_str); k++) {
						        if (!isdigit(rgm_str[k])) {
						            printf("RGM invalido. Use apenas numeros.\n");
						            valido = 0;
						            break;
						        }
						    }
						} while (!valido);
	
						info_aluno[i].rgm = atoi(rgm_str);
                        
						do {
                            printf("Digite a nova nota da A1 do aluno (1-5): ");
                            scanf("%d", &info_aluno[i].a1);
                            if (info_aluno[i].a1 <= 0 || info_aluno[i].a1 >= 6) {
                                printf("Nota invalida. Digite novamente.\n");
                            }
                        } while (info_aluno[i].a1 <= 0 || info_aluno[i].a1 >= 6);

                        do {
                            printf("Digite a nova nota da A2 do aluno (1-5): ");
                            scanf("%d", &info_aluno[i].a2);
                            if (info_aluno[i].a2 <= 0 || info_aluno[i].a2 >= 6) {
                                printf("Nota invalida. Digite novamente.\n");
                            }
                        } while (info_aluno[i].a2 <= 0 || info_aluno[i].a2 >= 6);

                        do {
                            printf("Digite a nova nota da AF do aluno (1-5, ou 0 se nao fez): ");
                            scanf("%d", &info_aluno[i].af);
                            if (info_aluno[i].af < 0 || info_aluno[i].af >= 6) {
                                printf("Nota invalida. Digite novamente.\n");
                            }
                        } while (info_aluno[i].af < 0 || info_aluno[i].af >= 6);

                        printf("Informacoes do aluno atualizadas com sucesso!\n");
                        break;
                    }
                }
                if (i == numero_de_alunos) {
                    printf("Aluno nao encontrado.\n");
                }
				
				break;
			case 4:
				printf("Digite o RGM do aluno que deseja remover: ");
                scanf("%d", &rgm_busca);
                for (i = 0; i < numero_de_alunos; i++) {
                    if (info_aluno[i].rgm == rgm_busca) {
                        
                        for (int j = i; j < numero_de_alunos - 1; j++) {
                            info_aluno[j] = info_aluno[j + 1];
                        }
                        numero_de_alunos--; 
                        printf("Aluno removido com sucesso!\n");
                        break;
                    }
                }
                if (i == numero_de_alunos) {
                    printf("Aluno nao encontrado.\n");
                }
                
                
                break;
            case 0:
                
				printf("Finalizando o programa.\n");
                
				break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
	}while (opcao != 0);
	
	return 0 ;
	
}
