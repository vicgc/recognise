#!/usr/bin/env python
# Print text in all colors

from clint.textui import colored, puts, indent
from clint.arguments import Args
from clint import piped_in


if __name__ == '__main__':

    puts('Test:')
    with indent(4):
        puts('%s Fake test 1.' % colored.green('✔'))
        puts('%s Fake test 2.' % colored.red('✖'))

    puts('')
    puts('Greet:')
    with indent(4):
        puts(colored.red('Здравствуйте'))
        puts(colored.green('你好。'))
        puts(colored.yellow('سلام'))
        puts(colored.magenta('안녕하세요'))
        puts(colored.blue('नमस्ते'))
        puts(colored.cyan('γειά σου'))

    puts('')
    puts('Arguments:')
    with indent(4):
        puts('%s' % colored.red(args[0]))

    puts('')
    puts('File:')