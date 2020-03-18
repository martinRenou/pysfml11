import pathlib

import pysfml11 as sf


def test_from_file():
    resources = pathlib.Path(__file__).parent.parent.absolute() / 'resources'

    vertex = sf.Shader()
    assert vertex.load_from_file(str(resources / 'vertex.glsl'), sf.Shader.Vertex)

    shader = sf.Shader()
    assert shader.load_from_file(str(resources / 'vertex.glsl'), str(resources / 'fragment.glsl'))


def test_from_memory():
    resources = pathlib.Path(__file__).parent.parent.absolute() / 'resources'

    vertex_str = ''
    fragment_str = ''

    with open(resources / 'vertex.glsl', 'r') as fobj:
        vertex_str = fobj.read()

    with open(resources / 'fragment.glsl', 'r') as fobj:
        fragment_str = fobj.read()

    vertex = sf.Shader()
    assert vertex.load_from_memory(vertex_str, sf.Shader.Vertex)

    shader = sf.Shader()
    assert shader.load_from_memory(vertex_str, fragment_str)


def test_from_stream():
    resources = pathlib.Path(__file__).parent.parent.absolute() / 'resources'

    vertex_stream = sf.FileInputStream()
    vertex_stream.open(str(resources / 'vertex.glsl'))

    fragment_stream = sf.FileInputStream()
    fragment_stream.open(str(resources / 'fragment.glsl'))

    vertex = sf.Shader()
    assert vertex.load_from_stream(vertex_stream, sf.Shader.Vertex)

    shader = sf.Shader()
    assert shader.load_from_stream(vertex_stream, fragment_stream)


def test_set_uniform():
    resources = pathlib.Path(__file__).parent.parent.absolute() / 'resources'

    vertex = sf.Shader()
    vertex.load_from_file(str(resources / 'vertex.glsl'), sf.Shader.Vertex)

    vertex.set_uniform('x', 34.)
    vertex.set_uniform('x', 34)

    vertex.set_uniform('vec_2', sf.Glsl.Vec2(0.2, 0.3))
    vertex.set_uniform('vec_2', sf.Glsl.Ivec2(2, 3))
    vertex.set_uniform('vec_2', sf.Glsl.Bvec2(True, False))

    vertex.set_uniform('vec_3', sf.Glsl.Vec3(0.2, 0.3, 0.4))
    vertex.set_uniform('vec_3', sf.Glsl.Ivec3(2, 3, 4))
    vertex.set_uniform('vec_3', sf.Glsl.Bvec3(True, False, True))

    vertex.set_uniform('vec_4', sf.Glsl.Vec4(0.2, 0.3, 0.4, 0.5))
    vertex.set_uniform('vec_4', sf.Glsl.Ivec4(2, 3, 4, 5))
    vertex.set_uniform('vec_4', sf.Glsl.Bvec4(True, False, True, True))

    vertex.set_uniform('vec_4', sf.Glsl.Ivec4(2, 3, 4, 5))
    vertex.set_uniform('vec_4', sf.Glsl.Bvec4(True, False, True, True))

    vertex.set_uniform('matrix', sf.Glsl.Mat3([
        0.4, 0.5, 0.6,
        0.8, 0.9, 0.7,
        0.2, 0.3, 0.1
    ]))

    vertex.set_uniform('PMatrix', sf.Glsl.Mat4([
        0.4, 0.5, 0.6, 0.8,
        0.9, 0.7, 0.2, 0.3,
        0.1, 0.6, 0.7, 0.1,
        0.9, 0.7, 0.2, 0.3
    ]))
