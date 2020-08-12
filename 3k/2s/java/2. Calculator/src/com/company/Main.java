package com.company;

/**
 * Выражение может содержать числа, знаки операций, имена переменных, тригонометрические функции, скобки.
 * В случае, если есть переменные, их значения нужно запросить у пользователя (для каждой из них — по одному разу).
 * Функция записывается в виде, например, sin(x1*yza).
 * Переменные записываются в виде буквенно-цифровых последовательностей, первый символ — буква.
 * В случае, если выражение записано корректно, вычислить значение, в противном случае — вывести сообщение об ошибке.
 */
public class Main
{
    final private static String STRING_FOR_INPUT_EXIT = "exit";
    final private static String STRING_FOR_INPUT_VARIABLE_RESET = "reset";

    public static void main(String[] args)
    {
        input();

        test("5 + 5 + 5", 5 + 5 + 5);

        test("xyz");

        System.out.println("- - Неверный пример");
        test("0 / 0");

        System.out.println("- - Неверный пример");
        test("5 + 100 +");

        test("sin (5)", Math.sin(5));

        test("5 + x + 10");
        test("5 * x * 10");

        test("34 * y * 7");
        test("sin (5 * y)");

        test("tan (x * 5 + y)");
        test("cos (x * y)");

        System.out.println("- - Сбросим все переменные");

        VariableManager.reset();

        System.out.println("- - Пример из условия задачи");
        test("sin (x1 * yza)");
    }

    private static void input()
    {
        String expression = "";

        while(!expression.equals(STRING_FOR_INPUT_EXIT)) {
            System.out.println("Введите выражение. Что бы выйти из режима ввода," +
                    " введите: '" + STRING_FOR_INPUT_EXIT + "'" +
                    "\nчтобы сбросить переменные введите: '" + STRING_FOR_INPUT_VARIABLE_RESET + "'");

            expression = VariableManager.getScanner().nextLine();

            if (!expression.isEmpty() && !expression.equals(STRING_FOR_INPUT_EXIT)) {
                if (expression.equals(STRING_FOR_INPUT_VARIABLE_RESET)) {
                    VariableManager.reset();
                } else {
                    test(expression);
                }
            }
        }
    }

    private static void test(String expression, int realValue)
    {
        try {
            test(expression, String.valueOf(realValue));
        } catch (BringException exception) {
            error(exception);
        }
    }

    private static void test(String expression, double realValue)
    {
        try {
            test(expression, String.valueOf(realValue));
        } catch (BringException exception) {
            error(exception);
        }
    }

    private static void test(String expression, String realValue) throws BringException
    {
        String computedValue = Calculator.getInstance().calc(expression);

        System.out.println("- - Вычисляем значение выражения: " + expression);
        System.out.println("- - Реальное значение выражения: " + realValue);
        System.out.println("- - Вычисленное значение выражения: " + computedValue);
        System.out.println("- - Пройден ли тест: " + ((computedValue.equals(realValue)) ? "да" : "нет"));
        System.out.println("");
    }

    private static void test(String expression)
    {
        System.out.println("- - Вычисляем значение выражения: " + expression);
        bring(expression);
        System.out.println("");
    }

    private static void bring(String expression)
    {
        try {
            System.out.println("- - Вычисленное значение выражения: " + Calculator.getInstance().calc(expression));
        } catch (BringException exception) {
            error(exception);
        }
    }

    private static void error(BringException exception)
    {
        System.out.println("> > " + exception.getMessage());
    }
}
