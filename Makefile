# Copyright (C) 2009, 2010, 2011, 2012 Ian <wjuma@students.usiu.ac.ke>
# 
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-13, USA

CC	    = $(shell which gcc)
LIBFLAGS    = -lm
THREADFLAGS = -pthread
OPTFLAGS    = -g -o0
LINTFLAGS   = -Wall -pedantic
CFLAGS	    = $(THREADFLAGS) $(LINTFLAGS) -std=c99


all: build

build: src/new-terminal.c
	echo "Building program ... "
	$(CC) $(THREADFLAGS) -o bin/new src/new-terminal.c
	echo "Done :)"


clean:
	rm -rf bin/*.o bin/.so

help:
	$(shell echo "Help Page")

get-deps:
	echo "am not getting anything just yet :)"

test:
	echo "by default all tests shall pass"
