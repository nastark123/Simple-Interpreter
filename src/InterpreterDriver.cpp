#include <InterpreterDriver.h>

InterpreterDriver::InterpreterDriver() : trace_scanning(false), trace_parsing(false) {
    program = Program();
}

InterpreterDriver::~InterpreterDriver() {

}

int InterpreterDriver::parse(const std::string& f) {
    file = f;
    scan_begin();

    yy::InterpreterParser parser(*this);

    parser.set_debug_level(trace_parsing);

    int res = parser.parse();

    scan_end();

    return res;
}

void InterpreterDriver::error(const yy::location& l, const std::string& m) {
    std::cerr << l << ": " << m << std::endl;
}

void InterpreterDriver::error(const std::string& m) {
    std::cerr << m << std::endl;
}

void InterpreterDriver::scan_begin()
{
    lexer.set_debug( trace_scanning );

    // Try to open the file:
    instream.open(file);

    if( instream.good() ) {
        lexer.switch_streams(&instream, 0);
    } else if( file == "-" ) {
        lexer.switch_streams(&std::cin, 0);
    } else {
        error ("Cannot open file '" + file + "'.");
        exit (EXIT_FAILURE);
    }
}

void InterpreterDriver::scan_end ()
{
    instream.close();
}