### Answers ###
1. L'output di `$ objdump -f` sui due file (`test` e `divide.a`) differisce nei flag del header.
2. L'output di `$ objdump -t` invece visualizza la tabella dei simboli presenti nel programma che si riferiscono anche a chiamate al sistema opertivo.3. L'output di `$ objdump -T` invece ci mostra la tabella dei simboli dinamici. Nella tabella di `test` appare anche la funzione `printf`. Quella di `divide.a` invece e' vuota.

--------------------------------------------------------------------------------

### Info Objdump ###

Da `man objdump`:

    -f
    --file-headers
        Display summary information from the overall header of each of the objfile files.

    -t
    --syms
        Print the symbol table entries of the file.

    -T
    --dynamic-syms
        Print the dynamic symbol table entries of the file.

--------------------------------------------------------------------------------

### Output objdump ###

`$ objdump -f test`

Output:

    test:     file format elf64-x86-64
    architecture: i386:x86-64, flags 0x00000150:
    HAS_SYMS, DYNAMIC, D_PAGED
    start address 0x0000000000000540

`$ objdump -f divide.a`

Output:

    divide.a:     file format elf64-x86-64
    architecture: i386:x86-64, flags 0x00000011:
    HAS_RELOC, HAS_SYMS
    start address 0x0000000000000000


--------------------------------------------------------------------------------

`$ objdump -t test`

Output:

    test:     file format elf64-x86-64

    SYMBOL TABLE:
    0000000000000238 l    d  .interp	0000000000000000              .interp
    0000000000000254 l    d  .note.ABI-tag	0000000000000000              .note.ABI-tag
    0000000000000274 l    d  .note.gnu.build-id	0000000000000000              .note.gnu.build-id
    0000000000000298 l    d  .gnu.hash	0000000000000000              .gnu.hash
    00000000000002b8 l    d  .dynsym	0000000000000000              .dynsym
    0000000000000360 l    d  .dynstr	0000000000000000              .dynstr
    00000000000003e4 l    d  .gnu.version	0000000000000000              .gnu.version
    00000000000003f8 l    d  .gnu.version_r	0000000000000000              .gnu.version_r
    0000000000000418 l    d  .rela.dyn	0000000000000000              .rela.dyn
    00000000000004f0 l    d  .rela.plt	0000000000000000              .rela.plt
    0000000000000508 l    d  .init	0000000000000000              .init
    0000000000000520 l    d  .plt	0000000000000000              .plt
    0000000000000540 l    d  .text	0000000000000000              .text
    00000000000006f4 l    d  .fini	0000000000000000              .fini
    0000000000000700 l    d  .rodata	0000000000000000              .rodata
    0000000000000708 l    d  .eh_frame_hdr	0000000000000000              .eh_frame_hdr
    0000000000000748 l    d  .eh_frame	0000000000000000              .eh_frame
    0000000000200de0 l    d  .init_array	0000000000000000              .init_array
    0000000000200de8 l    d  .fini_array	0000000000000000              .fini_array
    0000000000200df0 l    d  .dynamic	0000000000000000              .dynamic
    0000000000200fd0 l    d  .got	0000000000000000              .got
    0000000000201000 l    d  .got.plt	0000000000000000              .got.plt
    0000000000201020 l    d  .data	0000000000000000              .data
    0000000000201030 l    d  .bss	0000000000000000              .bss
    0000000000000000 l    d  .comment	0000000000000000              .comment
    0000000000000000 l    d  .GCC.command.line	0000000000000000              .GCC.command.line
    0000000000000000 l    df *ABS*	0000000000000000              init.c
    0000000000000000 l    df *ABS*	0000000000000000              crtstuff.c
    0000000000000570 l     F .text	0000000000000000              deregister_tm_clones
    00000000000005b0 l     F .text	0000000000000000              register_tm_clones
    0000000000000600 l     F .text	0000000000000000              __do_global_dtors_aux
    0000000000201030 l     O .bss	0000000000000001              completed.6983
    0000000000200de8 l     O .fini_array	0000000000000000              __do_global_dtors_aux_fini_array_entry
    0000000000000640 l     F .text	0000000000000000              frame_dummy
    0000000000200de0 l     O .init_array	0000000000000000              __frame_dummy_init_array_entry
    0000000000000000 l    df *ABS*	0000000000000000              test.c
    0000000000000000 l    df *ABS*	0000000000000000              divide.c
    0000000000000000 l    df *ABS*	0000000000000000              crtstuff.c
    0000000000000844 l     O .eh_frame	0000000000000000              __FRAME_END__
    0000000000000000 l    df *ABS*	0000000000000000
    0000000000200de8 l       .init_array	0000000000000000              __init_array_end
    0000000000200df0 l     O .dynamic	0000000000000000              _DYNAMIC
    0000000000200de0 l       .init_array	0000000000000000              __init_array_start
    0000000000000708 l       .eh_frame_hdr	0000000000000000              __GNU_EH_FRAME_HDR
    0000000000201000 l     O .got.plt	0000000000000000              _GLOBAL_OFFSET_TABLE_
    00000000000006f0 g     F .text	0000000000000002              __libc_csu_fini
    0000000000000000  w      *UND*	0000000000000000              _ITM_deregisterTMCloneTable
    0000000000201020  w      .data	0000000000000000              data_start
    0000000000201030 g       .data	0000000000000000              _edata
    0000000000000676 g     F .text	0000000000000006              divide
    00000000000006f4 g     F .fini	0000000000000000              _fini
    0000000000000000       F *UND*	0000000000000000              printf@@GLIBC_2.2.5
    0000000000000000       F *UND*	0000000000000000              __libc_start_main@@GLIBC_2.2.5
    0000000000201020 g       .data	0000000000000000              __data_start
    0000000000000000  w      *UND*	0000000000000000              __gmon_start__
    0000000000201028 g     O .data	0000000000000000              .hidden __dso_handle
    0000000000000700 g     O .rodata	0000000000000004              _IO_stdin_used
    0000000000000680 g     F .text	0000000000000065              __libc_csu_init
    0000000000201038 g       .bss	0000000000000000              _end
    0000000000000540 g     F .text	000000000000002b              _start
    0000000000201030 g       .bss	0000000000000000              __bss_start
    000000000000064a g     F .text	000000000000002c              main
    0000000000201030 g     O .data	0000000000000000              .hidden __TMC_END__
    0000000000000000  w      *UND*	0000000000000000              _ITM_registerTMCloneTable
    0000000000000000  w    F *UND*	0000000000000000              __cxa_finalize@@GLIBC_2.2.5
    0000000000000508 g     F .init	0000000000000000              _init

`$ objdump -t divide.a`

Output:

    divide.a:     file format elf64-x86-64

    SYMBOL TABLE:
    0000000000000000 l    df *ABS*	0000000000000000 divide.c
    0000000000000000 l    d  .text	0000000000000000 .text
    0000000000000000 l    d  .data	0000000000000000 .data
    0000000000000000 l    d  .bss	0000000000000000 .bss
    0000000000000000 l    d  .note.GNU-stack	0000000000000000 .note.GNU-stack
    0000000000000000 l    d  .eh_frame	0000000000000000 .eh_frame
    0000000000000000 l    d  .comment	0000000000000000 .comment
    0000000000000000 g     F .text	0000000000000006 divide

--------------------------------------------------------------------------------

`$ objdump -T test`

Output:

    test:     file format elf64-x86-64

    DYNAMIC SYMBOL TABLE:
    0000000000000000  w   D  *UND*	0000000000000000              _ITM_deregisterTMCloneTable
    0000000000000000      DF *UND*	0000000000000000  GLIBC_2.2.5 printf
    0000000000000000      DF *UND*	0000000000000000  GLIBC_2.2.5 __libc_start_main
    0000000000000000  w   D  *UND*	0000000000000000              __gmon_start__
    0000000000000000  w   D  *UND*	0000000000000000              _ITM_registerTMCloneTable
    0000000000000000  w   DF *UND*	0000000000000000  GLIBC_2.2.5 __cxa_finalize

`$ objdump -T divide.a`

Output:

    divide.a:     file format elf64-x86-64

    DYNAMIC SYMBOL TABLE:
    no symbols
