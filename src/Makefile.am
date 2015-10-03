GMOCK_HOME = /home/michael/libraries/gmock-1.7.0

bin_PROGRAMS = Soundex
Soundex_SOURCES = main.cpp SoundexTest.cpp

AM_LDFLAGS = -pthread

AM_CXXFLAGS = -std=c++0x -Wall
AM_CPPFLAGS = -I$(GMOCK_HOME)/gtest/include \
              -I$(GMOCK_HOME)/include

LDADD = $(GMOCK_HOME)/mybuild/libgmock.a \
        $(GMOCK_HOME)/mybuild/libgmock_main.a \
        $(GMOCK_HOME)/gtest/mybuild/libgtest_main.a \
        $(GMOCK_HOME)/gtest/mybuild/libgtest.a
