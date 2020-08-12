package com.company;

/**
 * Исключение для отлова ошибок вычислений
 */
public class BringException extends Exception
{
    final protected String PRE_MESSAGE = "Неверно составлено выражение";

    public String getMessage()
    {
        return PRE_MESSAGE;
    }

    protected String prepareMessage(String message)
    {
        return PRE_MESSAGE + ": " + message;
    }
}
