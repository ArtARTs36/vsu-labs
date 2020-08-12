package com.company;

/**
 * Исключение для отлова ошибок при вводе неккоректного значения переменной
 */
public class VariableInCorrectException extends BringException
{
    private String name;

    public VariableInCorrectException(String name)
    {
        this.name = name;
    }

    public String getMessage()
    {
        return prepareMessage("для переменной '" + name + "' введено неверное значение");
    }
}
