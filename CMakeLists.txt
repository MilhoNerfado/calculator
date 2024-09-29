# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(BOARD qemu_riscv32)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(calculator)

target_sources(app PRIVATE src/main.c)
