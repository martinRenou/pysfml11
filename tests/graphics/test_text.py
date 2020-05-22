import pysfml11 as sf


def test_construction():
    sf.Text()
    sf.Text('Hello World!', sf.Font())
    sf.Text('Hello World!', sf.Font(), 12)


def test_properties():
    text = sf.Text('Hello World!', sf.Font(), 12)

    assert text.string == 'Hello World!'
    text.string = 'Coucou!'
    assert text.string == 'Coucou!'

    assert sf.Text().character_size == 30
    assert text.character_size == 12
    text.character_size = 3
    assert text.character_size == 3

    assert text.style == sf.Text.Regular
    text.style = sf.Text.Italic
    assert text.style == sf.Text.Italic
