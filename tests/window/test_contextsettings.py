import pytest

from pysfml11 import ContextSettings


def test_construction(ci):
    if ci:
        pytest.skip("skipping Context tests on CI (no display available)")

    settings1 = ContextSettings()

    assert settings1.depth_bits == 0
    assert settings1.stencil_bits == 0
    assert settings1.antialiasing_level == 1
    assert settings1.attribute_flags == ContextSettings.Attribute.Default
