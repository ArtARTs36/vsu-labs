package com.company;

public abstract class Person implements PersonInterface
{
    // Мужской пол
    public static final int SEX_MALE = 1;

    // Женский пол
    public static final int SEX_FEMALE = 2;

    /** Имя **/
    private String name;

    /** Возраст **/
    private int age;

    /** Пол **/
    private int sex;

    public Person(String newName, int newAge, int newSex) {
        name = newName;
        age = newAge;
        sex = newSex;
    }

    abstract protected void hello(Person personTwo);

    abstract public String getTypeText();

    /**
     * Получить пол
     */
    public int getSex()
    {
        return sex;
    }

    /**
     * Получить пол текстом
     */
    public String getSexText()
    {
        return (sex == 1) ? "мужской" : "женский";
    }

    public void fullHello(Person personTwo)
    {
        System.out.print(name + ": ");

        hello(personTwo);
    }

    /**
     * Получить имя персоны
     */
    public String getName()
    {
        return name;
    }

    /**
     * Вывод информации о персоне
     */
    public void about()
    {
        System.out.println("Меня зовут: " + name);
        System.out.println("Мой возраст: " + getAgeText());
        System.out.println("Мой пол: " + getSexText());
        System.out.println("Я - " + getTypeText());
    }

    /**
     * Получить возраст
     */
    public int getAge()
    {
        return age;
    }

    /**
     * Получить возраст с корректным склонением
     */
    public String getAgeText()
    {
        switch(age % 10)
        {
            case 1:
                return age + " год";
            case 2: case 3: case 4:
                return age + " года";
            default:
                return age + " лет";
        }
    }

    protected String getTypeTextSuffix()
    {
        return sex == SEX_FEMALE ? "ка" : "";
    }
}
