package com.company;

public class Helper
{
    /**
     * Получить случайное число между min и max
     */
    public static int randomBetween(int min, int max)
    {
        return (int) (min + Math.random() * (max - min));
    }

    public static int findFirstKey(boolean[] array, boolean flag)
    {
        for (int i = 0; i < array.length; i++) {
            if (array[i] == flag) {
                return i;
            }
        }

        return -1;
    }
}
