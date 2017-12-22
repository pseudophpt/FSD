#ifndef KERNEL_DRIVER_IO
#define KERNEL_DRIVER_IO

extern uint8_t in_byte (uint16_t port);
extern uint16_t in_word (uint16_t port);
extern uint32_t in_long (uint16_t port);

extern void out_byte (uint16_t port, uint8_t out);
extern void out_word (uint16_t port, uint16_t out);
extern void out_long (uint16_t port, uint32_t out);

#endif
