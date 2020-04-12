"""Pytest configuration file."""

def pytest_addoption(parser):
    parser.addoption("--ci", action="store", default=False)


def pytest_generate_tests(metafunc):
    option_value = metafunc.config.option.ci
    if 'ci' in metafunc.fixturenames and option_value is not None:
        metafunc.parametrize("ci", [option_value])
