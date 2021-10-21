#include <cpu.h>
#include <bus.h>

cpu_context ctx = {0};

void cpu_init() {
	ctx.regs.pc = 0x100;
}

static void fetch_instruction() {
	ctx.cur_opcode = bus_read(ctx.regs.pc++);
  	ctx.cur_inst = instruction_by_opcode(ctx.cur_opcode);
	if (ctx.cur_inst == NULL) {
	  printf("Unknown instruction %02X!\n", ctx.cur_opcode);
	  exit(-7);
	}
}

static void fetch_data() {
	ctx.mem_dest = 0;
	ctx.dest_is_mem = false;

  switch (ctx.cur_inst->mode) {
	case AM_IMP:
	  return;
	  break;
	case AM_R:
	  ctx.fetched_data = cpu_read_reg(ctx.cur_inst->reg_1);
	  return;
	  break;
	case AM_R_D8:
	  ctx.fetched_data = bus_read(ctx.regs.pc);
	  emu_cycles(1);
	  ctx.regs.pc++;
	  return;
	  break;
	case AM_D16: {
	  u16 lo = bus_read(ctx.regs.pc);
	  emu_cycles(1);

	  u16  hi = bus_read(ctx.regs.pc + 1);
	  emu_cycles(1);
	  ctx.fetched_data = lo | (hi << 8);
	  ctx.regs.pc += 2;
	  return;
	  break;
	}
	default:
	  printf("Unknown addressing mode %d!\n", ctx.cur_inst->mode);
	  exit(-7);
	  return;
  }
}

static void execute() {
  printf("\tNo executing yet...\n");
}


bool cpu_step() {
  if (!ctx.halted) {
	u16 pc = ctx.regs.pc;
	fetch_instruction();
	fetch_data();
	printf("Executing Instruction: %02x PC: %04x\n", ctx.cur_opcode, pc);
	execute();
  }
    return true;
}
