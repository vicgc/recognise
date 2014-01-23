#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
from optparse import OptionParser

from clint.textui import colored, puts, indent
from clint.arguments import Args


args = Args()

parser = OptionParser()
parser.add_option("-f", "--file", dest="./console.py",
                    help="write report to FILE", metavar="FILE")
parser.add_option("-q", "--quiet",
                    action="store_false", dest="verbose", default=True,
                    help="don't print status messages to stdout")

if __name__ == '__main__':
    (options, args) = parser.parse_args()
    puts('Tests:')
    with indent(4):
        pass

    puts('')
    with indent(4):
        puts(colored.red('Здравствуйте'))

    puts('')

    print sys.argv[0]
