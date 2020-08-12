package com.randomizer.support;

import javax.enterprise.context.ApplicationScoped;
import javax.inject.Named;

@Named
@ApplicationScoped
public class Dictionary
{
    private String[] names = new String[] {
            "Саша", "Маша", "Юля", "Петя", "Артем", "Карина", "Лена", "Вася", "Катя"
    };

    private String[] families = new String[] {
            "Иванов", "Смирнов", "Соболев", "Петров", "Александров", "Посиделкин", "Курочкин", "Третьяков"
    };

    public String[] names()
    {
        return names;
    }

    public String[] families()
    {
        return families;
    }
}
