#!/bin/bash

cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.h get_next_line.c main.c
