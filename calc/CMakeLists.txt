cmake_minimum_required(VERSION 2.5)

# Create target for the parser
ADD_CUSTOM_TARGET(CalcParser echo "Creating parser.c")

SET(CALC_LEX_FILE ${PROJECT_SOURCE_DIR}/base/lexer.l)
SET(CALC_BISON_FILE ${PROJECT_SOURCE_DIR}/base/parser.y)

SET(CALC_LEX_FILE_C ${PROJECT_SOURCE_DIR}/base/lexer.c)
SET(CALC_BISON_FILE_C ${PROJECT_SOURCE_DIR}/base/parser.c)

SET(FLEX_EXECUTABLE /usr/bin/flex)
SET(BISON_EXECUTABLE /usr/local/Cellar/bison/3.0.4/bin/bison)

# Create custom command for flex/lex (note the outputs)
 ADD_CUSTOM_COMMAND(
   COMMAND ${FLEX_EXECUTABLE} -o ${CALC_LEX_FILE_C} ${CALC_LEX_FILE}
   TARGET CalcParser)

# Create custom command for bison/yacc (note the DEPENDS)
 ADD_CUSTOM_COMMAND(
   COMMAND ${BISON_EXECUTABLE} -o ${CALC_BISON_FILE_C} -y ${CALC_BISON_FILE}
   TARGET CalcParser
   DEPENDS CALC_LEX_FILE_C)

# Add parser.c to the list of sources
 SET(CALC_SRCS ${CALC_SRCS} ${CALC_BISON_FILE_C})

# Since parser.c does not exists yet when cmake is run, mark
# it as generated
 SET_SOURCE_FILES_PROPERTIES(${CALC_BISON_FILE_C} GENERATED)

# Include binary directory to include lexer.c in parser.c
 INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/base)