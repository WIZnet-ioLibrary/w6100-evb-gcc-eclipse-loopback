//#include <CoOS.h>

#include <stdio.h>
#include "W6100RelFunctions.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_spi.h"
#include "stm32f10x_dma.h"
#include "stm32f10x_board.h"


#define W6100_SPI	SPI2

#define W6100_DMA_CHANNEL_RX	DMA1_Channel4
#define W6100_DMA_CHANNEL_TX	DMA1_Channel5

#define DMA_TX_FLAG				DMA1_FLAG_TC5
#define DMA_RX_FLAG				DMA1_FLAG_TC4

DMA_InitTypeDef		DMA_RX_InitStructure, DMA_TX_InitStructure;


void W6100Initialze(void)
{
    intr_kind temp;
    uint8_t phylink;
    unsigned char W6100_AdrSet[2][8] = {{2,2,2,2,2,2,2,2},{2,2,2,2,2,2,2,2}};
    //unsigned char W6100_AdrSet[2][8] = {{8,0,0,0,0,0,0,0},{8,0,0,0,0,0,0,0}};
    /*
     */
    do{
        ctlwizchip(CW_GET_PHYLINK,(void*)&phylink);
        if(phylink == -1){
            printf("Unknown PHY link status.\r\n");
        }
    }while(phylink == PHY_LINK_OFF);

    printf("PHY OK.\r\n");

    temp = IK_DEST_UNREACH;

    if(ctlwizchip(CW_INIT_WIZCHIP,(void*)W6100_AdrSet) == -1)
    {
        printf("W6100 initialized fail.\r\n");
    }

    if(ctlwizchip(CW_SET_INTRMASK,&temp) == -1)
    {
        printf("W6100 interrupt\r\n");
    }
}


uint8_t spiReadByte(void)
{
    while (SPI_I2S_GetFlagStatus(W6100_SPI, SPI_I2S_FLAG_TXE) == RESET);
    SPI_I2S_SendData(W6100_SPI, 0xff);
    while (SPI_I2S_GetFlagStatus(W6100_SPI, SPI_I2S_FLAG_RXNE) == RESET);
    return SPI_I2S_ReceiveData(W6100_SPI);
}

void spiWriteByte(uint8_t byte)
{
    while (SPI_I2S_GetFlagStatus(W6100_SPI, SPI_I2S_FLAG_TXE) == RESET);
    SPI_I2S_SendData(W6100_SPI, byte);
    while (SPI_I2S_GetFlagStatus(W6100_SPI, SPI_I2S_FLAG_RXNE) == RESET);
    SPI_I2S_ReceiveData(W6100_SPI);
}


uint8_t spiReadBurst(uint8_t* pBuf, uint16_t len)
{
    unsigned char tempbuf = 0xff;
    DMA_TX_InitStructure.DMA_BufferSize = len;
    DMA_TX_InitStructure.DMA_MemoryBaseAddr = (uint32_t)&tempbuf;
    //DMA_TX_InitStructure.DMA_Mode = DMA_Mode_Circular;
    DMA_Init(W6100_DMA_CHANNEL_TX, &DMA_TX_InitStructure);

    DMA_RX_InitStructure.DMA_BufferSize = len;
    DMA_RX_InitStructure.DMA_MemoryBaseAddr = (uint32_t)pBuf;
    DMA_Init(W6100_DMA_CHANNEL_RX, &DMA_RX_InitStructure);
    /* Enable SPI Rx/Tx DMA Request*/
    DMA_Cmd(W6100_DMA_CHANNEL_RX, ENABLE);
    DMA_Cmd(W6100_DMA_CHANNEL_TX, ENABLE);
    /* Waiting for the end of Data Transfer */
    while(DMA_GetFlagStatus(DMA_TX_FLAG) == RESET);
    while(DMA_GetFlagStatus(DMA_RX_FLAG) == RESET);


    DMA_ClearFlag(DMA_TX_FLAG | DMA_RX_FLAG);

    DMA_Cmd(W6100_DMA_CHANNEL_TX, DISABLE);
    DMA_Cmd(W6100_DMA_CHANNEL_RX, DISABLE);

    return len;
}

void spiWriteBurst(uint8_t* pBuf, uint16_t len)
{
    unsigned char tempbuf;
    DMA_TX_InitStructure.DMA_BufferSize = len;
    DMA_TX_InitStructure.DMA_MemoryBaseAddr = (uint32_t)pBuf;
    DMA_Init(W6100_DMA_CHANNEL_TX, &DMA_TX_InitStructure);

    DMA_RX_InitStructure.DMA_BufferSize = 1;
    DMA_RX_InitStructure.DMA_MemoryBaseAddr = (uint32_t)&tempbuf;
    DMA_RX_InitStructure.DMA_Mode = DMA_Mode_Circular;
    DMA_Init(W6100_DMA_CHANNEL_RX, &DMA_RX_InitStructure);

    DMA_Cmd(W6100_DMA_CHANNEL_RX, ENABLE);
    DMA_Cmd(W6100_DMA_CHANNEL_TX, ENABLE);

    /* Enable SPI Rx/Tx DMA Request*/


    /* Waiting for the end of Data Transfer */
    while(DMA_GetFlagStatus(DMA_TX_FLAG) == RESET);
    while(DMA_GetFlagStatus(DMA_RX_FLAG) == RESET);

    DMA_ClearFlag(DMA_TX_FLAG | DMA_RX_FLAG);

    DMA_Cmd(W6100_DMA_CHANNEL_TX, DISABLE);
    DMA_Cmd(W6100_DMA_CHANNEL_RX, DISABLE);
}

void busWriteByte(uint32_t addr, iodata_t data)
{
    (*(volatile uint8_t*)(addr)) = data;
}

iodata_t busReadByte(uint32_t addr)
{
    return (*((volatile uint8_t*)(addr)));
}

void busWriteBurst(uint32_t addr, uint8_t* pBuf ,uint32_t len,uint8_t addr_inc)
{
    if(addr_inc){
        DMA_TX_InitStructure.DMA_MemoryInc  = DMA_MemoryInc_Enable;

    }
    else 	DMA_TX_InitStructure.DMA_MemoryInc  = DMA_MemoryInc_Disable;


    DMA_TX_InitStructure.DMA_BufferSize = len;
    DMA_TX_InitStructure.DMA_MemoryBaseAddr = addr;
    DMA_TX_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)pBuf;

    DMA_Init(W6100_DMA_CHANNEL_TX, &DMA_TX_InitStructure);

    DMA_Cmd(W6100_DMA_CHANNEL_TX, ENABLE);

    /* Enable SPI Rx/Tx DMA Request*/


    /* Waiting for the end of Data Transfer */
    while(DMA_GetFlagStatus(DMA_TX_FLAG) == RESET);


    DMA_ClearFlag(DMA_TX_FLAG);

    DMA_Cmd(W6100_DMA_CHANNEL_TX, DISABLE);
}


void busReadBurst(uint32_t addr,uint8_t* pBuf, uint32_t len, uint8_t addr_inc)
{
    DMA_RX_InitStructure.DMA_BufferSize = len;
    DMA_RX_InitStructure.DMA_MemoryBaseAddr = (uint32_t)pBuf;
    DMA_RX_InitStructure.DMA_PeripheralBaseAddr =addr;

    DMA_Init(W6100_DMA_CHANNEL_RX, &DMA_RX_InitStructure);

    DMA_Cmd(W6100_DMA_CHANNEL_RX, ENABLE);
    /* Waiting for the end of Data Transfer */
    while(DMA_GetFlagStatus(DMA_RX_FLAG) == RESET);


    DMA_ClearFlag(DMA_RX_FLAG);


    DMA_Cmd(W6100_DMA_CHANNEL_RX, DISABLE);
}


inline void csEnable(void)
{
    GPIO_ResetBits(SPI2_NSS_PORT, SPI2_NSS_PIN);
}

inline void csDisable(void)
{
    GPIO_SetBits(SPI2_NSS_PORT, SPI2_NSS_PIN);
}

inline void resetAssert(void)
{
    GPIO_ResetBits(RSTn_PORT, RSTn_PIN);
}

inline void resetDeassert(void)
{
    GPIO_SetBits(RSTn_PORT, RSTn_PIN);
}

void W6100Reset(void)
{
//	int i,j,k;
//	k=0;
//	GPIO_ResetBits(RSTn_PORT, RSTn_PIN);
//	CoTickDelay(10);
//	GPIO_SetBits(RSTn_PORT, RSTn_PIN);
}
