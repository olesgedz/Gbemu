#pragma once
#include <common.h>

typedef struct {
  bool active;
  u8 byte;
  u8 value;
  u8 start_delay;
} dma_context;


void dma_start(u8 start);
void dma_tick();
bool dma_transferring();