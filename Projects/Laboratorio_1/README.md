# ELF74

Repositório destinado a pratica 1 da disciplina de Sistemas Embarcados, turma ELF74, ministrada na Universidade Tecnológica Federal do Paraná (UTFPR). 

## Professor orientador

Hugo Vieira Neto

## Placa de desenvolvimento

[ARM® Cortex®-M4F-Based MCU TM4C1294 Connected LaunchPad™ Evaluation Kit](https://www.ti.com/tool/EK-TM4C1294XL)

## Analise e discussão da atividade
Ao se alterar a otimização do compilador C foi notada a alteração no tempo de piscada do LED. Isso se deve a alteração que o compilação destina a instrução em questão. No caso do projeto atual o modo de "delay" utilizado foi:

    while(count != 1200000){
          count++;
    }

Para esse trecho de código, e otimização em LOW, foram destinados dois comandos em assembly (possível de ver na janela de Disassembly ao debugar o programa):
- ADDS
- LDR. N
 
Alterando a otimização para HIGH e recompilando o projeto teve-se o seguinte assembly resultante:
- ADDS
- CMP

Importante notar que o comando LDR. N consome dois ciclos de clock enquanto CMP utiliza apenas um ciclo de clock, o que gera uma otimização de 33%. Essa alteração consequentemente faz com que o led pisque mais rápido e se desejado manter o período de cada ciclo, ligado/desligado, é necessário mudar o valor contido dentro do while.
Além do laço de repetição foi utilizada a função SysCtlDelay.

    __asm("    subs    r0, #1\n"
          "    bne.n   SysCtlDelay\n"
          "    bx      lr");

  O comando utiliza 3 ciclos de clock e não sefre interferência sobre a otimização do compilador.
## Referências
- https://developer.arm.com/documentation/ddi0432/c/CHDCICDF
- The Definitive Guide to ARM® Cortex®-M3 and Cortex®-M4 Processors, Third Edition by Joseph Yiu