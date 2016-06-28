cmake_minimum_required(VERSION 2.5)

# Create target for the parser
ADD_CUSTOM_TARGET(CalcParser echo "Creating parser.c")

SET(CALC_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

SET(CALC_LEX_FILE ${CALC_SOURCE_DIR}/bison/lexer.l)
SET(CALC_BISON_FILE ${CALC_SOURCE_DIR}/bison/parser.y)

SET(CALC_LEX_FILE_C ${CALC_SOURCE_DIR}/lexer.cpp)
SET(CALC_BISON_FILE_C ${CALC_SOURCE_DIR}/parser.cpp)

SET(FLEX_EXECUTABLE /usr/bin/flex)
SET(BISON_EXECUTABLE /usr/local/Cellar/bison/3.0.4/bin/bison)

include_directories(${CALC_SOURCE_DIR})

# Create custom command for flex/lex (note the outputs)
ADD_CUSTOM_COMMAND(
COMMAND ${FLEX_EXECUTABLE} -o ${CALC_LEX_FILE_C} ${CALC_LEX_FILE}
TARGET CalcParser)

# Create custom command for bison/yacc (note the DEPENDS)
ADD_CUSTOM_COMMAND(
COMMAND ${BISON_EXECUTABLE} -o ${CALC_BISON_FILE_C} -y ${CALC_BISON_FILE} -vd
TARGET CalcParser
DEPENDS CALC_LEX_FILE_C)

# Since parser.c does not exists yet when cmake is run, mark
# it as generated
SET_SOURCE_FILES_PROPERTIES(${CALC_BISON_FILE_C} GENERATED)

# Include binary directory to include lexer.c in parser.c

link_libraries(Calc l)
add_executable(Calc ${CALC_BISON_FILE_C} ${CALC_LEX_FILE_C})
ADD_DEPENDENCIES(Calc CalcParser)

install(TARGETS Calc DESTINATION ${PROJECT_SOURCE_DIR}/bin)