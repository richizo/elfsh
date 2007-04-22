/*
**
** $Id: asm_sparc_sethi.c,v 1.4 2007-04-22 20:48:41 strauss Exp $
**
*/
#include "libasm.h"

int
asm_sparc_sethi(asm_instr * ins, u_char * buf, u_int len,
		asm_processor * proc)
{
  struct s_decode_branch opcode;
  sparc_convert_branch(&opcode, buf, proc);
  
  ins->type = ASM_TYPE_ASSIGN;

  if (!opcode.rd && !opcode.imm) {
    ins->instr = ASM_SP_NOP;
    ins->type = ASM_TYPE_NOP;
    ins->nb_op = 0;
  }
  else {
    ins->instr = ASM_SP_SETHI;
    ins->nb_op = 2;
    ins->op1.type = ASM_SP_OTYPE_REGISTER;
    ins->op1.base_reg = opcode.rd;
    ins->op2.type = ASM_SP_OTYPE_SETHI;
    ins->op2.imm = opcode.imm;
  }

  return 4;
}
