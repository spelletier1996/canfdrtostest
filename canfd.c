/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Guidebolt

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#include "canfd.h"

uint8_t Mcan1MessageRAM[MCAN1_MESSAGE_RAM_CONFIG_SIZE] __attribute__((aligned (32)))__attribute__((space(data), section (".ram_nocache")));


void canfd(){

//    
    /* Set Message RAM Configuration */
    MCAN1_MessageRAMConfigSet(Mcan1MessageRAM);

    
//    /* Prepare the message to send*/
//    messageID = 0x469;
//    messageLength = 8;
//    for (uint8_t count = 8; count >=1; count--){
//        message[count - 1] = 0;
//    }
//        for (uint8_t count = 8; count >=1; count--){
//        message2[count - 1] = 1;
//    }

    
    buttonFlag = 0;
    
    while(1){
        
        vTaskDelay(200);
        
        USER_LED_Toggle();
        

        
        
    
        /* Prepare the message to send*/
    messageID = 0x469;
    messageLength = 1;
    message = 1;
    message2 = 2;  
         for(int x = 0; x > 1000; x++){};
        
    //if (MCAN1_TxFIFOIsFull() == false)    
        
           if (buttonFlag == 0) {
                if (MCAN1_InterruptGet(MCAN_INTERRUPT_TC_MASK))
                {
                    MCAN1_InterruptClear(MCAN_INTERRUPT_TC_MASK);
                }
                if (MCAN1_TxFIFOIsFull() == false){
                if (MCAN1_MessageTransmit(messageID,messageLength,&message,MCAN_MODE_NORMAL,MCAN_MSG_ATTR_TX_FIFO_DATA_FRAME) == true)
                {    
                    printf("Success%d \r\n", message);
                }
                else
                {
                    printf("Failed \r\n");
                }   
                }
      
       buttonFlag = 1; }
   else {
                if (MCAN1_InterruptGet(MCAN_INTERRUPT_TC_MASK))
                {
                    MCAN1_InterruptClear(MCAN_INTERRUPT_TC_MASK);
                }
                if (MCAN1_TxFIFOIsFull() == false){
                if (MCAN1_MessageTransmit(messageID,messageLength,&message2,MCAN_MODE_NORMAL,MCAN_MSG_ATTR_TX_FIFO_DATA_FRAME) == true)
                {    
                    printf("Success2%d \r\n", message2);
                }
                else
                {
                    printf("Failed2 \r\n");
                }   
                }

   buttonFlag = 0;}  
        
  
    
         
        
    }
  

    }

    


void canfd_init(){
    
    xTaskCreate(canfd, "CANFD", 2024, NULL, 2, &canfdHandle);
    
    
}

