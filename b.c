===== Global Symbol Table =====
putchar	int(int)
getchar	int(void)
x	int(char)
lmao	double(char,int,double,int)
main	int(char,int,int)
expressions	int(void)
statements	int(void)
oi	int(int,int)
huehue	int(int)
meta3	int(int,char,double,short)
f2	int(char,char)
f6	int(char,int)
__	void(int,double,double,char,char,double,int)
f3	int(char)
f4	int(char)
recursiva	void(int)
f	int(char)
f1	int(char,int)
b	int(char)
f5	int(int,int)
f7	int(char,int)
k	int
v	int
f8	int(char)
f9	int(int,double)
teste	int(void)
main1	void(void)
rekt	void(void)
help	int(int,int)
help1	void(int,char)
help2	int(int,int)
f10	void(void)
f12	void(short)
c	int
e	int
g	int(void)

===== Function x Symbol Table =====
return	int
e	char	param
a	char
b	int
c	int
d	int

===== Function main Symbol Table =====
return	int
x	char	param
y	int	param
z	int	param
a	int
b	int
c	int
d	int
e	int

===== Function expressions Symbol Table =====
return	int
i	int
a	int
b	int
c	int
d	int
variable	int
x	double

===== Function statements Symbol Table =====
return	int
x	int

===== Function oi Symbol Table =====
return	int
tudo	int	param
bem	int	param
a	char
b	char
c	char
d	double
e	double
f	double

===== Function huehue Symbol Table =====
return	int
x	int	param

===== Function meta3 Symbol Table =====
return	int
xd	int	param
lmao	char	param
ups	double	param
huehue	short	param
v	double

===== Function __ Symbol Table =====
return	void
e	int	param
z	double	param
a	double	param
b	char	param
c	char	param
d	double	param
t	int	param
y	int
h	int

===== Function f3 Symbol Table =====
return	int
x	char	param

===== Function f4 Symbol Table =====
return	int
x	char	param

===== Function recursiva Symbol Table =====
return	void
a	int	param

===== Function f1 Symbol Table =====
return	int
x	char	param
y	int	param

===== Function b Symbol Table =====
return	int
c	char	param
x	int

===== Function f5 Symbol Table =====
return	int
a	int	param
b	int	param
f	double
n	int
c	int

===== Function f7 Symbol Table =====
return	int
a	char	param
b	int	param

===== Function f8 Symbol Table =====
return	int
y	char	param
x	char

===== Function teste Symbol Table =====
return	int
b	int

===== Function main1 Symbol Table =====
return	void
c	int
m	int

===== Function rekt Symbol Table =====
return	void

===== Function help1 Symbol Table =====
return	void
x	int	param
y	char	param
h	char

===== Function help2 Symbol Table =====
return	int
x	int	param
y	int	param
wgdsg	int
gsfrgs	char

===== Function f10 Symbol Table =====
return	void

===== Function f12 Symbol Table =====
return	void
a	short	param
b	double

===== Function g Symbol Table =====
return	int

Program
..FuncDefinition
....Int
....Id(x)
....ParamList
......ParamDeclaration
........Char
........Id(e)
....FuncBody
......Declaration
........Char
........Id(a)
......Declaration
........Int
........Id(b)
......Declaration
........Int
........Id(c)
......Declaration
........Int
........Id(d)
........IntLit(2) - int
......Store - char
........Id(a) - char
........ChrLit('a') - int
..FuncDeclaration
....Double
....Id(lmao)
....ParamList
......ParamDeclaration
........Char
........Id(in)
......ParamDeclaration
........Int
......ParamDeclaration
........Double
......ParamDeclaration
........Int
..FuncDefinition
....Int
....Id(main)
....ParamList
......ParamDeclaration
........Char
........Id(x)
......ParamDeclaration
........Int
........Id(y)
......ParamDeclaration
........Int
........Id(z)
....FuncBody
......Declaration
........Int
........Id(a)
......Declaration
........Int
........Id(b)
......Declaration
........Int
........Id(c)
......Declaration
........Int
........Id(d)
......Declaration
........Int
........Id(e)
......If
........Or - int
..........And - int
............Gt - int
..............Id(x) - int
..............Id(y) - int
............Gt - int
..............Id(z) - int
..............Id(y) - int
..........Ne - int
............Id(z) - int
............Id(x) - int
........Null
........Return
..........IntLit(0) - int
..FuncDefinition
....Int
....Id(expressions)
....ParamList
......ParamDeclaration
........Void
....FuncBody
......Declaration
........Int
........Id(i)
........IntLit(2) - int
......Declaration
........Int
........Id(a)
........IntLit(3) - int
......Declaration
........Int
........Id(b)
........IntLit(4) - int
......Declaration
........Int
........Id(c)
......Declaration
........Int
........Id(d)
......Declaration
........Int
........Id(variable)
........IntLit(1) - int
......Declaration
........Double
........Id(x)
......Store - int
........Id(variable) - int
........Plus - int
..........Id(variable) - int
......Store - int
........Id(variable) - int
........Add - int
..........Id(variable) - int
..........IntLit(2) - int
......Store - int
........Id(variable) - int
........Sub - int
..........Id(variable) - int
..........IntLit(2) - int
......Eq - int
........Id(variable) - int
........IntLit(2) - int
......Gt - int
........Id(variable) - int
........IntLit(2) - int
......Lt - int
........Id(variable) - int
........IntLit(2) - int
......Ge - int
........Id(variable) - int
........IntLit(2) - int
......Le - int
........Id(variable) - int
........IntLit(2) - int
......BitWiseOr - int
........Id(variable) - int
........IntLit(2) - int
......BitWiseAnd - int
........Id(variable) - int
........IntLit(2) - int
......Ne - int
........Id(variable) - int
........IntLit(2) - int
......And - int
........Id(variable) - int
........IntLit(2) - int
......Or - int
........Id(variable) - int
........IntLit(2) - int
......BitWiseXor - int
........Id(variable) - int
........IntLit(2) - int
......Store - int
........Id(variable) - int
........Mod - int
..........Id(variable) - int
..........IntLit(2) - int
......Store - int
........Id(variable) - int
........Mul - int
..........Id(variable) - int
..........IntLit(2) - int
......Store - int
........Id(variable) - int
........Div - int
..........Id(variable) - int
..........IntLit(2) - int
......Not - int
........Id(variable) - int
......Plus - int
........Id(variable) - int
......Minus - int
........Id(variable) - int
......Store - int
........Id(variable) - int
........IntLit(2) - int
......Store - int
........Id(i) - int
........Add - int
..........BitWiseXor - int
............Not - int
..............Id(i) - int
............IntLit(1) - int
..........BitWiseOr - int
............Add - int
..............Id(a) - int
..............Id(b) - int
............Mod - int
..............Id(c) - int
..............Id(d) - int
......Store - int
........Id(i) - int
........And - int
..........Add - int
............BitWiseXor - int
..............Id(a) - int
..............IntLit(1) - int
............Not - int
..............Or - int
................Mul - int
..................Id(a) - int
..................Id(b) - int
................Mod - int
..................Id(a) - int
..................Id(c) - int
..........Id(a) - int
......Store - int
........Id(a) - int
........Id(b) - int
......Call - int
........Id(putchar) - int(int)
........Id(x) - double
..FuncDefinition
....Int
....Id(statements)
....ParamList
......ParamDeclaration
........Void
....FuncBody
......Declaration
........Int
........Id(x)
........IntLit(1) - int
......While
........Comma - int
..........IntLit(1) - int
..........IntLit(2) - int
........If
..........Id(x) - int
..........If
............Id(x) - int
............StatList
..............Call - int
................Id(putchar) - int(int)
................Id(x) - int
..............Return
................IntLit(1) - int
............If
..............IntLit(1) - int
..............Call - int
................Id(putchar) - int(int)
................Id(x) - int
..............Call - int
................Id(putchar) - int(int)
................Id(x) - int
..........While
............IntLit(1) - int
............Return
..............IntLit(0) - int
......If
........And - int
..........Eq - int
............Id(x) - int
............IntLit(1) - int
..........Ne - int
............Id(x) - int
............IntLit(1) - int
........Return
..........IntLit(1) - int
........Null
......If
........Not - int
..........Id(x) - int
........Call - int
..........Id(putchar) - int(int)
..........ChrLit('o') - int
........Null
..FuncDefinition
....Int
....Id(oi)
....ParamList
......ParamDeclaration
........Int
........Id(tudo)
......ParamDeclaration
........Int
........Id(bem)
....FuncBody
......Declaration
........Char
........Id(a)
......Declaration
........Char
........Id(b)
......Declaration
........Char
........Id(c)
........ChrLit('d') - int
......Declaration
........Double
........Id(d)
......Declaration
........Double
........Id(e)
......Declaration
........Double
........Id(f)
......Store - double
........Id(e) - double
........IntLit(4) - int
......Store - double
........Id(f) - double
........Add - double
..........Id(d) - double
..........Id(e) - double
..FuncDefinition
....Int
....Id(huehue)
....ParamList
......ParamDeclaration
........Int
........Id(x)
....FuncBody
......Return
........IntLit(3) - int
..FuncDefinition
....Int
....Id(meta3)
....ParamList
......ParamDeclaration
........Int
........Id(xd)
......ParamDeclaration
........Char
........Id(lmao)
......ParamDeclaration
........Double
........Id(ups)
......ParamDeclaration
........Short
........Id(huehue)
....FuncBody
......Declaration
........Double
........Id(v)
........RealLit(2.4) - double
......Eq - int
........Id(xd) - int
........Id(huehue) - int
......Gt - int
........Id(xd) - int
........Id(huehue) - int
......Lt - int
........Id(xd) - int
........Id(huehue) - int
......Ge - int
........Id(xd) - int
........Id(huehue) - int
......Le - int
........Id(xd) - int
........Id(huehue) - int
......BitWiseOr - int
........Id(xd) - int
........Id(huehue) - int
......BitWiseAnd - int
........Id(xd) - int
........Id(huehue) - int
......Ne - int
........Id(xd) - int
........Id(huehue) - int
......And - int
........Id(xd) - int
........Id(huehue) - int
......Or - int
........Id(xd) - int
........Id(huehue) - int
......BitWiseXor - int
........Id(xd) - int
........Id(huehue) - int
......Store - int
........Id(xd) - int
........Mod - int
..........Id(xd) - int
..........Id(huehue) - int
......Store - int
........Id(xd) - int
........Mul - int
..........Id(xd) - int
..........Id(huehue) - int
......Store - int
........Id(xd) - int
........Div - int
..........Id(xd) - int
..........Id(huehue) - int
......Not - int
........Id(xd) - int
......Plus - int
........Id(xd) - int
......Minus - int
........Id(xd) - int
..FuncDeclaration
....Int
....Id(f2)
....ParamList
......ParamDeclaration
........Char
......ParamDeclaration
........Char
..FuncDeclaration
....Int
....Id(f6)
....ParamList
......ParamDeclaration
........Char
......ParamDeclaration
........Int
..FuncDeclaration
....Void
....Id(__)
....ParamList
......ParamDeclaration
........Int
......ParamDeclaration
........Double
......ParamDeclaration
........Double
......ParamDeclaration
........Char
......ParamDeclaration
........Char
......ParamDeclaration
........Double
......ParamDeclaration
........Int
........Id(e)
..FuncDefinition
....Void
....Id(__)
....ParamList
......ParamDeclaration
........Int
........Id(e)
......ParamDeclaration
........Double
........Id(z)
......ParamDeclaration
........Double
........Id(a)
......ParamDeclaration
........Char
........Id(b)
......ParamDeclaration
........Char
........Id(c)
......ParamDeclaration
........Double
........Id(d)
......ParamDeclaration
........Int
........Id(t)
....FuncBody
......Declaration
........Int
........Id(a)
......Declaration
........Double
........Id(e)
......Declaration
........Short
........Id(b)
......Declaration
........Int
........Id(y)
......Declaration
........Int
........Id(h)
........Call - int
..........Id(f2) - int(char,char)
..........ChrLit('a') - int
..........ChrLit('c') - int
......Return
........IntLit(2) - int
..FuncDeclaration
....Int
....Id(f3)
....ParamList
......ParamDeclaration
........Char
........Id(x)
..FuncDefinition
....Int
....Id(f3)
....ParamList
......ParamDeclaration
........Char
........Id(x)
....FuncBody
..FuncDefinition
....Int
....Id(f4)
....ParamList
......ParamDeclaration
........Char
........Id(x)
....FuncBody
..FuncDefinition
....Void
....Id(recursiva)
....ParamList
......ParamDeclaration
........Int
........Id(a)
....FuncBody
......Call - void
........Id(recursiva) - void(int)
........Id(a) - int
..FuncDeclaration
....Int
....Id(f)
....ParamList
......ParamDeclaration
........Char
........Id(x)
..FuncDefinition
....Int
....Id(f1)
....ParamList
......ParamDeclaration
........Char
........Id(x)
......ParamDeclaration
........Int
........Id(y)
....FuncBody
......Declaration
........Char
........Id(x)
........RealLit(2.3) - double
..FuncDeclaration
....Int
....Id(b)
....ParamList
......ParamDeclaration
........Char
..FuncDefinition
....Int
....Id(b)
....ParamList
......ParamDeclaration
........Char
........Id(c)
....FuncBody
......Declaration
........Int
........Id(x)
........ChrLit('a') - int
..FuncDeclaration
....Int
....Id(f5)
....ParamList
......ParamDeclaration
........Int
........Id(a)
......ParamDeclaration
........Int
........Id(b)
..FuncDefinition
....Int
....Id(f5)
....ParamList
......ParamDeclaration
........Int
........Id(a)
......ParamDeclaration
........Int
........Id(b)
....FuncBody
......Declaration
........Double
........Id(f)
......Declaration
........Int
........Id(n)
......Declaration
........Int
........Id(n)
......Declaration
........Int
........Id(b)
......Declaration
........Int
........Id(c)
......Declaration
........Int
........Id(b)
..FuncDefinition
....Int
....Id(f7)
....ParamList
......ParamDeclaration
........Char
........Id(a)
......ParamDeclaration
........Int
........Id(b)
....FuncBody
..Declaration
....Int
....Id(k)
..Declaration
....Int
....Id(v)
..FuncDefinition
....Int
....Id(f8)
....ParamList
......ParamDeclaration
........Char
........Id(y)
....FuncBody
......Declaration
........Char
........Id(x)
........Id(y) - char
..FuncDeclaration
....Int
....Id(f9)
....ParamList
......ParamDeclaration
........Int
........Id(x)
......ParamDeclaration
........Double
........Id(y)
..FuncDefinition
....Int
....Id(teste)
....ParamList
......ParamDeclaration
........Void
....FuncBody
......Declaration
........Int
........Id(b)
........Id(b) - int
..FuncDefinition
....Void
....Id(main1)
....ParamList
......ParamDeclaration
........Void
....FuncBody
......Declaration
........Int
........Id(c)
......Declaration
........Int
........Id(c)
......Declaration
........Int
........Id(m)
..FuncDefinition
....Void
....Id(rekt)
....ParamList
......ParamDeclaration
........Void
....FuncBody
..FuncDeclaration
....Int
....Id(help)
....ParamList
......ParamDeclaration
........Int
........Id(x)
......ParamDeclaration
........Int
........Id(y)
..FuncDeclaration
....Int
....Id(help)
....ParamList
......ParamDeclaration
........Int
........Id(t)
......ParamDeclaration
........Int
........Id(h)
..FuncDefinition
....Void
....Id(help1)
....ParamList
......ParamDeclaration
........Int
........Id(x)
......ParamDeclaration
........Char
........Id(y)
....FuncBody
......Declaration
........Char
........Id(h)
..FuncDefinition
....Int
....Id(help2)
....ParamList
......ParamDeclaration
........Int
........Id(x)
......ParamDeclaration
........Int
........Id(y)
....FuncBody
......Declaration
........Int
........Id(wgdsg)
......Declaration
........Char
........Id(gsfrgs)
..FuncDeclaration
....Void
....Id(f10)
....ParamList
......ParamDeclaration
........Void
..FuncDefinition
....Void
....Id(f10)
....ParamList
......ParamDeclaration
........Void
....FuncBody
......Comma - int
........Id(a)
........Id(b) - int
..FuncDefinition
....Void
....Id(f12)
....ParamList
......ParamDeclaration
........Short
........Id(a)
....FuncBody
......Declaration
........Double
........Id(b)
........RealLit(2.3) - double
..Declaration
....Int
....Id(c)
..Declaration
....Int
....Id(e)
..FuncDefinition
....Int
....Id(g)
....ParamList
......ParamDeclaration
........Void
....FuncBody
