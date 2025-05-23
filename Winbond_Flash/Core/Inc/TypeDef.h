/*
 * TypeDef.h
 *
 *  Created on: Apr 15, 2025
 *      Author: Thomas
 */

#ifndef INC_TYPEDEF_H_
#define INC_TYPEDEF_H_

//Init TypeDef struct
typedef struct{
	uint8_t SR_1;
	uint8_t SR_2;
	uint8_t SR_3;
	uint8_t SR_1_Addr;
	uint8_t SR_2_Addr;
	uint8_t SR_3_Addr;
}SR_Data;

typedef struct{
	uint8_t Tx_Buffer[5];
	uint8_t Rx_Buffer[5];
}SPI_Data;

typedef struct{
	uint8_t Tx_Buffer[8];
	uint8_t Rx_Buffer[8];
}CAN_Data;

typedef struct{
	uint8_t Buffer_0[2048];
	uint8_t Buffer_1[2048];
	uint16_t Buffer_Index;
	uint8_t Buffer_flip;
	uint8_t* Buffer_p;

	uint16_t Block_Mem;
	uint16_t Page_Index;
	uint32_t ID;
}Flash_Data;

typedef struct{
	uint8_t Tx_Buffer[2];
	uint8_t Rx_Buffer[2];
}CAM_Data;
#endif /* INC_TYPEDEF_H_ */
