package com.company;

/**
 * Модель "Оператор"
 */
public class Operator
{
    // Сложение
    static public final String PLUS = "+";

    // Вычитание
    static public final String MINUS = "-";

    // Умножение
    static public final String MULTI = "*";

    // Деление
    static public final String DIV = "/";

    /**
     * Является ли symbol оператором
     */
    static public boolean is(String symbol)
    {
        return symbol.length() == 1 && (
                symbol.equals(PLUS) || symbol.equals(MINUS) || symbol.equals(MULTI) || symbol.equals(DIV)
        );
    }
}
