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
            print(event.size)

        if event.type == sf.Event.TextEntered:
            print(event.text, 'which is:', chr(event.text.unicode))

        if event.type == sf.Event.KeyPressed or event.type == sf.Event.KeyReleased:
            print(event.key)

        if event.type == sf.Event.MouseMoved:
            print(event.mouse_move)

        if event.type == sf.Event.MouseButtonPressed or event.type == sf.Event.MouseButtonReleased:
            print(event.mouse_button)

        if event.type == sf.Event.MouseWheelMoved:
            print(event.mouse_wheel)

        if event.type == sf.Event.MouseWheelScrolled:
            print(event.mouse_wheel_scroll)

        if event.type == sf.Event.JoystickButtonPressed or event.type == sf.Event.JoystickButtonReleased:
            print(event.joystick_button)

        if event.type == sf.Event.JoystickMoved:
            print(event.joystick_move)

        if event.type == sf.Event.JoystickConnected or event.type == sf.Event.JoystickDisconnected:
            print(event.joystick_connect)

        if event.type == sf.Event.SensorChanged:
            print(event.sensor)

    window.clear(sf.Color.White)

    window.display()
