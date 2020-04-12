import pytest

from pysfml11 import Vector2u, Cursor


def test_construction_system(ci):
    if ci:
        pytest.skip("skipping Cursor tests on CI (no display available)")

    cursor = Cursor()
    result = cursor.load_from_system(Cursor.Type.Hand)

    assert isinstance(cursor, Cursor)
    assert result


def test_construction_pixels(ci):
    if ci:
        pytest.skip("skipping Cursor tests on CI (no display available)")

    cursor = Cursor()

    pixels = [
        0, 255, 255, 255, 125, 125, 125, 255,
        255, 255, 0, 255, 200, 200, 200, 255,
    ]
    size = Vector2u(2, 2)
    hotspot = Vector2u(0, 1)

    result = cursor.load_from_pixels(pixels, size, hotspot)

    assert isinstance(cursor, Cursor)
    assert result
