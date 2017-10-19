#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

void BuscaDeInstucao(){
    printf(" BUSCA DE INSTRUCAO.\n\n");
    printf(" ler memoria.\n");
    printf(" UALFonteA =0\n");
    printf(" LouD=0\n");
    printf(" IREsc\n");
    printf(" UALFonteB =01\n");
    printf(" UALOp =00\n");
    printf(" PCEsc\n");
    printf(" FontePC=00\n\n");
}

void DecoDaInstBuscaEmRegis(){
     printf(" DECODIFICACAO DA INSTRUCAO/BUSCA EM REGISTRADOR.\n\n");
     printf(" UALFonteA =0\n");
     printf(" UALFonteB =11\n");
     printf(" UALOp =00\n\n");
}

void CalDoEnderDeMem(){
     printf(" CALCULO DO ENDERECO DA MEMORIA.\n\n");
     printf(" UALFonteA =1\n");
     printf(" UALFonteB =10\n");
     printf(" UALOp =00\n\n");
}

void Execucao(){
     printf(" EXECUCAO.\n\n");
     printf(" UALFonteA =1\n");
     printf(" UALFonteB =00\n");
     printf(" UALOp =10\n\n");
}

void TermDoDesvioCondi(){
     printf(" TERMINO DO DESVIO CONDICIONAL.\n\n");
     printf(" UALFonteA =1\n");
     printf(" UALFonteB =00\n");
     printf(" UALOp =01\n");
     printf(" PCEscCond\n");
     printf(" FontePC=01\n\n");
}

void TermDoDesvioIncondi(){
    printf(" TERMINO DO DESVIO INCONDICIONAL.\n\n");
    printf(" PCEsc\n");
    printf(" FontePC=00\n\n");
}

void AcessoAMemoriaLw(){
    printf(" ACESSO A MEMORIA LW.\n\n");
    printf("ler memoria.\n");
    printf(" LouD=1\n\n");
}
void AcessoAMemoriaSW(){
    printf(" ACESSO A MEMORIA SW.\n\n");
    printf("Esc memoria.\n");
    printf(" LouD=1\n\n");
}

void TermDaInstDeTipoR(){
     printf(" TERMINO DA INSTRUCAO DE TIPO R.\n\n");
     printf(" RegDst = 1\n");
     printf(" EscReg\n");
     printf(" MemParaReg = 0\n\n");
}
void PassoDeEscrita(){
    printf(" PASSO DE ESCRITA.\n\n");
    printf(" RegDst = 0\n");
    printf(" EscReg\n");
    printf(" MemParaReg = 1\n\n");
}

/*
* instrucao de tipo R: OPCODE = 0001;
* instrucao de tipo J: OPCODE = 0010;
* instrucao de tipo BEQ: OPCODE = 0011;
* instrucao de tipo LW: OPCODE = 0100;
* instrucao de tipo SW: OPCODE = 0101;
*/

int main(){
    char OPCODE[4];
    int N[4],V=0;
    int i,j ;
        while(1){
            printf("Digite o valor do OPCODE.\n");
            scanf("%s",OPCODE);
                N[0] = OPCODE[0]-'0';
                N[1] = OPCODE[1]-'0';
                N[2] = OPCODE[2]-'0';
                N[3] = OPCODE[3]-'0';
            for(i=0,j=3;i<4;i++,j--){
                V+=(N[i]*pow(2,j));
            }
            switch (V){
                    case 1:
                        BuscaDeInstucao();
                        DecoDaInstBuscaEmRegis();
                        Execucao();
                        TermDaInstDeTipoR();
                        break;
                    case 2:
                        BuscaDeInstucao();
                        DecoDaInstBuscaEmRegis();
                        TermDoDesvioIncondi();
                        break;
                    case 3:
                        BuscaDeInstucao();
                        DecoDaInstBuscaEmRegis();
                        TermDoDesvioCondi();
                        break;
                    case 4:
                        BuscaDeInstucao();
                        DecoDaInstBuscaEmRegis();
                        CalDoEnderDeMem();
                        AcessoAMemoriaLw();
                        PassoDeEscrita();
                        break;
                    case 5:
                        BuscaDeInstucao();
                        DecoDaInstBuscaEmRegis();
                        CalDoEnderDeMem();
                        AcessoAMemoriaSW();
                        break;
                }
        }
   return 0;
}
