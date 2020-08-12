package com.company;

/**
 * Модель для скобки
 */
public class Bracket
{
    final static public String OPENED = "(";

    final static public String CLOSED = ")";

    /**
     * Является ли symbol скобкой
     */
    public static boolean isBracket(String symbol)
    {
        return symbol.equals(OPENED) || symbol.equals(CLOSED);
    }
}
