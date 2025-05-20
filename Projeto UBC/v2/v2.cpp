#include <stdio.h>
#include <math.h>

#define QTD_ALUNOS 100

int main() 
{
	float A1[QTD_ALUNOS], A2[QTD_ALUNOS], AF[QTD_ALUNOS], NF[QTD_ALUNOS], NFD[QTD_ALUNOS];
    int i;

	    for (i = 0; i < QTD_ALUNOS; i++) 
		{
	        printf("\n--- Aluno %d ---\n", i + 1);
	
			printf("Digite o valor da nota do aluno na A1:");
	    	scanf("%f", &A1[i]);
	
	    	while (A1[i] >= 6)
	    	{
	        	printf("A nota deve ser menor que 6, digite a nota correta:");
	        	scanf("%f", &A1[i]);
	    	}
	    
	    	printf("Digite o valor da nota do aluno na A2:");
	    	scanf("%f", &A2[i]);
	
	    	while (A2[i] >= 6)
	    	{
	    	
	        	printf("A nota deve ser menor que 6, digite a nota correta:");
	        	scanf("%f", &A2[i]);
	    	}
	    
	    	NF[i] = A1[i]+A2[i];
	    
	    	int NFA = (int)round(NF[i]);
	    
	    	switch (NFA)
			{
				case 6:
				case 7:
				case 8:
				case 9:
				case 10:
					printf("Aprovado!");
					break;
				case 5:
				case 4:
				case 3:
				case 2:
				case 1:
				case 0:	
					printf("O aluno deve realizar a AF!!! \n");
					break;
	
			}
		
			if (NFA <= 5)
			{
				printf("Digite o valor da nota do aluno na AF:");
				scanf("%f", &AF[i]);
			
				while (AF[i] >= 6)
	    		{	
	        		printf("A nota deve ser menor que 6, digite a nota correta:");
	        		scanf("%f", &AF[i]);
	    		}
	    	
				if (A1[i] > A2[i])
				{
					NFD[i] = A1[i] + AF[i];
				}
				else 
				{
					NFD[i] = A2[i] + AF[i];
				}
			
				int NFDA = (int)round(NFD[i]);
		
				switch (NFDA)
				{
					case 6:
					case 7:
					case 8:
					case 9:
					case 10:
						printf("Aprovado com uso de AF!");
						break;
					case 5:
				    case 4:
				    case 3:
				    case 2:
				    case 1:
				    case 0:	
						printf("O aluno ficou de RP!!");
						break;
				}
	    }
	}

    return 0;
}
