import os
import pynq
import numpy as np

REG = 5
N = 10


def main():
    curdir = os.path.dirname(os.path.abspath(__file__))
    overlay = pynq.Overlay(os.path.join(curdir, 'hw', 'design.bit'))

    # read register value
    print('reg (before):', overlay.stream_adder.register_map.reg_V)

    # write register value
    overlay.stream_adder.register_map.reg_V = REG
    print('reg (after):', overlay.stream_adder.register_map.reg_V)

    # allocate input and output buffers in DRAM
    ibuff = pynq.allocate(shape=(N,), dtype=np.uint64)
    obuff = pynq.allocate(shape=(N,), dtype=np.uint64)

    # create input stream data
    for i in range(N):
        data = np.uint64(0)
        data |= np.uint32(i)  # upper 32 bits
        data <<= np.uint64(32)  # left shift by 32 bits
        data |= np.uint32(i)  # lower 32 bits
        ibuff[i] = data

    # run dma
    overlay.dma.sendchannel.transfer(ibuff)  # send input stream data
    overlay.dma.sendchannel.wait()  # wait until it finishes
    overlay.dma.recvchannel.transfer(obuff)  # receive output stream data
    overlay.dma.recvchannel.wait()  # wait until it finishes

    # show result
    for i in range(N):
        print('upper 32 bits: {}, lower 32 bits: {}, reg: {}'.format(
            i, i, REG))
        print('output: {}'.format(obuff[i]))


if __name__ == '__main__':
    main()
