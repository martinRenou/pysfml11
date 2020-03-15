import pathlib

from pysfml11 import Shader, FileInputStream


def test_from_file():
    resources = pathlib.Path(__file__).parent.parent.absolute() / 'resources'

    vertex = Shader()
    assert vertex.load_from_file(str(resources / 'vertex.glsl'), Shader.Vertex)

    shader = Shader()
    assert shader.load_from_file(str(resources / 'vertex.glsl'), str(resources / 'fragment.glsl'))


def test_from_memory():
    resources = pathlib.Path(__file__).parent.parent.absolute() / 'resources'

    vertex_str = ''
    fragment_str = ''

    with open(resources / 'vertex.glsl', 'r') as fobj:
        vertex_str = fobj.read()

    with open(resources / 'fragment.glsl', 'r') as fobj:
        fragment_str = fobj.read()

    vertex = Shader()
    assert vertex.load_from_memory(vertex_str, Shader.Vertex)

    shader = Shader()
    assert shader.load_from_memory(vertex_str, fragment_str)


def test_from_stream():
    resources = pathlib.Path(__file__).parent.parent.absolute() / 'resources'

    vertex_stream = FileInputStream()
    vertex_stream.open(str(resources / 'vertex.glsl'))

    fragment_stream = FileInputStream()
    fragment_stream.open(str(resources / 'fragment.glsl'))

    vertex = Shader()
    assert vertex.load_from_stream(vertex_stream, Shader.Vertex)

    shader = Shader()
    assert shader.load_from_stream(vertex_stream, fragment_stream)


def test_set_uniform():
    resources = pathlib.Path(__file__).parent.parent.absolute() / 'resources'

    vertex = Shader()
    vertex.load_from_file(str(resources / 'vertex.glsl'), Shader.Vertex)

    vertex.set_uniform('x', 34.)
    vertex.set_uniform('x', 34)
