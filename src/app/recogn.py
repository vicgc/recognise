#!/usr/bin/env python
# -*- coding: utf-8 -*-

from clint.textui import colored, puts, indent
from clint.arguments import Args


args = Args()

if __name__ == '__main__':

    puts('Tests:')
    with indent(4):
        pass

    puts('')
    with indent(4):
        puts(colored.red('Здравствуйте'))

    puts('')
