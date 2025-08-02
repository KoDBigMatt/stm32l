/* Memory layout */
MEMORY
{
  FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 1024K
  RAM   (rwx) : ORIGIN = 0x20000000, LENGTH = 96K
}

/* Sections */
SECTIONS
{
  .isr_vector :
  {
    KEEP(*(.isr_vector))
  } > FLASH

  .text :
  {
    *(.isr_vector)
    *(.text*)
    *(.rodata*)
    *(.init) /* add this if needed */
  } > FLASH

  .ARM.exidx :
  {
    __exidx_start = .;
    *(.ARM.exidx* .gnu.linkonce.armexidx.*)
    __exidx_end = .;
  } >FLASH

  .data : AT(ADDR(.ARM.exidx) + SIZEOF(.ARM.exidx))
  {
    _sdata = .;
    *(.data*)
    _edata = .;
  } > RAM

  .bss :
  {
    _sbss = .;
    *(.bss*)
    *(COMMON)
    _ebss = .;
  } > RAM

  PROVIDE(end = .);

  /* These are used by startup.s */
  _sidata = LOADADDR(.data);
  _estack = ORIGIN(RAM) + LENGTH(RAM);
}
