import os
import struct
# -*- coding: utf-8 -*-
filename, count_one, count_zero = './demo.ipynb', 0, 0
for current_byte in list(open(filename, 'rb').read()):
    count_one += bin(struct.unpack("B", current_byte)[0]).count('1')
count_zero = os.path.getsize(filename) * 8 - count_one
print('One:  ' + str(count_one) + ' times\nZero: ' + str(count_zero) +
      ' times\nOne/Zero: ' + str(float(count_one) / float(count_zero)))
