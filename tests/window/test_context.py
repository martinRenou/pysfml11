import pytest

from pysfml11 import Context, ContextSettings


def test_construction(ci):
    if ci:
        pytest.skip("skipping Context tests on CI (no display available)")

    context1 = Context()

    assert isinstance(context1.settings, ContextSettings)
    assert Context.get_active_context() is context1

    context2 = Context(ContextSettings(), 800, 600)

    assert Context.get_active_context() is context2
