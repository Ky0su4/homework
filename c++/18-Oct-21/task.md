1. Сиракузская последовательность. Рассмотрим некоторое натуральное число n. Если оно четное, то разделим его на 2, иначе - умножим на 3 и прибавим 1. Будем повторять такие действия, пока не получится 1.
Полученная последовательность называется сиракузская последовательность, а наибольшее из чисел последовательности - её вершиной.
Написать программу, вычисляющую для заданного n последовательность, подсчитывающую число шагов в ней и находящую её вершину.
`func3n1`


2. Перевести заданное пользователем число (целое, положительное) в заданную пользователем систему счисления (от 2  до 16). Для систем счисления более 9 использовать буквы английского алфавита ABCDEF.
`notation`

3. Перевести заданное целое число (<4000) в систему римского счета.
Система римских цифр использует особые знаки для десятичных разрядов I=1, X=10, C=100, M=1000 и их половин V=5, L=50, D=500.
Натуральные числа записываются при помощи повторения этих цифр. При этом, если большая цифра стоит перед меньшей, то они складываются, если же меньшая перед большей, то меньшая вычитается из большей. Последнее правило применяется во избежание четырехкратного повторения одной и той же цифры. Например, XL=50-10=40 вместо XXXX.
Максимально возможное число, записанное по правилам в римской системе счисления 3999. 
`frim`