from pysfml11 import ContextSettings


def test_construction():
    settings1 = ContextSettings()

    assert settings1.depth_bits == 0
    assert settings1.stencil_bits == 0
    assert settings1.antialiasing_level == 1
    assert settings1.attribute_flags == ContextSettings.Attribute.Default
