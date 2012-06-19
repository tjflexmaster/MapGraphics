TEMPLATE = subdirs

SUBDIRS += MapGraphics \
    TestApp \
    ViewModelTest

TestApp.depends += MapGraphics
