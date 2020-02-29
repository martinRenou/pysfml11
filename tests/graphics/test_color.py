from pysfml11.graphics import Color


def test_construction():
    color1 = Color(123, 200, 200, 255)

    assert color1.r == 123
    assert color1.g == 200
    assert color1.b == 200
    assert color1.a == 255

    color2 = Color(color1.to_integer())

    assert color2.r == 123
    assert color2.g == 200
    assert color2.b == 200
    assert color2.a == 255


def test_colors():
    black = Color.Black

    assert black.r == 0
    assert black.g == 0
    assert black.b == 0
    assert black.a == 255

    transparent = Color.Transparent

    assert transparent.r == 0
    assert transparent.g == 0
    assert transparent.b == 0
    assert transparent.a == 0


def test_operators():
    color1 = Color(123, 200, 200, 255)
    color2 = Color(123, 150, 200, 255)

    assert not color1 == color2
    assert color1 != color2

    color3 = color1 + color2
    assert color3.r == 246
    assert color3.g == 255
    assert color3.b == 255
    assert color3.a == 255

    color3 = color1 - color2
    assert color3.r == 0
    assert color3.g == 50
    assert color3.b == 0
    assert color3.a == 0
