#include <stdio.h>

int main(){

	int MatrizCinema[10][10], primeiraDecisao = -1, segundaDecisao = -1, linha, coluna, fila = 0, cadeira = 0, tipo = 0, voltarMenu = 0, ingressoPopularInteira = 0;
	int ingressoPopularMeia = 0, ingressoComumMeia = 0, alfabeto = 65, ingressoComumInteira = 0, ingressoVipMeia = 0, ingressoVipInteira = 0;
	float ingresso = -1,totalPopular, totalComum, totalVip;

	printf("Algoritmo para gerenciar uma sala de cinema.\n");

	for (linha = 0; linha < 10; linha++)
	{
		for ( coluna = 0; coluna < 10; coluna++)
			{
				MatrizCinema[linha][coluna] = 0;
			}
	}


    while( ingresso < 0 ){
        printf("Digite o preco do ingresso:\n");
        scanf("%f", &ingresso);
        if( ingresso < 0){
            printf("Erro. Digite novamente o valor do ingresso.\n");
            printf("\n");
        }
    }

    while(voltarMenu == 0){
        tipo = 0;
        fila = 0;
        cadeira = 0;
        totalComum = 0;
        totalPopular = 0;
        totalVip = 0;
        ingressoComumInteira = 0;
        ingressoComumMeia = 0;
        ingressoPopularInteira = 0;
        ingressoPopularMeia = 0;
        ingressoVipInteira = 0;
        ingressoVipMeia = 0;
        alfabeto = 65;

        for(linha = 0; linha < 10; linha++){
            for(coluna = 0; coluna < 10; coluna++){
                if( MatrizCinema[linha][coluna] == 3){
                    MatrizCinema[linha][coluna] = 1;
                }
                if( MatrizCinema[linha][coluna] == 4){
                    MatrizCinema[linha][coluna] = 2;
                }
                if( MatrizCinema[linha][coluna] == 5){
                    MatrizCinema[linha][coluna] = 0;
                }
            }
        }

        while( primeiraDecisao < 0 || primeiraDecisao > 3 ){
            printf("Digite a opcao desejada.\n");
            printf("0 - Sair.\n");
            printf("1 - Vender ou Liberar uma cadeira.\n");
            printf("2 - Apresentar a disposicao  das cadeiras.\n");
            printf("3 - Apresentar o resumo financeiro.\n");
            scanf("%d", &primeiraDecisao);

            if( primeiraDecisao < 0 || primeiraDecisao > 3 ){
                printf("Erro. Digite novamente o valor do ingresso.\n");
                printf("\n");
            }
        }

        switch( primeiraDecisao ){

            case 0:

                printf("Encerrando programa !\n");
                return 0;

            case 1:

                while( segundaDecisao < 1 || segundaDecisao > 2 ){
                    printf("Digite a opcao desejada.\n");
                    printf("1 - Vender uma cadeira.\n");
                    printf("2 - Liberar uma cadeira.\n");
                    scanf("%d", &segundaDecisao);

                    if( (segundaDecisao < 1 ) || ( segundaDecisao > 2 ) ){
                        printf("Erro. Digite novamente o valor do ingresso.\n");
                        printf("\n");
                    }
                }

                switch( segundaDecisao ){


                    case 1:
                            //~Vender
                        while( (( fila < 1 ) || ( fila > 10 ))  ){
                            printf("Qual fila ? ( Digite apenas numero ex:1 - para Fila 1 ) \n");
                            scanf("%d", &fila);
                        }
                        while(  (( cadeira < 1 ) || ( cadeira > 10 )) ){
                            printf("Qual cadeira ? ( Digite apenas numero ex: 2 - para cadeira 2) \n");
                            scanf("%d", &cadeira);
                        }

                        fila--;
                        cadeira--;

                        while( tipo < 1 || tipo > 2){
                            printf("O usuario tem direito a meia ? 1 - Sim/ 2- Nao \n");
                            scanf("%d", &tipo);
                            if( (tipo < 1) || (tipo > 2) ){
                                printf("Erro. Digite novamente de acordo com o solicitado\n");
                            }
                        }

                        if( MatrizCinema[fila][cadeira] > 0){
                            printf("O lugar ja esta ocupado.\n");
                        }
                        else{
                            MatrizCinema[fila][cadeira]= tipo;
                            printf("cadeira %d da fila %d comprada.\n",cadeira+1,fila+1);
                        }

                        break;
                    case 2:

                        while( (( fila < 1 ) || ( fila > 10 ))  ){
                            printf("Qual fila ? ( Digite apenas numero ex:1 2 para 1-Fila 2-Coluna) \n");
                            scanf("%d", &fila);
                        }
                        while(  (( cadeira < 1 ) || ( cadeira > 10 )) ){
                            printf("Qual cadeira ? ( Digite apenas numero ex:1 2 para 1-Fila 2-Coluna) \n");
                            scanf("%d", &cadeira);
                        }

                        fila--;
                        cadeira--;

                        if( MatrizCinema[fila][cadeira] > 0){
                            MatrizCinema[fila][cadeira] = 0;
                            printf("Lugar esvaziado.\n");
                        }
                        else{
                            printf("O lugar esta vazio.\n");
                            printf("\n");
                        }
                        break;
                }
                break;

            case 2:
                //~Imprimir cadeiras
                printf("Cadeiras: \n\n\t");

                for(linha = 0; linha < 10; linha ++)
                    printf("%d\t", linha + 1);

                printf("\n");

                for (linha = 0; linha < 10; linha++){
                    printf("%c\t",alfabeto+linha);
                    for ( coluna = 0; coluna < 10; coluna++){
                        printf("%d\t", MatrizCinema[linha][coluna] );
                    }
                    printf("\n");
                }

                break;

            case 3:

                //~Printar resumo financeiro
                //~~Extrair ingressos populares
                for(linha = 0; linha < 2; linha++){
                    for( coluna = 0; coluna < 10; coluna++){
                        if( MatrizCinema[linha][coluna] == 1){
                            ingressoPopularMeia = ingressoPopularMeia + 1;
                        }
                        if( MatrizCinema[linha][coluna] == 2){
                                ingressoPopularInteira = ingressoPopularInteira + 1;
                        }
                    }
                }

                //~Extrair ingressos vips
                for( linha = 4; linha < 8; linha++){
                    for( coluna = 2; coluna < 8; coluna++){
                        if( MatrizCinema[linha][coluna] == 1){
                            ingressoVipMeia = ingressoVipMeia + 1;
                            MatrizCinema[linha][coluna] = 3;
                        }
                        if( MatrizCinema[linha][coluna] == 2){
                            ingressoVipInteira = ingressoVipInteira + 1;
                            MatrizCinema[linha][coluna] = 4;
                        }
                        if( MatrizCinema[linha][coluna] == 0){
                            MatrizCinema[linha][coluna] = 5;
                        }
                    }
                }

                //~Extrair ingressos comuns
                for( linha = 2; linha < 10; linha++){
                    for( coluna = 0; coluna < 10; coluna++){
                        if( MatrizCinema[linha][coluna] > 0 ){
                            if( MatrizCinema[linha][coluna] < 3 ){
                                if( MatrizCinema[linha][coluna] == 1){
                                    ingressoComumMeia = ingressoComumMeia + 1;
                                }
                                if( MatrizCinema[linha][coluna] == 2){
                                    ingressoComumInteira = ingressoComumInteira + 1;
                                }
                            }
                        }
                    }
                }
                //~Mostrar resumo financeiro
                printf("Resumo financeiro:\n");
                printf("Preco do ingresso: %.2f reais (comum), %.2f reais (popular), %.2f reais (vip)\n", ingresso, ingresso-(ingresso*0.25), ingresso+(ingresso*0.30));
                printf("\n");
                printf("Ingressos populares:\n");
                totalPopular = ingressoPopularInteira*(ingresso-(ingresso*0.25))  + (ingressoPopularMeia*(ingresso-(ingresso*0.25)))*0.5;
                printf(" %d inteiras / %d meias: Total: %.2f \n", ingressoPopularInteira, ingressoPopularMeia, totalPopular);
                printf("\n");
                printf("Ingressos VIP:\n");
                totalVip = ingressoVipInteira*(ingresso+(ingresso*0.30))  + (ingressoVipMeia*(ingresso+(ingresso*0.30)))*0.5;
                printf(" %d inteiras / %d meias: Total: %.2f \n", ingressoVipInteira, ingressoVipMeia, totalVip);
                printf("\n");
                printf("Ingressos Comum:\n");
                totalComum = ingressoComumInteira*ingresso + ingressoComumMeia*ingresso*0.5;
                printf(" %d inteiras / %d meias: Total: %.2f \n", ingressoComumInteira, ingressoComumMeia, totalComum);
                printf("\n");
                printf("Total geral: %.2f\n", totalComum+totalPopular+totalVip);
                printf("\n");
                break;

        }

        printf("Deseja voltar ao inicio ? 0 - Sim / Qualquer outro valor - Nao\n");
        scanf("%d", &voltarMenu);
        if( voltarMenu == 0){
            primeiraDecisao = -1;
            segundaDecisao = -1;
        }
	}

    return 0;
}
