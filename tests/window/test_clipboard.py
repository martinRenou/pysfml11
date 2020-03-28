import pytest

from pysfml11 import Clipboard


def test_clipboard(ci):
    if ci:
        pytest.skip("skipping Clipboard tests on CI (no display available)")

    value = Clipboard.string

    assert isinstance(value, str)

    Clipboard.string = 'Hello World!'

    value = Clipboard.string
    assert isinstance(value, str)
    assert value == 'Hello World!'
