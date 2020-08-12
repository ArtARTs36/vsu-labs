package com.company;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Модель "переменная"
 */
public class Variable
{
    // x1, x2 - буква/индекс
    static public final String REGULAR_PATTERN = "([a-z][0-9])";

    // Название переменной
    private String name;

    // Значение переменной
    private String value;

    public Variable(String newName, String newValue)
    {
        name = newName;
        value = newValue;
    }

    /**
     * Получить название переменной
     */
    public String getName()
    {
        return name;
    }

    /**
     * Получить значение переменной
     */
    public String getValue()
    {
        return value;
    }

     /**
     * Является ли symbol переменной
     */
    static public boolean is(String symbol)
    {
        if (symbol.length() > 2 || Bracket.isBracket(symbol) || Operator.is(symbol) || Number.is(symbol)) {
            return false;
        }

        if (symbol.length() == 1) {
            return true;
        }

        Pattern pattern = Pattern.compile(REGULAR_PATTERN);

        Matcher matcher = pattern.matcher(symbol);

        return matcher.find();
    }
}
