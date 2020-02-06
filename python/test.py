import os
import argparse
import pynq
import numpy as np

parser = argparse.ArgumentParser()
parser.add_argument('--mult', type=int, default=2)
parser.add_argument('--a', type=int, default=4)
parser.add_argument('--b', type=int, default=8)


def main(args):
    curdir = os.path.dirname(os.path.abspath(__file__))
    overlay = pynq.Overlay(os.path.join(curdir, 'hw', 'design.bit'))
    mult = np.uint64(args.mult)
    a = np.uint32(args.a)
    b = np.uint32(args.b)

    # change register value
    overlay.stream_adder.register_map.mult = mult

    # create input
    data = np.uint64(0)
    data |= a
    data <<= 32
    data |= b

    # allocate buffer
    ibuff = pynq.allocate(shape=(1,), dtype=np.uint64)
    obuff = pynq.allocate(shape=(1,), dtype=np.uint64)
    ibuff[0] = data

    # run dma
    overlay.dma.sendchannel.transfer(ibuff)
    overlay.dma.recvchannel.transfer(obuff)
    overlay.dma.sendchannel.wait()
    overlay.dma.recvchannel.wait()

    # show result
    print('input: a = {}, b = {}, mult = {}'.format(a, b, mult))
    print('output: {}'.format(obuff[0]))


if __name__ == '__main__':
    args = parser.parse_args()
    main(args)
