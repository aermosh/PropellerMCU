/* Generated automatically by the program `genflags'
   from the machine description file `md'.  */

#ifndef GCC_INSN_FLAGS_H
#define GCC_INSN_FLAGS_H

#define HAVE_nop 1
#define HAVE_addsi3 1
#define HAVE_subsi3 1
#define HAVE_abssi2 1
#define HAVE_negsi2 1
#define HAVE_one_cmplsi2 1
#define HAVE_andsi3 1
#define HAVE_iorsi3 1
#define HAVE_xorsi3 1
#define HAVE_ashlsi3 1
#define HAVE_ashrsi3 1
#define HAVE_lshrsi3 1
#define HAVE_rotlsi3 1
#define HAVE_rotrsi3 1
#define HAVE_stack_pushm (TARGET_LMM && reload_completed)
#define HAVE_stack_popm (TARGET_LMM && reload_completed)
#define HAVE_umaxsi3 1
#define HAVE_uminsi3 1
#define HAVE_smaxsi3 1
#define HAVE_sminsi3 1
#define HAVE_compare_unsigned 1
#define HAVE_compare_zero 1
#define HAVE_compare_carryonly 1
#define HAVE_compare_signed 1
#define HAVE_call_std (!TARGET_LMM)
#define HAVE_sibcall_std (!TARGET_LMM)
#define HAVE_call_std_lmm (TARGET_LMM)
#define HAVE_sibcall_std_lmm (TARGET_LMM)
#define HAVE_call_native 1
#define HAVE_call_native_value 1
#define HAVE_indirect_jump 1
#define HAVE_fcache_jump 1
#define HAVE_fcache_func_start 1
#define HAVE_fcache_done 1
#define HAVE_fcache_done_func 1
#define HAVE_return_in_fcache 1
#define HAVE_return_cog (!TARGET_LMM)
#define HAVE_return_lmm (TARGET_LMM)
#define HAVE_naked_return 1
#define HAVE_native_return 1
#define HAVE_doloop_begin_internal 1
#define HAVE_djnz (!TARGET_LMM)
#define HAVE_djnz_lmm (TARGET_LMM && !TARGET_CMM)
#define HAVE_cogid 1
#define HAVE_coginit 1
#define HAVE_cogstop 1
#define HAVE_clkset 1
#define HAVE_reverse 1
#define HAVE_locknew 1
#define HAVE_lockret 1
#define HAVE_lockclr 1
#define HAVE_lockset 1
#define HAVE_waitcnt 1
#define HAVE_waitpeq 1
#define HAVE_waitpne 1
#define HAVE_waitvid 1
#define HAVE_fcache_load 1
#define HAVE_fcache_const_word 1
#define HAVE_movsi 1
#define HAVE_movhi 1
#define HAVE_movqi 1
#define HAVE_zero_extendhisi2 1
#define HAVE_zero_extendqisi2 1
#define HAVE_mulsi3 1
#define HAVE_udivmodsi4 1
#define HAVE_divmodsi4 1
#define HAVE_udivmoddi4 1
#define HAVE_movsicc 1
#define HAVE_cstoresi4 1
#define HAVE_cbranchsi4 1
#define HAVE_call 1
#define HAVE_sibcall 1
#define HAVE_call_value 1
#define HAVE_sibcall_value 1
#define HAVE_jump 1
#define HAVE_prologue 1
#define HAVE_epilogue 1
#define HAVE_sibcall_epilogue 1
#define HAVE_return (propeller_can_use_return ())
#define HAVE_doloop_begin 1
#define HAVE_doloop_end 1
#define HAVE_clzsi2 1
#define HAVE_ctzsi2 1
#define HAVE_paritysi2 1
#define HAVE_sync_compare_and_swapsi 1
extern rtx        gen_nop                     (void);
extern rtx        gen_addsi3                  (rtx, rtx, rtx);
extern rtx        gen_subsi3                  (rtx, rtx, rtx);
extern rtx        gen_abssi2                  (rtx, rtx);
extern rtx        gen_negsi2                  (rtx, rtx);
extern rtx        gen_one_cmplsi2             (rtx, rtx);
extern rtx        gen_andsi3                  (rtx, rtx, rtx);
extern rtx        gen_iorsi3                  (rtx, rtx, rtx);
extern rtx        gen_xorsi3                  (rtx, rtx, rtx);
extern rtx        gen_ashlsi3                 (rtx, rtx, rtx);
extern rtx        gen_ashrsi3                 (rtx, rtx, rtx);
extern rtx        gen_lshrsi3                 (rtx, rtx, rtx);
extern rtx        gen_rotlsi3                 (rtx, rtx, rtx);
extern rtx        gen_rotrsi3                 (rtx, rtx, rtx);
extern rtx        gen_stack_pushm             (rtx, rtx);
extern rtx        gen_stack_popm              (rtx, rtx);
extern rtx        gen_umaxsi3                 (rtx, rtx, rtx);
extern rtx        gen_uminsi3                 (rtx, rtx, rtx);
extern rtx        gen_smaxsi3                 (rtx, rtx, rtx);
extern rtx        gen_sminsi3                 (rtx, rtx, rtx);
extern rtx        gen_compare_unsigned        (rtx, rtx);
extern rtx        gen_compare_zero            (rtx, rtx);
extern rtx        gen_compare_carryonly       (rtx, rtx);
extern rtx        gen_compare_signed          (rtx, rtx);
extern rtx        gen_call_std                (rtx, rtx);
extern rtx        gen_sibcall_std             (rtx, rtx);
extern rtx        gen_call_std_lmm            (rtx, rtx);
extern rtx        gen_sibcall_std_lmm         (rtx, rtx);
extern rtx        gen_call_native             (rtx, rtx);
extern rtx        gen_call_native_value       (rtx, rtx, rtx);
extern rtx        gen_indirect_jump           (rtx);
extern rtx        gen_fcache_jump             (rtx, rtx);
extern rtx        gen_fcache_func_start       (void);
extern rtx        gen_fcache_done             (void);
extern rtx        gen_fcache_done_func        (void);
extern rtx        gen_return_in_fcache        (rtx);
extern rtx        gen_return_cog              (rtx);
extern rtx        gen_return_lmm              (rtx);
extern rtx        gen_naked_return            (void);
extern rtx        gen_native_return           (rtx);
extern rtx        gen_doloop_begin_internal   (rtx, rtx, rtx);
extern rtx        gen_djnz                    (rtx, rtx, rtx);
extern rtx        gen_djnz_lmm                (rtx, rtx, rtx);
extern rtx        gen_cogid                   (rtx);
extern rtx        gen_coginit                 (rtx, rtx);
extern rtx        gen_cogstop                 (rtx);
extern rtx        gen_clkset                  (rtx);
extern rtx        gen_reverse                 (rtx, rtx, rtx);
extern rtx        gen_locknew                 (rtx);
extern rtx        gen_lockret                 (rtx);
extern rtx        gen_lockclr                 (rtx);
extern rtx        gen_lockset                 (rtx, rtx);
extern rtx        gen_waitcnt                 (rtx, rtx, rtx);
extern rtx        gen_waitpeq                 (rtx, rtx);
extern rtx        gen_waitpne                 (rtx, rtx);
extern rtx        gen_waitvid                 (rtx, rtx);
extern rtx        gen_fcache_load             (rtx, rtx);
extern rtx        gen_fcache_const_word       (rtx);
extern rtx        gen_movsi                   (rtx, rtx);
extern rtx        gen_movhi                   (rtx, rtx);
extern rtx        gen_movqi                   (rtx, rtx);
extern rtx        gen_zero_extendhisi2        (rtx, rtx);
extern rtx        gen_zero_extendqisi2        (rtx, rtx);
extern rtx        gen_mulsi3                  (rtx, rtx, rtx);
extern rtx        gen_udivmodsi4              (rtx, rtx, rtx, rtx);
extern rtx        gen_divmodsi4               (rtx, rtx, rtx, rtx);
extern rtx        gen_udivmoddi4              (rtx, rtx, rtx, rtx);
extern rtx        gen_movsicc                 (rtx, rtx, rtx, rtx);
extern rtx        gen_cstoresi4               (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchsi4              (rtx, rtx, rtx, rtx);
#define GEN_CALL(A, B, C, D) gen_call ((A), (B))
extern rtx        gen_call                    (rtx, rtx);
#define GEN_SIBCALL(A, B, C, D) gen_sibcall ((A), (B))
extern rtx        gen_sibcall                 (rtx, rtx);
#define GEN_CALL_VALUE(A, B, C, D, E) gen_call_value ((A), (B), (C))
extern rtx        gen_call_value              (rtx, rtx, rtx);
#define GEN_SIBCALL_VALUE(A, B, C, D, E) gen_sibcall_value ((A), (B), (C))
extern rtx        gen_sibcall_value           (rtx, rtx, rtx);
extern rtx        gen_jump                    (rtx);
extern rtx        gen_prologue                (void);
extern rtx        gen_epilogue                (void);
extern rtx        gen_sibcall_epilogue        (void);
extern rtx        gen_return                  (void);
extern rtx        gen_doloop_begin            (rtx, rtx, rtx, rtx);
extern rtx        gen_doloop_end              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_clzsi2                  (rtx, rtx);
extern rtx        gen_ctzsi2                  (rtx, rtx);
extern rtx        gen_paritysi2               (rtx, rtx);
extern rtx        gen_sync_compare_and_swapsi (rtx, rtx, rtx, rtx);

#endif /* GCC_INSN_FLAGS_H */
