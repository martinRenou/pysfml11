from pysfml import VideoMode


def test_construction():
    mode = VideoMode(900, 700)

    assert mode.width == 900
    assert mode.height == 700
    assert mode.bits_per_pixel == 32

    mode = VideoMode(800, 600, 16)

    assert mode.width == 800
    assert mode.height == 600
    assert mode.bits_per_pixel == 16


def test_attributes():
    mode = VideoMode(900, 700)

    mode.width = 1200
    mode.height = 1000
    mode.bits_per_pixel = 16

    assert mode.width == 1200
    assert mode.height == 1000
    assert mode.bits_per_pixel == 16
