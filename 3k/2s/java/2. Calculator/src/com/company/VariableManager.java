package com.company;

import java.util.ArrayList;
import java.util.Scanner;

public class VariableManager
{
    private static ArrayList<Variable> variables = new ArrayList<Variable>();

    private static Scanner scanner = null;

    /**
     * Получить переменную
     */
    public static Variable get(String name) throws BringException
    {
        Variable variable = null;

        // ищем в массиве
        if (!variables.isEmpty()) {
            for (Variable var : variables) {
                if (var.getName().equals(name)) {
                    variable = var;
                }
            }
        }

        // не нашли, запросили у пользователя
        if (variable == null) {
            variable = request(name);

            variables.add(variable);
        }

        return variable;
    }

    /**
     * Сбросить все переменные
     */
    public static void reset()
    {
        variables.clear();
    }

    /**
     * Запросить переменную у пользователя
     */
    private static Variable request(String name) throws BringException
    {
        System.out.println("Введите значение переменной " + name + ":");

        String value = getScanner().next();

        if (!Number.is(value)) {
            throw new VariableInCorrectException(name);
        }

        return new Variable(name, value);
    }

    public static Scanner getScanner()
    {
        if (scanner == null) {
            scanner = new Scanner(System.in);
        }

        return scanner;
    }

    /**
     * Получить все переменные
     */
    public static ArrayList<Variable> all()
    {
        return variables;
    }
}
