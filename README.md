# na2022

编译说明：

EquationSolver类：
定义了所有会用到的函数、导函数于函数f。定义求F小题中的4个变量的求值函数find_ABCE。
bisection类：
以EquationSolver作为基类的子类，其中定义了符号函数sgn，并利用两种算法去验证答案的准确性（已将其中一个算法注释起来）
newton类：
以EquationSolver作为基类的子类，定义了需要用到不同导函数的算法，分别对应解决（solve1,B小题），（solve2，E小题），（solve3，F小题）。
secant类：
以EquationSolver作为基类的子类，按照课本算法执行。
