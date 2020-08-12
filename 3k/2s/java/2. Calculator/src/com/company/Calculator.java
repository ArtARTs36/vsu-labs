package com.company;

import javax.script.ScriptEngine;
import javax.script.ScriptEngineManager;
import javax.script.ScriptException;
import java.util.ArrayList;

/**
 * Калькулятор
 */
public class Calculator
{
    // храним экземпляр движка js
    private ScriptEngine engine;

    private static Calculator instance = null;

    private Calculator()
    {
        this.engine = new ScriptEngineManager().getEngineByName("JavaScript");
    }

    public static Calculator getInstance()
    {
        if (instance == null) {
            instance = new Calculator();
        }

        return instance;
    }

    /**
     * Вычислить введенное значение
     */
    public String calc(Expression expression) throws BringException
    {
        // собрали переменные из веденных строк
        ArrayList<Variable> variables = VariableManager.all();

        String preparedExpression = expression.get();

        // отдали движку
        for (Variable var: variables) {
            engine.put(var.getName(), Double.parseDouble(var.getValue()));
        }

        try {
            String result = engine.eval(preparedExpression).toString();

            if (result.equals("NaN")) {
                throw new BringException();
            }

            return result;
        } catch (ScriptException exception) {
            throw new BringException();
        }
    }

    /**
     * Вычислить введенное значение
     */
    public String calc(String expression) throws BringException
    {
        return calc(new Expression(expression));
    }
}