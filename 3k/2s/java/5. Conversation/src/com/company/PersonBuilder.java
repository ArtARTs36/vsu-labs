package com.company;

public class PersonBuilder
{
    // Количество типов (наследников)
    final int COUNT_TYPES = 3;

    // Количество имен
    final int COUNT_NAMES = 10;

    // ID типа "Формалист"
    final int FORMALIST_TYPE_ID = 1;

    // ID типа "Неформал"
    final int NOFORMALIST_TYPE_ID = 2;

    // ID типа "Реалист"
    final int REALIST_TYPE_ID = 3;

    // Минимальный генерируемый возраст
    final int AGE_MIN = 20;

    // Максимальный
    final int AGE_MAX = 40;

    final String[] names = {
            "Артем", "Сергей", "Иван", "Петр", "Андрей",
            "Дарья", "Елена", "Марина", "Екатерина", "Анастасия"
    };

    final int[] namesTypes = new int[]{
            Person.SEX_MALE, Person.SEX_MALE, Person.SEX_MALE, Person.SEX_MALE, Person.SEX_MALE,
            Person.SEX_FEMALE, Person.SEX_FEMALE, Person.SEX_FEMALE, Person.SEX_FEMALE, Person.SEX_FEMALE,
    };

    private int totalCountPersons = 0;
    private int[] countsMakeTypes = new int[COUNT_TYPES];
    private int[] countsNamesUses = new int[COUNT_NAMES];

    public PersonBuilder() {
        resetCounts();
    }

    private void resetCounts()
    {
        for (int i = 0; i < COUNT_TYPES; i++) {
            countsMakeTypes[i] = 0;
        }

        for (int i = 0; i < COUNT_NAMES; i++) {
            countsNamesUses[i] = 0;
        }
    }

    /**
     * Выбрать случайное имя
     */
    private int[] selectNameAndSex()
    {
        int id = (totalCountPersons < COUNT_NAMES) ? findExclusiveNameId() : random(0, COUNT_NAMES);

        countsNamesUses[id]++;

        return new int[]{
                id,
                namesTypes[id]
        };
    }

    /**
     * Поиск не использованного имени
     */
    private int findExclusiveNameId()
    {
        int randId = random(0, COUNT_NAMES);

        if (countsNamesUses[randId] == 0) {
            return randId;
        }

        return findExclusiveNameId();
    }

    /**
     * Создать персону
     */
    private Person createPerson(int typeId, String name, int age, int newSex)
    {
        switch (typeId) {
            case FORMALIST_TYPE_ID:
                return new Formalist(name, age, newSex);
            case NOFORMALIST_TYPE_ID:
                return new NoFormalist(name, age, newSex);
            default:
                return new Realist(name, age, newSex);
        }
    }

    /**
     * Поиск первого не использованного элемента в массиве
     */
    private int findFirstNoUsedElem(int[] counts, int max) {
        for (int i = 0; i < max; i++) {
            if (counts[i] == 0) {
                return i;
            }
        }

        return 0;
    }

    /**
     * Генерация случайного числа от min до max
     */
    private int random(int min, int max)
    {
        return (int) (min + Math.random() * (max - min));
    }

    Person build()
    {
        int[] nameAndSex = selectNameAndSex();

        int nameId = nameAndSex[0];
        int sex = nameAndSex[1];

        String name = names[nameId];

        int typeId = (totalCountPersons < COUNT_TYPES) ?
                findFirstNoUsedElem(countsMakeTypes, COUNT_TYPES) : random(0, COUNT_TYPES);

        int age = random(AGE_MIN, AGE_MAX);

        Person person = createPerson(typeId, name, age, sex);

        countsMakeTypes[typeId]++;
        totalCountPersons++;

        return person;
    }
};
