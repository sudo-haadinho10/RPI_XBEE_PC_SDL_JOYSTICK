#define MMIO_BASE 0x3F000000
#define GPFSEL0   ((volatile unsigned int*)(MMIO_BASE+0x00200000))
#define GPFSEL2   ((volatile unsigned int*)(MMIO_BASE+0x00200004))
#define GPFSEL3   ((volatile unsigned int*)(MMIO_BASE+0x00200008))
#define GPFSEL4   ((volatile unsigned int*)(MMIO_BASE+0x0020000C))
#define GPFSEL5   ((volatile unsigned int*)(MMIO_BASE+0x00200010))
#define GPFSEL5   ((volatile unsigned int*)(MMIO_BASE+0x00200014))

#define GPSET0    ((volatile unsigned int*)(MMIO_BASE+0x0020001C))
#define GPSET1    ((volatile unsigned int*)(MMIO_BASE+0x00200020))

#define GPCLR0    ((volatile unsigned int*)(MMIO_BASE+0x00200028))
#define GPCLR1    ((volatile unsigned int*)(MMIO_BASE+0x0020002C))

#define GPLEV0    ((volatile unsigned int*)(MMIO_BASE+0x00200034))
#define GPLEV1    ((volatile unsigned int*)(MMIO_BASE+0x00200038))

#define GPEDS0    ((volatile unsigned int*)(MMIO_BASE+0x00200040))
#define GPEDS1    ((volatile unsigned int*)(MMIO_BASE+0x00200044))

#define GPREN0    ((volatile unsigned int*)(MMIO_BASE+0x0020004C))
#define GPREN1    ((volatile unsigned int*)(MMIO_BASE+0x00200050))

#define GPFEN0    ((volatile unsigned int*)(MMIO_BASE+0x00200058))
#define GPFEN1    ((volatile unsigned int*)(MMIO_BASE+0x0020005C))
//Page 90

