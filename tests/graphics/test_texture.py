import sys
import pathlib

import pytest

import pysfml11 as sf


RESOURCES = pathlib.Path(__file__).parent.parent.absolute() / 'resources'


def test_construction(ci):
    if ci:
        pytest.skip("skipping Texture tests on CI (no display available)")
    texture = sf.Texture()
    texture.create(50, 50)


def test_load_from_file(ci):
    if ci:
        pytest.skip("skipping Texture tests on CI (no display available)")
    texture = sf.Texture()

    assert texture.load_from_file(str(RESOURCES / 'saxo.jpg'))

    assert texture.size.x == 562
    assert texture.size.y == 422

    assert not texture.load_from_file(str(RESOURCES / 'this_file_does_not_exist.jpg'))


def test_load_from_image(ci):
    if ci:
        pytest.skip("skipping Texture tests on CI (no display available)")
    image = sf.Image()
    texture = sf.Texture()

    image.load_from_file(str(RESOURCES / 'saxo.jpg'))
    texture.load_from_image(image)

    assert texture.size.x == 562
    assert texture.size.y == 422


def test_to_image(ci):
    if ci:
        pytest.skip("skipping Texture tests on CI (no display available)")
    texture = sf.Texture()

    texture.load_from_file(str(RESOURCES / 'saxo.jpg'))

    image = texture.copy_to_image()

    assert isinstance(image, sf.Image)

    assert image.size.x == 562
    assert image.size.y == 422


def test_update(ci):
    if ci:
        pytest.skip("skipping Texture tests on CI (no display available)")
    image = sf.Image()
    texture = sf.Texture()
    texture.create(562, 422)

    image.load_from_file(str(RESOURCES / 'saxo.jpg'))

    texture.update(image)
    texture.update(image, 50, 50)
    texture.update(texture)
    texture.update(texture, 20, 20)


def test_properties(ci):
    if ci:
        pytest.skip("skipping Texture tests on CI (no display available)")
    texture = sf.Texture()

    texture.load_from_file(str(RESOURCES / 'saxo.jpg'))

    assert not texture.repeated
    texture.repeated = True
    assert texture.repeated

    assert not texture.smooth
    texture.smooth = True
    assert texture.smooth

    assert not texture.srgb
    texture.srgb = True
    assert texture.srgb


def test_generate_mipmap(ci):
    if ci:
        pytest.skip("skipping Texture tests on CI (no display available)")
    if sys.platform.startswith("win"):
        pytest.skip('skip texture.generate_mipmap test on Windows')

    texture = sf.Texture()

    texture.load_from_file(str(RESOURCES / 'saxo.jpg'))

    assert texture.generate_mipmap()


def test_static_methods(ci):
    if ci:
        pytest.skip("skipping Texture tests on CI (no display available)")
    texture = sf.Texture()

    texture.load_from_file(str(RESOURCES / 'saxo.jpg'))

    sf.Texture.bind(texture, sf.Texture.CoordinateType.Pixels)
    sf.Texture.bind(texture, sf.Texture.CoordinateType.Normalized)

    assert isinstance(sf.Texture.get_maximum_size(), int)
