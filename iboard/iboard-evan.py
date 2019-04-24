while True:
    try:
        # If there is an even number of 1's, and an even number of 0's, the user is free.
        # using [2::] to cut off binary string prefix.
        strings = [bin(ord(x))[2::] for x in list(input())]
        
        # need to add several zeros if they're missing from the beginning
        num_0 = 0
        num_1 = 0
        for char in strings:
            num_0 += 7 - len(char) # 7 bit ascii

        for bit in ''.join(strings):
            if bit == '0':
                num_0 += 1
            elif bit == '1':
                num_1 += 1
        if num_0 % 2 == 0 and num_1 % 2 == 0:
            print('free')
        else:
            print('trapped')
    except EOFError:
        break
