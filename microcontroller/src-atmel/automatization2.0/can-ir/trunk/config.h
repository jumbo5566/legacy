#pragma once

// SPI
#define MCP_CS_BIT          PB2
#define MCP_CS_PORT         PORTB

#define SPI_REG_PIN_MCP_INT PIND
#define SPI_PIN_MCP_INT     PD2

//#define CAN_INTERRUPT
//#define CAN_INT_NOBLOCK

#define ENABLE_CAN_INT()    GIMSK |= _BV(INT0)
#define DISABLE_CAN_INT()   GIMSK &= ~_BV(INT0)
#define SETUP_CAN_INT()     MCUCR |= _BV(ISC01)
#define MCP_INT_VEC         INT0_vect

#define CAN_TX_BUFFER_SIZE 4
#define CAN_RX_BUFFER_SIZE 4

#define F_MCP F_CPU

#define UART_BAUD_RATE 9600

#define TEA6420_ADDR 0x00
#define PCA9555_ADDR 0x00
