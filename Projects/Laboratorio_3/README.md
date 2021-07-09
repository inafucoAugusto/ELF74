# ELF74

Repositório destinado a pratica 3 da disciplina de Sistemas Embarcados, turma ELF74, ministrada na Universidade Tecnológica Federal do Paraná (UTFPR). 

## Professor orientador

Hugo Vieira Neto

## Placa de desenvolvimento

[ARM® Cortex®-M4F-Based MCU TM4C1294 Connected LaunchPad™ Evaluation Kit](https://www.ti.com/tool/EK-TM4C1294XL)

## Analise e discussão da atividade
### Exercício prático 1

![PlantUML model ](http://www.plantuml.com/plantuml/png/LO_H2e9G38RlznIx3dm1eP18A2Y9D0YYYqDRUaYdx4oYjqz8fQx-iV_ZOqk2ERM-gQ7onCXDPsya3dVrdVbMuBguOHIjiAYK7S4tS5vW76Dss1tJR9EdnTAqvvcXzYK3c9jxUYbXJ8pKbvKDnTO9rQpuPtYuEZ1CrUGuInWjy_Hx0wulk3z1maB3Any0)

 - Se ocorrer uma interrupção durante o Handler (PEND=1) é gerado/ocasionado um tail-channing.
 - Se ocorrer uma interrupção durante o Unstacking (PEND=1) é gerado um pop preenption , indo para  um tail-channing.

### Exercício prático 2
![PlantUML model ](http://www.plantuml.com/plantuml/png/SoWkIImgAStDuOhMYbNGrRLJyCbCJqp9vmAAbwH2EGfM2ZwkBeOAjWg6N5mG8R1IbzJY79W2rxBKl99yXUZWokAGpEJiU8_4l9ISrA9OY448fGYp3BYuuA8GcmcQnUMGcfS2T2m0)
![](http://www.plantuml.com/plantuml/png/SoWkIImgAStDuKhDAyrLS0LoK_AhkHGKN5ABSpBJWHmWsmV2gELoICrB0Qe50000)

- Sempre que houver uma exceção (evento) do SysTick_Handler o Estado será alterado, isto é, se estiver Ligado deverá ficar desligo e vice versa.

## Referências
- The Definitive Guide to ARM® Cortex®-M3 and Cortex®-M4 Processors, Third Edition by Joseph Yiu
- [PlantUML](https://plantuml.com/)