/* Default linker script, for normal executables */
OUTPUT_FORMAT("elf32-propeller","elf32-propeller","elf32-propeller")
OUTPUT_ARCH(propeller)
MEMORY
{
  hub     : ORIGIN = 0, LENGTH = 128K
  cog	  : ORIGIN = 0, LENGTH = 1984 /* 496*4 */
  /* coguser is just an alias for cog, but for overlays */
  coguser : ORIGIN = 0, LENGTH = 1984 /* 496*4 */
  /* kernel memory is where the .lmm or .xmm kernel goes */
  kermem  : ORIGIN = 0, LENGTH = 0x6C0
  kerextmem : ORIGIN = 0x6C0, LENGTH = 0x100
  /* bootpasm is an alias for kernel */
  bootpasm : ORIGIN = 0, LENGTH = 0x6C0
  ram     : ORIGIN = 0x20000000, LENGTH = 256M
  rom     : ORIGIN = 0x30000000, LENGTH = 256M
  /* some sections (like the .xmm kernel) are handled specially by the loader */
  drivers : ORIGIN = 0xc0000000, LENGTH = 1M
  dummy   : ORIGIN = 0xe0000000, LENGTH = 1M
}
SECTIONS
{
  /* if we are not relocating (-r flag given) then discard the boot and bootpasm sections; otherwise keep them */
  /* the initial spin boot code, if any */
   .boot : { KEEP(*(.boot)) } >hub
   .bootpasm : { KEEP(*(.bootpasm)) } >bootpasm AT>hub
  /* the initial startup code (including constructors) */
  .init   :
  {
    KEEP(*(.init*))
  }  >rom AT>rom
  /* Internal text space or external memory.  */
  .text   :
  {
    *(.text*)
     _etext = . ;
  }  >rom AT>rom
  /* the final cleanup code (including destructors) */
  .fini   :
  {
    *(.fini*)
  }  >rom AT>rom
  .hub   :
  {
    *(.hubstart)
    *(.hubtext*)
    *(.hubdata*)
    *(.hub)
    *(.data)
    *(.data*)
    *(.rodata)  /* We need to include .rodata here if gcc is used */
    *(.rodata*) /* with -fdata-sections.  */
    *(.gnu.linkonce.d*)
     PROVIDE(__C_LOCK = .); LONG(0);
  }  >hub AT>rom
  .ctors   :
  {
    KEEP(*(.ctors*))
  }  >hub AT>rom
  .dtors   :
  {
    KEEP(*(.dtors*))
  }  >hub AT>rom
  .data	  :
  {
    . = ALIGN(4);
  }  >hub AT>rom
  /* the LMM kernel that is loaded into the cog */
  .xmmkernel   :
  {
    *(.xmmkernel)
    *(.kernel)
  } >kermem AT>dummy
  .bss     :
  {
     PROVIDE (__bss_start = .) ;
    *(.bss)
    *(.bss*)
    *(COMMON)
     PROVIDE (__bss_end = .) ;
  }  >hub AT>rom
    .hub_heap : { . += 4; } >hub AT>hub
    ___hub_heap_start = ADDR(.hub_heap) ;
  .drivers   :
  {
    *(.drivers)
    /* the linker will place .ecog sections after this section */
  }  AT>drivers
    __load_start_kernel = LOADADDR (.xmmkernel) ;
   ___CTOR_LIST__ = ADDR(.ctors) ;
   ___DTOR_LIST__ = ADDR(.dtors) ;
  .hash          : { *(.hash)		}
  .dynsym        : { *(.dynsym)		}
  .dynstr        : { *(.dynstr)		}
  .gnu.version   : { *(.gnu.version)	}
  .gnu.version_d   : { *(.gnu.version_d)	}
  .gnu.version_r   : { *(.gnu.version_r)	}
  .rel.init      : { *(.rel.init)		}
  .rela.init     : { *(.rela.init)	}
  .rel.text      :
    {
      *(.rel.text)
      *(.rel.text.*)
      *(.rel.gnu.linkonce.t*)
    }
  .rela.text     :
    {
      *(.rela.text)
      *(.rela.text.*)
      *(.rela.gnu.linkonce.t*)
    }
  .rel.fini      : { *(.rel.fini)		}
  .rela.fini     : { *(.rela.fini)	}
  .rel.rodata    :
    {
      *(.rel.rodata)
      *(.rel.rodata.*)
      *(.rel.gnu.linkonce.r*)
    }
  .rela.rodata   :
    {
      *(.rela.rodata)
      *(.rela.rodata.*)
      *(.rela.gnu.linkonce.r*)
    }
  .rel.data      :
    {
      *(.rel.data)
      *(.rel.data.*)
      *(.rel.gnu.linkonce.d*)
    }
  .rela.data     :
    {
      *(.rela.data)
      *(.rela.data.*)
      *(.rela.gnu.linkonce.d*)
    }
  .rel.ctors     : { *(.rel.ctors)	}
  .rela.ctors    : { *(.rela.ctors)	}
  .rel.dtors     : { *(.rel.dtors)	}
  .rela.dtors    : { *(.rela.dtors)	}
  .rel.got       : { *(.rel.got)		}
  .rela.got      : { *(.rela.got)		}
  .rel.bss       : { *(.rel.bss)		}
  .rela.bss      : { *(.rela.bss)		}
  .rel.plt       : { *(.rel.plt)		}
  .rela.plt      : { *(.rela.plt)		}
  /* Stabs debugging sections.  */
  .stab 0 : { *(.stab) }
  .stabstr 0 : { *(.stabstr) }
  .stab.excl 0 : { *(.stab.excl) }
  .stab.exclstr 0 : { *(.stab.exclstr) }
  .stab.index 0 : { *(.stab.index) }
  .stab.indexstr 0 : { *(.stab.indexstr) }
  .comment 0 : { *(.comment) }
  /* DWARF debug sections.
     Symbols in the DWARF debugging sections are relative to the beginning
     of the section so we begin them at 0.  */
  /* DWARF 1 */
  .debug          0 : { *(.debug) }
  .line           0 : { *(.line) }
  /* GNU DWARF 1 extensions */
  .debug_srcinfo  0 : { *(.debug_srcinfo .zdebug_srcinfo) }
  .debug_sfnames  0 : { *(.debug_sfnames .zdebug_sfnames) }
  /* DWARF 1.1 and DWARF 2 */
  .debug_aranges  0 : { *(.debug_aranges .zdebug_aranges) }
  .debug_pubnames 0 : { *(.debug_pubnames .zdebug_pubnames) }
  /* DWARF 2 */
  .debug_info     0 : { *(.debug_info .gnu.linkonce.wi.* .zdebug_info) }
  .debug_abbrev   0 : { *(.debug_abbrev .zdebug_abbrev) }
  .debug_line     0 : { *(.debug_line .zdebug_line) }
  .debug_frame    0 : { *(.debug_frame .zdebug_frame) }
  .debug_str      0 : { *(.debug_str .zdebug_str) }
  .debug_loc      0 : { *(.debug_loc .zdebug_loc) }
  .debug_macinfo  0 : { *(.debug_macinfo .zdebug_macinfo) }
  /* global variables */
  /* provide some register definitions - propeller 1 */
  /* provide some case-sensitive aliases - propeller 1 */
  /* provide some case-sensitive aliases - propeller 2 */
  PROVIDE(pina = PINA) ;
  PROVIDE(pinb = PINB) ;
  PROVIDE(pinc = PINC) ;
  PROVIDE(pind = PIND) ;
  PROVIDE(dira = DIRA) ;
  PROVIDE(dirb = DIRB) ;
  PROVIDE(dirc = DIRC) ;
  PROVIDE(dird = DIRD) ;
  /* this symbol is used to tell the spin boot code where the spin stack can go */
   PROVIDE(__hub_end = ADDR(.hub_heap) + 16) ;
  /* default initial stack pointer */
  PROVIDE(__stack_end = 0x20000) ;
}
