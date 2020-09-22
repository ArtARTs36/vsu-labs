package com.company;

public class Formalist extends Person
{
    public Formalist(String newName, int newAge, int newSex)
    {
        super(newName, newAge, newSex);
    }

    public String getTypeText()
    {
        return "Формалист" + getTypeTextSuffix();
    }
    
    public void hello(Person twoPerson)
    {
        System.out.print("Здравствуйте, " + twoPerson.getName());
    }
}
