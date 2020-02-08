from pysfml import VideoMode


def test_construction():
    mode = VideoMode(900, 700)

    assert mode.width == 900
    assert mode.height == 700
    assert mode.bits_per_pixel == 32
