package com.company;

public class CollectionCreator {

    public static Collection integer()
    {
        int count = 20;

        int[] items = new int[count];
        for (int i = 0; i < count; i++) {
            items[i] = randomNumber();
        }

        return new Collection(items);
    }

    public static int randomNumber()
    {
        return (int) (5 + Math.random() * 20);
    }
}
