#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Print text in all colors

from clint.textui import colored, puts, indent
from clint.arguments import Args


args = Args()

if __name__ == '__main__':

    puts('Tests:')
    with indent(4):
        puts('%s All tests passed 1.' % colored.green('✔'))
        puts('%s Failed? ' % colored.red('✖'))

    puts('')
    puts('Greet:')
    with indent(4):
        puts(colored.red('Здравствуйте'))
        puts(colored.blue('नमस्ते'))
        puts(colored.cyan('γειά σου'))

    puts('')
    puts('Arguments:')
    with indent(4):
        puts('%s' % colored.red(args[0]))

    puts('')
