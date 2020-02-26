from pysfml11.window import Clipboard


def test_clipboard():
    value = Clipboard.string

    assert isinstance(value, str)

    Clipboard.string = 'Hello World!'

    value = Clipboard.string
    assert isinstance(value, str)
    assert value == 'Hello World!'
