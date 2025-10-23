#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
le inteiro, depois operação + inteiro
le com %s
*/
typedef struct pilha_operando
{
    int n[1000];
    int topo_n;
    
}pilha_n;

typedef struct pilha_operadores
{
    char o[1000];
    int top_op;
    
}pilha_op;

void inicializa_pilha_num (pilha_n *pil_num){
    pil_num->topo_n = -1;
    return;
}

void inicializa_pilha_op (pilha_op *pil_op){
    pil_op->top_op = -1;
    return;
}

void push_valor (pilha_n *pil_num, int valor){
    if(pil_num->topo_n == 999){
        printf("Pilha cheia");
        return;
    }
    ++(pil_num->topo_n);
    pil_num->n[pil_num->topo_n] = valor;
    return;
}

void push_operadores (pilha_op *pil_op, char operando){
    if (pil_op->top_op == 999){
        printf("Pilha cheia");
        return;
    }
    ++(pil_op->top_op);
    pil_op->o[pil_op->top_op] = operando;
    return;
}

int pop_valor(pilha_n *pil_num){
    if (pil_num->topo_n == -1){
        ("Pilha Vazia");
        return -1;
    }
    int topo_lista = pil_num->n[pil_num->topo_n];
    --(pil_num->topo_n);
    return topo_lista;
}

char pop_operadores(pilha_op *pil_op){
    if(pil_op->top_op == -1){
        printf("Pilha vazia");
        return 'F';
    }
    char operador = pil_op->o[pil_op->top_op];
    --(pil_op->top_op);
    return operador;
}

int resolve_calculo (int primeiro_num, int segundo_num, char operacao){
    int res;
    switch (operacao)
    {
    case '+':
        res = (primeiro_num) + (segundo_num);
        break;
    case '-':
        res = (primeiro_num) - (segundo_num);
        break;
    case '*':
        res = (primeiro_num) * (segundo_num);
        break;
    case '/':
        res = (primeiro_num) / (segundo_num);
        break;
    default:
        break;
    }
    return res;
}

void resolve_expressao(pilha_n *pil_num, pilha_op *pil_op){
    inicializa_pilha_num(pil_num);
    inicializa_pilha_op(pil_op);
    scanf("%d", &(*pil_num).n[0]);
    ++(pil_num->topo_n);
    int i=0, n, s1, s2, res;
    char s[100], op;
    while( 2 == scanf("%s %d", s ,&n)){
        if(pil_op->top_op == -1){
            push_operadores(pil_op, s[0]);
            push_valor(pil_num, n);
        }
        else {
            if (s[0] == '*' || s[0] == '/'){
                push_operadores(pil_op, s[0]);
                push_valor(pil_num, n);
            }
            else{
                s2 = pop_valor(pil_num);
                op = pop_operadores(pil_op);
                s1 = pop_valor(pil_num);
                res = resolve_calculo(s1,s2,op);
                push_valor(pil_num, res);
                push_operadores(pil_op, s[0]);
                push_valor(pil_num, n);
            }
        }
    }
    while(pil_op->top_op != -1){
        s2 = pop_valor(pil_num);
        op = pop_operadores(pil_op);
        s1 = pop_valor(pil_num);
        res = resolve_calculo(s1,s2,op);
        push_valor(pil_num, res);
    }
    return;
}

int main (){
    
    pilha_n pil_num;
    pilha_op pil_op;
    resolve_expressao(&pil_num , &pil_op);
    printf("saida:%d", pil_num.n[0]);
    return 0;
}