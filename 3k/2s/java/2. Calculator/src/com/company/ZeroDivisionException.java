package com.company;

/**
 * Исключение для отлова ошибок вычислений при делении на ноль
 */
public class ZeroDivisionException extends BringException
{
    public String getMessage()
    {
        return prepareMessage("на ноль делить нельзя");
    }
}
