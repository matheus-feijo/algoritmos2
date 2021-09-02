#include <stdio.h>
#include<stdlib.h>
#include<string.h>

void to_Lower(char* login){
    int tamanho = strlen(login);
    for(int c=0;c<tamanho;c++){
        if(login[c] >= 65 && login[c] <= 90){
            login[c] += 32; 
        }
    }
}

char* pegando_ultimoNome(char nome[100],int tam_nome){
	int i,j=0,k,aux;
	char ultNome1[100];
	char* ultNome;

	ultNome = (char*) malloc(100*sizeof(char));

	for(i=0;i<tam_nome;i++){
		if(nome[i]==' '){
			for(k=0;k<j;k++){
				ultNome1[k] = ' ';
			}

		}else{
			ultNome1[j] = nome[i];
			j++;
		}
	}
	//tirando os espaços consequentemente limpando a string
	j=0;
	
	for(i=0;i<tam_nome;i++){
		if(ultNome1[i] != ' '){
			ultNome[j] = ultNome1[i];
			j++;
		}

	}
	//printf("Ultimo nome = %s\n",ultNome);

	return ultNome;
}

char* estrutra_login(char str1[50],int tam,char nome[100]){
	int i,j=0,k,cont,tam_nome,tamLetras;
	char* nomeComp;
	tam_nome = strlen(nome);

	nomeComp = (char*) malloc(50*sizeof(char));

	if(tam ==2){
		nomeComp[j] = str1[0];
		j++;
		for(i=0;i<tam_nome;i++){
			if(nome[i] == str1[1] && nome[i-1]==' '){
				for(k=i;k<tam_nome;k++){
					nomeComp[j] = nome[k];
					j++;
				}
			}
		}
		return nomeComp;

	}else{
		nomeComp[j] = str1[0];
		j++;
		nomeComp[j] = str1[1];
		j++;

		strcat(nomeComp,pegando_ultimoNome(nome,tam_nome));

		return nomeComp;
	}
	return 0;
}

int tirar_conector(char aux[20]){
	
	if(strcmp(aux,"e")==0 || strcmp(aux,"de")==0 || strcmp(aux,"di")==0 ||strcmp(aux,"do")==0 || strcmp(aux,"da")==0 || strcmp(aux,"dos")==0 || strcmp(aux,"das")==0){
		return 2;
	}else{
		return 1;
	}
}

char* primeira_letra(char nome[100],int tam){
	int i,k=0,j,v=0,param,cont=0,param1;
	char* guardaInicial;
	char aux[20];

	guardaInicial = (char*) malloc(50*sizeof(char));

		for(i=0;i<tam;i++){
			if(i==0){
				guardaInicial[k] = nome[i];
				k++;
			}
			if(nome[i] == ' '){
				cont++;
				for(j=i+1;j<tam;j++){
					if(nome[j]==' '){
						cont++;
						j=tam;
					}else{
						aux[v] = nome[j];
						v++;
					}
				}
				
				if(v>3 || (aux[0]!='d' && aux[0]!='e')){
					guardaInicial[k] = nome[i+1];
					k++;
					v=0;
					aux[v] = '\0';
				}else{
					param = tirar_conector(aux);

					if(param==2){
						v=0;
						aux[v]='\0';
					}			
				}
			}
		}
	return guardaInicial;
}

int main(void) {
	char nome[100],str1[50],login[50];
	int tam;

	printf("digite seu nome: ");
	scanf("%[^\n]",nome);
	tam = strlen(nome);

	strcpy(str1,primeira_letra(nome,tam));
	
	tam = strlen(str1);

	strcpy(login,estrutra_login(str1,tam,nome));

	to_Lower(login);
	
	//RESPOSTA

	printf("login: %s\n",login);

  return 0;
}