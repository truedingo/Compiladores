===== Global Symbol Table =====
putchar	int(int)
getchar	int(void)
readint	int(void)
printint	void(int)
main	int(void)

===== Function readint Symbol Table =====
return	int
read	int
sign	int
c	char

===== Function printint Symbol Table =====
return	void
n	int	param

===== Function main Symbol Table =====
return	int
i	int

Program
..FuncDefinition
....Int
....Id(readint)
....ParamList
......ParamDeclaration
........Void
....FuncBody
......Declaration
........Int
........Id(read)
........IntLit(0) - int
......Declaration
........Int
........Id(sign)
........IntLit(1) - int
......Declaration
........Char
........Id(c)
........Call - int
..........Id(getchar) - int(void)
......If
........Eq - int
..........Id(c) - char
..........ChrLit('-') - int
........Store - int
..........Id(sign) - int
..........Minus - int
............IntLit(1) - int
........Null
......While
........Ne - int
..........Id(c) - char
..........ChrLit('\n') - int
........StatList
..........If
............Ne - int
..............Id(c) - char
..............ChrLit('-') - int
............Store - int
..............Id(read) - int
..............Add - int
................Mul - int
..................Id(read) - int
..................IntLit(10) - int
................Sub - int
..................Id(c) - char
..................ChrLit('0') - int
............Null
..........Store - char
............Id(c) - char
............Call - int
..............Id(getchar) - int(void)
......Return
........Mul - int
..........Id(sign) - int
..........Id(read) - int
..FuncDefinition
....Void
....Id(printint)
....ParamList
......ParamDeclaration
........Int
........Id(n)
....FuncBody
......If
........Lt - int
..........Id(n) - int
..........IntLit(0) - int
........StatList
..........Call - int
............Id(putchar) - int(int)
............ChrLit('-') - int
..........Store - int
............Id(n) - int
............Minus - int
..............Id(n) - int
........Null
......If
........Div - int
..........Id(n) - int
..........IntLit(10) - int
........Call - void
..........Id(printint) - void(int)
..........Div - int
............Id(n) - int
............IntLit(10) - int
........Null
......Call - int
........Id(putchar) - int(int)
........Add - int
..........Mod - int
............Id(n) - int
............IntLit(10) - int
..........ChrLit('0') - int
..FuncDefinition
....Int
....Id(main)
....ParamList
......ParamDeclaration
........Void
....FuncBody
......Declaration
........Int
........Id(i)
........IntLit(1) - int
......While
........Ne - int
..........Id(i) - int
..........IntLit(0) - int
........StatList
..........Store - int
............Id(i) - int
............Call - int
..............Id(readint) - int(void)
..........Call - void
............Id(printint) - void(int)
............Id(i) - int
..........Call - int
............Id(putchar) - int(int)
............ChrLit('\n') - int
