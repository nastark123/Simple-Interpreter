all : directories bison flex compile_flex compile_bison InterpreterDriver Values Environment Evaluator Program Main
	g++ build/*.o -o out/interpreter

directories :
	mkdir -p build/
	mkdir -p out/

flex : flex/interpreter.l
	flex -c++ -o build/interpreter.yy.cpp flex/interpreter.l

bison : bison/interpreter.y
	bison -d bison/interpreter.y -o build/InterpreterParser.cpp

compile_flex : flex bison
	g++ -c build/interpreter.yy.cpp -I include/ -I build/ -o build/interpreter.yy.o

compile_bison : flex bison
	g++ -c build/InterpreterParser.cpp -I include/ -I build/ -o build/InterpreterParser.o

InterpreterDriver :
	g++ -c src/InterpreterDriver.cpp -I include/ -I build/ -o build/InterpreterDriver.o

Values : src/values/*.cpp
	g++ -c src/values/ErrorValue.cpp -I include/ -I build/ -o build/ErrorValue.o
	g++ -c src/values/IntegerValue.cpp -I include/ -I build/ -o build/IntegerValue.o
	g++ -c src/values/BooleanValue.cpp -I include/ -I build/ -o build/BooleanValue.o

Environment : src/Environment.cpp
	g++ -c src/Environment.cpp -I include/ -I build/ -o build/Environment.o

Evaluator : Statements Expressions src/Evaluator.cpp
	g++ -c src/Evaluator.cpp -I include/ -I build/ -o build/Evaluator.o

Expressions : src/expressions/*.cpp
	g++ -c src/expressions/AddExp.cpp -I include/ -I build/ -o build/AddExp.o
	g++ -c src/expressions/SubExp.cpp -I include/ -I build/ -o build/SubExp.o
	g++ -c src/expressions/MultExp.cpp -I include/ -I build/ -o build/MultExp.o
	g++ -c src/expressions/DivExp.cpp -I include/ -I build/ -o build/DivExp.o
	g++ -c src/expressions/EqualExp.cpp -I include/ -I build/ -o build/EqualExp.o
	g++ -c src/expressions/ConstExp.cpp -I include/ -I build/ -o build/ConstExp.o
	g++ -c src/expressions/VarExp.cpp -I include/ -I build/ -o build/VarExp.o

Statements : src/statements/*.cpp
	g++ -c src/statements/Statements.cpp -I include/ -I build/ -o build/Statements.o
	g++ -c src/statements/AssignStatement.cpp -I include/ -I build/ -o build/AssignStatement.o
	g++ -c src/statements/PrintStatement.cpp -I include/ -I build/ -o build/PrintStatement.o
	g++ -c src/statements/IfStatement.cpp -I include/ -I build/ -o build/IfStatement.o
	g++ -c src/statements/WhileStatement.cpp -I include/ -I build/ -o build/WhileStatement.o

Program : src/Program.cpp
	g++ -c src/Program.cpp -I include/ -I build/ -o build/Program.o

Main :
	g++ -c src/Main.cpp -I include/ -I build/ -o build/Main.o

clean :
	rm -rf build/
	rm -rf out/