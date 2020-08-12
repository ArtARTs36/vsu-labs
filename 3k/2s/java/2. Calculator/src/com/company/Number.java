package com.company;

/**
 * Модель для чисел
 */
public class Number
{
    static public final String ZERO = "0";

    /**
     * Является ли symbol числом
     */
    public static boolean is(String symbol)
    {
        try {
            // если получилось привести к числовому типу, все ок
            Integer.parseInt(symbol);

            return true;
        } catch (NumberFormatException exception) {
            return false;
        }
    }
}
