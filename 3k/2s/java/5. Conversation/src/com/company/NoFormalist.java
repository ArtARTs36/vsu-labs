package com.company;

public class NoFormalist extends Person
{
    public NoFormalist(String newName, int newAge, int newSex)
    {
        super(newName, newAge, newSex);
    }

    public String getTypeText()
    {
        return "Неформал" + getTypeTextSuffix();
    }

    public void hello(Person twoPerson)
    {
        System.out.print("Привет, " + twoPerson.getName());
    }
}
