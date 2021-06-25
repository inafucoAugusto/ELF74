#include <stdint.h>
#include <stdbool.h>

// Biblioteca do driverlib
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

void main(void){
  
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF); // Habilita GPIO F (LED D4 = PF0)
  while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF)); // Aguarda final da habilitação
    
  GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_0); // LEDs D4 como saída
  GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0); // LEDs D4 apagados
  GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_STRENGTH_12MA, GPIO_PIN_TYPE_STD);

  bool change = 0;
  uint32_t count = 0;
  while(1){

    // -> BLINK COM LAÇOS DE ATRASO
    // Executa 2 instruções -> LDR . N + ADDS
    // Como tem que "demorar" um segundo para executar 2 instruções:
    // T = 1/24MHz = 41.67 ns
    // 41.67 * 2 = 83.33 ns
    // delay = 1/83.33 ns = 12M
    while(count != 1200000){
      count++;
    }
    count = 0;

    // -> BLINK COM LAÇOS DE ATRASO
    // f = 24Mhz
    // SysCtlDelay -> executa 3 instruções
    // T = 1/24MHz = 41.67 ns
    // 41.67 * 3 = 125 ns
    // delay = 1/125 ns = 8M -> 1 segundo aceso + 1 segundo apagado
    //SysCtlDelay(8000000);

    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, change);
    change = !change;

  }
}
