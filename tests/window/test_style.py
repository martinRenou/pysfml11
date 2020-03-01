from pysfml11.window import Style


def test_style():
    assert Style.Default == Style.Titlebar | Style.Resize | Style.Close
