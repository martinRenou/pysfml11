from pysfml.system import Vector2


def test_construction():
    vec = Vector2()

    assert vec.x == 0
    assert vec.y == 0

    vec1 = Vector2(2, 4)

    assert vec1.x == 2
    assert vec1.y == 4

    vec2 = Vector2(vec1)

    assert vec2.x == 2
    assert vec2.y == 4


def test_operators():
    vec1 = Vector2(3, 4)
    vec2 = Vector2(5, 6)

    assert (- vec1).x == -3
    assert (- vec1).y == -4

    vec3 = Vector2()
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
