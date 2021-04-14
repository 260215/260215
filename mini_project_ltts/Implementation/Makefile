#Name of the project
PROJECT_NAME = ATM
TEST_PROJECT_NAME = Test_$(PROJECT_NAME)

#Output directory
BUILD = build

#All source code files
SRC = mini_project_main.c\
src/atm_operations.c

#All test source files
TEST_SRC = src/atm_operations.c\
test/test_atm_operations.c\
unity/unity.c\


TEST_OUTPUT = $(BUILD)/Test_$(PROJECT_NAME).out

#All include folders with header files
INC = -Iinclude\
-Iunity\

#To check whether the os is Windows or Linux
#ifdef os
#	RM = del/q
#	FixPath = $(subst /,\,$1)
#	EXEC = exe
#else
#	ifeq($(shell uname), Linux)
#		RM = rm -rf
#		FixPath = $1
#		EXEC = out
#	endif
#endif


#Library Includes
#INCLUDE_LIBS = 
INCLUDE_LIBS = -Icunit

#Project output name
PROJECT_OUTPUT = $(BUILD)/$(PROJECT_NAME).out

#Document files
DOCUMENTATION_OUTPUT = documentation/Doxyfile

#Default target build
$(PROJECT_NAME):all

#Run the target even if the matching name exists
.PHONY: run clean test doc all

all: $(SRC) $(BUILD)
		gcc $(SRC) $(INC) -o $(PROJECT_OUTPUT).out


#Document the code using doxygen
doc:
		make -C ./documentation


#Build and run the unit tests
#test: $(BUILD)
#		gcc $(TEST_SRC) $(INC) -o $(TEST_OUTPUT) $(INCLUDE_LIBS) 
#		./$(TEST_OUTPUT)


#Remove all the built files, invoke by `make clean`
clean:
		rm -rf $(BUILD) $(DOCUMENTATION_OUTPUT)


#Create new folder if not present
$(BUILD):
			mkdir build