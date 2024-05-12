/*
    Compiler Construction
    For C0 syntax language
    Developer:ABID ALI

 */

import java.util.Scanner;

/**For a token, we keep its starting and ending positions, and save its type and
 * image (that is, what this thing looks like in the. C -- file) as well as the reference of the next token
 * */
public class Token implements java.io.Serializable {
    private static final long serialVersionUID = 1L;
    public int kind;
    //Token start line
    public int beginLine;
    //The column at the beginning of the token
    public int beginColumn;
    //token End line
    public int endLine;
    //token End column
    public int endColumn;
    //String image of token
    public String image;
    //The value of token and the definition of variable
    //The reference to the next token is equivalent to the next pointer in C language
    public Token next;

    //Constructors
    public Token() {}
    public Token(int kind)
    {
        this(kind, null);
    }
    public Token(int kind, String image)
    {
        this.kind = kind;
        this.image = image;
    }
    public String toString()
    {
        return image;
    }
}