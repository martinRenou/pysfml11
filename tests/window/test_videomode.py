import pytest

from pysfml11 import VideoMode


def test_construction(ci):
    if ci:
        pytest.skip("skipping VideoMode tests on CI (no display available)")

    mode = VideoMode(900, 700)

    assert mode.width == 900
    assert mode.height == 700
    assert mode.bits_per_pixel == 32

    mode = VideoMode(800, 600, 16)

    assert mode.width == 800
    assert mode.height == 600
    assert mode.bits_per_pixel == 16


def test_attributes(ci):
    if ci:
        pytest.skip("skipping VideoMode tests on CI (no display available)")

    mode = VideoMode(900, 700)

    mode.width = 1200
    mode.height = 1000
    mode.bits_per_pixel = 16

    assert mode.width == 1200
    assert mode.height == 1000
    assert mode.bits_per_pixel == 16


def test_get_desktop_mode(ci):
    if ci:
        pytest.skip("skipping VideoMode tests on CI (no display available)")

    mode = VideoMode.get_desktop_mode()

    assert mode.is_valid()


def test_get_fullscreen_modes(ci):
    if ci:
        pytest.skip("skipping VideoMode tests on CI (no display available)")

    modes = VideoMode.get_fullscreen_modes()

    assert isinstance(modes, list)
