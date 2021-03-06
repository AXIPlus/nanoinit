/**
 * MIT License
 * 
 * Copyright (c) 2022 AXIPlus / Adrian Lita / Alex Stancu - www.axiplus.com
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * */

#pragma once

#include <stdbool.h>

typedef enum {
    NI_NO_SPECIAL_MODE = 0,
    NI_COMMAND_RELOAD = 1,
} nanoinit_special_mode_t;

typedef struct nanoinit_arguments_s {
    char *config_file;
    char *config_json_object;
    char *log_path;
    bool manual_mode;
    nanoinit_special_mode_t special_mode;
    int verbosity_level;
} nanoinit_arguments_t;

const nanoinit_arguments_t *arguments_init(int argc, char **argv);
void arguments_free();
