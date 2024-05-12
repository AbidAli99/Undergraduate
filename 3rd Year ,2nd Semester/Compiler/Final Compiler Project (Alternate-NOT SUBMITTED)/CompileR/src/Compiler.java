/*
    Compiler Construction
    For C0 syntax language
    Developer:ABID ALI

 */


import java.io.*;
//Java.IO is standard for Java Input/Output. So in essence we are importing extra Input/Output functionality.
import java.util.*;


public class Compiler
{
    public static void main(String[] args) throws IOException
    {
        System.out.println("Directory: "+System.getProperty("user.dir"));
        // Input is a .c-
        String inFileName = "D:\\3rd Year ,2nd Semester\\Final Compiler ABID\\ABID Compiler\\CompileR\\TestFiles_Output\\TestFile.c";
        //The output is a .a file, which can be used for our assembler
        String outFileName = inFileName + ".assembly";
        // File reading
        Scanner inFile = new Scanner(new File(inFileName));
        // File output
        PrintWriter outFile = new PrintWriter(outFileName);
        // Symbol table
        SymbolTable st = new SymbolTable();
        // Lexical analyzer
        TokenMgr tm =  new TokenMgr(inFile);
        // Parser analyzer
        Parser parser = new Parser(st, tm, outFile);

        try
        {
            parser.parse();
        }
        // Compilation error
        catch (RuntimeException e)
        {
            System.err.println(e.getMessage());
            outFile.println(e.getMessage());
            outFile.close();
            System.exit(1);
        }
        outFile.close();
    }
}


/**
     This interface defines all kinds of identifier types that we may use.
     Subsequent lexical analyzer and parser are the implementation of this interface
 **/
interface Constants
{
    // integers that identify token kinds
    int EOF = 0;
    int PRINTLN = 1;
    int UNSIGNED = 2;
    int ID = 3;
    int ASSIGN = 4;
    int SEMICOLON = 5;
    int LEFTPAREN = 6;
    int RIGHTPAREN = 7;
    int PLUS = 8;
    int MINUS = 9;
    int TIMES = 10;
    int ERROR = 11;
    int DIVIDE = 12;
    int LEFTBRACE = 13;
    int RIGHTBRACE = 14;
    int STRING = 15;
    //switch expression
    int WHILE = 16;
    int IF = 17;
    int ELSE = 18;
    //boolean expression
    int EQUAL = 19;
    int GREATER_THAN = 20;
    int SMALLER_THAN = 21;
    int GREATER_EQUAL_THAN = 22;
    int SMALLER_EQUAL_THAN = 23;
    int INT = 24;   //Used as variable type
    int RETURN = 25;
    int DEF = 26;
    int VOID = 27;
    int CAL = 28;
    int AND = 29;
    int OR = 30;
    int COMMA = 31;
    int END = 32;
    int SWITCH = 33;
    int CASE = 34;
    int DEFAULT = 35;
    int COLON = 36;
    int GOTO = 37;
    int BREAK = 38;
    int CONTINUE = 39;
    int DEST = 40;
    int ARRAY = 41; //Used as variable type
    int LEFTBRACKET = 42;
    int RIGHTBRACKET = 43;

    int CONST = 44; //Used as variable type
    int ARGS = 45;  //Used as variable type

    int EXIT = 46; //Used as the force quit of the hole program
    int ASSERT = 47;

    // tokenImage provides string for each token kind
    String[] tokenImage =
            {
                    "<EOF>",
                    "\"println\"",
                    "<UNSIGNED>",
                    "<ID>",
                    "\"=\"",
                    "\";\"",
                    "\"(\"",
                    "\")\"",
                    "\"+\"",
                    "\"-\"",
                    "\"*\"",
                    "<ERROR>",
                    "\"/\"",
                    "\"{\"",
                    "\"}\"",
                    "<STRING>",
                    "\"while\"",
                    "\"if\"",
                    "\"else\"",
                    "\"==\"",
                    "\">\"",
                    "\"<\"",
                    "\">=\"",
                    "\"<=\"",
                    "int",
                    "return",
                    "def",
                    "void",
                    "cal",
                    "and",
                    "or",
                    ",",
                    "~",//FORCE END
                    "switch",
                    "case",
                    "default",
                    ":",
                    "goto",
                    "break",
                    "continue",
                    "dest",
                    "array",
                    "[",
                    "]"
            };
}



