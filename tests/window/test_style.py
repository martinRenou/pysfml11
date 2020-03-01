from pysfml11 import Style


def test_style():
    assert Style.Default == Style.Titlebar | Style.Resize | Style.Close
