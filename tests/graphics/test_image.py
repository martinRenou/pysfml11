import pathlib

import pysfml11 as sf


def test_construction():
    sf.Image()


def test_create():
    image = sf.Image()

    image.create(30, 30)
    image.create(30, 30, sf.Color.White)


def test_load_from_file():
    image = sf.Image()

    resources = pathlib.Path(__file__).parent.parent.absolute() / 'resources'

    assert image.load_from_file(str(resources / 'saxo.jpg'))
    assert not image.load_from_file(str(resources / 'this_file_does_not_exist.jpg'))


def test_save_to_file():
    image = sf.Image()

    image.create(30, 30, sf.Color.Blue)

    resources = pathlib.Path(__file__).parent.parent.absolute() / 'resources'

    assert image.save_to_file(str(resources / 'blue.jpg'))
    assert image.load_from_file(str(resources / 'blue.jpg'))


def test_load_from_file():
    image = sf.Image()

    resources = pathlib.Path(__file__).parent.parent.absolute() / 'resources'

    image.load_from_file(str(resources / 'saxo.jpg'))

    assert image.size.x == 562
    assert image.size.y == 422


def test_create_mask_from_color():
    image = sf.Image()

    image.create_mask_from_color(sf.Color.Blue)
    image.create_mask_from_color(sf.Color.Blue, 125)
