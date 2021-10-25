//
// Created by olesg on 10/25/2021.
//
#pragma once
#include <common.h>
u8 wram_read(u16 address);
void wram_write(u16 address, u8 value);

u8 hram_read(u16 address);
void hram_write(u16 address, u8 value);