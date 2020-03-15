import pysfml11 as sf


def test_types():
    assert sf.Glsl.Vec2 is sf.Vector2f
    assert sf.Glsl.IVec2 is sf.Vector2i
    assert sf.Glsl.BVec2 is sf.Vector2b

    assert sf.Glsl.Vec3 is sf.Vector3f
    assert sf.Glsl.IVec3 is sf.Vector3i
    assert sf.Glsl.BVec3 is sf.Vector3b
