from pysfml11 import PrimitiveType, Vector2f, Vertex, VertexArray


def test_vertexarray():
    lines = VertexArray(PrimitiveType.LineStrip, 4)

    assert lines.vertex_count == 4
    assert lines.primitive_type == PrimitiveType.LineStrip

    lines.resize(6)
    assert lines.vertex_count == 6

    lines.clear()
    assert lines.vertex_count == 0

    triangles = VertexArray(PrimitiveType.TriangleStrip, 10)

    assert triangles.vertex_count == 10
    assert triangles.primitive_type == PrimitiveType.TriangleStrip

    triangles.append(Vertex(position=Vector2f(4, 5)))

    assert triangles.vertex_count == 11

    vertex = triangles[10]

    assert vertex.position == Vector2f(4, 5)

