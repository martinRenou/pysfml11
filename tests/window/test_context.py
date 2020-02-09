from pysfml11.window import Context, ContextSettings


def test_construction():
    context1 = Context()

    assert isinstance(context1.get_settings(), ContextSettings)
    assert Context.get_active_context() is context1

    context2 = Context(ContextSettings(), 800, 600)

    assert Context.get_active_context() is context2
