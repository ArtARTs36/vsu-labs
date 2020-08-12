package com.company;

/**
 * Исключение для отлова ошибок вычислений при случае, когда выражение заканчивается оператором
 */
public class ExpressionEndOperatorException extends BringException
{
    public String getMessage()
    {
        return prepareMessage("выражение заканчивается оператором");
    }
}
