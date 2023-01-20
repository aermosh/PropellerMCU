/* Generated automatically by the program `genconstants'
   from the machine description file `md'.  */

#ifndef GCC_INSN_CONSTANTS_H
#define GCC_INSN_CONSTANTS_H

#define UNSPEC_CONST_WORD 10
#define UNSPEC_COGSTOP 2
#define UNSPEC_WAITPNE 7
#define UNSPEC_WAITVID 8
#define UNSPEC_FCACHE_CALL 123
#define UNSPEC_LOCKSET 15
#define UNSPEC_LOOP_START 103
#define UNSPEC_COGID 0
#define UNSPEC_POPM 17
#define UNSPEC_LOCKNEW 12
#define UNSPEC_WAITPEQ 6
#define FRAME_REG 14
#define UNSPEC_LOCKCLR 14
#define UNSPEC_LOOP_END 104
#define UNSPEC_CAS 19
#define UNSPEC_COGINIT 1
#define UNSPEC_FCACHE_FUNC_START 124
#define UNSPEC_LOCKSTATE 11
#define UNSPEC_REVERSE 4
#define UNSPEC_LOCKRET 13
#define UNSPEC_NAKED_RET 101
#define UNSPEC_COGSTATE 3
#define UNSPEC_FCACHE_DONE 125
#define UNSPEC_CLKSET 18
#define UNSPEC_FCACHE_RET 122
#define UNSPEC_FCACHE_LOAD 9
#define CC_REG 18
#define UNSPEC_FCACHE_LABEL_REF 121
#define UNSPEC_PUSHM 16
#define LINK_REG 15
#define LMM_PC_REG 17
#define SP_REG 16
#define UNSPEC_NATIVE_RET 102
#define STORE_FLAG_VALUE 1
#define UNSPEC_WAITCNT 5

enum processor {
  PROCESSOR_P1 = 0,
  PROCESSOR_P2 = 1
};
#define NUM_PROCESSOR_VALUES 2
extern const char *const processor_strings[];

#endif /* GCC_INSN_CONSTANTS_H */
