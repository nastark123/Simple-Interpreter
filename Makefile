all : directories bison flex compile_flex compile_bison InterpreterDriver Values Evaluator Main
	g++ build/*.o -o out/interpreter

directories :
	mkdir -p build/
	mkdir -p out/

flex : flex/interpreter.l
	flex -c++ -o build/interpreter.yy.cpp flex/interpreter.l

bison : bison/interpreter.y
	bison -d bison/interpreter.y -o build/InterpreterParser.cpp

compile_flex : flex
	g++ -c build/interpreter.yy.cpp -I include/ -I build/ -o build/interpreter.yy.o

compile_bison : bison
	g++ -c build/InterpreterParser.cpp -I include/ -I build/ -o build/InterpreterParser.o

InterpreterDriver :
	g++ -c src/InterpreterDriver.cpp -I include/ -I build/ -o build/InterpreterDriver.o

Values : src/values/*.cpp
	g++ -c src/values/ErrorValue.cpp -I include/ -I build/ -o build/ErrorValue.o
	g++ -c src/values/IntegerValue.cpp -I include/ -I build/ -o build/IntegerValue.o

Evaluator : Expressions src/Evaluator.cpp
	g++ -c src/Evaluator.cpp -I include/ -I build/ -o build/Evaluator.o

Expressions : src/expressions/*.cpp
	g++ -c src/expressions/AddExp.cpp -I include/ -I build/ -o build/AddExp.o

Main :
	g++ -c src/Main.cpp -I include/ -I build/ -o build/Main.o

clean :
	rm -rf build/
	rm -rf out/