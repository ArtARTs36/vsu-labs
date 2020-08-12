package com.company;

/**
 * Исключение для отлова ошибок вычислений при случае, когда выражение пустое
 */
public class EmptyExpressionException extends BringException
{
    public String getMessage()
    {
        return prepareMessage("выражение пустое");
    }
}
