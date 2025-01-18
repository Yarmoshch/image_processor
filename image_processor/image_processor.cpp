#include "Parsing.h"

int main(int argc, char** argv) {
    Parser parse(argc, argv);
    parse.Apply();
}