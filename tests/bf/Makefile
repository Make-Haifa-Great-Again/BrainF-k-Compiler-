CXX = g++
CC = $(CXX)

CPPFLAGS = -I $(INC_DIR) -I $(INL_DIR)
CPPFLAGS += -MMD -MP
# CPPFLAGS += -DDEBUG
# c language
CFLAGS = -g3

# c++ language
CXXFLAGS = -std=c++11
CXXFLAGS+= -Wall -pedantic
# CXXFLAGS+= -Werror -Wextra
CXXFLAGS+= -g3

LDFLAGS =
LDLIBS =

SRC_DIR= ../../src/
INC_DIR= ../../inc/
INL_DIR= ../../inc/inl/

TARGET = utest
# ! Fill only this:
OBJS = utest.o $(SRC_DIR)brain_fuck.o $(SRC_DIR)bf_compiler.o $(SRC_DIR)bf_operations.o

all: $(TARGET)

$(TARGET): $(OBJS)

check: $(TARGET)
	./$(TARGET) -v

vala: all
	valgrind --leak-check=yes --track-origins=yes -s ./$(TARGET)

DEPENDS= $(OBJS:%.o=%.d)

clean:
	@$(RM) $(TARGET) $(OBJS) $(DEPENDS)

.PHONY: all check clean DEPENDS

-include $(DEPENDS)