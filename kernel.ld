OUTPUT_ARCH( "riscv" )
ENTRY( boot )

SECTIONS {
  . = 0x80200000; /* '.' means 'current address' -> set current address to ... */
  
  .text :{
    KEEP(*(.text.boot));
    *(.text .text.*); /* place all [*(...)] segments of type [.text .text.*] here */ 
  }

  .rodata : ALIGN(4) {
    *(.rodata .rodata.*);
  }

  .data : ALIGN(4) {
    *(.data .data.*);
  }

  .bss : ALIGN(4) {
    __bss = .;  /* '__*' -> for use with 'extern char symbol_name' */
    *(.bss .bss.* .sbss .sbss.*);
    __bss_end = .;
  }

  . = ALIGN(4);
  . += 128 * 1024; /* 128KB */
  __stack_top = .;
}
