import sys
import pathlib

import pytest

import pysfml11 as sf


def test_construction(ci):
    if ci:
        pytest.skip("skipping VertexBuffer tests on CI (no display available)")

    points_buffer = sf.VertexBuffer(sf.Points)
    stream_buffer = sf.VertexBuffer(sf.VertexBuffer.Usage.Stream)

    copy_buffer = sf.VertexBuffer(stream_buffer)

    assert copy_buffer.usage == sf.VertexBuffer.Usage.Stream
    assert points_buffer.primitive_type == sf.Points


def test_create(ci):
    if ci:
        pytest.skip("skipping VertexBuffer tests on CI (no display available)")

    buffer = sf.VertexBuffer(sf.Triangles)

    buffer.create(10)

    assert buffer.vertex_count == 10


def test_swap(ci):
    if ci:
        pytest.skip("skipping VertexBuffer tests on CI (no display available)")

    buffer_a = sf.VertexBuffer(sf.Triangles)
    buffer_b = sf.VertexBuffer(sf.Lines)

    buffer_a.create(10)
    buffer_b.create(22)

    buffer_a.swap(buffer_b)

    assert buffer_a.vertex_count == 22
    assert buffer_a.primitive_type == sf.Lines
    assert buffer_b.vertex_count == 10
    assert buffer_b.primitive_type == sf.Triangles
