#include <vector>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <pybind11/operators.h>
#include <pybind11/stl.h>
#include <pybind11/pybind11.h>


namespace py = pybind11;

#define PYSFML_CONCATENATE(A, B) PYSFML_CONCATENATE_IMPL(A, B)
#define PYSFML_CONCATENATE_IMPL(A, B) A##B
#define PYSFML_STRINGIFY(a) PYSFML_STRINGIFY_IMPL(a)
#define PYSFML_STRINGIFY_IMPL(a) #a
#define PYSFML_CONCAT_STRING(A, B) PYSFML_STRINGIFY(PYSFML_CONCATENATE(A, B))


PYBIND11_MODULE(pysfml11, m)
{
    m.doc() = R"pbdoc(
        pysfml11
        --------

        .. currentmodule:: pysfml11
    )pbdoc";

    /*****************
     * SYSTEM MODULE *
     *****************/

    py::module system = m.def_submodule("system");
    system.doc() = R"pbdoc(
        pysfml11.system
        ---------------

        .. currentmodule:: pysfml11.system

        .. autosummary::
           :toctree: _generate

           Time
           Clock
           Vector2
           Vector3
    )pbdoc";

    // TODO
    // class   sf::FileInputStream
    // class   sf::InputStream
    // class   sf::Lock
    // class   sf::MemoryInputStream
    // class   sf::Mutex
    // class   sf::NonCopyable
    // class   sf::String
    // class   sf::Thread
    // class   sf::ThreadLocal
    // class   sf::ThreadLocalPtr< T >
    // class   sf::Utf< N >
    // std::ostream &  sf::err ()

    /* Time class */
    py::class_<sf::Time>(system, "Time")
        .def(py::init<>())
        .def("as_seconds", &sf::Time::asSeconds)
        .def("as_milliseconds", &sf::Time::asMilliseconds)
        .def("as_microseconds", &sf::Time::asMicroseconds)
        .def_readonly_static("zero", &sf::Time::Zero)
        .def(py::self == py::self)
        .def(py::self != py::self)
        .def(py::self < py::self)
        .def(py::self > py::self)
        .def(py::self <= py::self)
        .def(py::self >= py::self)
        .def(-py::self)
        .def(py::self + py::self)
        .def(py::self += py::self)
        .def(py::self - py::self)
        .def(py::self -= py::self)
        .def(float() * py::self)
        .def(py::self * float())
        .def(py::self *= float())
        .def(py::self / float())
        .def(py::self /= float())
        .def(py::self / py::self)
        .def(py::self % py::self)
        .def(py::self %= py::self);

    /* Timing free functions */
    system.def("seconds", &sf::seconds);
    system.def("milliseconds", &sf::milliseconds);
    system.def("microseconds", &sf::microseconds);
    system.def("sleep", &sf::sleep);

    /* Clock class */
    py::class_<sf::Clock>(system, "Clock")
        .def(py::init<>())
        .def_property_readonly("elapsed_time", &sf::Clock::getElapsedTime)
        .def("restart", &sf::Clock::restart);

    #define PYSFML_IMPLEMENT_VECTOR2(T, TS)                               \
    py::class_<sf::Vector2<T>>(system, PYSFML_CONCAT_STRING(Vector2, TS)) \
        .def(py::init<T, T>(), py::arg("x") = T(0), py::arg("y") = T(0))  \
        .def(py::init<sf::Vector2<T>>(), py::arg("vector"))               \
        .def_readwrite("x", &sf::Vector2<T>::x)                           \
        .def_readwrite("y", &sf::Vector2<T>::y)                           \
        .def(-py::self)                                                   \
        .def(py::self += py::self)                                        \
        .def(py::self -= py::self)                                        \
        .def(py::self + py::self)                                         \
        .def(py::self - py::self)                                         \
        .def(T() * py::self)                                              \
        .def(py::self * T())                                              \
        .def(py::self *= T())                                             \
        .def(py::self / T())                                              \
        .def(py::self /= T())                                             \
        .def(py::self == py::self)                                        \
        .def(py::self != py::self);

    /* Vector2f class */
    PYSFML_IMPLEMENT_VECTOR2(float, f)
    /* Vector2i class */
    PYSFML_IMPLEMENT_VECTOR2(int, i)
    /* Vector2u class */
    PYSFML_IMPLEMENT_VECTOR2(uint, u)

    #undef PYSFML_IMPLEMENT_VECTOR2

    #define PYSFML_IMPLEMENT_VECTOR3(T, TS)                                                      \
    py::class_<sf::Vector3<T>>(system, PYSFML_CONCAT_STRING(Vector3, TS))                        \
        .def(py::init<T, T, T>(), py::arg("x") = T(0), py::arg("y") = T(0), py::arg("z") = T(0)) \
        .def(py::init<sf::Vector3<T>>(), py::arg("vector"))                                      \
        .def_readwrite("x", &sf::Vector3<T>::x)                                                  \
        .def_readwrite("y", &sf::Vector3<T>::y)                                                  \
        .def_readwrite("z", &sf::Vector3<T>::z)                                                  \
        .def(-py::self)                                                                          \
        .def(py::self += py::self)                                                               \
        .def(py::self -= py::self)                                                               \
        .def(py::self + py::self)                                                                \
        .def(py::self - py::self)                                                                \
        .def(T() * py::self)                                                                     \
        .def(py::self * T())                                                                     \
        .def(py::self *= T())                                                                    \
        .def(py::self / T())                                                                     \
        .def(py::self /= T())                                                                    \
        .def(py::self == py::self)                                                               \
        .def(py::self != py::self);

    /* Vector3f class */
    PYSFML_IMPLEMENT_VECTOR3(float, f)
    /* Vector3i class */
    PYSFML_IMPLEMENT_VECTOR3(int, i)
    /* Vector3u class */
    PYSFML_IMPLEMENT_VECTOR3(uint, u)

    #undef PYSFML_IMPLEMENT_VECTOR3


    /*****************
     * WINDOW MODULE *
     *****************/

    // TODO
    // class   sf::Clipboard  (needs sf::String)
    // class   sf::Cursor
    // class   sf::Event
    // class   sf::GlResource
    // class   sf::Joystick
    // class   sf::Keyboard
    // class   sf::Mouse
    // class   sf::Sensor
    // class   sf::Touch
    // class   sf::Window

    py::module window = m.def_submodule("window");
    window.doc() = R"pbdoc(
        pysfml11.window
        ---------------

        .. currentmodule:: pysfml11.window

        .. autosummary::
           :toctree: _generate

           VideoMode
    )pbdoc";

    /* ContextSettings class */
    py::class_<sf::ContextSettings> context_settings(window, "ContextSettings");

    py::enum_<sf::ContextSettings::Attribute>(context_settings, "Attribute", py::arithmetic())
        .value("default", sf::ContextSettings::Attribute::Default)
        .value("core", sf::ContextSettings::Attribute::Core)
        .value("debug", sf::ContextSettings::Attribute::Debug)
        .export_values();

    context_settings.def(
            py::init<std::size_t, std::size_t, std::size_t, std::size_t, sf::ContextSettings::Attribute, bool>(),
            py::arg("depth_bits") = 0, py::arg("stencil_bits") = 0, py::arg("major_version") = 1, py::arg("minor_version") = 1, py::arg("attribute_flags") = sf::ContextSettings::Attribute::Default, py::arg("s_rgb_capable") = false
        )
        .def_readwrite("depth_bits", &sf::ContextSettings::depthBits)
        .def_readwrite("stencil_bits", &sf::ContextSettings::stencilBits)
        .def_readwrite("antialiasing_level", &sf::ContextSettings::antialiasingLevel)
        .def_readwrite("major_version", &sf::ContextSettings::majorVersion)
        .def_readwrite("minor_version", &sf::ContextSettings::minorVersion)
        .def_readwrite("attribute_flags", &sf::ContextSettings::attributeFlags)
        .def_readwrite("s_rgb_capable", &sf::ContextSettings::sRgbCapable);

    /* Context class */
    py::class_<sf::Context>(window, "Context")
        .def(py::init<>())
        .def(py::init<const sf::ContextSettings&, std::size_t, std::size_t>())
        .def("set_active", &sf::Context::setActive)
        .def_property_readonly("settings", &sf::Context::getSettings)
        .def_static("is_extension_available", &sf::Context::isExtensionAvailable)
        // .def_static("get_function", &sf::Context::getFunction)
        .def_static("get_active_context", &sf::Context::getActiveContext)
        .def_static("get_active_context_id", &sf::Context::getActiveContextId)
        ;

    /* VideoMode class */
    py::class_<sf::VideoMode>(window, "VideoMode")
        .def(py::init<std::size_t, std::size_t, std::size_t>(), py::arg("width"), py::arg("height"), py::arg("bits_per_pixel") = 32)
        .def("is_valid", &sf::VideoMode::isValid)
        .def_static("get_desktop_mode", &sf::VideoMode::getDesktopMode)
        .def_static("get_fullscreen_modes", &sf::VideoMode::getFullscreenModes)
        .def_readwrite("width", &sf::VideoMode::width)
        .def_readwrite("height", &sf::VideoMode::height)
        .def_readwrite("bits_per_pixel", &sf::VideoMode::bitsPerPixel)
        .def(py::self == py::self)
        .def(py::self != py::self)
        .def(py::self < py::self)
        .def(py::self > py::self)
        .def(py::self <= py::self)
        .def(py::self >= py::self);


    /*******************
     * GRAPHICS MODULE *
     *******************/

    // TODO
    // class   sf::BlendMode
    // class   sf::Font
    // class   sf::Glyph
    // class   sf::Image
    // class   sf::Rect< T >
    // class   sf::RenderStates
    // class   sf::RenderTarget
    // class   sf::RenderTexture
    // class   sf::RenderWindow
    // class   sf::Shader
    // class   sf::Sprite
    // class   sf::Text
    // class   sf::Texture
    // class   sf::Transform
    // class   sf::Vertex
    // class   sf::VertexArray
    // class   sf::VertexBuffer
    // class   sf::View

    py::module graphics = m.def_submodule("graphics");
    graphics.doc() = R"pbdoc(
        pysfml11.graphics
        -----------------

        .. currentmodule:: pysfml11.graphics

        .. autosummary::
           :toctree: _generate

           Color
           RenderWindow
    )pbdoc";

    /* Color class */
    py::class_<sf::Color>(graphics, "Color")
        .def(py::init<uint8_t, uint8_t, uint8_t, uint8_t>(), py::arg("r") = 255, py::arg("g") = 255, py::arg("b") = 255, py::arg("a") = 255)
        .def(py::init<uint32_t>(), py::arg("color"))
        .def("to_integer", &sf::Color::toInteger)
        .def_readwrite("r", &sf::Color::r)
        .def_readwrite("g", &sf::Color::g)
        .def_readwrite("b", &sf::Color::b)
        .def_readwrite("a", &sf::Color::a)
        .def_readonly_static("black", &sf::Color::Black)
        .def_readonly_static("white", &sf::Color::White)
        .def_readonly_static("red", &sf::Color::Red)
        .def_readonly_static("green", &sf::Color::Green)
        .def_readonly_static("blue", &sf::Color::Blue)
        .def_readonly_static("yellow", &sf::Color::Yellow)
        .def_readonly_static("magenta", &sf::Color::Magenta)
        .def_readonly_static("cyan", &sf::Color::Cyan)
        .def_readonly_static("transparent", &sf::Color::Transparent)
        .def(py::self == py::self)
        .def(py::self != py::self)
        .def(py::self + py::self)
        .def(py::self - py::self)
        .def(py::self * py::self)
        .def(py::self += py::self)
        .def(py::self -= py::self)
        .def(py::self *= py::self);

    /* Drawable class */
    py::class_<sf::Drawable>(graphics, "Drawable");

    /* Transform class */
    py::class_<sf::Transform>(graphics, "Transform")
        .def(py::init<>())
        .def(py::init<float, float, float, float, float, float, float, float, float>())
        .def_property_readonly("matrix", [](const sf::Transform& transform) {
            const float* matrix = transform.getMatrix();

            return std::vector<float>(matrix, matrix + 16);
        })
        .def_property_readonly("inverse", &sf::Transform::getInverse)
        .def("transform_point", [](sf::Transform& transform, float x, float y) {
            return transform.transformPoint(x, y);
        })
        .def("transform_point", [](sf::Transform& transform, const sf::Vector2f& point) {
            return transform.transformPoint(point);
        })
        // .def("transform_rect", &sf::Transform::transformRect)
        .def("combine", &sf::Transform::combine)
        .def("translate", [](sf::Transform& transform, float x, float y) {
            return transform.translate(x, y);
        })
        .def("translate", [](sf::Transform& transform, const sf::Vector2f& offset) {
            return transform.translate(offset);
        })
        .def("rotate", [](sf::Transform& transform, float angle) {
            return transform.rotate(angle);
        })
        .def("rotate", [](sf::Transform& transform, float angle, float centerx, float centery) {
            return transform.rotate(angle, centerx, centery);
        })
        .def("rotate", [](sf::Transform& transform, float angle, const sf::Vector2f& center) {
            return transform.rotate(angle, center);
        })
        .def("scale", [](sf::Transform& transform, float scalex, float scaley) {
            return transform.scale(scalex, scaley);
        })
        .def("scale", [](sf::Transform& transform, float scalex, float scaley, float centerx, float centery) {
            return transform.scale(scalex, scaley, centerx, centery);
        })
        .def("scale", [](sf::Transform& transform, const sf::Vector2f& factors) {
            return transform.scale(factors);
        })
        .def("scale", [](sf::Transform& transform, const sf::Vector2f& factors, const sf::Vector2f& center) {
            return transform.scale(factors, center);
        })
        .def_readonly_static("identity", &sf::Transform::Identity)
        .def(py::self * py::self)
        .def(py::self *= py::self)
        .def(py::self * sf::Vector2f())
        .def(py::self == py::self)
        .def(py::self != py::self);

    /* Transformable class */
    py::class_<sf::Transformable>(graphics, "Transformable")
        .def_property("position", &sf::Transformable::getPosition, [](sf::Transformable& shape, const sf::Vector2f& position) { shape.setPosition(position); })
        .def_property("rotation", &sf::Transformable::getRotation, &sf::Transformable::setRotation)
        .def_property("scale", &sf::Transformable::getScale, [](sf::Transformable& shape, const sf::Vector2f& scale) { shape.setScale(scale); })
        .def_property("origin", &sf::Transformable::getOrigin, [](sf::Transformable& shape, const sf::Vector2f& origin) { shape.setOrigin(origin); })
        .def("move", [](sf::Transformable& shape, float offsetx, float offsety) {
            return shape.move(offsetx, offsety);
        })
        .def("move", [](sf::Transformable& shape, const sf::Vector2f& offset) {
            return shape.move(offset);
        })
        .def("rotate", &sf::Transformable::rotate)
        .def_property_readonly("transform", &sf::Shape::getTransform)
        .def_property_readonly("inverse_transform", &sf::Shape::getInverseTransform);

    /* Shape class */
    py::class_<sf::Shape, sf::Drawable, sf::Transformable>(graphics, "Shape")
        // .def_property("texture", &sf::Shape::setTexture, &sf::Shape::getTexture)
        // .def_property("textureRect", &sf::Shape::setTextureRect, &sf::Shape::getTextureRect)
        .def_property("fill_color", &sf::Shape::getFillColor, &sf::Shape::setFillColor)
        .def_property("outline_color", &sf::Shape::getOutlineColor, &sf::Shape::setOutlineColor)
        .def_property("outline_thickness", &sf::Shape::getOutlineThickness, &sf::Shape::setOutlineThickness)
        .def_property_readonly("point_count", &sf::Shape::getPointCount)
        // .def_property_readonly("local_bounds", &sf::Shape::getLocalBounds)
        // .def_property_readonly("global_bounds", &sf::Shape::getGlobalBounds)
        .def("get_point", &sf::Shape::getPoint);

    /* CircleShape class */
    py::class_<sf::CircleShape, sf::Shape>(graphics, "CircleShape")
        .def(py::init<float, std::size_t>(), py::arg("radius"), py::arg("point_count") = 30)
        .def_property("radius", &sf::CircleShape::getRadius, &sf::CircleShape::setRadius)
        .def_property("point_count", &sf::CircleShape::getPointCount, &sf::CircleShape::setPointCount);

    /* ConvexShape class */
    py::class_<sf::ConvexShape, sf::Shape>(graphics, "ConvexShape")
        .def(py::init<std::size_t>(), py::arg("point_count") = 0)
        .def_property("point_count", &sf::ConvexShape::getPointCount, &sf::ConvexShape::setPointCount)
        .def("set_point", &sf::ConvexShape::setPoint);

    /* RectangleShape class */
    py::class_<sf::RectangleShape, sf::Shape>(graphics, "RectangleShape")
        .def(py::init<const sf::Vector2f&>(), py::arg("size") = sf::Vector2f(0, 0))
        .def_property("size", &sf::RectangleShape::getSize, &sf::RectangleShape::setSize)
        .def_property_readonly("point_count", &sf::RectangleShape::getPointCount);

    /* RenderWindow class */
    py::class_<sf::RenderWindow>(graphics, "RenderWindow")
        .def(py::init<const sf::VideoMode&, const std::string&>())
        .def("is_open", &sf::RenderWindow::isOpen)
        .def("display", &sf::RenderWindow::display)
        .def("poll_event", [](sf::RenderWindow& renderwindow) {
            sf::Event event;
            return renderwindow.pollEvent(event);
        })
        .def("clear", &sf::RenderWindow::clear)
        .def("draw", [](sf::RenderWindow& renderwindow, const sf::Drawable& drawable) {
            renderwindow.draw(drawable);
        });


    /****************
     * AUDIO MODULE *
     ****************/

    py::module audio = m.def_submodule("audio");
    audio.doc() = R"pbdoc(
        pysfml11.audio
        ---------------

        .. currentmodule:: pysfml11.audio

        .. autosummary::
           :toctree: _generate
    )pbdoc";

    /* InputSoundFile class */
    py::class_<sf::InputSoundFile>(audio, "InputSoundFile")
        .def(py::init<>())
        .def("open_from_file", &sf::InputSoundFile::openFromFile)
        // Should be tested with Python bytes
        // .def("open_from_memory", &sf::InputSoundFile::openFromMemory)
        .def("open_from_stream", &sf::InputSoundFile::openFromStream)
        .def_property_readonly("sample_count", &sf::InputSoundFile::getSampleCount)
        .def_property_readonly("channel_count", &sf::InputSoundFile::getChannelCount)
        .def_property_readonly("sample_rate", &sf::InputSoundFile::getSampleRate)
        .def_property_readonly("duration", &sf::InputSoundFile::getDuration)
        .def_property_readonly("time_offset", &sf::InputSoundFile::getTimeOffset)
        .def_property_readonly("sample_offset", &sf::InputSoundFile::getSampleOffset)
        .def("seek", [](sf::InputSoundFile& input_sound_file, uint64_t sample_offset) {
            input_sound_file.seek(sample_offset);
        })
        .def("seek", [](sf::InputSoundFile& input_sound_file, sf::Time time_offset) {
            input_sound_file.seek(time_offset);
        })
        .def("read", [](sf::InputSoundFile& inputfile, uint64_t count) {
            sf::Int16 samples[count];

            sf::Uint64 readcount = inputfile.read(samples, count);
            return std::vector<int16_t>(samples, samples + readcount);
        });

    /* OutputSoundFile class */
    py::class_<sf::OutputSoundFile>(audio, "OutputSoundFile")
        .def(py::init<>())
        .def("open_from_file", &sf::OutputSoundFile::openFromFile)
        .def("write", [](sf::OutputSoundFile& outputfile, const std::vector<int16_t>& samples) {
            outputfile.write(samples.data(), samples.size());
        });

    /* Listener class */
    py::class_<sf::Listener>(audio, "Listener")
        .def_property_static(
            "global_volume",
            [](py::object) { return sf::Listener::getGlobalVolume(); },
            [](py::object, float volume) { sf::Listener::setGlobalVolume(volume); }
        )
        .def_property_static(
            "position",
            [](py::object) { return sf::Listener::getPosition(); },
            [](py::object, const sf::Vector3f& position) { sf::Listener::setPosition(position); }
        )
        .def_property_static(
            "direction",
            [](py::object) { return sf::Listener::getDirection(); },
            [](py::object, const sf::Vector3f& direction) { sf::Listener::setDirection(direction); }
        )
        .def_property_static(
            "up_vector",
            [](py::object) { return sf::Listener::getUpVector(); },
            [](py::object, const sf::Vector3f& up_vector) { sf::Listener::setUpVector(up_vector); }
        );

    /* SoundBuffer class */
    py::class_<sf::SoundBuffer>(audio, "SoundBuffer")
        .def(py::init<>())
        .def("load_from_file", &sf::SoundBuffer::loadFromFile)
        // Should be tested with Python bytes
        // .def("load_from_memory", &sf::SoundBuffer::loadFromMemory)
        .def("load_from_stream", &sf::SoundBuffer::loadFromStream)
        .def("load_from_samples", [](sf::SoundBuffer& soundbuffer, const std::vector<int16_t>& samples, uint64_t channelcount, uint64_t samplerate) {
            return soundbuffer.loadFromSamples(samples.data(), samples.size(), channelcount, samplerate);
        })
        .def("save_to_file", &sf::SoundBuffer::saveToFile)
        .def_property_readonly("samples", [](const sf::SoundBuffer& soundbuffer) {
            const int16_t* samples = soundbuffer.getSamples();

            return std::vector<int16_t>(samples, samples + soundbuffer.getSampleCount());
        })
        .def_property_readonly("sample_count", &sf::SoundBuffer::getSampleCount)
        .def_property_readonly("sample_rate", &sf::SoundBuffer::getSampleRate)
        .def_property_readonly("channel_count", &sf::SoundBuffer::getChannelCount)
        .def_property_readonly("duration", &sf::SoundBuffer::getDuration);

    /* SoundSource class */
    py::class_<sf::SoundSource> soundsource(audio, "SoundSource");

    py::enum_<sf::SoundSource::Status>(soundsource, "Status")
        .value("stopped", sf::SoundSource::Status::Stopped)
        .value("paused", sf::SoundSource::Status::Paused)
        .value("playing", sf::SoundSource::Status::Playing)
        .export_values();

    soundsource.def_property("pitch", &sf::SoundSource::getPitch, &sf::SoundSource::setPitch)
        .def_property("volume", &sf::SoundSource::getVolume, &sf::SoundSource::setVolume)
        .def_property("position", &sf::SoundSource::getPosition, [](sf::SoundSource& source, const sf::Vector3f& position) {
            source.setPosition(position);
        })
        .def_property("relative_to_listener", &sf::SoundSource::isRelativeToListener, &sf::SoundSource::setRelativeToListener)
        .def_property("min_distance", &sf::SoundSource::getMinDistance, &sf::SoundSource::setMinDistance)
        .def_property("attenuation", &sf::SoundSource::getAttenuation, &sf::SoundSource::setAttenuation)
        .def_property_readonly("status", &sf::SoundSource::getStatus);

    /* Sound class */
    py::class_<sf::Sound, sf::SoundSource>(audio, "Sound")
        .def(py::init<>())
        .def("play", &sf::Sound::play)
        .def("pause", &sf::Sound::pause)
        .def("stop", &sf::Sound::stop)
        .def_property("buffer", &sf::Sound::getBuffer, &sf::Sound::setBuffer)
        .def("reset_buffer", &sf::Sound::resetBuffer)
        .def_property("loop", &sf::Sound::getLoop, &sf::Sound::setLoop)
        .def_property("playing_offset", &sf::Sound::getPlayingOffset, &sf::Sound::setPlayingOffset);

    /* SoundStream class */
    py::class_<sf::SoundStream, sf::SoundSource>(audio, "SoundStream")
        .def("play", &sf::SoundStream::play)
        .def("pause", &sf::SoundStream::pause)
        .def("stop", &sf::SoundStream::stop);

    /* Music class */
    py::class_<sf::Music, sf::SoundStream>(audio, "Music")
        .def(py::init<>())
        .def("open_from_file", &sf::Music::openFromFile)
        // Should be tested with Python bytes
        // .def("open_from_memory", &sf::Music::openFromMemory)
        .def("open_from_stream", &sf::Music::openFromStream)
        // .def_property("loop_points", &sf::Sound::getLoopPoints, &sf::Sound::setLoopPoints)
        .def_property_readonly("channel_count", &sf::Music::getChannelCount)
        .def_property_readonly("sample_rate", &sf::Music::getSampleRate)
        .def_property_readonly("duration", &sf::Music::getDuration)
        .def_property("loop", &sf::Music::getLoop, &sf::Music::setLoop)
        .def_property("playing_offset", &sf::Music::getPlayingOffset, &sf::Music::setPlayingOffset);

    /* SoundRecorder class */
    py::class_<sf::SoundRecorder>(audio, "SoundRecorder")
        .def("start", &sf::SoundRecorder::start)
        .def("stop", &sf::SoundRecorder::stop)
        .def_property_readonly("sample_rate", &sf::SoundRecorder::getSampleRate)
        .def_property("device", &sf::SoundRecorder::getDevice, &sf::SoundRecorder::setDevice)
        .def_property("channel_count", &sf::SoundRecorder::getChannelCount, &sf::SoundRecorder::setChannelCount)
        // TODO + tests
        ;


#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}

#undef PYSFML_CONCAT_STRING
#undef PYSFML_STRINGIFY_IMPL
#undef PYSFML_STRINGIFY
#undef PYSFML_CONCATENATE_IMPL
#undef PYSFML_CONCATENATE
