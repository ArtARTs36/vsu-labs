package com.company;

public class Realist extends Person
{
    Realist(String newName, int newAge, int newSex)
    {
        super(newName, newAge, newSex);
    }

    public String getTypeText()
    {
        return "Реалист" + getTypeTextSuffix();
    }

    public void hello(Person twoPerson) {
        if (Math.abs(twoPerson.getAge() - getAge()) <= 5) {
            System.out.print("Привет, " + twoPerson.getName());
        } else {
            System.out.print("Здравствуй, " + twoPerson.getName());
        }
    }
}
