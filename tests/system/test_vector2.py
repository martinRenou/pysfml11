import pytest

from pysfml11 import Vector2f, Vector2i, Vector2u, Vector2b


def test_construction():
    vec = Vector2f()

    assert vec.x == 0
    assert vec.y == 0

    vec1 = Vector2f(2, 4)

    assert vec1.x == 2
    assert vec1.y == 4

    vec2 = Vector2f(vec1)

    assert vec2.x == 2
    assert vec2.y == 4

    vec3 = Vector2i(3, 4)

    assert vec3.x == 3
    assert vec3.y == 4

    vec4 = Vector2u(3, 4)

    assert vec4.x == 3
    assert vec4.y == 4

    with pytest.raises(TypeError):
        Vector2i(3.4, 4)

    with pytest.raises(TypeError):
        Vector2u(-3, 4)

    vec5 = Vector2b(True, False)

    assert vec5.x
    assert not vec5.y


def test_operators():
    vec1 = Vector2f(3, 4)
    vec2 = Vector2f(5, 6)

    assert (- vec1).x == -3
    assert (- vec1).y == -4

    vec3 = Vector2f()
    vec3 += vec1
    assert vec3.x == 3
    assert vec3.y == 4

    vec3 -= vec1
    assert vec3.x == 0
    assert vec3.y == 0

    vec3 = vec1 + vec2
    assert vec3.x == 8
    assert vec3.y == 10

    vec3 = vec2 - vec1
    assert vec3.x == 2
    assert vec3.y == 2

    vec3 = vec1 * 2
    assert vec3.x == 6
    assert vec3.y == 8

    vec3 = 2 * vec2
    assert vec3.x == 10
    assert vec3.y == 12

    vec3 = vec2 / 2.
    assert vec3.x == 2.5
    assert vec3.y == 3

    vec3 /= 2
    assert vec3.x == 1.25
    assert vec3.y == 1.5

    assert not vec1 == vec2
    assert vec1 != vec2


def test_repr():
    vec = Vector2f()

    assert str(vec) == '<pysfml11.Vector2f x=0 y=0>'

    vec1 = Vector2f(2, 4)

    assert str(vec1) == '<pysfml11.Vector2f x=2 y=4>'

    vec3 = Vector2i(3, 4)

    assert str(vec3) == '<pysfml11.Vector2i x=3 y=4>'

    vec4 = Vector2u(3, 4)

    assert str(vec4) == '<pysfml11.Vector2u x=3 y=4>'
