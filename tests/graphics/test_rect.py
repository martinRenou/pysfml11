import math

import pytest

from pysfml11 import IntRect, FloatRect, Vector2i


def test_construction():
    rect = IntRect(0, 20, 200, 255)

    assert rect.left == 0
    assert rect.top == 20
    assert rect.width == 200
    assert rect.height == 255

    with pytest.raises(TypeError):
        IntRect(0.2, 20, 200, 255)

    with pytest.raises(TypeError):
        IntRect('Hey', 20, 200, 255)

    rect = IntRect(0, 20)

    assert rect.left == 0
    assert rect.top == 20
    assert rect.width == 0
    assert rect.height == 0

    rect = IntRect(width=10, height=20, top=200, left=255)

    assert rect.left == 255
    assert rect.top == 200
    assert rect.width == 10
    assert rect.height == 20

    rect = IntRect(position=Vector2i(20, 21))

    assert rect.left == 20
    assert rect.top == 21
    assert rect.width == 0
    assert rect.height == 0

    rect = IntRect(position=Vector2i(20, 21), size=Vector2i(200, 300))

    assert rect.left == 20
    assert rect.top == 21
    assert rect.width == 200
    assert rect.height == 300

    rect = FloatRect(0, 20.2, 200.5, 255.5)

    assert rect.left == 0
    assert math.isclose(rect.top, 20.2, rel_tol=0.01)
    assert math.isclose(rect.width, 200.5, rel_tol=0.01)
    assert math.isclose(rect.height, 255.5, rel_tol=0.01)


def test_contains():
    r1 = IntRect(0, 0, 20, 5)
    r2 = IntRect(4, 2, 18, 10)

    assert r1.contains(3, 1)
    assert not r2.contains(3, 1)

    point = Vector2i(3, 1)

    assert r1.contains(point)
    assert not r2.contains(point)


def test_intersects():
    r1 = IntRect(0, 0, 20, 5)
    r2 = IntRect(4, 2, 18, 10)

    intersection = IntRect()

    assert r1.intersects(r2)

    r1.intersects(r2, intersection)

    assert intersection.left == 4
    assert intersection.top == 2
    assert intersection.width == 16
    assert intersection.height == 3


def test_operator():
    r1 = IntRect(0, 0, 20, 5)
    r2 = IntRect(0, 0, 20, 5)

    assert r1 == r2

    r2.left = 3

    assert r1 != r2


def test_repr():
    r = IntRect(0, 0, 20, 5)

    assert str(r) == '<sfml.IntRect left=0 top=0 width=20 height=5>'

    r = FloatRect(0, 0, 20, 5)

    assert str(r) == '<sfml.FloatRect left=0 top=0 width=20 height=5>'
