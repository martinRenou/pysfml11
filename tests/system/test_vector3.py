from pysfml.system import Vector3


def test_construction():
    vec = Vector3()

    assert vec.x == 0
    assert vec.y == 0
    assert vec.z == 0

    vec1 = Vector3(2, 4)

    assert vec1.x == 2
    assert vec1.y == 4
    assert vec1.z == 0

    vec2 = Vector3(vec1)

    assert vec2.x == 2
    assert vec2.y == 4
    assert vec2.z == 0


def test_operators():
    vec1 = Vector3(3, 4, 5)
    vec2 = Vector3(5, 6, 7)

    assert (- vec1).x == -3
    assert (- vec1).y == -4
    assert (- vec1).z == -5

    vec3 = Vector3()
    vec3 += vec1
    assert vec3.x == 3
    assert vec3.y == 4
    assert vec3.z == 5

    vec3 -= vec1
    assert vec3.x == 0
    assert vec3.y == 0
    assert vec3.z == 0

    vec3 = vec1 + vec2
    assert vec3.x == 8
    assert vec3.y == 10
    assert vec3.z == 12

    vec3 = vec2 - vec1
    assert vec3.x == 2
    assert vec3.y == 2
    assert vec3.z == 2

    vec3 = vec1 * 2
    assert vec3.x == 6
    assert vec3.y == 8
    assert vec3.z == 10

    vec3 = 2 * vec2
    assert vec3.x == 10
    assert vec3.y == 12
    assert vec3.z == 14

    vec3 = vec2 / 2.
    assert vec3.x == 2.5
    assert vec3.y == 3
    assert vec3.z == 3.5

    vec3 /= 2
    assert vec3.x == 1.25
    assert vec3.y == 1.5
    assert vec3.z == 1.75

    assert not vec1 == vec2
    assert vec1 != vec2
