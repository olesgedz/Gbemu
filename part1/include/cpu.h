#pragma once

#include <common.h>
#include <instructions.h>
#include <emu.h>

typedef struct {
  u8 			a;
  u8 			b;
  u8 			c;
  u8 			d;
  u8 			e;
  u8 			f;
  u8 			h;
  u8 			l;
  u16 			pc;
  u16 			sp;
} 				cpu_registers;

typedef struct {
  cpu_registers regs;
  //current fetch
  u16 			fetched_data;
  u16 			mem_dest;
  u8  			cur_opcode;
  instruction	*cur_inst;
  bool			dest_is_mem;
  bool 			halted;
  bool 			stepping;
} 				cpu_context;


void cpu_init();
bool cpu_step();
u16 cpu_read_reg(reg_type rt);
