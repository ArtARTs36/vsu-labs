package com.company;

import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Модель "Выражение"
 */
public class Expression
{
    // Сырая, необработанная строка
    String raw;

    public Expression(String raw)
    {
        this.raw = raw;
    }

    /**
     * Получить подготовленную строку для подсчета
     */
    public String get() throws BringException
    {
        rebuild();

        replaceFunctions();

        return raw;
    }

    /**
     * Пересобираем выражение, чтоб подключить переменные
     */
    public void rebuild() throws BringException
    {
        ArrayList<String> symbols = getSymbols();

        if (symbols.size() == 0) {
            throw new EmptyExpressionException();
        }

        if (Operator.is(symbols.get(symbols.size() - 1))) {
            throw new ExpressionEndOperatorException();
        }

        String symbol = "";
        String lastSymbol = "";
        String newString = "";

        boolean isLastSymbolVariable = false;

        for (String s : symbols) {
            lastSymbol = symbol;
            symbol = s.trim();

            if (symbol.equals(Number.ZERO) && lastSymbol.equals(Operator.DIV)) {
                throw new ZeroDivisionException();
            }

            if (Variable.is(symbol)) {
                symbol = VariableManager.get(symbol).getValue();

                // для того, чтобы можно было писать переменные слитно: xyz
                if (isLastSymbolVariable) {
                    newString = newString.concat("*");
                }

                isLastSymbolVariable = true;
            } else {
                isLastSymbolVariable = false;
            }

            newString = newString.concat(symbol);
        }

        raw = newString;
    }

    /**
     * Замена на javascript функции из пакета Math
     */
    private void replaceFunctions()
    {
        String[] functions = new String[] {
                "cos", "sin", "tan", "lg"
        };

        replaceFunctions(functions);
    }

    /**
     * Замена на javascript функции из пакета Math
     */
    private void replaceFunctions(String[] functions)
    {
        for (String function: functions) {
            raw = raw.replaceAll(function, "Math." + function);
        }
    }

    /**
     * Получить упорядоченный массив символов
     */
    private ArrayList<String> getSymbols()
    {
        String patternString = "([0-9]{5})|([0-9]{4})|([0-9]{3})|([0-9]{2})|([0-9])|"
                + "-|\\*|\\+|/|([a-z][0-9])"
                + "|sin|cos|tan|ln|([a-z])"
                + "|\\(|\\)";

        Pattern pattern = Pattern.compile(patternString);

        ArrayList<String> symbols = new ArrayList<String>();

        Matcher matcher = pattern.matcher(raw);

        while(matcher.find()) {
            symbols.add(matcher.group());
        }

        return symbols;
    }
}
