#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct bloco_partidos{
	char sigla[3];
	char nome[50];
	int existe;

}partido;
struct estado{
	char sigla[1];
	char nome[50];

}estado;

struct congressista{
	char nome[50];
	int matricula;
	int voto;
	struct bloco_partidos partido;
	struct estado estado;
	int bancada;

}congressista;

int main (){

	struct congressista deputado[513];
	struct estado estados[26];
	struct bloco_partidos partidos[10];
	int cont = 0, aux =0 ;
	int menu = 0,sair = 0;
	int nump = 0 , numd = 0,votou = 0 ,confirmacao = 0,sim = 0 , nao =0;
	int matricula = 0,modo = 0;
	int bancada1s = 0, bancada1n = 0 ,bancada2s = 0, bancada2n = 0,bancada3s = 0, bancada3n = 0 ,bancada4s = 0, bancada4n = 0 , 
  		bancada5s = 0, bancada5n = 0 ;
	char sigla [26][1];

//estados	
	strcpy(estados[0].nome ,"Acre");					
	strcpy(estados[1].nome ,"Alagoas");
	strcpy(estados[2].nome ,"Amapa");
	strcpy(estados[3].nome ,"Amazonas");
	strcpy(estados[4].nome ,"Bahia");
	strcpy(estados[5].nome ,"Ceara");
	strcpy(estados[6].nome ,"Distrito federal");
	strcpy(estados[7].nome ,"Espirito santo");
	strcpy(estados[8].nome ,"Goias");
	strcpy(estados[9].nome ,"Maranhao");
	strcpy(estados[10].nome ,"Mato grosso");
	strcpy(estados[11].nome ,"Mato grosso do sul");
	strcpy(estados[12].nome ,"Minas gerais");
	strcpy(estados[13].nome ,"Para");
	strcpy(estados[14].nome ,"Paraiba");
	strcpy(estados[15].nome ,"Parana");
	strcpy(estados[16].nome ,"Pernambuco");
	strcpy(estados[17].nome ,"Piaui");
	strcpy(estados[18].nome ,"Rio de janeiro");
	strcpy(estados[19].nome ,"Rio grande do norte");
	strcpy(estados[20].nome ,"Rio grande do sul");
	strcpy(estados[21].nome ,"Rondonia");
	strcpy(estados[22].nome ,"Roraima");
	strcpy(estados[23].nome ,"Santa catarina");
	strcpy(estados[24].nome ,"Sao paulo");
	strcpy(estados[25].nome ,"Sergipe");
	strcpy(estados[26].nome ,"Tocantins");

//siglas
	strcpy(estados[0].sigla ,"ac");
	strcpy(estados[1].sigla ,"al");
	strcpy(estados[2].sigla ,"ap");
	strcpy(estados[3].sigla ,"am");
	strcpy(estados[4].sigla ,"ba");
	strcpy(estados[5].sigla ,"ce");
	strcpy(estados[6].sigla ,"df");
	strcpy(estados[7].sigla ,"es");
	strcpy(estados[8].sigla ,"go");
	strcpy(estados[9].sigla ,"ma");
	strcpy(estados[10].sigla ,"mt");
	strcpy(estados[11].sigla ,"ms");
	strcpy(estados[12].sigla ,"mg");
	strcpy(estados[13].sigla ,"pa");
	strcpy(estados[14].sigla ,"pb");
	strcpy(estados[15].sigla ,"pr");
	strcpy(estados[16].sigla ,"pe");
	strcpy(estados[17].sigla ,"pi");
	strcpy(estados[18].sigla ,"rj");
	strcpy(estados[19].sigla ,"rn");
	strcpy(estados[20].sigla ,"rs");
	strcpy(estados[21].sigla ,"ro");
	strcpy(estados[22].sigla ,"rr");
	strcpy(estados[23].sigla ,"sc");
	strcpy(estados[24].sigla ,"sp");
	strcpy(estados[25].sigla ,"se");
	strcpy(estados[26].sigla ,"to");

//limpando votos,matriculas e bancadas dos deputados antes do programa 
	for(cont == 0 ; cont <= 512 ; cont++ ){
		deputado[cont].matricula = 0;
		deputado[cont].voto = -1;
		deputado[cont].bancada = -1;
		deputado[cont].partido.existe = 0;
	}
	for(cont == 0 ; cont <=9 ; cont++){
		partidos[cont].existe = 0;

	}
//menu
	while(sair == 0){
	menu = 0;
		printf("---------------------------Menu------------------------\n");
		printf("1- Adicionar partido\n2- Adicionar Deputado\n3- Realizar voto de um deputado\n4- Escolher o modo de contabilização\n");
		printf("5- Contabilizar a votacao\n6- Contabilizar voto por partido\n7- Contabilizar voto por estado\n8- Contabilizar voto por bancada\n");
		printf("9- Sair\n");
		printf("-------------------------------------------------------\n");
		setbuf(stdin, NULL);
		scanf("%d", &menu);
//adicionando partido
		if(menu == 1){	
			if(nump <=9){
				printf("digite a sigla do partido (em letras minusculas)\n");
				setbuf(stdin, NULL);
				scanf("%s", partidos[nump].sigla);
				
				printf("Digite o nome do partido\n");
				setbuf(stdin, NULL);
				scanf("%s", partidos[nump].nome);
				partidos[nump].existe = 1;
				nump++;
			}else{
				printf("Numero maximo de partidos excedido\n");
			}
		}		
//adicionando deputado
		if(menu == 2){
			if(numd <= 512){
				printf("Digite o nome do deputado\n");
				setbuf(stdin, NULL);
				scanf(" %[^\n]s",deputado[numd].nome);

				printf("Digite a matricula\n");
				setbuf(stdin, NULL);
				scanf("%d",&deputado[numd].matricula);

				while(confirmacao != 1){
					printf("Digite a sigla do partido\n");
					setbuf(stdin, NULL);
					scanf("%s",deputado[numd].partido.sigla);					
					for(cont == 0 ; cont <= nump ; cont++){
						if(strcmp (deputado[numd].partido.sigla,partidos[cont].sigla) == 0){
							strcpy(deputado[numd].partido.nome , partidos[cont].nome);
							confirmacao = 1;
						}
					}
					if(confirmacao != 1){
						printf("Sigla partido invalida\n");
					}
				}
				confirmacao = 0;

				while(confirmacao != 1){
					printf("Digite a sigla do estado em letra minuscula!\n");
					setbuf(stdin, NULL);
					scanf("%s",deputado[numd].estado.sigla);	
					for(cont == 0 ; cont <=26 ; cont++){
						if(deputado[numd].estado.sigla == estados[cont].sigla){
							strcpy(deputado[numd].estado.nome , estados[cont].nome);
							confirmacao = 1;
						}
					}
					if(confirmacao != 1){
						printf("Sigla partido invalida\n");
					}


				}
				confirmacao = 0;
				
				while(confirmacao != 1){
					printf("Digite a bancada\n1- Ruralistas\n2- Religiosos\n3- Armamentistas\n4- Sindicalistas\n5- Maria vai com as outras\n");
					setbuf(stdin, NULL);
					scanf("%d",&deputado[numd].bancada);
					if(deputado[numd].bancada != 1 && deputado[numd].bancada != 2 && deputado[numd].bancada != 3 && deputado[numd].bancada != 4 && deputado[numd].bancada != 5){
						printf("Bancada invalida\n");
					}else{
						confirmacao = 1;
					}		
				}
				numd++;
			}else{
				printf("Numero maximo de deputados excedido\n");
			}
		}	
//realizar voto de um deputado
		if(menu ==3){
			printf("digite o numero de matricula do deputado\n");
			setbuf(stdin, NULL);
			scanf("%d",&matricula);
			for(cont = 0 ; cont <= numd ; cont++){
				if(matricula == deputado[cont].matricula && votou == 1){
					printf("sem maracutaia ... voto ja foi computado\n");
				}	
				if(matricula == deputado[cont].matricula && votou == 0){
					printf("digite o voto do deputado %s\n",deputado[cont].nome);
					setbuf(stdin, NULL);
					scanf("%d",&deputado[cont].voto);
					if(deputado[cont].voto != 0 && deputado[cont].voto != -1 && deputado[cont].voto != 2 ){
						printf("voto invalido\n");
					}else{
						votou = 1;
					}
				}
            }
            if(votou == 0){
            	printf("Matricula invalida\nDeputado nao encontrado\n");

            }
		}
//escolher modo de contabilizacao
		if(menu == 4){
			printf("digite o modo de contabilizacao\n1- Maioria Simples (Metade dos votos dos presentes +1)\n2- 2/3 dos	votos válidos\n");
			setbuf(stdin, NULL);
			scanf("%d", &modo);
		}	
		if(menu == 5){
			if(modo == 1){
				for(cont = 0 ; cont <= 512 ; cont++){
					if(deputado[cont].voto == 0){
						sim++;
					}
					if(deputado[cont].voto == 1 || deputado[cont].voto == 2){
						nao++;
					}

				}
				if(sim>nao){
					printf("impeachment aprovado\n");
				}else{
					printf("impeachment negado\n");
				}
			}
			if(modo == 2){
				for(cont = 0 ; cont <= 512 ; cont++){
					if(deputado[cont].voto == 0){
						sim++;
					}
					if(deputado[cont].voto == 1 || deputado[cont].voto == 2){
						nao++;
					}

				}
				if(sim >= numd*(2/3)){
					printf("impeachment aprovado\n");
				}else{
					printf("impeachment negado\n");
				}
			}
			if(modo != 1 && modo != 2){
				printf("modo ainda não computado\n");
			}
		}
//contabilizar votos por partido		
		if(menu == 6){
			sim =0;
			nao =0;
			for(cont == 0 ; cont <= nump ; cont++){	
				for(aux == 0 ; aux <= numd ; aux ++){
					if(deputado[aux].partido.sigla == partidos[cont].sigla){
						if(deputado[aux].voto == 0){
							sim++;
						}
						if(deputado[aux].voto == 1 || deputado[aux].voto == 2){
							nao++;
						}

					}
				}
				printf("Valor votos sim do partido %s: %d\n",partidos[cont].nome,sim);
				printf("Valor vatos nao do partido %s: %d\n",partidos[cont].nome,nao);

			}

		}
//contabilizar voto por estado
		if(menu == 7){
			sim =0;
			nao =0;
			for(cont == 0 ; cont <= 26 ; cont++){	
				for(aux == 0 ; aux <= numd ; aux ++){
					if(deputado[aux].estado.sigla == estados[cont].sigla){
						if(deputado[aux].voto == 0){
							sim++;
						}
						if(deputado[aux].voto == 1 || deputado[aux].voto == 2){
							nao++;
						}

					}
				}
				printf("Valor votos sim do estado %s: %d\n",estados[cont].nome,sim);
				printf("Valor vatos nao do estado %s: %d\n",estados[cont].nome,nao);

			}
		}
//contabilizar votos por bancada			
		if(menu == 8){
			sim =0;
			nao =0;
			for(aux == 0 ; aux <= numd ; aux ++){
				if(deputado[aux].bancada == 1){
					if(deputado[aux].voto == 0){
						bancada1s++;
					}
					if(deputado[aux].voto == 1 || deputado[aux].voto == 2){
						bancada1n++;
					}

				}
				if(deputado[aux].bancada == 2){
					if(deputado[aux].voto == 0){
						bancada2s++;
					}
					if(deputado[aux].voto == 1 || deputado[aux].voto == 2){
						bancada2n++;
					}

				}
				if(deputado[aux].bancada == 3){
					if(deputado[aux].voto == 0){
						bancada3s++;
					}
					if(deputado[aux].voto == 1 || deputado[aux].voto == 2){
						bancada3n++;
					}

				}
				if(deputado[aux].bancada == 4){
					if(deputado[aux].voto == 0){
						bancada4s++;
					}
					if(deputado[aux].voto == 1 || deputado[aux].voto == 2){
						bancada4n++;
					}

				}
				if(deputado[aux].bancada == 5){
					if(deputado[aux].voto == 0){
						bancada5s++;
					}
					if(deputado[aux].voto == 1 || deputado[aux].voto == 2){
						bancada5n++;
					}

				}																				
			}
			printf("Valor votos sim da bancada dos ruralistas : %d\n",bancada1s);
			printf("Valor vatos nao da bancada dos ruralistas : %d\n",bancada1n);

			printf("Valor votos sim da bancada dos religiosos : %d\n",bancada2s);
			printf("Valor vatos nao da bancada dos Religiosos : %d\n",bancada2n);
			
			printf("Valor votos sim da bancada dos armamentistas : %d\n",bancada3s);
			printf("Valor vatos nao da bancada dos armamentistas : %d\n",bancada3n);
			
			printf("Valor votos sim da bancada dos sindicalistas : %d\n",bancada4s);
			printf("Valor vatos nao da bancada dos sindicalistas : %d\n",bancada4n);
			
			printf("Valor votos sim da bancada dos maria vai com as outras : %d\n",bancada5s);
			printf("Valor vatos nao da bancada dos maria vai com as outras : %d\n",bancada5n);

			
		}										
	}
}