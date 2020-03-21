import math

import pytest

import pysfml11 as sf


def test_types():
    assert sf.Glsl.Vec2 is sf.Vector2f
    assert sf.Glsl.Ivec2 is sf.Vector2i
    assert sf.Glsl.Bvec2 is sf.Vector2b

    assert sf.Glsl.Vec3 is sf.Vector3f
    assert sf.Glsl.Ivec3 is sf.Vector3i
    assert sf.Glsl.Bvec3 is sf.Vector3b


def test_vec4():
    vec = sf.Glsl.Vec4(2.2, 4, 5, 6)
    assert math.isclose(vec.x, 2.2, rel_tol=0.01)
    assert vec.y == 4
    assert vec.z == 5
    assert vec.w == 6

    vec = sf.Glsl.Vec4(sf.Color.Black)
    assert vec.x == 0
    assert vec.y == 0
    assert vec.z == 0
    assert vec.w == 1

    vec = sf.Glsl.Ivec4(2, 4, 5, 6)
    assert vec.x == 2
    assert vec.y == 4
    assert vec.z == 5
    assert vec.w == 6

    with pytest.raises(TypeError):
        sf.Glsl.Ivec4(2.2, 4, 5, 6)

    vec = sf.Glsl.Bvec4(True, False, True, True)
    assert vec.x
    assert not vec.y
    assert vec.z
    assert vec.w


def test_mat():
    data3 = [
        0, 1, 2,
        3, 4, 5,
        6, 7, 8,
    ]

    data4 = [
        0, 1, 2, 3,
        4, 5, 6, 7,
        8, 9, 0, 1,
        2, 3, 4, 5,
    ]

    sf.Glsl.Mat3(data3)

    with pytest.raises(TypeError):
        sf.Glsl.Mat3(data4)

    sf.Glsl.Mat4(data4)

    with pytest.raises(TypeError):
        sf.Glsl.Mat4(data3)


def test_repr():
    vec = sf.Glsl.Vec4(sf.Color.Black)
    assert str(vec) == '<pysfml11.Glsl.Vec4 x=0 y=0 z=0 w=1>'

    vec = sf.Glsl.Ivec4(2, 4, 5, 6)
    assert str(vec) == '<pysfml11.Glsl.Ivec4 x=2 y=4 z=5 w=6>'

    vec = sf.Glsl.Bvec4(True, False, True, True)
    assert str(vec) == '<pysfml11.Glsl.Bvec4 x=True y=False z=True w=True>'
