/*
 * CAN.c
 *
 *  Created on: Apr 1, 2025
 *      Author: Thomas
 */
#include "main.h"
#include "CAN.h"
#include "EX_Global_Var.h"

extern FDCAN_HandleTypeDef hfdcan1;

void CAN_ReceiveMessage(void) {
    if (HAL_FDCAN_GetRxMessage(&hfdcan1, FDCAN_RX_FIFO0, &RxHeader, CAN.Rx_Buffer) == HAL_OK) {
    	USART3_Printf("Received CAN Message: ");
        for (int i = 0; i < 8; i++) {
        	USART3_Printf("%02X ", CAN.Rx_Buffer[i]);
        }
        USART3_Printf("\r\n");
    }
}

void CAN_SendMessage(uint16_t ID) {
    // Configure TX Header
    TxHeader.Identifier = ID;
    TxHeader.IdType = FDCAN_STANDARD_ID;
    TxHeader.TxFrameType = FDCAN_DATA_FRAME;
    TxHeader.DataLength = FDCAN_DLC_BYTES_8;
    TxHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    TxHeader.BitRateSwitch = FDCAN_BRS_OFF;
    TxHeader.FDFormat = FDCAN_CLASSIC_CAN;
    TxHeader.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
    TxHeader.MessageMarker = 0;

    // Send Message
    if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, CAN.Tx_Buffer) != HAL_OK) {
        Error_Handler();
    }
}
