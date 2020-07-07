#!/usr/bin/python3

'''UTF-8 validator'''

def validUTF8(data):
    """Determines if given data represents valid UTF-8 encoding
    Args:
        data: list of integers
    Returns:
        True if valid UTF-8 encoding, otherwise False
    """
    bit_count = 0
    for n in data:
        mask = 1 << 7
        if not bit_count:
            while n & mask:
                bit_count += 1
                mask >>= 1
            if bit_count > 4:
                return False
        elif n >> 6 != 2:
            return False
        if bit_count:
            bit_count -= 1
    return bit_count == 0
def validUTF8_2(data):
    '''Checks if UTF-8 is valid'''
    byte_cnt = 0

    for n in data:
        if byte_cnt:
            byte_cnt -= 1
            if (((n & 0xff) >> 6) != 2):
                return False
        elif (n & 0xF0) == 0xF0:  # 4 byte
            byte_cnt = 3
        elif (n & 0xE0) == 0xE0:  # 3 byte
            byte_cnt = 2
        elif (n & 0xC0) == 0xC0:  # 2 byte
            byte_cnt = 1
        elif not (n & 0x80):      # 1 byte
            byte_cnt = 0
        else:
            return False
    return not byte_cnt
