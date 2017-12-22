#ifndef KERNEL_DRIVER_PCI
#define KERNEL_DRIVER_PCI

#define CONFIG_ADDRESS 0xCF8
#define CONFIG_DATA 0xCFC

typedef struct pci_device {
    uint8_t bus;
    uint8_t device;
    uint8_t function;

    uint16_t vendor_id;
    uint16_t device_id;

    uint8_t revision_id;
    uint8_t prog_if;
    uint8_t subclass;
    uint8_t class_code;

    uint32_t bar0;
    uint32_t bar1;
    uint32_t bar2;
    uint32_t bar3;
    uint32_t bar4;
    uint32_t bar5;
} pci_device_t;

#endif
