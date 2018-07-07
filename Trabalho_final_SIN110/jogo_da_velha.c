#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

// ----------------------
// trabalho final SIN 110
// EVERTON HHENRIQUE RIBEIRO DA SILVA
// MATEUS VIEIRA DA SILVA
// PAULO VITOR DA SILVA NERES
// ----------------------

typedef struct label{
    char matrizX[4][4];
    char matrizBola[4][4];
    char matrizTabuleiro[20][20];
    int escolha;
    int jogadas;
    int player;
    char valida_opcao[11];
    char jogador_1[11];
    char jogador_2[11];
    char computador[11];
    int modo;
    int num_jogadores;
    char **nomes_jogadores;
    int contador;
    int num_partidas;
    int i_torn;
    int j_torn;
    int *pontuacao;
}var;

//---------------------------------------------------------------------------------------
/*A função ganhar() preenche um vetor com as possibilidades de vitória e verifica,
utilizando a função search() se um dos players chegou à uma condição de vitória,
se isso ocorre passa para a função main(): o player vencedor ou velha
(para que esta possa imprimir o resultado do jogo.)*/
//---------------------------------------------------------------------------------------

int ganhar(char *p1,char *p2){
    char possDeGanhar[35];

    strcpy(possDeGanhar,"123,456,789,147,258,369,159,357");

    if(search(possDeGanhar,p1) == 3){
        return 1;
    }else if(search(possDeGanhar,p2) == 3){
        return 2;
    }else{
        return 0;
    }
}
//-----------------------------------------------------------------------------------------------------------------------
/* a funcao search faz comparacao entre os vetores se o primeiro for uma unidade a funcao busca correspondencia
em outro vetor, ja se vetor1 eh maior que 1 entao ele compara sequencias de tres, se cont for tres esiste uma combinacao
que resulte em um ganhador*/
//------------------------------------------------------------------------------------------------------------------------
int search(char *vetor1, char *vetor2){
    int i, j, k, cont=0;
    int aux;
    if((strlen(vetor1) > 1)) {
        for(i = 0;i < strlen(vetor1);i++){
            for(j = 0;j < strlen(vetor2);j++){
                if(vetor1[i]==vetor2[j]){
                    cont++;
                }

                if(cont == 3){
                    // alguem ganhou
                    return cont;
                }
                if(vetor1[i]== ','){
                    cont = 0;
                    break;
                }
            }
        }
        return cont;

    }else if(strlen(vetor1) == 1){
        for(i = 0;i < strlen(vetor2);i++){
            if(vetor1[0]==vetor2[i]){
                cont++;
            }
        }
        return cont;

    }
}



//-----------------------------------------------------------------------------------------
/*A função curso_do_jogo(), atualiza o tabuleiro conforme as posições vão sendo marcadas,
imprimindo novamente, a cada jogada, o tabuleiro.
A função curso_do_jogo() recebe como parâmetro matrizTabuleiro, pertencente à struct var*/
//-----------------------------------------------------------------------------------------

int curso_do_jogo(var *info){
    int i, j;
    // imprimindo a matriz

    for(i = 0; i < 20; i++){
        printf("\n");
        for(j = 0; j < 20; j++){
           printf("%c ",info->matrizTabuleiro[i][j]);
        }
    }
    printf("\n");
    return 0;
}
//-----------------------------------------------------------------------------------------



//---------------------------------------------------------------------------------------------------
/*A função validacao_opcao() verifica se o espaço escolhido pelo player ou pela máquina está vazio,
se estiver preenchido pede para que seja escolhida outra posição, caso contrário passa
para a função tabuleiro() a posição, para que esta coloque a marca no lugar especificado.*/
//---------------------------------------------------------------------------------------------------

int validacao_opcao(int num, var *info){
    switch(num){
        case 1:
            // verificando se o espaço esta vazio
            if(search("1",info->valida_opcao)== 0){
                // armazenando as jogadas do player
                if(info->player == 1){
                    strcat(info->jogador_1,"1");
                }else{
                    strcat(info->jogador_2,"1");
                }

                strcat(info->valida_opcao,"1");
                tabuleiro(0,6,0,info);
                system("cls");
                curso_do_jogo(info);
                break;
            }else{
                do{
                    printf("player* %d :\n",info->player);
                    scanf("%d",&num);

                }while(num == 1);
                validacao_opcao(num,info);
                break;


            }
        case 2:
            // verificando se o espaço esta vazio
            if(search("2",info->valida_opcao)== 0){
                // armazenando as jogadas do player
                if(info->player == 1){
                    strcat(info->jogador_1,"2");
                }else{
                    strcat(info->jogador_2,"2");
                }
                strcat(info->valida_opcao,"2");
                tabuleiro(7,13,0,info);
                system("cls");
                curso_do_jogo(info);
                break;
            }else{
                do{
                    printf("player* %d :",info->player);
                    scanf("%d",&num);

                }while(num == 2);
                validacao_opcao(num,info);
                break;
            }
        case 3:
            // verificando se o espaço esta vazio
            if(search("3",info->valida_opcao)== 0){
                // armazenando as jogadas do player
                if(info->player == 1){
                    strcat(info->jogador_1,"3");
                }else{
                    strcat(info->jogador_2,"3");
                }

                strcat(info->valida_opcao,"3");
                tabuleiro(14,20,0,info);
                system("cls");
                curso_do_jogo(info);
                break;
            }else{
                do{
                    printf("player* %d :",info->player);
                    scanf("%d",&num);

                }while(num == 3);
                validacao_opcao(num,info);
                break;
            }

        case 4:
            // armazenando as jogadas do player
            if(info->player == 1){
                strcat(info->jogador_1,"4");
            }else{
                strcat(info->jogador_2,"4");
            }
            // verificando se o espaço esta vazio
            if(search("4",info->valida_opcao)== 0){
                strcat(info->valida_opcao,"4");
                tabuleiro(0,6,6,info);
                system("cls");
                curso_do_jogo(info);
                break;
            }else{
                do{
                    printf("player* %d :",info->player);
                    scanf("%d",&num);

                }while(num == 4);
                validacao_opcao(num,info);
                break;
            }
        case 5:
            // verificando se o espaço esta vazio
            if(search("5",info->valida_opcao)== 0){
                if(info->player == 1){
                    strcat(info->jogador_1,"5");
                }else{
                    strcat(info->jogador_2,"5");
                }
                strcat(info->valida_opcao,"5");
                tabuleiro(7,13,6,info);
                system("cls");
                curso_do_jogo(info);
                break;
            }else{
                do{
                    printf("player* %d :",info->player);
                    scanf("%d",&num);

                }while(num == 5);
                validacao_opcao(num,info);
                break;
            }
        case 6:
            // verificando se o espaço esta vazio
            if(search("6",info->valida_opcao)== 0){
                // armazenando as jogadas do player
                if(info->player == 1){
                    strcat(info->jogador_1,"6");
                }else{
                    strcat(info->jogador_2,"6");
                }

                strcat(info->valida_opcao,"6");
                tabuleiro(14,20,6,info);
                system("cls");
                curso_do_jogo(info);
                break;
            }else{
                do{
                    printf("player* %d :",info->player);
                    scanf("%d",&num);

                }while(num == 6);
                validacao_opcao(num,info);
                break;
            }
        case 7:
            // verificando se o espaço esta vazio
            if(search("7",info->valida_opcao)== 0){
                // armazenando as jogadas do player
                if(info->player == 1){
                    strcat(info->jogador_1,"7");
                }else{
                    strcat(info->jogador_2,"7");
                }

                strcat(info->valida_opcao,"7");
                tabuleiro(0,6,13,info);
                system("cls");
                curso_do_jogo(info);
                break;
            }else{
                do{
                    printf("player* %d :",info->player);
                    scanf("%d",&num);

                }while(num == 7);
                validacao_opcao(num,info);
                break;
            }
        case 8:
            // verificando se o espaço esta vazio
            if(search("8",info->valida_opcao)== 0){
            	// armazenando as jogadas do player
                if(info->player == 1){
                    strcat(info->jogador_1,"8");
                }else{
                    strcat(info->jogador_2,"8");
                }

                strcat(info->valida_opcao,"8");
                tabuleiro(7,13,13,info);
                system("cls");
                curso_do_jogo(info);
                break;
            }else{
                do{
                    printf("player* %d :",info->player);
                    scanf("%d",&num);

                }while(num == 8);
                validacao_opcao(num,info);
                break;
            }
        case 9:
            // verificando se o espaço esta vazio
            if(search("9",info->valida_opcao)== 0){
                // armazenando as jogadas do player
                if(info->player == 1){
                    strcat(info->jogador_1,"9");
                }else{
                    strcat(info->jogador_2,"9");
                }

                strcat(info->valida_opcao,"9");
                tabuleiro(14,20,13,info);
                system("cls");
                curso_do_jogo(info);
                break;
            }else{
                do{
                    printf("player* %d :",info->player);
                    scanf("%d",&num);

                }while(num == 9);
                validacao_opcao(num,info);
                break;
            }
        default:
            system("cls");
            curso_do_jogo(info);
            info->jogadas = info->jogadas + 1;
            interacao_players(info);
    }
    return 0;
}
//------------------------------------------------------------------------------------



//-----------------------------------------------------------------------------------------------------
/*A função tabuleiro() contem os parametros a e b que sao respectivamente inicio de intervalo
e fim de intervalo. ja o parametro c e alinha da matriz a ser selecionada
com esse tres parametros eh possivel substituir uma matriz 4X4 em qualquer posicao da matriz ;*/
//-----------------------------------------------------------------------------------------------------

int tabuleiro(int a, int b,int c,var *info){
    int i, j, k=0;
    // substituindo por bola

    if(info->escolha == 1){
        if(b != 0){
            for(i = a + 1; i < b-1;i++){
                for(j= a + 1; j < b - 1; j++){
                    // a=0 b=6
                    if((b == 6)&&(c == 0)){
                        info->matrizTabuleiro[i][j] = info->matrizBola[i-1][k];
                        k++;
                    }
                    // b=0 a=6 c=6
                    if((b == 6)&&(c == 6)){
                        info->matrizTabuleiro[i+7][j] = info->matrizBola[i-1][k];
                        k++;
                    }
                    // a=0 b=6 c=13
                    if((b == 6)&&(c == 13)){
                        info->matrizTabuleiro[i+14][j] = info->matrizBola[i-1][k];
                        k++;
                    }
                    // a=7 b=13
                    if((b == 13)&&(c == 0)){
                        info->matrizTabuleiro[i-7][j] = info->matrizBola[i-8][k];
                        k++;
                    }
                    // a=7 b=13 c=6
                    if((b == 13)&&(c == 6)){
                        info->matrizTabuleiro[i][j] = info->matrizBola[i-8][k];
                        k++;
                    }
                    // a=7 b=13 c=13
                    if((b == 13)&&(c == 13)){
                        info->matrizTabuleiro[i+7][j] = info->matrizBola[i-8][k];
                        k++;
                    }

                    // a=14 b =20
                    if((b == 20)&&(c ==0)){
                        info->matrizTabuleiro[i-14][j] = info->matrizBola[i-15][k];
                        k++;
                    }
                    // a=14 b=20 c=6
                    if((b == 20)&&(c == 6)){
                        info->matrizTabuleiro[i-7][j] = info->matrizBola[i-15][k];
                        k++;
                    }
                    // a=14 b=20 c=13
                    if((b == 20)&&(c == 13)){
                        info->matrizTabuleiro[i][j] = info->matrizBola[i-15][k];
                        k++;
                    }
                }
                k = 0;
            }

        }
    }else{
        if(b != 0){
            for(i = a + 1; i < b-1;i++){
                for(j= a + 1; j < b - 1; j++){
                    // a=0 b=6
                    if((b == 6)&&(c == 0)){
                        info->matrizTabuleiro[i][j] = info->matrizX[i-1][k];
                        k++;
                    }
                    // b=0 a=6 c=6
                    if((b == 6)&&(c == 6)){
                        info->matrizTabuleiro[i+7][j] = info->matrizX[i-1][k];
                        k++;
                    }
                    // a=0 b=6 c=13
                    if((b == 6)&&(c == 13)){
                        info->matrizTabuleiro[i+14][j] = info->matrizX[i-1][k];
                        k++;
                    }
                    // a=7 b=13
                    if((b == 13)&&(c == 0)){
                        info->matrizTabuleiro[i-7][j] = info->matrizX[i-8][k];
                        k++;
                    }
                    // a=7 b=13 c=6
                    if((b == 13)&&(c == 6)){
                        info->matrizTabuleiro[i][j] = info->matrizX[i-8][k];
                        k++;
                    }
                    // a=7 b=13 c=13
                    if((b == 13)&&(c == 13)){
                        info->matrizTabuleiro[i+7][j] = info->matrizX[i-8][k];
                        k++;
                    }

                    // a=14 b =20
                    if((b == 20)&&(c ==0)){
                        info->matrizTabuleiro[i-14][j] = info->matrizX[i-15][k];
                        k++;
                    }
                    // a=14 b=20 c=6
                    if((b == 20)&&(c == 6)){
                        info->matrizTabuleiro[i-7][j] = info->matrizX[i-15][k];
                        k++;
                    }
                    // a=14 b=20 c=13
                    if((b == 20)&&(c == 13)){
                        info->matrizTabuleiro[i][j] = info->matrizX[i-15][k];
                        k++;
                    }
                }
                k = 0;
            }
        }
    }


    printf("\n");

    return 0;

}
//------------------------------------------------------------------------------------



//----------------------------------------------------------------------------------------------------------
/*A função computer_ai() atua no modo single player marcando a posição correspondente à escolha da máquina.
Isso é feito utilizando a função rand(), que sorteia uma posição aleatória em um vetor com as posicoes vazias
*/
//-----------------------------------------------------------------------------------------------------------

int computer_ai(var *info){
    char todas_jogadas[10];
    char jogadas_poss[10];
    //char simula_jogador2[10];
    char aux[10];
    int cont, k = 0, i, j;


    strcpy(todas_jogadas,info->jogador_1);
    strcat(todas_jogadas,info->jogador_2);
    strcpy(jogadas_poss,"123456789");
    //strcpy(simula_jogador2,info->jogador_2);

    // verificando opcoes ja preechidas
    for(i = 0;i < strlen(jogadas_poss);i++){
        cont = 0;
        for(j = 0;j < strlen(todas_jogadas);j++){
            if(jogadas_poss[i] == todas_jogadas[j]){
                cont++;
            }
        }
        if(cont == 0){
            aux[k]= jogadas_poss[i];
            k++;
        }
    }
    aux[k+1] = '\0';

    srand(time(NULL));
    k = (rand()%(strlen(aux)));
   return aux[k];
}
//------------------------------------------------------------------------------------



//--------------------------------------------------------------------------------------------------
/*A função interacao_players() verifica quais são os players, seus movimentos e passa as informações
para a função validacao_posicao()*/
//--------------------------------------------------------------------------------------------------

int interacao_players(var *info){
    int num, cont;
    char aux;
    FILE* f;
    char texto[4];
    if(info->modo == 1){
        if(info->player == 1){
            printf("player %d :",info->player);
            scanf("%d",&num);
            validacao_opcao(num, info);
        }else{
            printf("computador");
            num = computer_ai(info);
            Sleep(1000);
            // convertendo para int
            switch(num){
                case 49:
                    num = 1;
                    break;
                case 50:
                    num = 2;
                    break;
                case 51:
                    num = 3;
                    break;
                case 52:
                    num = 4;
                    break;
                case 53:
                    num = 5;
                    break;
                case 54:
                    num = 6;
                    break;
                case 55:
                    num = 7;
                    break;
                case 56:
                    num = 8;
                    break;
                case 57:
                    num = 9;
                    break;
            }
            validacao_opcao(num, info);

        }

    }else if(info->modo == 2){
        printf("player %d :",info->player);
        scanf("%d", &num);
        validacao_opcao(num,info);
    }else{

        f = fopen("tabela.txt","r");
        if(f == NULL){
            printf("erro ao abrir arquivo!");
            exit(1);
        }
        // escaneando arquivo com os respectivos indices de nomes de usuario
       for(cont = 0; cont < info->num_partidas;cont++){
       		fscanf(f,"%d %s %d",&info->i_torn ,texto, &info->j_torn);
            if(info->contador == cont){
                break;
            }
       }
       if(info->player == 1){
            printf("%s ",info->nomes_jogadores[info->j_torn]);
       }else{
            printf("%s ",info->nomes_jogadores[info->i_torn]);
       }
       scanf("%d",&num);
       validacao_opcao(num,info);

    }


    return 0;
}
//---------------------------------------------------------------------------



//--------------------------------------------------------
// Funções com os componentes principais do jogo da velha:
// desenhar_tabu(), bola(), x()
//--------------------------------------------------------



// --------------------------------------------------------------------------------------------------------
/*Na função desenhar_tabu() o primeiro 'for' usado preenche a matriz com espaços em branco,
o segundo uso do 'for' substitui os espaços em branco, nos locais necessários, para formar o tabuleiro e
ao fim são inseridos numeros nas posições a serem ocupadas pela marcas 'X' e 'O' apenas para que fique mais
intuitivo.*/
// ---------------------------------------------------------------------------------------------------------
int desenhar_tabu(var *info){
    int i, j;
    // preechendo a matriz
    for(i = 0;i < 20;i++){
        for(j = 0; j < 20; j++){
            info->matrizTabuleiro[i][j] = ' ';
        }
    }

    // substituindo para formar o tabuleiro

    for(i = 0;i < 20;i++){
        for(j = 0; j < 20; j++){

                info->matrizTabuleiro[i][6] = '#';
                info->matrizTabuleiro[i][13] = '#';
                info->matrizTabuleiro[6][j] = '#';
                info->matrizTabuleiro[13][j] = '#';

        }
    }
    // inserindo guia de usuario
    info->matrizTabuleiro[3][3] = '1';
    info->matrizTabuleiro[10][3] = '4';
    info->matrizTabuleiro[16][3] = '7';
    info->matrizTabuleiro[3][10] = '2';
    info->matrizTabuleiro[3][16] = '3';
    info->matrizTabuleiro[10][10] = '5';
    info->matrizTabuleiro[10][16] = '6';
    info->matrizTabuleiro[16][10] = '8';
    info->matrizTabuleiro[16][16] = '9';
    // imprimindo matriz
    for(i = 0;i < 20;i++){
        printf("\n");
        for(j = 0; j < 20; j++){
           printf("%c ",info->matrizTabuleiro[i][j]);
        }
    }
    printf("\n");

    return 0;
}
//--------------------------------------------------------------------------------



//-----------------------------------------------------------------------------------------------------------------------
/*A funcão bola() desenha a marca bola que é formada por caracteres 'O' e ' ', primeiramente a matriz foi preenchida com
o caractere ' ', depois foram substituidos os locais necessários para que o formato ficasse parecido com um círculo. */
//-----------------------------------------------------------------------------------------------------------------------
int  bola(var *info){
    int i, j;
    // preenchendo a matriz
    for(i = 0; i< 4; i++){
        for(j = 0;j < 4;j++){
            info->matrizBola[i][j] = ' ';
        }
    }
    // substituindo para formar a bolinha

    info->matrizBola[0][1] = 'O';
    info->matrizBola[0][2] = 'O';

    info->matrizBola[1][0] = 'O';
    info->matrizBola[2][0] = 'O';

    info->matrizBola[1][3] = 'O';
    info->matrizBola[2][3] = 'O';

    info->matrizBola[3][1] = 'O';
    info->matrizBola[3][2] = 'O';

    return 0;


}
//-----------------------------------------------------------------------------------------



//--------------------------------------------------------------------------------------------------------
/*A função x() desenha, utilizando uma matriz, a marca 'X' utilizando os caracteres '\\' , '/' e ' '.  */
//--------------------------------------------------------------------------------------------------------
int x(var *info){
	int i, j;
	// substituindo para formar o X
	info->matrizX[0][0]='\\';
	info->matrizX[0][1]=' ';
	info->matrizX[0][2]=' ';
	info->matrizX[0][3]='/';
	info->matrizX[1][0]=' ';
	info->matrizX[1][1]='\\';
	info->matrizX[1][2]='/';
	info->matrizX[1][3]=' ';
	info->matrizX[2][0]=' ';
	info->matrizX[2][1]='/';
	info->matrizX[2][2]='\\';
	info->matrizX[2][3]=' ';
	info->matrizX[3][0]='/';
	info->matrizX[3][1]=' ';
	info->matrizX[3][2]=' ';
	info->matrizX[3][3]='\\';

	return 0;
}
//------------------------------------------------------------------------------------------



// -------------------------------------------------------------------------------------------------
/*A função menu_incial possibilita ao(s) jogador(es) escolher(em) entre multiplayer ou single player
e também escolher o sinal que irá usar para marcar suas posições no tabuleiro.*/
// -------------------------------------------------------------------------------------------------

int menu_inicial(var *info){
    int i, j;
    FILE* file;
    int cont = 0;

    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    printf("             JOGO DA VELHA \n");
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");

    printf("selecione o modo do jogo: \n");

    printf("-----------------------------------\n");
    printf("Modo[1] Singleplayer\n");
    printf("Modo[2] Multiplayer\n");
    printf("Modo[3] Torneio\n");
    printf("-----------------------------------\n");
    scanf("%d", &info->modo);
    system("cls");

    if(info->modo == 2){
        printf(">>>>>>>>>>>>>>>>>>>>>>\n");
        printf("     MULTIPLAYER\n");
        printf(">>>>>>>>>>>>>>>>>>>>>>\n");
        printf("Jogador 1 \n");
        printf("-------------------\n");
        printf("[1] para Escolher O \n");
        printf("[2] para Escolher X \n");
        printf("-------------------\n");
        scanf("%d", &info->escolha);

        if((info->escolha == 2)||(info->escolha == 1)){
            info->player = 1;
        }

    }
	if(info->modo == 1){
        printf(">>>>>>>>>>>>>>>>>>>>>>\n");
        printf("     SINGLEPLAYER\n");
        printf(">>>>>>>>>>>>>>>>>>>>>>\n");
        printf("Jogador 1 \n");
        printf("-------------------\n");
        printf("[1] para Escolher O \n");
        printf("[2] para Escolher X \n");
        printf("-------------------\n");
        scanf("%d", &info->escolha);

        if((info->escolha == 2)||(info->escolha == 1)){
            info->player = 1;
        }

    }
	if(info->modo==3){
        printf(">>>>>>>>>>>>>>>>>>>>>>\n");
        printf("      TORNEIO\n");
        printf(">>>>>>>>>>>>>>>>>>>>>>\n");
        printf("      NOSSO TORNEIO CONSISTE EM PONTOS CORRIDOS:\n");
        printf("          GANHADOR DA PARTIDA :3 PONTOS\n");
		printf("            EMPATE NA PARTIDA :1 PONTO\n");
		printf("E NO FINAL ELE SALVA EM UM ARQUIVO O GANHADOR DO TORNEIO\n");
		printf("\n");
        printf("\n");
		printf("Insira o numero de jogadores: \n");
        scanf("%d",&info->num_jogadores);
        fflush(stdin);
        if(info->num_jogadores==2){
        	system("cls");
        	printf("Nao e possivel criar um torneio com dois jogadores, utilize o modo multiplayer!\n");
        	printf("\n");
        	menu_inicial(&info);
		}
		if(info->num_jogadores==1){
			system("cls");
        	printf("Nao e possivel criar um torneio com um jogador, utilize o modo singleplayer!\n");
        	printf("\n");
			menu_inicial(&info);
		}
        info->nomes_jogadores = (char **) malloc(info->num_jogadores*sizeof(char));
        for(i = 0;i < info->num_jogadores;i++){
            info->nomes_jogadores[i] = (char*) malloc(15*sizeof(char));
        }

        printf("Insira o nome de cada jogador:\n");
        for(i = 0;i < info->num_jogadores;i++){
            printf("jogador:%d ",i+1);
            gets(info->nomes_jogadores[i]);
        }

        file = fopen("tabela.txt","w");
        if(file == NULL){
            printf("erro ao abrir arquivo!\n");
            exit(1);
        }
        info->num_partidas = 0;
        printf("\n         Partidas\n");
        printf("----------------------------\n");
        for(i = 0;i < info->num_jogadores;i++){
            for(j = i;j < info->num_jogadores;j++){
                if(j != i){
                    printf("%s X %s\n",info->nomes_jogadores[i],info->nomes_jogadores[j]);
                    fprintf(file,"%d x %d\n",i,j);
                    info->num_partidas++;
                }
            }
        }
        system("pause");
        fclose(file);

    }
    if((info->modo!=1)&&(info->modo!=2)&&(info->modo!=3)){
    	printf("ESCOLHA INVALIDA\n");
    	menu_inicial(&info);
	}

	// alocando memoria pontucao


    return 0;
}
//-----------------------------------------------------------------------------------------------



//-------------------------
// funcao principal main()
//-------------------------

//-----------------------------------------------------------------------------------------------------------------------------
/*Na função main() é declarada uma variavel do tipo var(info), para que se possa acessar as váriaveis da struct de mesmo nome.
Nela também estão as respostas para quando uma condição de vitória ou velha é alcançada.*/
//-----------------------------------------------------------------------------------------------------------------------------

int main(){
    char denovo;
    char texto[15];
    int ponto, i;
    var info;
    FILE* file;
    info.jogadas = 0;
    info.contador = 0;
    strcpy(info.valida_opcao,"g");
    strcpy(info.jogador_1," ");
    strcpy(info.jogador_2," ");
    // desenhando menu inicial
    menu_inicial(&info);
    // alocando memoria para pontuacao
    info.pontuacao = (int*)malloc(info.num_jogadores*sizeof(int));
    // colocando pontuacao
    for(i = 0;i < info.num_jogadores;i++){
        info.pontuacao[i] = 0;
    }
    system("cls");
    // preechendo as funções
    desenhar_tabu(&info);
    bola(&info);
    x(&info);
    // determinando numero de jogadas
    while(info.jogadas < 9){
        interacao_players(&info);

        info.jogadas = info.jogadas + 1;

        if(info.escolha!=1){
			info.escolha=1;
		}else{
			info.escolha=2;
		}

		if(info.player!=1){
			info.player=1;
		}else{
			info.player=2;
		}
		if(info.modo == 2){
            if(ganhar(info.jogador_1,info.jogador_2) == 1){
                printf("Jogador 1 Ganhou ! \n");
                break;
            }else if(ganhar(info.jogador_1,info.jogador_2)== 2){
                printf("Jogador 2 Ganhou ! \n");
                break;
            }
		}
		if(info.modo == 1){
		    if(ganhar(info.jogador_1,info.jogador_2) == 1){
                printf("Jogador 1 Ganhou ! \n");
                break;
            }else if(ganhar(info.jogador_1,info.jogador_2)== 2){
                printf("Computador Ganhou ! \n");
                break;
            }

		}
		if(info.modo==3){

		    if(ganhar(info.jogador_1,info.jogador_2) == 1){
                printf("%s Ganhou ! \n",info.nomes_jogadores[info.j_torn]);
                // atualizando pontuacao
                info.pontuacao[info.j_torn] += 3;


                Sleep(3000);
                info.contador++;
                if(info.contador != info.num_partidas){
                    info.jogadas = 0;
                }else{
                    break;
                }

                strcpy(info.valida_opcao," ");
                strcpy(info.jogador_1," ");
                strcpy(info.jogador_2," ");
                system("cls");
                desenhar_tabu(&info);
                bola(&info);
                x(&info);

            }else if (ganhar(info.jogador_1,info.jogador_2)== 2){

                printf("%s Ganhou ! \n",info.nomes_jogadores[info.i_torn]);
                info.pontuacao[info.i_torn] += 3;

                Sleep(3000);
                info.contador++;
                info.jogadas = 0;
                if(info.contador != info.num_partidas){
                    info.jogadas = 0;
                }else{
                    break;
                }
                strcpy(info.valida_opcao,"g");
                strcpy(info.jogador_1," ");
                strcpy(info.jogador_2," ");
                system("cls");
                desenhar_tabu(&info);
                bola(&info);
                x(&info);
            }
            if(info.jogadas==9){
				if(ganhar(info.jogador_1,info.jogador_2)==0){
			    	printf("Deu Empate ! \n");
			        info.pontuacao[info.i_torn] += 1;
					info.pontuacao[info.j_torn] += 1;

			        Sleep(3000);
		            info.contador++;
		            info.jogadas = 0;
		            printf("cu\n");
		            if(info.contador != info.num_partidas){
		                info.jogadas = 0;
		            }else{
                    	break;
                	}
		            strcpy(info.valida_opcao,"g");
		            strcpy(info.jogador_1," ");
		            strcpy(info.jogador_2," ");
		            system("cls");
		            desenhar_tabu(&info);
		            bola(&info);
		            x(&info);
				}
			}
        }
    }

    // finalizando a pontucao da partida mode 3
    if(info.modo == 3){
        system("cls");
        printf("------------------------------------\n");
        printf("     Resultado do torneio\n");
        printf("------------------------------------\n");
        file = fopen("resultado.txt","w");
        if(file == NULL){
            printf("erro ao abrir resultado!");
            exit(1);
        }
        for(i = 0;i < info.num_jogadores;i++){
            fprintf(file,"%s -> %d\n",info.nomes_jogadores[i],info.pontuacao[i]);
            printf("%s -> %d pontos\n",info.nomes_jogadores[i],info.pontuacao[i]);
        }

        fclose(file);



    }

    if(ganhar(info.jogador_1,info.jogador_2)==0){
    	printf("Deu Velha ! \n");
	}
	// fechando arquivo resultado
    fflush(stdin);
    printf("Quer jogar novamente ? [S/N] \n");
    scanf("%c", &denovo);
    if((denovo == 'n') || (denovo == 'N')){
        system("cls");
        printf("jogo terminado ! \n");
    }else{
        system("cls");
        main();
    }


    return 0;
}

