#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<windows.h>
#define altura 8
#define largura 40
#define larguraletra 6
#define tamtimes 16

char caracteres[11][altura][larguraletra];
char placar[altura][largura];
char times[2][tamtimes];

//Trecho importado da biblioteca conio.h usado para deslocar o cursor na tela.
void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}
void inserirDigito(int digito, int numero )
{
    digito--;
    int i,j,largura1=larguraletra + 2;
    //Pular o espaço do caractere "X" no placar
    if (digito >= 2)
        digito++;
    //Fixar o número no placar na respectiva posição do dígito
    for(i=0; i<altura; i++)
        for(j=0; j<larguraletra; j++)
        {
            placar[i][digito*largura1+j+1] = caracteres[numero][i][j]; //Fixa o número no placar
            placar[i+1][2*largura1+j+1] = caracteres[10][i][j]; //Fixa o "X" no placar
        }
}

void imprimirPlacar(char placar[altura][largura])
{
   //Imprimir os times
    int i,j;
    system("CLS");
    gotoxy(40-strlen(times[0])-8,1);
    printf("%s",times[0]);
    gotoxy(40,1);
    printf("X");
    gotoxy(49,1);
    printf("%s\n",times[1]);

//Imprimir o placar
    for(i=0;i<altura;i++)
    {
        //Quebra de linha e centralização do placar
        printf("\n\t\t   ");
        //Impressão do placar
        for(j=0;j<largura;j++)
            printf("%c",placar[i][j]);
    }
    printf("\n");
}
//Le os times
void lerTimes()
{
    fflush(stdin);
    printf("Digite o nome do time 1: ");
    //Verifica se o tamanho do time 1 nao eh muito grande.
    do
    {
        gets(times[0]);
        if (strlen(times[0]) > tamtimes)
        {
            printf("\nNome muito grande, favor inserir nome menor: \n");
        }
    }while(strlen(times[0]) > tamtimes);
    system("cls");
    printf("Digite o nome do time 2: ");
    //Verifica se o tamanho do time 2 nao eh muito grande.
    do
    {
        gets(times[1]);
        if (strlen(times[1]) > tamtimes)
        {
            printf("\nNome muito grande, favor inserir nome menor:\n");
        }
    }while(strlen(times[1]) > tamtimes);
}

//Função abençoada
//"Transforma" o código ascii em números na matriz de caracteres.
void adaptarCaractere(char ascii[48],int numcaractere)
{
int i,linha,coluna;
linha = coluna = 0;
    for(i=0; i<strlen(ascii);i++)
    {
        if (ascii[i]=='\n')
        {
            linha++;
            coluna = 0;
            caracteres[numcaractere][linha][coluna] = ' ';
        }
        else
        {
            caracteres[numcaractere][linha][coluna] = ascii[i];
            coluna ++;
        }
    }
}
void mudarFonte(int fonte)
{
    switch(fonte)
    {
    //Modelo de fonte 1
    case 1:
        adaptarCaractere(" ###\n## ##\n## ##\n## ##\n## ##\n## ##\n ###",0);
        adaptarCaractere("  ##\n####\n  ##\n  ##\n  ##\n  ##\n######",1);
        adaptarCaractere(" ###\n## ##\n   ##\n  ##\n ##\n## ##\n#####",2);
        adaptarCaractere(" ###\n## ##\n   ##\n ###\n   ##\n## ##\n ###",3);
        adaptarCaractere("   ##\n  ###\n # ##\n## ##\n######\n   ##\n   ##",4);
        adaptarCaractere("#####\n##\n####\n## ##\n   ##\n#  ##\n####",5);
        adaptarCaractere(" ###\n## ##\n##\n####\n## ##\n## ##\n ###",6);
        adaptarCaractere("#####\n## ##\n   ##\n  ##\n  ##\n ##\n ##",7);
        adaptarCaractere(" ###\n## ##\n## ##\n ###\n## ##\n## ##\n ###",8);
        adaptarCaractere(" ###\n## ##\n## ##\n ####\n   ##\n## ##\n ###",9);
        adaptarCaractere("##  ##\n ####\n  ##\n  ##\n ####\n##  ##",10); //Símbulo do X
        break;
    //Modelo de fonte 2
        case 2:
    	adaptarCaractere(" #### \n#    #\n#    #\n#    #\n#    #\n#    #\n#    #\n #### ",0);
    	adaptarCaractere(" #\n##\n #\n #\n #\n #\n #\n###",1);
    	adaptarCaractere(" #### \n#   #\n    #\n    #\n   #\n  #\n #\n######",2);
    	adaptarCaractere(" #### \n#    #\n    #\n   ### \n     #\n#    #\n#    #\n #### ",3);
    	adaptarCaractere("     #\n    ##\n   # #\n  #  # \n #####\n     #\n     #\n     #",4);
    	adaptarCaractere("######\n#\n#\n#####\n     #\n     #\n     #\n#####",5);
    	adaptarCaractere("  ###\n #\n#\n#####\n#    #\n#    #\n#    #\n ####",6);
    	adaptarCaractere("######\n     #\n    #\n    #\n   #\n   #\n  #\n  #",7);
    	adaptarCaractere(" #### \n#    #\n#    #\n ####\n#    #\n#    #\n#    #\n ####",8);
    	adaptarCaractere(" ####\n#    #\n#    #\n #####\n     #\n    #\n    #\n ###\n",9);
    	adaptarCaractere(" #   #\n  # #\n   #\n   #\n  # #\n #   #",10);
    	break;
    //modelo de fonte 3
    case 3:
        adaptarCaractere(" //\\\\\n||  ||\n||  ||\n||  ||\n||  ||\n||  ||\n||  ||\n \\\\//",0);
    	adaptarCaractere(" //|\n//||\n  ||\n  ||\n  ||\n  ||\n  ||\n/----\\",1);
    	adaptarCaractere(" //\\\n (  )\n   ||\n   ||\n   //\n  //\n /(\n{____",2);
    	adaptarCaractere("____\n` // \n //\n \\\\\n  \\\\\n   ))\n  //\n //",3);
    	adaptarCaractere("    '\n  //|\n // |\n//__|_\n----|\n    |\n    |\n   '-'",4);
    	adaptarCaractere("_____\n||   \n||_\n|__\\\n   ))\n  //\n //\n//",5);
    	adaptarCaractere("  ,/\n //\n((__\n||  \\\\\n\||  //\n|| //\n||//\n \\/",6);
    	adaptarCaractere("_____\n`    ||\n    //,\n   //\n  ((\n  ||\n  ||\n  |'",7);
    	adaptarCaractere(" //\\\\\n||  ||\n \\\\//\n //\\\\\n// \\\\\n||  ||\n||  ||\n \\\\//",8);
    	adaptarCaractere(" //\\\\\n|| ||\n|| ||\n \\/||\n   ||\n   ||\n   ||\n\\_//",9);
    	adaptarCaractere("\\\\  //\n \\\\//\n  ||\n  ||\n //\\\\\n//  \\\\",10);
        break;
    //modelo de fonte 4
    case 4:
    	adaptarCaractere(" 0000 \n0    0\n0    0\n0    0\n0    0\n0    0\n0    0\n 0000 ",0);
    	adaptarCaractere("  1\n 11\n1 1\n  1\n  1\n  1\n  1\n11111",1);
    	adaptarCaractere(" 2222 \n2   2\n    2\n    2\n   2\n  2\n 2\n222222",2);
    	adaptarCaractere(" 3333 \n3    3\n    3\n   333 \n     3\n3    3\n3    3\n 3333 ",3);
    	adaptarCaractere("     4\n    44\n   4 4 \n  4  4 \n 444444\n     4\n     4\n     4",4);
    	adaptarCaractere("555555\n5\n5\n55555\n     5\n     5\n     5\n55555",5);
    	adaptarCaractere("  666\n 6\n6\n66666\n6    6\n6    6\n6    6\n 6666",6);
    	adaptarCaractere("777777\n     7\n    7\n  7777\n   7\n   7\n  7\n  7",7);
    	adaptarCaractere(" 8888 \n8    8\n8    8\n 8888\n8    8\n8    8\n8    8\n 8888",8);
    	adaptarCaractere(" 9999\n9    9\n9    9\n 99999\n     9\n    9\n    9\n 999\n",9);
    	adaptarCaractere("XX  XX\n XXXX\n  XX\n  XX\n XXXX\nXX  XX",10);
    	break;
    }
}
main()
{
    int i,j,digito,numero,tecla,digito1,digito2,digito3,digito4,fonte,modo,pontost1,pontost2;
    //Criar placar vazio
    digito1=digito2=digito3=digito4=modo=pontost1=pontost2=0;
    for(i=0;i<altura;i++)
        for(j=0;j<largura;j++)
        {
            placar[i][j] = ' ';
            times[i][j]= NULL;
        }
    //Função para alternar entre as fontes (1..4)
    printf("Escolha a fonte desejada.\n1 - Padrao\n2 - Padrao Light\n3 - Anorexia\n4 - Numeros de Numeros\nFonte: ");
    do
    {
        scanf("%d",&fonte);
        if (fonte < 1 || fonte > 4)
            printf("Fonte invalida. Por favor, escolha uma fonte valida.\nFonte: ");
    } while(fonte < 1 || fonte > 4);
    system("cls");
    mudarFonte(fonte);
    //Atribuir dígitos
    inserirDigito(1,0);
    inserirDigito(2,0);
    inserirDigito(3,0);
    inserirDigito(4,0);
    //Imprimir placar zerado
    lerTimes();
    imprimirPlacar(placar);
      do{
        if (modo == 0)
        {
            printf("\n\n\t\t\t\t\t\tMODO DECREMENTO: OFF");
            printf("\nAperte para a esquerda para adicionar pontos para o time 1 (%s).\nAperte para a direita para adicionar pontos para o time 2 (%s).\nAperte seta para cima para entrar no modo DECREMENTO\nAperta ESC para sair.",times[0],times[1]);
        }
        else
        {
            printf("\n\n\t\t\t\t\t\tMODO DECREMENTO: ON");
            printf("\nAperte para a esquerda para retirar pontos para o time 1 (%s).\nAperte para a direita para retirar pontos para o time 2 (%s).\nAperte seta para cima para entrar no modo INCREMENTO\nAperta ESC para sair.",times[0],times[1]);
        }
        tecla=getch();
           switch(tecla)
           {
           case 72:
                if (modo == 0)
                    modo=1;
                else
                    modo = 0;
            break;
           case 75:
                system("CLS");
                //Identificar modo de pontuação
                (modo == 0)?pontost1++:pontost1--;
                //Filtrar pontos1
                if (pontost1 < 0)
                    pontost1 = 0;
                if (pontost1 >=100)
                {
                    //Filtrar dígitos
                    digito1=(pontost1-((pontost1/100)*100))/10;
                    digito2=(pontost1-((pontost1/100)*100))%10;
                }
                else
                {
                    digito1=pontost1/10;
                    digito2=pontost1%10;
                }
                //Inserir digitos no placar
                inserirDigito(1,digito1);
                inserirDigito(2,digito2);
                break;
           case 77:
                system("CLS");
                //Identificar modo de pontuação
                (modo == 0)?pontost2++:pontost2--;
                //Filtrar pontos2
                if (pontost2 < 0)
                    pontost2 = 0;
                if (pontost2 >=100)
                {
                    //Filtrar dígitos
                    digito3=(pontost2-((pontost2/100)*100))/10;
                    digito4=(pontost2-((pontost2/100)*100))%10;
                }
                else
                {
                    digito3=pontost2/10;
                    digito4=pontost2%10;
                }
                //Inserir digitos no placar
                inserirDigito(3,digito3);
                inserirDigito(4,digito4);
                break;
            case 27: break;
           }
           imprimirPlacar(placar);
       }while(tecla!=27);
       printf("\n\n\nObrigado por usar o nosso sistema.\n\n\n");
       system("pause");
}
