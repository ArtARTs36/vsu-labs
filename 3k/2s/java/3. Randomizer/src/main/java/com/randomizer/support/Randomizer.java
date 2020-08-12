package com.randomizer.support;

import com.randomizer.beans.AppDetailBean;
import javax.enterprise.context.ApplicationScoped;
import javax.inject.Inject;
import javax.inject.Named;
import java.io.Serializable;

@Named
@ApplicationScoped
public class Randomizer implements Serializable
{
    @Inject
    private AppDetailBean appDetailBean;

    @Inject
    private Dictionary dictionary;

    /**
     * Сгенерировать случайное целое число
     */
    public Integer integer()
    {
        return integer(appDetailBean.getMaxDefaultRandomInteger());
    }

    /**
     * Сгенерировать случайное целое число до max
     */
    public Integer integer(int max)
    {
        double number = 0 + Math.random() * max;

        return (int) number;
    }

    /**
     * Получить случайное имя из словаря
     */
    public String name()
    {
        int index = integer(dictionary.names().length - 1);

        return dictionary.names()[index];
    }

    /**
     * Получить случайную фамилию из словаря
     */
    public String family()
    {
        int index = integer(dictionary.families().length - 1);

        return dictionary.families()[index];
    }
}
