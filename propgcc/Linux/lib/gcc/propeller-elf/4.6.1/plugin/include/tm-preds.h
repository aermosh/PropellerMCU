/* Generated automatically by the program 'build/genpreds'
   from the machine description file '/media/psf/Home/Github/propgcc/gcc/gcc/config/propeller/propeller.md'.  */

#ifndef GCC_TM_PREDS_H
#define GCC_TM_PREDS_H

#ifdef HAVE_MACHINE_MODES
extern int general_operand (rtx, enum machine_mode);
extern int address_operand (rtx, enum machine_mode);
extern int register_operand (rtx, enum machine_mode);
extern int pmode_register_operand (rtx, enum machine_mode);
extern int scratch_operand (rtx, enum machine_mode);
extern int immediate_operand (rtx, enum machine_mode);
extern int const_int_operand (rtx, enum machine_mode);
extern int const_double_operand (rtx, enum machine_mode);
extern int nonimmediate_operand (rtx, enum machine_mode);
extern int nonmemory_operand (rtx, enum machine_mode);
extern int push_operand (rtx, enum machine_mode);
extern int pop_operand (rtx, enum machine_mode);
extern int memory_operand (rtx, enum machine_mode);
extern int indirect_operand (rtx, enum machine_mode);
extern int ordered_comparison_operator (rtx, enum machine_mode);
extern int comparison_operator (rtx, enum machine_mode);
extern int call_operand (rtx, enum machine_mode);
extern int sibcall_operand (rtx, enum machine_mode);
extern int symbolic_operand (rtx, enum machine_mode);
extern int function_operand (rtx, enum machine_mode);
extern int propeller_dst_operand (rtx, enum machine_mode);
extern int propeller_cogreg_operand (rtx, enum machine_mode);
extern int propeller_gpr_operand (rtx, enum machine_mode);
extern int propeller_src_operand (rtx, enum machine_mode);
extern int propeller_add_operand (rtx, enum machine_mode);
extern int propeller_and_operand (rtx, enum machine_mode);
extern int predicate_operator (rtx, enum machine_mode);
extern int propeller_math_op2 (rtx, enum machine_mode);
extern int propeller_math_op1 (rtx, enum machine_mode);
extern int propeller_math_op1srcflags (rtx, enum machine_mode);
extern int propeller_pair_op2 (rtx, enum machine_mode);
extern int cc_register (rtx, enum machine_mode);
extern int propeller_cmm_const16 (rtx, enum machine_mode);
extern int propeller_big_const (rtx, enum machine_mode);
extern int immediate_1_9 (rtx, enum machine_mode);
extern int immediate_0_8 (rtx, enum machine_mode);
extern int immediate_byte (rtx, enum machine_mode);
extern int immediate_nybble (rtx, enum machine_mode);
extern int negative_nybble (rtx, enum machine_mode);
extern int propeller_cmm_src_operand (rtx, enum machine_mode);
extern int stack_operand (rtx, enum machine_mode);
extern int propeller_store_multiple_vector (rtx, enum machine_mode);
extern int propeller_load_multiple_vector (rtx, enum machine_mode);
#endif /* HAVE_MACHINE_MODES */

#define CONSTRAINT_NUM_DEFINED_P 1
enum constraint_num
{
  CONSTRAINT__UNKNOWN = 0,
  CONSTRAINT_A,
  CONSTRAINT_B,
  CONSTRAINT_C,
  CONSTRAINT_Q,
  CONSTRAINT_S,
  CONSTRAINT_h,
  CONSTRAINT_O,
  CONSTRAINT_I,
  CONSTRAINT_M,
  CONSTRAINT_N,
  CONSTRAINT_W,
  CONSTRAINT_z,
  CONSTRAINT_y,
  CONSTRAINT_U,
  CONSTRAINT__LIMIT
};

extern enum constraint_num lookup_constraint (const char *);
extern bool constraint_satisfied_p (rtx, enum constraint_num);

#define CONSTRAINT_LEN(c_,s_) 1

extern enum reg_class regclass_for_constraint (enum constraint_num);
#define REG_CLASS_FROM_CONSTRAINT(c_,s_) \
    regclass_for_constraint (lookup_constraint (s_))
#define REG_CLASS_FOR_CONSTRAINT(x_) \
    regclass_for_constraint (x_)

extern bool insn_const_int_ok_for_constraint (HOST_WIDE_INT, enum constraint_num);
#define CONST_OK_FOR_CONSTRAINT_P(v_,c_,s_) \
    insn_const_int_ok_for_constraint (v_, lookup_constraint (s_))

#define CONST_DOUBLE_OK_FOR_CONSTRAINT_P(v_,c_,s_) 0

#define EXTRA_CONSTRAINT_STR(v_,c_,s_) \
    constraint_satisfied_p (v_, lookup_constraint (s_))

extern bool insn_extra_memory_constraint (enum constraint_num);
#define EXTRA_MEMORY_CONSTRAINT(c_,s_) insn_extra_memory_constraint (lookup_constraint (s_))

#define EXTRA_ADDRESS_CONSTRAINT(c_,s_) false

#endif /* tm-preds.h */
