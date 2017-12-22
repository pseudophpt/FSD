#include <stdint.h>
#include <stddef.h>

#include "pci.h"
#include "io.h"

uint32_t pci_read_config (uint8_t bus, uint8_t device, uint8_t function, uint8_t offset) {
    
    /* Encode address */
    
    uint32_t address = (0x1 << 31) | (bus << 16) | (device << 11) | (function << 8) | (offset & 0xFC);
    
    /* Tell PCI what we want to access */

    out_long(CONFIG_ADDRESS, address);
    
    return in_long(CONFIG_DATA);
}
