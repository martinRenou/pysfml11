"""Dumps the events in the console."""
import pysfml11 as sf


width = 800
height = 600

mode = sf.VideoMode(width, height)

window = sf.RenderWindow(mode, 'My awesome SFML application!')


while (window.is_open()):
    event = sf.Event()

    while window.poll_event(event):
        print('\n{}!'.format(event.type))

        if event.type == sf.Event.Resized:
            print(event.size.width, event.size.height)

        if event.type == sf.Event.TextEntered:
            print(event.text.unicode)

        if event.type == sf.Event.KeyPressed or event.type == sf.Event.KeyReleased:
            print(event.key.code, event.key.alt, event.key.control, event.key.shift, event.key.system)

        if event.type == sf.Event.MouseMoved:
            print(event.mouse_move.x, event.mouse_move.y)

        if event.type == sf.Event.MouseButtonPressed or event.type == sf.Event.MouseButtonReleased:
            print(event.mouse_button.button, event.mouse_button.x, event.mouse_button.y)

        if event.type == sf.Event.MouseWheelMoved:
            print(event.mouse_wheel.delta, event.mouse_wheel.x, event.mouse_wheel.y)

        if event.type == sf.Event.MouseWheelScrolled:
            print(event.mouse_wheel_scroll.wheel, event.mouse_wheel_scroll.delta, event.mouse_wheel_scroll.x, event.mouse_wheel_scroll.y)

    window.clear(sf.Color.White)

    window.display()
