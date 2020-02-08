import pytest

from pysfml.system import Vector2f, Vector2i, Vector2u


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
