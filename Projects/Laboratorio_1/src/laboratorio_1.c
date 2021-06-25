#include <stdint.h>
#include <stdbool.h>

// Biblioteca do driverlib
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

void main(void){
  
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF); // Habilita GPIO F (LED D4 = PF0)
  while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF)); // Aguarda final da habilita��o
    
  GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_0); // LEDs D4 como sa�da
  GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0); // LEDs D4 apagados
  GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_STRENGTH_12MA, GPIO_PIN_TYPE_STD);

  bool change = 0;
  uint32_t count = 0;
  while(1){

    // -> BLINK COM LA�OS DE ATRASO
    // Executa 2 instru��es -> LDR . N + ADDS
    // Como tem que "demorar" um segundo para executar 2 instru��es:
    // T = 1/24MHz = 41.67 ns
    // 41.67 * 2 = 83.33 ns
    // delay = 1/83.33 ns = 12M
    while(count != 1200000){
      count++;
    }
    count = 0;

    // -> BLINK COM LA�OS DE ATRASO
    // f = 24Mhz
    // SysCtlDelay -> executa 3 instru��es
    // T = 1/24MHz = 41.67 ns
    // 41.67 * 3 = 125 ns
    // delay = 1/125 ns = 8M -> 1 segundo aceso + 1 segundo apagado
    //SysCtlDelay(8000000);

    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, change);
    change = !change;

  }
}
