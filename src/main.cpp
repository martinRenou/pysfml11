#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <pybind11/stl.h>
#include <pybind11/pybind11.h>


namespace py = pybind11;


PYBIND11_MODULE(pysfml, m)
{
    m.doc() = R"pbdoc(
        pysfml
        ------

        .. currentmodule:: pysfml
    )pbdoc";

    /*****************
     * SYSTEM MODULE *
     *****************/

    py::module system = m.def_submodule("system");
    system.doc() = R"pbdoc(
        pysfml.system
        -------------

        .. currentmodule:: pysfml.system

        .. autosummary::
           :toctree: _generate

           VideoMode
           RenderWindow
    )pbdoc";

    // TODO
    // class   sf::Clock
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
    // class   sf::Time
    // class   sf::Utf< N >
    // class   sf::Vector2< T >
    // class   sf::Vector3< T >
    // ANativeActivity *   sf::getNativeActivity ()
    // void    sf::sleep (Time duration)
    // std::ostream &  sf::err ()

    py::class_<sf::Time>(system, "Time")
        .def(py::init<>())
        .def("as_seconds", &sf::Time::asSeconds)
        .def("as_milliseconds", &sf::Time::asMilliseconds)
        .def("as_microseconds", &sf::Time::asMicroseconds)
        .def_property_readonly_static("zero", []() { return sf::Time::Zero; });

    system.def("seconds", &sf::seconds);
    system.def("milliseconds", &sf::milliseconds);
    system.def("microseconds", &sf::microseconds);

    py::class_<sf::Clock>(system, "Clock")
        .def(py::init<>())
        .def("get_elapsed_time", &sf::Clock::getElapsedTime)
        .def("restart", &sf::Clock::restart);


    /*****************
     * WINDOW MODULE *
     *****************/

    py::module window = m.def_submodule("window");
    window.doc() = R"pbdoc(
        pysfml.window
        -------------

        .. currentmodule:: pysfml.window

        .. autosummary::
           :toctree: _generate

           VideoMode
           RenderWindow
    )pbdoc";

    py::class_<sf::VideoMode>(window, "VideoMode")
        .def(py::init<int, int, int>(), py::arg("width"), py::arg("height"), py::arg("bits_per_pixel") = 32)
        .def("is_valid", &sf::VideoMode::isValid)
        .def_static("get_desktop_mode", &sf::VideoMode::getDesktopMode)
        .def_static("get_fullscreen_modes", &sf::VideoMode::getFullscreenModes)
        .def_readwrite("width", &sf::VideoMode::width)
        .def_readwrite("height", &sf::VideoMode::height)
        .def_readwrite("bits_per_pixel", &sf::VideoMode::bitsPerPixel);

    py::class_<sf::RenderWindow>(window, "RenderWindow")
        .def(py::init<const sf::VideoMode&, const std::string&>());

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}
