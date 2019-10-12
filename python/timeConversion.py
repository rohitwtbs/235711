#!/bin/python

from __future__ import print_function

import os
import sys

#
# Complete the timeConversion function below.
#
def timeConversion(s):
    arr = s.split(':')
    if arr[2][2] == 'P':
        return s[0:len(s)-2]
    n = int(s[0])
    n = (n+12) % 24
    return str(n) + arr[1] + arr[2][0:len(arr[2]-2)]

if __name__ == '__main__':
    s = raw_input()

    result = timeConversion(s)

